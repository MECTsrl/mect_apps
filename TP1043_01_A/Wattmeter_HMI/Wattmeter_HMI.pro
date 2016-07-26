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
    page100.h \
    automation.h \
    page200.h \
    page300.h


FORMS += \
    page100.ui \
    page200.ui \
    page300.ui


SOURCES += \
    page100.cpp \
    automation.cpp \
    page200.cpp \
    page300.cpp


RESOURCES += \
    resources.qrc


