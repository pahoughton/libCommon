#
# Makefile for WCF Sample Client
#
#  This make file uses configuration system that detects the
#  platform (AIX, SEQ, NeXT ...) and uses the appropriate 
#  compiler and libs	
#
#
# Created: 3/29/93
#
# SCCS Info: %W% %G% %U%
#
#

include make.cfg

PROGRAM		= AvlTest

# **** S O U R C E   F I L E S ****

C_SOURCES   =   			\
	main.c		\
	DeleteError.c	\
	AvlTestSmallValues.c 	\
	CompareNodes.c		\
	AvlTestLargeValues.c	\
	DateTimeTest.c		\
	StringTest.c		\
	TestOutput.c	




# *****  D E F I N E S  *****

DEFINES		= 

# *****  I N C L U D E S *****


SRCINCDIR	= -I. -I../
PRJINCDIR	= -I

INCDIRS		= $(SRCINCDIR)	\
		  $(PRJINCDIR)


# **** C O M P I L E / C P P ****

CPPOTHER 	=
CCDEBUG		= -g
CCOTHER		=


# ***** L I B R A R I E S *****

LDLIBDIRS	= -L../
LDLIBS		= -lCommon


# ***** D E P E N D A N C I E S *****



all:	Prototypes $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(LD) -o $@ $(OBJECTS) $(LDFLAGS) 

depend:
	$(DEPEND) -s "# DO NOT DELETE" -- $(CPPFLAGS) -- $(SRCS)

test:


Prototypes:	$(PROTO_H)

$(PROTO_H): $(C_SOURCES)
	/usr/local/bin/mkproto -p $(C_SOURCES) >$@







# DO NOT DELETE
