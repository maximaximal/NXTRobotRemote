#-------------------------------------------------
#
# Project created by QtCreator 2014-08-06T13:34:17
#
#-------------------------------------------------

QT      += core gui
QT      += bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotRemote
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ConnectNXT.cpp

HEADERS  += MainWindow.h \
    ConnectNXT.h

FORMS    += MainWindow.ui \
    ConnectNXT.ui
