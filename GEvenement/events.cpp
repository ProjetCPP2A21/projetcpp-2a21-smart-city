#include "events.h"
#include "./ui_events.h"
#include "accueil.h"

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

