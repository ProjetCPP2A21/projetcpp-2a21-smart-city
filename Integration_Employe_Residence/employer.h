#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QString>
#include <QSqlQuery>

class employer
{
    int id, telephone;
    float salaire;
    QString nom, prenom, sexe, tache;

public:
    employer();
    employer(int id, float salaire, int telephone, QString nom, QString prenom, QString sexe, QString tache);
    bool ajouter();
};

#endif // EMPLOYER_H
