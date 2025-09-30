#ifndef SERVICE_H
#define SERVICE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class service;
}
QT_END_NAMESPACE

class service : public QWidget
{
    Q_OBJECT

public:
    service(QWidget *parent = nullptr);
    ~service();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_label_linkActivated(const QString &link);

private:
    Ui::service *ui;
};
#endif // SERVICE_H
