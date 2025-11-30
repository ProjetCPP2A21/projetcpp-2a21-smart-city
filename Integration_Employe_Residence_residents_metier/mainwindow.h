/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include "CrudResidence.h"
#include "residence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timerPopup;
    QString getMessageForCurrentTime();

private slots:
    void on_connecter_clicked();
    void on_Modifier_Employe_clicked();


    void on_Ajouter_Employe_clicked();

    void on_Supprimer_Employe_clicked();
    void clearChamps();
    void remplirTable(QSqlQuery &query);
    void afficherEmployes();
    void on_tableWidgetEmployes_cellClicked(int row, int column);
    void on_recherche_clicked();
    void on_trie_clicked();


    void on_Rechercher_Employe_2_clicked();

    //residence
    void afficherTableResidence();


    void on_Ajouter_Residence_clicked();

    void on_Modifier_Residence_clicked();

    void on_Supprimer_Residence_clicked();

    void keyPressEvent(QKeyEvent *event);



private:
    Ui::MainWindow *ui;
    CRUD crud;
    void goToPage(QWidget *page);
};

#endif // MAINWINDOW_H*/
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
    QString hashPassword(const QString &password);
    void onLoginClicked();
    void goToPage(QWidget *page);
    void on_Trier_2_clicked();
    void on_Exporter_2_clicked();
    void on_Statistiques_2_clicked();


    void on_Rechercher_Employe_2_clicked();

    //residence
    void afficherTableResidence();


    void on_Ajouter_Residence_clicked();

    void on_Modifier_Residence_clicked();

    void on_Supprimer_Residence_clicked();
    void on_recherche_clicked();
    void on_statistique_clicked();
    void keyPressEvent(QKeyEvent *event);

    void on_trie_clicked();
    void on_exporter_clicked();
    void handlePopupTimer();
    //residents
    void on_btn_ajouter_clicked();
    void on_btn_modifier_clicked();
    void on_btn_supprimer_clicked();
    void on_recherche_residents_textChanged(const QString &arg1);
    void on_btn_statistiques_clicked();
    void afficherStatistiques();
    void on_btnExportPDF_clicked();
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_tableView_clicked(const QModelIndex &index);
    void clearFields();
    QString calculerStabilite(int age, QString profession, QString situation);
    QString calculerMobilite(int age, QString profession, QString situation);

private:
    Ui::MainWindow *ui;
    CRUD crud;
    QTimer *timerPopup;
    QString getMessageForCurrentTime();
};

#endif // MAINWINDOW_H
