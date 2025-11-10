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

    void on_tableServices_itemSelectionChanged();
    void on_Rechercher_Employe_2_clicked();

    //residence
    void afficherTableResidence();


    void on_Ajouter_Residence_clicked();

    void on_Modifier_Residence_clicked();

    void on_Supprimer_Residence_clicked();

    // Service
    void on_Ajouter_Service_clicked();
    void afficherServices();
    void on_Modifier_Service_clicked();
    void on_Supprimer_Service_clicked();
    void on_rechercher_Service_clicked();
    void on_tableServices_cellActivated(int row, int column);
    void trierServices(int index);
    void viderChamps();


private:
    Ui::MainWindow *ui;
    CRUD crud;
    void goToPage(QWidget *page);
};

#endif // MAINWINDOW_H
