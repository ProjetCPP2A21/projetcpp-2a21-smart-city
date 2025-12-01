#include "gevenement.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "connection.h"
#include <QString>
#include <QMessageBox>
#include <QTableView>
#include <QSqlDatabase>




void MainWindow::on_Ajouterbutton_clicked()
{
    bool ok;
    int id = ui->ID->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }
    int ID_Employe = ui->ID_Employe_Evenement->text().toInt();
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    checkQuery.bindValue(":id", ID_Employe);

    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Erreur SQL", checkQuery.lastError().text());
        return;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();

    if (count == 0) {
        QMessageBox::warning(this, "Erreur", "L'employé avec cet ID n'existe pas !");
        return; // ❌ Stop l'ajout
    }
    QString Nom = ui->Nom->text().trimmed();
    QString Type = ui->Type->text().trimmed();
    QString Lieu = ui->Lieu->text().trimmed();
    QString Date = ui->dateEdit->date().toString("dd/MM/yyyy");
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


void MainWindow::on_Supprimer_clicked()
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


void MainWindow::on_Modifier_clicked()
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




void MainWindow::on_Recherche_Line_textChanged(const QString &text)
{
    if (text.isEmpty()) {
        ui->tableView->setModel(E.afficher());
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();

    QString requete = QString(
                          "SELECT * FROM EVENEMENT WHERE TO_CHAR(ID_Evenement) LIKE '%1'"
                          ).arg(text + "%");

    model->setQuery(requete);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Erreur SQL", model->lastError().text());
        return;
    }

    ui->tableView->setModel(model);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
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

    QString nom = model->index(row, 2).data().toString();
    QString type = model->index(row, 3).data().toString();
    QString lieu = model->index(row, 6).data().toString();
    int Nbr_Participants = model->index(row, 7).data().toInt();

    ui->Nom->setText(nom);
    ui->Type->setText(type);
    ui->Lieu->setText(lieu);
    ui->NbrP->setText(QString::number(Nbr_Participants));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString requete;
    QSqlQueryModel *model = new QSqlQueryModel();

    if (index == 1) { // Tri par date (puis heure)
        requete = "SELECT * FROM EVENEMENT ORDER BY Date_Evenement ASC, Heure ASC";
    }
    else if (index == 2) { // Tri par nombre de participants (décroissant)
        requete = "SELECT * FROM EVENEMENT ORDER BY Nbr_Participants DESC";
    }
    else {
        ui->tableView->setModel(E.afficher());
        return;
    }

    model->setQuery(requete);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Erreur SQL", model->lastError().text());
        return;
    }

    ui->tableView->setModel(model);
}

