# 2017-04-19 (cc) <paul4hough@gmail.com>
#

bin_PROGRAMS = validator
AM_CPPFLAGS = -I../../src

#validator_LDADD = clue/libclue.la
#validator_CXXFLAGS = -ggdb

validator_SOURCES =				\
	main.c	\
	tmissing.c \
	tstrptime.c

#	tIsLeapYear.c

.PHONY: test
test: validator
	$(hide) ./validator
