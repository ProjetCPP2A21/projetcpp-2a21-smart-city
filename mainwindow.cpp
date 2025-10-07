#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    QObject :: connect(ui->resident, SIGNAL(clicked()),this ,SLOT(page()));
    QObject :: connect(ui->RH_2, SIGNAL(clicked()),this ,SLOT(page_4()));
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    QObject :: connect(ui->resident_2, SIGNAL(clicked()),this ,SLOT(page()));
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    QObject :: connect(ui->residence_3, SIGNAL(clicked()),this ,SLOT(page_3()));
    QObject :: connect(ui->resident_3, SIGNAL(clicked()),this ,SLOT(page()));
}
void MainWindow :: page_3()
{
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    QObject :: connect(ui->resident_2, SIGNAL(clicked()),this ,SLOT(page()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
void MainWindow :: page_4()
{
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    QObject :: connect(ui->resident_3, SIGNAL(clicked()),this ,SLOT(page()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);

}
void MainWindow :: page()
{
    QObject :: connect(ui->RH_2, SIGNAL(clicked()),this ,SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page);
    QObject :: connect(ui->residence_3, SIGNAL(clicked()),this ,SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page);
}
MainWindow::~MainWindow()
{
    delete ui;
}
