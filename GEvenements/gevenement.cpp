#include "gevenement.h"
#include "ui_gevenement.h"
#include "evenement.h"
#include "connection.h"
#include <QString>
#include <QMessageBox>
#include <QTableView>
#include <QSqlDatabase>

GEvenement::GEvenement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEvenement)
{
    ui->setupUi(this);
    ui->tableView->setModel(E.afficher());
}

GEvenement::~GEvenement()
{
    delete ui;
}



void GEvenement::on_Ajouterbutton_clicked()
{
    bool ok;
    int id = ui->ID->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }
    int ID_Employe = 1;
    QString Nom = ui->Nom->text();
    QString Type = ui->Type->text();
    QString Lieu = ui->Lieu->text();
    QString Date = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString Heure = ui->timeEdit->time().toString("HH:mm");
    int Nbr_Participants = ui->NbrP->text().toInt();

    Evenement E(id, ID_Employe, Nom, Type, Date, Heure, Lieu, Nbr_Participants);
    bool test = E.ajouter();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue avec Succes\n""Click Cancel to exit."),QMessageBox::Cancel);
        //Vider les champs
        ui->ID->clear();
        ui->Nom->clear();
        ui->Type->clear();
        ui->Lieu->clear();
        ui->NbrP->clear();
        ui->dateEdit->setDate(QDate::currentDate());
        ui->timeEdit->setTime(QTime::currentTime());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectue !!\n""Click Cancel to exit."), QMessageBox::Cancel);
    }


}


void GEvenement::on_Supprimer_clicked()
{
    bool ok;
    int id = ui->ID->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }
    bool test = E.supprimer(id);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Supression effectue avec Succes\n""Click Cancel to exit."),QMessageBox::Cancel);
        //Vider le champs ID :
        ui->ID->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectue !!\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}
