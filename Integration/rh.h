#ifndef RH_H
#define RH_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class RH;
}
QT_END_NAMESPACE

class RH : public QWidget
{
    Q_OBJECT

public:
    RH(QWidget *parent = nullptr);
    ~RH();

private slots:
    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::RH *ui;
};
#endif // RH_H
