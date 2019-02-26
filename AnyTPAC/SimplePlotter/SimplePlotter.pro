#-------------------------------------------------
#
# Project created by QtCreator 2019-02-18T16:13:35
#
#-------------------------------------------------

QT       += core gui
QT       += network
CONFIG+= static

QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

linux-arm-gnueabi-g++:ATCM_ARM_LIBRARY_LIBPATH = $$QT_ROOTFS/usr/lib
linux-arm-gnueabi-g++:ATCM_ARM_LIBRARY_INCPATH = $$QT_ROOTFS/usr/include
linux-arm-gnueabi-g++:ATCM_ARM_LIBRARY_INCPATH = $${ATCM_QWT_INCL}
linux-arm-gnueabi-g++:LIBS += -lATCMinputdialog

linux-arm-gnueabi-g++:TARGET = hmi_only



#-lATCMcommon \
#-lATCMutility \
#-lATCMcommunication \
#-lATCMplugin \
#-lATCMinputdialog \
#-lATCMlogger \
#-lATCMstore \
#-lATCMalarms \
#-lATCMrecipe \
#-lATCMtrend \
#-lATCMsystem


!linux-arm-gnueabi-g++:TARGET = SimplePlotter

TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp \
        mectcomm.cpp \
    timepopup.cpp

HEADERS  += mainwindow.h \
        qcustomplot.h \
        mectcomm.h \
    timepopup.h

#lessThan(QT_MAJOR_VERSION, 5): SOURCES += qcustomplot.cpp
#lessThan(QT_MAJOR_VERSION, 5): HEADERS += qcustomplot.h
#greaterThan(QT_MAJOR_VERSION, 4): LIBS += -lqcustomplot

FORMS    += mainwindow.ui

target.path = /local/root
INSTALLS += target

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    icons/ic_keyboard_36pt.png
