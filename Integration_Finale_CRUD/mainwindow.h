#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include "CrudResidence.h"
#include "evenement.h"
#include "residents.h"

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

    // Service
    void on_Ajouter_Service_clicked();
    void afficherServices();
    void on_Modifier_Service_clicked();
    void on_Supprimer_Service_clicked();
    void on_rechercher_Service_clicked();
    void on_tableServices_cellActivated(int row, int column);
    void trierServices(int index);
    void viderChamps();

    // residents
    void on_Ajouter_Resident_clicked();
    void on_Supprimer_Resident_clicked();
    void on_Modifier_resident_clicked();
    void on_Rechercher_Resident_textChanged(const QString &arg1);
    void on_comboBox_tri_Resident_currentIndexChanged(int index);


    // Evenement
    void on_Ajouterbutton_clicked();
    void on_Supprimer_clicked();
    void on_Modifier_clicked();
    //void on_Rechercher_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_comboBox_currentIndexChanged(int index);
    void on_Recherche_Line_textChanged(const QString &text);
    void on_tableServices_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    CRUD crud;
    Evenement E;
    Resident Rtmp;
    void goToPage(QWidget *page);
};

#endif // MAINWINDOW_H
