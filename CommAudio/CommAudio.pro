#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T23:09:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CommAudio
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    circularbuffer.cpp

HEADERS  += mainwindow.h \
    circularbuffer.h \
    globals.h

FORMS    += mainwindow.ui