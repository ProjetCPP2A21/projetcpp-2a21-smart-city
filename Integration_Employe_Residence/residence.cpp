#include "residence.h"
#include "mainwindow.h"
#include "connection.h"
#include "CrudResidence.h"
#include <QMessageBox>
#include "ui_mainwindow.h"

void MainWindow::afficherTableResidence()
{
    // récupère DATE_CONST comme number
    QSqlQuery query("SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                    "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST FROM RESIDENCE");

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(8);

    QStringList headers;
    headers << "ID" << "Nom" << "Adresse" << "Type" << "Nbr Unités"
            << "Nbr Habitants" << "État" << "Date Création";
    ui->affichage->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->affichage->insertRow(row);
        // colonnes 0..6 : conversion normale
        for (int col = 0; col < 7; ++col) {
            ui->affichage->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }

        // colonne 7 = DATE_CONST (NUMBER) -> formater en "YYYY-MM-DD"
        int dateNum = query.value(7).toInt();
        QString dateStr = QString::number(dateNum);

        if (dateStr.length() >= 8) {
            // ex: 20240201 -> "2024-02-01"
            dateStr = dateStr.mid(0,4) + "-" + dateStr.mid(4,2) + "-" + dateStr.mid(6,2);
        }
        // sinon on laisse la valeur brute

        ui->affichage->setItem(row, 7, new QTableWidgetItem(dateStr));
        row++;
    }
}

void MainWindow::on_Ajouter_Residence_clicked()
{
    int id = ui->Id_Residence->text().toInt();
    QString nom = ui->Nom_Residence->text();
    QString adresse = ui->Adresse_Residence->text();
    QString type = ui->Type_Residence->text();
    int nbrUnite = ui->Nbr_Unites->text().toInt();
    int nbrHabitants = ui->Nbr_Habitants->text().toInt();
    QString etat = ui->Etat->text();
    QString dateCreation = ui->Date_Creation->text();

    if (crud.ajouter(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès", "Résidence ajoutée avec succès !");
        afficherTableResidence();
    } else {
        QMessageBox::critical(this, "Erreur", "L’ajout a échoué !");
    }
}


void MainWindow::on_Modifier_Residence_clicked()
{
    int id = ui->Id_Residence->text().toInt();
    QString nom = ui->Nom_Residence->text();
    QString adresse = ui->Adresse_Residence->text();
    QString type = ui->Type_Residence->text();
    int nbrUnite = ui->Nbr_Unites->text().toInt();
    int nbrHabitants = ui->Nbr_Habitants->text().toInt();
    QString etat = ui->Etat->text();
    QString dateCreation = ui->Date_Creation->text();

    if (crud.modifier(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès","Résidence modifiée !");
        afficherTableResidence();

    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué !");
    }
}


void MainWindow::on_Supprimer_Residence_clicked()
{
    int id = ui->Id_Residence->text().toInt();

    if (crud.supprimer(id)) {
        QMessageBox::information(this, "Succès","Résidence supprimer !");
        afficherTableResidence();

    } else {
        QMessageBox::critical(this, "Erreur", "La suppression a échoué !");
    }
}
