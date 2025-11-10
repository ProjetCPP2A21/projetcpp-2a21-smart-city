#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Service
{
private:
    int id;
    QString nom;
    QString typeService;
    QString responsable;
    double budget;
    QString priorite;
    QString etat;

public:
    // Constructeurs
    Service();
    Service(int id, QString nom, QString typeService, QString responsable,
            double budget, QString priorite, QString etat);

    // Getters
    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getTypeService() const { return typeService; }
    QString getResponsable() const { return responsable; }
    double getBudget() const { return budget; }
    QString getPriorite() const { return priorite; }
    QString getEtat() const { return etat; }

    // Setters
    void setId(int id) { this->id = id; }
    void setNom(QString nom) { this->nom = nom; }
    void setTypeService(QString typeService) { this->typeService = typeService; }
    void setResponsable(QString responsable) { this->responsable = responsable; }
    void setBudget(double budget) { this->budget = budget; }
    void setPriorite(QString priorite) { this->priorite = priorite; }
    void setEtat(QString etat) { this->etat = etat; }

    // Opérations CRUD
    bool ajouter();                          // CREATE
    static QSqlQueryModel* afficher();       // READ (tous)
    static Service rechercherParId(int id);  // READ (un seul)
    bool modifier();                         // UPDATE
    static bool supprimer(int id);           // DELETE

    // Fonctions supplémentaires
    static QSqlQueryModel* rechercherParNom(QString nom);
    static QSqlQueryModel* filtrerParEtat(QString etat);
    static QSqlQueryModel* filtrerParPriorite(QString priorite);
    static QSqlQueryModel* trierPar(QString colonne, bool croissant = true);
    static int compterServices();
    static int compterParEtat(QString etat);
};

#endif // SERVICE_H
