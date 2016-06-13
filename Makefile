#############################################################################
# Makefile for building: libsst_str01_lib_d.a
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  sstStr01Lib.pro
# Template: lib
# Command: /home/uli-le/Qt/5.5/android_armv7/bin/qmake -spec linux-g++ CONFIG+=debug -o Makefile sstStr01Lib.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -g -fPIC -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -fPIC -Wall -W $(DEFINES)
INCPATH       = -I. -IHeader -I../../Qt/5.5/android_armv7/mkspecs/linux-g++
QMAKE         = /home/uli-le/Qt/5.5/android_armv7/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = sst_str01_lib_d1.0.0
DISTDIR = /home/uli-le/Entwicklung/sst_str01_lib/.tmp/sst_str01_lib_d1.0.0
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = sstStr01Test.cpp \
		sstStr01Int1.cpp \
		sstStr01Int2.cpp \
		sstStr01Int3.cpp \
		sstStr01Int4.cpp \
		sstStr01Int5.cpp \
		sstStr01.cpp \
		sstStr01VarType.cpp \
		sstStr01DefType.cpp \
		sstStr01TestRec.cpp 
OBJECTS       = sstStr01Test.o \
		sstStr01Int1.o \
		sstStr01Int2.o \
		sstStr01Int3.o \
		sstStr01Int4.o \
		sstStr01Int5.o \
		sstStr01.o \
		sstStr01VarType.o \
		sstStr01DefType.o \
		sstStr01TestRec.o
DIST          = ../../Qt/5.5/android_armv7/mkspecs/features/spec_pre.prf \
		../../Qt/5.5/android_armv7/mkspecs/common/unix.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/linux.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/sanitize.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/gcc-base.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/gcc-base-unix.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/g++-base.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/g++-unix.conf \
		../../Qt/5.5/android_armv7/mkspecs/qconfig.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcollision.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcollision_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcore.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dinput.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dlogic.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquick.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquickrenderer.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquickrenderer_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3drenderer.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3drenderer_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_androidextras.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_androidextras_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bluetooth.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_clucene_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_concurrent.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_core.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_core_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_declarative.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_declarative_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_enginio.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_enginio_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_gui.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_gui_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_help.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_help_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_location.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_location_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimedia.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_network.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_network_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_nfc.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_nfc_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_opengl.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_opengl_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_openglextensions.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_positioning.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_positioning_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_printsupport.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qml.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qml_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmltest.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quick.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quick_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_script.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_script_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_scripttools.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sensors.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sensors_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sql.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sql_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_svg.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_svg_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_testlib.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_testlib_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uiplugin.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uitools.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uitools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webchannel.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_websockets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_websockets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webview_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_widgets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_widgets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xml.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xml_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/features/qt_functions.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/qt_config.prf \
		../../Qt/5.5/android_armv7/mkspecs/linux-g++/qmake.conf \
		../../Qt/5.5/android_armv7/mkspecs/features/spec_post.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/exclusive_builds.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/default_pre.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/resolve_config.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/default_post.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/warn_on.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/testcase_targets.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/exceptions.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/yacc.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/lex.prf \
		sstStr01Lib.pro sstStr01LibInt.h \
		Header/sstStr01Lib.h sstStr01Test.cpp \
		sstStr01Int1.cpp \
		sstStr01Int2.cpp \
		sstStr01Int3.cpp \
		sstStr01Int4.cpp \
		sstStr01Int5.cpp \
		sstStr01.cpp \
		sstStr01VarType.cpp \
		sstStr01DefType.cpp \
		sstStr01TestRec.cpp
QMAKE_TARGET  = sst_str01_lib_d
DESTDIR       = ../libs/#avoid trailing-slash linebreak
TARGET        = libsst_str01_lib_d.a


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

staticlib: ../libs/$(TARGET)

../libs/$(TARGET):  $(OBJECTS) $(OBJCOMP) 
	@test -d ../libs/ || mkdir -p ../libs/
	-$(DEL_FILE) $(TARGET)
	$(AR) $(TARGET) $(OBJECTS)
	-$(DEL_FILE) ../libs/$(TARGET)
	-$(MOVE) $(TARGET) ../libs/ 


Makefile: sstStr01Lib.pro ../../Qt/5.5/android_armv7/mkspecs/linux-g++/qmake.conf ../../Qt/5.5/android_armv7/mkspecs/features/spec_pre.prf \
		../../Qt/5.5/android_armv7/mkspecs/common/unix.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/linux.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/sanitize.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/gcc-base.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/gcc-base-unix.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/g++-base.conf \
		../../Qt/5.5/android_armv7/mkspecs/common/g++-unix.conf \
		../../Qt/5.5/android_armv7/mkspecs/qconfig.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcollision.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcollision_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcore.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dinput.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dlogic.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquick.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquickrenderer.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquickrenderer_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3drenderer.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3drenderer_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_androidextras.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_androidextras_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bluetooth.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_clucene_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_concurrent.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_core.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_core_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_declarative.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_declarative_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_enginio.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_enginio_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_gui.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_gui_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_help.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_help_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_location.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_location_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimedia.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_network.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_network_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_nfc.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_nfc_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_opengl.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_opengl_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_openglextensions.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_positioning.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_positioning_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_printsupport.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qml.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qml_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmltest.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quick.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quick_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_script.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_script_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_scripttools.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sensors.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sensors_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sql.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sql_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_svg.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_svg_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_testlib.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_testlib_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uiplugin.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uitools.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uitools_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webchannel.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_websockets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_websockets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webview_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_widgets.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_widgets_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xml.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xml_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../Qt/5.5/android_armv7/mkspecs/features/qt_functions.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/qt_config.prf \
		../../Qt/5.5/android_armv7/mkspecs/linux-g++/qmake.conf \
		../../Qt/5.5/android_armv7/mkspecs/features/spec_post.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/exclusive_builds.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/default_pre.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/resolve_config.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/default_post.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/warn_on.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/testcase_targets.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/exceptions.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/yacc.prf \
		../../Qt/5.5/android_armv7/mkspecs/features/lex.prf \
		sstStr01Lib.pro
	$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile sstStr01Lib.pro
../../Qt/5.5/android_armv7/mkspecs/features/spec_pre.prf:
../../Qt/5.5/android_armv7/mkspecs/common/unix.conf:
../../Qt/5.5/android_armv7/mkspecs/common/linux.conf:
../../Qt/5.5/android_armv7/mkspecs/common/sanitize.conf:
../../Qt/5.5/android_armv7/mkspecs/common/gcc-base.conf:
../../Qt/5.5/android_armv7/mkspecs/common/gcc-base-unix.conf:
../../Qt/5.5/android_armv7/mkspecs/common/g++-base.conf:
../../Qt/5.5/android_armv7/mkspecs/common/g++-unix.conf:
../../Qt/5.5/android_armv7/mkspecs/qconfig.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcollision.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcollision_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcore.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dcore_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dinput.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dinput_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dlogic.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquick.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquick_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquickrenderer.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3dquickrenderer_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3drenderer.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_3drenderer_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_androidextras.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_androidextras_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bluetooth.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_clucene_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_concurrent.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_concurrent_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_core.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_core_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_declarative.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_declarative_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_enginio.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_enginio_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_gui.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_gui_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_help.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_help_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_location.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_location_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimedia.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimedia_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_network.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_network_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_nfc.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_nfc_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_opengl.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_opengl_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_openglextensions.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_positioning.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_positioning_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_printsupport.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_printsupport_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qml.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qml_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmltest.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qmltest_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quick.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quick_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickwidgets.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_script.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_script_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_scripttools.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_scripttools_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sensors.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sensors_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sql.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_sql_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_svg.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_svg_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_testlib.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_testlib_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uiplugin.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uitools.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_uitools_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webchannel.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webchannel_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_websockets.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_websockets_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_webview_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_widgets.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_widgets_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xml.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xml_private.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../Qt/5.5/android_armv7/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../Qt/5.5/android_armv7/mkspecs/features/qt_functions.prf:
../../Qt/5.5/android_armv7/mkspecs/features/qt_config.prf:
../../Qt/5.5/android_armv7/mkspecs/linux-g++/qmake.conf:
../../Qt/5.5/android_armv7/mkspecs/features/spec_post.prf:
../../Qt/5.5/android_armv7/mkspecs/features/exclusive_builds.prf:
../../Qt/5.5/android_armv7/mkspecs/features/default_pre.prf:
../../Qt/5.5/android_armv7/mkspecs/features/resolve_config.prf:
../../Qt/5.5/android_armv7/mkspecs/features/default_post.prf:
../../Qt/5.5/android_armv7/mkspecs/features/warn_on.prf:
../../Qt/5.5/android_armv7/mkspecs/features/testcase_targets.prf:
../../Qt/5.5/android_armv7/mkspecs/features/exceptions.prf:
../../Qt/5.5/android_armv7/mkspecs/features/yacc.prf:
../../Qt/5.5/android_armv7/mkspecs/features/lex.prf:
sstStr01Lib.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile sstStr01Lib.pro

qmake_all: FORCE


all: Makefile ../libs/$(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) ../libs/$(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

sstStr01Test.o: sstStr01Test.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01Test.o sstStr01Test.cpp

sstStr01Int1.o: sstStr01Int1.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01Int1.o sstStr01Int1.cpp

sstStr01Int2.o: sstStr01Int2.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01Int2.o sstStr01Int2.cpp

sstStr01Int3.o: sstStr01Int3.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01Int3.o sstStr01Int3.cpp

sstStr01Int4.o: sstStr01Int4.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01Int4.o sstStr01Int4.cpp

sstStr01Int5.o: sstStr01Int5.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01Int5.o sstStr01Int5.cpp

sstStr01.o: sstStr01.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01.o sstStr01.cpp

sstStr01VarType.o: sstStr01VarType.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01VarType.o sstStr01VarType.cpp

sstStr01DefType.o: sstStr01DefType.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01DefType.o sstStr01DefType.cpp

sstStr01TestRec.o: sstStr01TestRec.cpp Header/sstStr01Lib.h \
		sstStr01LibInt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sstStr01TestRec.o sstStr01TestRec.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

