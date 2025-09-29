#include "events.h"
#include "ui_events.h"

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
