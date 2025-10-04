#include "residence.h"
#include "ui_residence.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::residence_3)
{
    ui->setupUi(this);
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
      QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
}
void MainWindow :: page_3()
{
    QObject :: connect(ui->RH, SIGNAL(clicked()),this ,SLOT(page_4()));
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}
void MainWindow :: page_4()
{
    QObject :: connect(ui->residence_2, SIGNAL(clicked()),this ,SLOT(page_3()));
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}
MainWindow::~MainWindow()
{
    delete ui;
}
