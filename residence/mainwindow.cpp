#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud_residence.h"
#include "crud_employe.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    crudEmp = new CRUD_emp(db, ui, this);

    db = QSqlDatabase::addDatabase("QODBC"); // or "QODBC", "QMYSQL", etc.
    db.setDatabaseName("XE");
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("22180595");
    bool success = db.open();
    if (!db.open()) {
        qDebug() << "❌ ERREUR FATALE DE CONNEXION:";
        qDebug() << "  Cause:" << db.lastError().text(); // <-- C'EST LE MESSAGE CLÉ
        // (If the app is crashing, you may need to exit gracefully here)
    } else {
        qDebug() << "✅ Connexion à la base de données réussie.";
    }



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
    delete crudEmp;
}
void MainWindow::afficherTable()
{
    QSqlQuery query("SELECT ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, "
                    "NBR_UNITE, NBR_HABITANTS, ETAT, TO_CHAR(DATE_CREATION, 'YYYY-MM-DD') "
                    "FROM RESIDENCE");

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
    QString dateCreation = ui->lineEdit_date->text(); // format : YYYY-MM-DD

    QSqlQuery query;
    QString sql = QString(
                      "INSERT INTO RESIDENCE "
                      "(ID_RESIDENCE, NOM, ADRESSE, TYPE_RESIDENCE, NBR_UNITE, NBR_HABITANTS, ETAT, DATE_CREATION) "
                      "VALUES (%1, %2, %3, %4, %5, %6, %7, '%8')"
                      ).arg(id)
                      .arg(nom)
                      .arg(adresse)
                      .arg(type)
                      .arg(nbrUnite)
                      .arg(nbrHabitants)
                      .arg(etat)
                      .arg(dateCreation);
    query.finish();

    if (query.exec(sql)) {
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











void MainWindow::on_Ajouter_3_clicked()
{

}

