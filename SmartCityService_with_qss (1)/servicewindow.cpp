#include "servicewindow.h"
#include "ui_servicewindow.h"
#include <QFile>
#include <QTextStream>
#include <QHeaderView>
#include <QAbstractItemView>

ServiceWindow::ServiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceWindow)
{
    ui->setupUi(this);

    // Try to load the style.qss from the same folder as the executable.
    QFile f(":/style.qss"); // fallback resource path (not used unless added to resource)
    if (!f.exists()) {
        // Try load from working directory
        f.setFileName("style.qss");
    }
    if (f.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream ts(&f);
        QString qss = ts.readAll();
        // Apply stylesheet scoped to the ServiceWindow by setting objectName and applying to this widget only
        this->setObjectName("ServiceWindow");
        this->setStyleSheet(qss);
        f.close();
    } else {
        // Ensure objectName set even if qss not found
        this->setObjectName("ServiceWindow");
    }

    // Adjust table appearance
    ui->tableServices->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableServices->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableServices->horizontalHeader()->setStretchLastSection(true);
    ui->tableServices->verticalHeader()->setVisible(false);
}

ServiceWindow::~ServiceWindow()
{
    delete ui;
}
