
QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        collection.cpp \
        inductance.cpp \
        main.cpp \
        mainwindow.cpp \
        resistor.cpp

HEADERS += \
    collection.h \
    inductance.h \
    mainwindow.h \
    resistor.h

FORMS += \
    mainwindow.ui
