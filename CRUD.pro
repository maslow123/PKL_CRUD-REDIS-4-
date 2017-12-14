#-------------------------------------------------
#
# Project created by QtCreator 2017-12-12T08:08:18
#
#-------------------------------------------------

QT       += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRUD
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    redis.cpp

HEADERS  += mainwindow.h \
    client.h \
    redis.h

FORMS    += mainwindow.ui
