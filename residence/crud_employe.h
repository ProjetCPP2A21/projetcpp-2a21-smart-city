/*#ifndef CRUD_EMPLOYE_H
#define CRUD_EMPLOYE_H
#include "employer.h"
#include <QSqlQuery>
#include <QWidget>
#include <QObject>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class CRUD_emp;
}
QT_END_NAMESPACE

class CRUD_emp : public QMainWindow
{
    Q_OBJECT

public:
    explicit CRUD_emp(QSqlDatabase &db, QObject *parent = nullptr);
    ~CRUD_emp();

private slots:
    void onAjouterClicked();
    void onModifierClicked();
    void onSupprimerClicked();
    void onRechercherClicked();
    void afficherEmployes();
    void remplirTable(QSqlQuery &query);
    void clearChamps();
    void goToPage(QWidget *page);
    void onLoginClicked();
    void onTableEmployeClicked(int row, int column);
private:
    Ui::CRUD_emp *ui;
    QSqlDatabase &m_bd;
};

#endif // CRUD_EMPLOYE_H*/
// CRUD_emp.h

#ifndef CRUD_EMPLOYE_H
#define CRUD_EMPLOYE_H
#include "connection.h"
#include <QMainWindow>
#include <QSqlDatabase> //
#include <QSqlQuery>
// #include <QWidget>
 #include <QObject>
#include <QTableWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class CRUD_emp : public QObject
{
    Q_OBJECT

public:

    explicit CRUD_emp(QSqlDatabase &db, Ui::MainWindow *mainUi, QObject *parent = nullptr); // <-- 3. Changed QObject* to QWidget*
    ~CRUD_emp();

private slots:
    void onajouterClicked();
    void onModifierClicked();
    void onSupprimerClicked();
    void onRechercherClicked();
    void afficherEmployes();
    void remplirTable(QSqlQuery &query);
    void clearChamps();
    void goToPage(QWidget *page);
    /*void onLoginClicked();*/
    void onTableEmployeClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    QSqlDatabase &m_bd;

};

#endif // CRUD_EMPLOYE_H

