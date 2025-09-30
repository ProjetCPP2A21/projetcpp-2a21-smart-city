#include "rh.h"
#include "ui_rh.h"
#include"events.h"
#include"residence.h"
#include"service.h"
#include"mainwindow.h"
RH::RH(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RH)
{
    ui->setupUi(this);
}

RH::~RH()
{
    delete ui;
}

void RH::on_pushButton_13_clicked()
{
    events *page = new events();
    page->show();
    this->close();
}


void RH::on_pushButton_11_clicked()
{
    residence *page = new residence();
    page->show();
    this->close();
}


void RH::on_pushButton_14_clicked()
{
    service *page = new service();
    page->show();
    this->close();
}


void RH::on_pushButton_12_clicked()
{
    MainWindow *page = new MainWindow();
    page->show();
    this->close();
}


