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
    page400.h


FORMS += \
    page100.ui \
    page400.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page400.cpp


RESOURCES += \
    resources.qrc


