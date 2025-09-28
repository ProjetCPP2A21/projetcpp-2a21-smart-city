/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_3;
    QTextBrowser *textBrowser_8;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_5;
    QTextBrowser *textBrowser_6;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_7;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_7;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1241, 588);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(-18, -1, 221, 601));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(44, 62, 80);\n"
"border-radius: 20px;"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 20, 141, 101));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/cropped_circle_image.png);\n"
"image: url(:/cropped_circle_image.png);"));
        textBrowser_8 = new QTextBrowser(Widget);
        textBrowser_8->setObjectName("textBrowser_8");
        textBrowser_8->setGeometry(QRect(260, 50, 461, 41));
        textBrowser_8->setFrameShape(QFrame::Shape::NoFrame);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 510, 90, 29));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(230, 150, 221, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_3 = new QTextBrowser(layoutWidget);
        textBrowser_3->setObjectName("textBrowser_3");

        verticalLayout->addWidget(textBrowser_3);

        textBrowser_2 = new QTextBrowser(layoutWidget);
        textBrowser_2->setObjectName("textBrowser_2");

        verticalLayout->addWidget(textBrowser_2);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        textBrowser_5 = new QTextBrowser(layoutWidget);
        textBrowser_5->setObjectName("textBrowser_5");

        verticalLayout->addWidget(textBrowser_5);

        textBrowser_6 = new QTextBrowser(layoutWidget);
        textBrowser_6->setObjectName("textBrowser_6");

        verticalLayout->addWidget(textBrowser_6);

        textBrowser_4 = new QTextBrowser(layoutWidget);
        textBrowser_4->setObjectName("textBrowser_4");

        verticalLayout->addWidget(textBrowser_4);

        textBrowser_7 = new QTextBrowser(layoutWidget);
        textBrowser_7->setObjectName("textBrowser_7");

        verticalLayout->addWidget(textBrowser_7);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(480, 150, 258, 321));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_3 = new QTextEdit(layoutWidget1);
        textEdit_3->setObjectName("textEdit_3");

        gridLayout_2->addWidget(textEdit_3, 5, 0, 1, 1);

        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName("textEdit");

        gridLayout_2->addWidget(textEdit, 2, 0, 1, 1);

        textEdit_5 = new QTextEdit(layoutWidget1);
        textEdit_5->setObjectName("textEdit_5");

        gridLayout_2->addWidget(textEdit_5, 7, 0, 1, 1);

        textEdit_2 = new QTextEdit(layoutWidget1);
        textEdit_2->setObjectName("textEdit_2");

        gridLayout_2->addWidget(textEdit_2, 6, 0, 1, 1);

        textEdit_7 = new QTextEdit(layoutWidget1);
        textEdit_7->setObjectName("textEdit_7");

        gridLayout_2->addWidget(textEdit_7, 3, 0, 1, 1);

        textEdit_4 = new QTextEdit(layoutWidget1);
        textEdit_4->setObjectName("textEdit_4");

        gridLayout_2->addWidget(textEdit_4, 1, 0, 1, 1);

        textEdit_6 = new QTextEdit(layoutWidget1);
        textEdit_6->setObjectName("textEdit_6");

        gridLayout_2->addWidget(textEdit_6, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 160, 121, 41));
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
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 220, 121, 41));
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
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 280, 121, 41));
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
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 340, 121, 41));
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
        label->raise();
        textBrowser_8->raise();
        pushButton->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        label_3->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        label_3->setText(QString());
        textBrowser_8->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700;\">ajouter un empoloyer</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "valider", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">nom</span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">prenom</span></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">Id</span></p></body></html>", nullptr));
        textBrowser_5->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">sexe</span></p></body></html>", nullptr));
        textBrowser_6->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">telephone</span></p></body></html>", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">salaire</span></p></body></html>", nullptr));
        textBrowser_7->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700;\">responsabilit\303\251</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "RH", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "Residence", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "service", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "evenement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
