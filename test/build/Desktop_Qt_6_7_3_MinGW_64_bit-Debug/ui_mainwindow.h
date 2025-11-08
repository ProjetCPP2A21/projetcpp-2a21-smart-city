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
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QFrame *Ajouter;
    QLabel *label_12;
    QLabel *label_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_adresse;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_nbrHabitants;
    QLabel *label_16;
    QLineEdit *lineEdit_nbrUnit;
    QLineEdit *lineEdit_id;
    QLabel *label_17;
    QPushButton *pushButton_add;
    QPushButton *pushButton_update;
    QPushButton *pushButton_delete;
    QLineEdit *lineEdit_etat;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit_date;
    QPushButton *ajouter_3;
    QPushButton *supprimer_2;
    QFrame *frame_2;
    QLabel *label_23;
    QPushButton *RH;
    QPushButton *residence;
    QPushButton *pushButton_13;
    QLabel *label_24;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *supprimer_3;
    QTableWidget *affichage;
    QPushButton *ajouter_2;
    QLineEdit *lineEditRecherche_2;
    QWidget *page_4;
    QPushButton *pushButton_23;
    QPushButton *pushButton_21;
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
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QLabel *label_5;
    QFrame *Ajouter_2;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEditPrenom_2;
    QLineEdit *lineEditID_2;
    QLineEdit *lineEditTelephone_2;
    QLineEdit *lineEditSalaire_2;
    QLabel *label_25;
    QLineEdit *lineEditSexe_2;
    QLineEdit *lineEditNom_2;
    QLabel *label_11;
    QLabel *label_26;
    QLineEdit *lineEditTache_2;
    QPushButton *Modifier;
    QPushButton *Supprimer;
    QPushButton *ajouter;
    QLabel *label_27;
    QPushButton *rechercher;
    QPushButton *pushButton_19;
    QTableWidget *tableWidgetEmployes;
    QGraphicsView *graphicsView;
    QLineEdit *lineEditRecherche;
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
        stackedWidget->setGeometry(QRect(0, 0, 1341, 768));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        Ajouter = new QFrame(page_3);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(210, -10, 361, 761));
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
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Ajouter);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 120, 81, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(Ajouter);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 220, 49, 21));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_14 = new QLabel(Ajouter);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 170, 91, 21));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(Ajouter);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 270, 141, 21));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_nom = new QLineEdit(Ajouter);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(170, 120, 141, 41));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_adresse = new QLineEdit(Ajouter);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(170, 170, 141, 41));
        lineEdit_adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_type = new QLineEdit(Ajouter);
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(170, 220, 141, 41));
        lineEdit_type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_nbrHabitants = new QLineEdit(Ajouter);
        lineEdit_nbrHabitants->setObjectName("lineEdit_nbrHabitants");
        lineEdit_nbrHabitants->setGeometry(QRect(170, 270, 141, 41));
        lineEdit_nbrHabitants->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_16 = new QLabel(Ajouter);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 330, 121, 16));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_nbrUnit = new QLineEdit(Ajouter);
        lineEdit_nbrUnit->setObjectName("lineEdit_nbrUnit");
        lineEdit_nbrUnit->setGeometry(QRect(170, 320, 141, 41));
        lineEdit_nbrUnit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_id = new QLineEdit(Ajouter);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(170, 70, 141, 41));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_17 = new QLabel(Ajouter);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 80, 81, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setPointSize(11);
        font2.setBold(true);
        label_17->setFont(font2);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_add = new QPushButton(Ajouter);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(120, 530, 101, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift")});
        font3.setBold(true);
        pushButton_add->setFont(font3);
        pushButton_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_update = new QPushButton(Ajouter);
        pushButton_update->setObjectName("pushButton_update");
        pushButton_update->setGeometry(QRect(10, 530, 101, 41));
        pushButton_update->setFont(font3);
        pushButton_update->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_delete = new QPushButton(Ajouter);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(230, 530, 101, 41));
        pushButton_delete->setFont(font3);
        pushButton_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_etat = new QLineEdit(Ajouter);
        lineEdit_etat->setObjectName("lineEdit_etat");
        lineEdit_etat->setGeometry(QRect(170, 370, 141, 41));
        lineEdit_etat->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_18 = new QLabel(Ajouter);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 390, 131, 16));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_19 = new QLabel(Ajouter);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 440, 51, 16));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_date = new QLineEdit(Ajouter);
        lineEdit_date->setObjectName("lineEdit_date");
        lineEdit_date->setGeometry(QRect(170, 420, 141, 41));
        lineEdit_date->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        ajouter_3 = new QPushButton(page_3);
        ajouter_3->setObjectName("ajouter_3");
        ajouter_3->setGeometry(QRect(990, 60, 91, 31));
        ajouter_3->setFont(font3);
        ajouter_3->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        supprimer_2 = new QPushButton(page_3);
        supprimer_2->setObjectName("supprimer_2");
        supprimer_2->setGeometry(QRect(1050, 420, 91, 31));
        supprimer_2->setFont(font3);
        supprimer_2->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        frame_2 = new QFrame(page_3);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, -30, 211, 791));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_23 = new QLabel(frame_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(80, 50, 121, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bahnschrift")});
        font4.setPointSize(18);
        font4.setBold(true);
        label_23->setFont(font4);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RH = new QPushButton(frame_2);
        RH->setObjectName("RH");
        RH->setGeometry(QRect(0, 130, 131, 61));
        RH->setFont(font3);
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
        residence = new QPushButton(frame_2);
        residence->setObjectName("residence");
        residence->setGeometry(QRect(10, 190, 171, 61));
        residence->setFont(font3);
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
        pushButton_13 = new QPushButton(frame_2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(0, 250, 171, 61));
        pushButton_13->setFont(font3);
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_24 = new QLabel(frame_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 30, 61, 61));
        label_24->setStyleSheet(QString::fromUtf8("image: url(:/cropped_circle_image.png);"));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_24->setScaledContents(true);
        pushButton_14 = new QPushButton(frame_2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(0, 370, 181, 61));
        pushButton_14->setFont(font3);
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_15 = new QPushButton(frame_2);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(0, 310, 171, 61));
        pushButton_15->setFont(font3);
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        supprimer_3 = new QPushButton(page_3);
        supprimer_3->setObjectName("supprimer_3");
        supprimer_3->setGeometry(QRect(1050, 480, 91, 31));
        supprimer_3->setFont(font3);
        supprimer_3->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
"background-color : #e1e5ff;"));
        ajouter_2 = new QPushButton(page_3);
        ajouter_2->setObjectName("ajouter_2");
        ajouter_2->setGeometry(QRect(890, 60, 91, 31));
        ajouter_2->setFont(font3);
        ajouter_2->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        lineEditRecherche_2 = new QLineEdit(page_3);
        lineEditRecherche_2->setObjectName("lineEditRecherche_2");
        lineEditRecherche_2->setGeometry(QRect(590, 50, 291, 41));
        lineEditRecherche_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        pushButton_23 = new QPushButton(page_4);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(1240, 400, 101, 51));
        pushButton_23->setFont(font3);
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_21 = new QPushButton(page_4);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(1040, 70, 101, 51));
        pushButton_21->setFont(font3);
        pushButton_21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_20->setFont(font4);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 130, 131, 61));
        pushButton->setFont(font3);
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
        pushButton_5->setFont(font3);
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
        pushButton_7->setFont(font3);
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
        pushButton_9->setFont(font3);
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
        pushButton_10->setFont(font3);
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
        label_22->setGeometry(QRect(70, 40, 121, 31));
        label_22->setFont(font4);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 130, 131, 61));
        pushButton_2->setFont(font3);
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
        residence_2->setFont(font3);
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
        pushButton_16 = new QPushButton(frame_3);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(0, 250, 171, 61));
        pushButton_16->setFont(font3);
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_17 = new QPushButton(frame_3);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(0, 370, 181, 61));
        pushButton_17->setFont(font3);
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_18 = new QPushButton(frame_3);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(0, 310, 171, 61));
        pushButton_18->setFont(font3);
        pushButton_18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_5->setGeometry(QRect(10, 30, 51, 51));
        label_5->setTextFormat(Qt::TextFormat::MarkdownText);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_5->setScaledContents(true);
        label_5->setWordWrap(false);
        label_5->setOpenExternalLinks(false);
        label_5->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        Ajouter_2 = new QFrame(page_4);
        Ajouter_2->setObjectName("Ajouter_2");
        Ajouter_2->setGeometry(QRect(220, -10, 381, 791));
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
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(Ajouter_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 170, 71, 21));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(Ajouter_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 230, 49, 21));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(Ajouter_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 290, 101, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(Ajouter_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 350, 71, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEditPrenom_2 = new QLineEdit(Ajouter_2);
        lineEditPrenom_2->setObjectName("lineEditPrenom_2");
        lineEditPrenom_2->setGeometry(QRect(170, 160, 141, 41));
        lineEditPrenom_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEditID_2 = new QLineEdit(Ajouter_2);
        lineEditID_2->setObjectName("lineEditID_2");
        lineEditID_2->setGeometry(QRect(170, 220, 141, 41));
        lineEditID_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEditTelephone_2 = new QLineEdit(Ajouter_2);
        lineEditTelephone_2->setObjectName("lineEditTelephone_2");
        lineEditTelephone_2->setGeometry(QRect(170, 280, 141, 41));
        lineEditTelephone_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEditSalaire_2 = new QLineEdit(Ajouter_2);
        lineEditSalaire_2->setObjectName("lineEditSalaire_2");
        lineEditSalaire_2->setGeometry(QRect(170, 340, 141, 41));
        lineEditSalaire_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_25->setGeometry(QRect(10, 420, 61, 16));
        label_25->setFont(font1);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEditSexe_2 = new QLineEdit(Ajouter_2);
        lineEditSexe_2->setObjectName("lineEditSexe_2");
        lineEditSexe_2->setGeometry(QRect(170, 410, 141, 41));
        lineEditSexe_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEditNom_2 = new QLineEdit(Ajouter_2);
        lineEditNom_2->setObjectName("lineEditNom_2");
        lineEditNom_2->setGeometry(QRect(170, 100, 141, 41));
        lineEditNom_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_11->setGeometry(QRect(10, 110, 131, 21));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(Ajouter_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 470, 141, 31));
        label_26->setFont(font1);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEditTache_2 = new QLineEdit(Ajouter_2);
        lineEditTache_2->setObjectName("lineEditTache_2");
        lineEditTache_2->setGeometry(QRect(170, 470, 141, 41));
        lineEditTache_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Modifier = new QPushButton(Ajouter_2);
        Modifier->setObjectName("Modifier");
        Modifier->setGeometry(QRect(140, 540, 101, 51));
        Modifier->setFont(font3);
        Modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Supprimer = new QPushButton(Ajouter_2);
        Supprimer->setObjectName("Supprimer");
        Supprimer->setGeometry(QRect(260, 540, 101, 51));
        Supprimer->setFont(font3);
        Supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ajouter = new QPushButton(Ajouter_2);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(20, 540, 101, 51));
        ajouter->setFont(font3);
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_27->setGeometry(QRect(600, 30, 301, 31));
        label_27->setFont(font);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        rechercher = new QPushButton(page_4);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(930, 70, 101, 51));
        rechercher->setFont(font3);
        rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_19 = new QPushButton(page_4);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(1180, 710, 101, 51));
        pushButton_19->setFont(font3);
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        graphicsView = new QGraphicsView(page_4);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(630, 440, 521, 321));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/statisque.png);"));
        lineEditRecherche = new QLineEdit(page_4);
        lineEditRecherche->setObjectName("lineEditRecherche");
        lineEditRecherche->setGeometry(QRect(630, 80, 291, 41));
        lineEditRecherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1367, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Ajouter une R\303\251sidence", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " Nom", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Nbr Habitants", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Nbr Unit\303\251s", nullptr));
        lineEdit_id->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_update->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Date de constiction", nullptr));
        ajouter_3->setText(QCoreApplication::translate("MainWindow", "Trie", nullptr));
        supprimer_2->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        RH->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        residence->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Resident", nullptr));
        label_24->setText(QString());
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        supprimer_3->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
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
        ajouter_2->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
#if QT_CONFIG(tooltip)
        lineEditRecherche_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditRecherche_2->setText(QString());
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "export", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "trier", nullptr));
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
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "resident", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_5->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ajouter un employee</p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "sexe", nullptr));
        lineEditNom_2->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "responsabilite", nullptr));
        Modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        Supprimer->setText(QCoreApplication::translate("MainWindow", "suprimer", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">rechcerche d'un employ\303\251e</p><p align=\"center\"><br/></p></body></html>", nullptr));
        rechercher->setText(QCoreApplication::translate("MainWindow", "rechercher", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetEmployes->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetEmployes->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "responsabilite", nullptr));
#if QT_CONFIG(tooltip)
        lineEditRecherche->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditRecherche->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
