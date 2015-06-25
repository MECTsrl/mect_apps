contains(QMAKE_HOST.os,Windows){
	ATCM_ARM_LIBRARY_LIBPATH = C:/Qt485/imx28/ATCM/library/lib
	ATCM_ARM_PLUGINS_LIBPATH = C:/Qt485/imx28/ATCM/plugins/lib
	ATCM_ARM_LIBRARY_INCPATH = C:/Qt485/imx28/ATCM/library/include
	ATCM_ARM_PLUGINS_INCPATH = C:/Qt485/imx28/ATCM/plugins/include
	ATCM_ARM_ROOTFS = C:/Qt485/imx28/rootfs
	QT_LUPDATE_PATH = C:/Qt485/desktop/bin
	QT_LRELEASE_PATH = C:/Qt485/imx28/qt-everywhere-opensource-src-4.8.5/bin
}
!contains(QMAKE_HOST.os,Windows){
	ATCM_ARM_LIBRARY_LIBPATH = $$(HOME)/install/library/lib
	ATCM_ARM_PLUGINS_LIBPATH = $$(HOME)/install/plugins/lib
	ATCM_ARM_LIBRARY_INCPATH = $$(HOME)/install/library/include
	ATCM_ARM_PLUGINS_INCPATH = $$(HOME)/install/plugins/include
	ATCM_ARM_ROOTFS = $$(HOME)/ltib/rootfs
}

