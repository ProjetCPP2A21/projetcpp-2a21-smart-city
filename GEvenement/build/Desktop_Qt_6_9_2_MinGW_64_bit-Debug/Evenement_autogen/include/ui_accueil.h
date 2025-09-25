/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Accueil
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QFrame *frame_2;
    QLabel *label_11;
    QLineEdit *lineEdit;
    QLabel *label_12;
    QFrame *frame_3;
    QLabel *label_15;
    QLineEdit *lineEdit_3;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lineEdit_4;
    QFrame *frame;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QLabel *label_10;
    QPushButton *pushButton_7;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;

    void setupUi(QWidget *Accueil)
    {
        if (Accueil->objectName().isEmpty())
            Accueil->setObjectName("Accueil");
        Accueil->resize(1366, 768);
        Accueil->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color : #e1e5ff;\n"
"}"));
        label = new QLabel(Accueil);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 550, 71, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_2 = new QLabel(Accueil);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(420, 550, 61, 16));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_3 = new QLabel(Accueil);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(530, 550, 49, 16));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_4 = new QLabel(Accueil);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(220, 200, 461, 16));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_5 = new QLabel(Accueil);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(300, 270, 291, 241));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/Statistique-removebg-preview.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(Accueil);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(330, 580, 21, 21));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #003366;\n"
"}"));
        label_7 = new QLabel(Accueil);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(440, 580, 21, 21));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color : #87CEEB;\n"
"}"));
        label_8 = new QLabel(Accueil);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(540, 580, 21, 21));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color : #FF0000;\n"
"}"));
        frame_2 = new QFrame(Accueil);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(970, 200, 341, 191));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color : #2C3E50;\n"
" border-radius: 20px\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(80, 20, 161, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift")});
        font1.setPointSize(11);
        font1.setBold(true);
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 80, 141, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 89, 151, 21));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_3 = new QFrame(Accueil);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(970, 440, 341, 191));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color : #2C3E50;\n"
" border-radius: 20px\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_15 = new QLabel(frame_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(100, 20, 161, 16));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_3 = new QLineEdit(frame_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(170, 80, 141, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_16 = new QLabel(frame_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 89, 151, 21));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_17 = new QLabel(frame_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 139, 151, 21));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_4 = new QLineEdit(frame_3);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(170, 130, 141, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        frame = new QFrame(Accueil);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 181, 771));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 30, 91, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Hamston")});
        font2.setPointSize(18);
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 80, 171, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift")});
        font3.setBold(true);
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
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 140, 171, 61));
        pushButton_3->setFont(font3);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 210, 171, 61));
        pushButton_4->setFont(font3);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_5->setGeometry(QRect(0, 290, 171, 61));
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
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 430, 171, 61));
        pushButton_8->setFont(font3);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 360, 171, 61));
        pushButton_6->setFont(font3);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 20, 51, 51));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_10->setScaledContents(true);
        pushButton_7 = new QPushButton(Accueil);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(720, 380, 171, 71));
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
        line = new QFrame(Accueil);
        line->setObjectName("line");
        line->setGeometry(QRect(580, 340, 171, 16));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(Accueil);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(860, 340, 141, 16));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(Accueil);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(740, 340, 16, 61));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(Accueil);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(860, 340, 16, 61));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(Accueil);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(850, 440, 16, 61));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_5->setFrameShape(QFrame::Shape::VLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(Accueil);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(850, 490, 141, 16));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_6->raise();
        line_5->raise();
        line_4->raise();
        line_3->raise();
        line_2->raise();
        line->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        frame_2->raise();
        frame_3->raise();
        frame->raise();
        pushButton_7->raise();

        retranslateUi(Accueil);

        QMetaObject::connectSlotsByName(Accueil);
    } // setupUi

    void retranslateUi(QWidget *Accueil)
    {
        Accueil->setWindowTitle(QCoreApplication::translate("Accueil", "Form", nullptr));
        label->setText(QCoreApplication::translate("Accueil", "Musique", nullptr));
        label_2->setText(QCoreApplication::translate("Accueil", "Cin\303\251ma", nullptr));
        label_3->setText(QCoreApplication::translate("Accueil", "Autre", nullptr));
        label_4->setText(QCoreApplication::translate("Accueil", "Statisque des \303\251v\303\251nements selon le nombres des participants", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_11->setText(QCoreApplication::translate("Accueil", "Envoyer une notification d'un nouveau \303\251v\303\251nement", nullptr));
        label_12->setText(QCoreApplication::translate("Accueil", "Identifiant Ev\303\251nement", nullptr));
        label_15->setText(QCoreApplication::translate("Accueil", "Pr\303\251diction D'impact ", nullptr));
        label_16->setText(QCoreApplication::translate("Accueil", "Identifiant Ev\303\251nement", nullptr));
        label_17->setText(QCoreApplication::translate("Accueil", "Nombre d'inscrits", nullptr));
        label_9->setText(QCoreApplication::translate("Accueil", "NEOCITY", nullptr));
        pushButton->setText(QCoreApplication::translate("Accueil", "Tableau de Bord", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Accueil", "R\303\251sidence", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Accueil", "Services", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Accueil", "Transport", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Accueil", "Infrastructures", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Accueil", "Evenements", nullptr));
        label_10->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("Accueil", "Fonctionnalit\303\251s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Accueil: public Ui_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
