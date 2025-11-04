#ifndef SERVICEC_H
#define SERVICEC_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

// ============================================================================
// Classe ServiceC : gère les opérations CRUD sur la table SERVICE
// ============================================================================
class ServiceC
{
public:
    // Constructeurs
    ServiceC();
    ServiceC(int id, QString nom, QString type, double cout);

    // Méthodes CRUD
    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficher();

private:
    // Attributs (mappés à la table SERVICE)
    int id_service;
    QString nom_service;
    QString type_service;
    double cout;
};

#endif // SERVICEC_H
