#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"rh.h"
#include"residence.h"
#include"service.h"
#include"events.h"
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

void MainWindow::on_pushButton_7_clicked()
{
    RH *page = new RH();
    page->show();
    this->close();
}


void MainWindow::on_pushButton_12_clicked()
{
    residence *page = new residence();
    page->show();
    this->close();
}



void MainWindow::on_pushButton_15_clicked()
{
    service *page = new service();
    page->show();
    this->close();
}


void MainWindow::on_pushButton_14_clicked()
{
    events *page = new events();
    page->show();
    this->close();
}





