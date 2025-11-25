#include "email.h"
#include <QDebug>
#include <QByteArray>
#include <QSslSocket>

Email::Email(QObject *parent) : QObject(parent) {}
Email::~Email() {}

bool Email::envoyerSMTP(const QString &to, const QString &sujet, const QString &corps)
{
    QSslSocket socket;

    // Connexion TLS directe sur port 465
    socket.connectToHostEncrypted("smtp.gmail.com", 465);
    if (!socket.waitForEncrypted(10000)) {
        qDebug() << "❌ Erreur TLS:" << socket.errorString();
        return false;
    }

    auto sendCommand = [&](const QString &cmd) {
        socket.write(cmd.toUtf8() + "\r\n");
        socket.flush();
        if (!socket.waitForReadyRead(10000)) {
            qDebug() << "❌ Timeout ou erreur lors de l'envoi de:" << cmd;
            return false;
        }
        qDebug() << socket.readAll();
        return true;
    };

    // Séquence SMTP
    if (!sendCommand("EHLO localhost")) return false;
    if (!sendCommand("AUTH LOGIN")) return false;

    QString loginEnc = QByteArray(monEmail.toUtf8()).toBase64();
    QString mdpEnc   = QByteArray(mdpApp.toUtf8()).toBase64();

    if (!sendCommand(loginEnc)) return false;
    if (!sendCommand(mdpEnc)) return false;

    if (!sendCommand(QString("MAIL FROM:<%1>").arg(monEmail))) return false;
    if (!sendCommand(QString("RCPT TO:<%1>").arg(to))) return false;
    if (!sendCommand("DATA")) return false;

    QString message;
    message += QString("From: %1\r\n").arg(monEmail);
    message += QString("To: %1\r\n").arg(to);
    message += QString("Subject: %1\r\n").arg(sujet);
    message += "\r\n";
    message += corps + "\r\n";
    message += ".";
    if (!sendCommand(message)) return false;

    if (!sendCommand("QUIT")) return false;

    qDebug() << "✅ Email envoyé avec succès à" << to;
    return true;
}

// ==== Méthodes spécialisées ====

void Email::envoyerChangementService(const QString &to, const QString &serviceName,
                                     const QString &ancienType, const QString &nouveauType)
{
    QString sujet = QString("Changement de type pour le service %1").arg(serviceName);
    QString corps = QString("Le type du service %1 a été modifié:\nAncien type: %2\nNouveau type: %3")
                        .arg(serviceName).arg(ancienType).arg(nouveauType);
    envoyerSMTP(to, sujet, corps);
}

void Email::envoyerChangementStatut(const QString &to, const QString &serviceName,
                                    const QString &ancienStatut, const QString &nouveauStatut)
{
    QString sujet = QString("Changement de statut pour le service %1").arg(serviceName);
    QString corps = QString("Le statut du service %1 a été modifié:\nAncien statut: %2\nNouveau statut: %3")
                        .arg(serviceName).arg(ancienStatut).arg(nouveauStatut);
    envoyerSMTP(to, sujet, corps);
}

void Email::envoyerBudgetDepasse(const QString &to, double budget, double limite,
                                 const QString &serviceName)
{
    QString sujet = QString("Alerte budget dépassé pour le service %1").arg(serviceName);
    QString corps = QString("Le budget du service %1 a dépassé la limite autorisée.\nBudget actuel: %2\nLimite: %3")
                        .arg(serviceName).arg(budget).arg(limite);
    envoyerSMTP(to, sujet, corps);
}

void Email::envoyerServiceSupprime(const QString &to, const QString &serviceName,
                                   const QString &raison)
{
    QString sujet = QString("Service %1 supprimé").arg(serviceName);
    QString corps = QString("Le service %1 a été supprimé du système.\nRaison: %2")
                        .arg(serviceName).arg(raison);
    envoyerSMTP(to, sujet, corps);
}

void Email::envoyerServiceAjoute(const QString &to,
                                 const QString &serviceName,
                                 double budget,
                                 const QString &type,
                                 const QString &priorite)
{
    QString sujet = QString("Nouveau service ajouté : %1").arg(serviceName);
    QString corps = QString("Un nouveau service a été ajouté.\nNom : %1\nBudget : %2\nType : %3\nPriorité : %4")
                        .arg(serviceName).arg(budget).arg(type).arg(priorite);
    envoyerSMTP(to, sujet, corps);
}

void Email::envoyerServiceModifie(const QString &to,
                                  const QString &ancienNom,
                                  const QString &nouveauNom,
                                  double ancienBudget,
                                  double nouveauBudget,
                                  const QString &ancienType,
                                  const QString &nouveauType)
{
    QString sujet = QString("Modification du service : %1").arg(nouveauNom);
    QString corps = QString("Un service a été modifié.\nAnciennes valeurs:\nNom: %1\nBudget: %2\nType: %3\n\nNouvelles valeurs:\nNom: %4\nBudget: %5\nType: %6")
                        .arg(ancienNom).arg(ancienBudget).arg(ancienType)
                        .arg(nouveauNom).arg(nouveauBudget).arg(nouveauType);
    envoyerSMTP(to, sujet, corps);
}
