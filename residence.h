#ifndef RESIDENCE_H
#define RESIDENCE_H

#include "ui_residence.h"
#include "connection.h"
#include "crud.h"
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    float derniereTemperature;   // Stocke la dernière température reçue
    int dernierIDResidence;      // Dernier ID de résidence ajouté

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CRUD crud;
    QSerialPort *serial;
    QTimer *timerPopup;

    // Fonctions utilitaires
    int getDerniereResidenceID();              // Récupérer le dernier ID de résidence
    void afficherTable();                      // Afficher toutes les résidences dans le tableau
    void ajouterTable();                       // Ajouter une résidence depuis les champs
    QString getMessageForCurrentTime();        // Message pop-up selon l'heure

public slots:
    void page_3();                              // Naviguer vers page 3
    void page_4();                              // Naviguer vers page 4

private slots:
    // Slots CRUD
    void on_pushButton_add_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_delete_clicked();
    void on_recherche_clicked();

    // Slots tri / statistiques / export
    void on_trie_clicked();
    void on_statistique_clicked();
    void on_exporter_clicked();

    // Slots Arduino
    void onSerialDataReceived();
    void on_btnTemp_clicked();
    // ← Déclaration manquante pour le timer et bouton
    void lireTemperatureArduino();
protected:
    void keyPressEvent(QKeyEvent *event) override;   // Gestion des touches (ex: 'P')
};

#endif // RESIDENCE_H
