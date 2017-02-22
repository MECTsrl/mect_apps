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


# Analog Output Family of Recipes

OTHER_FILES += recipes/AnOut/up_and_down.csv recipes/AnOut/sine_wave.csv

recipes_AnOut.files = recipes/AnOut/up_and_down.csv recipes/AnOut/sine_wave.csv
recipes_AnOut.path = /local/data/recipe/AnOut

INSTALLS += recipes_AnOut


# Digital Output Family of Recipes

OTHER_FILES += recipes/DigOut/from_1_to_4.csv recipes/DigOut/from_1_to_8.csv

recipes_DigOut.files = recipes/DigOut/from_1_to_4.csv recipes/DigOut/from_1_to_8.csv
recipes_DigOut.path = /local/data/recipe/DigOut

INSTALLS += recipes_DigOut
