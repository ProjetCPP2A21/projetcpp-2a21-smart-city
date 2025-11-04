#include "servicec.h"

// ============================================================================
// Constructeurs
// ============================================================================
ServiceC::ServiceC() {}  // Constructeur vide

ServiceC::ServiceC(int id, QString nom, QString type, double cout)
{
    this->id_service = id;
    this->nom_service = nom;
    this->type_service = type;
    this->cout = cout;
}

// ============================================================================
// Fonction : ajouter()
// ============================================================================
bool ServiceC::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICE (ID_SERVICE, NOM_SERVICE, TYPE_SERVICE, COUT) "
                  "VALUES (:id, :nom, :type, :cout)");
    query.bindValue(":id", id_service);
    query.bindValue(":nom", nom_service);
    query.bindValue(":type", type_service);
    query.bindValue(":cout", cout);

    return query.exec();
}

// ============================================================================
// Fonction : supprimer()
// ============================================================================
bool ServiceC::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICE WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    return query.exec();
}

// ============================================================================
// Fonction : modifier()
// ============================================================================
bool ServiceC::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE SERVICE SET NOM_SERVICE=:nom, TYPE_SERVICE=:type, COUT=:cout WHERE ID_SERVICE=:id");
    query.bindValue(":id", id_service);
    query.bindValue(":nom", nom_service);
    query.bindValue(":type", type_service);
    query.bindValue(":cout", cout);

    return query.exec();
}

// ============================================================================
// Fonction : afficher()
// ============================================================================
QSqlQueryModel* ServiceC::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Service"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Coût"));

    return model;
}
