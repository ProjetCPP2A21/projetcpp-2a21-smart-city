/********************************************************************************
** Form generated from reading UI file 'gemployer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEMPLOYER_H
#define UI_GEMPLOYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GEmployer
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *rechercher;
    QFrame *frame;
    QLabel *label_23;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QLabel *label_24;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButtonExporter;
    QLabel *label_39;
    QLabel *label_29;
    QFrame *Ajouter_2;
    QLabel *label_12;
    QLabel *label_4;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEditPrenom_2;
    QLineEdit *lineEditID_2;
    QLineEdit *lineEditTelephone_2;
    QLineEdit *lineEditSalaire_2;
    QLabel *label_27;
    QLineEdit *lineEditSexe_2;
    QLineEdit *lineEditNom_2;
    QLabel *label_16;
    QPushButton *Ajouter;
    QLabel *label_28;
    QLineEdit *lineEditTache_2;
    QPushButton *Modifier;
    QPushButton *Supprimer;
    QPushButton *pushButtonStats;
    QLineEdit *lineEditRecherche;
    QTableWidget *tableWidgetEmployes;
    QPushButton *pushButtonTrier;
    QWidget *widgetStats;
    QWidget *page_10;
    QTextBrowser *textBrowser_14;
    QLineEdit *lineEditMdpUsername;
    QTextBrowser *textBrowser_15;
    QLabel *label_8;
    QPushButton *pushButtonRetourLogin_2;
    QPushButton *pushButtonSuivant;
    QTextBrowser *textBrowser_16;
    QLineEdit *lineEditMdpId;
    QLineEdit *lineEditMdpEmail;
    QTextBrowser *textBrowser_19;
    QLabel *label_5;
    QWidget *page_2;
    QPushButton *connecter;
    QTextBrowser *textBrowser_2;
    QLineEdit *lineEditLoginUsername;
    QPushButton *pushButtonGoToMdp;
    QTextBrowser *textBrowser_3;
    QLabel *label;
    QPushButton *quitter;
    QTextBrowser *textBrowser;
    QLineEdit *lineEditLoginPassword;
    QPushButton *pushButtonGoToCreer;
    QLabel *label_2;
    QLabel *label_26;
    QLabel *label_25;
    QWidget *page_4;
    QPushButton *pushButtonValiderReset;
    QTextBrowser *textBrowser_18;
    QTextBrowser *textBrowser_20;
    QPushButton *pushButtonRetourLogin_3;
    QLabel *label_9;
    QLineEdit *lineEditCodeRecu;
    QLineEdit *lineEditNouveauPass;
    QTextBrowser *textBrowser_17;
    QLabel *label_6;
    QWidget *page_3;
    QTextBrowser *textBrowser_10;
    QLabel *label_7;
    QLineEdit *lineEditCreerUsername;
    QLineEdit *lineEditCreerPassword;
    QLineEdit *lineEditCreerId;
    QTextBrowser *textBrowser_11;
    QTextBrowser *textBrowser_12;
    QTextBrowser *textBrowser_13;
    QPushButton *pushButtonCreer;
    QPushButton *pushButtonRetourLogin;
    QLineEdit *lineEditEmail;
    QTextBrowser *textBrowser_21;
    QLabel *label_3;

    void setupUi(QWidget *GEmployer)
    {
        if (GEmployer->objectName().isEmpty())
            GEmployer->setObjectName("GEmployer");
        GEmployer->resize(1360, 768);
        stackedWidget = new QStackedWidget(GEmployer);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1360, 761));
        page = new QWidget();
        page->setObjectName("page");
        rechercher = new QPushButton(page);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(920, 300, 101, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        font.setBold(true);
        rechercher->setFont(font);
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
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -10, 211, 801));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_23 = new QLabel(frame);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(80, 50, 121, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift")});
        font1.setPointSize(18);
        font1.setBold(true);
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 130, 131, 61));
        pushButton_3->setFont(font);
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
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 190, 171, 61));
        pushButton_6->setFont(font);
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
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 250, 171, 61));
        pushButton_8->setFont(font);
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
        label_24 = new QLabel(frame);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 30, 61, 61));
        label_24->setStyleSheet(QString::fromUtf8("image: url(:/cropped_circle_image.png);"));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_24->setScaledContents(true);
        pushButton_11 = new QPushButton(frame);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(0, 370, 181, 61));
        pushButton_11->setFont(font);
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_12 = new QPushButton(frame);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(0, 310, 171, 61));
        pushButton_12->setFont(font);
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButtonExporter = new QPushButton(page);
        pushButtonExporter->setObjectName("pushButtonExporter");
        pushButtonExporter->setGeometry(QRect(1220, 700, 101, 51));
        pushButtonExporter->setFont(font);
        pushButtonExporter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_39 = new QLabel(page);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(580, 0, 791, 781));
        label_39->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_29 = new QLabel(page);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(600, 280, 301, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        font2.setBold(true);
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Ajouter_2 = new QFrame(page);
        Ajouter_2->setObjectName("Ajouter_2");
        Ajouter_2->setGeometry(QRect(200, -10, 381, 801));
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
        label_12 = new QLabel(Ajouter_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(80, 30, 211, 31));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(Ajouter_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 170, 71, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Rockwell")});
        font3.setPointSize(12);
        font3.setBold(true);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(Ajouter_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 230, 49, 21));
        label_13->setFont(font3);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_14 = new QLabel(Ajouter_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 290, 101, 21));
        label_14->setFont(font3);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(Ajouter_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 350, 71, 21));
        label_15->setFont(font3);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
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
"    background-color: #000000;\n"
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
"    background-color: #000000;\n"
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
"    background-color: #000000;\n"
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
"    background-color: #000000;\n"
"}"));
        label_27 = new QLabel(Ajouter_2);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 420, 61, 16));
        label_27->setFont(font3);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
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
"    background-color: #000000;\n"
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
"    background-color: #000000;\n"
"}"));
        label_16 = new QLabel(Ajouter_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 110, 131, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Rockwell")});
        font4.setPointSize(11);
        font4.setBold(true);
        label_16->setFont(font4);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Ajouter = new QPushButton(Ajouter_2);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(30, 540, 101, 51));
        Ajouter->setFont(font);
        Ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_28 = new QLabel(Ajouter_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 470, 141, 31));
        label_28->setFont(font3);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
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
"    background-color: #000000;\n"
"}"));
        Modifier = new QPushButton(Ajouter_2);
        Modifier->setObjectName("Modifier");
        Modifier->setGeometry(QRect(150, 540, 101, 51));
        Modifier->setFont(font);
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
        Supprimer->setGeometry(QRect(270, 540, 101, 51));
        Supprimer->setFont(font);
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
        pushButtonStats = new QPushButton(page);
        pushButtonStats->setObjectName("pushButtonStats");
        pushButtonStats->setGeometry(QRect(1100, 700, 101, 51));
        pushButtonStats->setFont(font);
        pushButtonStats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEditRecherche = new QLineEdit(page);
        lineEditRecherche->setObjectName("lineEditRecherche");
        lineEditRecherche->setGeometry(QRect(620, 310, 291, 41));
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
        tableWidgetEmployes = new QTableWidget(page);
        if (tableWidgetEmployes->columnCount() < 7)
            tableWidgetEmployes->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidgetEmployes->setObjectName("tableWidgetEmployes");
        tableWidgetEmployes->setGeometry(QRect(590, 10, 751, 251));
        pushButtonTrier = new QPushButton(page);
        pushButtonTrier->setObjectName("pushButtonTrier");
        pushButtonTrier->setGeometry(QRect(1030, 300, 101, 51));
        pushButtonTrier->setFont(font);
        pushButtonTrier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        widgetStats = new QWidget(page);
        widgetStats->setObjectName("widgetStats");
        widgetStats->setGeometry(QRect(700, 390, 501, 241));
        stackedWidget->addWidget(page);
        label_39->raise();
        rechercher->raise();
        frame->raise();
        pushButtonExporter->raise();
        label_29->raise();
        Ajouter_2->raise();
        pushButtonStats->raise();
        lineEditRecherche->raise();
        tableWidgetEmployes->raise();
        pushButtonTrier->raise();
        widgetStats->raise();
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        textBrowser_14 = new QTextBrowser(page_10);
        textBrowser_14->setObjectName("textBrowser_14");
        textBrowser_14->setGeometry(QRect(210, 280, 301, 61));
        textBrowser_14->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_14->setFrameShape(QFrame::Shape::NoFrame);
        lineEditMdpUsername = new QLineEdit(page_10);
        lineEditMdpUsername->setObjectName("lineEditMdpUsername");
        lineEditMdpUsername->setGeometry(QRect(210, 240, 301, 41));
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
        textBrowser_15 = new QTextBrowser(page_10);
        textBrowser_15->setObjectName("textBrowser_15");
        textBrowser_15->setGeometry(QRect(10, 60, 561, 111));
        textBrowser_15->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_15->setFrameShape(QFrame::Shape::NoFrame);
        label_8 = new QLabel(page_10);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, -10, 1381, 781));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 62, 80);"));
        pushButtonRetourLogin_2 = new QPushButton(page_10);
        pushButtonRetourLogin_2->setObjectName("pushButtonRetourLogin_2");
        pushButtonRetourLogin_2->setGeometry(QRect(380, 500, 101, 51));
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
        pushButtonSuivant = new QPushButton(page_10);
        pushButtonSuivant->setObjectName("pushButtonSuivant");
        pushButtonSuivant->setGeometry(QRect(260, 500, 101, 51));
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
        textBrowser_16 = new QTextBrowser(page_10);
        textBrowser_16->setObjectName("textBrowser_16");
        textBrowser_16->setGeometry(QRect(210, 180, 301, 61));
        textBrowser_16->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_16->setFrameShape(QFrame::Shape::NoFrame);
        lineEditMdpId = new QLineEdit(page_10);
        lineEditMdpId->setObjectName("lineEditMdpId");
        lineEditMdpId->setGeometry(QRect(210, 330, 301, 41));
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
        lineEditMdpEmail = new QLineEdit(page_10);
        lineEditMdpEmail->setObjectName("lineEditMdpEmail");
        lineEditMdpEmail->setGeometry(QRect(210, 430, 301, 41));
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
        textBrowser_19 = new QTextBrowser(page_10);
        textBrowser_19->setObjectName("textBrowser_19");
        textBrowser_19->setGeometry(QRect(140, 380, 431, 61));
        textBrowser_19->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_19->setFrameShape(QFrame::Shape::NoFrame);
        label_5 = new QLabel(page_10);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(670, 0, 691, 761));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/Mesa de trabajo 1.png);"));
        stackedWidget->addWidget(page_10);
        label_8->raise();
        textBrowser_14->raise();
        textBrowser_15->raise();
        pushButtonRetourLogin_2->raise();
        pushButtonSuivant->raise();
        textBrowser_16->raise();
        textBrowser_19->raise();
        lineEditMdpEmail->raise();
        lineEditMdpUsername->raise();
        lineEditMdpId->raise();
        label_5->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        connecter = new QPushButton(page_2);
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
        textBrowser_2 = new QTextBrowser(page_2);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(190, 270, 201, 41));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_2->setFrameShape(QFrame::Shape::NoFrame);
        lineEditLoginUsername = new QLineEdit(page_2);
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
        pushButtonGoToMdp = new QPushButton(page_2);
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
        textBrowser_3 = new QTextBrowser(page_2);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(200, 370, 141, 41));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_3->setFrameShape(QFrame::Shape::NoFrame);
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(-10, 0, 1381, 781));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 62, 80);"));
        quitter = new QPushButton(page_2);
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
        textBrowser = new QTextBrowser(page_2);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 130, 591, 111));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser->setFrameShape(QFrame::Shape::NoFrame);
        lineEditLoginPassword = new QLineEdit(page_2);
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
        pushButtonGoToCreer = new QPushButton(page_2);
        pushButtonGoToCreer->setObjectName("pushButtonGoToCreer");
        pushButtonGoToCreer->setGeometry(QRect(250, 580, 191, 41));
        pushButtonGoToCreer->setFont(font);
        pushButtonGoToCreer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(720, 0, 641, 761));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/Artboard 1.png);"));
        label_26 = new QLabel(page_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(80, 40, 121, 31));
        label_26->setFont(font1);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_25 = new QLabel(page_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 20, 61, 61));
        label_25->setStyleSheet(QString::fromUtf8("image: url(:/cropped_circle_image.png);"));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_25->setScaledContents(true);
        stackedWidget->addWidget(page_2);
        label->raise();
        connecter->raise();
        textBrowser_2->raise();
        lineEditLoginUsername->raise();
        pushButtonGoToMdp->raise();
        textBrowser_3->raise();
        quitter->raise();
        textBrowser->raise();
        lineEditLoginPassword->raise();
        pushButtonGoToCreer->raise();
        label_2->raise();
        label_26->raise();
        label_25->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        pushButtonValiderReset = new QPushButton(page_4);
        pushButtonValiderReset->setObjectName("pushButtonValiderReset");
        pushButtonValiderReset->setGeometry(QRect(210, 460, 101, 51));
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
        textBrowser_18 = new QTextBrowser(page_4);
        textBrowser_18->setObjectName("textBrowser_18");
        textBrowser_18->setGeometry(QRect(160, 230, 301, 61));
        textBrowser_18->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_18->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser_20 = new QTextBrowser(page_4);
        textBrowser_20->setObjectName("textBrowser_20");
        textBrowser_20->setGeometry(QRect(50, 90, 521, 111));
        textBrowser_20->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_20->setFrameShape(QFrame::Shape::NoFrame);
        pushButtonRetourLogin_3 = new QPushButton(page_4);
        pushButtonRetourLogin_3->setObjectName("pushButtonRetourLogin_3");
        pushButtonRetourLogin_3->setGeometry(QRect(330, 460, 101, 51));
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
        label_9 = new QLabel(page_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(-10, 0, 1381, 781));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 62, 80);"));
        lineEditCodeRecu = new QLineEdit(page_4);
        lineEditCodeRecu->setObjectName("lineEditCodeRecu");
        lineEditCodeRecu->setGeometry(QRect(160, 280, 301, 41));
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
        lineEditNouveauPass = new QLineEdit(page_4);
        lineEditNouveauPass->setObjectName("lineEditNouveauPass");
        lineEditNouveauPass->setGeometry(QRect(160, 390, 301, 41));
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
        textBrowser_17 = new QTextBrowser(page_4);
        textBrowser_17->setObjectName("textBrowser_17");
        textBrowser_17->setGeometry(QRect(90, 340, 431, 61));
        textBrowser_17->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_17->setFrameShape(QFrame::Shape::NoFrame);
        label_6 = new QLabel(page_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(660, 0, 691, 771));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/Artboa.png);"));
        stackedWidget->addWidget(page_4);
        label_9->raise();
        pushButtonValiderReset->raise();
        textBrowser_18->raise();
        textBrowser_20->raise();
        pushButtonRetourLogin_3->raise();
        lineEditCodeRecu->raise();
        textBrowser_17->raise();
        lineEditNouveauPass->raise();
        label_6->raise();
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        textBrowser_10 = new QTextBrowser(page_3);
        textBrowser_10->setObjectName("textBrowser_10");
        textBrowser_10->setGeometry(QRect(20, 20, 621, 111));
        textBrowser_10->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_10->setFrameShape(QFrame::Shape::NoFrame);
        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 1381, 781));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 62, 80);"));
        lineEditCreerUsername = new QLineEdit(page_3);
        lineEditCreerUsername->setObjectName("lineEditCreerUsername");
        lineEditCreerUsername->setGeometry(QRect(190, 170, 281, 41));
        lineEditCreerUsername->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        lineEditCreerPassword = new QLineEdit(page_3);
        lineEditCreerPassword->setObjectName("lineEditCreerPassword");
        lineEditCreerPassword->setGeometry(QRect(190, 280, 281, 41));
        lineEditCreerPassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        lineEditCreerId = new QLineEdit(page_3);
        lineEditCreerId->setObjectName("lineEditCreerId");
        lineEditCreerId->setGeometry(QRect(190, 390, 281, 41));
        lineEditCreerId->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        textBrowser_11 = new QTextBrowser(page_3);
        textBrowser_11->setObjectName("textBrowser_11");
        textBrowser_11->setGeometry(QRect(180, 120, 301, 61));
        textBrowser_11->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_11->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser_12 = new QTextBrowser(page_3);
        textBrowser_12->setObjectName("textBrowser_12");
        textBrowser_12->setGeometry(QRect(180, 230, 301, 61));
        textBrowser_12->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_12->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser_13 = new QTextBrowser(page_3);
        textBrowser_13->setObjectName("textBrowser_13");
        textBrowser_13->setGeometry(QRect(180, 340, 301, 61));
        textBrowser_13->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_13->setFrameShape(QFrame::Shape::NoFrame);
        pushButtonCreer = new QPushButton(page_3);
        pushButtonCreer->setObjectName("pushButtonCreer");
        pushButtonCreer->setGeometry(QRect(220, 570, 101, 51));
        pushButtonCreer->setFont(font);
        pushButtonCreer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButtonRetourLogin = new QPushButton(page_3);
        pushButtonRetourLogin->setObjectName("pushButtonRetourLogin");
        pushButtonRetourLogin->setGeometry(QRect(350, 570, 101, 51));
        pushButtonRetourLogin->setFont(font);
        pushButtonRetourLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEditEmail = new QLineEdit(page_3);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(190, 510, 281, 41));
        lineEditEmail->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #000000;\n"
"}"));
        textBrowser_21 = new QTextBrowser(page_3);
        textBrowser_21->setObjectName("textBrowser_21");
        textBrowser_21->setGeometry(QRect(180, 450, 301, 61));
        textBrowser_21->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);"));
        textBrowser_21->setFrameShape(QFrame::Shape::NoFrame);
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(680, -1, 681, 761));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-image: url(:/Artboard .png);"));
        stackedWidget->addWidget(page_3);
        label_7->raise();
        textBrowser_10->raise();
        textBrowser_11->raise();
        textBrowser_12->raise();
        textBrowser_13->raise();
        pushButtonCreer->raise();
        pushButtonRetourLogin->raise();
        lineEditCreerPassword->raise();
        textBrowser_21->raise();
        lineEditCreerId->raise();
        lineEditEmail->raise();
        lineEditCreerUsername->raise();
        label_3->raise();

        retranslateUi(GEmployer);

        QMetaObject::connectSlotsByName(GEmployer);
    } // setupUi

    void retranslateUi(QWidget *GEmployer)
    {
        GEmployer->setWindowTitle(QCoreApplication::translate("GEmployer", "GEmployer", nullptr));
        rechercher->setText(QCoreApplication::translate("GEmployer", "rechercher", nullptr));
        label_23->setText(QCoreApplication::translate("GEmployer", "NEOCITY", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GEmployer", "RH", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GEmployer", "R\303\251sidence", nullptr));
        pushButton_8->setText(QCoreApplication::translate("GEmployer", "resident", nullptr));
        label_24->setText(QString());
        pushButton_11->setText(QCoreApplication::translate("GEmployer", "Evenement", nullptr));
        pushButton_12->setText(QCoreApplication::translate("GEmployer", "Services", nullptr));
        pushButtonExporter->setText(QCoreApplication::translate("GEmployer", "export", nullptr));
        label_39->setText(QString());
        label_29->setText(QCoreApplication::translate("GEmployer", "<html><head/><body><p align=\"center\">rechcerche d'un employ\303\251e</p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("GEmployer", "<html><head/><body><p align=\"center\">ajouter un employee</p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("GEmployer", "Prenom", nullptr));
        label_13->setText(QCoreApplication::translate("GEmployer", "Id", nullptr));
        label_14->setText(QCoreApplication::translate("GEmployer", "telephone", nullptr));
        label_15->setText(QCoreApplication::translate("GEmployer", "salaire", nullptr));
        label_27->setText(QCoreApplication::translate("GEmployer", "sexe", nullptr));
#if QT_CONFIG(tooltip)
        lineEditNom_2->setToolTip(QCoreApplication::translate("GEmployer", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditNom_2->setText(QString());
        label_16->setText(QCoreApplication::translate("GEmployer", "Nom", nullptr));
        Ajouter->setText(QCoreApplication::translate("GEmployer", "ajouter", nullptr));
        label_28->setText(QCoreApplication::translate("GEmployer", "responsabilite", nullptr));
        Modifier->setText(QCoreApplication::translate("GEmployer", "modifier", nullptr));
        Supprimer->setText(QCoreApplication::translate("GEmployer", "suprimer", nullptr));
        pushButtonStats->setText(QCoreApplication::translate("GEmployer", "statistique", nullptr));
#if QT_CONFIG(tooltip)
        lineEditRecherche->setToolTip(QCoreApplication::translate("GEmployer", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditRecherche->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GEmployer", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("GEmployer", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("GEmployer", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("GEmployer", "telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("GEmployer", "salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetEmployes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("GEmployer", "sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetEmployes->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("GEmployer", "responsabilite", nullptr));
        pushButtonTrier->setText(QCoreApplication::translate("GEmployer", "trier", nullptr));
        textBrowser_14->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">ID</span></p></body></html>", nullptr));
        lineEditMdpUsername->setText(QString());
        textBrowser_15->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:700; color:#3668f2;\"> Restaurer votre  compte</span></p></body></html>", nullptr));
        label_8->setText(QString());
        pushButtonRetourLogin_2->setText(QCoreApplication::translate("GEmployer", "retour", nullptr));
        pushButtonSuivant->setText(QCoreApplication::translate("GEmployer", "suivant", nullptr));
        textBrowser_16->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">Nom d'utilisateur</span></p></body></html>", nullptr));
        lineEditMdpId->setText(QString());
        lineEditMdpEmail->setText(QString());
        textBrowser_19->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">E_mail</span></p></body></html>", nullptr));
        label_5->setText(QString());
        connecter->setText(QCoreApplication::translate("GEmployer", "connecter", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#3668f2;\">Nom d'utlisateur</span></p></body></html>", nullptr));
        lineEditLoginUsername->setText(QString());
#if QT_CONFIG(tooltip)
        pushButtonGoToMdp->setToolTip(QCoreApplication::translate("GEmployer", "<html><head/><body><p>mot de pass oublier</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonGoToMdp->setText(QCoreApplication::translate("GEmployer", "mot de pass oublier !!", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#3668f2;\">Mot de pass</span></p></body></html>", nullptr));
        label->setText(QString());
        quitter->setText(QCoreApplication::translate("GEmployer", "quitter", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; color:#3668f2;\">Bienvenu \303\240 neocity</span></p></body></html>", nullptr));
        lineEditLoginPassword->setText(QString());
        pushButtonGoToCreer->setText(QCoreApplication::translate("GEmployer", "cr\303\251e votre compte !!", nullptr));
        label_2->setText(QString());
        label_26->setText(QCoreApplication::translate("GEmployer", "NEOCITY", nullptr));
        label_25->setText(QString());
        pushButtonValiderReset->setText(QCoreApplication::translate("GEmployer", "valider", nullptr));
        textBrowser_18->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">entrer le code </span></p></body></html>", nullptr));
        textBrowser_20->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:700; color:#3668f2;\"> Restaurer votre  compte</span></p></body></html>", nullptr));
        pushButtonRetourLogin_3->setText(QCoreApplication::translate("GEmployer", "retour", nullptr));
        label_9->setText(QString());
        lineEditCodeRecu->setText(QString());
        lineEditNouveauPass->setText(QString());
        textBrowser_17->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">Nouveau mot de pass</span></p></body></html>", nullptr));
        label_6->setText(QString());
        textBrowser_10->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; color:#3668f2;\">creation d'un compte</span></p></body></html>", nullptr));
        label_7->setText(QString());
        lineEditCreerUsername->setText(QString());
        lineEditCreerPassword->setText(QString());
        lineEditCreerId->setText(QString());
        textBrowser_11->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">Nom d'utilisateur</span></p></body></html>", nullptr));
        textBrowser_12->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">mot de pass</span></p></body></html>", nullptr));
        textBrowser_13->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">ID</span></p></body></html>", nullptr));
        pushButtonCreer->setText(QCoreApplication::translate("GEmployer", "cr\303\251e", nullptr));
        pushButtonRetourLogin->setText(QCoreApplication::translate("GEmployer", "retour", nullptr));
        lineEditEmail->setText(QString());
        textBrowser_21->setHtml(QCoreApplication::translate("GEmployer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#3668f2;\">E-mail</span></p></body></html>", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GEmployer: public Ui_GEmployer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEMPLOYER_H
