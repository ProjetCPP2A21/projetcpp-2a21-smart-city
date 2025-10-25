#include "gevenement.h"
#include "ui_gevenement.h"

GEvenement::GEvenement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GEvenement)
{
    ui->setupUi(this);
}

GEvenement::~GEvenement()
{
    delete ui;
}



void GEvenement::on_Ajouterbutton_clicked()
{
    int id = ui->ID->text().toInt();

}

