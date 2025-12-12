
#include "CrudResidence.h"
#include "connection.h"
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>


CRUD::CRUD() {}


bool CRUD::ajouter(int id, QString nom, QString adresse, QString type,
                   int nbrUnite, int nbrHabitants, QString etat, QString dateCreation)
{
    // 1️⃣ Convert date to number
    QString dateNumberString = dateCreation;
    dateNumberString.remove("-");
    int dateNumber = dateNumberString.toInt();

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM RESIDENCE WHERE ID_RESIDENCE = :id");
    checkQuery.bindValue(":id", id);
    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Erreur vérification ID:" << checkQuery.lastError().text();
        return false;
    }

    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Erreur", "Cet ID existe déjà !");
        return false; // Stop ajouter
    }

    // 2️⃣ Insert new record
    QSqlQuery query;
    query.prepare("INSERT INTO RESIDENCE "
                  "(ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST) "
                  "VALUES (:id, :nom, :adresse, :type, :nbrUnite, :nbrHabitants, :etat, :dateConst)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":nbrUnite", nbrUnite);
    query.bindValue(":nbrHabitants", nbrHabitants);
    query.bindValue(":etat", etat);
    query.bindValue(":dateConst", dateNumber);

    if (!query.exec()) {
        qDebug() << "Erreur ajout:" << query.lastError().text();
        return false;
    }

    return true;
}

bool CRUD::modifier(int id, QString nom, QString adresse, QString type,
                    int nbrUnite, int nbrHabitants, QString etat, QString dateCreation)
{
    // Convert YYYY-MM-DD → YYYYMMDD (int)
    QString dateNumberString = dateCreation;
    dateNumberString.remove("-");
    int dateNumber = dateNumberString.toInt();

    QSqlQuery query;
    query.prepare("UPDATE RESIDENCE SET "
                  "NOM = :nom, "
                  "ADRESSE = :adresse, "
                  "TYPE_RESIDENCE = :type, "
                  "NBR_UNITE = :nbrUnite, "
                  "NBR_HABITANTS = :nbrHabitants, "
                  "ETAT = :etat, "
                  "DATE_CONST = :dateConst "
                  "WHERE ID_RESIDENCE = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":nbrUnite", nbrUnite);
    query.bindValue(":nbrHabitants", nbrHabitants);
    query.bindValue(":etat", etat);
    query.bindValue(":dateConst", dateNumber);
    query.bindValue(":id", id);

    return query.exec();
}

// DANS CrudResidence.cpp

bool CRUD::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM RESIDENCE WHERE ID_RESIDENCE=:id");
    query.bindValue(":id", id);

    // On exécute la requête
    bool succes = query.exec();

    // CORRECTION : On vérifie si une ligne a VRAIMENT été touchée
    // numRowsAffected() renvoie le nombre de lignes supprimées.
    if (succes && query.numRowsAffected() > 0) {
        return true; // Supprimé pour de vrai
    }

    return false; // Requête passée, mais rien n'a été supprimé (ID introuvable)
}

QSqlQuery CRUD::rechercherParID(int id)
{
    QSqlQuery query;
    // CORRECTION : On enlève TO_CHAR/TO_DATE et on prend juste DATE_CONST brut
    query.prepare("SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                  "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST "
                  "FROM RESIDENCE WHERE ID_RESIDENCE = :id");

    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur recherche:" << query.lastError().text();
    }

    return query;
}


QSqlQueryModel* CRUD::trierParNbrHabitants()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlDatabase db = Connection::instance().getDatabase();
    if (!db.isOpen()) {
        if (!Connection::instance().createConnection()) {
            qDebug() << "Impossible d'ouvrir la base de données pour le tri";
            return nullptr;
        }
    }

    QString sql = R"(
        SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE,
               NBR_UNITE, NBR_HABITANTS, ETAT,
               DATE_CONST
        FROM RESIDENCE
        ORDER BY NBR_HABITANTS ASC
    )";

    model->setQuery(sql,db);  // PASS THE DATABASE

    if (model->lastError().isValid()) {
        qDebug() << "Erreur tri TEST SQL:" << model->lastError().text();
    } else {
        qDebug() << "Test query executed. Rows found:" << model->rowCount(); // <-- CRITICAL CHECK
    }

    return model;
}





QSqlQuery CRUD::statistiquesHabitants()
{
    QSqlQuery query;
    QString sql = R"(
        SELECT
            CASE
                WHEN NBR_HABITANTS BETWEEN 0 AND 50 THEN '0-50'
                WHEN NBR_HABITANTS BETWEEN 51 AND 100 THEN '51-100'
                WHEN NBR_HABITANTS BETWEEN 101 AND 200 THEN '101-200'
                ELSE '200+'
            END AS RANGE_HABITANTS,
            COUNT(*) AS TOTAL
        FROM RESIDENCE
        GROUP BY
            CASE
                WHEN NBR_HABITANTS BETWEEN 0 AND 50 THEN '0-50'
                WHEN NBR_HABITANTS BETWEEN 51 AND 100 THEN '51-100'
                WHEN NBR_HABITANTS BETWEEN 101 AND 200 THEN '101-200'
                ELSE '200+'
            END
        ORDER BY RANGE_HABITANTS
    )";

    query.exec(sql);
    return query;
}

