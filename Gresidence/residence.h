#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class residence;
}
QT_END_NAMESPACE

class residence : public QWidget
{
    Q_OBJECT

public:
    explicit residence(QWidget *parent = nullptr);
    ~residence();

private slots:
    void openOtherWindow();     // function that opens the 2nd window

private:
    Ui::residence *ui;
};

#endif // RESIDENCE_H


