#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include "crud_residence.h"
#include "employer.h"
#include "crud_employe.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CRUD crud;
    employer e;
    CRUD_emp *crudEmp;
    QSqlDatabase db;
    void ajouterTable();
    void afficherTable();
    bool ajouter();
public slots :
    void page_3();
    void page_4();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_delete_clicked();
    void on_Ajouter_3_clicked();
};
#endif // MAINWINDOW_H

