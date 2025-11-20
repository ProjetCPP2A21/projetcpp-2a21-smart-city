QT       += core gui
QT       += core gui sql
QT += core gui widgets sql
QT += network
QT += quick positioning location quick quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    evenement.cpp \
    main.cpp \
    gevenement.cpp \
    connection.cpp \
    statistique.cpp

HEADERS += \
    evenement.h \
    gevenement.h \
    connection.h \
    statistique.h

FORMS += \
    gevenement.ui



# (optionnel) si Qt n’arrive toujours pas à inclure, ajoute une ligne includePath :
INCLUDEPATH += $$PWD/Excel
DEPENDPATH += $$PWD/Excel
# Ajouter le dossier où se trouve QXlsx
include(Excel/QXlsx/QXlsx/qxlsx.pri)
INCLUDEPATH += "C:/Users/ASUS/Desktop/Smart City/GEvenements/ONNX_IA/include"
LIBS += -L"C:/Users/ASUS/Desktop/Smart City/GEvenements/ONNX_IA/lib" -lonnxruntime

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

DISTFILES += \
    Map.qml
