##
# @file
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Project file for qmake
#

include(./template.pri)

#
# This project uses Eclipse libmosquitto API v2.0.14 (open source MQTT library)
# and QtJson - A simple class for parsing JSON data into a QVariant hierarchies and vice-versa by Eeli Reilin
#

#Add Reference to mosqutto and mosquittopp Libs (needed for Linker)
LIBS += -lmosquitto -lmosquittopp

CONFIG += c++11

HEADERS += \
    automation.h \
    page100.h \
    json.h

FORMS += \
    page100.ui

SOURCES += \
    automation.cpp \
    page100.cpp \
    json.cpp

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    hmi.ini \
    hmi.qss


other.files =  hmi.ini hmi.qss
other.path = /local/root

INSTALLS += other
