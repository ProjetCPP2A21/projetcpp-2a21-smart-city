#include "Gservice.h"
#include "service.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// ========== CONSTRUCTEUR ==========

/**
 * Constructeur du Widget (fenêtre principale)
 * Initialise l'interface et connecte les signaux/slots
 */

/**
 * Destructeur - Libère la mémoire de l'interface
 */


// ========== AFFICHER TOUS LES SERVICES ==========

/**
 * Afficher tous les services dans le tableau
 * Cette fonction charge les données depuis Oracle et les affiche
 */
void MainWindow::afficherServices()
{
    // Créer une requête SQL pour récupérer les services
    // Sélectionner toutes les colonnes nécessaires
    QSqlQuery query("SELECT ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                    "BUDGET_P, NIVEAU_PR, ETAT FROM SERVICE");

    // Effacer toutes les lignes existantes du tableau
    ui->tableServices->setRowCount(0);

    // Variable pour compter les lignes
    int row = 0;

    // Parcourir tous les résultats de la requête
    while (query.next()) {
        // Insérer une nouvelle ligne dans le tableau
        ui->tableServices->insertRow(row);

        // Remplir chaque cellule de la ligne avec les données Oracle
        // query.value(index) récupère la valeur de la colonne index
        // new QTableWidgetItem() crée un élément pour le tableau

        // Colonne 0 du tableau = NOM (colonne 1 de la requête)
        ui->tableServices->setItem(row, 0,
                                   new QTableWidgetItem(query.value(1).toString()));

        // Colonne 1 du tableau = TYPE_SERVICE (colonne 2 de la requête)
        ui->tableServices->setItem(row, 1,
                                   new QTableWidgetItem(query.value(2).toString()));

        // Colonne 2 du tableau = RESPONSABLE (colonne 3 de la requête)
        ui->tableServices->setItem(row, 2,
                                   new QTableWidgetItem(query.value(3).toString()));

        // Colonne 3 du tableau = BUDGET_P (colonne 4 de la requête)
        ui->tableServices->setItem(row, 3,
                                   new QTableWidgetItem(query.value(4).toString()));

        // Colonne 4 du tableau = NIVEAU_PR (colonne 5 de la requête)
        ui->tableServices->setItem(row, 4,
                                   new QTableWidgetItem(query.value(5).toString()));

        // Colonne 5 du tableau = ETAT (colonne 6 de la requête)
        ui->tableServices->setItem(row, 5,
                                   new QTableWidgetItem(query.value(6).toString()));

        // Colonne 6 du tableau (cachée) = ID_SERVICE (colonne 0 de la requête)
        // On stocke l'ID pour pouvoir modifier/supprimer plus tard
        ui->tableServices->setItem(row, 6,
                                   new QTableWidgetItem(query.value(0).toString()));

        // Passer à la ligne suivante
        row++;
    }

    // Ajuster automatiquement la largeur des colonnes au contenu
    ui->tableServices->resizeColumnsToContents();
}

// ========== AJOUTER UN SERVICE ==========

/**
 * Ajouter un nouveau service dans la base de données
 * Récupère les valeurs des champs du formulaire et les insère dans Oracle
 */
void MainWindow::on_Ajouter_Service_clicked()
{
    // ========== RÉCUPÉRATION DES DONNÉES DU FORMULAIRE ==========

    QString nom = ui->Nom_Service->text();              // Champ "Nom"
    QString type = ui->Type_Service->currentText();         // ComboBox "Type"
    QString responsable = ui->Responsable_Service->text();// Champ "Responsable"
    double budget = ui->spin_budget->value();             // SpinBox "Budget"
    QString priorite = ui->combo_priority->currentText(); // ComboBox "Priorité"
    QString etat = ui->combo_state->currentText();        // ComboBox "État"

    // ========== VALIDATION DES DONNÉES ==========

    // Vérifier que le nom n'est pas vide
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le nom du service est obligatoire!");
        return;  // Arrêter la fonction
    }

    // Vérifier que le responsable n'est pas vide
    if (responsable.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le responsable est obligatoire!");
        return;
    }
    // Vérifier que le responsable contient uniquement des lettres et espaces
    QRegularExpression regex("^[A-Za-zÀ-ÿ\\s]+$");
    if (!regex.match(responsable).hasMatch()) {
        QMessageBox::warning(this, "Attention",
                             "Le nom du responsable ne doit contenir que des lettres et des espaces !");
        return;
    }
    // ========== CALCULER LE PROCHAIN ID ==========

    // Trouver le plus grand ID existant et ajouter 1
    // NVL(MAX(ID_SERVICE), 0) retourne 0 si la table est vide
    QSqlQuery queryMax;
    queryMax.exec("SELECT NVL(MAX(ID_SERVICE), 0) + 1 FROM SERVICE");

    int newId = 1;  // Par défaut, le premier ID sera 1
    if (queryMax.next()) {
        newId = queryMax.value(0).toInt();
    }

    // Afficher l'ID calculé dans la console (pour déboguer)
    qDebug() << "Prochain ID calculé automatiquement:" << newId;

    // ========== INSERTION DANS LA BASE DE DONNÉES ==========

    QSqlQuery query;

    // Préparer la requête INSERT
    // On INCLUT maintenant ID_SERVICE avec la valeur calculée
    query.prepare("INSERT INTO SERVICE (ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                  "BUDGET_P, NIVEAU_PR, ETAT) "
                  "VALUES (:id, :nom, :type, :responsable, :budget, :priorite, :etat)");

    // Lier les valeurs du formulaire aux placeholders
    query.bindValue(":id", newId);           // ID calculé automatiquement
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);

    // Exécuter la requête
    if (query.exec()) {
        // ========== SUCCÈS ==========

        // Afficher un message de succès
        QMessageBox::information(this, "Succès",
                                 "Service ajouté avec succès!");

        // Rafraîchir le tableau pour afficher le nouveau service
        afficherServices();

        // Vider les champs du formulaire
        viderChamps();
    } else {
        // ========== ERREUR ==========

        // Récupérer le message d'erreur Oracle
        QString erreur = query.lastError().text();

        // Afficher un message d'erreur à l'utilisateur
        QMessageBox::critical(this, "Erreur",
                              "Échec de l'ajout:\n" + erreur);

        // Afficher des informations de débogage dans la console
        qDebug() << "✗ Erreur SQL:" << erreur;
        qDebug() << "Requête:" << query.lastQuery();
        qDebug() << "ID utilisé:" << newId;
    }
}

// ========== MODIFIER UN SERVICE ==========

/**
 * Modifier un service existant dans la base de données
 * L'utilisateur doit d'abord sélectionner un service dans le tableau
 */

void MainWindow::on_Modifier_Service_clicked()
{
    // ========== VÉRIFICATION DE LA SÉLECTION ==========

    // Récupérer l'ID du champ (qui doit être rempli après sélection)
    QString idText = ui->ID_Service->text();

    // Vérifier qu'un service est sélectionné
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Veuillez d'abord sélectionner un service dans le tableau !");
        return;
    }

    // Convertir l'ID en nombre
    int id = idText.toInt();

    // Vérifier que l'ID est valide (> 0)
    if (id <= 0) {
        QMessageBox::warning(this, "Attention",
                             "ID de service invalide. Sélectionnez un service dans le tableau.");
        return;
    }

    // ========== RÉCUPÉRATION DES NOUVELLES VALEURS ==========

    QString nom = ui->Nom_Service->text();
    QString type = ui->Type_Service->currentText();
    QString responsable = ui->Responsable_Service->text();
    double budget = ui->spin_budget->value();
    QString priorite = ui->combo_priority->currentText();
    QString etat = ui->combo_state->currentText();

    // ========== VALIDATION ==========

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le nom du service est obligatoire!");
        return;
    }

    if (responsable.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Le responsable est obligatoire!");
        return;
    }

    // ========== DÉBOGAGE (optionnel) ==========

    qDebug() << "========== MODIFICATION ==========";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << nom;
    qDebug() << "Type:" << type;
    qDebug() << "Responsable:" << responsable;
    qDebug() << "Budget:" << budget;
    qDebug() << "Priorité:" << priorite;
    qDebug() << "État:" << etat;

    // ========== MISE À JOUR DANS LA BASE DE DONNÉES ==========

    QSqlQuery query;

    // Préparer la requête UPDATE
    query.prepare("UPDATE SERVICE SET "
                  "NOM = :nom, "
                  "TYPE_SERVICE = :type, "
                  "RESPONSABLE = :responsable, "
                  "BUDGET_P = :budget, "
                  "NIVEAU_PR = :priorite, "
                  "ETAT = :etat "
                  "WHERE ID_SERVICE = :id");

    // Lier les valeurs
    query.bindValue(":id", id);              // L'ID identifie le service à modifier
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);

    // Exécuter la requête
    if (query.exec()) {
        // Vérifier si une ligne a été modifiée
        if (query.numRowsAffected() > 0) {
            // ========== SUCCÈS ==========

            QMessageBox::information(this, "Succès",
                                     "Service modifié avec succès!");

            // Rafraîchir le tableau
            afficherServices();

            // Vider les champs
            viderChamps();
        } else {
            // Aucune ligne modifiée (l'ID n'existe pas)
            QMessageBox::warning(this, "Attention",
                                 "Aucun service trouvé avec cet ID.\n"
                                 "Il a peut-être été supprimé.");
        }
    } else {
        // ========== ERREUR ==========

        QString erreur = query.lastError().text();

        QMessageBox::critical(this, "Erreur",
                              "Échec de la modification:\n" + erreur);

        qDebug() << "✗ Erreur SQL:" << erreur;
        qDebug() << "Requête:" << query.lastQuery();
    }
}


// ========== SUPPRIMER UN SERVICE ==========

/**
 * Supprimer un service de la base de données
 * Demande confirmation avant de supprimer
 */
void MainWindow::on_Supprimer_Service_clicked()
{
    // ========== VÉRIFICATION DE LA SÉLECTION ==========

    QString idText = ui->ID_Service->text();

    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Attention",
                             "Veuillez sélectionner un service à supprimer!");
        return;
    }

    // ========== DEMANDER CONFIRMATION ==========

    // Afficher une boîte de dialogue de confirmation
    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Confirmation",
                                    "Êtes-vous sûr de vouloir supprimer ce service?",
                                    QMessageBox::Yes | QMessageBox::No);

    // Si l'utilisateur clique sur "Non", annuler la suppression
    if (reponse != QMessageBox::Yes) {
        return;
    }

    // ========== SUPPRESSION DANS LA BASE DE DONNÉES ==========

    int id = idText.toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM SERVICE WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        // ========== SUCCÈS ==========

        QMessageBox::information(this, "Succès",
                                 "Service supprimé avec succès!");

        // Rafraîchir le tableau
        afficherServices();

        // Vider les champs
        viderChamps();
    } else {
        // ========== ERREUR ==========

        QString erreur = query.lastError().text();

        QMessageBox::critical(this, "Erreur",
                              "Échec de la suppression:\n" + erreur);

        qDebug() << "✗ Erreur SQL:" << erreur;
    }
}


// ========== RECHERCHER UN SERVICE ==========

/**
 * Rechercher des services par nom ou responsable
 * Affiche uniquement les services correspondant à la recherche
 */
void MainWindow::on_rechercher_Service_clicked()
{
    // Récupérer le texte de recherche
    QString critere = ui->Nom_3->text();

    // Si le champ est vide, afficher tous les services
    if (critere.isEmpty()) {
        afficherServices();
        return;
    }

    // ========== RECHERCHE DANS LA BASE DE DONNÉES ==========

    QSqlQuery query;

    // Recherche partielle avec LIKE
    // Cherche dans NOM et RESPONSABLE
    query.prepare("SELECT ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                  "BUDGET_P, NIVEAU_PR, ETAT "
                  "FROM SERVICE "
                  "WHERE NOM LIKE :critere OR RESPONSABLE LIKE :critere");

    // % = n'importe quels caractères
    query.bindValue(":critere", "%" + critere + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur",
                              "Erreur de recherche:\n" + query.lastError().text());
        return;
    }

    // ========== AFFICHER LES RÉSULTATS ==========

    // Effacer le tableau
    ui->tableServices->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableServices->insertRow(row);

        // Remplir les cellules avec les résultats
        ui->tableServices->setItem(row, 0,
                                   new QTableWidgetItem(query.value(1).toString()));
        ui->tableServices->setItem(row, 1,
                                   new QTableWidgetItem(query.value(2).toString()));
        ui->tableServices->setItem(row, 2,
                                   new QTableWidgetItem(query.value(3).toString()));
        ui->tableServices->setItem(row, 3,
                                   new QTableWidgetItem(query.value(4).toString()));
        ui->tableServices->setItem(row, 4,
                                   new QTableWidgetItem(query.value(5).toString()));
        ui->tableServices->setItem(row, 5,
                                   new QTableWidgetItem(query.value(6).toString()));
        ui->tableServices->setItem(row, 6,
                                   new QTableWidgetItem(query.value(0).toString()));

        row++;
    }

    ui->tableServices->resizeColumnsToContents();
}


// ========== SÉLECTIONNER UN SERVICE DANS LE TABLEAU ==========

/**
 * Quand l'utilisateur clique sur une ligne du tableau,
 * remplir les champs du formulaire avec les données de cette ligne
 *
 * @param row Le numéro de la ligne cliquée
 * @param column Le numéro de la colonne cliquée (non utilisé)
 */
void MainWindow::on_tableServices_cellActivated(int row, int column)
{
    Q_UNUSED(column);  // On n'utilise pas la colonne

    // ========== VÉRIFICATION ==========

    // Vérifier que la ligne existe
    if (row < 0 || row >= ui->tableServices->rowCount()) {
        qDebug() << "✗ Ligne invalide:" << row;
        return;
    }

    // ========== RÉCUPÉRATION DES DONNÉES ==========

    // Récupérer l'ID depuis la colonne 6 (cachée)
    QTableWidgetItem* idItem = ui->tableServices->item(row, 6);
    if (!idItem) {
        qDebug() << "✗ ID introuvable à la ligne" << row;
        return;
    }

    QString id = idItem->text();
    QString nom = ui->tableServices->item(row, 0)->text();
    QString type = ui->tableServices->item(row, 1)->text();
    QString responsable = ui->tableServices->item(row, 2)->text();
    QString budget = ui->tableServices->item(row, 3)->text();
    QString priorite = ui->tableServices->item(row, 4)->text();
    QString etat = ui->tableServices->item(row, 5)->text();

    // ========== DÉBOGAGE ==========

    qDebug() << "========== SERVICE SÉLECTIONNÉ ==========";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << nom;

    // ========== REMPLIR LES CHAMPS DU FORMULAIRE ==========

    ui->ID_Service->setText(id);                    // Champ ID
    ui->Nom_Service->setText(nom);                 // Champ Nom
    ui->Type_Service->setCurrentText(type);            // ComboBox Type
    ui->Responsable_Service->setText(responsable);  // Champ Responsable
    ui->spin_budget->setValue(budget.toDouble());    // SpinBox Budget
    ui->combo_priority->setCurrentText(priorite);    // ComboBox Priorité
    ui->combo_state->setCurrentText(etat);           // ComboBox État

}

void MainWindow::on_tableServices_itemSelectionChanged()
{
    int row = ui->tableServices->currentRow();
    if (row < 0) return;

    // Récupérer l'ID (supposons qu'il est en colonne 6)
    QTableWidgetItem* idItem = ui->tableServices->item(row, 6);
    QString id = idItem ? idItem->text() : QString();

    // Récupérer les autres cellules en vérifiant les nullptr
    QTableWidgetItem* itNom = ui->tableServices->item(row, 0);
    QTableWidgetItem* itType = ui->tableServices->item(row, 1);
    QTableWidgetItem* itResp = ui->tableServices->item(row, 2);
    QTableWidgetItem* itBudget = ui->tableServices->item(row, 3);
    QTableWidgetItem* itPrior = ui->tableServices->item(row, 4);
    QTableWidgetItem* itEtat = ui->tableServices->item(row, 5);

    QString nom = itNom ? itNom->text() : QString();
    QString type = itType ? itType->text() : QString();
    QString responsable = itResp ? itResp->text() : QString();
    QString budgetStr = itBudget ? itBudget->text() : QString();
    QString priorite = itPrior ? itPrior->text() : QString();
    QString etat = itEtat ? itEtat->text() : QString();

    // ========== DÉBOGAGE ==========
    qDebug() << "========== SERVICE SÉLECTIONNÉ ==========";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << nom << "Type:" << type << "Resp:" << responsable << "Budget:" << budgetStr;

    // ========== REMPLIR LES CHAMPS DU FORMULAIRE ==========
    ui->ID_Service->setText(id);
    ui->Nom_Service->setText(nom);

    // Combobox Type : on essaie de trouver l'index correspondant
    int idxType = ui->Type_Service->findText(type);
    if (idxType >= 0) ui->Type_Service->setCurrentIndex(idxType);
    else ui->Type_Service->setCurrentText(type); // ou laisser tel quel

    ui->Responsable_Service->setText(responsable);

    // Conversion sécurisée du budget
    bool ok = false;
    double budgetVal = budgetStr.toDouble(&ok);
    if (ok) {
        // si spin_budget est QDoubleSpinBox -> setValue(budgetVal)
        // si c'est QSpinBox -> cast en int
        ui->spin_budget->setValue((int) qRound(budgetVal));
    } else {
        ui->spin_budget->setValue(0); // valeur par défaut si conversion échoue
    }

    int idxPrior = ui->combo_priority->findText(priorite);
    if (idxPrior >= 0) ui->combo_priority->setCurrentIndex(idxPrior);
    else ui->combo_priority->setCurrentText(priorite);

    int idxEtat = ui->combo_state->findText(etat);
    if (idxEtat >= 0) ui->combo_state->setCurrentIndex(idxEtat);
    else ui->combo_state->setCurrentText(etat);
}

// ========== TRIER LES SERVICES ==========

/**
 * Trier les services selon le critère choisi dans le ComboBox
 *
 * @param index L'index sélectionné dans le ComboBox (0=Budget, 1=Priorité, 2=État)
 */
void MainWindow::trierServices(int index)
{
    // Déterminer la colonne de tri selon l'index
    QString colonne;

    switch(index) {
    case 0: colonne = "BUDGET_P"; break;    // Trier par budget
    case 1: colonne = "NIVEAU_PR"; break;   // Trier par priorité
    case 2: colonne = "ETAT"; break;        // Trier par état
    default: colonne = "ID_SERVICE"; break; // Par défaut, trier par ID
    }

    // ========== REQUÊTE AVEC TRI ==========

    QSqlQuery query("SELECT ID_SERVICE, NOM, TYPE_SERVICE, RESPONSABLE, "
                    "BUDGET_P, NIVEAU_PR, ETAT "
                    "FROM SERVICE ORDER BY " + colonne);

    // ========== AFFICHER LES RÉSULTATS TRIÉS ==========

    ui->tableServices->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableServices->insertRow(row);

        ui->tableServices->setItem(row, 0,
                                   new QTableWidgetItem(query.value(1).toString()));
        ui->tableServices->setItem(row, 1,
                                   new QTableWidgetItem(query.value(2).toString()));
        ui->tableServices->setItem(row, 2,
                                   new QTableWidgetItem(query.value(3).toString()));
        ui->tableServices->setItem(row, 3,
                                   new QTableWidgetItem(query.value(4).toString()));
        ui->tableServices->setItem(row, 4,
                                   new QTableWidgetItem(query.value(5).toString()));
        ui->tableServices->setItem(row, 5,
                                   new QTableWidgetItem(query.value(6).toString()));
        ui->tableServices->setItem(row, 6,
                                   new QTableWidgetItem(query.value(0).toString()));

        row++;
    }

    ui->tableServices->resizeColumnsToContents();
}


// ========== VIDER LES CHAMPS DU FORMULAIRE ==========

/**
 * Réinitialiser tous les champs du formulaire
 * Appelé après un ajout, modification ou suppression réussi
 */
void MainWindow::viderChamps()
{
    ui->ID_Service->clear();                        // Vider l'ID
    ui->Nom_Service->clear();                      // Vider le nom
    ui->Responsable_Service->clear();               // Vider le responsable
    ui->Type_Service->setCurrentIndex(0);              // Réinitialiser le type
    ui->spin_budget->setValue(0);                    // Mettre le budget à 0
    ui->combo_priority->setCurrentIndex(0);          // Réinitialiser la priorité
    ui->combo_state->setCurrentIndex(0);             // Réinitialiser l'état
    ui->dateEdit_date->setDate(QDate::currentDate());// Date du jour
}
