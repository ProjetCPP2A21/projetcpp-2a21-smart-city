#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
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
    double budgetHistory[12];
    QString priorite;
    QString etat;

public:
    // Constructeurs
    Service();
    Service(int id, QString nom, QString typeService, QString responsable,
            double budget, QString priorite, QString etat);

    // Getters
    int getId() const;
    QString getNom() const;
    QString getTypeService() const;
    QString getResponsable() const;
    double getBudget() const;
    QString getPriorite() const;
    QString getEtat() const;

    // Setters
    void setId(int id);
    void setNom(QString nom);
    void setTypeService(QString typeService);
    void setResponsable(QString responsable);
    void setBudget(double budget);
    void setPriorite(QString priorite);
    void setEtat(QString etat);

    // ================== IA / Fonctionnalités supplémentaires ==================
    double predictedBudget() const;
    bool isBudgetAnomaly() const;
    QString autoPriority() const;
    void setBudgetHistory(int monthIndex, double value);
    double getBudgetHistory(int monthIndex) const;

    // ================== Opérations CRUD ==================
    bool ajouter();
    static QSqlQueryModel* afficher();
    static Service rechercherParId(int id);
    bool modifier();
    static bool supprimer(int id);

    // ================== Fonctions supplémentaires ==================
    static QSqlQueryModel* rechercherParNom(QString nom);
    static QSqlQueryModel* filtrerParEtat(QString etat);
    static QSqlQueryModel* filtrerParPriorite(QString priorite);
    static QSqlQueryModel* trierPar(QString colonne, bool croissant = true);
    static int compterServices();
    static int compterParEtat(QString etat);
};

#endif // SERVICE_H
