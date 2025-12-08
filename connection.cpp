
/*#include "connection.h"

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");

}

bool Connection::createConnection()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source2A");//inserer le nom de la source de données
db.setUserName("ALEE");//inserer nom de l'utilisateur
db.setPassword("esprit25");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
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
}*/
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

    db.setDatabaseName("Source_projet2A");
    db.setUserName("maram");
    db.setPassword("1429705");

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

