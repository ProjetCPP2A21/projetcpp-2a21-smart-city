#include "authentification.h"
#include "ui_gemployer.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QByteArray>
#include <QDebug>

Authentification::Authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authentification)
{
    ui->setupUi(this);

    // Mettre les champs de mot de passe en mode "caché"
    ui->lineEditLoginPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditCreerPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditMdpNouveauPassword->setEchoMode(QLineEdit::Password);

    // --- CORRECTION ---
    // Démarrer sur votre page de login, qui est 'page_2' d'après vos slots
    ui->stackedWidgetAuth->setCurrentWidget(ui->page_2);
}

Authentification::~Authentification()
{
    delete ui;
}

// ===============================================
// FONCTION DE HACHAGE (SÉCURITÉ)
// ===============================================

QString Authentification::hashPassword(const QString &password)
{
    // Utilise SHA-256 pour hacher le mot de passe
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex()); // On stocke le hash en format hexadécimal
}

// ===============================================
// SLOTS PRINCIPAUX (LOGIQUE MÉTIER)
// ===============================================

void Authentification::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditLoginUsername->text();
    QString password = ui->lineEditLoginPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // 1. Hacher le mot de passe entré par l'utilisateur
    QString inputHash = hashPassword(password);

    // 2. Préparer la requête pour trouver l'utilisateur
    QSqlQuery query;
    query.prepare("SELECT password_hash FROM utilisateurs WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur BDD", "Erreur lors de la vérification.");
        qDebug() << "Login Error:" << query.lastError().text();
        return;
    }

    // 3. Vérifier si l'utilisateur existe ET si les hashs correspondent
    if (query.next()) {
        QString storedHash = query.value(0).toString();

        if (inputHash == storedHash) {
            // SUCCÈS !
            QMessageBox::information(this, "Succès", "Connexion réussie !");
            accept(); // <-- Ceci dit à main.cpp que la connexion est OK
        } else {
            // Mauvais mot de passe
            QMessageBox::warning(this, "Échec", "Nom d'utilisateur ou mot de passe incorrect.");
        }
    } else {
        // Utilisateur non trouvé
        QMessageBox::warning(this, "Échec", "Nom d'utilisateur ou mot de passe incorrect.");
    }
}

void Authentification::on_pushButtonCreer_clicked()
{
    QString id = ui->lineEditCreerId->text();
    QString username = ui->lineEditCreerUsername->text();
    QString password = ui->lineEditCreerPassword->text();

    if (id.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires.");
        return;
    }

    // Étape 1 : Vérifier si l'ID ou le username existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM utilisateurs WHERE id = :id OR username = :username");
    checkQuery.bindValue(":id", id);
    checkQuery.bindValue(":username", username);
    checkQuery.exec();

    if (checkQuery.next()) {
        QMessageBox::warning(this, "Erreur", "Cet ID ou ce nom d'utilisateur existe déjà.");
        return;
    }

    // Étape 2 : Hacher le mot de passe
    QString newHash = hashPassword(password);

    // Étape 3 : Insérer le nouvel utilisateur
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO utilisateurs (id, username, password_hash) VALUES (:id, :username, :hash)");
    insertQuery.bindValue(":id", id);
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":hash", newHash);

    if (insertQuery.exec()) {
        QMessageBox::information(this, "Succès", "Compte créé avec succès ! Vous pouvez maintenant vous connecter.");
        clearFields();
        // Ramener à la page de login
        ui->stackedWidgetAuth->setCurrentWidget(ui->page_2);
    } else {
        QMessageBox::critical(this, "Erreur BDD", "Impossible de créer le compte.");
        qDebug() << "Create Account Error:" << insertQuery.lastError().text();
    }
}

void Authentification::on_pushButtonReset_clicked()
{
    QString id = ui->lineEditMdpId->text();
    QString username = ui->lineEditMdpUsername->text();
    QString newPassword = ui->lineEditMdpNouveauPassword->text();

    if (id.isEmpty() || username.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires.");
        return;
    }

    // Étape 1 : Vérifier si l'utilisateur (ID + Username) existe
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM utilisateurs WHERE id = :id AND username = :username");
    checkQuery.bindValue(":id", id);
    checkQuery.bindValue(":username", username);
    checkQuery.exec();
    checkQuery.next();

    if (checkQuery.value(0).toInt() != 1) {
        QMessageBox::warning(this, "Erreur", "Combinaison ID / Nom d'utilisateur incorrecte.");
        return;
    }

    // Étape 2 : Hacher le NOUVEAU mot de passe
    QString newHash = hashPassword(newPassword);

    // Étape 3 : Mettre à jour le mot de passe
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE utilisateurs SET password_hash = :hash WHERE id = :id AND username = :username");
    updateQuery.bindValue(":hash", newHash);
    updateQuery.bindValue(":id", id);
    updateQuery.bindValue(":username", username);

    if (updateQuery.exec()) {
        QMessageBox::information(this, "Succès", "Mot de passe réinitialisé avec succès !");
        clearFields();
        // Ramener à la page de login
        ui->stackedWidgetAuth->setCurrentWidget(ui->page_2);
    } else {
        QMessageBox::critical(this, "Erreur BDD", "Impossible de réinitialiser le mot de passe.");
        qDebug() << "Reset Password Error:" << updateQuery.lastError().text();
    }
}

void Authentification::clearFields()
{
    // Vider tous les champs
    ui->lineEditLoginUsername->clear();
    ui->lineEditLoginPassword->clear();
    ui->lineEditCreerId->clear();
    ui->lineEditCreerUsername->clear();
    ui->lineEditCreerPassword->clear();
    ui->lineEditMdpId->clear();
    ui->lineEditMdpUsername->clear();
    ui->lineEditMdpNouveauPassword->clear();
}


// ===============================================
// SLOTS DE NAVIGATION (utilisant VOS noms de page)
// ===============================================

void Authentification::on_pushButtonGoToCreer_clicked()
{
    // Aller à la page "Créer un compte"
    ui->stackedWidgetAuth->setCurrentWidget(ui->page_3);
    clearFields();
}

void Authentification::on_pushButtonGoToMdp_clicked()
{
    // Aller à la page "Mot de passe oublié"
    ui->stackedWidgetAuth->setCurrentWidget(ui->page_10);
    clearFields();
}

void Authentification::on_pushButtonRetourLogin_1_clicked()
{
    // Retourner à la page de Login
    ui->stackedWidgetAuth->setCurrentWidget(ui->page_2);
    clearFields();
}

void Authentification::on_pushButtonRetourLogin_2_clicked()
{
    // Retourner à la page de Login
    ui->stackedWidgetAuth->setCurrentWidget(ui->page_2);
    clearFields();
}
