QMAKE_CXXFLAGS_RELEASE += -Wno-psabi
QMAKE_CXXFLAGS_DEBUG   += -Wno-psabi

DEFINES += LOG_LEVEL=error_e
contains(QMAKE_HOST.os,Windows){
        QT_ROOTFS = C:/Qt485/imx28/rootfs
        QT_CREATOR = C:/Qt485/desktop
        ATCM_DIR_COPY = "cmd /c xcopy /Q /Y /E /S /I"
        QT_LUPDATE_PATH = C:/Qt485/desktop/bin
        QT_LRELEASE_PATH = C:/Qt485/imx28/qt-everywhere-opensource-src-4.8.5/bin
        ATCM_TEMPLATE_BASE_DIR = C:/Qt485/desktop/share/qtcreator/templates/wizards
}
!contains(QMAKE_HOST.os,Windows){
	    QT_ROOTFS=$$(RFSDIR)
	    QT_CREATOR = C:/Qt485/desktop
        ATCM_DIR_COPY = "cp -rf"
        QT_LUPDATE_PATH = C:/Qt485/desktop/bin
        QT_LRELEASE_PATH = C:/Qt485/imx28/qt-everywhere-opensource-src-4.8.5/bin
        ATCM_TEMPLATE_BASE_DIR = C:/Qt485/desktop/share/qtcreator/templates/wizards
}

isEmpty(QT_ROOTFS) {
        error(QT_ROOTFS is empty)
}

ATCM_ARM_LIBRARY_LIBPATH = $$QT_ROOTFS/usr/lib
ATCM_ARM_PLUGINS_LIBPATH = $$QT_ROOTFS/usr/lib
ATCM_ARM_LIBRARY_INCPATH = $$QT_ROOTFS/usr/include
ATCM_ARM_PLUGINS_INCPATH = $$QT_ROOTFS/usr/include

