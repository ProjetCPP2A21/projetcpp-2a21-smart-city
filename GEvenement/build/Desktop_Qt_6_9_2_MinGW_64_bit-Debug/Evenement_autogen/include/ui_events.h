/********************************************************************************
** Form generated from reading UI file 'events.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTS_H
#define UI_EVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Events
{
public:
    QWidget *centralwidget;
    QFrame *frame_4;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *Nom;
    QLineEdit *Type;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_13;
    QLineEdit *lineEdit_7;
    QLineEdit *Nom_2;
    QLabel *label_11;
    QPushButton *pushButton_3;
    QLabel *label_14;
    QLineEdit *lineEdit;
    QFrame *frame_3;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QFrame *line_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_16;
    QLabel *label_15;
    QPushButton *pushButton_4;
    QPushButton *Fonctionnalit;
    QPushButton *pushButton_6;
    QFrame *line;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QFrame *line_15;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Events)
    {
        if (Events->objectName().isEmpty())
            Events->setObjectName("Events");
        Events->resize(1366, 768);
        Events->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color : #e1e5ff;\n"
"}"));
        centralwidget = new QWidget(Events);
        centralwidget->setObjectName("centralwidget");
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 160, 401, 571));
        frame_4->setStyleSheet(QString::fromUtf8("\n"
"QFrame {\n"
"background-color : #2C3E50;\n"
" border-radius: 20px\n"
"}\n"
""));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        label_10 = new QLabel(frame_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 20, 211, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 170, 49, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(frame_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 230, 49, 21));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(frame_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 290, 49, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_9 = new QLabel(frame_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 350, 49, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Nom = new QLineEdit(frame_4);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(170, 160, 141, 41));
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
        Type = new QLineEdit(frame_4);
        Type->setObjectName("Type");
        Type->setGeometry(QRect(170, 220, 141, 41));
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
        lineEdit_3 = new QLineEdit(frame_4);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(170, 280, 141, 41));
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
        lineEdit_4 = new QLineEdit(frame_4);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(170, 340, 141, 41));
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
        label_13 = new QLabel(frame_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 420, 61, 16));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_7 = new QLineEdit(frame_4);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(170, 410, 141, 41));
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
        Nom_2 = new QLineEdit(frame_4);
        Nom_2->setObjectName("Nom_2");
        Nom_2->setGeometry(QRect(170, 100, 141, 41));
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
        label_11 = new QLabel(frame_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 110, 131, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setPointSize(11);
        font2.setBold(true);
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(150, 480, 101, 51));
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
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(910, 660, 201, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font4.setPointSize(11);
        font4.setBold(true);
        label_14->setFont(font4);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(1130, 650, 171, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(660, 170, 701, 441));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_6 = new QLineEdit(frame_3);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(400, 10, 201, 41));
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
        label_12 = new QLabel(frame_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(170, 19, 211, 21));
        label_12->setFont(font4);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_2 = new QFrame(frame_3);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 130, 701, 16));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 100, 71, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Bahnschrift")});
        font5.setPointSize(11);
        font5.setBold(true);
        label->setFont(font5);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 100, 51, 16));
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(300, 100, 51, 16));
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(410, 100, 51, 16));
        label_5->setFont(font5);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(frame_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(520, 100, 41, 16));
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_16 = new QLabel(frame_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(630, 100, 41, 16));
        label_16->setFont(font5);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(630, 650, 41, 41));
        label_15->setFont(font4);
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/download-icon-png-4384.png")));
        label_15->setScaledContents(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(470, 650, 131, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font6.setBold(true);
        pushButton_4->setFont(font6);
        pushButton_4->setAutoFillBackground(false);
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
"}\n"
""));
        Fonctionnalit = new QPushButton(centralwidget);
        Fonctionnalit->setObjectName("Fonctionnalit");
        Fonctionnalit->setGeometry(QRect(-10, 0, 181, 71));
        Fonctionnalit->setFont(font3);
        Fonctionnalit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color : #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(1200, 0, 171, 71));
        pushButton_6->setFont(font3);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color : #2C3E50;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1E5BB8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #FFFFFF;\n"
"}"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(160, 30, 281, 16));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(430, 30, 16, 161));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_6->setFrameShape(QFrame::Shape::VLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(430, 180, 191, 16));
        line_7->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(610, 30, 16, 161));
        line_8->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_8->setFrameShape(QFrame::Shape::VLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(610, 30, 611, 16));
        line_9->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_9->setFrameShape(QFrame::Shape::HLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName("line_10");
        line_10->setGeometry(QRect(530, 180, 16, 481));
        line_10->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_10->setFrameShape(QFrame::Shape::VLine);
        line_10->setFrameShadow(QFrame::Shadow::Sunken);
        line_11 = new QFrame(centralwidget);
        line_11->setObjectName("line_11");
        line_11->setGeometry(QRect(460, 400, 151, 16));
        line_11->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_11->setFrameShape(QFrame::Shape::HLine);
        line_11->setFrameShadow(QFrame::Shadow::Sunken);
        line_12 = new QFrame(centralwidget);
        line_12->setObjectName("line_12");
        line_12->setGeometry(QRect(460, 400, 16, 71));
        line_12->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_12->setFrameShape(QFrame::Shape::VLine);
        line_12->setFrameShadow(QFrame::Shadow::Sunken);
        line_13 = new QFrame(centralwidget);
        line_13->setObjectName("line_13");
        line_13->setGeometry(QRect(390, 460, 81, 16));
        line_13->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_13->setFrameShape(QFrame::Shape::HLine);
        line_13->setFrameShadow(QFrame::Shadow::Sunken);
        line_14 = new QFrame(centralwidget);
        line_14->setObjectName("line_14");
        line_14->setGeometry(QRect(600, 400, 16, 71));
        line_14->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_14->setFrameShape(QFrame::Shape::VLine);
        line_14->setFrameShadow(QFrame::Shadow::Sunken);
        line_15 = new QFrame(centralwidget);
        line_15->setObjectName("line_15");
        line_15->setGeometry(QRect(600, 460, 71, 16));
        line_15->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_15->setFrameShape(QFrame::Shape::HLine);
        line_15->setFrameShadow(QFrame::Shadow::Sunken);
        Events->setCentralWidget(centralwidget);
        line_15->raise();
        line_13->raise();
        line_11->raise();
        line_10->raise();
        line_9->raise();
        line->raise();
        line_6->raise();
        frame_3->raise();
        frame_4->raise();
        label_14->raise();
        lineEdit->raise();
        label_15->raise();
        pushButton_4->raise();
        Fonctionnalit->raise();
        pushButton_6->raise();
        line_7->raise();
        line_8->raise();
        line_12->raise();
        line_14->raise();
        menubar = new QMenuBar(Events);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1366, 22));
        Events->setMenuBar(menubar);
        statusbar = new QStatusBar(Events);
        statusbar->setObjectName("statusbar");
        Events->setStatusBar(statusbar);

        retranslateUi(Events);

        QMetaObject::connectSlotsByName(Events);
    } // setupUi

    void retranslateUi(QMainWindow *Events)
    {
        Events->setWindowTitle(QCoreApplication::translate("Events", "Events", nullptr));
        label_10->setText(QCoreApplication::translate("Events", "Ajouter un Ev\303\251nement", nullptr));
        label_2->setText(QCoreApplication::translate("Events", "Nom", nullptr));
        label_7->setText(QCoreApplication::translate("Events", "Type", nullptr));
        label_8->setText(QCoreApplication::translate("Events", "Lieu", nullptr));
        label_9->setText(QCoreApplication::translate("Events", "Date", nullptr));
        label_13->setText(QCoreApplication::translate("Events", "Heure", nullptr));
        Nom_2->setText(QString());
        label_11->setText(QCoreApplication::translate("Events", "Identifiant Unique", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Events", "Ajouter", nullptr));
        label_14->setText(QCoreApplication::translate("Events", "Supprimer Un Evenement", nullptr));
        label_12->setText(QCoreApplication::translate("Events", "Rechercher Un Evenement", nullptr));
        label->setText(QCoreApplication::translate("Events", "Identifiant", nullptr));
        label_3->setText(QCoreApplication::translate("Events", "Nom", nullptr));
        label_4->setText(QCoreApplication::translate("Events", "Type", nullptr));
        label_5->setText(QCoreApplication::translate("Events", "Lieu", nullptr));
        label_6->setText(QCoreApplication::translate("Events", "Lieu", nullptr));
        label_16->setText(QCoreApplication::translate("Events", "Date", nullptr));
        label_15->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Events", "Exporter En Exel", nullptr));
        Fonctionnalit->setText(QCoreApplication::translate("Events", "Fonctionnalit\303\251", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Events", "Acceuil", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Events: public Ui_Events {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTS_H
