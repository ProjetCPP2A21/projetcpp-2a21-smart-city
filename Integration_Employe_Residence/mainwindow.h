#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include "CrudResidence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connecter_clicked();
    void on_Modifier_Employe_clicked();


    void on_Ajouter_Employe_clicked();

    void on_Supprimer_Employe_clicked();
    void clearChamps();
    void remplirTable(QSqlQuery &query);
    void afficherEmployes();
    void on_tableWidgetEmployes_cellClicked(int row, int column);


    void on_Rechercher_Employe_2_clicked();

    //residence
    void afficherTableResidence();


    void on_Ajouter_Residence_clicked();

    void on_Modifier_Residence_clicked();

    void on_Supprimer_Residence_clicked();

private:
    Ui::MainWindow *ui;
    CRUD crud;
    void goToPage(QWidget *page);
};

#endif // MAINWINDOW_H
