/*#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include "CrudResidence.h"
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
    void ajouterTable();
    void afficherTableResidence();
    void setupTableHeaders();
    QTimer *timerPopup;
    QString getMessageForCurrentTime();

public slots :
    void page_3();
    void page_4();

private slots:
    void on_Ajouter_Residence_clicked();
    void on_Modifier_Residence_clicked();
    void on_Supprimer_Residence_clicked();
    void on_recherche_clicked();
    void on_statistique_clicked();
    void keyPressEvent(QKeyEvent *event);

    void on_trie_clicked();
    void on_exporter_clicked();
};
#endif*/
#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "connection.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include "CrudResidence.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GResidence : public QMainWindow
{
    Q_OBJECT

public:

private:
    CRUD crud;
    void ajouterTable();
    void afficherTableResidence();
    void setupTableHeaders();
    QTimer *timerPopup;
    QString getMessageForCurrentTime();
public slots :

private slots:
    /*void on_Ajouter_Residence_clicked();
    void on_Modifier_Residence_clicked();
    void on_Supprimer_Residence_clicked();
    void on_recherche_clicked();
    void on_statistique_clicked();
    void keyPressEvent(QKeyEvent *event);

    void on_trie_clicked();
    void on_exporter_clicked();*/
};
#endif // RESIDENCE_H
