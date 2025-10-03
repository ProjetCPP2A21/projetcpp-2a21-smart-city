#include "gemployer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GEmployer w;
    w.show();
    return a.exec();
}
