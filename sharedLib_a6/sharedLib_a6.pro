QT -= gui

TEMPLATE = lib
DEFINES += SHAREDLIB_A6_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    example.cpp \
    factory.cpp \
    vendorafactory.cpp

HEADERS += \
    example.h \
    factory.h \
    sharedlib_a6.h \
    vendorafactory.h

# Default rules for deployment.
unix {
    #target.path = /home/yuqi/mp20-team-a6
}
!isEmpty(target.path): INSTALLS += target
