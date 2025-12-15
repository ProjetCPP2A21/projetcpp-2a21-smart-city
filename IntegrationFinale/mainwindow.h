/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include "CrudResidence.h"
#include "residence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timerPopup;
    QString getMessageForCurrentTime();

private slots:
    void on_connecter_clicked();
    void on_Modifier_Employe_clicked();


    void on_Ajouter_Employe_clicked();

    void on_Supprimer_Employe_clicked();
    void clearChamps();
    void remplirTable(QSqlQuery &query);
    void afficherEmployes();
    void on_tableWidgetEmployes_cellClicked(int row, int column);
    void on_recherche_clicked();
    void on_trie_clicked();


    void on_Rechercher_Employe_2_clicked();

    //residence
    void afficherTableResidence();


    void on_Ajouter_Residence_clicked();

    void on_Modifier_Residence_clicked();

    void on_Supprimer_Residence_clicked();

    void keyPressEvent(QKeyEvent *event);



private:
    Ui::MainWindow *ui;
    CRUD crud;
    void goToPage(QWidget *page);
};

#endif // MAINWINDOW_H*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include "CrudResidence.h"
#include "evenement.h"
#include <QWidget>
#include <QQuickWidget>
#include <QMap>
#include <QPointF>
#include <QQuickView>
#include <QGeoCodingManager>
#include <QGeoServiceProvider>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QProcess>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include "arduino.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QUrl>
#include <QVideoSink>  // <--- AJOUTER CECI
#include <QVideoFrame> // <--- AJOUTER CECI
#include <QLabel>      // <--- AJOUTER CECI


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //employer
    void onLoginClicked();
    //void on_pushButtonCreer_clicked();
    void on_pushButtonReset_clicked();

    // --- Slots du CRUD ---
    void on_Ajouter_Employe_Clicked();
    void on_Modifier_Employe_Clicked();
    void on_Supprimer_Employe_Clicked();
    void onRechercherClicked();
    void ontableWidgetEmployesClicked(int row, int column);

    // --- Slots de Navigation ---
    //void on_pushButtonGoToCreer_clicked();
    void on_pushButtonGoToMdp_clicked();
    void on_pushButtonRetourLogin_clicked();
    void on_pushButtonRetourLogin_2_clicked();
    void on_pushButtonRetourLogin_3_cliked();

    // ===============================================
    // AJOUT : NOUVEAUX SLOTS (Tri, Export, Stats)
    // ===============================================
    void onTrierClicked();
    void onExporterClicked();
    void onStatistiquesClicked();
    void on_pushButtonValiderReset_clicked();
    void on_pushButtonSuivant_clicked();
    void clearChamps();
    void on_pushButtonRetourLogin_3_clicked();
    void remplirTable(QSqlQuery &query);
    void afficherEmployes();
    void on_quitter_clicked();

    //residence
    void afficherTableResidence();



    void on_Supprimer_Residence_clicked();
    void on_recherche_clicked();
    void on_statistique_clicked();
    void keyPressEvent(QKeyEvent *event);
    void on_trie_clicked();
    void on_exporter_clicked();
    void handlePopupTimer();
    void  goToPage(QWidget *page);
    void afficherNotification(const QString &message);
    //residents
    void on_btn_ajouter_clicked();
    void on_btn_modifier_clicked();
    void on_btn_supprimer_clicked();
    void on_recherche_residents_textChanged(const QString &arg1);
    void on_btn_statistiques_clicked();
    void afficherStatistiques();
    void on_btnExportPDF_clicked();
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_tableView_clicked(const QModelIndex &index);
    void clearFields();
    QString calculerStabilite(int age, QString profession, QString situation);
    QString calculerMobilite(int age, QString profession, QString situation);
    int obtenirNiveauMetier(QString profession);

    // Services
    // Opérations CRUD
    void ajouterService();
    void modifierService();
    void supprimerService();
    void afficherServices();
    void rechercherService();
    // Sélection
    void selectionnerService(int row, int column);
    // Tri
    void trierServices(int index);
    // Statistiques
    void afficherStatistiques_Services();
    // Export PDF
    void on_btnExportPDF_Services_clicked();
    // IA - Optimisation Budget
    // IA suggère si budget est élevé ou faible
    void rechercheSmart();          // recherche intelligente: low priority dépassant budget

    //Evènements
    void onGpsProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void on_Ajouterbutton_clicked();

    void on_Modifier_2_clicked();
    void on_btn_StartMonitoring_clicked();


    //void on_Rechercher_clicked();
    // metiers
    void on_Prediction_clicked();
    void on_tableView_Evenement_clicked(const QModelIndex &index);
    void on_comboBox_currentIndexChanged(int index);
    void on_Recherche_Line_textChanged(const QString &text);
    void on_Excel_clicked();
    void on_Statistiques_Evenement_clicked();
    void on_Localiser_clicked();
    void on_btnItineraire_clicked();




    void on_Supprimer_2_clicked();



    void on_Ajouter_Residence_2_clicked();

    void on_Modifier_Residence_2_clicked();

        // Arduino
    void read_serial_data();           // Le "Chef de gare" (connecté au readyRead)
    void traiter_rfid(QString uid);    // Fonction 1 : Gère l'accès RFID
    void traiter_temperature(QString message); // Fonction 2 : Gère la ventilation
    void on_Aide_clicked();

private:
    Ui::MainWindow *ui;
    CRUD crud;
    QTimer *timerPopup;
    QString getMessageForCurrentTime();

    //services
    void viderChamps();
    void remplirTableau();
    void calculerBudgetPrevu();     // met à jour la colonne Budget prévu
    void calculerPrioriteAuto();    // met à jour la colonne Priorité automatique
    void verifierAnomalies();    // surligne les services dépassant le budget prévu
//employer
    void configurerAccesSelonRole(QString role); // Nouvelle fonction
    QString codeVerificationGenere; // Le code envoyé par mail
    QString idUtilisateurEnCours;
    QWidget* page_employer;
    QString hashPassword(const QString &password);
    // Evènements
    Evenement E;
    QMap<QString, QPointF> lieuCoords;
    QQuickView *mapView;
    QGeoCodingManager *geoCoder;
    QObject *rootMapObject;
    QLabel *labelScore;
    QProcess *gpsProcess;
    double myLatitude;
    double myLongitude;
    Arduino A; // L'objet Arduino
    QByteArray data;
    int id_residence_surveillance; // L'ID saisi par l'utilisateur
    bool monitoring_actif;

    QMediaPlayer *player;
    QLabel *videoLabel;       // Le nouveau conteneur
    QVideoSink *videoSink;    // L'objet qui capture les images
    QAudioOutput *audioOutput;

};

#endif // MAINWINDOW_H
