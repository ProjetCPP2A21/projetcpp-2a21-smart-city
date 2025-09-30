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
    residence(QWidget *parent = nullptr);
    ~residence();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::residence *ui;
};
#endif // RESIDENCE_H
