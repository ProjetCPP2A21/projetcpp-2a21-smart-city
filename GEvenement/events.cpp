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


void Events::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
}


void Events::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Accueil *page = new Accueil();
    page->show();
    this->close();
}



