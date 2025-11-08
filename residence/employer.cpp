#include "employer.h"
#include <QSqlError>
#include <QDebug>

employer::employer() {}

employer::employer(int id, float salaire, int telephone, QString nom, QString prenom, QString sexe, QString tache)
    : id(id), salaire(salaire), telephone(telephone), nom(nom), prenom(prenom), sexe(sexe), tache(tache) {}

bool employer::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYER (id_employe, nom, prenom, num_tel, salaire, sexe, responsabilite) "
                  "VALUES (:id_employe, :nom, :prenom, :num_tel, :salaire, :sexe, :responsabilite)");
    query.bindValue(":id_employe", id);
    query.bindValue(":salaire", salaire);
    query.bindValue(":num_tel", telephone);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":responsabilite", tache);

    if (!query.exec()) {
        qDebug() << "Erreur ajout:" << query.lastError().text();
        return false;
    }
    return true;
}
