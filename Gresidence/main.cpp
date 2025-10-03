#include "residence.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    residence w;
    w.show();
    return a.exec();
}
