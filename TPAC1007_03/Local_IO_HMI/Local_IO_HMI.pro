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
    page300.h \
    page400.h \
    page401.h \
    page402.h \
    page403.h \
    page404.h \
    page405.h


FORMS += \
    page100.ui \
    page200.ui \
    page300.ui \
    page400.ui \
    page401.ui \
    page402.ui \
    page403.ui \
    page404.ui \
    page405.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page200.cpp \
    page300.cpp \
    page400.cpp \
    page401.cpp \
    page402.cpp \
    page403.cpp \
    page404.cpp \
    page405.cpp


RESOURCES += \
    resources.qrc


