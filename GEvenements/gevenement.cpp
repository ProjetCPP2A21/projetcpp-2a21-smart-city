#include "gevenement.h"
#include "ui_gevenement.h"
#include "evenement.h"
#include "connection.h"
#include <QString>
#include <QMessageBox>
#include <QTableView>
#include <QSqlDatabase>
#include <onnxruntime_cxx_api.h>

GEvenement::GEvenement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEvenement)
{
    ui->setupUi(this);
    ui->tableView->setModel(E.afficher());
}

GEvenement::~GEvenement()
{
    delete ui;
}



void GEvenement::on_Ajouterbutton_clicked()
{
    bool ok;
    int id = ui->ID->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }
    int ID_Employe = 1;
    QString Nom = ui->Nom->text();
    QString Type = ui->Type->text();
    QString Lieu = ui->Lieu->text();
    QString Date = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString Heure = ui->timeEdit->time().toString("HH:mm");
    int Nbr_Participants = ui->NbrP->text().toInt();

    Evenement E(id, ID_Employe, Nom, Type, Date, Heure, Lieu, Nbr_Participants);
    bool test = E.ajouter();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue avec Succes\n""Click Cancel to exit."),QMessageBox::Cancel);
        ui->tableView->setModel(E.afficher());
        //Vider les champs
        ui->ID->clear();
        ui->Nom->clear();
        ui->Type->clear();
        ui->Lieu->clear();
        ui->NbrP->clear();
        ui->dateEdit->setDate(QDate::currentDate());
        ui->timeEdit->setTime(QTime::currentTime());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectue !!\n""Click Cancel to exit."), QMessageBox::Cancel);
    }


}


void GEvenement::on_Supprimer_clicked()
{
    bool ok;
    int id = ui->ID->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }
    bool test = E.supprimer(id);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Supression effectue avec Succes\n""Click Cancel to exit."),QMessageBox::Cancel);
        //Vider le champs ID :
        ui->tableView->setModel(E.afficher());
        ui->ID->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectue !!\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void GEvenement::on_Modifier_clicked()
{
        // récupères l'ID sélectionné dans la tableView
        int id = ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0).data().toInt();
        QSqlQuery query(QSqlDatabase::database("qt_sql_default_connection"));
        query.prepare("SELECT Nom, Type_Evenement, Date_Evenement, Heure, Lieu, Nbr_Participants FROM Evenement WHERE ID_Evenement = :id");
        query.bindValue(":id", id);
        query.exec();
        query.next();

        // Utiliser les anciennes valeurs si les champs sont vides
        QString nom   = ui->Nom->text().isEmpty()      ? query.value(0).toString() : ui->Nom->text();
        QString type  = ui->Type->text().isEmpty()     ? query.value(1).toString() : ui->Type->text();
        QString date  = ui->dateEdit->text().isEmpty() ? query.value(2).toString() : ui->dateEdit->text();
        QString heure = ui->timeEdit->text().isEmpty() ? query.value(3).toString() : ui->timeEdit->text();
        QString lieu  = ui->Lieu->text().isEmpty()     ? query.value(4).toString() : ui->Lieu->text();
        int nbr       = ui->NbrP->text().isEmpty()     ? query.value(5).toInt()    : ui->NbrP->text().toInt();

        // Mettre à jour l’objet E AVEC les valeurs corrigées
        E.setNom(nom);
        E.setType(type);
        E.setDate(date);
        E.setHeure(heure);
        E.setLieu(lieu);
        E.setNbr_Participants(nbr);

        if(E.modifier(id))
        {
            QMessageBox::information(this, "Modifier", "Événement modifié avec succès");
            ui->tableView->setModel(E.afficher()); // rafraîchir l'affichage
            ui->Nom->clear();
            ui->Type->clear();
            ui->dateEdit->clear();
            ui->timeEdit->clear();
            ui->Lieu->clear();
            ui->NbrP->clear();
        }
        else
        {
            QMessageBox::warning(this, "Modifier", "Erreur lors de la modification");
        }

}




void GEvenement::on_Rechercher_clicked()
{
    QString textId = ui->Recherche_Line->text();

    // Si le champ est vide → afficher tout le tableau
    if (textId.isEmpty()) {
        QMessageBox::warning(this, "Recherche", "Veuillez saisir un ID !");
        ui->tableView->setModel(E.afficher()); // réutilise ta fonction afficher()
        return;
    }

    int id = textId.toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Recherche", "ID invalide !");
        return;
    }

    QSqlQueryModel *model = E.rechercher(id);

    if (!model) {
        QMessageBox::warning(this, "Recherche", "Aucun événement trouvé avec cet ID.");
        return;
    }

    ui->tableView->setModel(model);
    QMessageBox::information(this, "Recherche", "Résultat de la recherche affiché !");
}


void GEvenement::on_Prediction_clicked()
{
    int id = ui->Id_Evenement->text().toInt();
    int nbr = ui->NombreP->text().toInt();

    float impact = E.predireImpact(id, nbr);

    if (impact >= 0) {
        ui->Prediction->setText(QString("Impact prédicté : %1").arg(impact));
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de charger le modèle ONNX.");
    }
}


void GEvenement::on_tableView_clicked(const QModelIndex &index)
{
    // Récupérer le modèle actuellement affiché
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    if (!model)
        return;

    int row = index.row();

    // Récupérer les données de la ligne sélectionnée
    QString idStr    = model->data(model->index(row, 0)).toString();
    QString nomStr   = model->data(model->index(row, 2)).toString();
    QString typeStr  = model->data(model->index(row, 3)).toString();
    QString dateStr  = model->data(model->index(row, 4)).toString();
    QString heureStr = model->data(model->index(row, 5)).toString();
    QString lieuStr  = model->data(model->index(row, 6)).toString();
    QString nbrStr   = model->data(model->index(row, 7)).toString();

    // Conversion de la date et de l'heure
    QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");
    if (!date.isValid())
        date = QDate::fromString(dateStr, "yyyy-MM-dd");

    QTime time = QTime::fromString(heureStr, "HH:mm");

    // Remplir les champs du formulaire
    ui->dateEdit->setDate(date);
    ui->timeEdit->setTime(time);
}
