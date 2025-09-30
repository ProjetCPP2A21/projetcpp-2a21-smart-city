/********************************************************************************
** Form generated from reading UI file 'service.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_service
{
public:
    QGroupBox *groupSearch;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupDetails;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayoutButtons;
    QPushButton *btn_add;
    QPushButton *btn_modify;
    QPushButton *btn_delete;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_resp;
    QLineEdit *lineEdit_responsable;
    QLabel *label_search;
    QLineEdit *lineEdit;
    QLabel *label_budget;
    QDoubleSpinBox *spin_budget;
    QLabel *label_priority;
    QComboBox *combo_priority;
    QLabel *label_state;
    QComboBox *combo_state;
    QLabel *label_date;
    QDateEdit *dateEdit_date;
    QLabel *label_type;
    QComboBox *combo_type;
    QLineEdit *lineEdit_search;
    QPushButton *btn_search;
    QLabel *label_sort;
    QComboBox *combo_sort;
    QPushButton *btn_export;
    QTableWidget *tableServices;
    QFrame *frame_2;
    QLabel *label_16;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QLabel *label;

    void setupUi(QWidget *service)
    {
        if (service->objectName().isEmpty())
            service->setObjectName("service");
        service->resize(1360, 768);
        groupSearch = new QGroupBox(service);
        groupSearch->setObjectName("groupSearch");
        groupSearch->setGeometry(QRect(200, 40, 1261, 431));
        groupSearch->setMinimumSize(QSize(220, 220));
        groupSearch->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(groupSearch);
        horizontalLayout->setObjectName("horizontalLayout");
        groupDetails = new QGroupBox(groupSearch);
        groupDetails->setObjectName("groupDetails");
        horizontalLayout_2 = new QHBoxLayout(groupDetails);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayoutButtons = new QVBoxLayout();
        verticalLayoutButtons->setObjectName("verticalLayoutButtons");
        btn_add = new QPushButton(groupDetails);
        btn_add->setObjectName("btn_add");

        verticalLayoutButtons->addWidget(btn_add);

        btn_modify = new QPushButton(groupDetails);
        btn_modify->setObjectName("btn_modify");

        verticalLayoutButtons->addWidget(btn_modify);

        btn_delete = new QPushButton(groupDetails);
        btn_delete->setObjectName("btn_delete");

        verticalLayoutButtons->addWidget(btn_delete);


        horizontalLayout_2->addLayout(verticalLayoutButtons);


        horizontalLayout->addWidget(groupDetails);

        frame = new QFrame(groupSearch);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout->addWidget(frame);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_id = new QLabel(groupSearch);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_id);

        lineEdit_id = new QLineEdit(groupSearch);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_id);

        label_name = new QLabel(groupSearch);
        label_name->setObjectName("label_name");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_name);

        lineEdit_name = new QLineEdit(groupSearch);
        lineEdit_name->setObjectName("lineEdit_name");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_name);

        label_resp = new QLabel(groupSearch);
        label_resp->setObjectName("label_resp");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_resp);

        lineEdit_responsable = new QLineEdit(groupSearch);
        lineEdit_responsable->setObjectName("lineEdit_responsable");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEdit_responsable);

        label_search = new QLabel(groupSearch);
        label_search->setObjectName("label_search");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_search);

        lineEdit = new QLineEdit(groupSearch);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, lineEdit);

        label_budget = new QLabel(groupSearch);
        label_budget->setObjectName("label_budget");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, label_budget);

        spin_budget = new QDoubleSpinBox(groupSearch);
        spin_budget->setObjectName("spin_budget");
        spin_budget->setMaximum(100000000.000000000000000);

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, spin_budget);

        label_priority = new QLabel(groupSearch);
        label_priority->setObjectName("label_priority");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, label_priority);

        combo_priority = new QComboBox(groupSearch);
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->setObjectName("combo_priority");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, combo_priority);

        label_state = new QLabel(groupSearch);
        label_state->setObjectName("label_state");

        formLayout->setWidget(9, QFormLayout::ItemRole::LabelRole, label_state);

        combo_state = new QComboBox(groupSearch);
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->addItem(QString());
        combo_state->setObjectName("combo_state");

        formLayout->setWidget(9, QFormLayout::ItemRole::FieldRole, combo_state);

        label_date = new QLabel(groupSearch);
        label_date->setObjectName("label_date");

        formLayout->setWidget(10, QFormLayout::ItemRole::LabelRole, label_date);

        dateEdit_date = new QDateEdit(groupSearch);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setCalendarPopup(true);

        formLayout->setWidget(10, QFormLayout::ItemRole::FieldRole, dateEdit_date);

        label_type = new QLabel(groupSearch);
        label_type->setObjectName("label_type");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_type);

        combo_type = new QComboBox(groupSearch);
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->setObjectName("combo_type");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, combo_type);


        horizontalLayout->addLayout(formLayout);

        lineEdit_search = new QLineEdit(groupSearch);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setAutoFillBackground(false);

        horizontalLayout->addWidget(lineEdit_search);

        btn_search = new QPushButton(groupSearch);
        btn_search->setObjectName("btn_search");

        horizontalLayout->addWidget(btn_search);

        label_sort = new QLabel(groupSearch);
        label_sort->setObjectName("label_sort");

        horizontalLayout->addWidget(label_sort);

        combo_sort = new QComboBox(groupSearch);
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->addItem(QString());
        combo_sort->setObjectName("combo_sort");

        horizontalLayout->addWidget(combo_sort);

        btn_export = new QPushButton(groupSearch);
        btn_export->setObjectName("btn_export");

        horizontalLayout->addWidget(btn_export);

        tableServices = new QTableWidget(service);
        if (tableServices->columnCount() < 7)
            tableServices->setColumnCount(7);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setBackground(QColor(0, 0, 0, 0));
        tableServices->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setBackground(QColor(0, 0, 0, 0));
        tableServices->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        __qtablewidgetitem2->setBackground(QColor(0, 0, 0, 0));
        tableServices->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        __qtablewidgetitem3->setBackground(QColor(0, 0, 0, 0));
        tableServices->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        __qtablewidgetitem4->setBackground(QColor(0, 0, 0, 0));
        tableServices->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        __qtablewidgetitem5->setBackground(QColor(0, 0, 0, 0));
        tableServices->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        __qtablewidgetitem6->setBackground(QColor(0, 0, 0, 0));
        tableServices->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableServices->rowCount() < 4)
            tableServices->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableServices->setVerticalHeaderItem(3, __qtablewidgetitem10);
        tableServices->setObjectName("tableServices");
        tableServices->setGeometry(QRect(210, 530, 1161, 271));
        tableServices->setMinimumSize(QSize(220, 50));
        tableServices->setAutoFillBackground(true);
        tableServices->setStyleSheet(QString::fromUtf8("\n"
"font: 10pt \"Segoe UI\";\n"
""));
        tableServices->setRowCount(4);
        tableServices->setColumnCount(7);
        frame_2 = new QFrame(service);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(-10, -10, 211, 791));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
" border-radius: 20px;\n"
"background-color : #2C3E50;\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(80, 50, 121, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift")});
        font3.setPointSize(18);
        font3.setBold(true);
        label_16->setFont(font3);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 130, 131, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bahnschrift")});
        font4.setBold(true);
        pushButton->setFont(font4);
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
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 190, 171, 61));
        pushButton_5->setFont(font4);
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
        pushButton_7 = new QPushButton(frame_2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 250, 171, 61));
        pushButton_7->setFont(font4);
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
        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 370, 181, 61));
        pushButton_8->setFont(font4);
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
        pushButton_10 = new QPushButton(frame_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(0, 310, 171, 61));
        pushButton_10->setFont(font4);
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
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 63, 51));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/img/cropped_circle_image.png);"));
        label->setScaledContents(true);

        retranslateUi(service);

        QMetaObject::connectSlotsByName(service);
    } // setupUi

    void retranslateUi(QWidget *service)
    {
        service->setWindowTitle(QCoreApplication::translate("service", "service", nullptr));
        groupSearch->setTitle(QCoreApplication::translate("service", "gestion des Service:", nullptr));
        groupDetails->setTitle(QCoreApplication::translate("service", "D\303\251tails du service", nullptr));
        btn_add->setText(QCoreApplication::translate("service", "Ajouter", nullptr));
        btn_modify->setText(QCoreApplication::translate("service", "Modifier", nullptr));
        btn_delete->setText(QCoreApplication::translate("service", "Supprimer", nullptr));
        label_id->setText(QCoreApplication::translate("service", "ID Service :", nullptr));
        label_name->setText(QCoreApplication::translate("service", "Nom :", nullptr));
        label_resp->setText(QCoreApplication::translate("service", "Responsable :", nullptr));
        label_search->setText(QCoreApplication::translate("service", "Recherche :", nullptr));
        label_budget->setText(QCoreApplication::translate("service", "Budget :", nullptr));
        spin_budget->setPrefix(QCoreApplication::translate("service", "$ ", nullptr));
        label_priority->setText(QCoreApplication::translate("service", "Priorit\303\251 :", nullptr));
        combo_priority->setItemText(0, QCoreApplication::translate("service", "Faible", nullptr));
        combo_priority->setItemText(1, QCoreApplication::translate("service", "Moyen", nullptr));
        combo_priority->setItemText(2, QCoreApplication::translate("service", "\303\211lev\303\251", nullptr));

        label_state->setText(QCoreApplication::translate("service", "\303\211tat :", nullptr));
        combo_state->setItemText(0, QCoreApplication::translate("service", "Actif", nullptr));
        combo_state->setItemText(1, QCoreApplication::translate("service", "En attente", nullptr));
        combo_state->setItemText(2, QCoreApplication::translate("service", "Suspendu", nullptr));

        label_date->setText(QCoreApplication::translate("service", "Date :", nullptr));
        label_type->setText(QCoreApplication::translate("service", "Type :", nullptr));
        combo_type->setItemText(0, QCoreApplication::translate("service", "Transport", nullptr));
        combo_type->setItemText(1, QCoreApplication::translate("service", "Propret\303\251", nullptr));
        combo_type->setItemText(2, QCoreApplication::translate("service", "\303\211clairage", nullptr));
        combo_type->setItemText(3, QCoreApplication::translate("service", "Eau", nullptr));
        combo_type->setItemText(4, QCoreApplication::translate("service", "Sant\303\251", nullptr));
        combo_type->setItemText(5, QCoreApplication::translate("service", "S\303\251curit\303\251", nullptr));

        btn_search->setText(QCoreApplication::translate("service", "Rechercher", nullptr));
        label_sort->setText(QCoreApplication::translate("service", "Trier par :", nullptr));
        combo_sort->setItemText(0, QCoreApplication::translate("service", "Budget", nullptr));
        combo_sort->setItemText(1, QCoreApplication::translate("service", "Priorit\303\251", nullptr));
        combo_sort->setItemText(2, QCoreApplication::translate("service", "\303\211tat", nullptr));

        btn_export->setText(QCoreApplication::translate("service", "Exporter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableServices->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("service", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableServices->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("service", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableServices->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("service", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableServices->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("service", "Budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableServices->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("service", "Priorit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableServices->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("service", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableServices->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("service", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableServices->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("service", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableServices->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("service", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableServices->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("service", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableServices->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("service", "Nouvelle ligne", nullptr));
        label_16->setText(QCoreApplication::translate("service", "NEOCITY", nullptr));
        pushButton->setText(QCoreApplication::translate("service", "RH", nullptr));
        pushButton_5->setText(QCoreApplication::translate("service", "R\303\251sidence", nullptr));
        pushButton_7->setText(QCoreApplication::translate("service", "resident", nullptr));
        pushButton_8->setText(QCoreApplication::translate("service", "Evenement", nullptr));
        pushButton_10->setText(QCoreApplication::translate("service", "Services", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class service: public Ui_service {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICE_H
