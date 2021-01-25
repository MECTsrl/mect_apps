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
    page100.h


FORMS += \
    page100.ui


SOURCES += \
    automation.cpp \
    page100.cpp


RESOURCES += \
    resources.qrc

OTHER_FILES += \
    sounds/Front_Right.wav \
    sounds/Front_Left.wav \
    sounds/Front_Center.wav


