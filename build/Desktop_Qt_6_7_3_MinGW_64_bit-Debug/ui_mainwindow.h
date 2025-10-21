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
#include <QtWidgets/QComboBox>
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
    QLineEdit *Nom;
    QLineEdit *Type;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_16;
    QLineEdit *lineEdit_7;
    QLineEdit *Nom_2;
    QLabel *label_17;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_8;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit_9;
    QPushButton *ajouter_3;
    QPushButton *supprimer_2;
    QFrame *frame_2;
    QLabel *label_23;
    QPushButton *RH;
    QPushButton *residence;
    QPushButton *resident_2;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_24;
    QPushButton *supprimer_3;
    QTableWidget *affichage;
    QPushButton *ajouter_2;
    QLineEdit *Nom_3;
    QLabel *label_38;
    QWidget *page_4;
    QPushButton *pushButton_23;
    QPushButton *pushButton_21;
    QLineEdit *Nom_6;
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
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QLabel *label_5;
    QFrame *Ajouter_2;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *Nom_4;
    QLineEdit *Type_2;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLabel *label_25;
    QLineEdit *lineEdit_10;
    QLineEdit *Nom_5;
    QLabel *label_11;
    QPushButton *pushButton_6;
    QLabel *label_26;
    QLineEdit *lineEdit_11;
    QPushButton *pushButton_20;
    QLabel *label_27;
    QPushButton *pushButton_22;
    QPushButton *pushButton_19;
    QTableWidget *tableWidget;
    QGraphicsView *graphicsView;
    QLabel *label_39;
    QWidget *page;
    QFrame *frame_5;
    QLabel *label_32;
    QPushButton *RH_2;
    QPushButton *residence_3;
    QPushButton *resident;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QLabel *label_53;
    QLabel *label_6;
    QPushButton *pushButton_30;
    QFrame *Ajouter_3;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLineEdit *Nom_9;
    QLineEdit *Type_5;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *Nom_10;
    QLabel *label_49;
    QPushButton *pushButton_31;
    QLabel *label_50;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QFrame *frame_4;
    QComboBox *comboBox_3;
    QLabel *label_51;
    QLabel *label_52;
    QLineEdit *lineEdit_19;
    QTableWidget *tableWidget_3;
    QPushButton *pushButton_34;
    QGraphicsView *graphicsView_2;
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
        Nom = new QLineEdit(Ajouter);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(170, 120, 141, 41));
        Nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Type = new QLineEdit(Ajouter);
        Type->setObjectName("Type");
        Type->setGeometry(QRect(170, 170, 141, 41));
        Type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_3 = new QLineEdit(Ajouter);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(170, 220, 141, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_4 = new QLineEdit(Ajouter);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(170, 270, 141, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_7 = new QLineEdit(Ajouter);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(170, 320, 141, 41));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Nom_2 = new QLineEdit(Ajouter);
        Nom_2->setObjectName("Nom_2");
        Nom_2->setGeometry(QRect(170, 70, 141, 41));
        Nom_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton_3 = new QPushButton(Ajouter);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(120, 530, 101, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift")});
        font3.setBold(true);
        pushButton_3->setFont(font3);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_8 = new QPushButton(Ajouter);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(10, 530, 101, 41));
        pushButton_8->setFont(font3);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_4 = new QPushButton(Ajouter);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(230, 530, 101, 41));
        pushButton_4->setFont(font3);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_8 = new QLineEdit(Ajouter);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(170, 370, 141, 41));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_19->setGeometry(QRect(20, 450, 51, 16));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_9 = new QLineEdit(Ajouter);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(170, 420, 141, 41));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        resident_2 = new QPushButton(frame_2);
        resident_2->setObjectName("resident_2");
        resident_2->setGeometry(QRect(0, 250, 171, 61));
        resident_2->setFont(font3);
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
        label_24 = new QLabel(frame_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 40, 51, 51));
        label_24->setTextFormat(Qt::TextFormat::MarkdownText);
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_24->setScaledContents(true);
        label_24->setWordWrap(false);
        label_24->setOpenExternalLinks(false);
        label_24->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
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
"background-color : #111111;"));
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
        Nom_3 = new QLineEdit(page_3);
        Nom_3->setObjectName("Nom_3");
        Nom_3->setGeometry(QRect(590, 50, 291, 41));
        Nom_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_38 = new QLabel(page_3);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(560, -21, 791, 791));
        label_38->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page_3);
        label_38->raise();
        Ajouter->raise();
        ajouter_3->raise();
        supprimer_2->raise();
        frame_2->raise();
        supprimer_3->raise();
        affichage->raise();
        ajouter_2->raise();
        Nom_3->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        pushButton_23 = new QPushButton(page_4);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(1210, 400, 101, 51));
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
        Nom_6 = new QLineEdit(page_4);
        Nom_6->setObjectName("Nom_6");
        Nom_6->setGeometry(QRect(620, 80, 291, 41));
        Nom_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        resident_3 = new QPushButton(frame_3);
        resident_3->setObjectName("resident_3");
        resident_3->setGeometry(QRect(0, 250, 171, 61));
        resident_3->setFont(font3);
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
        Ajouter_2->setGeometry(QRect(190, -10, 381, 801));
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
        Nom_4 = new QLineEdit(Ajouter_2);
        Nom_4->setObjectName("Nom_4");
        Nom_4->setGeometry(QRect(170, 160, 141, 41));
        Nom_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Type_2 = new QLineEdit(Ajouter_2);
        Type_2->setObjectName("Type_2");
        Type_2->setGeometry(QRect(170, 220, 141, 41));
        Type_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_5 = new QLineEdit(Ajouter_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(170, 280, 141, 41));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        lineEdit_6 = new QLineEdit(Ajouter_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(170, 340, 141, 41));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_10 = new QLineEdit(Ajouter_2);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(170, 410, 141, 41));
        lineEdit_10->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        Nom_5 = new QLineEdit(Ajouter_2);
        Nom_5->setObjectName("Nom_5");
        Nom_5->setGeometry(QRect(170, 100, 141, 41));
        Nom_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton_6 = new QPushButton(Ajouter_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(70, 540, 101, 51));
        pushButton_6->setFont(font3);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_26->setGeometry(QRect(10, 470, 141, 31));
        label_26->setFont(font1);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_11 = new QLineEdit(Ajouter_2);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(170, 470, 141, 41));
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButton_20 = new QPushButton(Ajouter_2);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(190, 540, 101, 51));
        pushButton_20->setFont(font3);
        pushButton_20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_22 = new QPushButton(page_4);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(930, 70, 101, 51));
        pushButton_22->setFont(font3);
        pushButton_22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_19->setGeometry(QRect(1180, 650, 101, 51));
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
        tableWidget = new QTableWidget(page_4);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(600, 140, 711, 241));
        graphicsView = new QGraphicsView(page_4);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(630, 390, 521, 321));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/statisque.png);"));
        label_39 = new QLabel(page_4);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(570, -11, 791, 751));
        label_39->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page_4);
        label_39->raise();
        pushButton_23->raise();
        pushButton_21->raise();
        Nom_6->raise();
        frame->raise();
        Ajouter_2->raise();
        label_27->raise();
        pushButton_22->raise();
        pushButton_19->raise();
        tableWidget->raise();
        graphicsView->raise();
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
        label_32->setGeometry(QRect(90, 40, 121, 31));
        label_32->setFont(font4);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RH_2 = new QPushButton(frame_5);
        RH_2->setObjectName("RH_2");
        RH_2->setGeometry(QRect(20, 130, 131, 61));
        RH_2->setFont(font3);
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
        residence_3->setGeometry(QRect(10, 190, 171, 61));
        residence_3->setFont(font3);
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
        resident->setGeometry(QRect(0, 250, 171, 61));
        resident->setFont(font3);
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
        pushButton_25 = new QPushButton(frame_5);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(0, 370, 181, 61));
        pushButton_25->setFont(font3);
        pushButton_25->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_26 = new QPushButton(frame_5);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(0, 310, 171, 61));
        pushButton_26->setFont(font3);
        pushButton_26->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_53->setGeometry(QRect(20, 20, 51, 51));
        label_53->setTextFormat(Qt::TextFormat::MarkdownText);
        label_53->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_53->setScaledContents(true);
        label_53->setWordWrap(false);
        label_53->setOpenExternalLinks(false);
        label_53->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(640, 0, 701, 771));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_30 = new QPushButton(page);
        pushButton_30->setObjectName("pushButton_30");
        pushButton_30->setGeometry(QRect(690, 611, 101, 51));
        pushButton_30->setFont(font3);
        pushButton_30->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Ajouter_3 = new QFrame(page);
        Ajouter_3->setObjectName("Ajouter_3");
        Ajouter_3->setGeometry(QRect(210, -10, 451, 801));
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
        label_44 = new QLabel(Ajouter_3);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(120, 20, 211, 16));
        label_44->setFont(font);
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_45 = new QLabel(Ajouter_3);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(30, 170, 49, 21));
        label_45->setFont(font1);
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_46 = new QLabel(Ajouter_3);
        label_46->setObjectName("label_46");
        label_46->setGeometry(QRect(30, 230, 49, 21));
        label_46->setFont(font1);
        label_46->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_47 = new QLabel(Ajouter_3);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(10, 420, 191, 21));
        label_47->setFont(font1);
        label_47->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_48 = new QLabel(Ajouter_3);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(30, 350, 111, 31));
        label_48->setFont(font1);
        label_48->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Nom_9 = new QLineEdit(Ajouter_3);
        Nom_9->setObjectName("Nom_9");
        Nom_9->setGeometry(QRect(230, 160, 141, 41));
        Nom_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Type_5 = new QLineEdit(Ajouter_3);
        Type_5->setObjectName("Type_5");
        Type_5->setGeometry(QRect(230, 220, 141, 41));
        Type_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_16 = new QLineEdit(Ajouter_3);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(230, 280, 141, 41));
        lineEdit_16->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_17 = new QLineEdit(Ajouter_3);
        lineEdit_17->setObjectName("lineEdit_17");
        lineEdit_17->setGeometry(QRect(230, 340, 141, 41));
        lineEdit_17->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_18 = new QLineEdit(Ajouter_3);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(230, 410, 141, 41));
        lineEdit_18->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Nom_10 = new QLineEdit(Ajouter_3);
        Nom_10->setObjectName("Nom_10");
        Nom_10->setGeometry(QRect(230, 100, 141, 41));
        Nom_10->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_49 = new QLabel(Ajouter_3);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(20, 110, 131, 21));
        label_49->setFont(font2);
        label_49->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_31 = new QPushButton(Ajouter_3);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setGeometry(QRect(130, 520, 101, 51));
        pushButton_31->setFont(font3);
        pushButton_31->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_50 = new QLabel(Ajouter_3);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(30, 290, 61, 16));
        label_50->setFont(font1);
        label_50->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_32 = new QPushButton(Ajouter_3);
        pushButton_32->setObjectName("pushButton_32");
        pushButton_32->setGeometry(QRect(260, 520, 101, 51));
        pushButton_32->setFont(font3);
        pushButton_32->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_33 = new QPushButton(Ajouter_3);
        pushButton_33->setObjectName("pushButton_33");
        pushButton_33->setGeometry(QRect(10, 520, 101, 51));
        pushButton_33->setFont(font3);
        pushButton_33->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame_4->setGeometry(QRect(660, 40, 801, 401));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        comboBox_3 = new QComboBox(frame_4);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(610, 30, 101, 21));
        comboBox_3->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff;\n"
"color: rgb(0, 0, 0);"));
        label_51 = new QLabel(frame_4);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(560, 30, 41, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Bahnschrift")});
        font5.setPointSize(11);
        font5.setBold(true);
        label_51->setFont(font5);
        label_51->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_52 = new QLabel(frame_4);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(10, 29, 211, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font6.setPointSize(11);
        font6.setBold(true);
        label_52->setFont(font6);
        label_52->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_19 = new QLineEdit(frame_4);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setGeometry(QRect(240, 20, 201, 41));
        lineEdit_19->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        tableWidget_3 = new QTableWidget(frame_4);
        if (tableWidget_3->columnCount() < 6)
            tableWidget_3->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(40, 80, 601, 321));
        tableWidget_3->setStyleSheet(QString::fromUtf8("border-raduis : 20px;\n"
"color: rgb(0, 0, 0);\n"
"background-color : #e1e5ff;"));
        pushButton_34 = new QPushButton(frame_4);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setGeometry(QRect(450, 20, 91, 41));
        pushButton_34->setFont(font3);
        pushButton_34->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        graphicsView_2 = new QGraphicsView(page);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(870, 470, 311, 192));
        graphicsView_2->setStyleSheet(QString::fromUtf8("border-image: url(:/diagramme_circulaire3.png);"));
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1367, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


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
        Nom_2->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Date de constiction", nullptr));
        ajouter_3->setText(QCoreApplication::translate("MainWindow", "Trie", nullptr));
        supprimer_2->setText(QCoreApplication::translate("MainWindow", "Exporter", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        RH->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        residence->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        resident_2->setText(QCoreApplication::translate("MainWindow", "Resident", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_24->setText(QString());
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
        Nom_3->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Nom_3->setText(QCoreApplication::translate("MainWindow", "Recherche/Trie d'une r\303\251sidence", nullptr));
        label_38->setText(QString());
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "export", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "trier", nullptr));
#if QT_CONFIG(tooltip)
        Nom_6->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Nom_6->setText(QCoreApplication::translate("MainWindow", "rechercher un employ\303\251e", nullptr));
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
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_5->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ajouter un employee</p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "sexe", nullptr));
        Nom_5->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "responsabilite", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">rechcerche d'un employ\303\251e</p><p align=\"center\"><br/></p></body></html>", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "rechercher", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "responsabilite", nullptr));
        label_39->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "NEOCITY", nullptr));
        RH_2->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        residence_3->setText(QCoreApplication::translate("MainWindow", "R\303\251sidence", nullptr));
        resident->setText(QCoreApplication::translate("MainWindow", "resident", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "Evenement", nullptr));
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        label_53->setText(QString());
        label_6->setText(QString());
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Ajouter un r\303\251sidents", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "Situation familiale", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "profession", nullptr));
        Nom_10->setText(QString());
        label_49->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "Sexe", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Age", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Sex", nullptr));
        comboBox_3->setItemText(3, QString());

        label_51->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "Rechercher Un Evenement", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Identifiant unique", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Profession", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Situation familiale", nullptr));
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
