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

config.files = config/atn01.conf config/application.conf config/Crosstable.csv config/Commpar.csv config/Alarms.csv
config.path = /local/etc/sysconfig

splash.files = config/splash.png config/systool.png
splash.path = /local/etc/sysconfig/img

customstore.files = config/store1.csv
customstore.path = /local/data/customstore

customtrend.files = config/trend1.csv
customtrend.path = /local/data/customtrend

INSTALLS += config splash customstore customtrend
CONFIG += alarms store trend

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
-lATCMutility \
-lATCMcommunication \
-lATCMplugin \
-lATCMinputdialog

# Input
HEADERS += \
		   commpar_rtu.h \
		   commpar_tcp.h \
		   commpar_tcprtu.h \
		   display_settings.h \
		   info.h \
		   main.h \
		   menu.h \
		   option.h \
		   page0.h \
		   pagebrowser.h \
		   pages.h \
		   screensaver.h \
		   sgdd.h \
		   item_selector.h \
		   style.h \
		   time_set.h \
		   data_manager.h \
		   buzzer_settings.h \
		   comm_status.h

FORMS += \
		 commpar_rtu.ui \
		 commpar_tcp.ui \
		 commpar_tcprtu.ui \
		 display_settings.ui \
		 info.ui \
		 menu.ui \
		 option.ui \
		 page0.ui \
		 sgdd.ui \
		 item_selector.ui \
		 time_set.ui \
		 data_manager.ui \
		 buzzer_settings.ui \
		 comm_status.ui

SOURCES += \
		   commpar_rtu.cpp \
		   commpar_tcp.cpp \
		   commpar_tcprtu.cpp \
		   display_settings.cpp \
		   info.cpp \
		   main.cpp \
		   menu.cpp \
		   option.cpp \
		   page0.cpp \
		   pagebrowser.cpp \
		   pages.cpp \
		   screensaver.cpp \
		   sgdd.cpp \
		   item_selector.cpp \
		   time_set.cpp \
		   data_manager.cpp \
		   buzzer_settings.cpp \
		   comm_status.cpp

store {
	DEFINES+=ENABLE_STORE

	HEADERS -= \
               hmi_logger.h \
			   datalog_set.h

	HEADERS += \
			   hmi_logger.h \
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
	           hmi_logger.cpp \
               datalog_set.cpp

  	SOURCES += \
			   hmi_logger.cpp \
			   datalog_set.cpp \
			   store.cpp \
			   store_filter.cpp
}

alarms {
	DEFINES+=ENABLE_ALARMS

	HEADERS -= \
               hmi_logger.h \
			   datalog_set.h

	HEADERS += \
			   hmi_logger.h \
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
	           hmi_logger.cpp \
               datalog_set.cpp

  	SOURCES += \
			   hmi_logger.cpp \
			   datalog_set.cpp \
			   alarms.cpp \
			   alarms_history.cpp
}

trend {
	DEFINES+=ENABLE_TREND

	HEADERS -= \
               hmi_logger.h \
			   datalog_set.h

	HEADERS += \
			   hmi_logger.h \
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
	           hmi_logger.cpp \
               datalog_set.cpp

  	SOURCES += \
			   hmi_logger.cpp \
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

check.commands = @perl $${PWD}/cleanmissingpage.pl $$_PRO_FILE_

QMAKE_EXTRA_TARGETS += check
PRE_TARGETDEPS += check

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
