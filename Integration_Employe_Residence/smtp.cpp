#include "smtp.h"

Smtp::Smtp(const QString &user, const QString &pass, const QString &host, int port, int timeout)
{
    socket = new QSslSocket(this);

    connect(socket, &QSslSocket::readyRead, this, &Smtp::readyRead);
    connect(socket, &QSslSocket::connected, this, &Smtp::connected);
    // CORRECTION QT6 : On utilise errorOccurred au lieu de error
    connect(socket, &QSslSocket::errorOccurred, this, &Smtp::errorReceived);
    connect(socket, &QSslSocket::stateChanged, this, &Smtp::stateChanged);
    connect(socket, &QSslSocket::disconnected, this, &Smtp::disconnected);

    this->user = user;
    this->pass = pass;
    this->host = host;
    this->port = port;
    this->timeout = timeout;
}

Smtp::~Smtp()
{
    delete t;
    delete socket;
}

void Smtp::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body)
{
    message = "To: " + to + "\n";
    message.append("From: " + from + "\n");
    message.append("Subject: " + subject + "\n");
    message.append("MIME-Version: 1.0\n");
    message.append("Content-Type: text/html; charset=UTF-8\n\n"); // En HTML pour les accents
    message.append(body);
    message.replace( QString::fromLatin1( "\n" ), QString::fromLatin1( "\r\n" ) );
    message.replace( QString::fromLatin1( "\r\n.\r\n" ), QString::fromLatin1( "\r\n..\r\n" ) );

    this->from = from;
    rcpt = to;
    state = Init;

    // --- CORRECTION CRITIQUE POUR GMAIL / SECURE CHANNEL ---
    // On force l'utilisation de TLS 1.2 ou 1.3 (Gmail refuse les vieux protocoles)
    socket->setProtocol(QSsl::TlsV1_2OrLater);

    // On se connecte en mode crypté direct (Port 465)
    socket->connectToHostEncrypted(host, port);

    if (!socket->waitForConnected(timeout)) {
        qDebug() << "Erreur de connexion SMTP:" << socket->errorString();
    }

    t = new QTextStream( socket );
}

void Smtp::stateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "State:" << socketState;
}

void Smtp::errorReceived(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Erreur SMTP:" << socketError << socket->errorString();
}

void Smtp::disconnected()
{
    qDebug() << "Déconnecté du serveur SMTP";
    qDebug() << "Message d'erreur final (si échec): " << socket->errorString();
}

void Smtp::connected()
{
    qDebug() << "Connecté au serveur SMTP !";
}

void Smtp::readyRead()
{
    qDebug() << "Réponse serveur : " << socket->readAll();

    if (state == Init && response.isEmpty())
    {
        // Premier contact établi, on envoie le EHLO
        *t << "EHLO localhost" << "\r\n";
        t->flush();
        state = HandShake;
    }
    else if (state == HandShake)
    {
        // On demande l'authentification
        *t << "AUTH LOGIN" << "\r\n";
        t->flush();
        state = Auth;
    }
    else if (state == Auth)
    {
        // On envoie l'email encodé en Base64
        *t << QByteArray().append(user.toUtf8()).toBase64() << "\r\n";
        t->flush();
        state = User;
    }
    else if (state == User)
    {
        // On envoie le mot de passe encodé en Base64
        *t << QByteArray().append(pass.toUtf8()).toBase64() << "\r\n";
        t->flush();
        state = Pass;
    }
    else if (state == Pass)
    {
        // Authentification réussie, on envoie l'expéditeur
        *t << "MAIL FROM:<" << from << ">" << "\r\n";
        t->flush();
        state = Mail;
    }
    else if (state == Mail)
    {
        *t << "RCPT TO:<" << rcpt << ">" << "\r\n";
        t->flush();
        state = Rcpt;
    }
    else if (state == Rcpt)
    {
        *t << "DATA" << "\r\n";
        t->flush();
        state = Data;
    }
    else if (state == Data)
    {
        *t << message << "\r\n.\r\n";
        t->flush();
        state = Body;
    }
    else if (state == Body)
    {
        *t << "QUIT" << "\r\n";
        t->flush();
        state = Quit;
    }
    else if (state == Quit)
    {
        // Fini !
        socket->close();
    }
}
