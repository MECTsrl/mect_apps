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
    page310.h \
    page320.h \
    page330.h \
    page340.h


FORMS += \
    page100.ui \
    page200.ui \
    page310.ui \
    page320.ui \
    page330.ui \
    page340.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page200.cpp \
    page310.cpp \
    page320.cpp \
    page330.cpp \
    page340.cpp


RESOURCES += \
    resources.qrc


