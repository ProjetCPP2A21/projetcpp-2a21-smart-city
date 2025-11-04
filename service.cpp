#include "service.h"
#include <QDebug>
#include <QSqlError>
#include <utility>

// Constructeurs
Service::Service()
{
    id = 0;
    nom = "";
    typeService = "";
    responsable = "";
    budget = 0.0;
    priorite = "Moyen";
    etat = "En attente";
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
}

// CREATE - Ajouter un service
bool Service::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICE (NOM, TYPE_SERVICE, RESPONSABLE, BUDGET_P, NIVEAU_PR, ETAT) "
                  "VALUES (:nom, :type, :responsable, :budget, :priorite, :etat)");

    query.bindValue(":nom", nom);
    query.bindValue(":type", typeService);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);

    if (query.exec()) {
        qDebug() << "Service ajouté avec succès";
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout:" << query.lastError().text();
        return false;
    }
}

// READ - Afficher tous les services
QSqlQueryModel* Service::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICE ORDER BY ID_SERVICE");

    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Responsable"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Priorité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("État"));

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage:" << model->lastError().text();
    }

    return model;
}

// READ - Rechercher un service par ID
Service Service::rechercherParId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM SERVICE WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    Service service;

    if (query.exec() && query.next()) {
        service.setId(query.value(0).toInt());
        service.setNom(query.value(1).toString());
        service.setTypeService(query.value(2).toString());
        service.setResponsable(query.value(3).toString());
        service.setBudget(query.value(4).toDouble());
        service.setPriorite(query.value(5).toString());
        service.setEtat(query.value(6).toString());
        qDebug() << "Service trouvé:" << service.getNom();
    } else {
        qDebug() << "Service non trouvé ou erreur:" << query.lastError().text();
    }

    return service;
}

// UPDATE - Modifier un service
bool Service::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE SERVICE SET NOM = :nom, TYPE_SERVICE = :type, "
                  "RESPONSABLE = :responsable, BUDGET_P = :budget, "
                  "NIVEAU_PR = :priorite, ETAT = :etat "
                  "WHERE ID_SERVICE = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", typeService);
    query.bindValue(":responsable", responsable);
    query.bindValue(":budget", budget);
    query.bindValue(":priorite", priorite);
    query.bindValue(":etat", etat);

    if (query.exec()) {
        qDebug() << "Service modifié avec succès";
        return true;
    } else {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }
}

// DELETE - Supprimer un service
bool Service::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICE WHERE ID_SERVICE = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Service supprimé avec succès";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }
}

// Rechercher par nom
QSqlQueryModel* Service::rechercherParNom(QString nom)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM SERVICE WHERE NOM LIKE :nom OR RESPONSABLE LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    query.exec();
    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Responsable"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Priorité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("État"));

    return model;
}

// Filtrer par état
QSqlQueryModel* Service::filtrerParEtat(QString etat)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM SERVICE WHERE ETAT = :etat");
    query.bindValue(":etat", etat);

    query.exec();
    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Responsable"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Priorité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("État"));

    return model;
}

// Filtrer par priorité
QSqlQueryModel* Service::filtrerParPriorite(QString priorite)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM SERVICE WHERE NIVEAU_PR = :priorite");
    query.bindValue(":priorite", priorite);

    query.exec();
    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Responsable"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Priorité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("État"));

    return model;
}

// Trier par colonne
QSqlQueryModel* Service::trierPar(QString colonne, bool croissant)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString ordre = croissant ? "ASC" : "DESC";
    QString requete = "SELECT * FROM SERVICE ORDER BY " + colonne + " " + ordre;

    model->setQuery(requete);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Responsable"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Priorité"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("État"));

    return model;
}

// Compter le nombre total de services
int Service::compterServices()
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SERVICE");

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

// Compter les services par état
int Service::compterParEtat(QString etat)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SERVICE WHERE ETAT = :etat");
    query.bindValue(":etat", etat);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}
