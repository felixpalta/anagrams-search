TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    Dictionary.cpp \
    input_loop.cpp

HEADERS += \
    Arguments.h \
    Dictionary.h \
    input_loop.h

