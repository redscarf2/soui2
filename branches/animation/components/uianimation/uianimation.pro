######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 23 19:28:33 2014
######################################################################

TEMPLATE = lib
TARGET = uianimation


!LIB_ALL:!COM_LIB{
	RC_FILE += uianimation.rc
}
else{
	CONFIG += staticlib
}

DEPENDPATH += .
INCLUDEPATH += . \
			  ../../utilities/include \
			  ../../soui/include \

dir = ../..
include($$dir/common.pri)


CONFIG(debug,debug|release){
	LIBS += utilitiesd.lib
}
else{
	LIBS += utilities.lib
}

PRECOMPILED_HEADER = stdafx.h

# Input
HEADERS += uianimation.h
SOURCES += uianimation.cpp
