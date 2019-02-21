#-------------------------------------------------
#
# Project created by QtCreator 2019-02-18T16:13:35
#
#-------------------------------------------------

QT       += core gui
QT       += network

QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


unix:ATCM_ARM_LIBRARY_LIBPATH = $$QT_ROOTFS/usr/lib
unix:ATCM_ARM_LIBRARY_INCPATH = $$QT_ROOTFS/usr/include
unix:LIBS += -lATCMinputdialog


TARGET = hmi_only
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    mectcomm.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    mectcomm.h

FORMS    += mainwindow.ui

target.path = /local/root
INSTALLS += target

RESOURCES += \
    icons.qrc

OTHER_FILES += \
    icons/ic_keyboard_36pt.png
