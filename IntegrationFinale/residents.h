#ifndef RESIDENT_H
#define RESIDENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Resident
{
private:
    int id_resident;
    int id_residence;
    QString nom;
    QString prenom;
    int age;
    QString sexe;
    QString profession;
    QString situation_familiale;

public:
    Resident();
    Resident(int, int, QString, QString, int, QString, QString, QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* rechercher(QString texte);
    QSqlQueryModel* trier(QString critere, QString ordre);
};

#endif // RESIDENT_H
