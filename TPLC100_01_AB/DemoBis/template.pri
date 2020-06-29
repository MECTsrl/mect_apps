#
# @file
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Qmake project file for TPLC100_01_AB
#

INSTALLS += target

config.files = config/Crosstable.csv config/system.ini
config.path = /local/etc/sysconfig
config.files += config/iomap0.cmg config/network0.cmg 

splash.files = config/splash.png
splash.path = /local/etc/sysconfig/img

customtrend.files = config/trend1.csv
customtrend.path = /local/data/customtrend

INSTALLS += config splash customtrend

# language
OTHER_FILES += \
    languages_it.ts \
    languages_en.ts

include(./common.pri)

TYPE = "TPLC100_01_AB"

# display size
MODEL = "<width>683</width><height>384</height>"

equals(MODEL, "<width>683</width><height>384</height>") {
    DEFINES+=WIDTH=683
    DEFINES+=HEIGHT=384
    DEFINES+=ROTATION=0
}

