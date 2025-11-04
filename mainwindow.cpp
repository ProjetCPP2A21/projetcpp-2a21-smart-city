#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // For message dialogs

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // --- Your existing page navigation connections ---
    QObject::connect(ui->RH, SIGNAL(clicked()), this, SLOT(page_4()));
    QObject::connect(ui->residence_2, SIGNAL(clicked()), this, SLOT(page_3()));
    QObject::connect(ui->resident, SIGNAL(clicked()), this, SLOT(page()));
    QObject::connect(ui->RH_2, SIGNAL(clicked()), this, SLOT(page_4()));
    QObject::connect(ui->resident_2, SIGNAL(clicked()), this, SLOT(page()));
    QObject::connect(ui->residence_3, SIGNAL(clicked()), this, SLOT(page_3()));
    QObject::connect(ui->resident_3, SIGNAL(clicked()), this, SLOT(page()));

    // --- NEW: show the list of residents when the program starts ---
    ui->tableView->setModel(Rtmp.afficher());
}

// --- Your existing page navigation functions ---
void MainWindow::page_3()
{
    QObject::connect(ui->RH, SIGNAL(clicked()), this, SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    QObject::connect(ui->resident_2, SIGNAL(clicked()), this, SLOT(page()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

void MainWindow::page_4()
{
    QObject::connect(ui->residence_2, SIGNAL(clicked()), this, SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    QObject::connect(ui->resident_3, SIGNAL(clicked()), this, SLOT(page()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}

void MainWindow::page()
{
    QObject::connect(ui->RH_2, SIGNAL(clicked()), this, SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page);
    QObject::connect(ui->residence_3, SIGNAL(clicked()), this, SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ======================================================
// 🧩 NEW PART : CRUD for Resident
// ======================================================

// --- ADD a new resident ---
void MainWindow::on_btn_ajouter_clicked()
{
    // Get data from input fields in your UI
    int identifiant = ui->lineEdit_identifiant->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    int age = ui->lineEdit_age->text().toInt();
    QString sexe = ui->lineEdit_sexe->text();
    QString profession = ui->lineEdit_profession->text();
    QString situation = ui->lineEdit_situation->text();

    // Create a Resident object with the entered data
    Resident R(identifiant, nom, age, sexe, profession, situation);

    // Try to insert into database
    bool test = R.ajouter();

    if (test)
    {
        ui->tableView->setModel(Rtmp.afficher()); // Refresh table view
        QMessageBox::information(this, "Succès", "Résident ajouté avec succès !");
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Échec de l’ajout du résident !");
    }
}

// --- DELETE a resident by ID ---
void MainWindow::on_btn_supprimer_clicked()
{
    int id = ui->lineEdit_identifiant->text().toInt(); // Get the ID

    bool test = Rtmp.supprimer(id);

    if (test)
    {
        ui->tableView->setModel(Rtmp.afficher()); // Refresh table view
        QMessageBox::information(this, "Succès", "Résident supprimé avec succès !");
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression !");
    }
}
