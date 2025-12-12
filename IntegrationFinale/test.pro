QT       += core gui sql printsupport charts network widgets quickwidgets qml quick positioning location serialport multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
PRECOMPILED_HEADER = Bibliotheque.h
CONFIG += precompile_header

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
    Bibliotheque.h \
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


# --- Début de l'automatisation de la copie ---

# 1. Définir quel dossier copier (Source) et où le mettre (Destination)
SOURCE_DIR = $$PWD/Animation
DEST_DIR = $$OUT_PWD/debug/Animation  # En mode debug
CONFIG(release, debug|release): DEST_DIR = $$OUT_PWD/release/Animation # Si on passe en release

# 2. Adapter les chemins pour Windows (remplacer / par \)
# Version corrigée pour gérer les espaces dans "Smart City"
win32 {
    SOURCE_DIR_WIN = $$replace(SOURCE_DIR, /, \\)
    DEST_DIR_WIN = $$replace(DEST_DIR, /, \\)
    # Les guillemets \" sont obligatoires ici
    QMAKE_POST_LINK += xcopy /E /I /Y \"$$SOURCE_DIR_WIN\" \"$$DEST_DIR_WIN\"
}

# --- Fin de l'automatisation ---
