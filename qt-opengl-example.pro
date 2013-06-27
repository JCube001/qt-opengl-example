#-------------------------------------------------
#
# Project created by QtCreator 2013-06-27T15:43:14
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-opengl-example
TEMPLATE = app


SOURCES += \
    src/mainwindow.cpp \
    src/main.cpp \
    src/helloglwidget.cpp

HEADERS  += \
    src/mainwindow.h \
    src/helloglwidget.h

FORMS    += \
    ui/mainwindow.ui

RESOURCES += \
    src/glexamples.qrc
