TEMPLATE	  = app
CONFIG	 	 += warn_on
CONFIG       -= qt
CONFIG       -= windows

# CONFIG       -= debug  # RELEASE ist aktiv
CONFIG       -= release  # DEBUG ist aktiv

INCLUDEPATH += ../Header

debug{
  LIBS        += ../../libs/libsstStr01Lib_d.a
}
release{
  
  win32-g++:QMAKE_LFLAGS += -static
  win32-g++:QMAKE_LFLAGS -= -mthreads
  win32-g++:QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
  win32-g++:QMAKE_CXXFLAGS_EXCEPTIONS_ON -= -mthreads
  
  
  LIBS        += ../../libs/libsstStr01Lib_r.a
}

HEADERS    += sstStr01LibTest.h \
              ../Header/sstStr01Lib.h

SOURCES    += \
    sstStr01LibTest.cpp



TARGET	  	= sstStr01LibTest
