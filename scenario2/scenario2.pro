TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp




unix:!macx: LIBS += -L$$PWD/../sharedLib_a6/ -lsharedLib_a6

INCLUDEPATH += $$PWD/../sharedLib_a6
DEPENDPATH += $$PWD/../sharedLib_a6
