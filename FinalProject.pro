TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dsstring.cpp \
    tests.cpp \
    hashtable.cpp

HEADERS += \
    dsstring.h \
    avltree.h \
    catch.hpp \
    vector.h \
    parse.h \
    hashtable.h \
    metric1.h \
    commentcounter.h

