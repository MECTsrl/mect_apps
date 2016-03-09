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
    page400.h \
    page401.h \
    page402.h \
    page405.h


FORMS += \
    page100.ui \
    page400.ui \
    page401.ui \
    page402.ui \
    page405.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    page400.cpp \
    page401.cpp \
    page402.cpp \
    page405.cpp


RESOURCES += \
    resources.qrc

OTHER_FILES += \
    my_img/remote.png \
    my_img/local.png \
    my_img/done.png


