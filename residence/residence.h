#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "ui_residence.h"
#include <QMainWindow>
#include <QtGui>
#include <QStackedWidget>
QT_BEGIN_NAMESPACE
namespace Ui {
class residence_3;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::residence_3 *ui;
public slots :
    void page_3();
    void page_4();

};
#endif // RESIDENCE_H
