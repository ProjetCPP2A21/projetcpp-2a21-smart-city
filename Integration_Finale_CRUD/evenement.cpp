#include "evenement.h"
#include "connection.h"
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <iostream>
#include <QCoreApplication>



//costructeur par défaut
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
// constructeur paramétré
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

// ajouter un évènement
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
// supprimer un évènement
bool Evenement::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from Evenement where ID_Evenement = :id");
    query.bindValue(":id", res);
    return query.exec();
}
// afficher un évènement
QSqlQueryModel *Evenement::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel();
   model->setQuery("SELECT * FROM Evenement");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_Evenement"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Type_Evenement"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Date_Evenement"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("Nbr_Participants"));
    return model;
}
// modifier un évènement
bool Evenement::modifier(int id)
{
    QSqlQuery query(QSqlDatabase::database("oracleConnection")); // utilise la connexion existante

    query.prepare("UPDATE Evenement "
                  "SET Nom = :nom, "
                  "Type_Evenement = :type, "
                  "Date_Evenement = :date, "
                  "Heure = :heure, "
                  "Lieu = :lieu, "
                  "Nbr_Participants = :nbr "
                  "WHERE ID_Evenement = :id");

    query.bindValue(":nom", Nom);
    query.bindValue(":type", Type);
    query.bindValue(":date", Date);
    query.bindValue(":heure", Heure);
    query.bindValue(":lieu", Lieu);
    query.bindValue(":nbr", Nbr_Participants);
    query.bindValue(":id", id);

    if(!query.exec())
    {
        qDebug() << "Erreur modification Evenement :" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel *Evenement::rechercher(int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Vérifie si l'ID existe
    QSqlQuery query;
    query.prepare("SELECT * FROM Evenement WHERE ID_Evenement = :id");
    query.bindValue(":id", id);
    query.exec();

    if (!query.next()) { // aucun résultat
        return nullptr; // on retournera nullptr si ID invalide
    }

    // Si ID existe, on le charge dans le modèle
    model->setQuery(query);

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_Evenement"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_Evenement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_Evenement"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nbr_Participants"));

    return model;
}

