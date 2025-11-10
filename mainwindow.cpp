#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherTableResidence();
    afficherServices();

    // 🟢 Show the login page first
    ui->stackedWidget->setCurrentWidget(ui->Connection);

    // 🟥 "Quitter" button → Close the window
    connect(ui->quitter, &QPushButton::clicked, this, &QMainWindow::close);

    // 🔵 "Mot de passe oublié" → Go to page_7
    connect(ui->mdpo_2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page_7);
    });
    connect(ui->retour, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->Connection);
    });


    //
    // --- DASHBOARD (page_4) ---
    //
    connect(ui->RH, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->resident_3, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->residence_2, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); });
    connect(ui->service_3, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //

    //
    // --- RÉSIDENCE PAGE (page_3) ---
    //
    connect(ui->resident_2, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->service_2, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- ÉVÈNEMENTS PAGE (page_2) ---
    //


    //
    // --- SERVICE PAGE (page_6) ---
    //
    connect(ui->RH_6, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->residence_7, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); }); // ✅ FIXED
    connect(ui->resident_8, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
// === UNIVERSAL PAGE SWITCH FUNCTION ===
//
void MainWindow::goToPage(QWidget *page)
{
    if (page && ui->stackedWidget->indexOf(page) != -1)
        ui->stackedWidget->setCurrentWidget(page);
}


