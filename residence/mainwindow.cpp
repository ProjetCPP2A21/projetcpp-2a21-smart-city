/*#include <QTreeWidget>
#include <QTreeWidgetItem>


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../GEvenement/events.h"
#include "../GEvenement/accueil.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Events *page = new Events();
    /*page->resize(this->size());*/
    /*page->show();*/
    /*this->showMaximized();*/
    /*this->close();*/
/*}*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup table headers
    ui->tableWidget->setColumnCount(8);
    QStringList headers;
    headers << "ID_résidence" << "Nom de la résidence" << "Adresse"
            << "Type" << "Nbr d’unités" << "Nbr d’habitants"
            << "État" << "Date de construction";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot for the "Ajouter" button
void MainWindow::on_pushButton_ajouter_clicked()
{
    // Read data from input fields
    QString id = ui->lineEdit_id->text();
    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString type = ui->lineEdit_type->text();
    QString nbrUnites = ui->lineEdit_nbrUnites->text();
    QString nbrHabitants = ui->lineEdit_nbrHabitants->text();
    QString etat = ui->lineEdit_etat->text();
    QString dateConstruction = ui->lineEdit_date->text();

    // Optional: check for empty fields
    if(id.isEmpty() || nom.isEmpty())
        return;

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    // Add data to table
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(id));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nom));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(adresse));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(type));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(nbrUnites));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(nbrHabitants));
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(etat));
    ui->tableWidget->setItem(row, 7, new QTableWidgetItem(dateConstruction));

    // Clear input fields
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_nbrUnites->clear();
    ui->lineEdit_nbrHabitants->clear();
    ui->lineEdit_etat->clear();
    ui->lineEdit_date->clear();
}




