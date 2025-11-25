QT += core gui sql widgets
QT += core gui sql widgets printsupport
QT += core gui widgets charts
QT += core gui sql widgets printsupport charts
QT += charts
QT += core gui network sql charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VotreNomProjet
TEMPLATE = app

SOURCES += \
    email.cpp \
    main.cpp \
    widget.cpp \
    connection.cpp \
    service.cpp

HEADERS += \
    email.h \
    widget.h \
    connection.h \
    service.h

FORMS += \
    widget.ui
