#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "residents.h"
#include "service.h"
#include "widget_Service.h"
#include "connection.h"
#include <QTimer>
#include <QTime>
#include <QRandomGenerator>
#include <cstdlib>
#include <QMessageBox>
#include <QMovie>
#include "gevenement.h"
#include "evenement.h"
#include "statistique.h"
#include <QString>
#include <QTableView>
#include <QSqlDatabase>
#include <onnxruntime_cxx_api.h>
#include "Excel/QXlsx/QXlsx/header/xlsxdocument.h"
#include "Excel/QXlsx/QXlsx/header/xlsxformat.h"
#include "Excel/QXlsx/QXlsx/header/xlsxcellrange.h"
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
#include <QVariantList>
#include <QtQuick/QQuickItem>
#include <QGeoCodingManager>
#include <QGeoCodeReply>
#include <QGeoServiceProvider>
#include <QGeoCoordinate>
#include <QGeoLocation>
#include <QGeoAddress>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStyledItemDelegate>
#include "datedelegate.h"
#include <QVBoxLayout>
#include <QGeoPositionInfoSource>
#include <QDebug>
#include <QAction>
#include <QIcon>

using namespace QXlsx;
const QString SELECT_QUERY = "SELECT id_employe, nom, prenom, num_tel, salaire, sexe, responsabilite FROM EMPLOYER";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1. Définir le mode mot de passe par défaut (si ce n'est pas fait dans le Designer)
    ui->lineEditLoginPassword->setEchoMode(QLineEdit::Password);

    // 2. Créer l'action (le bouton œil)
    QAction *togglePasswordAction = new QAction(this);

    // Mettez ici le chemin vers votre icône dans les ressources (ex: ":/icons/eye_open.png")
    // Si vous n'avez pas d'icône, vous pouvez mettre du texte : togglePasswordAction->setText("Voir");
    togglePasswordAction->setIcon(QIcon("C:/Users/ASUS/Desktop/Smart City/IntegrationFinale/eye_open.jpg"));

    // 3. Ajouter l'action DANS le champ de texte (à droite)
    ui->lineEditLoginPassword->addAction(togglePasswordAction, QLineEdit::TrailingPosition);

    // 4. Connecter le clic sur l'icône à la logique
    connect(togglePasswordAction, &QAction::triggered, this, [=]() {
        if (ui->lineEditLoginPassword->echoMode() == QLineEdit::Password) {
            // Si c'est caché, on montre le texte
            ui->lineEditLoginPassword->setEchoMode(QLineEdit::Normal);
            // On change l'icône pour "œil barré"
            togglePasswordAction->setIcon(QIcon("C:/Users/ASUS/Desktop/Smart City/IntegrationFinale/eye_closed.jpg"));
        } else {
            // Si c'est visible, on cache le texte
            ui->lineEditLoginPassword->setEchoMode(QLineEdit::Password);
            // On remet l'icône "œil ouvert"
            togglePasswordAction->setIcon(QIcon("C:/Users/ASUS/Desktop/Smart City/IntegrationFinale/eye_open.jpg"));
        }
    });
    QMovie *movie = new QMovie("C:/Users/ASUS/Downloads/upscaled-video.mp4");

    // 2. Vérifiez si le GIF s'est bien chargé (optionnel mais recommandé)
    if (!movie->isValid()) {
        qDebug() << "Erreur : Impossible de charger le GIF d'arrière-plan.";
    } else {
        // 3. Attachez le GIF au label
        ui->BackgroundGif->setMovie(movie);

        // 4. Lancez l'animation
        movie->start();
    }
    connect(ui->btn_logout_2, &QPushButton::clicked, this, [this]() {
        // 1. Revenir à la page de connexion
        ui->stackedWidget->setCurrentWidget(ui->Connection);

        // 2. Vider les champs pour la sécurité (optionnel mais recommandé)
        ui->lineEditLoginUsername->clear();
        ui->lineEditLoginPassword->clear();

        // 3. Masquer le menu latéral (si ce n'est pas déjà géré automatiquement)


        QMessageBox::information(this, "Déconnexion", "Vous avez été déconnecté avec succès.");
    });
    // Connecter la gestion automatique de visibilité de la sidebar
    connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, [this](int idx){
        QWidget *w = ui->stackedWidget->widget(idx);
        qDebug() << "stackedWidget changed to index" << idx << "widgetName =" << w->objectName();
        if (w == ui->Connection || w == ui->page_7 || w == ui->page_13) {
            ui->leftmenu->hide();
        } else {
            ui->leftmenu->show();
        }
    });
    qDebug() << "================ DIAGNOSTIC EMAIL ================";
    qDebug() << "Support SSL disponible :" << QSslSocket::supportsSsl();
    qDebug() << "Version SSL Compilée   :" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "Version SSL Chargée    :" << QSslSocket::sslLibraryVersionString();
    qDebug() << "Chemin des DLL attendu :" << QCoreApplication::applicationDirPath();
    qDebug() << "==================================================";
    // ... (Connexion BDD)
    if (!Connection::instance().createConnection()) {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données !");
    } else {
        qDebug() << "✅ Connexion réussie à la base de données.";
    }

    // ... (TABLE SETUP)
    ui->tableWidgetEmployes->setColumnCount(7);
    QStringList headers = {"ID", "nom", "prenom", "telephone", "salaire", "Sexe", "Tâche"};
    ui->tableWidgetEmployes->setHorizontalHeaderLabels(headers);
    ui->tableWidgetEmployes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEmployes->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // ==================== LOGIN PAGE (DÉMARRAGE) ====================
    ui->stackedWidget->setCurrentWidget(ui->page_2); // Démarrer sur la page login
    ui->Ajouter_Employe->setEnabled(false);
    ui->Modifier_Employe->setEnabled(false);
    ui->Supprimer_Employe->setEnabled(false);
    ui->Rechercher_Employe->setEnabled(false);

    // --- CONNEXIONS (SIGNALS & SLOTS) ---

    // Login
    connect(ui->connecter, &QPushButton::clicked, this, &MainWindow::onLoginClicked);

    // CRUD
    connect(ui->Ajouter_Employe, &QPushButton::clicked, this, &MainWindow::on_Ajouter_Employe_Clicked);
    connect(ui->Modifier_Employe, &QPushButton::clicked, this, &MainWindow::on_Modifier_Employe_Clicked);
    connect(ui->Supprimer_Employe, &QPushButton::clicked, this, &MainWindow::on_Supprimer_Employe_Clicked);
    connect(ui->Rechercher, &QPushButton::clicked, this, &MainWindow::onRechercherClicked);
    connect(ui->tableWidgetEmployes, &QTableWidget::cellClicked, this, &MainWindow::ontableWidgetEmployesClicked);

    // ===============================================
    // AJOUT : CONNEXIONS POUR LES NOUVELLES FONCTIONS
    // ===============================================
    // Assurez-vous que ces noms (ex: "pushButtonTrier")
    // correspondent à ceux que vous avez mis dans le Qt Designer (.ui)

    connect(ui->Trier_2, &QPushButton::clicked, this, &MainWindow::onTrierClicked);
    connect(ui->Exporter_2, &QPushButton::clicked, this, &MainWindow::onExporterClicked);
    connect(ui->Statistiques_Employe, &QPushButton::clicked, this, &MainWindow::onStatistiquesClicked);


    // --- NOUVELLES CONNEXIONS (automatiques) ---
    // (Qt s'occupe de celles-ci grâce à leurs noms)
    /*MainWindow* gEmp = new MainWindow(ui->page_employer, this);*/
    afficherTableResidence();

    timerPopup = new QTimer(this);
    connect(timerPopup, &QTimer::timeout, this, &MainWindow::handlePopupTimer);
    timerPopup->start(30000);

    // Charger table Residents
    Resident Rtmp;
    ui->tableView->setModel(Rtmp.afficher());
    // ComboBox de tri
    ui->comboBox_tri->addItem("Nom");
    ui->comboBox_tri->addItem("Age");
    ui->comboBox_tri->addItem("Sexe");

    // charger table Services
    afficherServices();
    connect(ui->ajouterButton, &QPushButton::clicked,
            this, &MainWindow::ajouterService);
    connect(ui->modifierButton, &QPushButton::clicked,
            this, &MainWindow::modifierService);
    connect(ui->supprimerButton, &QPushButton::clicked,
            this, &MainWindow::supprimerService);
    connect(ui->Rechercher_Services, &QPushButton::clicked,
            this, &MainWindow::rechercherService);
    connect(ui->btnStats, &QPushButton::clicked,
            this, &MainWindow::afficherStatistiques_Services);

    connect(ui->combo_sort, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::trierServices);
    connect(ui->tableServices, &QTableWidget::cellClicked,
            this, &MainWindow::selectionnerService);


    gpsProcess = new QProcess(this);
    connect(gpsProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &MainWindow::onGpsProcessFinished);

    // La commande PowerShell pour interroger le vrai GPS Windows
    // Elle charge la DLL système, crée un watcher, attend 3 secondes la stabilisation et affiche Lat,Lon
    QString script = "Add-Type -AssemblyName System.Device; "
                     "$watcher = New-Object System.Device.Location.GeoCoordinateWatcher; "
                     "$watcher.Start(); "
                     "$count = 0; "
                     "while (($watcher.Status -ne 'Ready') -and ($count -lt 5)) { Start-Sleep -Milliseconds 500; $count++ }; "
                     "$coord = $watcher.Position.Location; "
                     "if ($coord.IsUnknown -ne $true) { Write-Output \"$($coord.Latitude),$($coord.Longitude)\" } "
                     "else { Write-Output \"Unknown\" }";

    QStringList arguments;
    arguments << "-NoProfile" << "-Command" << script;

    qDebug() << "Lancement de la recherche GPS précise via Windows...";
    gpsProcess->start("powershell", arguments);
    // 2. Essayer de créer la source par défaut
    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    if (source) {
        qDebug() << "Succès : Une source par défaut a été créée (" << source->sourceName() << ")";

        // Connecter les erreurs pour voir pourquoi ça échoue plus tard
        connect(source, &QGeoPositionInfoSource::errorOccurred, this, [](QGeoPositionInfoSource::Error error){
            qDebug() << "ERREUR SIGNALÉE PAR LE GPS :" << error;
            if (error == QGeoPositionInfoSource::AccessError)
                qDebug() << " -> Accès refusé par l'OS (Paramètres de confidentialité Windows ?)";
            if (error == QGeoPositionInfoSource::ClosedError)
                qDebug() << " -> Le système de localisation est fermé ou indisponible.";
        });

        source->startUpdates(); // On tente de démarrer pour voir si ça crashe ou si ça erreur
    } else {
        qDebug() << "ERREUR : Impossible de créer la source par défaut, même si des plugins existent.";
    }
    qDebug() << "--- FIN DU TEST ---";
    // --- DIAGNOSTIC GPS FIN ---
    // --- CORRECTION : PAS DE LAYOUT ---
    // On crée juste le label pour le dessin, sans toucher au reste du design.
    labelScore = new QLabel(ui->frame_Prediction);
    labelScore->setAlignment(Qt::AlignCenter);
    labelScore->setVisible(false); // Caché au début
    // ----------------------------------

    ui->ID->setValidator(new QIntValidator(1, 999999, this));
    ui->NbrP->setValidator(new QIntValidator(1, 100000, this));
    ui->tableView_Evenement->setModel(E.afficher());
    ui->ID->setValidator(new QIntValidator(1, 999999, this));
    ui->NbrP->setValidator(new QIntValidator(1, 100000, this));
    ui->tableView_Evenement->setModel(E.afficher());
    ui->tableView_Evenement->setItemDelegateForColumn(4, new DateDelegate(ui->tableView_Evenement));
    QObject *rootObject = ui->MapWidget->rootObject();
    QGeoServiceProvider provider("osm"); // Ou "here", "googlemaps", selon le plugin installé
    geoCoder = provider.geocodingManager();
    if (!geoCoder) {
        QMessageBox::critical(this, "Erreur", "Le géocodeur n'a pas été initialisé !");
        return;
    }
    ui->MapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->MapWidget->setFocusPolicy(Qt::StrongFocus);
    ui->MapWidget->setSource(QUrl("qrc:/Map.qml"));
    ui->MapWidget->setFocus();  // important pour que la souris et le clavier interagissent



    // 🟢 Show the login page first
    ui->stackedWidget->setCurrentWidget(ui->Connection);

    // 🟥 "Quitter" button → Close the window
    connect(ui->quitter, &QPushButton::clicked, this, &QMainWindow::close);

    // 🔵 "Mot de passe oublié" → Go to page_7
    connect(ui->pushButtonGoToMdp, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->page_7);
    });
    connect(ui->pushButtonRetourLogin_2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->Connection);
    });



    //
    // --- DASHBOARD (page_4) ---
    //
    connect(ui->RH_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->resident_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->residence, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); });
    connect(ui->Evenements_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
    connect(ui->service_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- RÉSIDENT PAGE (page) ---
    //
    connect(ui->RH_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->residence, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); });
    connect(ui->Evenements_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
    connect(ui->service_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- RÉSIDENCE PAGE (page_3) ---
    //
    connect(ui->RH_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->resident_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->Evenements_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
    connect(ui->service_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- ÉVÈNEMENTS PAGE (page_2) ---
    //
    connect(ui->RH_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->residence, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); });
    connect(ui->resident_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->service_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_6); });

    //
    // --- SERVICE PAGE (page_6) ---
    //
    connect(ui->RH_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_4); });
    connect(ui->residence, &QPushButton::clicked, this, [this]() { goToPage(ui->page_3); }); // ✅ FIXED
    connect(ui->resident_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page); });
    connect(ui->Evenements_Page, &QPushButton::clicked, this, [this]() { goToPage(ui->page_2); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
// === UNIVERSAL PAGE SWITCH FUNCTION ===
//
void MainWindow::goToPage(QWidget *page)
{
    if (!page || ui->stackedWidget->indexOf(page) == -1) return;

    ui->stackedWidget->setCurrentWidget(page);

    // Masquer la barre gauche pour la page de connexion et mot de passe oublié
    if (page == ui->Connection || page == ui->page_7) {
        ui->leftmenu->setVisible(false);
    } else {
        ui->leftmenu->setVisible(true);
    }
}
































