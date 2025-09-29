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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_events
{
public:
    QFrame *Ajouter;
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
    QFrame *line_13;
    QFrame *frame;
    QLabel *label_16;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label_17;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QFrame *frame_5;
    QLabel *label_25;
    QPushButton *pushButton_6;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLabel *label_26;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_3;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QTableWidget *tableWidget;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton_8;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QFrame *line_6;
    QFrame *line_3;
    QFrame *line;
    QLabel *label_14;
    QFrame *frame_2;
    QLabel *label_15;
    QLineEdit *lineEdit;
    QLabel *label_18;
    QFrame *line_2;
    QLabel *label_3;
    QFrame *line_4;
    QLabel *label_19;
    QPushButton *pushButton_9;
    QFrame *frame_4;
    QLabel *label_20;
    QLineEdit *lineEdit_5;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEdit_8;
    QLabel *label_23;
    QLabel *label_4;
    QFrame *line_5;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_24;
    QPushButton *pushButton_4;

    void setupUi(QWidget *events)
    {
        if (events->objectName().isEmpty())
            events->setObjectName("events");
        events->resize(1360, 768);
        Ajouter = new QFrame(events);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(160, 10, 361, 751));
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
        label_10 = new QLabel(Ajouter);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 20, 211, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Ajouter);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 170, 49, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(Ajouter);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 230, 49, 21));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(Ajouter);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 290, 49, 21));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(Ajouter);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 350, 49, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        Nom = new QLineEdit(Ajouter);
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
        Type = new QLineEdit(Ajouter);
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
        lineEdit_3 = new QLineEdit(Ajouter);
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
        lineEdit_4 = new QLineEdit(Ajouter);
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
        label_13 = new QLabel(Ajouter);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 420, 61, 16));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_7 = new QLineEdit(Ajouter);
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
        Nom_2 = new QLineEdit(Ajouter);
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
        label_11 = new QLabel(Ajouter);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 110, 131, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setPointSize(11);
        font2.setBold(true);
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_3 = new QPushButton(Ajouter);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 520, 101, 51));
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
        line_13 = new QFrame(events);
        line_13->setObjectName("line_13");
        line_13->setGeometry(QRect(370, 480, 81, 16));
        line_13->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_13->setFrameShape(QFrame::Shape::HLine);
        line_13->setFrameShadow(QFrame::Shadow::Sunken);
        frame = new QFrame(events);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-30, -10, 201, 791));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_16 = new QLabel(frame);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(80, 50, 121, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bahnschrift")});
        font4.setPointSize(18);
        font4.setBold(true);
        label_16->setFont(font4);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
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
        label_17 = new QLabel(frame);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 30, 61, 61));
        label_17->setStyleSheet(QString::fromUtf8("image: url(:/cropped_circle_image.png);"));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_17->setScaledContents(true);
        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(0, 370, 181, 61));
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
        pushButton_11 = new QPushButton(frame);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(0, 310, 171, 61));
        pushButton_11->setFont(font3);
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
        frame_5 = new QFrame(frame);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(0, 0, 201, 791));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        label_25 = new QLabel(frame_5);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(80, 50, 121, 31));
        label_25->setFont(font4);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_6 = new QPushButton(frame_5);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 130, 151, 61));
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
        pushButton_12 = new QPushButton(frame_5);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(10, 190, 171, 61));
        pushButton_12->setFont(font3);
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
        pushButton_13 = new QPushButton(frame_5);
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
        label_26 = new QLabel(frame_5);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 30, 61, 61));
        label_26->setStyleSheet(QString::fromUtf8("image: url(:/cropped_circle_image.png);"));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/551544292_1166092592062473_5497828692904860049_n-removebg-preview.png")));
        label_26->setScaledContents(true);
        pushButton_14 = new QPushButton(frame_5);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(0, 370, 171, 61));
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
        pushButton_15 = new QPushButton(frame_5);
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
        tabWidget = new QTabWidget(events);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(520, 20, 821, 651));
        tabWidget->setStyleSheet(QString::fromUtf8("border-radius : 20px\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        frame_3 = new QFrame(tab);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(10, 10, 771, 541));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_6 = new QLineEdit(frame_3);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(240, 10, 221, 41));
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
        label_12->setGeometry(QRect(10, 19, 211, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font5.setPointSize(11);
        font5.setBold(true);
        label_12->setFont(font5);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tableWidget = new QTableWidget(frame_3);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(35, 81, 691, 381));
        tableWidget->setStyleSheet(QString::fromUtf8("border-raduis : 20px;\n"
"background-color : #e1e5ff;"));
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setGeometry(QRect(490, 20, 41, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Bahnschrift")});
        font6.setPointSize(11);
        font6.setBold(true);
        label->setFont(font6);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        comboBox = new QComboBox(frame_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(540, 20, 101, 21));
        comboBox->setStyleSheet(QString::fromUtf8("background-color : #e1e5ff;"));
        pushButton_8 = new QPushButton(frame_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 480, 101, 41));
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
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 480, 91, 41));
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        line_6 = new QFrame(tab_2);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(410, 390, 141, 16));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(tab_2);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(330, 240, 16, 61));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line = new QFrame(tab_2);
        line->setObjectName("line");
        line->setGeometry(QRect(210, 240, 131, 16));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_14 = new QLabel(tab_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 170, 261, 221));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Statistique-removebg-preview.png")));
        label_14->setScaledContents(true);
        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(480, 110, 341, 191));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color : #2C3E50;\n"
" border-radius: 20px\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_15 = new QLabel(frame_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(80, 20, 161, 16));
        label_15->setFont(font6);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
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
        label_18 = new QLabel(frame_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 89, 151, 21));
        label_18->setFont(font6);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_2 = new QFrame(tab_2);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(410, 240, 121, 16));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 450, 49, 16));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        line_4 = new QFrame(tab_2);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(410, 240, 16, 61));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_4->setFrameShape(QFrame::Shape::VLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        label_19 = new QLabel(tab_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(270, 480, 21, 21));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color : #FF0000;\n"
"}"));
        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(290, 280, 171, 71));
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
        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(470, 350, 341, 191));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background-color : #2C3E50;\n"
" border-radius: 20px\n"
"}"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        label_20 = new QLabel(frame_4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(100, 20, 161, 16));
        label_20->setFont(font6);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_5 = new QLineEdit(frame_4);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(170, 80, 141, 41));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_21 = new QLabel(frame_4);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(10, 89, 151, 21));
        label_21->setFont(font6);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_22 = new QLabel(frame_4);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(10, 139, 151, 21));
        label_22->setFont(font6);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_8 = new QLineEdit(frame_4);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(170, 130, 141, 41));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}"));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(170, 480, 21, 21));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color : #87CEEB;\n"
"}"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 451, 20));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        line_5 = new QFrame(tab_2);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(410, 340, 16, 61));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb(105, 125, 255);\n"
"color: rgb(105, 125, 255);\n"
"border-radius: 8px;"));
        line_5->setFrameShape(QFrame::Shape::VLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(150, 450, 61, 16));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 450, 71, 16));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color : #000000;\n"
"}"));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(60, 480, 21, 21));
        label_24->setFont(font2);
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: #003366;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        pushButton_4 = new QPushButton(events);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(1180, 690, 131, 41));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font7.setBold(true);
        pushButton_4->setFont(font7);
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

        retranslateUi(events);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(events);
    } // setupUi

    void retranslateUi(QWidget *events)
    {
        events->setWindowTitle(QCoreApplication::translate("events", "events", nullptr));
        label_10->setText(QCoreApplication::translate("events", "Ajouter un Ev\303\251nement", nullptr));
        label_2->setText(QCoreApplication::translate("events", "Nom", nullptr));
        label_7->setText(QCoreApplication::translate("events", "Type", nullptr));
        label_8->setText(QCoreApplication::translate("events", "Lieu", nullptr));
        label_9->setText(QCoreApplication::translate("events", "Date", nullptr));
        label_13->setText(QCoreApplication::translate("events", "Heure", nullptr));
        Nom_2->setText(QString());
        label_11->setText(QCoreApplication::translate("events", "ID", nullptr));
        pushButton_3->setText(QCoreApplication::translate("events", "Ajouter", nullptr));
        label_16->setText(QCoreApplication::translate("events", "NEOCITY", nullptr));
        pushButton->setText(QCoreApplication::translate("events", "RH", nullptr));
        pushButton_5->setText(QCoreApplication::translate("events", "R\303\251sidence", nullptr));
        pushButton_7->setText(QCoreApplication::translate("events", "resident", nullptr));
        label_17->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("events", "Evenement", nullptr));
        pushButton_11->setText(QCoreApplication::translate("events", "Services", nullptr));
        label_25->setText(QCoreApplication::translate("events", "NEOCITY", nullptr));
        pushButton_6->setText(QCoreApplication::translate("events", "RH", nullptr));
        pushButton_12->setText(QCoreApplication::translate("events", "R\303\251sidence", nullptr));
        pushButton_13->setText(QCoreApplication::translate("events", "resident", nullptr));
        label_26->setText(QString());
        pushButton_14->setText(QCoreApplication::translate("events", "Evenement", nullptr));
        pushButton_15->setText(QCoreApplication::translate("events", "Services", nullptr));
        label_12->setText(QCoreApplication::translate("events", "Rechercher Un Evenement", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("events", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("events", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("events", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("events", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("events", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("events", "Heure", nullptr));
        label->setText(QCoreApplication::translate("events", "Trier", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("events", "Date", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("events", "Nombre d'inscrits", nullptr));

        pushButton_8->setText(QCoreApplication::translate("events", "Modifier", nullptr));
        pushButton_2->setText(QCoreApplication::translate("events", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("events", "Fonctionnalit\303\251s", nullptr));
        label_14->setText(QString());
        label_15->setText(QCoreApplication::translate("events", "Envoyer une notification d'un nouveau \303\251v\303\251nement", nullptr));
        label_18->setText(QCoreApplication::translate("events", "Identifiant Ev\303\251nement", nullptr));
        label_3->setText(QCoreApplication::translate("events", "Autre", nullptr));
        label_19->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("events", "Fonctionnalit\303\251s", nullptr));
        label_20->setText(QCoreApplication::translate("events", "Pr\303\251diction D'impact ", nullptr));
        label_21->setText(QCoreApplication::translate("events", "Identifiant Ev\303\251nement", nullptr));
        label_22->setText(QCoreApplication::translate("events", "Nombre d'inscrits", nullptr));
        label_23->setText(QString());
        label_4->setText(QCoreApplication::translate("events", "Statisque des \303\251v\303\251nements selon le nombres des participants", nullptr));
        label_5->setText(QCoreApplication::translate("events", "Cin\303\251ma", nullptr));
        label_6->setText(QCoreApplication::translate("events", "Musique", nullptr));
        label_24->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("events", "Avanc\303\251s", nullptr));
        pushButton_4->setText(QCoreApplication::translate("events", "Exporter En Exel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class events: public Ui_events {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTS_H
