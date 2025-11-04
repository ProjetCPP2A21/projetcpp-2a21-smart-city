/********************************************************************************
** Form generated from reading UI file 'service.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICE_H
#define UI_SERVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
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
    QLabel *label_5;
    QFrame *frame_5;
    QLabel *label_32;
    QPushButton *RH_2;
    QPushButton *residence_3;
    QPushButton *resident;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QLabel *label_53;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QComboBox *combo_type;
    QLabel *label_type;
    QLabel *label_budget;
    QDoubleSpinBox *spin_budget;
    QComboBox *combo_state;
    QDateEdit *dateEdit_date;
    QLabel *label_priority;
    QLabel *label_state;
    QLabel *label_date;
    QLineEdit *lineEdit_responsable;
    QLabel *label_resp;
    QComboBox *combo_priority;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayoutButtons;
    QPushButton *btn_add;
    QPushButton *btn_modify;
    QPushButton *btn_delete;
    QTableWidget *tableServices;
    QLineEdit *Nom_3;
    QPushButton *pushButton_9;
    QLabel *label_sort;
    QComboBox *combo_sort;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1640, 750);
        Widget->setMinimumSize(QSize(1640, 750));
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 191, 791));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_18 = new QLabel(frame_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(70, 40, 121, 31));
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
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 30, 51, 51));
        label_5->setTextFormat(Qt::TextFormat::MarkdownText);
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/cropped_circle_image.png")));
        label_5->setScaledContents(true);
        label_5->setWordWrap(false);
        label_5->setOpenExternalLinks(false);
        label_5->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
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
        layoutWidget_2 = new QWidget(Widget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(350, 220, 301, 511));
        formLayout = new QFormLayout(layoutWidget_2);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_id = new QLabel(layoutWidget_2);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_id);

        lineEdit_id = new QLineEdit(layoutWidget_2);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_id->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_id);

        label_name = new QLabel(layoutWidget_2);
        label_name->setObjectName("label_name");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(layoutWidget_2);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(0, 0, 0);\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    font-size: 12px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #2D89EF;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_name);

        combo_type = new QComboBox(layoutWidget_2);
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->setObjectName("combo_type");
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
"}"));

        formLayout->setWidget(4, QFormLayout::FieldRole, combo_type);

        label_type = new QLabel(layoutWidget_2);
        label_type->setObjectName("label_type");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_type);

        label_budget = new QLabel(layoutWidget_2);
        label_budget->setObjectName("label_budget");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_budget);

        spin_budget = new QDoubleSpinBox(layoutWidget_2);
        spin_budget->setObjectName("spin_budget");
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

        formLayout->setWidget(5, QFormLayout::FieldRole, spin_budget);

        combo_state = new QComboBox(layoutWidget_2);
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->setObjectName("combo_state");
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

        formLayout->setWidget(7, QFormLayout::FieldRole, combo_state);

        dateEdit_date = new QDateEdit(layoutWidget_2);
        dateEdit_date->setObjectName("dateEdit_date");
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

        formLayout->setWidget(8, QFormLayout::FieldRole, dateEdit_date);

        label_priority = new QLabel(layoutWidget_2);
        label_priority->setObjectName("label_priority");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_priority);

        label_state = new QLabel(layoutWidget_2);
        label_state->setObjectName("label_state");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_state);

        label_date = new QLabel(layoutWidget_2);
        label_date->setObjectName("label_date");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_date);

        lineEdit_responsable = new QLineEdit(layoutWidget_2);
        lineEdit_responsable->setObjectName("lineEdit_responsable");
        lineEdit_responsable->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_responsable);

        label_resp = new QLabel(layoutWidget_2);
        label_resp->setObjectName("label_resp");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_resp);

        combo_priority = new QComboBox(layoutWidget_2);
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->setObjectName("combo_priority");
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

        formLayout->setWidget(6, QFormLayout::FieldRole, combo_priority);

        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(210, 100, 121, 491));
        verticalLayoutButtons = new QVBoxLayout(layoutWidget);
        verticalLayoutButtons->setObjectName("verticalLayoutButtons");
        verticalLayoutButtons->setContentsMargins(0, 0, 0, 0);
        btn_add = new QPushButton(layoutWidget);
        btn_add->setObjectName("btn_add");
        btn_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayoutButtons->addWidget(btn_add);

        btn_modify = new QPushButton(layoutWidget);
        btn_modify->setObjectName("btn_modify");
        btn_modify->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayoutButtons->addWidget(btn_modify);

        btn_delete = new QPushButton(layoutWidget);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayoutButtons->addWidget(btn_delete);

        tableServices = new QTableWidget(Widget);
        if (tableServices->columnCount() < 7)
            tableServices->setColumnCount(7);
        QFont font2;
        font2.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        __qtablewidgetitem->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font3;
        font3.setBold(true);
        font3.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font3);
        __qtablewidgetitem1->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font3);
        __qtablewidgetitem2->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font3);
        __qtablewidgetitem3->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font3);
        __qtablewidgetitem4->setBackground(QColor(255, 255, 255, 114));
        tableServices->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font3);
        __qtablewidgetitem5->setBackground(QColor(255, 255, 255, 0));
        tableServices->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QFont font4;
        font4.setPointSize(7);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font4);
        __qtablewidgetitem6->setBackground(QColor(255, 255, 255));
        tableServices->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableServices->rowCount() < 8)
            tableServices->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(7, __qtablewidgetitem14);
        tableServices->setObjectName("tableServices");
        tableServices->setGeometry(QRect(710, 260, 751, 401));
        tableServices->setMinimumSize(QSize(220, 50));
        tableServices->setAutoFillBackground(true);
        tableServices->setStyleSheet(QString::fromUtf8(""));
        tableServices->setRowCount(8);
        tableServices->setColumnCount(7);
        Nom_3 = new QLineEdit(Widget);
        Nom_3->setObjectName("Nom_3");
        Nom_3->setGeometry(QRect(430, 50, 491, 31));
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
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(960, 40, 101, 51));
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
        label_sort->setGeometry(QRect(1100, -90, 62, 312));
        combo_sort = new QComboBox(Widget);
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->setObjectName("combo_sort");
        combo_sort->setGeometry(QRect(1240, 50, 73, 26));
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
        label_5->setText(QString());
        label_32->setText(QCoreApplication::translate("Widget", "NEOCITY", nullptr));
        RH_2->setText(QCoreApplication::translate("Widget", "RH", nullptr));
        residence_3->setText(QCoreApplication::translate("Widget", "R\303\251sidence", nullptr));
        resident->setText(QCoreApplication::translate("Widget", "resident", nullptr));
        pushButton_25->setText(QCoreApplication::translate("Widget", "Evenement", nullptr));
        pushButton_26->setText(QCoreApplication::translate("Widget", "Services", nullptr));
        label_53->setText(QString());
        label_id->setText(QCoreApplication::translate("Widget", "ID Service :", nullptr));
        label_name->setText(QCoreApplication::translate("Widget", "Nom :", nullptr));
        combo_type->setItemText(0, QCoreApplication::translate("Widget", "Transport", nullptr));
        combo_type->setItemText(1, QCoreApplication::translate("Widget", "Propret\303\251", nullptr));
        combo_type->setItemText(2, QCoreApplication::translate("Widget", "\303\211clairage", nullptr));
        combo_type->setItemText(3, QCoreApplication::translate("Widget", "Eau", nullptr));
        combo_type->setItemText(4, QCoreApplication::translate("Widget", "Sant\303\251", nullptr));
        combo_type->setItemText(5, QCoreApplication::translate("Widget", "S\303\251curit\303\251", nullptr));

        label_type->setText(QCoreApplication::translate("Widget", "Type :", nullptr));
        label_budget->setText(QCoreApplication::translate("Widget", "Budget :", nullptr));
        spin_budget->setPrefix(QCoreApplication::translate("Widget", "$ ", nullptr));
        combo_state->setItemText(0, QCoreApplication::translate("Widget", "Actif", nullptr));
        combo_state->setItemText(1, QCoreApplication::translate("Widget", "En attente", nullptr));
        combo_state->setItemText(2, QCoreApplication::translate("Widget", "Suspendu", nullptr));

        label_priority->setText(QCoreApplication::translate("Widget", "Priorit\303\251 :", nullptr));
        label_state->setText(QCoreApplication::translate("Widget", "\303\211tat :", nullptr));
        label_date->setText(QCoreApplication::translate("Widget", "Date :", nullptr));
        label_resp->setText(QCoreApplication::translate("Widget", "Responsable :", nullptr));
        combo_priority->setItemText(0, QCoreApplication::translate("Widget", "Faible", nullptr));
        combo_priority->setItemText(1, QCoreApplication::translate("Widget", "Moyen", nullptr));
        combo_priority->setItemText(2, QCoreApplication::translate("Widget", "\303\211lev\303\251", nullptr));

        btn_add->setText(QCoreApplication::translate("Widget", "Ajouter", nullptr));
        btn_modify->setText(QCoreApplication::translate("Widget", "Modifier", nullptr));
        btn_delete->setText(QCoreApplication::translate("Widget", "Supprimer", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableServices->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableServices->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableServices->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableServices->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "Budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableServices->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "Priorit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableServices->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableServices->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "ID", nullptr));
#if QT_CONFIG(tooltip)
        Nom_3->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">recherche un employ\303\251e</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Nom_3->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("Widget", "rechercher", nullptr));
        label_sort->setText(QCoreApplication::translate("Widget", "Trier par :", nullptr));
        combo_sort->setItemText(0, QCoreApplication::translate("Widget", "Budget", nullptr));
        combo_sort->setItemText(1, QCoreApplication::translate("Widget", "Priorit\303\251", nullptr));
        combo_sort->setItemText(2, QCoreApplication::translate("Widget", "\303\211tat", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_H
