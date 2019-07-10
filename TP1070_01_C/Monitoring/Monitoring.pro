##
# @file
# @author Emiliano Bergamaschini <ebergamaschini@mect.it>
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
    page300.h


FORMS += \
    page100.ui \
    page200.ui \
    page300.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page200.cpp \
    page300.cpp


RESOURCES += \
    resources.qrc

OTHER_FILES += \
    customtrend/trend_termostati.csv \
    customtrend/trend_potenze.csv \
    customtrend/trend_piani.csv \
    customtrend/trend_caldaia.csv \
    icons/LedOn_chiaro.png \
    icons/LedOff_scuro.png


