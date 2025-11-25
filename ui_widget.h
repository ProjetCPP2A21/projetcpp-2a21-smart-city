/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame_2;
    QLabel *label_18;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QFrame *frame_5;
    QLabel *label_32;
    QPushButton *RH_2;
    QPushButton *residence_3;
    QPushButton *resident;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QLabel *label_53;
    QLabel *label_65;
    QTableWidget *tableServices;
    QLineEdit *Nom_3;
    QPushButton *pushButton_9;
    QLabel *label_sort;
    QComboBox *combo_sort;
    QLabel *label_39;
    QPushButton *supprimerButton;
    QPushButton *modifierButton;
    QPushButton *ajouterButton;
    QPushButton *pushButton_23;
    QPushButton *btnExportPDF;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnStats;
    QLineEdit *lineEdit_responsable;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_id;
    QLabel *label_id;
    QLabel *label_name;
    QLabel *label_resp;
    QComboBox *combo_type;
    QDoubleSpinBox *spin_budget;
    QComboBox *combo_priority;
    QComboBox *combo_state;
    QDateEdit *dateEdit_date;
    QLabel *label_date;
    QLabel *label_state;
    QLabel *label_priority;
    QLabel *label_budget;
    QLabel *label_type;
    QPushButton *btnIA;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1640, 750);
        Widget->setMinimumSize(QSize(1640, 750));
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(-80, -60, 201, 871));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_18 = new QLabel(frame_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(60, 40, 111, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift")});
        font.setPointSize(18);
        font.setBold(true);
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 130, 131, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift")});
        font1.setBold(true);
        pushButton_2->setFont(font1);
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
        pushButton_11 = new QPushButton(frame_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(10, 190, 171, 61));
        pushButton_11->setFont(font1);
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
        pushButton_12 = new QPushButton(frame_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(0, 250, 171, 61));
        pushButton_12->setFont(font1);
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
        pushButton_13 = new QPushButton(frame_2);
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
        pushButton_14 = new QPushButton(frame_2);
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
        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(180, 140, 221, 791));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        label_32 = new QLabel(frame_5);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(90, 40, 121, 31));
        label_32->setFont(font);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        RH_2 = new QPushButton(frame_5);
        RH_2->setObjectName("RH_2");
        RH_2->setGeometry(QRect(20, 130, 131, 61));
        RH_2->setFont(font1);
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
        residence_3->setFont(font1);
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
        resident->setFont(font1);
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
        pushButton_25->setFont(font1);
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
        pushButton_26->setFont(font1);
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
        label_65 = new QLabel(frame_2);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(0, 30, 61, 51));
        label_65->setTextFormat(Qt::TextFormat::MarkdownText);
        label_65->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_65->setScaledContents(true);
        label_65->setWordWrap(false);
        label_65->setOpenExternalLinks(false);
        label_65->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        tableServices = new QTableWidget(Widget);
        if (tableServices->columnCount() < 8)
            tableServices->setColumnCount(8);
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        __qtablewidgetitem->setBackground(QColor(255, 255, 255));
        tableServices->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font3;
        font3.setBold(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font3);
        __qtablewidgetitem1->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font4;
        font4.setBold(true);
        font4.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font4);
        __qtablewidgetitem2->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font4);
        __qtablewidgetitem3->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font4);
        __qtablewidgetitem4->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font4);
        __qtablewidgetitem5->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font4);
        __qtablewidgetitem6->setBackground(QColor(255, 255, 255, 0));
        tableServices->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableServices->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableServices->rowCount() < 8)
            tableServices->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QFont font5;
        font5.setPointSize(23);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font5);
        tableServices->setItem(0, 0, __qtablewidgetitem16);
        tableServices->setObjectName("tableServices");
        tableServices->setGeometry(QRect(660, 140, 811, 251));
        tableServices->setMinimumSize(QSize(220, 50));
        tableServices->setAutoFillBackground(true);
        tableServices->setStyleSheet(QString::fromUtf8(""));
        tableServices->setRowCount(8);
        tableServices->setColumnCount(8);
        Nom_3 = new QLineEdit(Widget);
        Nom_3->setObjectName("Nom_3");
        Nom_3->setGeometry(QRect(180, 80, 511, 31));
        Nom_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(880, 70, 101, 51));
        pushButton_9->setFont(font1);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_sort = new QLabel(Widget);
        label_sort->setObjectName("label_sort");
        label_sort->setGeometry(QRect(1100, -60, 62, 312));
        combo_sort = new QComboBox(Widget);
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->setObjectName("combo_sort");
        combo_sort->setGeometry(QRect(1400, 90, 73, 26));
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
        label_39 = new QLabel(Widget);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(-10, -70, 1811, 851));
        label_39->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        supprimerButton = new QPushButton(Widget);
        supprimerButton->setObjectName("supprimerButton");
        supprimerButton->setGeometry(QRect(470, 650, 119, 39));
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
        modifierButton = new QPushButton(Widget);
        modifierButton->setObjectName("modifierButton");
        modifierButton->setGeometry(QRect(300, 650, 119, 39));
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
        ajouterButton = new QPushButton(Widget);
        ajouterButton->setObjectName("ajouterButton");
        ajouterButton->setGeometry(QRect(150, 650, 119, 39));
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
        pushButton_23 = new QPushButton(Widget);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(1430, 760, 101, 51));
        pushButton_23->setFont(font1);
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
        btnExportPDF = new QPushButton(Widget);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setGeometry(QRect(1440, 700, 141, 51));
        btnExportPDF->setFont(font1);
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
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(600, 400, 1011, 301));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(219, 20, 711, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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
        lineEdit_responsable = new QLineEdit(Widget);
        lineEdit_responsable->setObjectName("lineEdit_responsable");
        lineEdit_responsable->setGeometry(QRect(370, 250, 201, 36));
        lineEdit_responsable->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_name = new QLineEdit(Widget);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(370, 190, 201, 36));
        lineEdit_name->setMinimumSize(QSize(8, 0));
        lineEdit_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_id = new QLineEdit(Widget);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(370, 300, 201, 36));
        lineEdit_id->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit {\n"
"	\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
""));
        label_id = new QLabel(Widget);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(250, 190, 73, 35));
        label_name = new QLabel(Widget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(250, 240, 40, 35));
        label_resp = new QLabel(Widget);
        label_resp->setObjectName("label_resp");
        label_resp->setGeometry(QRect(230, 290, 91, 35));
        combo_type = new QComboBox(Widget);
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->setObjectName("combo_type");
        combo_type->setGeometry(QRect(340, 400, 237, 26));
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
        spin_budget = new QDoubleSpinBox(Widget);
        spin_budget->setObjectName("spin_budget");
        spin_budget->setGeometry(QRect(340, 450, 237, 22));
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
        combo_priority = new QComboBox(Widget);
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->setObjectName("combo_priority");
        combo_priority->setGeometry(QRect(340, 500, 237, 26));
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
        combo_state = new QComboBox(Widget);
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->setObjectName("combo_state");
        combo_state->setGeometry(QRect(340, 540, 237, 26));
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
        dateEdit_date = new QDateEdit(Widget);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setGeometry(QRect(330, 580, 237, 22));
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
        label_date = new QLabel(Widget);
        label_date->setObjectName("label_date");
        label_date->setGeometry(QRect(230, 570, 39, 35));
        label_state = new QLabel(Widget);
        label_state->setObjectName("label_state");
        label_state->setGeometry(QRect(230, 530, 33, 35));
        label_priority = new QLabel(Widget);
        label_priority->setObjectName("label_priority");
        label_priority->setGeometry(QRect(220, 490, 55, 35));
        label_budget = new QLabel(Widget);
        label_budget->setObjectName("label_budget");
        label_budget->setGeometry(QRect(210, 440, 55, 35));
        label_type = new QLabel(Widget);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(230, 390, 38, 35));
        btnIA = new QPushButton(Widget);
        btnIA->setObjectName("btnIA");
        btnIA->setGeometry(QRect(1520, 70, 93, 41));
        btnIA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(255, 105, 180); /* rose vif */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"}\n"
""));
        label_39->raise();
        frame_2->raise();
        tableServices->raise();
        Nom_3->raise();
        pushButton_9->raise();
        label_sort->raise();
        combo_sort->raise();
        supprimerButton->raise();
        modifierButton->raise();
        ajouterButton->raise();
        pushButton_23->raise();
        btnExportPDF->raise();
        widget->raise();
        lineEdit_responsable->raise();
        lineEdit_name->raise();
        lineEdit_id->raise();
        label_id->raise();
        label_name->raise();
        label_resp->raise();
        combo_type->raise();
        spin_budget->raise();
        combo_priority->raise();
        combo_state->raise();
        dateEdit_date->raise();
        label_date->raise();
        label_state->raise();
        label_priority->raise();
        label_budget->raise();
        label_type->raise();
        btnIA->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "NEOCITY", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "RH", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "R\303\251sidence", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "resident", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Widget", "Evenement", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Widget", "Services", nullptr));
        label_32->setText(QCoreApplication::translate("Widget", "NEOCITY", nullptr));
        RH_2->setText(QCoreApplication::translate("Widget", "RH", nullptr));
        residence_3->setText(QCoreApplication::translate("Widget", "R\303\251sidence", nullptr));
        resident->setText(QCoreApplication::translate("Widget", "resident", nullptr));
        pushButton_25->setText(QCoreApplication::translate("Widget", "Evenement", nullptr));
        pushButton_26->setText(QCoreApplication::translate("Widget", "Services", nullptr));
        label_53->setText(QString());
        label_65->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableServices->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableServices->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableServices->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableServices->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableServices->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "piriorite ", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableServices->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "etat ", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableServices->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableServices->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Widget", "date", nullptr));

        const bool __sortingEnabled = tableServices->isSortingEnabled();
        tableServices->setSortingEnabled(false);
        tableServices->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        Nom_3->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Nom_3->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("Widget", "rechercher", nullptr));
        label_sort->setText(QCoreApplication::translate("Widget", "Trier par :", nullptr));
        combo_sort->setItemText(0, QCoreApplication::translate("Widget", "Budget", nullptr));
        combo_sort->setItemText(1, QCoreApplication::translate("Widget", "Priorit\303\251", nullptr));
        combo_sort->setItemText(2, QCoreApplication::translate("Widget", "\303\211tat", nullptr));

        label_39->setText(QString());
        supprimerButton->setText(QCoreApplication::translate("Widget", "Supprimer", nullptr));
        modifierButton->setText(QCoreApplication::translate("Widget", "Modifier", nullptr));
        ajouterButton->setText(QCoreApplication::translate("Widget", "Ajouter \360\237\245\260", nullptr));
        pushButton_23->setText(QCoreApplication::translate("Widget", "export", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("Widget", "btnExportPDF", nullptr));
        btnStats->setText(QCoreApplication::translate("Widget", "Afficher Statistiques  \360\237\214\270", nullptr));
        label_id->setText(QCoreApplication::translate("Widget", "ID Service :", nullptr));
        label_name->setText(QCoreApplication::translate("Widget", "Nom :", nullptr));
        label_resp->setText(QCoreApplication::translate("Widget", "Responsable :", nullptr));
        combo_type->setItemText(0, QCoreApplication::translate("Widget", "Transport", nullptr));
        combo_type->setItemText(1, QCoreApplication::translate("Widget", "Propret\303\251", nullptr));
        combo_type->setItemText(2, QCoreApplication::translate("Widget", "\303\211clairage", nullptr));
        combo_type->setItemText(3, QCoreApplication::translate("Widget", "Eau", nullptr));
        combo_type->setItemText(4, QCoreApplication::translate("Widget", "Sant\303\251", nullptr));
        combo_type->setItemText(5, QCoreApplication::translate("Widget", "S\303\251curit\303\251", nullptr));

        spin_budget->setPrefix(QCoreApplication::translate("Widget", "$ ", nullptr));
        combo_priority->setItemText(0, QCoreApplication::translate("Widget", "Faible", nullptr));
        combo_priority->setItemText(1, QCoreApplication::translate("Widget", "Moyen", nullptr));
        combo_priority->setItemText(2, QCoreApplication::translate("Widget", "\303\211lev\303\251", nullptr));

        combo_state->setItemText(0, QCoreApplication::translate("Widget", "Actif", nullptr));
        combo_state->setItemText(1, QCoreApplication::translate("Widget", "En attente", nullptr));
        combo_state->setItemText(2, QCoreApplication::translate("Widget", "Suspendu", nullptr));

        label_date->setText(QCoreApplication::translate("Widget", "Date :", nullptr));
        label_state->setText(QCoreApplication::translate("Widget", "\303\211tat :", nullptr));
        label_priority->setText(QCoreApplication::translate("Widget", "Priorit\303\251 :", nullptr));
        label_budget->setText(QCoreApplication::translate("Widget", "Budget :", nullptr));
        label_type->setText(QCoreApplication::translate("Widget", "Type :", nullptr));
        btnIA->setText(QCoreApplication::translate("Widget", "Lancer IA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
