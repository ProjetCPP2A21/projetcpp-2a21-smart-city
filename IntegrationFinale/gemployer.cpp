#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include "connection.h"
#include <QStringConverter> // <-- AJOUTEZ CETTE LIGNE (Nécessaire pour Qt 6)
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QRegularExpression>
#include <QCryptographicHash> // <-- AJOUTÉ POUR LA SÉCURITÉ
#include <QByteArray>         // <-- AJOUTÉ POUR LA SÉCURITÉ
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>
#include "smtp.h"              // Pour reconnaitre la classe 'Smtp'
#include <QRandomGenerator>
// ===============================================
// AJOUT : INCLUDES POUR LES NOUVELLES FONCTIONS
// ===============================================
#include <QFileDialog>  // Pour la fenêtre "Enregistrer sous"
#include <QFile>        // Pour écrire dans un fichier
#include <QTextStream>  // Pour formater le texte du fichier
// ===============================================
//using namespace QtCharts;
#include <QSslSocket> // <--- Mettez ça tout en haut du fichier avec les autres includes
// Définition de la requête SELECT





const QString SELECT_QUERY = "SELECT id_employe, nom, prenom, num_tel, salaire, sexe, responsabilite FROM EMPLOYER";
// ===============================================
// FONCTION DE HACHAGE (SÉCURITÉ)
// ===============================================

QString MainWindow::hashPassword(const QString &password)
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

// ==================== LOGIN (CORRIGÉ ET SÉCURISÉ) ====================
void MainWindow::onLoginClicked()
{
    QString username = ui->lineEditLoginUsername->text();
    QString password = ui->lineEditLoginPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QString inputHash = hashPassword(password);

    QSqlQuery query;
    // --- MODIFICATION ICI : On sélectionne aussi la RESPONSABILITE ---
    query.prepare("SELECT PASSWORD, RESPONSABILITE FROM EMPLOYER WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur de connexion !");
        return;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        QString roleRecupere = query.value(1).toString(); // On récupère le rôle

        if (inputHash == storedHash) {
            QMessageBox::information(this, "Bienvenue", "Connexion réussie en tant que : " + roleRecupere);

            clearChamps(); // Vider les champs de login

            // --- APPEL DE LA NOUVELLE FONCTION ---
            configurerAccesSelonRole(roleRecupere);

        } else {
            QMessageBox::warning(this, "Erreur", "Mot de passe incorrect !");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "ID introuvable !");
    }
}


// ==================== CRUD ====================

void MainWindow::on_Ajouter_Employe_Clicked()
{
    // --- 1. Récupérer tous les champs en QString ---
    QString idStr = ui->ID_Employe->text();
    QString salaireStr = ui->Salaire->text();
    QString telephoneStr = ui->Telephone_Employe->text();
    QString nom = ui->Nom_Employe->text();
    QString prenom = ui->Prenom_Employe->text();
    QString sexe = ui->Sexe_Employe->text();
    QString tache = ui->Responsabilite->text();

    // --- 2. Définir les règles de validation (Regex) ---
    QRegularExpression regexID("^[0-9]+$");
    QRegularExpression regexTel("^[0-9]{8}$");
    QRegularExpression regexTexte("^[a-zA-Z '-]+$");
    QRegularExpression regexSalaire("^[0-9]+$");

    // --- 3. Effectuer les validations ---
    if (idStr.isEmpty() || salaireStr.isEmpty() || telephoneStr.isEmpty() || nom.isEmpty() || prenom.isEmpty() || sexe.isEmpty() || tache.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Tous les champs doivent être remplis.");
        return;
    }
    if (!regexID.match(idStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID ne doit contenir que des chiffres.");
        return;
    }
    if (!regexTexte.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le Nom ne doit contenir que des lettres.");
        return;
    }
    if (!regexTexte.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le Prénom ne doit contenir que des lettres.");
        return;
    }
    if (!regexTel.match(telephoneStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }
    if (!regexSalaire.match(salaireStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le salaire doit être un nombre entier valide.");
        return;
    }
    QString sexeLower = sexe.toLower();
    if (sexeLower != "homme" && sexeLower != "femme") {
        QMessageBox::warning(this, "Erreur de saisie", "Le Sexe doit être 'homme' ou 'femme'.");
        return;
    }
    if (!regexTexte.match(tache).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "La Tâche (Responsabilité) ne doit contenir que des lettres.");
        return;
    }

    // --- 4. Si tout est valide, convertir et créer l'objet ---
    int id = idStr.toInt();
    int salaire = salaireStr.toInt();
    int telephone = telephoneStr.toInt();
    sexe = sexeLower.replace(0, 1, sexeLower.at(0).toUpper()); // Met "Homme" ou "Femme"

    employer e(id, salaire, telephone, nom, prenom, sexe, tache);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout ! (Vérifiez si l'ID existe déjà)");
    }
}

void MainWindow::on_Modifier_Employe_Clicked()
{
    // (vous pouvez aussi ajouter les validations ici comme pour 'onAjouterClicked')
    int id = ui->ID_Employe->text().toInt();
    float salaire = ui->Salaire->text().toInt();
    int telephone = ui->Telephone_Employe->text().toInt();
    QString nom = ui->Nom_Employe->text();
    QString prenom = ui->Prenom_Employe->text();
    QString sexe = ui->Sexe_Employe->text();
    QString tache = ui->Responsabilite->text();

    QSqlQuery query;
    query.prepare("UPDATE EMPLOYER SET nom=?, prenom=?, sexe=?, responsabilite=?, salaire=?, num_tel=? WHERE id_employe=?");
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(sexe);
    query.addBindValue(tache);
    query.addBindValue(salaire);
    query.addBindValue(telephone);
    query.addBindValue(id);
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Employé modifié avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
        qDebug() << "Erreur modif:" << query.lastError().text();
    }
}

void MainWindow::on_Supprimer_Employe_Clicked()
{
    int id = ui->ID_Employe->text().toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide !");
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYER WHERE id_employe=?");
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
        qDebug() << "Erreur suppression:" << query.lastError().text();
    }
}

void MainWindow::onRechercherClicked()
{
    QString critere = ui->Rechercher_Employe->text();
    QSqlQuery query;

    if (critere.isEmpty()) {
        query.prepare(SELECT_QUERY);
    } else {
        query.prepare(QString("%1 WHERE "
                              "CAST(id_employe AS VARCHAR(10)) LIKE :critere OR "
                              "LOWER(nom) LIKE LOWER(:critere) OR "
                              "LOWER(prenom) LIKE LOWER(:critere) OR "
                              "LOWER(sexe) LIKE LOWER(:critere) OR "
                              "LOWER(responsabilite) LIKE LOWER(:critere)").arg(SELECT_QUERY));
        query.bindValue(":critere", "%" + critere + "%");
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche !");
        qDebug() << "Erreur recherche:" << query.lastError().text();
        return;
    }
    remplirTable(query);
}

// ==================== TABLE ====================

void MainWindow::ontableWidgetEmployesClicked(int row, int column)
{
    (void)column; // Indique que 'column' n'est pas utilisé

    QTableWidgetItem *itemID = ui->tableWidgetEmployes->item(row, 0);
    QTableWidgetItem *itemNom = ui->tableWidgetEmployes->item(row, 1);
    QTableWidgetItem *itemPrenom = ui->tableWidgetEmployes->item(row, 2);
    QTableWidgetItem *itemTel = ui->tableWidgetEmployes->item(row, 3);
    QTableWidgetItem *itemSalaire = ui->tableWidgetEmployes->item(row, 4);
    QTableWidgetItem *itemSexe = ui->tableWidgetEmployes->item(row, 5);
    QTableWidgetItem *itemTache = ui->tableWidgetEmployes->item(row, 6);

    if (itemID) ui->ID_Employe->setText(itemID->text());
    if (itemNom) ui->Nom_Employe->setText(itemNom->text());
    if (itemPrenom) ui->Prenom_Employe->setText(itemPrenom->text());
    if (itemTel) ui->Telephone_Employe->setText(itemTel->text());
    if (itemSalaire) ui->Salaire->setText(itemSalaire->text());
    if (itemSexe) ui->Sexe_Employe->setText(itemSexe->text());
    if (itemTache) ui->Responsabilite->setText(itemTache->text());
}

void MainWindow::afficherEmployes()
{
    QSqlQuery query(SELECT_QUERY);
    remplirTable(query);
}

void MainWindow::remplirTable(QSqlQuery &query)
{
    ui->tableWidgetEmployes->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidgetEmployes->insertRow(row);
        for (int col = 0; col < 7; col++) {
            ui->tableWidgetEmployes->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}

// ==================== UTILS ====================


void MainWindow::clearChamps()
{
    // Champs du Dashboard
    ui->ID_Employe->clear();
    ui->Nom_Employe->clear();
    ui->Prenom_Employe->clear();
    ui->Sexe_Employe->clear();
    ui->Responsabilite->clear();
    ui->Salaire->clear();
    ui->Telephone_Employe->clear();

    // Champs de Login
    ui->lineEditLoginUsername->clear();
    ui->lineEditLoginPassword->clear();

    /* Champs de Création de Compte
    if (ui->lineEditCreerId) ui->lineEditCreerId->clear();
    if (ui->lineEditCreerUsername) ui->lineEditCreerUsername->clear();
    if (ui->lineEditCreerPassword) ui->lineEditCreerPassword->clear();*/

    // Champs de Mot de Passe Oublié
    if (ui->lineEditMdpId) ui->lineEditMdpId->clear();
    if (ui->lineEditMdpUsername) ui->lineEditMdpUsername->clear();
    if (ui->lineEditNouveauPass) ui->lineEditNouveauPass->clear();
}


// ===============================================
// FONCTIONS (Création / Mot de passe)
// ===============================================

/*void MainWindow::on_pushButtonCreer_clicked()
{
    QString id = ui->lineEditCreerId->text();
    QString username = ui->lineEditCreerUsername->text();
    QString password = ui->lineEditCreerPassword->text();
    QString email = ui->lineEditEmail->text();


    if (id.isEmpty() || username.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires.");
        return;
    }
    ui->lineEditCreerPassword->setEchoMode(QLineEdit::Password);

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM UTILISATEURS WHERE id = :id OR username = :username");
    checkQuery.bindValue(":id", id);
    checkQuery.bindValue(":username", username);
    checkQuery.bindValue(":email", email);


    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Erreur BDD (Check)", QString("La vérification du compte a échoué.\n\nErreur: %1").arg(checkQuery.lastError().text()));
        return;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Cet ID ou ce nom d'utilisateur existe déjà.");
        return;
    }

    QString newHash = hashPassword(password);
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO UTILISATEURS (id, username, password_hash,Email) VALUES (:id, :username, :hash,:email)");
    insertQuery.bindValue(":id", id);
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":hash", newHash);
    insertQuery.bindValue(":email", email);


    if (insertQuery.exec()) {
        QMessageBox::information(this, "Succès", "Compte créé avec succès ! Vous pouvez maintenant vous connecter.");
        clearChamps();
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    } else {
        QMessageBox::critical(this, "Erreur BDD (Insert)", QString("Impossible de créer le compte.\n\nErreur: %1").arg(insertQuery.lastError().text()));
    }
}*/

void MainWindow::on_pushButtonReset_clicked()
{
    QString id = ui->lineEditMdpId->text();
    QString username = ui->lineEditMdpUsername->text();
    QString newPassword = ui->lineEditNouveauPass->text();

    if (id.isEmpty() || username.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires.");
        return;
    }
    ui->lineEditNouveauPass->setEchoMode(QLineEdit::Password);

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYER WHERE id = :id AND username = :username");
    checkQuery.bindValue(":id", id);
    checkQuery.bindValue(":username", username);

    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Erreur BDD (Check)", QString("La vérification du compte a échoué.\n\nErreur: %1").arg(checkQuery.lastError().text()));
        return;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() != 1) {
        QMessageBox::warning(this, "Erreur", "Combinaison ID / Nom d'utilisateur incorrecte.");
        return;
    }

    QString newHash = hashPassword(newPassword);
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE EMPLOYER SET password_hash = :hash WHERE id = :id AND username = :username");
    updateQuery.bindValue(":hash", newHash);
    updateQuery.bindValue(":id", id);
    updateQuery.bindValue(":username", username);

    if (updateQuery.exec()) {
        QMessageBox::information(this, "Succès", "Mot de passe réinitialisé avec succès !");
        clearChamps();
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    } else {
        QMessageBox::critical(this, "Erreur BDD (Update)", QString("Impossible de réinitialiser le mot de passe.\n\nErreur: %1").arg(updateQuery.lastError().text()));
    }
}

// ===============================================
// SLOTS DE NAVIGATION (Création / Mot de passe)
// ===============================================

/*void MainWindow::on_pushButtonGoToCreer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    clearChamps();
}*/

void MainWindow::on_pushButtonGoToMdp_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_7);
    clearChamps();
}

void MainWindow::on_pushButtonRetourLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Connection);
    clearChamps();
}

void MainWindow::on_pushButtonRetourLogin_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Connection);
    clearChamps();
}

void MainWindow::on_pushButtonRetourLogin_3_cliked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_7);
    clearChamps();
}


// ===============================================
// ===============================================
//   AJOUT : NOUVELLES FONCTIONS (Tri, Export, Stats)
// ===============================================
// ===============================================

// ===============================================
// FONCTION 1 : TRIER PAR NOM
// ===============================================
void MainWindow::onTrierClicked()
{
    // On trie le QTableWidget directement.
    // 1 est l'index de votre colonne "nom" (0=ID, 1=nom, ...)
    // Qt::AscendingOrder = Ordre alphabétique (A-Z)

    ui->tableWidgetEmployes->sortByColumn(1, Qt::AscendingOrder);

    QMessageBox::information(this, "Tri", "Le tableau a été trié par nom (A-Z).");
}

// ===============================================
// FONCTION 2 : EXPORTER EN CSV (pour Excel)
// ===============================================
void MainWindow::onExporterClicked()
{
    // 1. Choisir où enregistrer le fichier
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter les employés", "", "Fichiers CSV (*.csv)");

    if (filePath.isEmpty()) {
        return; // L'utilisateur a annulé
    }

    QFile file(filePath);

    // 2. Tenter d'ouvrir le fichier en écriture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier pour l'exportation !");
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8); // <-- LIGNE CORRIGÉE (pour Qt 6)
    // 3. Écrire les en-têtes (Noms des colonnes)
    QStringList headers;
    for (int c = 0; c < ui->tableWidgetEmployes->columnCount(); ++c) {
        headers << ui->tableWidgetEmployes->horizontalHeaderItem(c)->text();
    }
    // Nous utilisons ";" comme séparateur (standard Excel France)
    out << headers.join(";") << "\n";

    // 4. Écrire toutes les lignes de données
    for (int r = 0; r < ui->tableWidgetEmployes->rowCount(); ++r) {
        QStringList rowData;
        for (int c = 0; c < ui->tableWidgetEmployes->columnCount(); ++c) {
            QTableWidgetItem *item = ui->tableWidgetEmployes->item(r, c);
            QString text = (item ? item->text() : "");
            // Gérer les ";" dans le texte
            if (text.contains(';')) {
                rowData << "\"" + text + "\"";
            } else {
                rowData << text;
            }
        }
        out << rowData.join(";") << "\n";
    }

    // 5. Fermer le fichier et notifier l'utilisateur
    file.close();
    QMessageBox::information(this, "Succès", "Exportation vers le fichier CSV réussie !");
}

// ===============================================
// FONCTION 3 : STATISTIQUES (Sexe)
// ===============================================
void MainWindow::onStatistiquesClicked()
{
    // 1. COMPTER (HOMMES vs FEMMES)
    int h = 0, f = 0;
    QSqlQuery q;
    q.exec("SELECT COUNT(*) FROM EMPLOYER WHERE LOWER(sexe)='homme'");
    if (q.next()) h = q.value(0).toInt();
    q.exec("SELECT COUNT(*) FROM EMPLOYER WHERE LOWER(sexe)='femme'");
    if (q.next()) f = q.value(0).toInt();

    if (h == 0 && f == 0) return;

    // 2. PRÉPARER LE CAMEMBERT
    // Notez qu'on n'écrit plus "QtCharts::QPieSeries", juste "QPieSeries"
    QPieSeries *series = new QPieSeries();
    series->append("Hommes", h);
    series->append("Femmes", f);

    // Couleurs et Labels
    QPieSlice *sliceH = series->slices().at(0);
    sliceH->setBrush(QColor("#3498db")); // Bleu
    sliceH->setLabelVisible(true);
    sliceH->setLabel(QString("Hommes: %1").arg(h));

    QPieSlice *sliceF = series->slices().at(1);
    sliceF->setBrush(QColor("#e74c3c")); // Rouge
    sliceF->setLabelVisible(true);
    sliceF->setLabel(QString("Femmes: %1").arg(f));

    // 3. CRÉER LE GRAPHIQUE
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques Sexe");
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignRight);

    // 4. METTRE LE GRAPHIQUE DANS LE WIDGET
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // --- CORRECTION DE L'ERREUR "ui->widgetStats" ---
    // Vérifiez bien que le widget existe, sinon le programme plantera ici.
    if (ui->widgetStats->layout() != nullptr) {
        QLayoutItem* item;
        while ((item = ui->widgetStats->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete ui->widgetStats->layout();
    }

    QVBoxLayout *layout = new QVBoxLayout(ui->widgetStats);
    layout->addWidget(chartView);
    ui->widgetStats->setLayout(layout);
}
// MainWindow.cpp

void MainWindow::on_pushButtonSuivant_clicked()
{
    QString emailSaisi = ui->lineEditMdpEmail->text();

    if(emailSaisi.isEmpty()){
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre adresse email.");
        return;
    }

    QSqlQuery query;
    // CORRECTION : Table EMPLOYER, colonne ID_EMPLOYE
    query.prepare("SELECT ID_EMPLOYE FROM EMPLOYER WHERE EMAIL = :email");
    query.bindValue(":email", emailSaisi);

    if(query.exec() && query.next()){
        // L'email existe, on récupère l'ID
        this->idUtilisateurEnCours = query.value(0).toString();

        // Génération du code
        int code = QRandomGenerator::global()->bounded(1000, 9999);
        this->codeVerificationGenere = QString::number(code);

        // Envoi Email (reste inchangé)
        Smtp *smtp = new Smtp("mo7it.re@gmail.com", "zfuj tzox yrss fpvj", "smtp.gmail.com", 465);
        smtp->sendMail("mo7it.re@gmail.com", emailSaisi, "Code de réinitialisation", "Code : " + this->codeVerificationGenere);

        QMessageBox::information(this, "Succès", "Code envoyé à " + emailSaisi);
        ui->stackedWidget->setCurrentWidget(ui->page_13);

    } else {
        QMessageBox::warning(this, "Erreur", "Email introuvable dans la liste des employés.");
    }
}
// MainWindow.cpp

void MainWindow::on_pushButtonValiderReset_clicked()
{
    QString codeSaisi = ui->lineEditCodeRecu->text();
    QString nouveauPass = ui->lineEditNouveauPass->text();

    if (codeSaisi.isEmpty() || nouveauPass.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    if (codeSaisi != this->codeVerificationGenere) {
        QMessageBox::critical(this, "Erreur", "Code incorrect ! Veuillez vérifier votre email.");
        return;
    }

    QString newHash = hashPassword(nouveauPass);

    QSqlQuery query;
    query.prepare("UPDATE EMPLOYER SET PASSWORD = :hash WHERE ID_EMPLOYE = :id");

    query.bindValue(":hash", newHash);

    // --- CORRECTION ICI ---
    // On convertit la chaîne (QString) en Entier (int) pour qu'Oracle soit content.
    query.bindValue(":id", this->idUtilisateurEnCours.toInt());

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Mot de passe modifié avec succès !");
        clearChamps();
        ui->stackedWidget->setCurrentWidget(ui->Connection); // Retour login
    } else {
        // Affiche l'erreur exacte si ça échoue encore
        QMessageBox::critical(this, "Erreur BDD", query.lastError().text());
        qDebug() << "Erreur Update MDP:" << query.lastError().text();
    }
}

void MainWindow::on_pushButtonRetourLogin_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_7); // Démarrer sur la page login

}


void MainWindow::on_quitter_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quitter", "Voulez-vous vraiment quitter l'application ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}
void MainWindow::configurerAccesSelonRole(QString role)
{
    // 1. Normaliser le texte (minuscules et sans espaces inutiles)
    role = role.toLower().trimmed();

    // 2. Par défaut, on désactive TOUT (Sécurité d'abord)
    // Désactivez ici vos boutons de navigation du menu principal
    /* Exemple :
    ui->btnMenuRH->setEnabled(false);
    ui->btnMenuService->setEnabled(false);
    ui->btnMenuEvent->setEnabled(false);
    ui->btnMenuResidence->setEnabled(false);
    */

    // Les boutons CRUD employés (Ajouter/Modifier/Supprimer)
    ui->Ajouter_Employe->setEnabled(false);
    ui->Modifier_Employe->setEnabled(false);
    ui->Supprimer_Employe->setEnabled(false);
    ui->Rechercher_Employe->setEnabled(false);

    // 3. Logique par Rôle
    if (role == "rh") {
        // --- Rôle RH ---
        // Accès complet à la gestion des employés
        ui->Ajouter_Employe->setEnabled(true);
        ui->Modifier_Employe->setEnabled(true);
        ui->Supprimer_Employe->setEnabled(true);
        ui->Rechercher_Employe->setEnabled(true);

        // Redirection vers la page des employés (votre page actuelle ui->page)
        ui->stackedWidget->setCurrentWidget(ui->page_4);
        afficherEmployes(); // On charge les données

    }
    else if (role == "service") {
        // --- Rôle SERVICE ---
        // Activez le bouton ou le menu Service ici si vous en avez un
        // ui->btnMenuService->setEnabled(true);

        // Redirection (Remplacez page_Service par le vrai nom de votre page Service)
        ui->stackedWidget->setCurrentWidget(ui->page_6);
        QMessageBox::information(this, "Accès", "Interface Service chargée.");
    }
    else if (role == "evenement") {
        // --- Rôle EVENEMENT ---
        ui->stackedWidget->setCurrentWidget(ui->page_2);
        QMessageBox::information(this, "Accès", "Interface Événement chargée.");
    }
    else if (role == "residence") {
        // --- Rôle RESIDENCE ---
        ui->stackedWidget->setCurrentWidget(ui->page_3);
        QMessageBox::information(this, "Accès", "Interface Résidence chargée.");
    }
    else if (role == "resident") {
        // --- Rôle RESIDENT ---
         ui->stackedWidget->setCurrentWidget(ui->page);
        QMessageBox::information(this, "Accès", "Interface Résident chargée.");
    }
    else {
        // Rôle inconnu ou "admin"
        QMessageBox::warning(this, "Attention", "Rôle non reconnu : " + role);
    }
}
