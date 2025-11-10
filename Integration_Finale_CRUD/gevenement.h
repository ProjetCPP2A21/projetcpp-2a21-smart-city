#ifndef GEVENEMENT_H
#define GEVENEMENT_H
#include "connection.h"
#include "evenement.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GEvenement;
}
QT_END_NAMESPACE

class GEvenement : public QMainWindow
{
    Q_OBJECT

public:

private slots:


private:
    Ui::GEvenement *ui;
    Evenement E;
};
#endif // GEVENEMENT_H
