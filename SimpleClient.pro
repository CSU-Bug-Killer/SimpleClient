#-------------------------------------------------
#
# Project created by QtCreator 2017-07-04T17:12:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = SimpleClient
TEMPLATE = app


SOURCES += main.cpp\
        testnet_c.cpp

HEADERS  += testnet_c.h

FORMS    += testnet_c.ui
