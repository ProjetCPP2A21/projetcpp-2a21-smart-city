#include "residents.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

Resident::Resident() {}

Resident::Resident(int idRes, int idResidence, QString n, QString p, int a, QString s, QString prof, QString sit)
{
    id_resident = idRes;
    id_residence = idResidence;
    nom = n;
    prenom = p;
    age = a;
    sexe = s;
    profession = prof;
    situation_familiale = sit;
}

bool Resident::ajouter()
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO RESIDENT "
        "(ID_RESIDENT, ID_RESIDENCE, NOM, PRENOM, AGE, SEXE, PROFESSION, SITUATION_FAMILIALE) "
        "VALUES (:id_resident, :id_residence, :nom, :prenom, :age, :sexe, :profession, :situation_familiale)"
        );

    query.bindValue(":id_resident", id_resident);
    query.bindValue(":id_residence", id_residence);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":sexe", sexe);
    query.bindValue(":profession", profession);
    query.bindValue(":situation_familiale", situation_familiale);

    if (!query.exec()) {
        qDebug() << "Erreur SQL (ajouter) :" << query.lastError().text();
        return false;
    }

    return true;
}

QSqlQueryModel* Resident::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(
        "SELECT "
        "ID_RESIDENT, "
        "ID_RESIDENCE, "
        "NOM, "
        "PRENOM, "
        "AGE, "
        "SEXE, "
        "PROFESSION, "
        "SITUATION_FAMILIALE "
        "FROM RESIDENT"
        );

    return model;
}

bool Resident::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RESIDENT WHERE ID_RESIDENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL (supprimer) :" << query.lastError().text();
        return false;
    }

    return true;
}

bool Resident::modifier()
{
    QSqlQuery query;
    query.prepare(
        "UPDATE RESIDENT "
        "SET ID_RESIDENCE=:id_residence, NOM=:nom, PRENOM=:prenom, AGE=:age, "
        "SEXE=:sexe, PROFESSION=:profession, SITUATION_FAMILIALE=:situation_familiale "
        "WHERE ID_RESIDENT=:id_resident"
        );

    query.bindValue(":id_resident", id_resident);
    query.bindValue(":id_residence", id_residence);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":sexe", sexe);
    query.bindValue(":profession", profession);
    query.bindValue(":situation_familiale", situation_familiale);

    if (!query.exec()) {
        qDebug() << "Erreur SQL (modifier) :" << query.lastError().text();
        return false;
    }

    return true;
}

QSqlQueryModel* Resident::rechercher(QString texte)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // 1. On reprend EXACTEMENT les mêmes colonnes que dans afficher()
    // pour ne pas casser l'ordre dans le tableau et le clic.
    QString queryStr = "SELECT "
                       "ID_RESIDENT, "
                       "ID_RESIDENCE, "
                       "NOM, "
                       "PRENOM, "
                       "AGE, "
                       "SEXE, "
                       "PROFESSION, "
                       "SITUATION_FAMILIALE "
                       "FROM RESIDENT "
                       "WHERE ";

    // 2. On utilise UPPER() pour ignorer la casse (majuscule/minuscule)
    // Exemple : UPPER(NOM) LIKE UPPER('%texte%')
    queryStr += "UPPER(NOM) LIKE UPPER('%" + texte + "%') OR "
                                                     "UPPER(PRENOM) LIKE UPPER('%" + texte + "%') OR "
                          "UPPER(SEXE) LIKE UPPER('%" + texte + "%') OR "
                          "UPPER(PROFESSION) LIKE UPPER('%" + texte + "%')";

    model->setQuery(queryStr);

    // Petit debug pour voir si la requête échoue dans la console
    if (model->lastError().isValid()) {
        qDebug() << "Erreur recherche :" << model->lastError().text();
    }

    return model;
}

QSqlQueryModel* Resident::trier(QString critere, QString ordre)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(
        "SELECT * FROM RESIDENT ORDER BY " + critere + " " + ordre
        );

    return model;
}
