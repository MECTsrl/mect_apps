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

config.files = config/atn01.conf config/application.conf config/Crosstable.csv config/Commpar.csv
%ALARMS%config.files += config/Alarms.csv
%TRANSLATION%config.files += config/lang_table.csv
config.path = /local/etc/sysconfig

splash.files = config/splash.png config/systool.png
splash.path = /local/etc/sysconfig/img

%STORE%customstore.files = config/store1.csv
%STORE%customstore.path = /local/data/customstore

%TREND%customtrend.files = config/trend1.csv
%TREND%customtrend.path = /local/data/customtrend

CONFIG(debug, debug|release) {
    debug_deploy.files = config/dont_run_safe_hmi
    debug_deploy.path = /var/tmp
    INSTALLS += debug_deploy
}

INSTALLS += config splash

%STORE%INSTALLS += customstore
%TREND%INSTALLS += customtrend

%ALARMS%CONFIG += alarms
%STORE%CONFIG += store
%TREND%CONFIG += trend
%RECIPE%CONFIG += recipe

%LANGUAGE%DEFINES += TRANSLATION

include(./qt_environment.pri)

INCLUDEPATH += .\
	$${ATCM_ARM_ROOTFS}/usr/src/linux/include \
	$${ATCM_ARM_ROOTFS}/usr/include \
	$${ATCM_ARM_PLUGINS_INCPATH} \
	$${ATCM_ARM_LIBRARY_INCPATH}

QMAKE_LIBDIR += ../../lib \
	$${QWT_LIBPATH} \
	$${ATCM_ARM_ROOTFS}/usr/lib \
	$${ATCM_ARM_PLUGINS_LIBPATH} \
	$${ATCM_ARM_LIBRARY_LIBPATH}

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
                   pages.h

FORMS += \


SOURCES += \
                   pages.cpp

store {
	DEFINES+=ENABLE_STORE
}

alarms {
	DEFINES+=ENABLE_ALARMS
}

trend {
	DEFINES+=ENABLE_TREND
}

recipe {
        DEFINES+=ENABLE_RECIPE
}

RESOURCES += \
	systemicons.qrc

check_missing_file.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/cleanmissingpage.pl $$_PRO_FILE_ $$_PRO_FILE_PWD_
check_undeclared_variable.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/check_cross_var.pl $$_PRO_FILE_PWD_

QMAKE_EXTRA_TARGETS += check_missing_file check_undeclared_variable
PRE_TARGETDEPS += check_missing_file check_undeclared_variable

%LANGUAGE%TRANSLATION = 1
!isEmpty(TRANSLATION)
{
QT_LUPDATE_PATH=$$(QT_LUPDATE_PATH)

isEmpty(QT_LUPDATE_PATH) {
  warning(QT_LUPDATE_PATH is empty)
} else {
    QT_LRELEASE_PATH=$$(QT_LRELEASE_PATH)
    isEmpty(QT_LRELEASE_PATH) {
        warning(QT_LRELEASE_PATH is empty)
    } else {
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
    }
}

}

MODEL = "<width>480</width><height>272</height>"

OTHER_FILES += \
    config/Alarms.csv
