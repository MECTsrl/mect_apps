##
# @file
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Project file for qmake
#

include(./template.pri)

HEADERS += \
    automation.h \
    page100.h \
    page200.h \
    page300.h \
    page400.h


FORMS += \
    page100.ui \
    page200.ui \
    page300.ui \
    page400.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page200.cpp \
    page300.cpp \
    page400.cpp


RESOURCES += \
    resources.qrc


OTHER_FILES += \
    hmi.ini \
    hmi.qss


other.files =  hmi.ini hmi.qss
other.path = /local/root

INSTALLS += other


