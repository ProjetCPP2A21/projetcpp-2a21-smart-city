#include "service.h"
#include "ui_service.h"
#include"rh.h"
#include"residence.h"
#include"events.h"
#include"mainwindow.h"
service::service(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::service)
{
    ui->setupUi(this);
}

service::~service()
{
    delete ui;
}

void service::on_pushButton_clicked()
{
    RH *page = new RH();
    page->show();
    this->close();
}


void service::on_pushButton_5_clicked()
{
    residence *page = new residence();
    page->show();
    this->close();
}


void service::on_pushButton_8_clicked()
{
    events *page = new events();
    page->show();
    this->close();
}


void service::on_pushButton_7_clicked()
{
    MainWindow *page = new MainWindow();
    page->show();
    this->close();
}



void service::on_label_linkActivated(const QString &link)
{

}

