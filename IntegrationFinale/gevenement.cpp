#include "gevenement.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QGeoPositionInfoSource>
#include <QDebug>

using namespace QXlsx;


void MainWindow::on_Ajouterbutton_clicked()
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
        ui->tableView_Evenement->setModel(E.afficher());
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

void MainWindow::on_Supprimer_2_clicked()
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
        ui->tableView_Evenement->setModel(E.afficher());
        ui->ID->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectue !!\n""Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_Modifier_2_clicked()
{
    // récupères l'ID sélectionné dans la tableView
    int id = ui->tableView_Evenement->model()->index(ui->tableView_Evenement->currentIndex().row(), 0).data().toInt();
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
        ui->tableView_Evenement->setModel(E.afficher()); // rafraîchir l'affichage
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
        ui->tableView_Evenement->setModel(E.afficher());
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

    ui->tableView_Evenement->setModel(model);
}



void MainWindow::on_Prediction_clicked()
{
    // 1. Récupération et calcul
    int id = ui->Id_Evenement->text().toInt();
    ImpactResult impact = E.predireImpact(id);

    if (impact.co2 < 0) {
        QMessageBox::warning(this, "Erreur", "Impossible de prédire l'impact.");
        return;
    }

    // 2. Mise à jour du texte
    ui->Dioxyde->setText(
        QString("<html><head/><body><p>"
                "🌫️ CO₂ : <b>%1 kg</b><br/>"
                "🏭 Pollution : <b>%2</b> <span style='font-size:10pt;'>ug/m³</span>"
                "</p></body></html>")
            .arg(impact.co2, 0, 'f', 2)
            .arg(impact.pollution, 0, 'f', 2)
        );

    // 3. --- DESSIN DE LA JAUGE ---
    labelScore->setVisible(true);

    int frameW = ui->frame_Prediction->width();
    int frameH = ui->frame_Prediction->height();
    int gaugeHeight = 60; // Hauteur suffisante pour tout contenir

    // Positionnement du label dans le cadre
    labelScore->setGeometry(10, frameH - gaugeHeight - 5, frameW - 20, gaugeHeight);

    QPixmap pixmap(labelScore->width(), labelScore->height());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    // Marge latérale
    int margin = 30;
    int usefulWidth = labelScore->width() - (2 * margin);

    // Position verticale de la barre (vers le bas)
    int barHeight = 10;
    int barY = gaugeHeight - barHeight - 10;

    QRect barRect(margin, barY, usefulWidth, barHeight);

    QLinearGradient gradient(barRect.topLeft(), barRect.topRight());
    gradient.setColorAt(0.0, QColor("#3498db"));
    gradient.setColorAt(0.35, QColor("#800080"));
    gradient.setColorAt(0.7, QColor("#FF4500"));
    gradient.setColorAt(1.0, QColor("#8B0000"));

    painter.setBrush(gradient);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(barRect, 5, 5);

    // Position X du curseur (pointe du triangle)
    double scoreSecure = (impact.impact < 0) ? 0 : (impact.impact > 1 ? 1 : impact.impact);
    int cursorX = margin + (int)(scoreSecure * usefulWidth);

    // Dessin du Triangle
    QPolygon triangle;
    triangle << QPoint(cursorX, barY - 2)
             << QPoint(cursorX - 6, barY - 10)
             << QPoint(cursorX + 6, barY - 10);
    painter.setBrush(Qt::white);
    painter.drawPolygon(triangle);

    // Dessin du Texte (Score) avec "CLAMPING"
    QString textScore = QString::number(impact.impact, 'f', 2);
    painter.setPen(Qt::white);
    QFont font("Arial", 10, QFont::Bold);
    painter.setFont(font);

    // Calcul précis de la largeur du texte
    int textWidth = painter.fontMetrics().horizontalAdvance(textScore);

    // Position idéale (centrée sur le curseur)
    int textX = cursorX - (textWidth / 2);

    // --- PROTECTION BORDS (CLAMPING) ---
    // Si le texte dépasse à gauche (< 0), on le bloque à 0
    if (textX < 0) {
        textX = 0;
    }
    // Si le texte dépasse à droite (> largeur totale), on le bloque contre le bord droit
    else if (textX + textWidth > labelScore->width()) {
        textX = labelScore->width() - textWidth;
    }

    // Dessin à la position corrigée textX
    painter.drawText(textX, barY - 12, textScore);

    painter.end();
    labelScore->setPixmap(pixmap);
    labelScore->raise();

    // 4. Animation (Clignotement si score élevé)
    if (impact.impact > 0.80) {
        QTimer *timer = new QTimer(this);
        int *count = new int(0);
        connect(timer, &QTimer::timeout, this, [this, timer, count]() {
            if (*count >= 18) {
                ui->frame_Prediction->setStyleSheet("QFrame { background-color: #2c3e50; border-radius: 10px; }");
                timer->stop();
                timer->deleteLater();
                delete count;
                return;
            }
            if (*count % 2 == 0) {
                ui->frame_Prediction->setStyleSheet("QFrame { background-color: #c0392b; border-radius: 10px; }");
            } else {
                ui->frame_Prediction->setStyleSheet("QFrame { background-color: #2c3e50; border-radius: 10px; }");
            }
            (*count)++;
        });
        timer->start(500);
    } else {
        ui->frame_Prediction->setStyleSheet("QFrame { background-color: #2c3e50; border-radius: 10px; }");
    }
}


void MainWindow::on_tableView_Evenement_clicked(const QModelIndex &index)
{
    // Récupérer le modèle actuellement affiché
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView_Evenement->model());
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

void MainWindow::on_comboBox_currentIndexChanged(int index)
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
        ui->tableView_Evenement->setModel(E.afficher());
        // Le delegate reste actif car il est attaché à la "Vue" (TableView), pas au "Modèle"
        return;
    }

    model->setQuery(requete);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Erreur SQL", model->lastError().text());
        return;
    }

    ui->tableView_Evenement->setModel(model);
}




void MainWindow::on_Excel_clicked()
{
    QAbstractItemModel *model = ui->tableView_Evenement->model();
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


void MainWindow::on_Statistiques_Evenement_clicked()
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

    // On envoie les chiffres calculés à Widget personnalisé
    // C'est lui qui va dessiner le beau graphique "Donut" qu'on a fait avant
    ui->StatisqueWidget->setData(totalMusique, totalCinema, totalAutre);
}

void MainWindow::on_Localiser_clicked()
{
    int id = ui->ID_localisation->text().toInt();
    QString lieu = E.RecupererLieu(id);

    if (lieu.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Événement non trouvé !");
        return;
    }

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString url = "https://nominatim.openstreetmap.org/search?format=json&q=" + lieu + ",Tunisie";
    //on prépare la requete
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, "QtApp");

    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonArray arr = doc.array();

        if (arr.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Lieu introuvable !");
            return;
        }

        QJsonObject obj = arr.first().toObject();
        double lat = obj["lat"].toString().toDouble();
        double lon = obj["lon"].toString().toDouble();

        QObject *rootObject = ui->MapWidget->rootObject();
        if (!rootObject) return;

        // --- AJOUTS ICI ---

        // 1. On efface tout ancien trajet (Ligne bleue + marqueur vert)
        QMetaObject::invokeMethod(rootObject, "clearRoute");

        // 2. On centre et on met le marqueur rouge (Destination)
        QMetaObject::invokeMethod(rootObject, "centerOn",
                                  Q_ARG(QVariant, lat),
                                  Q_ARG(QVariant, lon));

        QMetaObject::invokeMethod(rootObject, "addMarker",
                                  Q_ARG(QVariant, lat),
                                  Q_ARG(QVariant, lon));
    });

    manager->get(request);
}


void MainWindow::on_btnItineraire_clicked()
{
    // 1. Récupérer l'ID et le lieu (comme pour Localiser)
    int id = ui->ID_localisation->text().toInt();
    QString lieu = E.RecupererLieu(id);

    if (lieu.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide pour récupérer le lieu.");
        return;
    }

    // 2. Requête Nominatim pour trouver les coordonnées de la destination
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QString url = "https://nominatim.openstreetmap.org/search?format=json&q=" + lieu + ",Tunisie";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, "QtApp_Projet_NeoCity");

    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        if (reply->error() != QNetworkReply::NoError) {
            QMessageBox::warning(this, "Erreur Réseau", reply->errorString());
            reply->deleteLater();
            return;
        }

        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonArray arr = doc.array();

        if (arr.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Lieu introuvable via GPS !");
            reply->deleteLater();
            return;
        }

        // 3. Extraction des coordonnées de destination
        QJsonObject obj = arr.first().toObject();
        double latDest = obj["lat"].toString().toDouble();
        double lonDest = obj["lon"].toString().toDouble();

        // 4. Appel de la fonction QML pour tracer la route
        QObject *rootObject = ui->MapWidget->rootObject();
        if (rootObject) {
            // On centre d'abord sur la destination pour être sûr
            // (Optionnel, vous pouvez commenter si vous voulez voir tout le trajet avec le zoom auto)
            /*
            QMetaObject::invokeMethod(rootObject, "centerOn",
                                      Q_ARG(QVariant, latDest),
                                      Q_ARG(QVariant, lonDest));
            */

            // --- CORRECTION ICI : On passe 4 ARGUMENTS (Départ + Arrivée) ---
            // On utilise vos variables membres myLatitude/myLongitude (remplies par le GPS Windows)

            // Sécurité : Si le GPS n'a rien trouvé, on met une valeur par défaut (ex: Tunis)
            double departLat = (this->myLatitude != 0) ? this->myLatitude : 36.8065;
            double departLon = (this->myLongitude != 0) ? this->myLongitude : 10.1815;

            QMetaObject::invokeMethod(rootObject, "calculateRoute",
                                      Q_ARG(QVariant, departLat),   // 1. Latitude Départ (Moi)
                                      Q_ARG(QVariant, departLon),   // 2. Longitude Départ (Moi)
                                      Q_ARG(QVariant, latDest),     // 3. Latitude Arrivée (Event)
                                      Q_ARG(QVariant, lonDest));    // 4. Longitude Arrivée (Event)

        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de communiquer avec la carte.");
        }
        reply->deleteLater();
    });

    manager->get(request);
}

void MainWindow::onGpsProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::CrashExit || exitCode != 0) {
        qDebug() << "Erreur : Le processus GPS a échoué.";
        return;
    }

    QByteArray output = gpsProcess->readAllStandardOutput().trimmed();
    QString result = QString::fromUtf8(output);

    if (!result.isEmpty() && result != "Unknown") {
        QStringList parts = result.split(',');
        if (parts.size() == 2) {
            bool latOk, lonOk;
            double lat = parts[0].replace(',', '.').toDouble(&latOk);
            double lon = parts[1].replace(',', '.').toDouble(&lonOk);

            if (latOk && lonOk) {
                this->myLatitude = lat;
                this->myLongitude = lon;
                qDebug() << "✅ GPS PRÉCIS TROUVÉ (VERT) :" << lat << lon;

                // --- CORRECTION ICI ---
                QObject *rootObject = ui->MapWidget->rootObject();
                if (rootObject) {
                    // On appelle EXPLICITEMENT "addGreenMarker" au lieu de "addMarker"
                    QMetaObject::invokeMethod(rootObject, "addGreenMarker",
                                              Q_ARG(QVariant, lat),
                                              Q_ARG(QVariant, lon));
                }
                // ----------------------
            }
        }
    } else {
        qDebug() << "⚠️ GPS Windows n'a pas pu fixer la position.";
    }
}
