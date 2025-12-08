#ifndef RESIDENCE_H
#define RESIDENCE_H

#include "ui_residence.h"
#include "connection.h"
#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include <QKeyEvent>
#include "crud.h"
#include "arduino.h"

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

private:
    Ui::MainWindow *ui;
    CRUD crud;
    Arduino A;
    QTimer *timerPopup;
    bool ventilateurON = false;

    void ajouterTable();
    void afficherTable();
    void setupTableHeaders();
    QString getMessageForCurrentTime();

public slots:
    void page_3();
    void page_4();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_delete_clicked();
    void on_recherche_clicked();
    void on_statistique_clicked();
    void on_trie_clicked();
    void on_exporter_clicked();

    void checkTemperature();
    int getTemperatureFromDB();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // RESIDENCE_H
