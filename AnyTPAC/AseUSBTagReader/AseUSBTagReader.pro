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
    tagreader.h


FORMS += \
    page100.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    tagreader.cpp


RESOURCES += \
    resources.qrc


OTHER_FILES += \
    hmi.ini \
    hmi.qss


other.files =  hmi.ini hmi.qss
other.path = /local/root

INSTALLS += other


