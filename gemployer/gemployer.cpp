#include "gemployer.h"
#include "ui_gemployer.h"
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

GEmployer::GEmployer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEmployer)
{
    ui->setupUi(this);


    qDebug() << "================ DIAGNOSTIC EMAIL ================";
    qDebug() << "Support SSL disponible :" << QSslSocket::supportsSsl();
    qDebug() << "Version SSL Compilée   :" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "Version SSL Chargée    :" << QSslSocket::sslLibraryVersionString();
    qDebug() << "Chemin des DLL attendu :" << QCoreApplication::applicationDirPath();
    qDebug() << "==================================================";
    // ... (Connexion BDD)
    if (!Connection::instance().createConnection()) {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données !");
    } else {
        qDebug() << "✅ Connexion réussie à la base de données.";
    }

    // ... (TABLE SETUP)
    ui->tableWidgetEmployes->setColumnCount(7);
    QStringList headers = {"ID", "nom", "prenom", "telephone", "salaire", "Sexe", "Tâche"};
    ui->tableWidgetEmployes->setHorizontalHeaderLabels(headers);
    ui->tableWidgetEmployes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEmployes->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // ==================== LOGIN PAGE (DÉMARRAGE) ====================
    ui->stackedWidget->setCurrentWidget(ui->page_2); // Démarrer sur la page login
    ui->Ajouter->setEnabled(false);
    ui->Modifier->setEnabled(false);
    ui->Supprimer->setEnabled(false);
    ui->rechercher->setEnabled(false);

    // --- CONNEXIONS (SIGNALS & SLOTS) ---

    // Login
    connect(ui->connecter, &QPushButton::clicked, this, &GEmployer::onLoginClicked);

    // CRUD
    connect(ui->Ajouter, &QPushButton::clicked, this, &GEmployer::onAjouterClicked);
    connect(ui->Modifier, &QPushButton::clicked, this, &GEmployer::onModifierClicked);
    connect(ui->Supprimer, &QPushButton::clicked, this, &GEmployer::onSupprimerClicked);
    connect(ui->rechercher, &QPushButton::clicked, this, &GEmployer::onRechercherClicked);
    connect(ui->tableWidgetEmployes, &QTableWidget::cellClicked, this, &GEmployer::onTableEmployeClicked);

    // ===============================================
    // AJOUT : CONNEXIONS POUR LES NOUVELLES FONCTIONS
    // ===============================================
    // Assurez-vous que ces noms (ex: "pushButtonTrier")
    // correspondent à ceux que vous avez mis dans le Qt Designer (.ui)

    connect(ui->pushButtonTrier, &QPushButton::clicked, this, &GEmployer::onTrierClicked);
    connect(ui->pushButtonExporter, &QPushButton::clicked, this, &GEmployer::onExporterClicked);
    connect(ui->pushButtonStats, &QPushButton::clicked, this, &GEmployer::onStatistiquesClicked);


    // --- NOUVELLES CONNEXIONS (automatiques) ---
    // (Qt s'occupe de celles-ci grâce à leurs noms)
}

GEmployer::~GEmployer()
{
    delete ui;
}

// ===============================================
// FONCTION DE HACHAGE (SÉCURITÉ)
// ===============================================

QString GEmployer::hashPassword(const QString &password)
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

// ==================== LOGIN (CORRIGÉ ET SÉCURISÉ) ====================
void GEmployer::onLoginClicked()
{
    QString username = ui->lineEditLoginUsername->text();
    QString password = ui->lineEditLoginPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QString inputHash = hashPassword(password);
    QSqlQuery query;
    query.prepare("SELECT PASSWORD_HASH FROM UTILISATEURS WHERE USERNAME = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la connexion à la base !");
        qDebug() << "Login Error:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        if (inputHash == storedHash) {
            // SUCCÈS
            QMessageBox::information(this, "Succès", "Connexion réussie !");
            ui->Ajouter->setEnabled(true);
            ui->Modifier->setEnabled(true);
            ui->Supprimer->setEnabled(true);
            ui->rechercher->setEnabled(true);

            goToPage(ui->page);
            clearChamps();
            afficherEmployes();
        } else {
            QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
    }
}


// ==================== CRUD ====================

void GEmployer::onAjouterClicked()
{
    // --- 1. Récupérer tous les champs en QString ---
    QString idStr = ui->lineEditID_2->text();
    QString salaireStr = ui->lineEditSalaire_2->text();
    QString telephoneStr = ui->lineEditTelephone_2->text();
    QString nom = ui->lineEditNom_2->text();
    QString prenom = ui->lineEditPrenom_2->text();
    QString sexe = ui->lineEditSexe_2->text();
    QString tache = ui->lineEditTache_2->text();

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

void GEmployer::onModifierClicked()
{
    // (vous pouvez aussi ajouter les validations ici comme pour 'onAjouterClicked')
    int id = ui->lineEditID_2->text().toInt();
    float salaire = ui->lineEditSalaire_2->text().toInt();
    int telephone = ui->lineEditTelephone_2->text().toInt();
    QString nom = ui->lineEditNom_2->text();
    QString prenom = ui->lineEditPrenom_2->text();
    QString sexe = ui->lineEditSexe_2->text();
    QString tache = ui->lineEditTache_2->text();

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

void GEmployer::onSupprimerClicked()
{
    int id = ui->lineEditID_2->text().toInt();
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

void GEmployer::onRechercherClicked()
{
    QString critere = ui->lineEditRecherche->text();
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

void GEmployer::onTableEmployeClicked(int row, int column)
{
    (void)column; // Indique que 'column' n'est pas utilisé

    QTableWidgetItem *itemID = ui->tableWidgetEmployes->item(row, 0);
    QTableWidgetItem *itemNom = ui->tableWidgetEmployes->item(row, 1);
    QTableWidgetItem *itemPrenom = ui->tableWidgetEmployes->item(row, 2);
    QTableWidgetItem *itemTel = ui->tableWidgetEmployes->item(row, 3);
    QTableWidgetItem *itemSalaire = ui->tableWidgetEmployes->item(row, 4);
    QTableWidgetItem *itemSexe = ui->tableWidgetEmployes->item(row, 5);
    QTableWidgetItem *itemTache = ui->tableWidgetEmployes->item(row, 6);

    if (itemID) ui->lineEditID_2->setText(itemID->text());
    if (itemNom) ui->lineEditNom_2->setText(itemNom->text());
    if (itemPrenom) ui->lineEditPrenom_2->setText(itemPrenom->text());
    if (itemTel) ui->lineEditTelephone_2->setText(itemTel->text());
    if (itemSalaire) ui->lineEditSalaire_2->setText(itemSalaire->text());
    if (itemSexe) ui->lineEditSexe_2->setText(itemSexe->text());
    if (itemTache) ui->lineEditTache_2->setText(itemTache->text());
}

void GEmployer::afficherEmployes()
{
    QSqlQuery query(SELECT_QUERY);
    remplirTable(query);
}

void GEmployer::remplirTable(QSqlQuery &query)
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

void GEmployer::goToPage(QWidget *page)
{
    if (page && ui->stackedWidget->indexOf(page) != -1)
        ui->stackedWidget->setCurrentWidget(page);
}

void GEmployer::clearChamps()
{
    // Champs du Dashboard
    ui->lineEditID_2->clear();
    ui->lineEditNom_2->clear();
    ui->lineEditPrenom_2->clear();
    ui->lineEditSexe_2->clear();
    ui->lineEditTache_2->clear();
    ui->lineEditSalaire_2->clear();
    ui->lineEditTelephone_2->clear();

    // Champs de Login
    ui->lineEditLoginUsername->clear();
    ui->lineEditLoginPassword->clear();

    // Champs de Création de Compte
    if (ui->lineEditCreerId) ui->lineEditCreerId->clear();
    if (ui->lineEditCreerUsername) ui->lineEditCreerUsername->clear();
    if (ui->lineEditCreerPassword) ui->lineEditCreerPassword->clear();

    // Champs de Mot de Passe Oublié
    if (ui->lineEditMdpId) ui->lineEditMdpId->clear();
    if (ui->lineEditMdpUsername) ui->lineEditMdpUsername->clear();
    if (ui->lineEditNouveauPass) ui->lineEditNouveauPass->clear();
}


// ===============================================
// FONCTIONS (Création / Mot de passe)
// ===============================================

void GEmployer::on_pushButtonCreer_clicked()
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
}

void GEmployer::on_pushButtonReset_clicked()
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
    checkQuery.prepare("SELECT COUNT(*) FROM UTILISATEURS WHERE id = :id AND username = :username");
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
    updateQuery.prepare("UPDATE UTILISATEURS SET password_hash = :hash WHERE id = :id AND username = :username");
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

void GEmployer::on_pushButtonGoToCreer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    clearChamps();
}

void GEmployer::on_pushButtonGoToMdp_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_10);
    clearChamps();
}

void GEmployer::on_pushButtonRetourLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    clearChamps();
}

void GEmployer::on_pushButtonRetourLogin_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    clearChamps();
}

void GEmployer::on_pushButtonRetourLogin_3_cliked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_10);
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
void GEmployer::onTrierClicked()
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
void GEmployer::onExporterClicked()
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
void GEmployer::onStatistiquesClicked()
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
// gemployer.cpp

void GEmployer::on_pushButtonSuivant_clicked()
{
    // 1. Récupérer l'email saisi par l'utilisateur
    QString emailSaisi = ui->lineEditMdpEmail->text();

    if(emailSaisi.isEmpty()){
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre adresse email.");
        return;
    }

    // 2. Chercher si cet email existe dans la base de données
    // On récupère l'ID car on en aura besoin plus tard pour modifier le mot de passe
    QSqlQuery query;
    query.prepare("SELECT id FROM UTILISATEURS WHERE email = :email");
    query.bindValue(":email", emailSaisi);

    if(query.exec() && query.next()){
        // --- L'EMAIL EXISTE ---

        // A. On sauvegarde l'ID de l'utilisateur trouvé pour l'étape suivante (Page 4)
        this->idUtilisateurEnCours = query.value(0).toString();

        // B. Générer le code de vérification
        int code = QRandomGenerator::global()->bounded(1000, 9999);
        this->codeVerificationGenere = QString::number(code);

        // C. Envoyer l'email
        // (Remplacez par vos identifiants Gmail)
        Smtp *smtp = new Smtp("mo7it.re@gmail.com", "zfuj tzox yrss fpvj", "smtp.gmail.com", 465);

        QString sujet = "Code de réinitialisation de mot de passe";
        QString corps = "Votre code de vérification est : " + this->codeVerificationGenere;

        smtp->sendMail("mo7it.re@gmail.com", emailSaisi, sujet, corps);

        QMessageBox::information(this, "Succès", "Un code a été envoyé à : " + emailSaisi);

        // D. Aller à la page suivante (Page 4) pour entrer le code
        ui->lineEditCodeRecu->clear();
        ui->lineEditNouveauPass->clear();
        ui->stackedWidget->setCurrentWidget(ui->page_4);

    } else {
        // --- L'EMAIL N'EXISTE PAS ---
        QMessageBox::warning(this, "Erreur", "Cette adresse email ne correspond à aucun compte.");
    }
}
// gemployer.cpp

void GEmployer::on_pushButtonValiderReset_clicked()
{
    // 1. Récupérer les infos de la Page 4
    QString codeSaisi = ui->lineEditCodeRecu->text(); // Le champ du code
    QString nouveauPass = ui->lineEditNouveauPass->text(); // Le champ du nouveau MDP

    if (codeSaisi.isEmpty() || nouveauPass.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez tout remplir.");
        return;
    }

    // 2. Vérifier le code (comparer avec celui stocké à l'étape précédente)
    if (codeSaisi != this->codeVerificationGenere) {
        QMessageBox::critical(this, "Erreur", "Code incorrect ! Veuillez vérifier votre email.");
        return;
    }

    // 3. Si le code est bon, on met à jour le mot de passe
    QString newHash = hashPassword(nouveauPass); // Votre fonction de hachage

    QSqlQuery query;
    query.prepare("UPDATE UTILISATEURS SET password_hash = :hash WHERE id = :id");
    query.bindValue(":hash", newHash);
    query.bindValue(":id", this->idUtilisateurEnCours); // On utilise l'ID sauvegardé

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Mot de passe modifié avec succès !");

        // 4. Retour à la page de Login
        clearChamps(); // Votre fonction pour vider les textes
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    } else {
        QMessageBox::critical(this, "Erreur BDD", query.lastError().text());
    }
}

void GEmployer::on_pushButtonRetourLogin_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_10); // Démarrer sur la page login

}


void GEmployer::on_quitter_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quitter", "Voulez-vous vraiment quitter l'application ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

