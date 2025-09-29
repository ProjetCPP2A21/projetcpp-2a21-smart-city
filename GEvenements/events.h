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

private:
    Ui::events *ui;
};
#endif // EVENTS_H
