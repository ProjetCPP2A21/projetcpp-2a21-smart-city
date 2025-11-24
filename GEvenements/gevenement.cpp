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
#include <QVariantList>
#include <QtQuick/QQuickItem>
#include <QGeoCodingManager>
#include <QGeoCodeReply>
#include <QGeoServiceProvider>
#include <QGeoCoordinate>
#include <QGeoLocation>
#include <QGeoAddress>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include <QStyledItemDelegate>
#include "datedelegate.h"
#include <QVBoxLayout>

using namespace QXlsx;


GEvenement::GEvenement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEvenement)
{
    ui->setupUi(this);
    // --- CORRECTION : PAS DE LAYOUT ---
    // On crée juste le label pour le dessin, sans toucher au reste du design.
    labelScore = new QLabel(ui->frame_Prediction);
    labelScore->setAlignment(Qt::AlignCenter);
    labelScore->setVisible(false); // Caché au début
    // ----------------------------------

    ui->ID->setValidator(new QIntValidator(1, 999999, this));
    ui->NbrP->setValidator(new QIntValidator(1, 100000, this));
    ui->tableView->setModel(E.afficher());
    ui->ID->setValidator(new QIntValidator(1, 999999, this));
    ui->NbrP->setValidator(new QIntValidator(1, 100000, this));
    ui->tableView->setModel(E.afficher());
    ui->tableView->setItemDelegateForColumn(4, new DateDelegate(ui->tableView));
    QObject *rootObject = ui->MapWidget->rootObject();
    QGeoServiceProvider provider("osm"); // Ou "here", "googlemaps", selon le plugin installé
    geoCoder = provider.geocodingManager();
    if (!geoCoder) {
        QMessageBox::critical(this, "Erreur", "Le géocodeur n'a pas été initialisé !");
        return;
    }
    ui->MapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->MapWidget->setFocusPolicy(Qt::StrongFocus);
    ui->MapWidget->setSource(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Smart City/GEvenements/Map.qml"));
    ui->MapWidget->setFocus();  // important pour que la souris et le clavier interagissent

    // Initialiser dictionnaire lieu → lat/lon
    lieuCoords = {
        {"tunis", QPointF(36.8065, 10.1815)},
        {"ariana", QPointF(36.8665, 10.1647)},
        {"sousse", QPointF(35.8256, 10.6084)},
        {"sfax", QPointF(34.7406, 10.7603)},
        {"bizerte", QPointF(37.2746, 9.8739)},
        {"gabes", QPointF(33.8815, 10.0994)},
        {"azur city", QPointF(36.8, 10.2)},
        {"geant", QPointF(36.81, 10.18)}
    };
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
    // 1. Récupération et calcul (inchangé)
    int id = ui->Id_Evenement->text().toInt();
    ImpactResult impact = E.predireImpact(id);

    if (impact.co2 < 0) {
        QMessageBox::warning(this, "Erreur", "Impossible de prédire l'impact.");
        return;
    }

    // 2. Mise à jour du texte existant (CO2 et Pollution)
    // On garde le label ui->Dioxyde à sa place définie dans Qt Designer
    ui->Dioxyde->setText(
        QString("<html><head/><body><p>"
                "🌫️ CO₂ : <b>%1 kg</b><br/>"
                "🏭 Pollution : <b>%2</b>"
                "</p></body></html>")
            .arg(impact.co2, 0, 'f', 2)
            .arg(impact.pollution, 0, 'f', 2)
        );

    // 3. --- POSITIONNEMENT ET DESSIN DE LA JAUGE ---
    labelScore->setVisible(true);

    // A. On calcule la position manuellement pour le mettre EN BAS du frame
    int frameW = ui->frame_Prediction->width();
    int frameH = ui->frame_Prediction->height();
    int gaugeHeight = 50;

    // setGeometry(x, y, largeur, hauteur)
    // On le place à 10px du bord gauche, et tout en bas (hauteur - 55px)
    labelScore->setGeometry(10, frameH - gaugeHeight - 5, frameW - 20, gaugeHeight);

    // B. Préparation du dessin
    QPixmap pixmap(labelScore->width(), labelScore->height());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    // C. Dessin de la barre dégradée
    int barHeight = 10;
    // On place la barre en bas du label
    int barY = gaugeHeight - barHeight - 5;
    QRect barRect(0, barY, labelScore->width(), barHeight); // On utilise toute la largeur du label

    QLinearGradient gradient(barRect.topLeft(), barRect.topRight());
    gradient.setColorAt(0.0, QColor("#3498db")); // Bleu
    gradient.setColorAt(1.0, QColor("#8e44ad")); // Violet

    painter.setBrush(gradient);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(barRect, 5, 5);

    // D. Dessin du Curseur (Triangle)
    double scoreSecure = (impact.impact < 0) ? 0 : (impact.impact > 1 ? 1 : impact.impact);
    int usefulWidth = labelScore->width();
    int cursorX = (int)(scoreSecure * usefulWidth);

    // On empêche le curseur de sortir des bords
    if (cursorX < 6) cursorX = 6;
    if (cursorX > usefulWidth - 6) cursorX = usefulWidth - 6;

    QPolygon triangle;
    triangle << QPoint(cursorX, barY - 2)
             << QPoint(cursorX - 6, barY - 10)
             << QPoint(cursorX + 6, barY - 10);
    painter.setBrush(Qt::white);
    painter.drawPolygon(triangle);

    // E. Dessin du Texte (Score)
    QString textScore = QString::number(impact.impact, 'f', 2);
    painter.setPen(Qt::white);
    QFont font("Arial", 10, QFont::Bold);
    painter.setFont(font);
    int textWidth = painter.fontMetrics().horizontalAdvance(textScore);

    // On dessine le texte au-dessus de la flèche
    painter.drawText(cursorX - (textWidth / 2), barY - 12, textScore);

    painter.end();
    labelScore->setPixmap(pixmap);
    labelScore->raise(); // S'assure que la jauge est au-dessus du fond
    // ---------------------------------------------


    // 4. Animation du cadre (Optionnel, inchangé)
    if (impact.impact > 0.80) {
        QTimer *timer = new QTimer(this);
        int *count = new int(0); // Compteur de clignotements

        connect(timer, &QTimer::timeout, this, [this, timer, count]() {
            if (*count >= 6) { // Arrêter après 6 changements (3 clignotements)
                ui->frame_Prediction->setStyleSheet("QFrame { background-color: #2c3e50; border-radius: 10px; }"); // Retour couleur normale (Adaptez le code couleur si besoin)
                timer->stop();
                timer->deleteLater();
                delete count;
                return;
            }

            // Alterner entre Rouge et la couleur de fond normale
            if (*count % 2 == 0) {
                ui->frame_Prediction->setStyleSheet("QFrame { background-color: #c0392b; border-radius: 10px; }"); // ROUGE
            } else {
                ui->frame_Prediction->setStyleSheet("QFrame { background-color: #2c3e50; border-radius: 10px; }"); // NORMAL (Gris foncé/Bleu nuit)
            }
            (*count)++;
        });

        timer->start(800); // Vitesse du clignotement (300ms)
    } else {
        // Si le score est bon, on s'assure que le fond est normal
        ui->frame_Prediction->setStyleSheet("QFrame { background-color: #2c3e50; border-radius: 10px; }");
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
    // On crée un nouveau modèle pour le tri
    QSqlQueryModel *model = new QSqlQueryModel();

    if (index == 1) { // Tri par date (puis heure)
        requete = "SELECT ID_EVENEMENT, ID_EMPLOYE, NOM, TYPE_EVENEMENT, "
                  "DATE_EVENEMENT, "
                  "HEURE, LIEU, NBR_PARTICIPANTS "
                  "FROM EVENEMENT ORDER BY Date_Evenement DESC, Heure DESC";
    }
    else if (index == 2) { // Tri par nombre de participants (décroissant)
        requete = "SELECT ID_EVENEMENT, ID_EMPLOYE, NOM, TYPE_EVENEMENT, "
                  "DATE_EVENEMENT, "
                  "HEURE, LIEU, NBR_PARTICIPANTS "
                  "FROM EVENEMENT ORDER BY Nbr_Participants DESC";
    }
    else {
        // Retour à l'affichage par défaut
        ui->tableView->setModel(E.afficher());
        // Le delegate reste actif car il est attaché à la "Vue" (TableView), pas au "Modèle"
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

    // 1. Écrire les en-têtes
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        xlsx.write(1, col + 1, header);
    }

    // 2. Écrire les données ligne par ligne
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant value = model->data(model->index(row, col));

            if (col == 4) {
                // On transforme la date en texte simple "dd/MM/yyyy"
                // Cela évite les "######" et l'heure "00:00" dans Excel
                if (value.type() == QVariant::Date || value.type() == QVariant::DateTime) {
                    xlsx.write(row + 2, col + 1, value.toDate().toString("dd/MM/yyyy"));
                } else {
                    xlsx.write(row + 2, col + 1, value);
                }
            }
            else {
                // Pour toutes les autres colonnes, on écrit normalement
                xlsx.write(row + 2, col + 1, value);
            }
        }
    }

    // 3. Sauvegarder le fichier
    if (xlsx.saveAs(fileName))
        QMessageBox::information(this, "Succès", "Exportation réussie !");
    else
        QMessageBox::warning(this, "Erreur", "Impossible d’enregistrer le fichier.");
}


void GEvenement::on_Statistiques_2_clicked()
{
    QSqlQuery query;

    // On sélectionne le Type et le Nbr_Participants
    if (!query.exec("SELECT Type_Evenement, Nbr_Participants FROM Evenement")) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques.\n" + query.lastError().text());
        return;
    }

    int totalMusique = 0;
    int totalCinema  = 0;
    int totalAutre   = 0;

    while (query.next()) {
        // On nettoie le texte (minuscule + sans espaces inutiles) pour éviter les erreurs
        QString type = query.value(0).toString().trimmed().toLower();

        // RECUPERATION DE LA VALEUR A AJOUTER :
        // Option A : Si vous voulez comparer le NOMBRE de participants (Popularité)
        int valeur = query.value(1).toInt();

        // Option B : Si vous voulez comparer le NOMBRE D'EVENEMENTS (Fréquence)
        // int valeur = 1; // Décommentez cette ligne et commentez celle du dessus pour l'Option B

        if (type.contains("musique")) {
            totalMusique += valeur;
        }
        else if (type.contains("cinema") || type.contains("cinéma")) {
            totalCinema += valeur;
        }
        else {
            totalAutre += valeur;
        }
    }

    // On vérifie qu'il y a des données pour éviter un graphique vide
    if ((totalMusique + totalCinema + totalAutre) == 0) {
        QMessageBox::information(this, "Info", "Aucune donnée à afficher pour le moment.");
        return;
    }

    // On envoie les chiffres calculés à votre Widget personnalisé
    // C'est lui qui va dessiner le beau graphique "Donut" qu'on a fait avant
    ui->StatisqueWidget->setData(totalMusique, totalCinema, totalAutre);
}

void GEvenement::on_Localiser_clicked()
{
    int id = ui->ID_localisation->text().toInt();
    QString lieu = E.RecupererLieu(id);

    if (lieu.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Événement non trouvé !");
        return;
    }

    // Préparer la requête Nominatim
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QString url = "https://nominatim.openstreetmap.org/search?format=json&q=" + lieu+",Tunisie";
    QNetworkRequest request(url);

    // Obligatoire : Nominatim exige un User-Agent
    request.setHeader(QNetworkRequest::UserAgentHeader, "QtApp");

    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {

        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonArray arr = doc.array();

        if (arr.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Lieu introuvable !");
            return;
        }

        // Récupération des coordonnées GPS
        QJsonObject obj = arr.first().toObject();
        double lat = obj["lat"].toString().toDouble();
        double lon = obj["lon"].toString().toDouble();

        // Appel aux fonctions QML
        QObject *rootObject = ui->MapWidget->rootObject();
        if (!rootObject) {
            QMessageBox::critical(this, "Erreur", "Map QML non chargée !");
            return;
        }

        QMetaObject::invokeMethod(rootObject, "centerOn",
                                  Q_ARG(QVariant, lat),
                                  Q_ARG(QVariant, lon));

        QMetaObject::invokeMethod(rootObject, "addMarker",
                                  Q_ARG(QVariant, lat),
                                  Q_ARG(QVariant, lon));
    });

    manager->get(request);
}

