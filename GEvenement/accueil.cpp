#include "accueil.h"
#include "ui_accueil.h"
#include "events.h"

Accueil::Accueil(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}


void Accueil::on_pushButton_7_clicked()
{
    Events *page = new Events();
    page->show();
    this->close();
}



