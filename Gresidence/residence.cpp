#include "residence.h"
#include "ui_residence.h"
#include "gemployer.h"


residence::residence(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::residence)
{
    ui->setupUi(this);
    connect(ui->RH, &QPushButton::clicked, this, &residence::openOtherWindow);

}

residence::~residence()
{
    delete ui;
}
void residence::openOtherWindow() {
    GEmployer *w = new GEmployer(this);  // or without `this` if you want it independent
    w->show();
}

