TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH = ./Header

# SOURCES		+= str1_lib1.cpp
HEADERS		+= \
    sstStr01LibInt.h \
    Header/sstStr01Lib.h
    # Header/sstStr01Kern.h

SOURCES		+= \
    sstStr01Test.cpp \
    sstStr01Int1.cpp \
    sstStr01Int2.cpp \
    sstStr01Int3.cpp \
    sstStr01Int4.cpp \
    sstStr01Int5.cpp \
    sstStr01.cpp

OTHER_FILES += README.md

debug{
  TARGET		= sst_str01_lib_d
}
release{
  TARGET		= sst_str01_lib_r
}

DESTDIR     = ../libs

