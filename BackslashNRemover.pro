#-------------------------------------------------
#
# Project created by QtCreator 2014-02-08T19:14:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BackslashNRemover
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parser.cpp \
    formoption.cpp

HEADERS  += mainwindow.h \
    parser.h \
    formoption.h

FORMS    += mainwindow.ui \
    formoption.ui
