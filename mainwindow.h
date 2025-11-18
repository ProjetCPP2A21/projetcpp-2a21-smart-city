#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "residents.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void page();
    void page_3();
    void page_4();
    void on_btn_ajouter_clicked();
    void on_btn_supprimer_clicked();
    void on_btn_modifier_clicked();
    void on_btn_statistiques_clicked();
    void afficherStatistiques();
    void on_btnExportPDF_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void clearFields();

};

#endif // MAINWINDOW_H
