##
# @file
# @author Emiliano Bergamaschini <ebergamaschini@mect.it>
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Qmake project file for TP1043_01_A
#

INSTALLS += target

config.files = config/Crosstable.csv config/system.ini
config.path = /local/etc/sysconfig


splash.files = config/splash.png
splash.path = /local/etc/sysconfig/img

customtrend.files = config/trend1.csv \
    config/trend_caldaia.csv \
    config/trend_piani.csv \
    config/trend_piano_sopra.csv \
    config/trend_piano_sotto.csv \
    config/trend_piano_terra.csv \
    config/trend_potenze.csv \
    config/trend_termo_terra.csv \
    config/trend_termo_sotto.csv \
    config/trend_termo_sopra.csv \
    config/trend_ufficio.csv

customtrend.path = /local/data/customtrend

INSTALLS += config splash customtrend

# language
OTHER_FILES += \
    languages_it.ts \
    languages_en.ts \
    config/trend_ufficio.csv

include(./common.pri)

TYPE = "TP1043_01_A"

# display size
MODEL = "<width>480</width><height>272</height>"

equals(MODEL, "<width>320</width><height>240</height>") {
    DEFINES+=WIDTH=320
    DEFINES+=HEIGHT=240
    DEFINES+=ROTATION=0
}
equals(MODEL, "<width>240</width><height>320</height>") {
    DEFINES+=WIDTH=240
    DEFINES+=HEIGHT=320
    DEFINES+=ROTATION=270
}
equals(MODEL, "<width>480</width><height>272</height>") {
    DEFINES+=WIDTH=480
    DEFINES+=HEIGHT=272
    DEFINES+=ROTATION=0
}
equals(MODEL, "<width>272</width><height>480</height>") {
    DEFINES+=WIDTH=272
    DEFINES+=HEIGHT=480
    DEFINES+=ROTATION=90
}
equals(MODEL, "<width>800</width><height>480</height>") {
    DEFINES+=WIDTH=800
    DEFINES+=HEIGHT=480
    DEFINES+=ROTATION=0
}
equals(MODEL, "<width>480</width><height>800</height>") {
    DEFINES+=WIDTH=480
    DEFINES+=HEIGHT=800
    DEFINES+=ROTATION=270
}

