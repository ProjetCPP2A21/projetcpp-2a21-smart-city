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
    void afficherTable();
public slots :

private slots:
};
#endif // RESIDENCE_H
