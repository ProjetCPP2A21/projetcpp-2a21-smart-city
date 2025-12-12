#include "residence.h"
#include "ui_residence.h"
#include "connection.h"
#include "crud.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QFont>
#include <QTimer>
#include <QTime>
#include <QRandomGenerator>
#include <cstdlib>
#include <QDebug>
#include <climits>
#include <QKeyEvent>
#include <QDate>
#include <QSqlError>

// --- Déclarations des variables globales / partagées ---
// Ces variables doivent être définies une seule fois dans le .cpp si elles sont déclarées
// extern dans d'autres fichiers, ou simplement ici si elles sont privées à ce fichier.
QSerialPort *serial = nullptr;
QString bufferSerial;
bool ventilateurON = false;
int dernierIDResidence = 1; // ID de la résidence où le capteur est localisé

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherTable(); // Afficher les données au démarrage

    // --- Connections des boutons principaux ---
    connect(ui->recherche, &QPushButton::clicked, this, &MainWindow::on_recherche_clicked);
    connect(ui->trie, &QPushButton::clicked, this, &MainWindow::on_trie_clicked);
    connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);
    connect(ui->statistique, &QPushButton::clicked, this, &MainWindow::on_statistique_clicked);

    // --- Connection du bouton de Température (Arduino) ---
    connect(ui->btnTemp, &QPushButton::clicked, this, &MainWindow::on_btnTemp_clicked);

    // --- 1. Timer de Recommandation (Toutes les 5 minutes) ---
    timerPopup = new QTimer(this);
    connect(timerPopup, &QTimer::timeout, this, [this]() {
        QString message = getMessageForCurrentTime();
        if (!message.isEmpty()) {
            QMessageBox::information(this, "Recommandation NEOCITY", message);
        }
    });
    timerPopup->start(5 * 60 * 1000);

    // --- 2. Timer d'arrêt automatique du ventilateur ---
    fanTimer = new QTimer(this);
    fanTimer->setSingleShot(true);
    connect(fanTimer, &QTimer::timeout, this, [=]() {
        // Envoie '0' (OFF) via le port série
        if (serial && serial->isOpen()) serial->write("0\n");
        ventilateurON = false;
        qDebug() << "Ventilateur OFF (Timer expired)";
    });

    // --- 3. Configuration du Port Série (Arduino) ---
    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::onSerialDataReceived);

    // **** ATTENTION : CONFIGURATION CRUCIALE ****
    // ⚙️ VEUILLEZ REMPLACER "COM3" PAR LE NOM DE PORT DE VOTRE ARDUINO
    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud9600); // Assurez-vous que cela correspond à l'Arduino

    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Port série ouvert avec succès !";
    } else {
        QMessageBox::critical(this, "Erreur Série", "Impossible d'ouvrir le port série : " + serial->errorString() +
                                                        "\nVérifiez le câble et le nom du port (ex: COM3).");
    }

    // --- 4. Navigation Stacked Widget ---
    // Connexion via QObject::connect pour les signaux/slots basés sur les pointeurs ou noms
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
}


MainWindow::~MainWindow()
{
    delete ui;
    // Le QSerialPort est détruit par QMainWindow
}

// -------------------------------------------------------------------
//                          I. Navigation
// -------------------------------------------------------------------

void MainWindow :: page_3()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

void MainWindow :: page_4()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}

// -------------------------------------------------------------------
//                          II. Affichage et Formatage
// -------------------------------------------------------------------

void MainWindow::afficherTable()
{
    QSqlQuery query("SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                    "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST FROM RESIDENCE");

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(8);

    QStringList headers;
    headers << "ID" << "Nom" << "Adresse" << "Type" << "Nbr Unités"
            << "Nbr Habitants" << "État" << "Date Création";
    ui->affichage->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->affichage->insertRow(row);

        // Colonnes 0..6 (valeurs standard)
        for (int col = 0; col < 7; ++col) {
            ui->affichage->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }

        // Colonne 7 : DATE_CONST (NUMBER) -> format YYYY-MM-DD
        int dateNum = query.value(7).toInt();
        QString dateStr = QString::number(dateNum);

        if (dateStr.length() >= 8) {
            // ex: 20240201 -> "2024-02-01"
            dateStr = dateStr.mid(0,4) + "-" + dateStr.mid(4,2) + "-" + dateStr.mid(6,2);
        }

        ui->affichage->setItem(row, 7, new QTableWidgetItem(dateStr));
        row++;
    }
}

// -------------------------------------------------------------------
//                          III. CRUD Operations
// -------------------------------------------------------------------

void MainWindow::on_pushButton_add_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString type = ui->lineEdit_type->text();
    int nbrUnite = ui->lineEdit_nbrUnit->text().toInt();
    int nbrHabitants = ui->lineEdit_nbrHabitants->text().toInt();
    QString etat = ui->lineEdit_etat->text();
    QString dateCreation = ui->lineEdit_date->text();

    if (crud.ajouter(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès", "Résidence ajoutée avec succès !");
        afficherTable();
    } else {
        QMessageBox::critical(this, "Erreur", "L’ajout a échoué ! Vérifiez les données (ID unique) ou la connexion.");
    }
}

void MainWindow::on_pushButton_update_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString type = ui->lineEdit_type->text();
    int nbrUnite = ui->lineEdit_nbrUnit->text().toInt();
    int nbrHabitants = ui->lineEdit_nbrHabitants->text().toInt();
    QString etat = ui->lineEdit_etat->text();
    QString dateCreation = ui->lineEdit_date->text();

    if (crud.modifier(id, nom, adresse, type, nbrUnite, nbrHabitants, etat, dateCreation)) {
        QMessageBox::information(this, "Succès","Résidence modifiée !");
        afficherTable();
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué ! (Résidence introuvable?)");
    }
}


void MainWindow::on_pushButton_delete_clicked()
{
    int id = ui->lineEdit_id->text().toInt();

    if (crud.supprimer(id)) {
        QMessageBox::information(this, "Succès","Résidence supprimée !");
        afficherTable();
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression a échoué ! (Résidence introuvable?)");
    }
}

// -------------------------------------------------------------------
//                          IV. Recherche, Tri, Stats, Export
// -------------------------------------------------------------------

void MainWindow::on_recherche_clicked()
{
    int id = ui->search->text().toInt();

    QSqlQuery query = crud.rechercherParID(id);

    // Setup table headers
    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(8);

    QStringList headers;
    headers << "ID" << "Nom" << "Adresse" << "Type" << "Nbr Unités"
            << "Nbr Habitants" << "État" << "Date Création";
    ui->affichage->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (query.next()) {
        ui->affichage->insertRow(row);
        for (int col = 0; col < 8; ++col) {
            ui->affichage->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }

    if (row == 0) {
        QMessageBox::information(this, "Résultat", "Aucune résidence trouvée avec cet ID.");
    }
}


void MainWindow::on_trie_clicked()
{
    QSqlQueryModel *model = crud.trierParNbrHabitants();
    if (!model) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données triées.");
        return;
    }

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(model->columnCount());

    QStringList headers = {"ID", "Nom", "Adresse", "Type", "Nbr Unités",
                           "Nbr Habitants", "État", "Date Création"};
    ui->affichage->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < model->rowCount(); ++row) {
        ui->affichage->insertRow(row);
        for (int col = 0; col < model->columnCount(); ++col) {
            ui->affichage->setItem(row, col,
                                   new QTableWidgetItem(model->data(model->index(row, col)).toString()));
        }
    }

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Résultat", "Aucune résidence trouvée.");
    }

    delete model;
}


void MainWindow::on_statistique_clicked()
{
    QSqlQuery query = crud.statistiquesHabitants();

    if(!query.isActive()) {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de générer les statistiques.");
        return;
    }


    QPieSeries *series = new QPieSeries();
    while(query.next()) {
        QString range = query.value(0).toString();
        int total = query.value(1).toInt();
        series->append(range, total);
    }

    for(QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
        // Format étiquette : Plage (Compte)
        slice->setLabel(QString("%1 (%2)").arg(slice->label()).arg(slice->value()));
    }


    QChart *chartObj = new QChart();
    chartObj->addSeries(series);
    chartObj->setTitle("Répartition des résidences selon le nombre d'habitants");
    chartObj->legend()->setAlignment(Qt::AlignRight);


    QChartView *chartView = new QChartView(chartObj);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->chart);
    chartView->setGeometry(ui->chart->rect());
    chartView->show();
    //
}


void MainWindow::on_exporter_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    if (!fileName.endsWith(".pdf"))
        fileName += ".pdf";

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html;

    html += "<h2>Liste des Résidences</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='3'>";
    html += "<tr>"
            "<th>ID</th>"
            "<th>Nom</th>"
            "<th>Adresse</th>"
            "<th>Type</th>"
            "<th>Nbr Unités</th>"
            "<th>Nbr Habitants</th>"
            "<th>État</th>"
            "<th>Date Création</th>"
            "</tr>";

    QSqlDatabase db = Connection::instance().getDatabase();
    if (!db.isOpen() && !Connection::instance().createConnection()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données pour l'export.");
        return;
    }

    QSqlQuery query(db);
    QString sql = R"(
        SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE,
               NBR_UNITE, NBR_HABITANTS, ETAT,
               DATE_CONST
        FROM RESIDENCE
        ORDER BY NBR_HABITANTS ASC
    )";

    if (!query.exec(sql)) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les résidences : " + query.lastError().text());
        return;
    }

    while (query.next()) {
        html += "<tr>";
        // NOTE: La date est exportée comme un NUMBER (YYYYMMDD) dans l'HTML.
        for (int col = 0; col < 8; ++col) {
            html += "<td>" + query.value(col).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "La liste des résidences a été exportée avec succès !");
}

// -------------------------------------------------------------------
//                          V. Priorité (Touche 'P')
// -------------------------------------------------------------------

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_P)
    {
        QSqlQuery query("SELECT NOM, NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST FROM RESIDENCE");

        QString message = "Priorité des résidences (P): \n\n";

        while (query.next())
        {
            int etat = query.value("ETAT").toInt();
            int nbrHab = query.value("NBR_HABITANTS").toInt();
            int nbrUnite = query.value("NBR_UNITE").toInt();
            int dateConst = query.value("DATE_CONST").toInt();
            QString nom = query.value("NOM").toString();

            if (nbrUnite == 0) nbrUnite = 1;

            int yearConst = dateConst / 10000;
            if (yearConst == 0) yearConst = QDate::currentDate().year();

            // Formule de Priorité : État (40%) + Densité (30%) + Âge (30%)
            // Plus la valeur est élevée, plus la priorité est haute.
            double priority =
                (5.0 - etat) * 0.4 +
                ((double)nbrHab / nbrUnite) * 0.3 +
                (2025.0 - yearConst) * 0.3;

            message += nom + " → " + QString::number(priority, 'f', 2) + "\n";
        }

        QDialog dialog(this);
        dialog.setWindowTitle("Priorités des Résidences (Critères de Maintenance)");
        dialog.resize(600, 500);

        QVBoxLayout *layout = new QVBoxLayout(&dialog);

        QTextEdit *text = new QTextEdit();
        text->setText(message);
        text->setReadOnly(true);
        text->setFont(QFont("Rockwell", 11));

        layout->addWidget(text);
        dialog.exec();
    } else {
        QMainWindow::keyPressEvent(event);
    }
}

// -------------------------------------------------------------------
//                          VI. Recommandations
// -------------------------------------------------------------------

QString MainWindow::getMessageForCurrentTime()
{
    int hour = QTime::currentTime().hour();

    auto randomChoice = [](const QStringList &list) {
        return list.at(QRandomGenerator::global()->bounded(list.size()));
    };

    if (hour >= 7 && hour <= 11) {
        QStringList matin = {
            "Bon matin ! Pensez à vérifier les résidences dont l’état est inférieur à 3.",
            "Contactez le concierge SVP.",
            "Conseil du jour : consultez les résidences les plus anciennes pour la maintenance."
        };
        return randomChoice(matin);
    }

    if (hour >= 12 && hour <= 16) {
        QStringList apm = {
            "Point mi-journée : avez-vous mis à jour les résidences modifiées ?",
            "Recommandation : vérifiez les résidences à densité élevée.",
            "Suggestion : consulter la priorité si il y a des modifications dans la BD."
        };
        return randomChoice(apm);
    }

    if (hour >= 17 && hour <= 20) {
        QStringList soir = {
            "Fin de journée : souhaitez-vous générer un fichier pdf des résidences ?",
            "Astuce : vérifiez les résidences critiques pour demain.",
            "Pensez à enregistrer vos dernières modifications."
        };
        return randomChoice(soir);
    }

    // ... (Logique pour 21h-23h et 0h-6h) ...
    // ...

    return "";
}

// -------------------------------------------------------------------
//                          VII. Arduino et Température
// -------------------------------------------------------------------

int MainWindow::getTemperatureFromDB()
{
    // Fonction utilisée pour lire la température stockée dans la DB
    QSqlQuery query;

    // Récupère la température de la dernière résidence enregistrée
    if (!query.exec("SELECT TEMPERATURE FROM ("
                    "SELECT TEMPERATURE FROM RESIDENCE "
                    "ORDER BY ID_RESIDENCE DESC"
                    ") WHERE ROWNUM = 1"))
    {
        qDebug() << "SQL Error reading Temperature:" << query.lastError().text();
        return INT_MIN;
    }

    if (query.next()) {
        return query.value(0).toInt();
    }

    return INT_MIN;
}

void MainWindow::onSerialDataReceived()
{
    QByteArray data = serial->readAll();
    bufferSerial += QString::fromUtf8(data); // Accumuler les fragments

    int index;
    // Traiter toutes les lignes complètes reçues (terminées par '\n')
    while ((index = bufferSerial.indexOf('\n')) != -1) {
        QString line = bufferSerial.left(index).trimmed();
        bufferSerial.remove(0, index + 1);

        bool ok;
        float temp = line.toFloat(&ok);

        // Validation : Est-ce un nombre et est-il dans une plage de température plausible ?
        if(ok && temp >= -10 && temp <= 50) {
            qDebug() << "Température reçue de l'Arduino:" << temp;

            // 1. Mise à jour de l'UI
            ui->btnTemp->setText(QString::number(temp,'f',1) + " °C");

            // 2. Mise à jour de la base de données
            QSqlQuery query;
            query.prepare("UPDATE RESIDENCE SET TEMPERATURE = :t WHERE ID_RESIDENCE = :id");
            query.bindValue(":t", temp);
            query.bindValue(":id", dernierIDResidence);
            if (!query.exec()) {
                qDebug() << "DB Update Temp Error:" << query.lastError().text();
            }

            // 3. CONTRÔLE DU VENTILATEUR
            // Extrait de residence.cpp (dans onSerialDataReceived)
            if(temp > 35) {
                if(!ventilateurON) {
                    if (serial->isOpen()) serial->write("1\n"); // Envoie '1' pour ALLUMER
                    ventilateurON = true;
                    fanTimer->start(10000);
                }
            } else {
                if(ventilateurON) {
                    if (serial->isOpen()) serial->write("0\n"); // Envoie '0' pour ÉTEINDRE
                    ventilateurON = false;
                    fanTimer->stop();
                }

            }
        } else {
            qDebug() << "Donnée série non reconnue:" << line;
        }
    }
}

void MainWindow::lireTemperatureArduino()
{
    if(!serial || !serial->isOpen()) {
        QMessageBox::warning(this, "Connexion", "Le port série n'est pas ouvert. Vérifiez la connexion.");
        return;
    }

    // Envoie la commande 'READ\n' pour que l'Arduino envoie la température
    serial->write("READ\n");
    serial->flush();
    qDebug() << "Commande 'READ' envoyée à l'Arduino.";
}

void MainWindow::on_btnTemp_clicked()
{
    // Déclenche la demande de lecture à l'Arduino
    lireTemperatureArduino();
}
