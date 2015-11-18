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
config.files += config/Alarms.csv
%TRANSLATION%config.files += config/lang_table.csv
config.path = /local/etc/sysconfig

splash.files = config/splash.png config/systool.png
splash.path = /local/etc/sysconfig/img

customstore.files = config/store1.csv
customstore.path = /local/data/customstore

customtrend.files = config/trend1.csv
customtrend.path = /local/data/customtrend

CONFIG(debug, debug|release) {
    debug_deploy.files = config/dont_run_safe_hmi
    debug_deploy.path = /var/tmp
    INSTALLS += debug_deploy
}

INSTALLS += config splash

INSTALLS += customstore
INSTALLS += customtrend

CONFIG += alarms
CONFIG += store
CONFIG += trend
CONFIG += recipe

DEFINES += TRANSLATION

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
-lATCMlogger

# Input
HEADERS += \
		   commpar_rtu.h \
		   commpar_tcp.h \
		   commpar_tcprtu.h \
		   display_settings.h \
		   info.h \
		   main.h \
		   menu.h \
		   page0.h \
		   pages.h \
		   sgdd.h \
		   item_selector.h \
		   style.h \
		   time_set.h \
		   data_manager.h \
		   buzzer_settings.h \
		   comm_status.h \
    options.h

FORMS += \
		 commpar_rtu.ui \
		 commpar_tcp.ui \
		 commpar_tcprtu.ui \
		 display_settings.ui \
		 info.ui \
		 menu.ui \
		 page0.ui \
		 sgdd.ui \
		 item_selector.ui \
		 time_set.ui \
		 data_manager.ui \
		 buzzer_settings.ui \
		 comm_status.ui \
    options.ui

SOURCES += \
		   commpar_rtu.cpp \
		   commpar_tcp.cpp \
		   commpar_tcprtu.cpp \
		   display_settings.cpp \
		   info.cpp \
		   main.cpp \
		   menu.cpp \
		   page0.cpp \
		   pages.cpp \
		   sgdd.cpp \
		   item_selector.cpp \
		   time_set.cpp \
		   data_manager.cpp \
		   buzzer_settings.cpp \
		   comm_status.cpp \
    options.cpp

store {
	DEFINES+=ENABLE_STORE

	HEADERS -= \
			   datalog_set.h

	HEADERS += \
			   datalog_set.h \
			   store.h \
			   store_filter.h

	FORMS -= \
              datalog_set.ui

	FORMS += \
			   datalog_set.ui \
			   store.ui \
			   store_filter.ui

	SOURCES -= \
               datalog_set.cpp

  	SOURCES += \
			   datalog_set.cpp \
			   store.cpp \
			   store_filter.cpp
}

alarms {
	DEFINES+=ENABLE_ALARMS

	HEADERS -= \
			   datalog_set.h

	HEADERS += \
			   datalog_set.h \
			   alarms.h \
			   alarms_history.h

	FORMS -= \
              datalog_set.ui

	FORMS += \
			   datalog_set.ui \
			   alarms.ui \
			   alarms_history.ui

	SOURCES -= \
               datalog_set.cpp

  	SOURCES += \
			   datalog_set.cpp \
			   alarms.cpp \
			   alarms_history.cpp
}

trend {
	DEFINES+=ENABLE_TREND

	HEADERS -= \
			   datalog_set.h

	HEADERS += \
			   datalog_set.h \
			   trend.h \
			   trend_other.h \
			   trend_option.h \
			   trend_range.h

	FORMS -= \
              datalog_set.ui

	FORMS += \
			   datalog_set.ui \
			   trend.ui \
			   trend_other.ui \
			   trend_option.ui \
			   trend_range.ui

	SOURCES -= \
               datalog_set.cpp

  	SOURCES += \
			   datalog_set.cpp \
			   trend.cpp \
			   trend_other.cpp \
			   trend_option.cpp \
			   trend_range.cpp
}

recipe {
	
        DEFINES+=ENABLE_RECIPE

	HEADERS += \
			   recipe.h \
			   recipe_select.h

	FORMS += \
			   recipe.ui \
			   recipe_select.ui

	SOURCES += \
			   recipe.cpp \
			   recipe_select.cpp
}

RESOURCES += \
	systemicons.qrc

check_missing_file.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/cleanmissingpage.pl $$_PRO_FILE_ $$_PRO_FILE_PWD_
check_undeclared_variable.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/check_cross_var.pl $$_PRO_FILE_PWD_

QMAKE_EXTRA_TARGETS += check_missing_file check_undeclared_variable
PRE_TARGETDEPS += check_missing_file check_undeclared_variable

TRANSLATION = 1
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
