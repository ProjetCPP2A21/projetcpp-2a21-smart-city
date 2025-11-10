#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "residents.h"
#include <QMessageBox>

void MainWindow::on_Ajouter_Resident_clicked()
{
    int id_resident = ui->Id_resident->text().toInt();
    int id_residence = 250;
    QString nom = ui->Id_resident->text();
    QString prenom = ui->Prenom_Resident->text();
    int age = ui->Age_Resident->text().toInt();
    QString sexe = ui->Sexe_Resident->text();
    QString profession = ui->Profession_Resident->text();
    QString situation = ui->Situation_Fmiliale->text();

    Resident R(id_resident, id_residence, nom, prenom, age, sexe, profession, situation);

    if (R.ajouter()) {
        QMessageBox::information(this, "Succès", "Résident ajouté !");
        ui->tableView_Resident->setModel(R.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout échoué !");
    }
}


void MainWindow::on_Supprimer_Resident_clicked()
{
    int id = ui->Id_resident->text().toInt();
    Resident R;

    if (R.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Résident supprimé !");
        ui->tableView_Resident->setModel(R.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression échouée !");
    }
}

void MainWindow::on_Modifier_resident_clicked()
{
    int id_resident = ui->Id_resident->text().toInt();
    int id_residence = 250;
    QString nom = ui->Nom_Resident->text();
    QString prenom = ui->Prenom_Resident->text();
    int age = ui->Age_Resident->text().toInt();
    QString sexe = ui->Sexe_Resident->text();
    QString profession = ui->Profession_Resident->text();
    QString situation = ui->Situation_Fmiliale->text();

    Resident R(id_resident, id_residence, nom, prenom, age, sexe, profession, situation);

    if (R.modifier()) {
        QMessageBox::information(this, "Succès", "Résident modifié !");
        ui->tableView_Resident->setModel(R.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Modification échouée !");
    }
}

void MainWindow::on_Rechercher_Resident_textChanged(const QString &arg1)
{
    Resident R;
    ui->tableView_Resident->setModel(R.rechercher(arg1));
}

void MainWindow::on_comboBox_tri_Resident_currentIndexChanged(int index)
{
    Resident R;
    QString critere;

    if (index == 0)
        critere = "NOM";
    else if (index == 1)
        critere = "AGE";
    else if (index == 2)
        critere = "SEXE";

    ui->tableView_Resident->setModel(R.trier(critere, "ASC"));
}


