QT       += core gui sql printsupport charts network widgets quickwidgets qml quick positioning location serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    employer.cpp \
    gemployer.cpp \
    residence.cpp \
    CrudResidence.cpp \
    smtp.cpp \
    residents.cpp \
    gresidents.cpp \
    service.cpp \
    widget_Service.cpp \
    email_Service.cpp \
    gevenement.cpp \
    statistique.cpp \
    evenement.cpp \
    datedelegate.cpp \
    classification.cpp \
    arduino.cpp

HEADERS += \
    mainwindow.h \
    connection.h \
    employer.h \
    gemployer.h \
    residence.h \
    CrudResidence.h \
    smtp.h \
    residents.h \
    gresidents.h \
    service.h \
    widget_Service.h \
    email_Service.h \
    gevenement.h \
    statistique.h \
    evenement.h \
    datedelegate.h \
    classification.h \
    arduino.h


FORMS += \
    mainwindow.ui

# (optionnel) si Qt n’arrive toujours pas à inclure, ajoute une ligne includePath :
INCLUDEPATH += $$PWD/Excel
DEPENDPATH += $$PWD/Excel
# Ajouter le dossier où se trouve QXlsx
include(Excel/QXlsx/QXlsx/qxlsx.pri)
INCLUDEPATH += "$$PWD/ONNX_IA/include"
LIBS += -L"$$PWD/ONNX_IA/lib" -lonnxruntime

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    img.qrc

DISTFILES += \
    eye_open.jpg
