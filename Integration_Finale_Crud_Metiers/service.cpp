#include "service.h"
#include <QDebug>
#include <QSqlError>

// Constructeurs
Service::Service() : id(0), nom(""), typeService(""), responsable(""),
    budget(0.0), priorite("Medium"), etat("En attente")
{
    for(int i=0; i<12; ++i) budgetHistory[i] = 0;
}

Service::Service(int id, QString nom, QString typeService, QString responsable,
                 double budget, QString priorite, QString etat)
{
    this->id = id;
    this->nom = nom;
    this->typeService = typeService;
    this->responsable = responsable;
    this->budget = budget;
    this->priorite = priorite;
    this->etat = etat;
    for(int i=0; i<12; ++i) budgetHistory[i] = 0;
}

// ======= Getters =======
int Service::getId() const { return id; }
QString Service::getNom() const { return nom; }
QString Service::getTypeService() const { return typeService; }
QString Service::getResponsable() const { return responsable; }
double Service::getBudget() const { return budget; }
QString Service::getPriorite() const { return priorite; }
QString Service::getEtat() const { return etat; }

// ======= Setters =======
void Service::setId(int value) { id = value; }
void Service::setNom(QString value) { nom = value; }
void Service::setTypeService(QString value) { typeService = value; }
void Service::setResponsable(QString value) { responsable = value; }
void Service::setBudget(double value) { budget = value; }
void Service::setPriorite(QString value) { priorite = value; }
void Service::setEtat(QString value) { etat = value; }

// ======= IA / fonctionnalités supplémentaires =======
double Service::predictedBudget() const {
    double sum = 0;
    int count = 0;
    for(int i=0; i<12; ++i){
        if(budgetHistory[i] > 0){ sum += budgetHistory[i]; count++; }
    }
    return count > 0 ? sum / count : budget;
}

bool Service::isBudgetAnomaly() const {
    return budget > 1.5 * predictedBudget();
}

QString Service::autoPriority() const {
    double pred = predictedBudget();
    if(pred > 1000) return "High";
    else if(pred > 500) return "Medium";
    else return "Low";
}

void Service::setBudgetHistory(int monthIndex, double value) {
    if(monthIndex>=0 && monthIndex<12) budgetHistory[monthIndex] = value;
}

double Service::getBudgetHistory(int monthIndex) const {
    if(monthIndex>=0 && monthIndex<12) return budgetHistory[monthIndex];
    return 0;
}

// ======= CRUD =======
bool Service::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICE (NOM, TYPE_SERVICE, RESPONSABLE, BUDGET_P, NIVEAU_PR, ETAT) "
                  "VALUES (:nom, :type, :responsable, :budget, :priorite, :etat)");
    query.bindValue(":nom", nom);
    query.bindValue(":type", typeService);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);
    return query.exec();
}

QSqlQueryModel* Service::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICE ORDER BY ID_SERVICE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Responsable"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Priorité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("État"));
    return model;
}

Service Service::rechercherParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM SERVICE WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    Service service;
    if(query.exec() && query.next()) {
        service.setId(query.value(0).toInt());
        service.setNom(query.value(1).toString());
        service.setTypeService(query.value(2).toString());
        service.setResponsable(query.value(3).toString());
        service.setBudget(query.value(4).toDouble());
        service.setPriorite(query.value(5).toString());
        service.setEtat(query.value(6).toString());
    }
    return service;
}

bool Service::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE SERVICE SET NOM=:nom, TYPE_SERVICE=:type, RESPONSABLE=:responsable, "
                  "BUDGET_P=:budget, NIVEAU_PR=:priorite, ETAT=:etat WHERE ID_SERVICE=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", typeService);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);
    return query.exec();
}

bool Service::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICE WHERE ID_SERVICE=:id");
    query.bindValue(":id", id);
    return query.exec();
}

// ======= Fonctions supplémentaires =======
QSqlQueryModel* Service::rechercherParNom(QString nom) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM SERVICE WHERE NOM LIKE :nom OR RESPONSABLE LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Service::filtrerParEtat(QString etat) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM SERVICE WHERE ETAT=:etat");
    query.bindValue(":etat", etat);
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Service::filtrerParPriorite(QString priorite) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM SERVICE WHERE NIVEAU_PR=:priorite");
    query.bindValue(":priorite", priorite);
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Service::trierPar(QString colonne, bool croissant) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString ordre = croissant ? "ASC" : "DESC";
    model->setQuery("SELECT * FROM SERVICE ORDER BY " + colonne + " " + ordre);
    return model;
}

int Service::compterServices() {
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM SERVICE");
    if(query.next()) return query.value(0).toInt();
    return 0;
}

int Service::compterParEtat(QString etat) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SERVICE WHERE ETAT=:etat");
    query.bindValue(":etat", etat);
    query.exec();
    if(query.next()) return query.value(0).toInt();
    return 0;
}
