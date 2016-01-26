##
# @file
# @author Emiliano Bergamaschini <ebergamaschini@mect.it>
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Project file for qmake
#
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE += -Wno-psabi
QMAKE_CXXFLAGS_DEBUG   += -Wno-psabi

TARGET = hmi
TEMPLATE = app

target.path = /local/root
INSTALLS += target

config.files = config/Crosstable.csv config/system.ini
config.files += config/Alarms.csv
config.files += config/lang_table.csv
config.path = /local/etc/sysconfig

splash.files = config/splash.png config/systool.png
splash.path = /local/etc/sysconfig/img

customstore.files = config/store1.csv
customstore.path = /local/data/customstore

customtrend.files = config/trend1.csv
customtrend.path = /local/data/customtrend

INSTALLS += config splash

INSTALLS += customstore
INSTALLS += customtrend

DEFINES+=ENABLE_STORE
DEFINES+=ENABLE_ALARMS
DEFINES+=ENABLE_TREND
DEFINES+=ENABLE_RECIPE

DEFINES += TRANSLATION

INCLUDEPATH += .\
	./config

LIBS += \
-lts \
-lqwt \
-lATCMcommon \
-lATCMutility \
-lATCMcommunication \
-lATCMplugin \
-lATCMinputdialog \
-lATCMlogger \
-lATCMstore \
-lATCMalarms \
-lATCMrecipe \
-lATCMtrend \
-lATCMsystem

# Input
HEADERS += \
        style.h \
        config/crosstable.h \
        pages.h

SOURCES += \
        config/crosstable.cpp \
        pages.cpp

RESOURCES += \
	systemicons.qrc

# pre-elabortation
check_missing_file.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/cleanmissingpage.pl $$_PRO_FILE_ $$_PRO_FILE_PWD_
check_undeclared_variable.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/check_cross_var.pl $$_PRO_FILE_PWD_
check_gotopage_bind.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/connectbutton.pl $$_PRO_FILE_PWD_

QMAKE_EXTRA_TARGETS += check_missing_file check_undeclared_variable check_gotopage_bind
PRE_TARGETDEPS += check_missing_file check_undeclared_variable check_gotopage_bind

# language
        update.commands = $${QT_LUPDATE_PATH}/lupdate $$_PRO_FILE_
        updates.depends = $$SOURCES $$HEADERS $$FORMS $$TRANSLATIONS
        release.commands = $${QT_LRELEASE_PATH}/lrelease $$_PRO_FILE_
        release.depends = update

        QMAKE_EXTRA_TARGETS += update release
        PRE_TARGETDEPS += update release

        RESOURCES += \
            languages.qrc

        OTHER_FILES += \
            languages_it.ts \
            languages_en.ts

        include(./languages.pri)

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
    DEFINES+=ROTATION=90
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
    DEFINES+=WIDTH=240
    DEFINES+=HEIGHT=240
    DEFINES+=ROTATION=90
}

