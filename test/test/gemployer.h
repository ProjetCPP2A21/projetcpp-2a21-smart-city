#ifndef GEMPLOYER_H
#define GEMPLOYER_H
#include <QSqlQuery>
#include <QWidget>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class GEmployer;
}
QT_END_NAMESPACE

class GEmployer : public QMainWindow
{
    Q_OBJECT

public:


private slots:
private:
    Ui::GEmployer *ui;
};

#endif // GEMPLOYER_H
