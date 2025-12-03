/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "statistique.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QPushButton *trie;
    QPushButton *exporter;
    QPushButton *statistique;
    QTableWidget *affichage;
    QPushButton *recherche;
    QLineEdit *search;
    QLabel *label_38;
    QFrame *Ajouter;
    QLabel *label_12;
    QLabel *label_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *Id_Residence_2;
    QLineEdit *Nom_Residence_2;
    QLineEdit *Adresse_Residence_2;
    QLineEdit *Type_Residence_2;
    QLineEdit *Nbr_Habitants_2;
    QLineEdit *Nbr_Unites_2;
    QLineEdit *Etat_2;
    QLineEdit *Date_Creation_2;
    QPushButton *Ajouter_Residence_2;
    QPushButton *Modifier_Residence_2;
    QPushButton *Supprimer_Residence;
    QWidget *chart;
    QWidget *page_4;
    QPushButton *Exporter_2;
    QPushButton *Trier_2;
    QLineEdit *Rechercher_Employe;
    QFrame *frame;
    QLabel *label_20;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label_21;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QFrame *frame_3;
    QLabel *label_22;
    QPushButton *pushButton_2;
    QPushButton *residence_2;
    QPushButton *resident_3;
    QPushButton *Evenements_4;
    QPushButton *service_3;
    QLabel *label_5;
    QFrame *Ajouter_2;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *Prenom_Employe;
    QLineEdit *ID_Employe;
    QLineEdit *Telephone_Employe;
    QLineEdit *Salaire;
    QLabel *label_25;
    QLineEdit *Sexe_Employe;
    QLineEdit *Nom_Employe;
    QLabel *label_11;
    QPushButton *Ajouter_Employe;
    QLabel *label_26;
    QLineEdit *Responsabilite;
    QPushButton *Modifier_Employe;
    QPushButton *Supprimer_Employe;
    QLabel *label_27;
    QPushButton *Rechercher;
    QPushButton *Statistiques_Employe;
    QTableWidget *tableWidgetEmployes;
    QLabel *label_39;
    QWidget *widgetStats;
    QWidget *page_6;
    QFrame *frame_9;
    QLabel *label_64;
    QPushButton *RH_6;
    QPushButton *residence_7;
    QPushButton *resident_8;
    QPushButton *Evenements_8;
    QPushButton *pushButton_29;
    QLabel *label_65;
    QFrame *frame_10;
    QLabel *label_priority;
    QLabel *label_date;
    QPushButton *ajouterButton;
    QLabel *label_resp;
    QLineEdit *lineEdit_responsable;
    QDateEdit *dateEdit_date;
    QComboBox *combo_priority;
    QComboBox *combo_type;
    QComboBox *combo_state;
    QLabel *label_type;
    QLabel *label_budget;
    QPushButton *supprimerButton;
    QDoubleSpinBox *spin_budget;
    QLabel *label_state;
    QLabel *label_id;
    QLineEdit *lineEdit_Nom;
    QPushButton *modifierButton;
    QLabel *label_name;
    QLineEdit *lineEdit_id;
    QLineEdit *Rechercher_Service;
    QPushButton *Rechercher_Services;
    QLabel *label_sort;
    QComboBox *combo_sort;
    QPushButton *btnIA;
    QTableWidget *tableServices;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_Service;
    QPushButton *btnStats;
    QPushButton *btnExportPDF_Services;
    QWidget *page_2;
    QFrame *BarreGestions;
    QLabel *label_60;
    QPushButton *RH_3;
    QPushButton *service_4;
    QPushButton *Evenements;
    QPushButton *resident_4;
    QLabel *label_61;
    QPushButton *residence_5;
    QFrame *Ajouter_4;
    QLabel *label_28;
    QLabel *label_4;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *Nom;
    QLineEdit *Type;
    QLineEdit *Lieu;
    QLabel *label_33;
    QLineEdit *ID;
    QLabel *label_34;
    QPushButton *Ajouterbutton;
    QLineEdit *NbrP;
    QLabel *label_35;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QLabel *label_44;
    QLineEdit *ID_Employe_Evenement;
    QPushButton *Modifier_2;
    QPushButton *Supprimer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_6;
    QLineEdit *Recherche_Line;
    QLabel *label_36;
    QComboBox *comboBox;
    QPushButton *Excel;
    QTableView *tableView_Evenement;
    QWidget *Fonctionnalites;
    QFrame *frame_Prediction;
    QLabel *label_37;
    QLineEdit *Id_Evenement;
    QLabel *label_40;
    QPushButton *Prediction;
    QLabel *Dioxyde;
    QFrame *frame_7;
    QLabel *label_41;
    QLineEdit *ID_localisation;
    QLabel *label_42;
    QPushButton *Localiser;
    QQuickWidget *MapWidget;
    QPushButton *btnItineraire;
    QLabel *label_43;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QPushButton *Statistiques_Evenement;
    Statistique *StatisqueWidget;
    QWidget *page_13;
    QLineEdit *lineEditCodeRecu;
    QLineEdit *lineEditNouveauPass;
    QLabel *label_131;
    QTextBrowser *textBrowser_18;
    QPushButton *pushButtonValiderReset;
    QLabel *label_132;
    QTextBrowser *textBrowser_17;
    QPushButton *pushButtonRetourLogin_3;
    QTextBrowser *textBrowser_20;
    QWidget *page_14;
    QWidget *page_7;
    QLineEdit *lineEditMdpId;
    QTextBrowser *textBrowser_15;
    QLineEdit *lineEditMdpEmail;
    QLabel *label_66;
    QPushButton *pushButtonSuivant;
    QPushButton *pushButtonRetourLogin_2;
    QLabel *label_67;
    QLineEdit *lineEditMdpUsername;
    QTextBrowser *textBrowser_14;
    QTextBrowser *textBrowser_16;
    QTextBrowser *textBrowser_19;
    QWidget *Connection;
    QLabel *label_128;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *label_129;
    QTextBrowser *textBrowser_3;
    QLabel *label_130;
    QPushButton *quitter;
    QLineEdit *lineEditLoginUsername;
    QLineEdit *lineEditLoginPassword;
    QPushButton *connecter;
    QPushButton *pushButtonGoToMdp;
    QLabel *label;
    QWidget *page;
    QFrame *frame_5;
    QLabel *label_32;
    QPushButton *RH_2;
    QPushButton *residence_3;
    QPushButton *resident;
    QPushButton *Evenements_2;
    QPushButton *service;
    QLabel *label_53;
    QPushButton *pushButton_149;
    QLabel *label_293;
    QFrame *Ajouter_3;
    QLabel *label_45;
    QLabel *label_49;
    QLineEdit *lineEdit_situation;
    QLineEdit *lineEdit_age;
    QLineEdit *lineEdit_profession;
    QLineEdit *lineEdit_nom;
    QLabel *label_48;
    QLabel *label_46;
    QLineEdit *lineEdit_prenom;
    QLabel *label_47;
    QLineEdit *lineEdit_sexe;
    QLineEdit *lineEdit_idresident;
    QLabel *label_50;
    QLabel *label_68;
    QLabel *label_51;
    QPushButton *btn_supprimer;
    QPushButton *btn_modifier;
    QPushButton *btn_ajouter;
    QFrame *frame_4;
    QLabel *label_52;
    QLineEdit *recherche_residents;
    QTableView *tableView;
    QLabel *label_63;
    QComboBox *comboBox_tri;
    QLabel *labelMobilite;
    QLabel *label_stabilite;
    QPushButton *btnExportPDF;
    QPushButton *btn_statistiques;
    QWidget *widget_stats;
    QFrame *leftmenu;
    QLabel *label_23;
    QPushButton *RH;
    QPushButton *residence;
    QPushButton *resident_2;
    QPushButton *Evenements_3;
    QPushButton *service_2;
    QLabel *label_24;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1367, 768);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-4, -30, 1381, 768));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        trie = new QPushButton(page_3);
        trie->setObjectName("trie");
        trie->setGeometry(QRect(990, 60, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        font.setBold(true);
        trie->setFont(font);
        trie->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        exporter = new QPushButton(page_3);
        exporter->setObjectName("exporter");
        exporter->setGeometry(QRect(1050, 420, 91, 31));
        exporter->setFont(font);
        exporter->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        statistique = new QPushButton(page_3);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(1050, 480, 91, 31));
        statistique->setFont(font);
        statistique->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        affichage = new QTableWidget(page_3);
        if (affichage->columnCount() < 8)
            affichage->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(0, 0, 0));
        affichage->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        affichage->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        affichage->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        affichage->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        affichage->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        affichage->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        affichage->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        affichage->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        affichage->setObjectName("affichage");
        affichage->setGeometry(QRect(600, 170, 711, 241));
        affichage->setStyleSheet(QString::fromUtf8("border-raduis : 20px;\n"
"background-color : #e1e5ff;\n"
""));
        recherche = new QPushButton(page_3);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(890, 60, 91, 31));
        recherche->setFont(font);
        recherche->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        search = new QLineEdit(page_3);
        search->setObjectName("search");
        search->setGeometry(QRect(590, 50, 291, 41));
        search->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_38 = new QLabel(page_3);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(560, -21, 791, 791));
        label_38->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Ajouter = new QFrame(page_3);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(190, 20, 371, 761));
        Ajouter->setStyleSheet(QString::fromUtf8("#Ajouter {\n"
"border: 2px solid black;\n"
"	\n"
"	border-color: rgb(219, 220, 255);\n"
"}\n"
"\n"
"QFrame {\n"
"background-color : #ffffff;\n"
" border-radius: 20px\n"
"}"));
        Ajouter->setFrameShape(QFrame::Shape::StyledPanel);
        Ajouter->setFrameShadow(QFrame::Shadow::Raised);
        label_12 = new QLabel(Ajouter);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 20, 271, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Ajouter);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 120, 81, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setPointSize(12);
        font2.setBold(true);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(Ajouter);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 220, 49, 21));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_14 = new QLabel(Ajouter);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 170, 91, 21));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(Ajouter);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 270, 141, 21));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(Ajouter);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 330, 121, 16));
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_17 = new QLabel(Ajouter);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 80, 81, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Rockwell")});
        font3.setPointSize(11);
        font3.setBold(true);
        label_17->setFont(font3);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_18 = new QLabel(Ajouter);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 390, 131, 16));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_19 = new QLabel(Ajouter);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 450, 51, 16));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Id_Residence_2 = new QLineEdit(Ajouter);
        Id_Residence_2->setObjectName("Id_Residence_2");
        Id_Residence_2->setGeometry(QRect(170, 70, 141, 41));
        Id_Residence_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Nom_Residence_2 = new QLineEdit(Ajouter);
        Nom_Residence_2->setObjectName("Nom_Residence_2");
        Nom_Residence_2->setGeometry(QRect(170, 120, 141, 41));
        Nom_Residence_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Adresse_Residence_2 = new QLineEdit(Ajouter);
        Adresse_Residence_2->setObjectName("Adresse_Residence_2");
        Adresse_Residence_2->setGeometry(QRect(170, 170, 141, 41));
        Adresse_Residence_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Type_Residence_2 = new QLineEdit(Ajouter);
        Type_Residence_2->setObjectName("Type_Residence_2");
        Type_Residence_2->setGeometry(QRect(170, 220, 141, 41));
        Type_Residence_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Nbr_Habitants_2 = new QLineEdit(Ajouter);
        Nbr_Habitants_2->setObjectName("Nbr_Habitants_2");
        Nbr_Habitants_2->setGeometry(QRect(170, 270, 141, 41));
        Nbr_Habitants_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Nbr_Unites_2 = new QLineEdit(Ajouter);
        Nbr_Unites_2->setObjectName("Nbr_Unites_2");
        Nbr_Unites_2->setGeometry(QRect(170, 320, 141, 41));
        Nbr_Unites_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Etat_2 = new QLineEdit(Ajouter);
        Etat_2->setObjectName("Etat_2");
        Etat_2->setGeometry(QRect(170, 370, 141, 41));
        Etat_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Date_Creation_2 = new QLineEdit(Ajouter);
        Date_Creation_2->setObjectName("Date_Creation_2");
        Date_Creation_2->setGeometry(QRect(170, 420, 141, 41));
        Date_Creation_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Ajouter_Residence_2 = new QPushButton(Ajouter);
        Ajouter_Residence_2->setObjectName("Ajouter_Residence_2");
        Ajouter_Residence_2->setGeometry(QRect(130, 530, 111, 41));
        Ajouter_Residence_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Modifier_Residence_2 = new QPushButton(Ajouter);
        Modifier_Residence_2->setObjectName("Modifier_Residence_2");
        Modifier_Residence_2->setGeometry(QRect(10, 530, 111, 41));
        Modifier_Residence_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Supprimer_Residence = new QPushButton(Ajouter);
        Supprimer_Residence->setObjectName("Supprimer_Residence");
        Supprimer_Residence->setGeometry(QRect(250, 530, 101, 41));
        Supprimer_Residence->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        chart = new QWidget(page_3);
        chart->setObjectName("chart");
        chart->setGeometry(QRect(620, 440, 371, 291));
        stackedWidget->addWidget(page_3);
        label_38->raise();
        trie->raise();
        exporter->raise();
        statistique->raise();
        affichage->raise();
        recherche->raise();
        search->raise();
        Ajouter->raise();
        chart->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        Exporter_2 = new QPushButton(page_4);
        Exporter_2->setObjectName("Exporter_2");
        Exporter_2->setGeometry(QRect(1210, 400, 101, 51));
        Exporter_2->setFont(font);
        Exporter_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Trier_2 = new QPushButton(page_4);
        Trier_2->setObjectName("Trier_2");
        Trier_2->setGeometry(QRect(1040, 70, 101, 51));
        Trier_2->setFont(font);
        Trier_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Rechercher_Employe = new QLineEdit(page_4);
        Rechercher_Employe->setObjectName("Rechercher_Employe");
        Rechercher_Employe->setGeometry(QRect(620, 80, 291, 41));
        Rechercher_Employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        frame = new QFrame(page_4);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 211, 791));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_20 = new QLabel(frame);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(80, 50, 121, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bahnschrift")});
        font4.setPointSize(18);
        font4.setBold(true);
        label_20->setFont(font4);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 130, 131, 61));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 190, 171, 61));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 250, 171, 61));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_21 = new QLabel(frame);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(10, 30, 61, 61));
        label_21->setStyleSheet(QString::fromUtf8("image: url(:/cropped_circle_image.png);"));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_21->setScaledContents(true);
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(0, 370, 181, 61));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(0, 310, 171, 61));
        pushButton_10->setFont(font);
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(-10, -10, 211, 791));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_22 = new QLabel(frame_3);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(70, 80, 121, 31));
        label_22->setFont(font4);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 130, 131, 61));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        residence_2 = new QPushButton(frame_3);
        residence_2->setObjectName("residence_2");
        residence_2->setGeometry(QRect(10, 190, 171, 61));
        residence_2->setFont(font);
        residence_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        resident_3 = new QPushButton(frame_3);
        resident_3->setObjectName("resident_3");
        resident_3->setGeometry(QRect(0, 250, 171, 61));
        resident_3->setFont(font);
        resident_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Evenements_4 = new QPushButton(frame_3);
        Evenements_4->setObjectName("Evenements_4");
        Evenements_4->setGeometry(QRect(0, 370, 181, 61));
        Evenements_4->setFont(font);
        Evenements_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        service_3 = new QPushButton(frame_3);
        service_3->setObjectName("service_3");
        service_3->setGeometry(QRect(0, 310, 171, 61));
        service_3->setFont(font);
        service_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 70, 51, 51));
        label_5->setTextFormat(Qt::TextFormat::MarkdownText);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_5->setScaledContents(true);
        label_5->setWordWrap(false);
        label_5->setOpenExternalLinks(false);
        label_5->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        Ajouter_2 = new QFrame(page_4);
        Ajouter_2->setObjectName("Ajouter_2");
        Ajouter_2->setGeometry(QRect(200, 20, 381, 801));
        Ajouter_2->setStyleSheet(QString::fromUtf8("#Ajouter {\n"
"border: 2px solid black;\n"
"	\n"
"	border-color: rgb(219, 220, 255);\n"
"}\n"
"\n"
"QFrame {\n"
"background-color : #ffffff;\n"
" border-radius: 20px\n"
"}"));
        Ajouter_2->setFrameShape(QFrame::Shape::StyledPanel);
        Ajouter_2->setFrameShadow(QFrame::Shadow::Raised);
        label_10 = new QLabel(Ajouter_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(80, 30, 211, 31));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(Ajouter_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 200, 71, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(Ajouter_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 260, 49, 21));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(Ajouter_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 320, 101, 21));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(Ajouter_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 380, 71, 21));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Prenom_Employe = new QLineEdit(Ajouter_2);
        Prenom_Employe->setObjectName("Prenom_Employe");
        Prenom_Employe->setGeometry(QRect(170, 190, 141, 41));
        Prenom_Employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        ID_Employe = new QLineEdit(Ajouter_2);
        ID_Employe->setObjectName("ID_Employe");
        ID_Employe->setGeometry(QRect(170, 250, 141, 41));
        ID_Employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Telephone_Employe = new QLineEdit(Ajouter_2);
        Telephone_Employe->setObjectName("Telephone_Employe");
        Telephone_Employe->setGeometry(QRect(170, 310, 141, 41));
        Telephone_Employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Salaire = new QLineEdit(Ajouter_2);
        Salaire->setObjectName("Salaire");
        Salaire->setGeometry(QRect(170, 370, 141, 41));
        Salaire->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_25 = new QLabel(Ajouter_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(20, 450, 61, 16));
        label_25->setFont(font2);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Sexe_Employe = new QLineEdit(Ajouter_2);
        Sexe_Employe->setObjectName("Sexe_Employe");
        Sexe_Employe->setGeometry(QRect(170, 440, 141, 41));
        Sexe_Employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Nom_Employe = new QLineEdit(Ajouter_2);
        Nom_Employe->setObjectName("Nom_Employe");
        Nom_Employe->setGeometry(QRect(170, 120, 141, 41));
        Nom_Employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_11 = new QLabel(Ajouter_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 130, 131, 21));
        label_11->setFont(font3);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Ajouter_Employe = new QPushButton(Ajouter_2);
        Ajouter_Employe->setObjectName("Ajouter_Employe");
        Ajouter_Employe->setGeometry(QRect(30, 570, 101, 51));
        Ajouter_Employe->setFont(font);
        Ajouter_Employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_26 = new QLabel(Ajouter_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(20, 500, 141, 31));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Responsabilite = new QLineEdit(Ajouter_2);
        Responsabilite->setObjectName("Responsabilite");
        Responsabilite->setGeometry(QRect(170, 500, 141, 41));
        Responsabilite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Modifier_Employe = new QPushButton(Ajouter_2);
        Modifier_Employe->setObjectName("Modifier_Employe");
        Modifier_Employe->setGeometry(QRect(150, 570, 101, 51));
        Modifier_Employe->setFont(font);
        Modifier_Employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Supprimer_Employe = new QPushButton(Ajouter_2);
        Supprimer_Employe->setObjectName("Supprimer_Employe");
        Supprimer_Employe->setGeometry(QRect(270, 570, 101, 51));
        Supprimer_Employe->setFont(font);
        Supprimer_Employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_27 = new QLabel(page_4);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(600, 50, 301, 31));
        label_27->setFont(font1);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Rechercher = new QPushButton(page_4);
        Rechercher->setObjectName("Rechercher");
        Rechercher->setGeometry(QRect(930, 70, 101, 51));
        Rechercher->setFont(font);
        Rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Statistiques_Employe = new QPushButton(page_4);
        Statistiques_Employe->setObjectName("Statistiques_Employe");
        Statistiques_Employe->setGeometry(QRect(1210, 640, 101, 51));
        Statistiques_Employe->setFont(font);
        Statistiques_Employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        tableWidgetEmployes = new QTableWidget(page_4);
        if (tableWidgetEmployes->columnCount() < 7)
            tableWidgetEmployes->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        tableWidgetEmployes->setObjectName("tableWidgetEmployes");
        tableWidgetEmployes->setGeometry(QRect(600, 140, 711, 241));
        tableWidgetEmployes->setStyleSheet(QString::fromUtf8("border-raduis : 20px;\n"
"background-color : #e1e5ff;"));
        label_39 = new QLabel(page_4);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(560, 30, 791, 771));
        label_39->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widgetStats = new QWidget(page_4);
        widgetStats->setObjectName("widgetStats");
        widgetStats->setGeometry(QRect(600, 420, 501, 241));
        stackedWidget->addWidget(page_4);
        label_39->raise();
        Exporter_2->raise();
        Trier_2->raise();
        Rechercher_Employe->raise();
        frame->raise();
        Ajouter_2->raise();
        label_27->raise();
        Rechercher->raise();
        Statistiques_Employe->raise();
        tableWidgetEmployes->raise();
        widgetStats->raise();
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        frame_9 = new QFrame(page_6);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(-10, 10, 201, 801));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        label_64 = new QLabel(frame_9);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(70, 40, 121, 31));
        label_64->setFont(font4);
        label_64->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RH_6 = new QPushButton(frame_9);
        RH_6->setObjectName("RH_6");
        RH_6->setGeometry(QRect(20, 130, 131, 61));
        RH_6->setFont(font);
        RH_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        residence_7 = new QPushButton(frame_9);
        residence_7->setObjectName("residence_7");
        residence_7->setGeometry(QRect(10, 190, 171, 61));
        residence_7->setFont(font);
        residence_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        resident_8 = new QPushButton(frame_9);
        resident_8->setObjectName("resident_8");
        resident_8->setGeometry(QRect(0, 250, 171, 61));
        resident_8->setFont(font);
        resident_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Evenements_8 = new QPushButton(frame_9);
        Evenements_8->setObjectName("Evenements_8");
        Evenements_8->setGeometry(QRect(0, 370, 181, 61));
        Evenements_8->setFont(font);
        Evenements_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButton_29 = new QPushButton(frame_9);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(0, 310, 171, 61));
        pushButton_29->setFont(font);
        pushButton_29->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_65 = new QLabel(frame_9);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(10, 30, 51, 51));
        label_65->setTextFormat(Qt::TextFormat::MarkdownText);
        label_65->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_65->setScaledContents(true);
        label_65->setWordWrap(false);
        label_65->setOpenExternalLinks(false);
        label_65->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        frame_10 = new QFrame(page_6);
        frame_10->setObjectName("frame_10");
        frame_10->setGeometry(QRect(170, 30, 1171, 741));
        frame_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        label_priority = new QLabel(frame_10);
        label_priority->setObjectName("label_priority");
        label_priority->setGeometry(QRect(70, 470, 55, 35));
        label_date = new QLabel(frame_10);
        label_date->setObjectName("label_date");
        label_date->setGeometry(QRect(80, 550, 39, 35));
        ajouterButton = new QPushButton(frame_10);
        ajouterButton->setObjectName("ajouterButton");
        ajouterButton->setGeometry(QRect(50, 640, 119, 39));
        ajouterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_resp = new QLabel(frame_10);
        label_resp->setObjectName("label_resp");
        label_resp->setGeometry(QRect(70, 270, 91, 35));
        lineEdit_responsable = new QLineEdit(frame_10);
        lineEdit_responsable->setObjectName("lineEdit_responsable");
        lineEdit_responsable->setGeometry(QRect(210, 280, 201, 36));
        lineEdit_responsable->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit {\n"
"	\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
""));
        dateEdit_date = new QDateEdit(frame_10);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setGeometry(QRect(180, 560, 237, 22));
        dateEdit_date->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        dateEdit_date->setCalendarPopup(true);
        combo_priority = new QComboBox(frame_10);
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->setObjectName("combo_priority");
        combo_priority->setGeometry(QRect(190, 480, 237, 26));
        combo_priority->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        combo_type = new QComboBox(frame_10);
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->setObjectName("combo_type");
        combo_type->setGeometry(QRect(190, 380, 237, 26));
        combo_type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}     QLineEdit {\n"
"	\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
""));
        combo_state = new QComboBox(frame_10);
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->setObjectName("combo_state");
        combo_state->setGeometry(QRect(190, 520, 237, 26));
        combo_state->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_type = new QLabel(frame_10);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(80, 370, 38, 35));
        label_budget = new QLabel(frame_10);
        label_budget->setObjectName("label_budget");
        label_budget->setGeometry(QRect(60, 420, 55, 35));
        supprimerButton = new QPushButton(frame_10);
        supprimerButton->setObjectName("supprimerButton");
        supprimerButton->setGeometry(QRect(370, 640, 119, 39));
        supprimerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        spin_budget = new QDoubleSpinBox(frame_10);
        spin_budget->setObjectName("spin_budget");
        spin_budget->setGeometry(QRect(190, 430, 237, 22));
        spin_budget->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        spin_budget->setMaximum(100000000.000000000000000);
        label_state = new QLabel(frame_10);
        label_state->setObjectName("label_state");
        label_state->setGeometry(QRect(80, 510, 33, 35));
        label_id = new QLabel(frame_10);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(90, 170, 73, 35));
        lineEdit_Nom = new QLineEdit(frame_10);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setGeometry(QRect(210, 230, 201, 36));
        lineEdit_Nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        modifierButton = new QPushButton(frame_10);
        modifierButton->setObjectName("modifierButton");
        modifierButton->setGeometry(QRect(200, 640, 119, 39));
        modifierButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_name = new QLabel(frame_10);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(90, 220, 40, 35));
        lineEdit_id = new QLineEdit(frame_10);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(210, 170, 201, 36));
        lineEdit_id->setMinimumSize(QSize(8, 0));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        Rechercher_Service = new QLineEdit(frame_10);
        Rechercher_Service->setObjectName("Rechercher_Service");
        Rechercher_Service->setGeometry(QRect(40, 40, 511, 31));
        Rechercher_Service->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Rechercher_Services = new QPushButton(frame_10);
        Rechercher_Services->setObjectName("Rechercher_Services");
        Rechercher_Services->setGeometry(QRect(620, 30, 101, 51));
        Rechercher_Services->setFont(font);
        Rechercher_Services->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_sort = new QLabel(frame_10);
        label_sort->setObjectName("label_sort");
        label_sort->setGeometry(QRect(800, 30, 62, 41));
        combo_sort = new QComboBox(frame_10);
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->setObjectName("combo_sort");
        combo_sort->setGeometry(QRect(890, 40, 73, 26));
        combo_sort->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        btnIA = new QPushButton(frame_10);
        btnIA->setObjectName("btnIA");
        btnIA->setGeometry(QRect(1010, 30, 93, 41));
        btnIA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(255, 105, 180); /* rose vif */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
""));
        tableServices = new QTableWidget(frame_10);
        if (tableServices->columnCount() < 8)
            tableServices->setColumnCount(8);
        QFont font5;
        font5.setPointSize(9);
        font5.setBold(true);
        font5.setItalic(true);
        font5.setUnderline(false);
        font5.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font5);
        __qtablewidgetitem15->setBackground(QColor(255, 255, 255));
        tableServices->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QFont font6;
        font6.setBold(true);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font6);
        __qtablewidgetitem16->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QFont font7;
        font7.setBold(true);
        font7.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font7);
        __qtablewidgetitem17->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font7);
        __qtablewidgetitem18->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font7);
        __qtablewidgetitem19->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font7);
        __qtablewidgetitem20->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font7);
        __qtablewidgetitem21->setBackground(QColor(255, 255, 255, 0));
        tableServices->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableServices->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        if (tableServices->rowCount() < 8)
            tableServices->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(5, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(6, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(7, __qtablewidgetitem30);
        QFont font8;
        font8.setPointSize(23);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font8);
        tableServices->setItem(0, 0, __qtablewidgetitem31);
        tableServices->setObjectName("tableServices");
        tableServices->setGeometry(QRect(480, 100, 641, 251));
        tableServices->setMinimumSize(QSize(220, 50));
        tableServices->setAutoFillBackground(true);
        tableServices->setStyleSheet(QString::fromUtf8(""));
        tableServices->setRowCount(8);
        tableServices->setColumnCount(8);
        widget = new QWidget(frame_10);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(500, 360, 1011, 281));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(190, 20, 451, 241));
        verticalLayout_Service = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_Service->setObjectName("verticalLayout_Service");
        verticalLayout_Service->setContentsMargins(0, 0, 0, 0);
        btnStats = new QPushButton(widget);
        btnStats->setObjectName("btnStats");
        btnStats->setGeometry(QRect(10, 70, 171, 61));
        btnStats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        btnExportPDF_Services = new QPushButton(frame_10);
        btnExportPDF_Services->setObjectName("btnExportPDF_Services");
        btnExportPDF_Services->setGeometry(QRect(990, 660, 141, 51));
        btnExportPDF_Services->setFont(font);
        btnExportPDF_Services->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        stackedWidget->addWidget(page_6);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        BarreGestions = new QFrame(page_2);
        BarreGestions->setObjectName("BarreGestions");
        BarreGestions->setGeometry(QRect(-10, 0, 201, 781));
        BarreGestions->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        BarreGestions->setFrameShape(QFrame::Shape::StyledPanel);
        BarreGestions->setFrameShadow(QFrame::Shadow::Raised);
        label_60 = new QLabel(BarreGestions);
        label_60->setObjectName("label_60");
        label_60->setGeometry(QRect(70, 70, 121, 31));
        label_60->setFont(font4);
        label_60->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RH_3 = new QPushButton(BarreGestions);
        RH_3->setObjectName("RH_3");
        RH_3->setGeometry(QRect(10, 120, 141, 61));
        RH_3->setFont(font);
        RH_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        service_4 = new QPushButton(BarreGestions);
        service_4->setObjectName("service_4");
        service_4->setGeometry(QRect(0, 310, 151, 61));
        service_4->setFont(font);
        service_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Evenements = new QPushButton(BarreGestions);
        Evenements->setObjectName("Evenements");
        Evenements->setGeometry(QRect(20, 380, 151, 61));
        Evenements->setFont(font);
        Evenements->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        resident_4 = new QPushButton(BarreGestions);
        resident_4->setObjectName("resident_4");
        resident_4->setGeometry(QRect(10, 250, 131, 61));
        resident_4->setFont(font);
        resident_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_61 = new QLabel(BarreGestions);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(10, 50, 51, 51));
        label_61->setTextFormat(Qt::TextFormat::MarkdownText);
        label_61->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_61->setScaledContents(true);
        label_61->setWordWrap(false);
        label_61->setOpenExternalLinks(false);
        label_61->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        residence_5 = new QPushButton(BarreGestions);
        residence_5->setObjectName("residence_5");
        residence_5->setGeometry(QRect(20, 180, 151, 61));
        residence_5->setFont(font);
        residence_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Ajouter_4 = new QFrame(page_2);
        Ajouter_4->setObjectName("Ajouter_4");
        Ajouter_4->setGeometry(QRect(190, 20, 351, 751));
        Ajouter_4->setStyleSheet(QString::fromUtf8("#Ajouter {\n"
"border: 2px solid black;\n"
"	\n"
"	border-color: rgb(219, 220, 255);\n"
"}\n"
"\n"
"QFrame {\n"
"background-color : #ffffff;\n"
" border-radius: 20px\n"
"}"));
        Ajouter_4->setFrameShape(QFrame::Shape::StyledPanel);
        Ajouter_4->setFrameShadow(QFrame::Shadow::Raised);
        label_28 = new QLabel(Ajouter_4);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(90, 20, 171, 16));
        label_28->setFont(font1);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(Ajouter_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 200, 49, 21));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_29 = new QLabel(Ajouter_4);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(30, 260, 49, 21));
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_30 = new QLabel(Ajouter_4);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(30, 320, 49, 21));
        label_30->setFont(font2);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_31 = new QLabel(Ajouter_4);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(30, 380, 49, 21));
        label_31->setFont(font2);
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Nom = new QLineEdit(Ajouter_4);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(170, 190, 141, 41));
        Nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #7e7e7e;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Type = new QLineEdit(Ajouter_4);
        Type->setObjectName("Type");
        Type->setGeometry(QRect(170, 250, 141, 41));
        Type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #7e7e7e;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Lieu = new QLineEdit(Ajouter_4);
        Lieu->setObjectName("Lieu");
        Lieu->setGeometry(QRect(170, 310, 141, 41));
        Lieu->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #7e7e7e;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_33 = new QLabel(Ajouter_4);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(30, 450, 61, 16));
        label_33->setFont(font2);
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        ID = new QLineEdit(Ajouter_4);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(170, 80, 141, 41));
        ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #7e7e7e;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_34 = new QLabel(Ajouter_4);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(30, 90, 81, 21));
        label_34->setFont(font3);
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Ajouterbutton = new QPushButton(Ajouter_4);
        Ajouterbutton->setObjectName("Ajouterbutton");
        Ajouterbutton->setGeometry(QRect(120, 590, 101, 41));
        Ajouterbutton->setFont(font);
        Ajouterbutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        NbrP = new QLineEdit(Ajouter_4);
        NbrP->setObjectName("NbrP");
        NbrP->setGeometry(QRect(170, 510, 141, 41));
        NbrP->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #7e7e7e;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_35 = new QLabel(Ajouter_4);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(30, 520, 131, 16));
        label_35->setFont(font2);
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        timeEdit = new QTimeEdit(Ajouter_4);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(170, 440, 141, 31));
        dateEdit = new QDateEdit(Ajouter_4);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(170, 380, 141, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("border-raduis : 10px"));
        label_44 = new QLabel(Ajouter_4);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(20, 140, 131, 21));
        label_44->setFont(font3);
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        ID_Employe_Evenement = new QLineEdit(Ajouter_4);
        ID_Employe_Evenement->setObjectName("ID_Employe_Evenement");
        ID_Employe_Evenement->setGeometry(QRect(170, 130, 141, 41));
        ID_Employe_Evenement->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Modifier_2 = new QPushButton(Ajouter_4);
        Modifier_2->setObjectName("Modifier_2");
        Modifier_2->setGeometry(QRect(10, 590, 101, 41));
        Modifier_2->setFont(font);
        Modifier_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Supprimer_2 = new QPushButton(Ajouter_4);
        Supprimer_2->setObjectName("Supprimer_2");
        Supprimer_2->setGeometry(QRect(240, 590, 101, 41));
        Supprimer_2->setFont(font);
        Supprimer_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(540, 30, 771, 741));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{\n"
"	font: 700 12pt \"Bahnschrift\";\n"
"	 border-radius: 20px\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        frame_6 = new QFrame(tab);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 0, 801, 721));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        Recherche_Line = new QLineEdit(frame_6);
        Recherche_Line->setObjectName("Recherche_Line");
        Recherche_Line->setGeometry(QRect(220, 10, 201, 41));
        Recherche_Line->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #7e7e7e;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_36 = new QLabel(frame_6);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(10, 19, 201, 21));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Bahnschrift")});
        font9.setPointSize(12);
        font9.setBold(true);
        label_36->setFont(font9);
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        comboBox = new QComboBox(frame_6);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(590, 20, 131, 31));
        comboBox->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff;"));
        Excel = new QPushButton(frame_6);
        Excel->setObjectName("Excel");
        Excel->setGeometry(QRect(600, 640, 141, 41));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font10.setBold(true);
        Excel->setFont(font10);
        Excel->setAutoFillBackground(false);
        Excel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        tableView_Evenement = new QTableView(frame_6);
        tableView_Evenement->setObjectName("tableView_Evenement");
        tableView_Evenement->setGeometry(QRect(30, 100, 691, 401));
        tableView_Evenement->setStyleSheet(QString::fromUtf8("border-raduis : 20px;\n"
"background-color : #e1e5ff;"));
        tabWidget->addTab(tab, QString());
        Fonctionnalites = new QWidget();
        Fonctionnalites->setObjectName("Fonctionnalites");
        frame_Prediction = new QFrame(Fonctionnalites);
        frame_Prediction->setObjectName("frame_Prediction");
        frame_Prediction->setGeometry(QRect(410, 380, 341, 311));
        frame_Prediction->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color : #2C3E50;\n"
" border-radius: 20px\n"
"}"));
        frame_Prediction->setFrameShape(QFrame::Shape::StyledPanel);
        frame_Prediction->setFrameShadow(QFrame::Shadow::Raised);
        label_37 = new QLabel(frame_Prediction);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(100, 20, 161, 16));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Bahnschrift")});
        font11.setPointSize(11);
        font11.setBold(true);
        label_37->setFont(font11);
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Id_Evenement = new QLineEdit(frame_Prediction);
        Id_Evenement->setObjectName("Id_Evenement");
        Id_Evenement->setGeometry(QRect(170, 60, 141, 41));
        Id_Evenement->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_40 = new QLabel(frame_Prediction);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(10, 69, 151, 21));
        label_40->setFont(font11);
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Prediction = new QPushButton(frame_Prediction);
        Prediction->setObjectName("Prediction");
        Prediction->setGeometry(QRect(100, 110, 141, 41));
        Prediction->setFont(font);
        Prediction->setAutoFillBackground(false);
        Prediction->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        Dioxyde = new QLabel(frame_Prediction);
        Dioxyde->setObjectName("Dioxyde");
        Dioxyde->setGeometry(QRect(70, 170, 181, 71));
        Dioxyde->setFont(font9);
        Dioxyde->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_7 = new QFrame(Fonctionnalites);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(380, 40, 371, 331));
        frame_7->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color : #2C3E50;\n"
" border-radius: 20px\n"
"}"));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        label_41 = new QLabel(frame_7);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(90, 20, 201, 16));
        label_41->setFont(font11);
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ID_localisation = new QLineEdit(frame_7);
        ID_localisation->setObjectName("ID_localisation");
        ID_localisation->setGeometry(QRect(180, 50, 141, 41));
        ID_localisation->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_42 = new QLabel(frame_7);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(20, 60, 151, 21));
        label_42->setFont(font11);
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Localiser = new QPushButton(frame_7);
        Localiser->setObjectName("Localiser");
        Localiser->setGeometry(QRect(40, 110, 141, 41));
        Localiser->setFont(font);
        Localiser->setAutoFillBackground(false);
        Localiser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        MapWidget = new QQuickWidget(frame_7);
        MapWidget->setObjectName("MapWidget");
        MapWidget->setGeometry(QRect(20, 160, 331, 161));
        MapWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        btnItineraire = new QPushButton(frame_7);
        btnItineraire->setObjectName("btnItineraire");
        btnItineraire->setGeometry(QRect(200, 110, 141, 41));
        btnItineraire->setFont(font);
        btnItineraire->setAutoFillBackground(false);
        btnItineraire->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        label_43 = new QLabel(Fonctionnalites);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(180, 470, 21, 21));
        label_43->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color : #87CEEB;\n"
"}"));
        label_54 = new QLabel(Fonctionnalites);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(160, 440, 61, 16));
        label_54->setFont(font3);
        label_54->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_55 = new QLabel(Fonctionnalites);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(270, 440, 49, 16));
        label_55->setFont(font3);
        label_55->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_56 = new QLabel(Fonctionnalites);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(280, 470, 21, 21));
        label_56->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color : #FF0000;\n"
"}"));
        label_57 = new QLabel(Fonctionnalites);
        label_57->setObjectName("label_57");
        label_57->setGeometry(QRect(50, 440, 71, 16));
        label_57->setFont(font3);
        label_57->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_58 = new QLabel(Fonctionnalites);
        label_58->setObjectName("label_58");
        label_58->setGeometry(QRect(70, 470, 21, 21));
        label_58->setFont(font3);
        label_58->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #003366;\n"
"}"));
        Statistiques_Evenement = new QPushButton(Fonctionnalites);
        Statistiques_Evenement->setObjectName("Statistiques_Evenement");
        Statistiques_Evenement->setGeometry(QRect(120, 560, 121, 41));
        Statistiques_Evenement->setFont(font);
        Statistiques_Evenement->setAutoFillBackground(false);
        Statistiques_Evenement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        StatisqueWidget = new Statistique(Fonctionnalites);
        StatisqueWidget->setObjectName("StatisqueWidget");
        StatisqueWidget->setGeometry(QRect(10, 110, 361, 311));
        tabWidget->addTab(Fonctionnalites, QString());
        stackedWidget->addWidget(page_2);
        page_13 = new QWidget();
        page_13->setObjectName("page_13");
        lineEditCodeRecu = new QLineEdit(page_13);
        lineEditCodeRecu->setObjectName("lineEditCodeRecu");
        lineEditCodeRecu->setGeometry(QRect(170, 310, 301, 41));
        lineEditCodeRecu->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        lineEditNouveauPass = new QLineEdit(page_13);
        lineEditNouveauPass->setObjectName("lineEditNouveauPass");
        lineEditNouveauPass->setGeometry(QRect(170, 420, 301, 41));
        lineEditNouveauPass->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        label_131 = new QLabel(page_13);
        label_131->setObjectName("label_131");
        label_131->setGeometry(QRect(0, 30, 1381, 781));
        label_131->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 62, 80);"));
        textBrowser_18 = new QTextBrowser(page_13);
        textBrowser_18->setObjectName("textBrowser_18");
        textBrowser_18->setGeometry(QRect(170, 260, 301, 61));
        textBrowser_18->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_18->setFrameShape(QFrame::Shape::NoFrame);
        pushButtonValiderReset = new QPushButton(page_13);
        pushButtonValiderReset->setObjectName("pushButtonValiderReset");
        pushButtonValiderReset->setGeometry(QRect(220, 490, 101, 51));
        pushButtonValiderReset->setFont(font);
        pushButtonValiderReset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_132 = new QLabel(page_13);
        label_132->setObjectName("label_132");
        label_132->setGeometry(QRect(670, 30, 691, 771));
        label_132->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/Artboa.png);"));
        textBrowser_17 = new QTextBrowser(page_13);
        textBrowser_17->setObjectName("textBrowser_17");
        textBrowser_17->setGeometry(QRect(100, 370, 431, 61));
        textBrowser_17->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_17->setFrameShape(QFrame::Shape::NoFrame);
        pushButtonRetourLogin_3 = new QPushButton(page_13);
        pushButtonRetourLogin_3->setObjectName("pushButtonRetourLogin_3");
        pushButtonRetourLogin_3->setGeometry(QRect(340, 490, 101, 51));
        pushButtonRetourLogin_3->setFont(font);
        pushButtonRetourLogin_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        textBrowser_20 = new QTextBrowser(page_13);
        textBrowser_20->setObjectName("textBrowser_20");
        textBrowser_20->setGeometry(QRect(60, 120, 521, 111));
        textBrowser_20->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_20->setFrameShape(QFrame::Shape::NoFrame);
        stackedWidget->addWidget(page_13);
        label_131->raise();
        textBrowser_18->raise();
        pushButtonValiderReset->raise();
        label_132->raise();
        textBrowser_17->raise();
        pushButtonRetourLogin_3->raise();
        textBrowser_20->raise();
        lineEditCodeRecu->raise();
        lineEditNouveauPass->raise();
        page_14 = new QWidget();
        page_14->setObjectName("page_14");
        stackedWidget->addWidget(page_14);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        lineEditMdpId = new QLineEdit(page_7);
        lineEditMdpId->setObjectName("lineEditMdpId");
        lineEditMdpId->setGeometry(QRect(210, 360, 301, 41));
        lineEditMdpId->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        textBrowser_15 = new QTextBrowser(page_7);
        textBrowser_15->setObjectName("textBrowser_15");
        textBrowser_15->setGeometry(QRect(10, 90, 561, 111));
        textBrowser_15->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_15->setFrameShape(QFrame::Shape::NoFrame);
        lineEditMdpEmail = new QLineEdit(page_7);
        lineEditMdpEmail->setObjectName("lineEditMdpEmail");
        lineEditMdpEmail->setGeometry(QRect(210, 460, 301, 41));
        lineEditMdpEmail->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        label_66 = new QLabel(page_7);
        label_66->setObjectName("label_66");
        label_66->setGeometry(QRect(670, 30, 691, 761));
        label_66->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/Mesa de trabajo 1.png);"));
        pushButtonSuivant = new QPushButton(page_7);
        pushButtonSuivant->setObjectName("pushButtonSuivant");
        pushButtonSuivant->setGeometry(QRect(260, 530, 101, 51));
        pushButtonSuivant->setFont(font);
        pushButtonSuivant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButtonRetourLogin_2 = new QPushButton(page_7);
        pushButtonRetourLogin_2->setObjectName("pushButtonRetourLogin_2");
        pushButtonRetourLogin_2->setGeometry(QRect(380, 530, 101, 51));
        pushButtonRetourLogin_2->setFont(font);
        pushButtonRetourLogin_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_67 = new QLabel(page_7);
        label_67->setObjectName("label_67");
        label_67->setGeometry(QRect(0, 20, 1381, 781));
        label_67->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 62, 80);"));
        lineEditMdpUsername = new QLineEdit(page_7);
        lineEditMdpUsername->setObjectName("lineEditMdpUsername");
        lineEditMdpUsername->setGeometry(QRect(210, 270, 301, 41));
        lineEditMdpUsername->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        textBrowser_14 = new QTextBrowser(page_7);
        textBrowser_14->setObjectName("textBrowser_14");
        textBrowser_14->setGeometry(QRect(210, 310, 301, 61));
        textBrowser_14->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_14->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser_16 = new QTextBrowser(page_7);
        textBrowser_16->setObjectName("textBrowser_16");
        textBrowser_16->setGeometry(QRect(210, 210, 301, 61));
        textBrowser_16->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_16->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser_19 = new QTextBrowser(page_7);
        textBrowser_19->setObjectName("textBrowser_19");
        textBrowser_19->setGeometry(QRect(140, 410, 431, 61));
        textBrowser_19->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_19->setFrameShape(QFrame::Shape::NoFrame);
        stackedWidget->addWidget(page_7);
        label_67->raise();
        textBrowser_15->raise();
        label_66->raise();
        pushButtonSuivant->raise();
        pushButtonRetourLogin_2->raise();
        textBrowser_14->raise();
        textBrowser_16->raise();
        textBrowser_19->raise();
        lineEditMdpEmail->raise();
        lineEditMdpId->raise();
        lineEditMdpUsername->raise();
        Connection = new QWidget();
        Connection->setObjectName("Connection");
        label_128 = new QLabel(Connection);
        label_128->setObjectName("label_128");
        label_128->setGeometry(QRect(80, 70, 121, 31));
        label_128->setFont(font4);
        label_128->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        textBrowser = new QTextBrowser(Connection);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 130, 591, 111));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser_2 = new QTextBrowser(Connection);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(190, 270, 201, 41));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_2->setFrameShape(QFrame::Shape::NoFrame);
        label_129 = new QLabel(Connection);
        label_129->setObjectName("label_129");
        label_129->setGeometry(QRect(720, 0, 641, 761));
        label_129->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/Artboard 1.png);"));
        textBrowser_3 = new QTextBrowser(Connection);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(200, 370, 141, 41));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_3->setFrameShape(QFrame::Shape::NoFrame);
        label_130 = new QLabel(Connection);
        label_130->setObjectName("label_130");
        label_130->setGeometry(QRect(10, 50, 61, 61));
        label_130->setStyleSheet(QString::fromUtf8("image: url(:/cropped_circle_image.png);"));
        label_130->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_130->setScaledContents(true);
        quitter = new QPushButton(Connection);
        quitter->setObjectName("quitter");
        quitter->setGeometry(QRect(350, 520, 81, 41));
        quitter->setFont(font);
        quitter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEditLoginUsername = new QLineEdit(Connection);
        lineEditLoginUsername->setObjectName("lineEditLoginUsername");
        lineEditLoginUsername->setGeometry(QRect(210, 310, 271, 41));
        lineEditLoginUsername->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        lineEditLoginPassword = new QLineEdit(Connection);
        lineEditLoginPassword->setObjectName("lineEditLoginPassword");
        lineEditLoginPassword->setGeometry(QRect(210, 410, 271, 41));
        lineEditLoginPassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        connecter = new QPushButton(Connection);
        connecter->setObjectName("connecter");
        connecter->setGeometry(QRect(260, 520, 81, 41));
        connecter->setFont(font);
        connecter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButtonGoToMdp = new QPushButton(Connection);
        pushButtonGoToMdp->setObjectName("pushButtonGoToMdp");
        pushButtonGoToMdp->setGeometry(QRect(280, 450, 201, 51));
        pushButtonGoToMdp->setFont(font);
        pushButtonGoToMdp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label = new QLabel(Connection);
        label->setObjectName("label");
        label->setGeometry(QRect(-10, 0, 1381, 781));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 62, 80);"));
        stackedWidget->addWidget(Connection);
        label->raise();
        textBrowser_3->raise();
        pushButtonGoToMdp->raise();
        lineEditLoginPassword->raise();
        textBrowser_2->raise();
        label_128->raise();
        quitter->raise();
        label_130->raise();
        textBrowser->raise();
        label_129->raise();
        lineEditLoginUsername->raise();
        connecter->raise();
        page = new QWidget();
        page->setObjectName("page");
        frame_5 = new QFrame(page);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(-10, -10, 221, 791));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        label_32 = new QLabel(frame_5);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(90, 80, 121, 31));
        label_32->setFont(font4);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RH_2 = new QPushButton(frame_5);
        RH_2->setObjectName("RH_2");
        RH_2->setGeometry(QRect(20, 130, 131, 61));
        RH_2->setFont(font);
        RH_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        residence_3 = new QPushButton(frame_5);
        residence_3->setObjectName("residence_3");
        residence_3->setGeometry(QRect(30, 190, 171, 61));
        residence_3->setFont(font);
        residence_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        resident = new QPushButton(frame_5);
        resident->setObjectName("resident");
        resident->setGeometry(QRect(20, 250, 171, 61));
        resident->setFont(font);
        resident->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Evenements_2 = new QPushButton(frame_5);
        Evenements_2->setObjectName("Evenements_2");
        Evenements_2->setGeometry(QRect(20, 370, 181, 61));
        Evenements_2->setFont(font);
        Evenements_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        service = new QPushButton(frame_5);
        service->setObjectName("service");
        service->setGeometry(QRect(20, 310, 171, 61));
        service->setFont(font);
        service->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_53 = new QLabel(frame_5);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(30, 70, 51, 51));
        label_53->setTextFormat(Qt::TextFormat::MarkdownText);
        label_53->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_53->setScaledContents(true);
        label_53->setWordWrap(false);
        label_53->setOpenExternalLinks(false);
        label_53->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        pushButton_149 = new QPushButton(page);
        pushButton_149->setObjectName("pushButton_149");
        pushButton_149->setGeometry(QRect(740, 680, 101, 51));
        pushButton_149->setFont(font);
        pushButton_149->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_293 = new QLabel(page);
        label_293->setObjectName("label_293");
        label_293->setGeometry(QRect(660, 30, 711, 771));
        label_293->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Ajouter_3 = new QFrame(page);
        Ajouter_3->setObjectName("Ajouter_3");
        Ajouter_3->setGeometry(QRect(210, 30, 451, 801));
        Ajouter_3->setStyleSheet(QString::fromUtf8("#Ajouter {\n"
"border: 2px solid black;\n"
"	\n"
"	border-color: rgb(219, 220, 255);\n"
"}\n"
"\n"
"QFrame {\n"
"background-color : #ffffff;\n"
" border-radius: 20px\n"
"}"));
        Ajouter_3->setFrameShape(QFrame::Shape::StyledPanel);
        Ajouter_3->setFrameShadow(QFrame::Shadow::Raised);
        label_45 = new QLabel(Ajouter_3);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(120, 20, 211, 16));
        label_45->setFont(font1);
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_49 = new QLabel(Ajouter_3);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(20, 150, 131, 21));
        label_49->setFont(font3);
        label_49->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_situation = new QLineEdit(Ajouter_3);
        lineEdit_situation->setObjectName("lineEdit_situation");
        lineEdit_situation->setGeometry(QRect(240, 550, 141, 41));
        lineEdit_situation->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_age = new QLineEdit(Ajouter_3);
        lineEdit_age->setObjectName("lineEdit_age");
        lineEdit_age->setGeometry(QRect(240, 360, 141, 41));
        lineEdit_age->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_profession = new QLineEdit(Ajouter_3);
        lineEdit_profession->setObjectName("lineEdit_profession");
        lineEdit_profession->setGeometry(QRect(240, 480, 141, 41));
        lineEdit_profession->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_nom = new QLineEdit(Ajouter_3);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(240, 210, 141, 41));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_48 = new QLabel(Ajouter_3);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(30, 480, 111, 31));
        label_48->setFont(font2);
        label_48->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_46 = new QLabel(Ajouter_3);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(30, 220, 49, 21));
        label_46->setFont(font2);
        label_46->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_prenom = new QLineEdit(Ajouter_3);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(240, 280, 141, 41));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_47 = new QLabel(Ajouter_3);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(20, 560, 191, 21));
        label_47->setFont(font2);
        label_47->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_sexe = new QLineEdit(Ajouter_3);
        lineEdit_sexe->setObjectName("lineEdit_sexe");
        lineEdit_sexe->setGeometry(QRect(240, 420, 141, 41));
        lineEdit_sexe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_idresident = new QLineEdit(Ajouter_3);
        lineEdit_idresident->setObjectName("lineEdit_idresident");
        lineEdit_idresident->setGeometry(QRect(240, 140, 141, 41));
        lineEdit_idresident->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_50 = new QLabel(Ajouter_3);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(30, 430, 61, 16));
        label_50->setFont(font2);
        label_50->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_68 = new QLabel(Ajouter_3);
        label_68->setObjectName("label_68");
        label_68->setGeometry(QRect(30, 300, 91, 21));
        label_68->setFont(font2);
        label_68->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_51 = new QLabel(Ajouter_3);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(30, 370, 49, 21));
        label_51->setFont(font2);
        label_51->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        btn_supprimer = new QPushButton(Ajouter_3);
        btn_supprimer->setObjectName("btn_supprimer");
        btn_supprimer->setGeometry(QRect(270, 670, 101, 51));
        btn_supprimer->setFont(font);
        btn_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        btn_modifier = new QPushButton(Ajouter_3);
        btn_modifier->setObjectName("btn_modifier");
        btn_modifier->setGeometry(QRect(140, 670, 101, 51));
        btn_modifier->setFont(font);
        btn_modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        btn_ajouter = new QPushButton(Ajouter_3);
        btn_ajouter->setObjectName("btn_ajouter");
        btn_ajouter->setGeometry(QRect(20, 670, 101, 51));
        btn_ajouter->setFont(font);
        btn_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        frame_4 = new QFrame(page);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(680, 40, 801, 401));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        label_52 = new QLabel(frame_4);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(10, 29, 211, 21));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font12.setPointSize(11);
        font12.setBold(true);
        label_52->setFont(font12);
        label_52->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        recherche_residents = new QLineEdit(frame_4);
        recherche_residents->setObjectName("recherche_residents");
        recherche_residents->setGeometry(QRect(240, 20, 201, 41));
        recherche_residents->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        tableView = new QTableView(frame_4);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 70, 601, 321));
        tableView->setStyleSheet(QString::fromUtf8("border-raduis : 20px;\n"
"color: rgb(0, 0, 0);\n"
"background-color : #e1e5ff;"));
        label_63 = new QLabel(frame_4);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(490, 30, 41, 21));
        label_63->setFont(font11);
        label_63->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        comboBox_tri = new QComboBox(frame_4);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(530, 30, 101, 21));
        comboBox_tri->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff;\n"
"color: rgb(0, 0, 0);"));
        labelMobilite = new QLabel(page);
        labelMobilite->setObjectName("labelMobilite");
        labelMobilite->setGeometry(QRect(680, 500, 561, 21));
        labelMobilite->setFont(font2);
        labelMobilite->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_stabilite = new QLabel(page);
        label_stabilite->setObjectName("label_stabilite");
        label_stabilite->setGeometry(QRect(680, 470, 561, 21));
        label_stabilite->setFont(font2);
        label_stabilite->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        btnExportPDF = new QPushButton(page);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setGeometry(QRect(690, 570, 111, 51));
        btnExportPDF->setFont(font);
        btnExportPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        btn_statistiques = new QPushButton(page);
        btn_statistiques->setObjectName("btn_statistiques");
        btn_statistiques->setGeometry(QRect(690, 650, 111, 51));
        btn_statistiques->setFont(font);
        btn_statistiques->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2D89EF;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        widget_stats = new QWidget(page);
        widget_stats->setObjectName("widget_stats");
        widget_stats->setGeometry(QRect(930, 510, 371, 211));
        stackedWidget->addWidget(page);
        leftmenu = new QFrame(centralwidget);
        leftmenu->setObjectName("leftmenu");
        leftmenu->setGeometry(QRect(0, -10, 191, 801));
        leftmenu->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        leftmenu->setFrameShape(QFrame::Shape::StyledPanel);
        leftmenu->setFrameShadow(QFrame::Shadow::Raised);
        label_23 = new QLabel(leftmenu);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(60, 30, 121, 31));
        label_23->setFont(font4);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RH = new QPushButton(leftmenu);
        RH->setObjectName("RH");
        RH->setGeometry(QRect(-10, 110, 171, 61));
        RH->setFont(font);
        RH->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        residence = new QPushButton(leftmenu);
        residence->setObjectName("residence");
        residence->setGeometry(QRect(0, 170, 181, 61));
        residence->setFont(font);
        residence->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        resident_2 = new QPushButton(leftmenu);
        resident_2->setObjectName("resident_2");
        resident_2->setGeometry(QRect(0, 230, 171, 61));
        resident_2->setFont(font);
        resident_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        Evenements_3 = new QPushButton(leftmenu);
        Evenements_3->setObjectName("Evenements_3");
        Evenements_3->setGeometry(QRect(0, 360, 181, 61));
        Evenements_3->setFont(font);
        Evenements_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        service_2 = new QPushButton(leftmenu);
        service_2->setObjectName("service_2");
        service_2->setGeometry(QRect(0, 290, 171, 61));
        service_2->setFont(font);
        service_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_24 = new QLabel(leftmenu);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 20, 51, 51));
        label_24->setTextFormat(Qt::TextFormat::MarkdownText);
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_24->setScaledContents(true);
        label_24->setWordWrap(false);
        label_24->setOpenExternalLinks(false);
        label_24->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        MainWindow->setCentralWidget(centralwidget);
        leftmenu->raise();
        stackedWidget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1367, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        trie->setText(QCoreApplication::translate("MainWindow", "Trie", nullptr));
        exporter->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        statistique->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        QTableWidgetItem *___qtablewidgetitem = affichage->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "IDR", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = affichage->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = affichage->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Addresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = affichage->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = affichage->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Nbr Habitants", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = affichage->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Nbr Unit\303\251s", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = affichage->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "responsabilite", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = affichage->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        recherche->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
#if QT_CONFIG(tooltip)
        search->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        search->setText(QCoreApplication::translate("MainWindow", "Recherche/Trie d'une r\303\251sidence", nullptr));
        label_38->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Ajouter une R\303\251sidence", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " Nom", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Nbr Habitants", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Nbr Unit\303\251s", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Date de constiction", nullptr));
        Id_Residence_2->setText(QString());
        Ajouter_Residence_2->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        Modifier_Residence_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        Supprimer_Residence->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        Exporter_2->setText(QCoreApplication::translate("MainWindow", "export", nullptr));
        Trier_2->setText(QCoreApplication::translate("MainWindow", "trier", nullptr));
#if QT_CONFIG(tooltip)
        Rechercher_Employe->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Rechercher_Employe->setText(QCoreApplication::translate("MainWindow", "rechercher un employ\303\251e", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "resident", nullptr));
        label_21->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        residence_2->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        resident_3->setText(QCoreApplication::translate("MainWindow", "resident", nullptr));
        Evenements_4->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        service_3->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_5->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ajouter un employee</p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "sexe", nullptr));
        Nom_Employe->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        Ajouter_Employe->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "responsabilite", nullptr));
        Modifier_Employe->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        Supprimer_Employe->setText(QCoreApplication::translate("MainWindow", "suprimer", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">rechcerche d'un employ\303\251e</p><p align=\"center\"><br/></p></body></html>", nullptr));
        Rechercher->setText(QCoreApplication::translate("MainWindow", "rechercher", nullptr));
        Statistiques_Employe->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetEmployes->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetEmployes->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "responsabilite", nullptr));
        label_39->setText(QString());
        label_64->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        RH_6->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        residence_7->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        resident_8->setText(QCoreApplication::translate("MainWindow", "resident", nullptr));
        Evenements_8->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_65->setText(QString());
        label_priority->setText(QCoreApplication::translate("MainWindow", "Priorit\303\251 :", nullptr));
        label_date->setText(QCoreApplication::translate("MainWindow", "Date :", nullptr));
        ajouterButton->setText(QCoreApplication::translate("MainWindow", "Ajouter \360\237\245\260", nullptr));
        label_resp->setText(QCoreApplication::translate("MainWindow", "Responsable :", nullptr));
        combo_priority->setItemText(0, QCoreApplication::translate("MainWindow", "Faible", nullptr));
        combo_priority->setItemText(1, QCoreApplication::translate("MainWindow", "Moyen", nullptr));
        combo_priority->setItemText(2, QCoreApplication::translate("MainWindow", "\303\211lev\303\251", nullptr));

        combo_type->setItemText(0, QCoreApplication::translate("MainWindow", "Transport", nullptr));
        combo_type->setItemText(1, QCoreApplication::translate("MainWindow", "Propret\303\251", nullptr));
        combo_type->setItemText(2, QCoreApplication::translate("MainWindow", "\303\211clairage", nullptr));
        combo_type->setItemText(3, QCoreApplication::translate("MainWindow", "Eau", nullptr));
        combo_type->setItemText(4, QCoreApplication::translate("MainWindow", "Sant\303\251", nullptr));
        combo_type->setItemText(5, QCoreApplication::translate("MainWindow", "S\303\251curit\303\251", nullptr));

        combo_state->setItemText(0, QCoreApplication::translate("MainWindow", "Actif", nullptr));
        combo_state->setItemText(1, QCoreApplication::translate("MainWindow", "En attente", nullptr));
        combo_state->setItemText(2, QCoreApplication::translate("MainWindow", "Suspendu", nullptr));

        label_type->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        label_budget->setText(QCoreApplication::translate("MainWindow", "Budget :", nullptr));
        supprimerButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        spin_budget->setPrefix(QCoreApplication::translate("MainWindow", "$ ", nullptr));
        label_state->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        label_id->setText(QCoreApplication::translate("MainWindow", "ID Service :", nullptr));
        modifierButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
#if QT_CONFIG(tooltip)
        Rechercher_Service->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Rechercher_Service->setText(QString());
        Rechercher_Services->setText(QCoreApplication::translate("MainWindow", "rechercher", nullptr));
        label_sort->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        combo_sort->setItemText(0, QCoreApplication::translate("MainWindow", "Budget", nullptr));
        combo_sort->setItemText(1, QCoreApplication::translate("MainWindow", "Priorit\303\251", nullptr));
        combo_sort->setItemText(2, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));

        btnIA->setText(QCoreApplication::translate("MainWindow", "Lancer IA", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableServices->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableServices->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableServices->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableServices->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableServices->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "piriorite ", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableServices->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "etat ", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableServices->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableServices->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "date", nullptr));

        const bool __sortingEnabled = tableServices->isSortingEnabled();
        tableServices->setSortingEnabled(false);
        tableServices->setSortingEnabled(__sortingEnabled);

        btnStats->setText(QCoreApplication::translate("MainWindow", "Afficher Statistiques  \360\237\214\270", nullptr));
        btnExportPDF_Services->setText(QCoreApplication::translate("MainWindow", "btnExportPDF", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        RH_3->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        service_4->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        Evenements->setText(QCoreApplication::translate("MainWindow", "Evenements", nullptr));
        resident_4->setText(QCoreApplication::translate("MainWindow", "R\303\251sident", nullptr));
        label_61->setText(QString());
        residence_5->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Ajouter un Ev\303\251nement", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Lieu", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Heure", nullptr));
        ID->setText(QString());
        label_34->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        Ajouterbutton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Nbr Participants", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Id Employe", nullptr));
        ID_Employe_Evenement->setText(QString());
        Modifier_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        Supprimer_2->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Rechercher Un Evenement", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Choisir de trier par", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Date", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Nombre d'inscrits", nullptr));

        Excel->setText(QCoreApplication::translate("MainWindow", "Exporter En Excel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Pr\303\251diction D'impact ", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Identifiant Ev\303\251nement", nullptr));
        Prediction->setText(QCoreApplication::translate("MainWindow", "Pr\303\251dire", nullptr));
        Dioxyde->setText(QString());
        label_41->setText(QCoreApplication::translate("MainWindow", "Localisation de l'evenement", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Identifiant Ev\303\251nement", nullptr));
        Localiser->setText(QCoreApplication::translate("MainWindow", "Localiser", nullptr));
        btnItineraire->setText(QCoreApplication::translate("MainWindow", "Itin\303\251raire", nullptr));
        label_43->setText(QString());
        label_54->setText(QCoreApplication::translate("MainWindow", "Cin\303\251ma", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "Autre", nullptr));
        label_56->setText(QString());
        label_57->setText(QCoreApplication::translate("MainWindow", "Musique", nullptr));
        label_58->setText(QString());
        Statistiques_Evenement->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Fonctionnalites), QCoreApplication::translate("MainWindow", "Fonctionnalit\303\251s", nullptr));
        lineEditCodeRecu->setText(QString());
        lineEditNouveauPass->setText(QString());
        label_131->setText(QString());
        textBrowser_18->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">entrer le code </span></p></body></html>", nullptr));
        pushButtonValiderReset->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        label_132->setText(QString());
        textBrowser_17->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">Nouveau mot de pass</span></p></body></html>", nullptr));
        pushButtonRetourLogin_3->setText(QCoreApplication::translate("MainWindow", "retour", nullptr));
        textBrowser_20->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:700; color:#3668f2;\"> Restaurer votre  compte</span></p></body></html>", nullptr));
        lineEditMdpId->setText(QString());
        textBrowser_15->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:700; color:#3668f2;\"> Restaurer votre  compte</span></p></body></html>", nullptr));
        lineEditMdpEmail->setText(QString());
        label_66->setText(QString());
        pushButtonSuivant->setText(QCoreApplication::translate("MainWindow", "suivant", nullptr));
        pushButtonRetourLogin_2->setText(QCoreApplication::translate("MainWindow", "retour", nullptr));
        label_67->setText(QString());
        lineEditMdpUsername->setText(QString());
        textBrowser_14->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">ID</span></p></body></html>", nullptr));
        textBrowser_16->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">Nom d'utilisateur</span></p></body></html>", nullptr));
        textBrowser_19->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">E_mail</span></p></body></html>", nullptr));
        label_128->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; color:#3668f2;\">Bienvenu \303\240 neocity</span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#3668f2;\">ID</span></p></body></html>", nullptr));
        label_129->setText(QString());
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#3668f2;\">Mot de pass</span></p></body></html>", nullptr));
        label_130->setText(QString());
        quitter->setText(QCoreApplication::translate("MainWindow", "quitter", nullptr));
        lineEditLoginUsername->setText(QString());
        lineEditLoginPassword->setText(QString());
        connecter->setText(QCoreApplication::translate("MainWindow", "connecter", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonGoToMdp->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>mot de pass oublier</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonGoToMdp->setText(QCoreApplication::translate("MainWindow", "mot de pass oublier !!", nullptr));
        label->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        RH_2->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        residence_3->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        resident->setText(QCoreApplication::translate("MainWindow", "resident", nullptr));
        Evenements_2->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        service->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_53->setText(QString());
        pushButton_149->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_293->setText(QString());
        label_45->setText(QCoreApplication::translate("MainWindow", "Ajouter un r\303\251sident", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "ID resident", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "profession", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "Situation familiale", nullptr));
        lineEdit_idresident->setText(QString());
        label_50->setText(QCoreApplication::translate("MainWindow", "Sexe", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        btn_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btn_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btn_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "Rechercher Un resident", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "Age", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("MainWindow", "Sex", nullptr));

        labelMobilite->setText(QCoreApplication::translate("MainWindow", "Indice de mobilit\303\251 :", nullptr));
        label_stabilite->setText(QCoreApplication::translate("MainWindow", "Stabilit\303\251 sociale :", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        btn_statistiques->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        RH->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        residence->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        resident_2->setText(QCoreApplication::translate("MainWindow", "Resident", nullptr));
        Evenements_3->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        service_2->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_24->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
