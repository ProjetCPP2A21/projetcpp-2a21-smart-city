#ifndef GEMPLOYER_H
#define GEMPLOYER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class GEmployer;
}
QT_END_NAMESPACE

class GEmployer : public QWidget
{
    Q_OBJECT

public:
    explicit GEmployer(QWidget *parent = nullptr);
    ~GEmployer();

private:
    Ui::GEmployer *ui;
};
#endif // GEMPLOYER_H
