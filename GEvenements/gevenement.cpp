#include "gevenement.h"
#include "ui_gevenement.h"
#include "evenement.h"
#include "connection.h"
#include "statistique.h"
#include <QString>
#include <QMessageBox>
#include <QTableView>
#include <QSqlDatabase>
#include <onnxruntime_cxx_api.h>
#include "Excel/QXlsx/QXlsx/header/xlsxdocument.h"
#include "Excel/QXlsx/QXlsx/header/xlsxformat.h"
#include "Excel/QXlsx/QXlsx/header/xlsxcellrange.h"
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
using namespace QXlsx;


GEvenement::GEvenement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEvenement)
{
    ui->setupUi(this);
    ui->ID->setValidator(new QIntValidator(1, 999999, this));
    ui->NbrP->setValidator(new QIntValidator(1, 100000, this));
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
    QString Nom = ui->Nom->text().trimmed();
    QString Type = ui->Type->text().trimmed();
    QString Lieu = ui->Lieu->text().trimmed();
    QDate Date = ui->dateEdit->date();
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
        QDate date = ui->dateEdit->text().isEmpty()    ? query.value(2).toDate()   : ui->dateEdit->date();
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




void GEvenement::on_Recherche_Line_textChanged(const QString &text)
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



void GEvenement::on_Prediction_clicked()
{
    int id = ui->Id_Evenement->text().toInt();
    ImpactResult impact = E.predireImpact(id);

    if (impact.co2 < 0) {
        QMessageBox::warning(this, "Erreur", "Impossible de prédire l'impact.");
        return;
    }

    ui->Dioxyde->setText(
        QString("🌫️ CO₂ : %1 kg\n🏭 Pollution : %2\n💥 Score d'impact : %3")
            .arg(impact.co2, 0, 'f', 2)
            .arg(impact.pollution, 0, 'f', 2)
            .arg(impact.impact, 0, 'f', 2)
        );
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
    // --- DATE : conversion correcte ---
   QVariant dateVar = model->data(model->index(row, 4));
     // après type_evenement
    QDate dt = dateVar.toDate();
    QString heureStr = model->data(model->index(row, 5)).toString();
    QString lieuStr  = model->data(model->index(row, 6)).toString();
    QString nbrStr   = model->data(model->index(row, 7)).toString();

    // Conversion de la date et de l'heure

    QTime time = QTime::fromString(heureStr, "HH:mm");

    // Remplir les champs du formulaire
    ui->dateEdit->setDate(dt);
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

void GEvenement::on_comboBox_currentIndexChanged(int index)
{
    QString requete;
    QSqlQueryModel *model = new QSqlQueryModel();

    if (index == 1) { // Tri par date (puis heure)
        requete = "SELECT ID_EVENEMENT, ID_EMPLOYE, NOM, TYPE_EVENEMENT, "
                  "TO_CHAR(DATE_EVENEMENT, 'DD/MM/YYYY') AS DATE_EVENEMENT, "
                  "HEURE, LIEU, NBR_PARTICIPANTS "
                  "FROM EVENEMENT ORDER BY Date_Evenement DESC, Heure DESC";
    }
    else if (index == 2) { // Tri par nombre de participants (décroissant)
        requete = "SELECT ID_EVENEMENT, ID_EMPLOYE, NOM, TYPE_EVENEMENT, "
                  "TO_CHAR(DATE_EVENEMENT, 'DD/MM/YYYY') AS DATE_EVENEMENT, "
                  "HEURE, LIEU, NBR_PARTICIPANTS "
                  "FROM EVENEMENT ORDER BY Nbr_Participants DESC";
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




void GEvenement::on_Excel_clicked()
{
    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter !");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(
        this, "Enregistrer sous", "Evenements.xlsx", "Fichiers Excel (*.xlsx)"
        );
    if (fileName.isEmpty())
        return;

    QXlsx::Document xlsx;

    // Écrire les en-têtes
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        xlsx.write(1, col + 1, header);
    }

    // Écrire les lignes
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant value = model->data(model->index(row, col));
            xlsx.write(row + 2, col + 1, value);
        }
    }

    if (xlsx.saveAs(fileName))
        QMessageBox::information(this, "Succès", "Exportation réussie !");
    else
        QMessageBox::warning(this, "Erreur", "Impossible d’enregistrer le fichier.");
}


void GEvenement::on_Statistiques_2_clicked()
{
    QSqlQuery query;
    // On récupère toutes les lignes, on fera les regroupements en C++
    if (!query.exec("SELECT Type_Evenement, Nbr_Participants FROM Evenement")) {
        QMessageBox::warning(this, "Erreur SQL",
                             "Impossible de récupérer les évènements :\n"
                                 + query.lastError().text());
        return;
    }

    int nbMusique = 0;
    int nbCinema  = 0;
    int nbAutre   = 0;

    while (query.next()) {
        QString type = query.value(0).toString().trimmed().toLower();
        int nbr      = query.value(1).toInt();

        // 💿 Musique
        if (type.contains("musique")) {
            nbMusique += nbr;
        }
        // 🎬 Cinéma (on gère sans / avec accent)
        else if (type.contains("cinema") || type.contains("cinéma")) {
            nbCinema += nbr;
        }
        // 🌈 Tous les autres types → "Autre"
        else {
            nbAutre += nbr;
        }
    }

    int total = nbMusique + nbCinema + nbAutre;

    if (total == 0) {
        QMessageBox::information(this, "Statistiques",
                                 "Aucun évènement trouvé dans la base.");
        return;
    }

    // ⚠️ Remplace 'widgetStat' par l'objectName réel de ton widget promu
    ui->StatisqueWidget->setData(nbMusique, nbCinema, nbAutre);
}

void GEvenement::on_Localiser_clicked()
{
    QString idstr = ui->ID_localisation->text();

    if(idstr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID !");
        return;
    }

    int id = idstr.toInt();
    QString lieu = E.RecupererLieu(id);

    if(lieu.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Événement introuvable !");
        return;
    }

    // Normaliser le texte
    lieu = lieu.toLower().trimmed();

    // Charger la carte
    QPixmap map("C:/Users/ASUS/Desktop/Smart City/GEvenements/Map/tunisie-carte.jpg");
    if (map.isNull()) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger la carte !");
        return;
    }

    // Dictionnaire nom → position pixel (à ajuster selon la carte)
    QMap<QString, QPoint> mapPositions = {
        {"tunis", QPoint(250, 80)},
        {"ariana", QPoint(245, 70)},
        {"sousse", QPoint(300, 200)},
        {"sfax", QPoint(320, 260)},
        {"bizerte", QPoint(230, 40)},
        {"gabes", QPoint(200, 300)},
        {"azur city", QPoint(260, 100)},
        {"geant", QPoint(250, 85)}
    };

    if (!mapPositions.contains(lieu)) {
        QMessageBox::warning(this, "Erreur", "Lieu non reconnu dans la carte !");
        return;
    }

    QPoint pos = mapPositions[lieu];

    // Tracer un point rouge
    QPainter painter(&map);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::red, 4));
    painter.setBrush(Qt::red);
    painter.drawEllipse(pos, 6, 6);
    painter.end();

    // Afficher la carte dans ton QLabel
    ui->Map->setPixmap(map);
    ui->Map->setScaledContents(true);
}

