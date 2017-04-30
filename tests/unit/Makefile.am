# 2017-04-19 (cc) <paul4hough@gmail.com>
#

bin_PROGRAMS = validator
AM_CPPFLAGS = -I../.. -DVVSHOW=1 -DPROG_SED='"$(SED)"'

validator_LDADD = ../../Common/libCommon.la -lm

validator_SOURCES =				\
	main.c	\
	tCommon.c \
	tstrptime.c \
	tCenterLine.c \
	tCanExecute.c \
	tMemberOfGroup.c \
	tFindPath.c \
	tStripChars.c \
	tStringTo.c

#	tIsLeapYear.c

.PHONY: test
test: validator
	$(hide) ./validator
