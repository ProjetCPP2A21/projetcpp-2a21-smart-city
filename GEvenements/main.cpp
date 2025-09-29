#include "events.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    events w;
    w.show();
    return a.exec();
}
