#include "residence.h"
#include "ui_residence.h"



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

