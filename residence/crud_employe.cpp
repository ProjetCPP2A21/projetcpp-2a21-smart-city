#include "crud_employe.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include "connection.h"
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QRegularExpression>
#include <QPushButton>

// Définition de la requête SELECT pour garantir l'ordre des colonnes
// L'ordre doit correspondre à vos en-têtes : {"ID", "nom", "prenom", "telephone", "salaire", "Sexe", "Tâche"}
const QString SELECT_QUERY = "SELECT id_employe, nom, prenom, num_tel, salaire, sexe, responsabilite FROM EMPLOYER";

CRUD_emp::CRUD_emp(QSqlDatabase &db, Ui::MainWindow *mainUi, QObject *parent)
    : QObject(parent),
    ui(mainUi),
    m_bd(db)
{
    qDebug() << "CRUD_emp constructor done. Buttons connected?";


    /*ui->setupUi(ui->stackedWidget);*/
    connect(ui->ajouter, SIGNAL(clicked()),
            this, SLOT(onajouterClicked()));

    // Connect the table view for Read/Update functionality
    connect(ui->tableWidgetEmployes, SIGNAL(cellClicked(int,int)), this, SLOT(onTableEmployeClicked(int,int)));







    if (!m_bd.isOpen()) {
        QMessageBox::critical(ui->stackedWidget, "Database Error", "The database connection is closed.");
        qCritical() << "CRUD_emp received a closed database connection.";
    }

    // ==================== TABLE SETUP ====================
    ui->tableWidgetEmployes->setColumnCount(7);
    QStringList headers = {"ID", "nom", "prenom", "telephone", "salaire", "Sexe", "Tâche"};
    ui->tableWidgetEmployes->setHorizontalHeaderLabels(headers);
    ui->tableWidgetEmployes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEmployes->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // ==================== LOGIN PAGE ====================
    /*ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->Ajouter->setEnabled(true);
    ui->Modifier->setEnabled(true);
    ui->Supprimer->setEnabled(true);
    ui->rechercher->setEnabled(true);*/

    // --- CORRECTION LOGIN ---
    // Le bouton "connecter" doit appeler la fonction de login
    /*connect(ui->connecter, &QPushButton::clicked, this, &CRUD_emp::onLoginClicked); // Modifié*/
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->ajouter->setEnabled(true);
    ui->Modifier->setEnabled(true);
    ui->Supprimer->setEnabled(true);
    ui->rechercher->setEnabled(true);

    // ==================== CRUD BUTTONS ====================
    connect(ui->ajouter, SIGNAL(clicked()), this, SLOT(onajouterClicked()));
    connect(ui->Modifier, SIGNAL(clicked()), this, SLOT(onModifierClicked()));
    connect(ui->Supprimer, SIGNAL(clicked()), this, SLOT(onSupprimerClicked()));
    connect(ui->rechercher, SIGNAL(clicked()), this, SLOT(onRechercherClicked()));
    connect(ui->tableWidgetEmployes, SIGNAL(cellClicked(int,int)), this, SLOT(onTableEmployeClicked(int,int)));


}


// ==================== LOGIN ====================
/*void CRUD_emp::onLoginClicked() // Modifié
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM USERS WHERE USERNAME = :username AND PASSWORD = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la connexion à la base !");
        return;
    }

    if (query.next()) {
        QMessageBox::information(this, "Succès", "Connexion réussie !");
        ui->Ajouter->setEnabled(true);
        ui->Modifier->setEnabled(true);
        ui->Supprimer->setEnabled(true);
        ui->rechercher->setEnabled(true);

        // --- CORRECTION NAVIGATION ---
        // Aller au dashboard (page principale), pas à la page de login
        goToPage(ui->page); // Anciennement: ui->stackedWidget->setCurrentWidget(ui->page_2);

        clearChamps();
        afficherEmployes();
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
    }
}*/

// ==================== CRUD ====================

// --- MISE À JOUR ---
// Ajout des contrôles de saisie (validation)
void CRUD_emp::onajouterClicked()
{
    qDebug() << "Ajouter clicked!";
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
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "Tous les champs doivent être remplis.");
        return;
    }
    if (!regexID.match(idStr).hasMatch()) {
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "L'ID ne doit contenir que des chiffres.");
        return;
    }
    if (!regexTexte.match(nom).hasMatch()) {
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "Le Nom ne doit contenir que des lettres.");
        return;
    }
    if (!regexTexte.match(prenom).hasMatch()) {
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "Le Prénom ne doit contenir que des lettres.");
        return;
    }
    if (!regexTel.match(telephoneStr).hasMatch()) {
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }
    if (!regexSalaire.match(salaireStr).hasMatch()) {
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "Le salaire doit être un nombre entier valide.");
        return;
    }
    QString sexeLower = sexe.toLower();
    if (sexeLower != "homme" && sexeLower != "femme") {
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "Le Sexe doit être 'homme' ou 'femme'.");
        return;
    }
    if (!regexTexte.match(tache).hasMatch()) {
        QMessageBox::warning(ui->stackedWidget, "Erreur de saisie", "La Tâche (Responsabilité) ne doit contenir que des lettres.");
        return;
    }

    // --- 4. Si tout est valide, convertir et créer l'objet ---
    int id = idStr.toInt();
    int salaire = salaireStr.toInt();
    int telephone = telephoneStr.toInt();
    sexe = sexeLower.replace(0, 1, sexeLower.at(0).toUpper()); // Met "Homme" ou "Femme"

    employer e(id,salaire,telephone,nom,  prenom,  sexe, tache);
    if (e.ajouter()) {
        QMessageBox::information(ui->stackedWidget, "Succès", "Employé ajouté avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(ui->stackedWidget, "Erreur", "Échec de l'ajout ! (Vérifiez si l'ID existe déjà)");
    }
}

void CRUD_emp::onModifierClicked() // Modifié
{
    qDebug() << "Modifier clicked!";
    // ... (votre code pour modifier est correct)
    // ... (vous pouvez aussi ajouter les validations ici)
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
        QMessageBox::information(ui->stackedWidget, "Succès", "Employé modifié avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(ui->stackedWidget, "Erreur", "Échec de la modification !");
        qDebug() << "Erreur modif:" << query.lastError().text();
    }
}

void CRUD_emp::onSupprimerClicked() // Modifié
{
    qDebug() << "Supprimer clicked!";
    // ... (votre code pour supprimer est correct)
    int id = ui->lineEditID_2->text().toInt();
    if (id == 0) {
        QMessageBox::warning(ui->stackedWidget, "Attention", "Veuillez entrer un ID valide !");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYER WHERE id_employe=?");
    query.addBindValue(id);

    if (query.exec()) {
        QMessageBox::information(ui->stackedWidget, "Succès", "Employé supprimé avec succès !");
        afficherEmployes();
        clearChamps();
    } else {
        QMessageBox::critical(ui->stackedWidget, "Erreur", "Échec de la suppression !");
        qDebug() << "Erreur suppression:" << query.lastError().text();
    }
}
// ==================== TABLE CLICK ====================

/*void CRUD_emp::onTableEmployeClicked(int row, int column)
{
    'column' n'est pas utilisé ici, seule la ligne 'row' nous intéresse
    (void)column;
    Q_UNUSED(column);

    // Récupérer les 'items' de la ligne cliquée
    // Nous vérifions si l'item existe (n'est pas nullptr) avant de lire son texte

    QTableWidgetItem *itemID = ui->tableWidgetEmployes->item(row, 0);
    QTableWidgetItem *itemNom = ui->tableWidgetEmployes->item(row, 1);
    QTableWidgetItem *itemPrenom = ui->tableWidgetEmployes->item(row, 2);
    QTableWidgetItem *itemTel = ui->tableWidgetEmployes->item(row, 3);
    QTableWidgetItem *itemSalaire = ui->tableWidgetEmployes->item(row, 4);
    QTableWidgetItem *itemSexe = ui->tableWidgetEmployes->item(row, 5);
    QTableWidgetItem *itemTache = ui->tableWidgetEmployes->item(row, 6);

    // Remplir les champs (LineEdits) avec le texte des items

    if (itemID)
        ui->lineEditID_2->setText(itemID->text());

    if (itemNom)
        ui->lineEditNom_2->setText(itemNom->text());

    if (itemPrenom)
        ui->lineEditPrenom_2->setText(itemPrenom->text());

    if (itemTel)
        ui->lineEditTelephone_2->setText(itemTel->text());

    if (itemSalaire)
        ui->lineEditSalaire_2->setText(itemSalaire->text());

    if (itemSexe)
        ui->lineEditSexe_2->setText(itemSexe->text());

    if (itemTache)
        ui->lineEditTache_2->setText(itemTache->text());
}*/
void CRUD_emp::onTableEmployeClicked(int row, int column)
{
    Q_UNUSED(column); // We don't need column here

    // Make sure the row is valid
    if (row < 0 || row >= ui->tableWidgetEmployes->rowCount())
        return;

    // Get items from the clicked row
    QTableWidgetItem *itemID     = ui->tableWidgetEmployes->item(row, 0);
    QTableWidgetItem *itemNom    = ui->tableWidgetEmployes->item(row, 1);
    QTableWidgetItem *itemPrenom = ui->tableWidgetEmployes->item(row, 2);
    QTableWidgetItem *itemTel    = ui->tableWidgetEmployes->item(row, 3);
    QTableWidgetItem *itemSalaire= ui->tableWidgetEmployes->item(row, 4);
    QTableWidgetItem *itemSexe   = ui->tableWidgetEmployes->item(row, 5);
    QTableWidgetItem *itemTache  = ui->tableWidgetEmployes->item(row, 6);

    // Fill the line edits if the items exist
    if (itemID)      ui->lineEditID_2->setText(itemID->text());
    if (itemNom)     ui->lineEditNom_2->setText(itemNom->text());
    if (itemPrenom)  ui->lineEditPrenom_2->setText(itemPrenom->text());
    if (itemTel)     ui->lineEditTelephone_2->setText(itemTel->text());
    if (itemSalaire) ui->lineEditSalaire_2->setText(itemSalaire->text());
    if (itemSexe)    ui->lineEditSexe_2->setText(itemSexe->text());
    if (itemTache)   ui->lineEditTache_2->setText(itemTache->text());

    // Enable the CRUD buttons
    ui->Ajouter->setEnabled(true);
    ui->Modifier->setEnabled(true);
    ui->Supprimer->setEnabled(true);
    ui->rechercher->setEnabled(true);

    // Switch to the detail page
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}

void CRUD_emp::onRechercherClicked() // Modifié
{
    qDebug() << "Recehrcher clicked!";
    // ... (votre code pour rechercher est correct)
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
        QMessageBox::critical(ui->stackedWidget, "Erreur", "Échec de la recherche !");
        qDebug() << "Erreur recherche:" << query.lastError().text();
        return;
    }
    remplirTable(query);
}

// ==================== TABLE ====================
void CRUD_emp::afficherEmployes() // Modifié
{
    QSqlQuery query(SELECT_QUERY);
    remplirTable(query);
}

void CRUD_emp::remplirTable(QSqlQuery &query) // Modifié
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
void CRUD_emp::clearChamps() // Modifié
{
    ui->lineEditID_2->clear();
    ui->lineEditNom_2->clear();
    ui->lineEditPrenom_2->clear();
    ui->lineEditSexe_2->clear();
    ui->lineEditTache_2->clear();
    ui->lineEditSalaire_2->clear();
    ui->lineEditTelephone_2->clear();
    /*ui->lineEditUsername->clear();
    ui->lineEditPassword->clear();*/
}

void CRUD_emp::goToPage(QWidget *page) // Modifié
{
    if (page && ui->stackedWidget->indexOf(page) != -1)
        ui->stackedWidget->setCurrentWidget(page);
}

CRUD_emp::~CRUD_emp()
{
    delete ui;
}
