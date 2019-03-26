#-------------------------------------------------
#
# Project created by QtCreator 2019-01-26T09:40:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dvsQt
TEMPLATE = app

CONFIG += c++11 strict_c++

QMAKE_CXXFLAGS += -D_DEFAULT_SOURCE=1

SOURCES += main.cpp\
        mainwindow.cpp \
    recievingthread.cpp \
    dvsimagedrawer.cpp \
    dvsfilesaver.cpp

HEADERS  += mainwindow.h \
    recievingthread.h \
    dvsimagedrawer.h \
    dvsfilesaver.h

FORMS    += mainwindow.ui

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/x86_64-linux-gnu/ -lcaer

INCLUDEPATH += $$PWD/../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../usr/lib/x86_64-linux-gnu
