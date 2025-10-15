#include "gevenement.h"
#include "ui_gevenement.h"
#include "../Atelier_Connexion/connection.h"

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

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
    db.setUserName("Youssef");//inserer nom de l'utilisateur
    db.setPassword("Klibi26");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
