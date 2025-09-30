#include "events.h"
#include "ui_events.h"
#include"rh.h"
#include"residence.h"
#include"service.h"
#include"mainwindow.h"
events::events(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::events)
{
    ui->setupUi(this);
}

events::~events()
{
    delete ui;
}

void events::on_pushButton_6_clicked()
{
    RH *page = new RH();
    page->show();
    this->close();
}


void events::on_pushButton_12_clicked()
{
    residence *page = new residence();
    page->show();
    this->close();
}


void events::on_pushButton_15_clicked()
{
    service *page = new service();
    page->show();
    this->close();
}


void events::on_pushButton_13_clicked()
{
    MainWindow *page = new MainWindow();
    page->show();
    this->close();
}


