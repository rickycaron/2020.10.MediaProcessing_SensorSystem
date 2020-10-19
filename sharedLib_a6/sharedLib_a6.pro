QT -= gui

TEMPLATE = lib
DEFINES += SHAREDLIB_A6_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alarmaction.cpp \
    emergencyaction.cpp \
    emergencycenter.cpp \
    example.cpp \
    factory.cpp \
    gassensor.cpp \
    group.cpp \
    motionsensor.cpp \
    mpt67.cpp \
    sendaction.cpp \
    sensor.cpp \
    sharedlib_a6.cpp \
    single.cpp \
    smokesensor.cpp \
    unit.cpp \
    vendorafactory.cpp \
    warnaction.cpp

HEADERS += \
    MPT67_global.h \
    alarmaction.h \
    emergencyaction.h \
    emergencycenter.h \
    example.h \
    factory.h \
    gassensor.h \
    group.h \
    motionsensor.h \
    mpt67.h \
    sendaction.h \
    sensor.h \
    sharedLib_a6_global.h \
    sharedlib_a6.h \
    single.h \
    smokesensor.h \
    unit.h \
    vendorafactory.h \
    warnaction.h

# Default rules for deployment.
unix {
    #target.path = /home/yuqi/mp20-team-a6
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sharedLib_a6.pro.user \
    sharedLib_a6.pro.user.8ca0792 \
    sharedLib_a6.pro.user.e8d0022
