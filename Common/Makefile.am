# 2001-06-04 (cc) <paul4hough@gmail.com>
#

lib_LTLIBRARIES = libCommon.la

libCommon_la_SOURCES = \
EbcdicToAscii.c \
CenterLine.c \
StripChars.c \
StringTo.c \
CanExecute.c \
ForeachFile.c \
FindPath.c \
MemberOfGroup.c

include_HEADERS =				\
	Common.h

libCommon_la_CPPFLAGS = -I..

test: all
	$(MAKE) -C ../tests/unit test
