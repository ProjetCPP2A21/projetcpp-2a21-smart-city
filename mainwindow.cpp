#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "residents.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Navigation
    QObject::connect(ui->RH, SIGNAL(clicked()), this, SLOT(page_4()));
    QObject::connect(ui->residence_2, SIGNAL(clicked()), this, SLOT(page_3()));
    QObject::connect(ui->resident, SIGNAL(clicked()), this, SLOT(page()));
    QObject::connect(ui->RH_2, SIGNAL(clicked()), this, SLOT(page_4()));
    QObject::connect(ui->residence_3, SIGNAL(clicked()), this, SLOT(page_3()));
    QObject::connect(ui->resident_3, SIGNAL(clicked()), this, SLOT(page()));

    // Charger table
    Resident Rtmp;
    ui->tableView->setModel(Rtmp.afficher());

    // ComboBox de tri
    ui->comboBox_tri->addItem("Nom");
    ui->comboBox_tri->addItem("Age");
    ui->comboBox_tri->addItem("Sexe");
}

void MainWindow::page_3() { ui->stackedWidget->setCurrentWidget(ui->page_3); }
void MainWindow::page_4() { ui->stackedWidget->setCurrentWidget(ui->page_4); }
void MainWindow::page() { ui->stackedWidget->setCurrentWidget(ui->page); }

void MainWindow::on_btn_ajouter_clicked()
{
    int id_resident = ui->lineEdit_idresident->text().toInt();
    int id_residence = 250;
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    int age = ui->lineEdit_age->text().toInt();
    QString sexe = ui->lineEdit_sexe->text();
    QString profession = ui->lineEdit_profession->text();
    QString situation = ui->lineEdit_situation->text();

    Resident R(id_resident, id_residence, nom, prenom, age, sexe, profession, situation);

    if (R.ajouter()) {
        QMessageBox::information(this, "Succès", "Résident ajouté !");
        ui->tableView->setModel(R.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout échoué !");
    }
}

void MainWindow::on_btn_supprimer_clicked()
{
    int id = ui->lineEdit_idresident->text().toInt();
    Resident R;

    if (R.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Résident supprimé !");
        ui->tableView->setModel(R.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression échouée !");
    }
}

void MainWindow::on_btn_modifier_clicked()
{
    int id_resident = ui->lineEdit_idresident->text().toInt();
    int id_residence = 250;
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    int age = ui->lineEdit_age->text().toInt();
    QString sexe = ui->lineEdit_sexe->text();
    QString profession = ui->lineEdit_profession->text();
    QString situation = ui->lineEdit_situation->text();

    Resident R(id_resident, id_residence, nom, prenom, age, sexe, profession, situation);

    if (R.modifier()) {
        QMessageBox::information(this, "Succès", "Résident modifié !");
        ui->tableView->setModel(R.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Modification échouée !");
    }
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    Resident R;
    ui->tableView->setModel(R.rechercher(arg1));
}

void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
    Resident R;
    QString critere;

    if (index == 0)
        critere = "NOM";
    else if (index == 1)
        critere = "AGE";
    else if (index == 2)
        critere = "SEXE";

    ui->tableView->setModel(R.trier(critere, "ASC"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
