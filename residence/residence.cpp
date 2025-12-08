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
#include <QTextTable>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QFont>
#include <QTimer>
#include <QTime>
#include <QRandomGenerator>
#include <cstdlib>
#include "arduino.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->recherche, &QPushButton::clicked, this, &MainWindow::on_recherche_clicked);
    connect(ui->trie, &QPushButton::clicked, this, &MainWindow::on_trie_clicked);
    connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);
    timerPopup = new QTimer(this);
    connect(timerPopup, &QTimer::timeout, this, [this]() {
        QString message = getMessageForCurrentTime();
        if (!message.isEmpty()) {
            QMessageBox::information(this, "Recommandation NEOCITY", message);
        }
    });
    timerPopup->start(5 * 60 * 1000);
    A.connectArduino(); // inside constructor

    int temp = getTemperatureFromDB();
    if (temp > 37)
        A.writeToArduino("1"); // ON
    else
        A.writeToArduino("0");
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkTemperature);
    timer->start(10000);

    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
      QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
}
void MainWindow :: page_3()
{
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
void MainWindow :: page_4()
{
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficherTable()
{
    // récupère DATE_CONST comme number
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
        // colonnes 0..6 : conversion normale
        for (int col = 0; col < 7; ++col) {
            ui->affichage->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }

        // colonne 7 = DATE_CONST (NUMBER) -> formater en "YYYY-MM-DD"
        int dateNum = query.value(7).toInt();
        QString dateStr = QString::number(dateNum);

        if (dateStr.length() >= 8) {
            // ex: 20240201 -> "2024-02-01"
            dateStr = dateStr.mid(0,4) + "-" + dateStr.mid(4,2) + "-" + dateStr.mid(6,2);
        }
        // sinon on laisse la valeur brute

        ui->affichage->setItem(row, 7, new QTableWidgetItem(dateStr));
        row++;
    }
}



void MainWindow::ajouterTable()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString type = ui->lineEdit_type->text();
    int nbrUnite = ui->lineEdit_nbrUnit->text().toInt();
    int nbrHabitants = ui->lineEdit_nbrHabitants->text().toInt();
    QString etat = ui->lineEdit_etat->text();
    QString dateCreation = ui->lineEdit_date->text(); // YYYY-MM-DD

    // Convert date to number: "2024-11-20" → 20241120
    QString dateNumberString = dateCreation;
    dateNumberString.remove("-");
    int dateNumber = dateNumberString.toInt();

    QSqlQuery query;
    query.prepare("INSERT INTO RESIDENCE "
                  "(ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                  "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST) "
                  "VALUES (:id, :nom, :adresse, :type, :nbrUnite, :nbrHabitants, :etat, :dateConst)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":nbrUnite", nbrUnite);
    query.bindValue(":nbrHabitants", nbrHabitants);
    query.bindValue(":etat", etat);
    query.bindValue(":dateConst", dateNumber);  // <-- NUMBER

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Résidence ajoutée avec succès !");
        afficherTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout : " + query.lastError().text());
    }
}


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
        QMessageBox::critical(this, "Erreur", "L’ajout a échoué !");
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
        QMessageBox::critical(this, "Erreur", "La modification a échoué !");
    }
}


void MainWindow::on_pushButton_delete_clicked()
{
    int id = ui->lineEdit_id->text().toInt();

    if (crud.supprimer(id)) {
        QMessageBox::information(this, "Succès","Résidence supprimer !");
        afficherTable();
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression a échoué !");
    }
}





void MainWindow::on_recherche_clicked()
{
    int id = ui->search->text().toInt();

    QSqlQuery query = crud.rechercherParID(id);

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
        QMessageBox::critical(this, "Erreur SQL", "Impossible de générer les statistiques");
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
    if (!db.isOpen()) {
        if (!Connection::instance().createConnection()) {
            QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données.");
            return;
        }
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


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_P)
    {
       QSqlQuery query("SELECT NOM, NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST  FROM RESIDENCE");

        QString message = "Priorité des résidences :\n\n";

        while (query.next())
        {
            int etat = query.value("etat").toInt();
            int nbrHab = query.value("nbr_habitants").toInt();
            int nbrUnite = query.value("nbr_unite").toInt();
            int dateConst = query.value("date_const").toInt();
            QString nom = query.value("nom").toString();

            int yearConst = dateConst / 10000;

            double priority =
                (5.0 - etat) * 0.4 +
                ((double)nbrHab / nbrUnite) * 0.3 +
                (2025.0 - yearConst) * 0.3;

            message += nom + " → " + QString::number(priority, 'f', 2) + "\n";
        }


        QDialog dialog(this);
        dialog.setWindowTitle("Priorités");
        dialog.resize(600, 500);

        QVBoxLayout *layout = new QVBoxLayout(&dialog);

        QTextEdit *text = new QTextEdit();
        text->setText(message);
        text->setReadOnly(true);
        text->setFont(QFont("Rockwell", 11));

        layout->addWidget(text);

        dialog.exec();
    }
}


QString MainWindow::getMessageForCurrentTime()
{
    int hour = QTime::currentTime().hour();

    auto randomChoice = [](const QStringList &list) {
        return list.at(QRandomGenerator::global()->bounded(list.size()));
    };


    if (hour >= 7 && hour <= 11) {
        QStringList matin = {
            "Bon matin ! Pensez à vérifier les résidences dont l’état est inférieur à 3.",
            "Contactez le consièrge SVP.",
            "Conseil du jour : consultez les résidences les plus anciennes pour la maintenance.",
            "Veillez consulter le responsable service pour planifier la maintenance.."
        };
        return randomChoice(matin);
    }


    if (hour >= 12 && hour <= 16) {
        QStringList apm = {
            "Point mi-journée : avez-vous mis à jour les résidences modifiées ?",
            "Recommandation : vérifiez les résidences à densité élevée.",
            "Suggestion : consulter la priorité si il ya des modification dans la BD."
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


    if (hour >= 21 && hour <= 23) {
        QStringList nuit = {
            "Nuit calme… pensez à sauvegarder vos données.",
            "Conseil : vérifiez demain les résidences dont l’état est bas.",
            "Astuce : un nettoyage de la base peut améliorer les performances."
        };
        return randomChoice(nuit);
    }


    if (hour >= 0 && hour <= 6) {
        QStringList tard = {
            "Il est tard… n'oubliez pas de sauvegarder avant de fermer l’application.",
            "Recommandation : générez un rapport avant de finir et le verifiez avec les responsable ",
            "Pensez à revoir demain les résidences critiques."
        };
        return randomChoice(tard);
    }

    return "";
}
int MainWindow::getTemperatureFromDB()
{
    QSqlQuery query;
    if (!query.exec("SELECT TEMPERATURE FROM (SELECT TEMPERATURE FROM RESIDENCE ORDER BY ID_RESIDENCE DESC) WHERE ROWNUM = 1")) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return INT_MIN;
    }

    if (query.next()) {
        bool ok;
        int temp = query.value(0).toInt(&ok);
        if (!ok) return INT_MIN;
        return temp;
    }

    return INT_MIN; // pas de valeur trouvée
}

void MainWindow::checkTemperature()
{
    // Récupère la dernière température de la table RESIDENCE
    QSqlQuery query("SELECT TEMPERATURE FROM (SELECT TEMPERATURE FROM RESIDENCE ORDER BY ID_RESIDENCE DESC) WHERE ROWNUM = 1");

    if (query.next()) {
        int tempValue = query.value(0).toInt();

        if (tempValue > 37) {
            if (!ventilateurON) {             // si ventilateur OFF, on l'allume
                A.writeToArduino("0");        // 0 = ON (vérifie ton relais si c’est LOW trigger)
                ventilateurON = true;
                qDebug() << "Ventilateur ON | Temp =" << tempValue;
            }
        } else {
            if (ventilateurON) {              // si ventilateur ON, on l'éteint
                A.writeToArduino("1");        // 1 = OFF
                ventilateurON = false;
                qDebug() << "Ventilateur OFF | Temp =" << tempValue;
            }
        }
    } else {
        qDebug() << "Aucune température trouvée dans la table RESIDENCE";
    }
}








