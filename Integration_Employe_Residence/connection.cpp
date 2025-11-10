#include "connection.h"

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

Connection::~Connection()
{
    if (db.isOpen())
        db.close();
}

Connection& Connection::instance()
{
    static Connection instance;
    return instance;
}

bool Connection::createConnection()
{
    db.setDatabaseName("Source2A");
    db.setUserName("ALEE");
    db.setPassword("esprit25");

    if (db.open()) {
        qDebug() << "Connexion établie ✅";
        return true;
    } else {
        qDebug() << "Échec de la connexion ❌:" << db.lastError().text();
        return false;
    }
}
