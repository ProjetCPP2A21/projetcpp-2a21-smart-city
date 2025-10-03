#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class residence;
}
QT_END_NAMESPACE

class residence : public QWidget
{
    Q_OBJECT

public:
    residence(QWidget *parent = nullptr);
    ~residence();

private:
    Ui::residence *ui;
};
#endif // RESIDENCE_H*/



