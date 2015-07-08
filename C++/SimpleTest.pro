CONFIG += c++11
lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -std=c++11

QT -= core gui

CONFIG += console
CONFIG -= app_bundle

TARGET = SimpleTest

TEMPLATE = app

SOURCES += \
    $$PWD/SimpleTest/SimpleTest.cpp \
    $$PWD/DiffProcessor/Processor.cpp

HEADERS += \
    $$PWD/DiffProcessor/Processor.h \
    $$PWD/DiffProcessor/SortedLimitedList.h
