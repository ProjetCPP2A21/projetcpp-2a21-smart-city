QT += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VotreNomProjet
TEMPLATE = app

SOURCES += \
    main.cpp \
    widget.cpp \
    connection.cpp \
    service.cpp

HEADERS += \
    widget.h \
    connection.h \
    service.h

FORMS += \
    widget.ui
