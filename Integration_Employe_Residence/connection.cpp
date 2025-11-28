#include "connection.h"

Connection::Connection()
{
    // Create the connection ONCE, give it a name
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createConnection()
{
    if (db.isOpen())
        return true;

    db.setDatabaseName("Source2A");
    db.setUserName("ALEE");
    db.setPassword("esprit25");

    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected successfully.";
    return true;
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
