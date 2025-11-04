#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "residents.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Resident Rtmp; // 👈 object used for Resident operations (add, display, delete)

public slots:
    void page();    // your existing slot
    void page_3();  // your existing slot
    void page_4();  // your existing slot

    // 👇 new slots for Resident CRUD actions
    void on_btn_ajouter_clicked();   // add new Resident
    void on_btn_supprimer_clicked(); // delete Resident
};

#endif // MAINWINDOW_H
