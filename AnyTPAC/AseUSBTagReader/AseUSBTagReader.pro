##
# @file
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Project file for qmake
#

include(./template.pri)

# Location of QtSerialPort Library
SPP_LIBRARY_LOCATION=qtserialport

# Include Location for QtSerialPort
INCLUDEPATH +=  $$SPP_LIBRARY_LOCATION/include
DEPENDPATH += $$SPP_LIBRARY_LOCATION/include

# Lib Linking to QtSerialPort Library
LIBS += -L$$SPP_LIBRARY_LOCATION/lib/ -lQtSerialPort

#Declare Usage of QtSerialPort
CONFIG+=serial

HEADERS += \
    automation.h \
    page100.h \
    serialreader.h


FORMS += \
    page100.ui


SOURCES += \
    automation.cpp \
    page100.cpp \
    serialreader.cpp


RESOURCES += \
    resources.qrc


OTHER_FILES += \
    hmi.ini \
    hmi.qss

#Hmi.qss (intoduced with Mect Suite 3.4.3)
other.files =  hmi.ini hmi.qss
other.path = /local/root

#Deploy for libQtSerialPort.so
lib.path  += /local/root/lib
lib.files = $$SPP_LIBRARY_LOCATION/lib/libQtSerialPort.so

#Add lib libQtSerialPort.so to deploy file list
INSTALLS += other lib

#Add libQtSerialPort.so directory to application Path
QMAKE_LFLAGS += -Wl,-rpath,/local/root/lib



