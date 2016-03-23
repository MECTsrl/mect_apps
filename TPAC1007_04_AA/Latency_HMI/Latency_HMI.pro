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
    page101.h



FORMS += \
    page100.ui \
    page101.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page101.cpp



RESOURCES += \
    resources.qrc


