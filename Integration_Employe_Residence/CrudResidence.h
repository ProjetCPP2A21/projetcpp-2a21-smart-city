#ifndef CRUD_H
#define CRUD_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class CRUD
{
public:
    CRUD(); // constructor

    bool ajouter(int id, QString nom, QString adresse, QString type,
                 int nbrUnite, int nbrHabitants, QString etat, QString dateCreation);
    bool modifier(int id, QString nom, QString adresse, QString type,
                  int nbrUnite, int nbrHabitants, QString etat, QString dateCreation);
    bool supprimer(int id);
    QSqlQueryModel* afficher();
};

#endif // CRUD_H
