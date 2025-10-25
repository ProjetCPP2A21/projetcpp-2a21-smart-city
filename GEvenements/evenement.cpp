#include "evenement.h"
#include <QString>

Evenement::Evenement(int ID, QString Nom, QString Type, int Date, int Heure, QString Lieu, int Nbr_Participants)
{
    this->ID = ID;
    this->Nom = Nom;
    this->Type = Type;
    this->Date = Date;
    this->Heure = Heure;
    this->Lieu = Lieu;
    this->Nbr_Participants = Nbr_Participants;
}

 bool Evenement::ajouter()
{
     QSqlQuery query;
    QString res = QString::number(ID);
     query.prepare("insert into evenement (ID_Evenement, Nom, Type, Date, Heure, Lieu, Nbr_Participants;)""values (:ID_Evenement, :Nom, :Type, :Date, :Heure, :Lieu, :Nbr_Participants");
    // liaison entre les attributs de la classe et de la table en base de donnée
    query.bindValue(":ID_Evenement", ID);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Type", Type);
    query.bindValue(":Date", Date);
    query.bindValue(":Heure", Heure);
    query.bindValue(":Lieu", Lieu);
    query.bindValue(":Nbr_Participants", Nbr_Participants);
    return query.exec();

}
