#include "employer.h"
#include "gemployer.h"
#include "connection.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QRegularExpression> // <-- AJOUTÉ POUR LA VALIDATION

// Définition de la requête SELECT pour garantir l'ordre des colonnes
// L'ordre doit correspondre à vos en-têtes : {"ID", "nom", "prenom", "telephone", "salaire", "Sexe", "Tâche"}
const QString SELECT_QUERY = "SELECT id_employe, nom, prenom, num_tel, salaire, sexe, responsabilite FROM EMPLOYE";
// ==================== TABLE ====================
void MainWindow::afficherEmployes() // Modifié
{
    QSqlQuery query(SELECT_QUERY);
    remplirTable(query);
}
// ==================== LOGIN ====================
void MainWindow::on_connecter_clicked()
{

    QString username = ui->Username->text();
    QString password = ui->Motdepasse->text();

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
        ui->Ajouter_Employe->setEnabled(true);
        ui->Modifier_Employe->setEnabled(true);
        ui->Supprimer_Employe->setEnabled(true);
        ui->Rechercher_Employe->setEnabled(true);

        // --- CORRECTION NAVIGATION ---
        // Aller au dashboard (page principale), pas à la page de login
        goToPage(ui->page); // Anciennement: ui->stackedWidget->setCurrentWidget(ui->page_2);

        clearChamps();
        afficherEmployes();
    } else {
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
    }
}


// ==================== CRUD ====================

// --- MISE À JOUR ---
// Ajout des contrôles de saisie (validation)
void MainWindow::on_Ajouter_Employe_clicked()
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


void MainWindow::on_Modifier_Employe_clicked()
{
    // ... (votre code pour modifier est correct)
    // ... (vous pouvez aussi ajouter les validations ici)
    int id = ui->ID_Employe->text().toInt();
    float salaire = ui->Salaire->text().toInt();
    int telephone = ui->Telephone_Employe->text().toInt();
    QString nom = ui->Nom_Employe->text();
    QString prenom = ui->Prenom_Employe->text();
    QString sexe = ui->Sexe_Employe->text();
    QString tache = ui->Responsabilite->text();

    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET nom=?, prenom=?, sexe=?, responsabilite=?, salaire=?, num_tel=? WHERE id_employe=?");
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

void MainWindow::on_Supprimer_Employe_clicked()
{
    // ... (votre code pour supprimer est correct)
    int id = ui->ID_Employe->text().toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide !");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE id_employe=?");
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

// ==================== TABLE CLICK ====================
void MainWindow::on_tableWidgetEmployes_cellClicked(int row, int column)
{
    // 'column' n'est pas utilisé ici, seule la ligne 'row' nous intéresse
    (void)column;

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
        ui->ID_Employe->setText(itemID->text());

    if (itemNom)
        ui->Nom_Employe->setText(itemNom->text());

    if (itemPrenom)
        ui->Prenom_Employe->setText(itemPrenom->text());

    if (itemTel)
        ui->Telephone_Employe->setText(itemTel->text());

    if (itemSalaire)
        ui->Salaire->setText(itemSalaire->text());

    if (itemSexe)
        ui->Sexe_Employe->setText(itemSexe->text());

    if (itemTache)
        ui->Responsabilite->setText(itemTache->text());
}

void MainWindow::on_Rechercher_Employe_2_clicked()
{
    // ... (votre code pour rechercher est correct)
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



void MainWindow::remplirTable(QSqlQuery &query) // Modifié
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
void MainWindow::clearChamps() // Modifié
{
    ui->ID_Employe->clear();
    ui->Nom_Employe->clear();
    ui->Prenom_Employe->clear();
    ui->Sexe_Employe->clear();
    ui->Responsabilite->clear();
    ui->Salaire->clear();
    ui->Telephone_Employe->clear();
    ui->Username->clear();
    ui->Motdepasse->clear();
}




