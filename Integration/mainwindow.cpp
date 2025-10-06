#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //page_3
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    QObject :: connect(ui->resident_2, SIGNAL(clicked()),this ,SLOT(page()));
    QObject :: connect(ui->Evenements_3, SIGNAL(clicked()),this ,SLOT(page_2()));
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    //page_4
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    QObject :: connect(ui->resident_3, SIGNAL(clicked()),this ,SLOT(page()));
    QObject :: connect(ui->Evenements_4, SIGNAL(clicked()),this ,SLOT(page_2()));
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    //page
    QObject :: connect(ui->RH_2, SIGNAL(clicked()),this ,SLOT(page_4()));
    QObject :: connect(ui->residence_3, SIGNAL(clicked()),this ,SLOT(page_3()));
    QObject :: connect(ui->Evenements, SIGNAL(clicked()),this ,SLOT(page_2()));
    QObject :: connect(ui->resident, SIGNAL(clicked()),this ,SLOT(page()));
    //page_2
    QObject :: connect(ui->RH_2, SIGNAL(clicked()),this ,SLOT(page_4()));
    QObject :: connect(ui->residence_4, SIGNAL(clicked()),this ,SLOT(page_3()));
    QObject :: connect(ui->resident, SIGNAL(clicked()),this ,SLOT(page()));
    QObject :: connect(ui->Evenements, SIGNAL(clicked()),this ,SLOT(page_2()));
    //test

}
void MainWindow :: page_3()
{
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    QObject :: connect(ui->resident_2, SIGNAL(clicked()),this ,SLOT(page()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    QObject :: connect(ui->Evenements_3, SIGNAL(clicked()),this ,SLOT(page_2()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
void MainWindow :: page_4()
{
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    QObject :: connect(ui->resident_3, SIGNAL(clicked()),this ,SLOT(page()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    QObject :: connect(ui->Evenements_4, SIGNAL(clicked()),this ,SLOT(page_2()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}
void MainWindow :: page()
{
    QObject :: connect(ui->RH_2, SIGNAL(clicked()),this ,SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page);
    QObject :: connect(ui->residence_3, SIGNAL(clicked()),this ,SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page);
    QObject :: connect(ui->Evenements_2, SIGNAL(clicked()),this ,SLOT(page_2()));
    ui->stackedWidget->setCurrentWidget(ui->page);
}
void MainWindow :: page_2()
{
    QObject :: connect(ui->RH_3, SIGNAL(clicked()),this ,SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    QObject :: connect(ui->residence_4, SIGNAL(clicked()),this ,SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    QObject :: connect(ui->resident_4, SIGNAL(clicked()),this ,SLOT(page()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);

}
MainWindow::~MainWindow()
{
    delete ui;
}
