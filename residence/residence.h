#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "ui_residence.h"
#include "connection.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include "crud.h"
#include "arduino.h"



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
    void afficherTable();
    void setupTableHeaders();
    QTimer *timerPopup;
    QString getMessageForCurrentTime();
    Arduino A;

public slots :
    void page_3();
    void page_4();

private slots:
    void checkTemperatureAndAlert();
    void on_pushButton_add_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_delete_clicked();
    void on_recherche_clicked();
    void on_statistique_clicked();
    void keyPressEvent(QKeyEvent *event);

    void on_trie_clicked();
    void on_exporter_clicked();
};
#endif // RESIDENCE_H
