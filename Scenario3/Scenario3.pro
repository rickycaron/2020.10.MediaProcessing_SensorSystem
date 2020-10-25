TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../sharedLib_a6/release/ -lsharedLib_a6.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../sharedLib_a6/debug/ -lsharedLib_a6.1.0.0
else:unix: LIBS += -L$$PWD/../sharedLib_a6/ -lsharedLib_a6.1.0.0

INCLUDEPATH += $$PWD/../sharedLib_a6
DEPENDPATH += $$PWD/../sharedLib_a6
