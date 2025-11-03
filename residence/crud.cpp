
#include "crud.h"
#include <QSqlError>
#include <QDebug>

CRUD::CRUD() {}

bool CRUD::ajouter(int id, QString nom, QString adresse, QString type,
                   int nbrUnite, int nbrHabitants, QString etat, QString dateCreation)
{
    QSqlQuery query;
    /*query.prepare("INSERT INTO RESIDENCE "
                  "(ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                  "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CREATION) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");*/
    query.prepare("INSERT INTO RESIDENCE (ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                  "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CREATION) "
                  "VALUES (:id, :nom, :adresse, :type, :nbrUnite, :nbrHabitants, :etat, TO_DATE(:dateCreation, 'YYYY-MM-DD'))");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":nbrUnite", nbrUnite);
    query.bindValue(":nbrHabitants", nbrHabitants);
    query.bindValue(":etat", etat);
    query.bindValue(":dateCreation", dateCreation);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Add error:" << query.lastError().text();
        return false;
    }
}
bool CRUD::modifier(int id, QString nom, QString adresse, QString type, int nbrUnite, int nbrHabitants, QString etat, QString dateCreation)
{
    QSqlQuery query;
    query.prepare("UPDATE RESIDENCE SET NOM=:nom, ADRESSE=:adresse, TYPE_RESIDENCE=:type, "
                  "NBR_UNITE=:nbrUnite, NBR_HABITANTS=:nbrHabitants, ETAT=:etat, "
                  "DATE_CREATION=TO_DATE(:dateCreation,'YYYY-MM-DD') WHERE ID_RESIDENCE=:id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":nbrUnite", nbrUnite);
    query.bindValue(":nbrHabitants", nbrHabitants);
    query.bindValue(":etat", etat);
    query.bindValue(":dateCreation", dateCreation);

    return query.exec();
}

bool CRUD::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RESIDENCE WHERE ID_RESIDENCE=:id");
    query.bindValue(":id", id);
    return query.exec();
}
