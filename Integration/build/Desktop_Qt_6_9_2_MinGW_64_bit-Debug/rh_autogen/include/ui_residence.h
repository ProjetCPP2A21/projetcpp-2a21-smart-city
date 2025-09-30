/********************************************************************************
** Form generated from reading UI file 'residence.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIDENCE_H
#define UI_RESIDENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_residence
{
public:
    QTabWidget *tabWidget;
    QWidget *recherche;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_23;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_24;
    QLabel *label_2;
    QWidget *trie;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QLineEdit *lineEdit_31;
    QLineEdit *lineEdit_32;
    QLineEdit *lineEdit_33;
    QLineEdit *lineEdit_34;
    QLineEdit *lineEdit_35;
    QPushButton *pushButton_11;
    QLineEdit *lineEdit_4;
    QDateEdit *dateEdit;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_11;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_8;
    QFrame *frame;
    QLabel *label_16;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_4;

    void setupUi(QWidget *residence)
    {
        if (residence->objectName().isEmpty())
            residence->setObjectName("residence");
        residence->resize(1360, 768);
        tabWidget = new QTabWidget(residence);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(650, 80, 471, 401));
        tabWidget->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        recherche = new QWidget();
        recherche->setObjectName("recherche");
        lineEdit_16 = new QLineEdit(recherche);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(10, 20, 121, 28));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        font.setPointSize(10);
        font.setBold(true);
        lineEdit_16->setFont(font);
        lineEdit_16->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_17 = new QLineEdit(recherche);
        lineEdit_17->setObjectName("lineEdit_17");
        lineEdit_17->setGeometry(QRect(140, 20, 141, 31));
        lineEdit_17->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_18 = new QLineEdit(recherche);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setGeometry(QRect(10, 80, 121, 28));
        lineEdit_18->setFont(font);
        lineEdit_18->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_19 = new QLineEdit(recherche);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setGeometry(QRect(140, 80, 141, 31));
        lineEdit_19->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_20 = new QLineEdit(recherche);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(10, 130, 121, 28));
        lineEdit_20->setFont(font);
        lineEdit_20->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_21 = new QLineEdit(recherche);
        lineEdit_21->setObjectName("lineEdit_21");
        lineEdit_21->setGeometry(QRect(10, 180, 121, 28));
        lineEdit_21->setFont(font);
        lineEdit_21->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_22 = new QLineEdit(recherche);
        lineEdit_22->setObjectName("lineEdit_22");
        lineEdit_22->setGeometry(QRect(140, 130, 141, 31));
        lineEdit_22->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_23 = new QLineEdit(recherche);
        lineEdit_23->setObjectName("lineEdit_23");
        lineEdit_23->setGeometry(QRect(140, 180, 141, 31));
        lineEdit_23->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        pushButton_10 = new QPushButton(recherche);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(310, 90, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift")});
        font1.setBold(true);
        pushButton_10->setFont(font1);
        pushButton_10->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        lineEdit_24 = new QLineEdit(recherche);
        lineEdit_24->setObjectName("lineEdit_24");
        lineEdit_24->setGeometry(QRect(12, 227, 431, 121));
        lineEdit_24->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        label_2 = new QLabel(recherche);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 350, 63, 101));
        tabWidget->addTab(recherche, QString());
        trie = new QWidget();
        trie->setObjectName("trie");
        lineEdit_25 = new QLineEdit(trie);
        lineEdit_25->setObjectName("lineEdit_25");
        lineEdit_25->setGeometry(QRect(10, 20, 121, 28));
        lineEdit_25->setFont(font);
        lineEdit_25->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_26 = new QLineEdit(trie);
        lineEdit_26->setObjectName("lineEdit_26");
        lineEdit_26->setGeometry(QRect(10, 60, 121, 28));
        lineEdit_26->setFont(font);
        lineEdit_26->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_27 = new QLineEdit(trie);
        lineEdit_27->setObjectName("lineEdit_27");
        lineEdit_27->setGeometry(QRect(10, 100, 121, 28));
        lineEdit_27->setFont(font);
        lineEdit_27->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_28 = new QLineEdit(trie);
        lineEdit_28->setObjectName("lineEdit_28");
        lineEdit_28->setGeometry(QRect(10, 140, 121, 28));
        lineEdit_28->setFont(font);
        lineEdit_28->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_29 = new QLineEdit(trie);
        lineEdit_29->setObjectName("lineEdit_29");
        lineEdit_29->setGeometry(QRect(10, 180, 121, 28));
        lineEdit_29->setFont(font);
        lineEdit_29->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_30 = new QLineEdit(trie);
        lineEdit_30->setObjectName("lineEdit_30");
        lineEdit_30->setGeometry(QRect(150, 20, 141, 31));
        lineEdit_30->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_31 = new QLineEdit(trie);
        lineEdit_31->setObjectName("lineEdit_31");
        lineEdit_31->setGeometry(QRect(150, 60, 141, 31));
        lineEdit_31->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_32 = new QLineEdit(trie);
        lineEdit_32->setObjectName("lineEdit_32");
        lineEdit_32->setGeometry(QRect(150, 100, 141, 31));
        lineEdit_32->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_33 = new QLineEdit(trie);
        lineEdit_33->setObjectName("lineEdit_33");
        lineEdit_33->setGeometry(QRect(150, 140, 141, 31));
        lineEdit_33->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_34 = new QLineEdit(trie);
        lineEdit_34->setObjectName("lineEdit_34");
        lineEdit_34->setGeometry(QRect(150, 180, 141, 31));
        lineEdit_34->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_35 = new QLineEdit(trie);
        lineEdit_35->setObjectName("lineEdit_35");
        lineEdit_35->setGeometry(QRect(10, 230, 431, 121));
        lineEdit_35->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        pushButton_11 = new QPushButton(trie);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(320, 90, 111, 31));
        pushButton_11->setFont(font1);
        pushButton_11->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        tabWidget->addTab(trie, QString());
        lineEdit_4 = new QLineEdit(residence);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(270, 280, 121, 28));
        lineEdit_4->setFont(font);
        lineEdit_4->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        dateEdit = new QDateEdit(residence);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(420, 480, 141, 29));
        dateEdit->setFont(font1);
        dateEdit->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        pushButton_8 = new QPushButton(residence);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(470, 540, 111, 31));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        lineEdit_10 = new QLineEdit(residence);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(420, 180, 141, 31));
        lineEdit_10->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_7 = new QLineEdit(residence);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(270, 430, 121, 28));
        lineEdit_7->setFont(font);
        lineEdit_7->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_11 = new QLineEdit(residence);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(420, 230, 141, 31));
        lineEdit_11->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        pushButton_12 = new QPushButton(residence);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(910, 540, 141, 41));
        pushButton_12->setFont(font1);
        pushButton_12->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        lineEdit = new QLineEdit(residence);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(270, 130, 121, 28));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        label = new QLabel(residence);
        label->setObjectName("label");
        label->setEnabled(false);
        label->setGeometry(QRect(182, -1, 1181, 721));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift")});
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background-color : #ffffff"));
        pushButton_9 = new QPushButton(residence);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(310, 540, 111, 31));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
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
        lineEdit_5 = new QLineEdit(residence);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(270, 330, 121, 28));
        lineEdit_5->setFont(font);
        lineEdit_5->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        label_3 = new QLabel(residence);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 80, 381, 521));
        label_3->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_2 = new QLineEdit(residence);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(270, 180, 121, 28));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_3 = new QLineEdit(residence);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(270, 230, 121, 28));
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_9 = new QLineEdit(residence);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(420, 130, 141, 31));
        lineEdit_9->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_12 = new QLineEdit(residence);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(420, 280, 141, 31));
        lineEdit_12->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_14 = new QLineEdit(residence);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(420, 380, 141, 31));
        lineEdit_14->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_6 = new QLineEdit(residence);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(270, 380, 121, 28));
        lineEdit_6->setFont(font);
        lineEdit_6->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        lineEdit_15 = new QLineEdit(residence);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(420, 430, 141, 31));
        lineEdit_15->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_13 = new QLineEdit(residence);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(420, 330, 141, 31));
        lineEdit_13->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff"));
        lineEdit_8 = new QLineEdit(residence);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(270, 490, 121, 28));
        lineEdit_8->setFont(font);
        lineEdit_8->setStyleSheet(QString::fromUtf8(" background-color : #2C3E50"));
        frame = new QFrame(residence);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -10, 211, 791));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_16 = new QLabel(frame);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(70, 60, 121, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift")});
        font3.setPointSize(18);
        font3.setBold(true);
        label_16->setFont(font3);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 130, 131, 61));
        pushButton->setFont(font1);
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
        pushButton_5->setFont(font1);
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
        pushButton_7->setFont(font1);
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
        pushButton_13 = new QPushButton(frame);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(0, 370, 181, 61));
        pushButton_13->setFont(font1);
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
        pushButton_14 = new QPushButton(frame);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(0, 310, 171, 61));
        pushButton_14->setFont(font1);
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
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 40, 51, 51));
        label_4->setTextFormat(Qt::TextFormat::MarkdownText);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);
        label_4->setOpenExternalLinks(false);
        label_4->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        label->raise();
        label_3->raise();
        tabWidget->raise();
        lineEdit_4->raise();
        dateEdit->raise();
        pushButton_8->raise();
        lineEdit_10->raise();
        lineEdit_7->raise();
        lineEdit_11->raise();
        pushButton_12->raise();
        lineEdit->raise();
        pushButton_9->raise();
        lineEdit_5->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_9->raise();
        lineEdit_12->raise();
        lineEdit_14->raise();
        lineEdit_6->raise();
        lineEdit_15->raise();
        lineEdit_13->raise();
        lineEdit_8->raise();
        frame->raise();

        retranslateUi(residence);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(residence);
    } // setupUi

    void retranslateUi(QWidget *residence)
    {
        residence->setWindowTitle(QCoreApplication::translate("residence", "residence", nullptr));
        lineEdit_16->setText(QCoreApplication::translate("residence", "ID r\303\251sidence", nullptr));
        lineEdit_18->setText(QCoreApplication::translate("residence", "Nom r\303\251sidence", nullptr));
        lineEdit_20->setText(QCoreApplication::translate("residence", "Type", nullptr));
        lineEdit_21->setText(QCoreApplication::translate("residence", "Nbr habitans", nullptr));
        pushButton_10->setText(QCoreApplication::translate("residence", "Recherche", nullptr));
        label_2->setText(QCoreApplication::translate("residence", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(recherche), QCoreApplication::translate("residence", "Recherche", nullptr));
        lineEdit_25->setText(QCoreApplication::translate("residence", "Date", nullptr));
        lineEdit_26->setText(QCoreApplication::translate("residence", "Nbr habitans", nullptr));
        lineEdit_27->setText(QCoreApplication::translate("residence", "Nbr unit\303\251s", nullptr));
        lineEdit_28->setText(QCoreApplication::translate("residence", "Etat", nullptr));
        lineEdit_29->setText(QCoreApplication::translate("residence", "Type", nullptr));
        pushButton_11->setText(QCoreApplication::translate("residence", "Trier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(trie), QCoreApplication::translate("residence", "Trier", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("residence", "Type", nullptr));
        pushButton_8->setText(QCoreApplication::translate("residence", "Supprimer", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("residence", "Etat", nullptr));
        pushButton_12->setText(QCoreApplication::translate("residence", "Exporter ", nullptr));
        lineEdit->setText(QCoreApplication::translate("residence", "ID r\303\251sidence", nullptr));
        label->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("residence", "Ajouter", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("residence", "Nbr habitans", nullptr));
        label_3->setText(QString());
        lineEdit_2->setText(QCoreApplication::translate("residence", "Nom r\303\251sidence", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("residence", "Adresse", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("residence", "Nbr unit\303\251s", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("residence", "Date", nullptr));
        label_16->setText(QCoreApplication::translate("residence", "NEOCITY", nullptr));
        pushButton->setText(QCoreApplication::translate("residence", "RH", nullptr));
        pushButton_5->setText(QCoreApplication::translate("residence", "R\303\251sidence", nullptr));
        pushButton_7->setText(QCoreApplication::translate("residence", "resident", nullptr));
        pushButton_13->setText(QCoreApplication::translate("residence", "Evenement", nullptr));
        pushButton_14->setText(QCoreApplication::translate("residence", "Services", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class residence: public Ui_residence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIDENCE_H
