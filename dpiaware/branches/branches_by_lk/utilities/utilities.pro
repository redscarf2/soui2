######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 23 19:29:15 2014
######################################################################

TEMPLATE = lib

TARGET = utilities

dir = ..
include($$dir/common.pri)

DEFINES += UTILITIES_EXPORTS

INCLUDEPATH += .
INCLUDEPATH += ./include

PRECOMPILED_HEADER = stdafx.h

RC_FILE += utilities.rc

# Input
HEADERS += targetver.h \
           include/gdialpha.h \
           include/souicoll.h \
           include/trace.h \
           include/utilities-def.h \
           include/utilities.h \
           include/atl.mini/atldef.h \
           include/atl.mini/SComCli.h \
           include/pugixml/pugiconfig.hpp \
           include/pugixml/pugixml.hpp \
           include/string/strcpcvt.h \
           include/string/tstring.h \
           include/unknown/obj-ref-i.h \
           include/unknown/obj-ref-impl.hpp \
           include/com-loader.hpp \
           include/wtl.mini/msgcrack.h \
           include/wtl.mini/souigdi.h \
           include/wtl.mini/souimisc.h
SOURCES += src/gdialpha.cpp \
           src/trace.cpp \
           src/utilities.cpp \
           src/pugixml/pugixml.cpp \
           src/string/strcpcvt.cpp	\
