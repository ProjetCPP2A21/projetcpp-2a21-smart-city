#include "gemployer.h"
#include "ui_gemployer.h"

GEmployer::GEmployer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GEmployer)
{
    ui->setupUi(this);
}

GEmployer::~GEmployer()
{
    delete ui;
}

