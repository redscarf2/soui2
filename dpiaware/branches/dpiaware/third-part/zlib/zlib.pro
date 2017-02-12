######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 23 19:28:16 2014
######################################################################

TEMPLATE = lib
TARGET = zlib
DEPENDPATH += .
INCLUDEPATH += .

CONFIG += staticlib

dir = ../..
include($$dir/common.pri)

DEFINES += _CRT_SECURE_NO_WARNINGS

# Input
HEADERS += crc32.h \
           deflate.h \
           inffast.h \
           inffixed.h \
           inflate.h \
           inftrees.h \
           trees.h \
           zconf.h \
           zconf.in.h \
           zlib.h \
           zutil.h
SOURCES += adler32.c \
           compress.c \
           crc32.c \
           deflate.c \
           gzio.c \
           infback.c \
           inffast.c \
           inflate.c \
           inftrees.c \
           trees.c \
           uncompr.c \
           zutil.c
