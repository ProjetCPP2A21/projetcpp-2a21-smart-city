#include "events.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Events w;
    w.show();
    return a.exec();
}
