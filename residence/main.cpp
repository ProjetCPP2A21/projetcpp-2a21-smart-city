/*#include "residence.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}*/
#include "residence.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    if (c.createconnect()) {
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de connexion à la base de données !");
        return 0;
    }
}

