QT -= gui

TEMPLATE = lib
DEFINES += SHAREDLIB_A6_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
#    ../../../MDPT63/MPT67/alarmaction.cpp \
#    ../../../MDPT63/MPT67/emergencyaction.cpp \
#    ../../../MDPT63/MPT67/emergencycenter.cpp \
#    ../../../MDPT63/MPT67/gassensor.cpp \
#    ../../../MDPT63/MPT67/group.cpp \
#    ../../../MDPT63/MPT67/motionsensor.cpp \
#    ../../../MDPT63/MPT67/mpt67.cpp \
#    ../../../MDPT63/MPT67/sendaction.cpp \
#    ../../../MDPT63/MPT67/sensor.cpp \
#    ../../../MDPT63/MPT67/single.cpp \
#    ../../../MDPT63/MPT67/smokesensor.cpp \
#    ../../../MDPT63/MPT67/unit.cpp \
#    ../../../MDPT63/MPT67/warnaction.cpp \
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
#    ../../../MDPT63/MPT67/MPT67_global.h \
#    ../../../MDPT63/MPT67/alarmaction.h \
#    ../../../MDPT63/MPT67/emergencyaction.h \
#    ../../../MDPT63/MPT67/emergencycenter.h \
#    ../../../MDPT63/MPT67/gassensor.h \
#    ../../../MDPT63/MPT67/group.h \
#    ../../../MDPT63/MPT67/motionsensor.h \
#    ../../../MDPT63/MPT67/mpt67.h \
#    ../../../MDPT63/MPT67/sendaction.h \
#    ../../../MDPT63/MPT67/sensor.h \
#    ../../../MDPT63/MPT67/single.h \
#    ../../../MDPT63/MPT67/smokesensor.h \
#    ../../../MDPT63/MPT67/unit.h \
#    ../../../MDPT63/MPT67/warnaction.h \
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
    sensorCompById.h \
    sensorCompByVendor.h \
    sharedLib_a6_global.h \
    sharedlib_a6.h \
    single.h \
    smokesensor.h \
    unit.h \
    unitComp.h \
    vendorafactory.h \
    warnaction.h

# Default rules for deployment.
unix {
    #target.path = /home/yuqi/mp20-team-a6
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../MDPT63/MPT67/MPT67.pro.user \
    sharedLib_a6.pro.user \
    sharedLib_a6.pro.user.8ca0792 \
    sharedLib_a6.pro.user.e8d0022

SUBDIRS += \
    ../../../MDPT63/MPT67/MPT67.pro
