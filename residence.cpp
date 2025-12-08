#include "residence.h"
#include "ui_residence.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QPrinter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTime>
#include <QRandomGenerator>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDebug>
#include <QFileDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dernierIDResidence(-1)
    , derniereTemperature(0)
{
    ui->setupUi(this);

    // --- Initialisation série Arduino ---
    serial = new QSerialPort(this);
    serial->setPortName("COM4");  // Ajuster selon ton port
    serial->setBaudRate(QSerialPort::Baud9600);
    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Connexion série OK";
    } else {
        qDebug() << "Erreur connexion série";
    }

    connect(serial, &QSerialPort::readyRead, this, &MainWindow::onSerialDataReceived);

    // --- Connexion boutons ---
    connect(ui->btnTemp, &QPushButton::clicked, this, &MainWindow::on_btnTemp_clicked);
    connect(ui->recherche, &QPushButton::clicked, this, &MainWindow::on_recherche_clicked);
    connect(ui->trie, &QPushButton::clicked, this, &MainWindow::on_trie_clicked);
    connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);

    // --- Timer popup ---
    timerPopup = new QTimer(this);
    connect(timerPopup, &QTimer::timeout, this, [this](){
        QString msg = getMessageForCurrentTime();
        if (!msg.isEmpty())
            QMessageBox::information(this, "Recommandation NEOCITY", msg);
    });
    timerPopup->start(5*60*1000); // toutes les 5 minutes

    // --- Navigation pages ---
    QObject::connect(ui->RH, SIGNAL(clicked()), this, SLOT(page_4()));
    QObject::connect(ui->residence_2, SIGNAL(clicked()), this, SLOT(page_3()));

    // --- Dernier ID ---
    dernierIDResidence = getDerniereResidenceID();

    // --- Affichage initial table ---
    afficherTable();

    // --- Timer lecture automatique température toutes les 30 secondes ---
    QTimer *timerTemp = new QTimer(this);
    connect(timerTemp, &QTimer::timeout, this, &MainWindow::lireTemperatureArduino);
    timerTemp->start(30000); // 30 000 ms = 30 sec
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- Navigation pages ---
void MainWindow::page_3() { ui->stackedWidget->setCurrentWidget(ui->page_3); }
void MainWindow::page_4() { ui->stackedWidget->setCurrentWidget(ui->page_4); }

// --- CRUD et affichage ---
int MainWindow::getDerniereResidenceID()
{
    QSqlQuery query;
    query.prepare("SELECT MAX(ID_RESIDENCE) FROM RESIDENCE");
    if (query.exec() && query.next())
        return query.value(0).toInt();
    return -1;
}

void MainWindow::afficherTable()
{
    QSqlQuery query("SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                    "NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CONST FROM RESIDENCE");

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(8);

    QStringList headers = {"ID","Nom","Adresse","Type","Nbr Unités","Nbr Habitants","État","Date Création"};
    ui->affichage->setHorizontalHeaderLabels(headers);

    int row = 0;
    while(query.next()) {
        ui->affichage->insertRow(row);
        for(int col=0; col<7; ++col)
            ui->affichage->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));

        // Formater date
        QString dateStr = query.value(7).toString();
        if (dateStr.length() >= 8)
            dateStr = dateStr.mid(0,4) + "-" + dateStr.mid(4,2) + "-" + dateStr.mid(6,2);
        ui->affichage->setItem(row, 7, new QTableWidgetItem(dateStr));

        row++;
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
    QString date = ui->lineEdit_date->text();

    if(crud.ajouter(id,nom,adresse,type,nbrUnite,nbrHabitants,etat,date)){
        dernierIDResidence = id;
        QMessageBox::information(this,"Succès", "Résidence ajoutée avec succès !");
        afficherTable();
    } else {
        QMessageBox::critical(this,"Erreur","Échec de l'ajout !");
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
    QString date = ui->lineEdit_date->text();

    if(crud.modifier(id,nom,adresse,type,nbrUnite,nbrHabitants,etat,date)){
        QMessageBox::information(this,"Succès","Résidence modifiée !");
        afficherTable();
    } else {
        QMessageBox::critical(this,"Erreur","Échec modification !");
    }
}

void MainWindow::on_pushButton_delete_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    if(crud.supprimer(id)){
        QMessageBox::information(this,"Succès","Résidence supprimée !");
        afficherTable();
        if(id == dernierIDResidence) dernierIDResidence = getDerniereResidenceID();
    } else {
        QMessageBox::critical(this,"Erreur","Échec suppression !");
    }
}

// --- Recherche / tri / export / statistiques ---
void MainWindow::on_recherche_clicked()
{
    int id = ui->search->text().toInt();
    QSqlQuery query = crud.rechercherParID(id);

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(8);
    ui->affichage->setHorizontalHeaderLabels({"ID","Nom","Adresse","Type","Nbr Unités","Nbr Habitants","État","Date Création"});

    int row=0;
    while(query.next()){
        ui->affichage->insertRow(row);
        for(int col=0; col<8; ++col)
            ui->affichage->setItem(row,col,new QTableWidgetItem(query.value(col).toString()));
        row++;
    }

    if(row==0) QMessageBox::information(this,"Résultat","Aucune résidence trouvée.");
}

void MainWindow::on_trie_clicked()
{
    QSqlQueryModel *model = crud.trierParNbrHabitants();
    if(!model) return;

    ui->affichage->clear();
    ui->affichage->setRowCount(0);
    ui->affichage->setColumnCount(model->columnCount());
    ui->affichage->setHorizontalHeaderLabels({"ID","Nom","Adresse","Type","Nbr Unités","Nbr Habitants","État","Date Création"});

    for(int row=0; row<model->rowCount(); ++row){
        ui->affichage->insertRow(row);
        for(int col=0; col<model->columnCount(); ++col)
            ui->affichage->setItem(row,col,new QTableWidgetItem(model->data(model->index(row,col)).toString()));
    }
    delete model;
}

void MainWindow::on_statistique_clicked()
{
    QSqlQuery query = crud.statistiquesHabitants();
    if(!query.isActive()) return;

    QPieSeries *series = new QPieSeries();
    while(query.next()) series->append(query.value(0).toString(),query.value(1).toInt());

    for(QPieSlice *slice : series->slices()) slice->setLabelVisible(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des résidences selon le nombre d'habitants");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *view = new QChartView(chart, ui->chart);
    view->setRenderHint(QPainter::Antialiasing);
    view->setGeometry(ui->chart->rect());
    view->show();
}

void MainWindow::on_exporter_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Exporter en PDF","","*.pdf");
    if(fileName.isEmpty()) return;
    if(!fileName.endsWith(".pdf")) fileName += ".pdf";

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html = "<h2>Liste des Résidences</h2><table border='1'><tr>"
                   "<th>ID</th><th>Nom</th><th>Adresse</th><th>Type</th>"
                   "<th>Nbr Unités</th><th>Nbr Habitants</th><th>État</th><th>Date Création</th></tr>";

    QSqlQuery query("SELECT ID_RESIDENCE,NOM,ADRESSE,TYPE_RESIDENCE,NBR_UNITE,NBR_HABITANTS,ETAT,DATE_CONST FROM RESIDENCE");
    while(query.next()){
        html += "<tr>";
        for(int i=0;i<8;i++) html += "<td>"+query.value(i).toString()+"</td>";
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);
    QMessageBox::information(this,"Export PDF","Export terminé !");
}

// --- Lecture Arduino ---
// Ajouter un attribut dans MainWindow
QString bufferSerial;

// Slot pour lecture série
void MainWindow::onSerialDataReceived()
{
    QByteArray data = serial->readAll();
    bufferSerial += QString(data); // accumuler les fragments

    int index;
    while ((index = bufferSerial.indexOf('\n')) != -1) { // tant qu'il y a une ligne complète
        QString line = bufferSerial.left(index).trimmed(); // extraire la ligne
        bufferSerial.remove(0, index + 1); // retirer du buffer

        bool ok;
        float temp = line.toFloat(&ok);
        if(ok && temp >= -10 && temp <= 50) { // vérifier plage raisonnable
            ui->btnTemp->setText(QString::number(temp,'f',1) + " °C");

            // mettre à jour BD
            QSqlQuery query;
            query.prepare("UPDATE RESIDENCE SET TEMPERATURE = :t WHERE ID_RESIDENCE = :id");
            query.bindValue(":t", temp);
            query.bindValue(":id", dernierIDResidence > 0 ? dernierIDResidence : 1);
            query.exec();
        }
    }
}


// --- Lecture automatique toutes les 30 sec ---
void MainWindow::lireTemperatureArduino()
{
    if (!serial->isOpen()) return;

    serial->write("READ\n");
    serial->flush();

    if(!serial->waitForReadyRead(500)) return;

    QByteArray data = serial->readAll();
    QString tempStr = QString(data).trimmed();

    bool ok;
    float temp = tempStr.toFloat(&ok);
    if(!ok) return;

    ui->btnTemp->setText(QString::number(temp,'f',1) + " °C");

    QSqlQuery query;
    query.prepare("UPDATE RESIDENCE SET TEMPERATURE = :t WHERE ID_RESIDENCE = :id");
    query.bindValue(":t", temp);
    query.bindValue(":id", dernierIDResidence>0 ? dernierIDResidence : 1);
    query.exec();
}

// --- Bouton lecture manuelle ---
void MainWindow::on_btnTemp_clicked()
{
    lireTemperatureArduino();
}

// --- Popups horaires ---
QString MainWindow::getMessageForCurrentTime()
{
    int hour = QTime::currentTime().hour();
    auto randomChoice = [](QStringList list){ return list.at(QRandomGenerator::global()->bounded(list.size())); };

    if(hour>=7 && hour<=11) return randomChoice({"Bon matin ! Vérifiez les résidences critiques.","Consultez le responsable de service."});
    if(hour>=12 && hour<=16) return randomChoice({"Mi-journée : vérifiez les résidences.","Consultez les modifications récentes."});
    if(hour>=17 && hour<=20) return randomChoice({"Fin de journée : sauvegardez vos données.","Vérifiez les résidences pour demain."});
    if(hour>=21 && hour<=23) return randomChoice({"Nuit : pensez à sauvegarder vos données."});
    if(hour>=0 && hour<=6) return randomChoice({"Tôt le matin : vérifiez les résidences critiques."});

    return "";
}

// --- KeyPressEvent ---
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_P){
        QSqlQuery query("SELECT NOM,NBR_UNITE,NBR_HABITANTS,ETAT,DATE_CONST FROM RESIDENCE");
        QString msg="Priorité des résidences :\n\n";
        while(query.next()){
            int etat=query.value("ETAT").toInt();
            int nbHab=query.value("NBR_HABITANTS").toInt();
            int nbUnite=query.value("NBR_UNITE").toInt();
            int date=query.value("DATE_CONST").toInt();
            QString nom=query.value("NOM").toString();
            double prio=(5-etat)*0.4+((double)nbHab/nbUnite)*0.3+(2025-date/10000)*0.3;
            msg+=nom+" → "+QString::number(prio,'f',2)+"\n";
        }
        QDialog dialog(this);
        dialog.setWindowTitle("Priorités");
        dialog.resize(600,500);
        QVBoxLayout *layout=new QVBoxLayout(&dialog);
        QTextEdit *text=new QTextEdit();
        text->setReadOnly(true);
        text->setFont(QFont("Arial",11));
        text->setText(msg);
        layout->addWidget(text);
        dialog.exec();
    }
}
