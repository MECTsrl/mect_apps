##
# @file
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Project file for qmake
#

include(./template.pri)

CONFIG += c++11

HEADERS += \
    automation.h \
    page100.h


FORMS += \
    page100.ui


SOURCES += \
    automation.cpp \
    page100.cpp


RESOURCES += \
    resources.qrc


OTHER_FILES += \
    hmi.ini \
    hmi.qss \
    testPost.sh


other.files =  hmi.ini hmi.qss testPost.sh
other.path = /local/root

INSTALLS += other


