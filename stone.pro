#-------------------------------------------------
#
# Project created by QtCreator 2017-08-20T19:45:06
#
#-------------------------------------------------

QT       += core gui quickwidgets webengine webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stone
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stoneshell.cpp

HEADERS  += mainwindow.h \
    stoneshell.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    main.qml
