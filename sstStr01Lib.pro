TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH = ./Header

HEADERS		+=  sstStr01LibInt.h \
              Header/sstStr01Lib.h \
              Header/sstStr01FixColWidth.h \
    Header/sstStr01LibTypLib.h

SOURCES		+= \
    sstStr01Test.cpp \
    sstStr01Int1.cpp \
    sstStr01Int2.cpp \
    sstStr01Int3.cpp \
    sstStr01Int4.cpp \
    sstStr01Int5.cpp \
    sstStr01.cpp \
    sstStr01VarType.cpp \
    sstStr01DefType.cpp \
    sstStr01TestRec.cpp \
    sstStr01Fcw.cpp \
    Generate/sstStr01LibTypBase.cpp \
    Generate/sstStr01LibTypTst1Cls.cpp \
    Generate/sstStr01LibTypTst2Cls.cpp \
    Generate/sstStr01LibTypTst3Cls.cpp

OTHER_FILES += README.md

debug{
  TARGET		= sst_str01_lib_d
}
release{
  TARGET		= sst_str01_lib_r
}

DESTDIR     = ../libs

DISTFILES += \
    TestTypes.def

