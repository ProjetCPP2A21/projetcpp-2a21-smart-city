#ifndef EVENTS_H
#define EVENTS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class events;
}
QT_END_NAMESPACE

class events : public QWidget
{
    Q_OBJECT

public:
    events(QWidget *parent = nullptr);
    ~events();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::events *ui;
};
#endif // EVENTS_H
