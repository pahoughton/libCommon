#
# Makefile for Common
#
# Created: 9/31/95
#
# $Id$
#
# (see end of file for Log info)

#
# Include standard MakeConfig configuration for GNU make required
#

makefile_type   = library

include Make/make.cfg.3.3

# 
# =USE_CURRENT_MAKEFILE=
# When you re-gen a make file, every thing between 
# these tags will be kept int the new makefile
# if you want it re-gen'd, just delete the tags
#

BETA_DIR	= /usr/local/beta
BETA_LIB_DIR	= $(BETA_DIR)/lib
BETA_INC_DIR	= $(BETA_DIR)/include

PROD_DIR	= /usr/local/
PROD_LIB_DIR	= $(PROD_DIR)/lib 
PROD_INC_DIR	= $(PROD_DIR)/include

MAJOR_VER	= 2
MINOR_VER	= 00.00.b.04
VERSION		= $(MAJOR_VER).$(MINOR_VER)

LIBRARY		= libCommon.a

PROTO_H	= _Common_Proto.h


# *****  D E F I N E S  *****
#
# Config defines avalable
#
# $(COMMON_DEF)	    defines for libCommon
# $(WT_DEF)	    defines for libWt
# $(WCF_DEF)	    defines for libWcf (CommFabric)
# $(CLUE_DEF)	    defines for libClue (C++)
# $(DATA_DEF)	    defines for libData (C++)
# $(MMALLOC_DEF)    defines for libmmalloc
# $(X11_DEF)	    defines for X11

SRCDEFINES	= 
PRJDEFINES	= -DVERSION=\"$(VERSION)\" $(ARCH_DEFINES)

DEFINES		= $(PRJDEFINES) $(SRCDEFINES) 

# *****  I N C L U D E S *****
#
# Config includes available
#
# $(LOCAL_BETA_INC)
# $(LOCAL_INC)
# $(COMMON_BETA_INC)
# $(COMMON_INC)
# $(WT_BETA_INC)
# $(WT_INC)
# $(WCF_BETA_INC)
# $(WCF_INC)
# $(MMALLOC_BETA_INC)
# $(MMALLOC_INC)
# $(CLUE_BETA_INC)
# $(CLUE_INC)
# $(DATA_BETA_INC)
# $(DATA_INC)
# $(SYB_INC)
# $(X11_INC)

#TOPDIR		=

SRCINCDIR	= -I. -I../arch/$(arch)
PRJINCDIR	= 

INCDIRS		= $(SRCINCDIR)	\
		  $(PRJINCDIR)


# **** C O M P I L E / C P P ****
#
# Config flags available
#
# $(CC_OPTIMIZE)
# $(CC_DEBUG)
# $(CC_PROFILE)
#

CPPOTHER 	=
CCDEBUG		= $(CC_DEBUG)
CCOTHER		=

# **** I N S T A L L ****

INSTALL_LIB_FLAGS	= -m 664
INSTALL_INC_FLAGS	= -m 664
INSTALL_MAN_FLAGS	= -m 664

#
# =USE_CURRENT_MAKEFILE=
#

# **** S O U R C E   F I L E S ****

C_SOURCES	=			\
	ArgEnvBool.c                    \
	ArgEnvDouble.c                  \
	ArgEnvFlag.c                    \
	ArgEnvInt.c                     \
	ArgEnvLong.c                    \
	ArgEnvString.c                  \
	Avl.c                           \
	CenterLine.c                    \
	CommonGetVersion.c              \
	DateStringFromTimeT.c           \
	DateStringFromTm.c              \
	DateStringToTimeT.c             \
	DateTimeData.c                  \
	Difftm.c                        \
	EbcdicToAscii.c                 \
	ErrorString.c                   \
	FindPath.c                      \
	HHMMSStoTimeT.c                 \
	IsLeapYear.c                    \
	LibError.c                      \
	LogLevelFromString.c            \
	LogLevelString.c                \
	Logger.c                        \
	LoggerInit.c                    \
	LoggerLoc.c                     \
	LoggerTee.c                     \
	LoggerTrim.c                    \
	SetErrorHandler.c               \
	StringToDouble.c                \
	StringToInt.c                   \
	StringToLong.c                  \
	StringToShort.c                 \
	StringToUInt.c                  \
	StringToULong.c                 \
	StringToUShort.c                \
	StripSpaces.c                   \
	YYMMDDtoTimeT.c                 \
	YYYYMMDDtoTimeT.c               \
	YearMonthDayToTimeT.c           \
	_ArgString.c                    \
	_LoggerFileName.c               \


USER_H_INCS	=			\
	Common.h                        \
	../arch/$(arch)/CommonConfig.h	\

USER_INCS	=	\
	$(USER_H_INCS)	\
	$(USER_HH_INCS)	\
	$(USER_II_INCS)	\

C_HEADERS	=			\
	Common.h                        \
	_AvlTypes.h                     \
	_Common.h                       \
	_Common_Proto.h                 \



# ***** T A R G E T S *****
#
# Targets defined in make.cfg.targets.
#
# default: 	all
# depend:	create .depend
# profile:	MAKE CCDEBUG=CC_PROFILE all
# proto:	create $(PROTO_H)
# clean:  	rm -f LIB_OBJECTS LIBRARY
# realclean:	rm -f LIB_OBJECTS LIBRARY .depend.lib PROTO_H TAGS
# tags:		create TAGS using etags
#
#

include Make/make.cfg.targets.3.3

all: $(PROTO_H) $(LIBRARY)

$(LIBRARY): $(OBJECTS) 
	$(UPDATELIB) $@ $?

install: default
	$(MKDIRHIER) $(BETA_LIB_DIR)/old
	$(MKDIRHIER) $(BETA_INC_DIR)/old
	if [ -e $(BETA_LIB_DIR)/$(LIBRARY).$(VERSION) ] ; then \
	echo $(BETA_LIB_DIR)/$(LIBRARY).$(VERSION) already installed!; \
	echo Change version number in makefile and try again.; \
	exit 1; \
	fi
	if [ -e .installed.ver ] ; then \
	ver=`cat .installed.ver`; \
	for fn in `cat .installed.lib`; do \
	mv $(BETA_LIB_DIR)/$$fn $(BETA_LIB_DIR)/old; \
	done; \
	for fn in `cat .installed.inc`; do \
	mv $(BETA_INC_DIR)/$$fn $(BETA_INC_DIR)/old/$$fn.$$ver; \
	done; \
	fi
	echo $(VERSION) >.installed.ver
	echo $(LIBRARY).$(VERSION) >.installed.lib
	rm -f .installed.inc
	for fn in $(USER_INCS); do basename $$fn >>.installed.inc; done
	$(INSTALL) $(INSTALL_LIB_FLAGS) \
		$(LIBRARY) \
	  	$(BETA_LIB_DIR)/$(LIBRARY).$(VERSION)
	(cd $(BETA_LIB_DIR); \
	  rm $(LIBRARY); \
	  ln -s $(LIBRARY).$(VERSION) $(LIBRARY) )
	$(INSTALL) $(INSTALL_INC_FLAGS) $(USER_INCS) $(BETA_INC_DIR)
	echo 'Beta Install Complete!'


install_production: default
	$(MKDIRHIER) $(PROD_LIB_DIR)/old
	$(MKDIRHIER) $(PROD_INC_DIR)/old
	if [ -e $(PROD_LIB_DIR)/$(LIBRARY).$(VERSION) ] ; then \
	echo $(PROD_LIB_DIR)/$(LIBRARY).$(VERSION) already installed!; \
	echo Change version number in makefile and try again.; \
	exit 1; \
	fi
	if [ -e .installed.prod.ver ] ; then \
	ver=`cat .installed.prod.ver`; \
	for fn in `cat .installed.prod.lib`; do \
	mv $(PROD_LIB_DIR)/$$fn $(PROD_LIB_DIR)/old; \
	done; \
	for fn in `cat .installed.prod.inc`; do \
	mv $(PROD_INC_DIR)/$$fn $(PROD_INC_DIR)/old/$$fn.$$ver; \
	done; \
	fi
	echo $(MAJOR_VER).$(MINOR_VER) >.installed.prod.ver
	echo $(LIBRARY).$(VERSION) >.installed.prod.lib
	rm -f .installed.prod.inc
	for fn in $(USER_INCS); do basename $$fn >>.installed.inc; done
	$(INSTALL) $(INSTALL_LIB_FLAGS) \
		$(LIBRARY) \
	  	$(PROD_LIB_DIR)/$(LIBRARY).$(VERSION)
	(cd $(PROD_LIB_DIR); \
	  rm $(LIBRARY); \
	  ln -s $(LIBRARY).$(VERSION) $(LIBRARY) )
	$(INSTALL) $(INSTALL_INC_FLAGS) $(USER_INCS) $(PROD_INC_DIR)
	echo 'Production Install Complete!'

test:	default

CommonGetVersion.o: FORCE

FORCE:

#
# include dependancies generated by 'make depend'
#
include .depend

#
# =MAKEFILE_LOG=
#
# $Log$
# Revision 2.2  1995/10/30  14:55:15  houghton
# Move contents of Bit.h & DateTime.h to Common.h
# Add Net2Host
#
# Revision 2.1  1995/10/29  13:33:44  houghton
# Initial Linux Build of Version 2
#
# Revision 1.2  1995/02/13  17:35:10  houghton
# Major enhancements much cleaner
#
# Revision 1.1  1994/01/23  18:16:55  houghton
# Production release 1.0 of MakeConfig system
#
# =MAKEFILE_LOG=
#




