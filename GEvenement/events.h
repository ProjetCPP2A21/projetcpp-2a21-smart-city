#ifndef EVENTS_H
#define EVENTS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Events;
}
QT_END_NAMESPACE

class Events : public QMainWindow
{
    Q_OBJECT

public:
    Events(QWidget *parent = nullptr);
    ~Events();

private slots:

    void on_pushButton_6_clicked();

private:
    Ui::Events *ui;
};
#endif // EVENTS_H
