#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QTimer>
#include <QTime>
#include <QRandomGenerator>
#include <cstdlib>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*GEmployer* gEmp = new GEmployer(ui->page_employer, this);*/
    afficherTableResidence();

    timerPopup = new QTimer(this);
    connect(timerPopup, &QTimer::timeout, this, &MainWindow::handlePopupTimer);
    connect(timerPopup, &QTimer::timeout, this, [this]() {
        QString message = getMessageForCurrentTime();
        if (!message.isEmpty()) {
            QMessageBox::information(this, "Recommandation NEOCITY", message);
        }
    });
    timerPopup->start(30000);

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
    connect(ui->Evenements_4, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
    connect(ui->service_3, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- RÉSIDENT PAGE (page) ---
    //
    connect(ui->RH_2, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->residence_3, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); });
    connect(ui->Evenements_2, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
    connect(ui->service, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- RÉSIDENCE PAGE (page_3) ---
    //
    connect(ui->RH_3, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->resident_2, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->Evenements_3, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
    connect(ui->service_2, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- ÉVÈNEMENTS PAGE (page_2) ---
    //
    connect(ui->RH_3, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->residence_4, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); });
    connect(ui->resident_4, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->service_4, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- SERVICE PAGE (page_6) ---
    //
    connect(ui->RH_6, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->residence_7, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); }); // ✅ FIXED
    connect(ui->resident_8, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->Evenements_8, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
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












