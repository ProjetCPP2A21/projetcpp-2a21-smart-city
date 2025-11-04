#ifndef RESIDENTS_H
#define RESIDENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

// ====================
// Classe Modèle : Resident
// ====================
// Elle représente un résident et gère toutes les opérations CRUD
// (ajouter, afficher, supprimer, modifier, etc.)
// ====================

class Resident {
private:
    int identifiant;           // Identifiant unique
    QString nom;               // Nom du résident
    int age;                   // Âge du résident
    QString sexe;              // Sexe
    QString profession;        // Profession
    QString situationFamiliale; // Situation familiale

public:
    Resident();
    Resident(int, QString, int, QString, QString, QString);

    // Getters
    int getIdentifiant();
    QString getNom();
    int getAge();
    QString getSexe();
    QString getProfession();
    QString getSituationFamiliale();

    // Méthodes CRUD
    bool ajouter();                 // CREATE
    QSqlQueryModel* afficher();     // READ
    bool supprimer(int);            // DELETE
};

#endif // RESIDENT_H
