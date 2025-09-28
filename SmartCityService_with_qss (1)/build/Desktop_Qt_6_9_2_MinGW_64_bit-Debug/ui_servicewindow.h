/********************************************************************************
** Form generated from reading UI file 'servicewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICEWINDOW_H
#define UI_SERVICEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
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

class Ui_ServiceWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupSearch;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupDetails;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayoutButtons;
    QPushButton *btn_add;
    QPushButton *btn_modify;
    QPushButton *btn_delete;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_type;
    QComboBox *combo_type;
    QLabel *label_resp;
    QLineEdit *lineEdit_responsable;
    QLabel *label_search;
    QLabel *label_budget;
    QDoubleSpinBox *spin_budget;
    QLabel *label_priority;
    QLabel *label_state;
    QComboBox *combo_state;
    QLabel *label_date;
    QDateEdit *dateEdit_date;
    QLineEdit *lineEdit;
    QComboBox *combo_priority;
    QLineEdit *lineEdit_search;
    QPushButton *btn_search;
    QLabel *label_sort;
    QComboBox *combo_sort;
    QPushButton *btn_export;
    QTableWidget *tableServices;

    void setupUi(QWidget *ServiceWindow)
    {
        if (ServiceWindow->objectName().isEmpty())
            ServiceWindow->setObjectName("ServiceWindow");
        ServiceWindow->resize(1297, 426);
        verticalLayout = new QVBoxLayout(ServiceWindow);
        verticalLayout->setObjectName("verticalLayout");
        groupSearch = new QGroupBox(ServiceWindow);
        groupSearch->setObjectName("groupSearch");
        groupSearch->setMinimumSize(QSize(220, 220));
        groupSearch->setStyleSheet(QString::fromUtf8(""));
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

        label_type = new QLabel(groupSearch);
        label_type->setObjectName("label_type");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_type);

        combo_type = new QComboBox(groupSearch);
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->addItem(QString());
        combo_type->setObjectName("combo_type");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, combo_type);

        label_resp = new QLabel(groupSearch);
        label_resp->setObjectName("label_resp");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_resp);

        lineEdit_responsable = new QLineEdit(groupSearch);
        lineEdit_responsable->setObjectName("lineEdit_responsable");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEdit_responsable);

        label_search = new QLabel(groupSearch);
        label_search->setObjectName("label_search");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_search);

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

        lineEdit = new QLineEdit(groupSearch);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, lineEdit);

        combo_priority = new QComboBox(groupSearch);
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->addItem(QString());
        combo_priority->setObjectName("combo_priority");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, combo_priority);


        horizontalLayout->addLayout(formLayout);

        lineEdit_search = new QLineEdit(groupSearch);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setAutoFillBackground(true);

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


        verticalLayout->addWidget(groupSearch);

        tableServices = new QTableWidget(ServiceWindow);
        if (tableServices->columnCount() < 7)
            tableServices->setColumnCount(7);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setBackground(QColor(162, 212, 250, 114));
        tableServices->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setBackground(QColor(162, 212, 250, 114));
        tableServices->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        __qtablewidgetitem2->setBackground(QColor(162, 212, 250, 114));
        tableServices->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        __qtablewidgetitem3->setBackground(QColor(162, 212, 250, 114));
        tableServices->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        __qtablewidgetitem4->setBackground(QColor(162, 212, 250, 114));
        tableServices->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        __qtablewidgetitem5->setBackground(QColor(0, 0, 127));
        tableServices->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        __qtablewidgetitem6->setBackground(QColor(0, 0, 127));
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
        tableServices->setMinimumSize(QSize(220, 50));
        tableServices->setAutoFillBackground(true);
        tableServices->setStyleSheet(QString::fromUtf8(""));
        tableServices->setRowCount(4);
        tableServices->setColumnCount(7);

        verticalLayout->addWidget(tableServices);


        retranslateUi(ServiceWindow);

        QMetaObject::connectSlotsByName(ServiceWindow);
    } // setupUi

    void retranslateUi(QWidget *ServiceWindow)
    {
        groupSearch->setTitle(QCoreApplication::translate("ServiceWindow", "gestion des Service:", nullptr));
        groupDetails->setTitle(QCoreApplication::translate("ServiceWindow", "D\303\251tails du service", nullptr));
        btn_add->setText(QCoreApplication::translate("ServiceWindow", "Ajouter", nullptr));
        btn_modify->setText(QCoreApplication::translate("ServiceWindow", "Modifier", nullptr));
        btn_delete->setText(QCoreApplication::translate("ServiceWindow", "Supprimer", nullptr));
        label_id->setText(QCoreApplication::translate("ServiceWindow", "ID Service :", nullptr));
        label_name->setText(QCoreApplication::translate("ServiceWindow", "Nom :", nullptr));
        label_type->setText(QCoreApplication::translate("ServiceWindow", "Type :", nullptr));
        combo_type->setItemText(0, QCoreApplication::translate("ServiceWindow", "Transport", nullptr));
        combo_type->setItemText(1, QCoreApplication::translate("ServiceWindow", "Propret\303\251", nullptr));
        combo_type->setItemText(2, QCoreApplication::translate("ServiceWindow", "\303\211clairage", nullptr));
        combo_type->setItemText(3, QCoreApplication::translate("ServiceWindow", "Eau", nullptr));
        combo_type->setItemText(4, QCoreApplication::translate("ServiceWindow", "Sant\303\251", nullptr));
        combo_type->setItemText(5, QCoreApplication::translate("ServiceWindow", "S\303\251curit\303\251", nullptr));

        label_resp->setText(QCoreApplication::translate("ServiceWindow", "Responsable :", nullptr));
        label_search->setText(QCoreApplication::translate("ServiceWindow", "Recherche :", nullptr));
        label_budget->setText(QCoreApplication::translate("ServiceWindow", "Budget :", nullptr));
        spin_budget->setPrefix(QCoreApplication::translate("ServiceWindow", "$ ", nullptr));
        label_priority->setText(QCoreApplication::translate("ServiceWindow", "Priorit\303\251 :", nullptr));
        label_state->setText(QCoreApplication::translate("ServiceWindow", "\303\211tat :", nullptr));
        combo_state->setItemText(0, QCoreApplication::translate("ServiceWindow", "Actif", nullptr));
        combo_state->setItemText(1, QCoreApplication::translate("ServiceWindow", "En attente", nullptr));
        combo_state->setItemText(2, QCoreApplication::translate("ServiceWindow", "Suspendu", nullptr));

        label_date->setText(QCoreApplication::translate("ServiceWindow", "Date :", nullptr));
        combo_priority->setItemText(0, QCoreApplication::translate("ServiceWindow", "Faible", nullptr));
        combo_priority->setItemText(1, QCoreApplication::translate("ServiceWindow", "Moyen", nullptr));
        combo_priority->setItemText(2, QCoreApplication::translate("ServiceWindow", "\303\211lev\303\251", nullptr));

        btn_search->setText(QCoreApplication::translate("ServiceWindow", "Rechercher", nullptr));
        label_sort->setText(QCoreApplication::translate("ServiceWindow", "Trier par :", nullptr));
        combo_sort->setItemText(0, QCoreApplication::translate("ServiceWindow", "Budget", nullptr));
        combo_sort->setItemText(1, QCoreApplication::translate("ServiceWindow", "Priorit\303\251", nullptr));
        combo_sort->setItemText(2, QCoreApplication::translate("ServiceWindow", "\303\211tat", nullptr));

        btn_export->setText(QCoreApplication::translate("ServiceWindow", "Exporter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableServices->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ServiceWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableServices->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ServiceWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableServices->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ServiceWindow", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableServices->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ServiceWindow", "Budget", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableServices->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ServiceWindow", "Priorit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableServices->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ServiceWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableServices->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ServiceWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableServices->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ServiceWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableServices->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ServiceWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableServices->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ServiceWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableServices->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ServiceWindow", "Nouvelle ligne", nullptr));
        (void)ServiceWindow;
    } // retranslateUi

};

namespace Ui {
    class ServiceWindow: public Ui_ServiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICEWINDOW_H
