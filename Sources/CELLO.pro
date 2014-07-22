#-------------------------------------------------
#
# Project created by QtCreator 2014-04-27T14:19:16
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CELLO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagedialog.cpp

HEADERS  += mainwindow.h \
    imagedialog.h

FORMS    += mainwindow.ui \
    imagedialog.ui

RESOURCES += \
    resedit.qrc

QMAKE_CXXFLAGS += -std=c++11

