#include "residence.h"
#include "ui_residence.h"
#include"rh.h"
#include"events.h"
#include"service.h"
#include"mainwindow.h"
residence::residence(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::residence)
{
    ui->setupUi(this);
}

residence::~residence()
{
    delete ui;
}

void residence::on_pushButton_clicked()
{
    RH *page = new RH();
    page->show();
    this->close();
}


void residence::on_pushButton_13_clicked()
{
    events *page = new events();
    page->show();
    this->close();
}


void residence::on_pushButton_14_clicked()
{
    service *page = new service();
    page->show();
    this->close();
}


void residence::on_pushButton_7_clicked()
{
    MainWindow *page = new MainWindow();
    page->show();
    this->close();
}


