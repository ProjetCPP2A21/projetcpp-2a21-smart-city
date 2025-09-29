#include "events.h"
#include "./ui_events.h"
#include "accueil.h"
#include "../residence/mainwindow.h"

Events::Events(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Events)
{
    ui->setupUi(this);
}

Events::~Events()
{
    delete ui;
}

void Events::on_pushButton_6_clicked()
{
    Accueil *page = new Accueil();
    page->show();
    this->close();
}

void Events::on_pushButton_5_clicked()
{
    MainWindow *page = new MainWindow();
    page->show();
    this->close();
}

