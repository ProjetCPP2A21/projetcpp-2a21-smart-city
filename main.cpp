#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test = c.createconnect(); // Try to connect to Oracle DB

    if (test)
    {
        // ✅ Connection successful → show main window
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Connexion à la base réussie !"));
        MainWindow w;
        w.show();
        return a.exec(); // Start the application
    }
    else
    {
        // ❌ Connection failed → show error message and exit
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Échec de connexion à la base de données.\n"
                                          "Vérifiez votre configuration ODBC."));
        return 1;
    }
}
