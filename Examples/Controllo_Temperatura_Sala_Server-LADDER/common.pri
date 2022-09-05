##
# @file
#
# @section LICENSE
# Copyright Mect s.r.l. 2013
#
# @brief Qmake project file
#

contains(QMAKE_HOST.os,Windows){
        QT_ROOTFS = C:/Qt485/imx28/rootfs
        QT_LUPDATE_PATH = C:/Qt485/desktop/bin
        QT_LRELEASE_PATH = C:/Qt485/imx28/qt-everywhere-opensource-src-4.8.5/bin
        ATCM_TEMPLATE_BASE_DIR = C:/Qt485/desktop/share/qtcreator/templates/wizards
}
!contains(QMAKE_HOST.os,Windows){
        QT_ROOTFS=$$(MECT_RFSDIR)
        QT_LUPDATE_PATH = 
        QT_LRELEASE_PATH = $$(MECT_QT_INSTALL_DIR)/bin
        ATCM_TEMPLATE_BASE_DIR = 
}

isEmpty(QT_ROOTFS) {
        error(QT_ROOTFS is empty)
}
isEmpty(QT_LUPDATE_PATH) {
        warning(QT_LUPDATE_PATH is empty)
}
isEmpty(QT_LRELEASE_PATH) {
        warning(QT_LRELEASE_PATH is empty)
}
isEmpty(ATCM_TEMPLATE_BASE_DIR) {
        warning(ATCM_TEMPLATE_BASE_DIR is empty)
}

ATCM_ARM_LIBRARY_LIBPATH = $$QT_ROOTFS/usr/lib
ATCM_ARM_PLUGINS_LIBPATH = $$QT_ROOTFS/usr/lib
ATCM_ARM_LIBRARY_INCPATH = $$QT_ROOTFS/usr/include
ATCM_ARM_PLUGINS_INCPATH = $$QT_ROOTFS/usr/include

QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE += -Wno-psabi
QMAKE_CXXFLAGS_DEBUG   += -Wno-psabi

TARGET = hmi
TEMPLATE = app

target.path = /local/root

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
        config/crosstable.h \
        style.h \
        pages.h

SOURCES += \
        config/crosstable.cpp \
        pages.cpp

!isEmpty(ATCM_TEMPLATE_BASE_DIR) {
	# pre-elaboration
    check_missing_file.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/cleanmissingpage.pl \"$$_PRO_FILE_\" \"$$_PRO_FILE_PWD_\"
    check_undeclared_variable.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/check_cross_var.pl \"$$_PRO_FILE_PWD_\"
    check_gotopage_bind.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/connectbutton.pl \"$$_PRO_FILE_PWD_\"
    check_systemini.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/check_systemini.pl \"$$_PRO_FILE_\" \"$$_PRO_FILE_PWD_\"
    check_default_font.commands = @perl $${ATCM_TEMPLATE_BASE_DIR}/ATCM-template-project/defaultfont.pl \"$$_PRO_FILE_PWD_\"
# crosstable_compiler invocation moved in defaultfont.pl (for mect_suite_2.0 projects)
#    crosstable_compiler.commands = $${QT_LUPDATE_PATH}/ctc -c config/Crosstable.csv -g plc/Crosstable.gvl -i config/Crosstable.h -s config/Crosstable.cpp

        QMAKE_EXTRA_TARGETS += check_missing_file check_undeclared_variable check_gotopage_bind check_systemini check_default_font # crosstable_compiler
        PRE_TARGETDEPS += check_missing_file check_undeclared_variable check_gotopage_bind check_systemini check_default_font # crosstable_compiler
}

# system icons
RESOURCES += \
    systemicons.qrc

# language
!isEmpty(QT_LUPDATE_PATH) {
update.commands = $${QT_LUPDATE_PATH}/lupdate \"$$_PRO_FILE_\"
updates.depends = $$SOURCES $$HEADERS $$FORMS $$TRANSLATIONS
release.depends = update
        QMAKE_EXTRA_TARGETS += update
        PRE_TARGETDEPS += update
}
!isEmpty(QT_LRELEASE_PATH) {
        release.commands = $${QT_LRELEASE_PATH}/lrelease \"$$_PRO_FILE_\"
        QMAKE_EXTRA_TARGETS += release
        PRE_TARGETDEPS += release
}

RESOURCES += \
    languages.qrc

include(./languages.pri)

