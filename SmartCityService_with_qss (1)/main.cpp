#include <QApplication>
#include <QFile>
#include <QTextStream>
#include "servicewindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // You may load a global stylesheet here if desired.
    // QFile f(":style.qss");
    // if (f.open(QFile::ReadOnly | QFile::Text)) {
    //     QTextStream ts(&f);
    //     app.setStyleSheet(ts.readAll());
    // }

    ServiceWindow w;
    w.setWindowTitle("Gestion des Services - Smart City");
    w.resize(1000, 700);
    w.show();
    return app.exec();
}
