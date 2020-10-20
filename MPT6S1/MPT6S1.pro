QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

INCLUDEPATH += "/Users/user/Desktop/MDPT63/MPT67"
LIBS += "/Users/user/Desktop/MDPT63/build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug/libMPT67.1.dylib"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../MPT67/mpt67.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug/release/ -lMPT67.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug/debug/ -lMPT67.1.0.0
else:unix: LIBS += -L$$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug/ -lMPT67.1.0.0

INCLUDEPATH += $$PWD/../MPT67
DEPENDPATH += $$PWD/../MPT67

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug/release/ -lMPT67.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug/debug/ -lMPT67.1.0.0
else:unix: LIBS += -L$$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug/ -lMPT67.1.0.0

INCLUDEPATH += $$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug
DEPENDPATH += $$PWD/../build-MPT67-Desktop_Qt_5_15_1_clang_64bit-Debug
