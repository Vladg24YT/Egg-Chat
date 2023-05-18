QT += testlib network sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_parsertestcase.cpp \
    ../ServerProject/client.cpp \
    ../ServerProject/dbworker.cpp

HEADERS += \
    ../ServerProject/DBWorker.h \
    ../ServerProject/client.h
