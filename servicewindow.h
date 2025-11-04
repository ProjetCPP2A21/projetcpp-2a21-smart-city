#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H

#include <QWidget>
#include "widget.h"
#include <QMessageBox>

namespace Ui {
class ServiceWindow;
}

class ServiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ServiceWindow(QWidget *parent = nullptr);
    ~ServiceWindow();

private slots:
    void on_ajouterButton_clicked();
    void on_supprimerButton_clicked();
    void on_modifierButton_clicked();
    void on_afficherButton_clicked();


private:
    Ui::ServiceWindow *ui;
    Service Stmp;
};

#endif // SERVICEWINDOW_H
