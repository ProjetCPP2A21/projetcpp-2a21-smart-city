#include "rh.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RH w;
    w.show();
    return a.exec();
}
