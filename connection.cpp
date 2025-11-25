#include "connection.h"

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");   // nom de ta source ODBC
    db.setUserName("Maram");        // ton nom utilisateur Oracle
    db.setPassword("1429705");     // ton mot de passe Oracle

    return db.open(); // retourne vrai si la connexion réussit
}
