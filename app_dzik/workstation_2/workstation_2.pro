#-------------------------------------------------
#
# Project created by QtCreator 2017-08-15T10:40:11
# by elektronicznyJuzek
#-------------------------------------------------

QT       += core gui
QT       += network
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = workstation_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    udp_workstation.cpp

HEADERS  += mainwindow.h \
    udp_workstation.h

FORMS    += mainwindow.ui
