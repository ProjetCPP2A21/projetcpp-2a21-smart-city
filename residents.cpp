#include "residents.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Resident::Resident() {}
Resident::Resident(int identifiant, QString nom, int age, QString sexe, QString profession, QString situationFamiliale) {
    this->identifiant = identifiant;
    this->nom = nom;
    this->age = age;
    this->sexe = sexe;
    this->profession = profession;
    this->situationFamiliale = situationFamiliale;
}

int Resident::getIdentifiant() { return identifiant; }
QString Resident::getNom() { return nom; }
int Resident::getAge() { return age; }
QString Resident::getSexe() { return sexe; }
QString Resident::getProfession() { return profession; }
QString Resident::getSituationFamiliale() { return situationFamiliale; }

// --- CREATE ---
bool Resident::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO resident (identifiant, nom, age, sexe, profession, situation_familiale) "
                  "VALUES (:identifiant, :nom, :age, :sexe, :profession, :situation)");
    query.bindValue(":identifiant", identifiant);
    query.bindValue(":nom", nom);
    query.bindValue(":age", age);
    query.bindValue(":sexe", sexe);
    query.bindValue(":profession", profession);
    query.bindValue(":situation", situationFamiliale);
    return query.exec();
}

// --- READ ---
QSqlQueryModel* Resident::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM resident");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Âge"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Profession"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Situation familiale"));
    return model;
}

// --- DELETE ---
bool Resident::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM resident WHERE identifiant = :id");
    query.bindValue(":id", id);
    return query.exec();
}
