#include "gevenement.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GEvenement w;
    w.show();
    return a.exec();
}
