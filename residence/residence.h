#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "ui_residence.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
#include "crud.h"
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
public slots :
    void page_3();
    void page_4();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_delete_clicked();
};
#endif // RESIDENCE_H
