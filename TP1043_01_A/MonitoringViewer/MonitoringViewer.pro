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
    page400.h \
    page300.h \
    trendvartable.h


FORMS += \
    page100.ui \
    page200.ui \
    page400.ui \
    page300.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page200.cpp \
    page400.cpp \
    page300.cpp \
    trendvartable.cpp


RESOURCES += \
    resources.qrc

OTHER_FILES += \
    icons/LedOn_chiaro.png \
    icons/LedOff_scuro.png


