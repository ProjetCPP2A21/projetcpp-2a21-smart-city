#include "evenement.h"
#include "connection.h"
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlDatabase>


Evenement::Evenement()
{
    ID = 0;
    Nom = "";
    Type = "";
    Date = "";
    Heure = "";
    Lieu = "";
    Nbr_Participants = 0;
}

Evenement::Evenement(int ID,int ID_Employe, QString Nom, QString Type, QString Date, QString Heure, QString Lieu, int Nbr_Participants)
{
    this->ID = ID;
    this->ID_Employe = ID_Employe;
    this->Nom = Nom;
    this->Type = Type;
    this->Date = Date;
    this->Heure = Heure;
    this->Lieu = Lieu;
    this->Nbr_Participants = Nbr_Participants;
}

Evenement::~Evenement() {}


 bool Evenement::ajouter()
{
     QSqlQuery query;
    QString res = QString::number(ID);
     query.prepare("INSERT INTO evenement (ID_Evenement, ID_Employe, Nom, Type_Evenement, Date_Evenement, Heure, Lieu, Nbr_Participants) "
                   "VALUES (:ID_Evenement, :ID_Employe, :Nom, :Type_Evenement, :Date_Evenement, :Heure, :Lieu, :Nbr_Participants)");
    // liaison entre les attributs de la classe et de la table en base de donnée
    query.bindValue(":ID_Evenement", ID);
    query.bindValue(":ID_Employe", ID_Employe);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Type_Evenement", Type);
    query.bindValue(":Date_Evenement", Date);
    query.bindValue(":Heure", Heure);
    query.bindValue(":Lieu", Lieu);
    query.bindValue(":Nbr_Participants", Nbr_Participants);

    return query.exec();
}

bool Evenement::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from Evenement where ID_Evenement = :id");
    query.bindValue(":id", res);
    return query.exec();
}

QSqlQueryModel *Evenement::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel();
   model->setQuery("SELECT * FROM Evenement");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_Evenement"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Type_Evenement"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date_Evenement"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Nbr_Participants"));
    return model;
}
