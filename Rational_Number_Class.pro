QT += core
QT -= gui

CONFIG += c++11

TARGET = Rational_Number_Class
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rational.cpp

HEADERS += \
    rational.h
