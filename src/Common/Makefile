#
# -*- Makefile -*- for Common
#
# Created: 11/21/95 using MakeConfigs 4.00.00.a.08
#
# $Id$
#
# (see end of file for Log info)

#
# Do not modifiy 'makefile_type'
makefile_type   = library
# Uncomment 'show_compile_command' to output compile command.
show_commands = true

# Include standard MakeConfig configuration for GNU make required
include Make/make.cfg.4.00

# 
# =USE_CURRENT_MAKEFILE=
# When you re-gen a make file, every thing between 
# these tags will be kept in the new makefile
# if you want it re-gen'd, just delete the tags
#

NAME		= Common

INSTALL_LIBDIR	= $(LOCAL_ALPHA_LIBDIR)
INSTALL_INCDIR	= $(LOCAL_ALPHA_INCDIR)

VER_MAJOR	= 2
VER_MINOR	= 00
VER_RELEASE	= 00.a.28
VERSION		= $(VER_MAJOR).$(VER_MINOR).$(VER_RELEASE)

LIBRARY_DEFAULT	= lib$(NAME).a
LIBRARY_DEBUG	= lib$(NAME)g.a
LIBRARY_PROFILE	= lib$(NAME)pg.a
LIBRARY_SHARED	= lib$(NAME).so

PROTO_H		= _$(NAME)_Proto.h

include ../arch/$(arch)/Makefile.Common

###### D E F I N E S  #####
# 
# Config defines avalable
#
# $(X11_DEF)	    defines for X11
# $(SYB_DEF)	    defines for SYB
# $(MMALLOC_DEF)    defines for libmmalloc
# $(DATA_DEF)	    defines for libData (C++)
# $(CLUE_DEF)	    defines for libClue (C++)
# $(COMMON_DEF)	    defines for libCommon
# $(WT_DEF)	    defines for libWt
# $(WCF_DEF)	    defines for libWcf (CommFabric)
#


SRCDEFINES	= 
PRJDEFINES	= -DVERSION=\"$(VERSION)\" $(ARCH_DEFINES)

DEFINES		= $(PRJDEFINES) $(SRCDEFINES) 

######  I N C L U D E S #####
#
# Config includes available
#
# $(X11_INC)
# $(SYB_INC)
# $(MALLOC_ALPHA_INC)	$(MMALLOC_BETA_INC)	$(MMALLOC_INC)
# $(DATA_ALPHA_INC) 	$(DATA_BETA_INC) 	$(DATA_INC)
# $(CLUE_ALPHA_INC)	$(CLUE_BETA_INC) 	$(CLUE_INC)
# $(COMMON_ALPHA_INC)	$(COMMON_BETA_INC) 	$(COMMON_INC)
# $(WT_ALPHA_INC) 	$(WT_BETA_INC) 		$(WT_INC)
# $(WCF_ALPHA_INC) 	$(WCF_BETA_INC) 	$(WCF_INC)
#
# $(LOCAL_ALPHA_INC) 	$(LOCAL_BETA_INC) 	$(LOCAL_INC)
#


#TOPDIR		=

SRCINCDIR	= -I. $(ARCH_INCDIR)
PRJINCDIR	= 

INCDIRS		= $(SRCINCDIR)	\
		  $(PRJINCDIR)

###### C O M P I L E / C P P #####
#
# Config flags available
#
# $(CC_OPTIMIZE) $(CXX_OPTIMIZE)
# $(CC_DEBUG)	 $(CXX_DEBUG)
# $(CC_PROFILE)	 $(CXX_PROFILE)
# $(CC_WARN)	 $(CXX_WARN)
#


CPPOTHER 	=

CCDEBUG		= $(CC_OPTIMIZE)
CCOTHER		= $(CC_WARN)

CXXDEBUG	= $(CXX_OPTIMIZE)
CXXOTHER	= $(CXX_WARN)

# **** I N S T A L L ****

INSTALL_LIB_FLAGS	= 
INSTALL_INC_FLAGS	= -m 664


objects/default/CommonGetVersion.o: FORCE
objects/debug/CommonGetVersion.o:   FORCE
objects/profile/CommonGetVersion.o: FORCE
objects/shared/CommonGetVersion.o:  FORCE

OBJECTS_DEFAULT	= $(ARCH_OBJECTS_DEFAULT)
OBJECTS_DEBUG	= $(ARCH_OBJECTS_DEBUG)
OBJECTS_PROFILE	= $(ARCH_OBJECTS_PROFILE)
OBJECTS_SHARED	= $(ARCH_OBJECTS_SHARED)

PROTO_C_SOURCES	 = $(C_SOURCES) $(ARCH_PROTO_C_SOURCES)
DEPEND_C_SOURCES = $(C_SOURCES) $(ARCH_DEPEND_C_SOURCES)
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
	CommonErrorString.c             \
	CommonGetVersion.c              \
	DateStringFromTimeT.c           \
	DateStringFromTm.c              \
	DateStringToTimeT.c             \
	DateTimeData.c                  \
	Difftm.c                        \
	EbcdicToAscii.c                 \
	Error.c                         \
	ErrorArgs.c                     \
	ErrorMesg.c                     \
	ErrorTypeString.c               \
	FindPath.c                      \
	GetErrorHandler.c               \
	GnuRegex.c                      \
	HHMMSStoTimeT.c                 \
	IsLeapYear.c                    \
	LogLevelFromString.c            \
	LogLevelSetString.c             \
	LogLevelString.c                \
	Logger.c                        \
	LoggerArgs.c                    \
	LoggerGetFunct.c                \
	LoggerInit.c                    \
	LoggerLevel.c                   \
	LoggerLoc.c                     \
	LoggerSetDate.c                 \
	LoggerSetFunct.c                \
	LoggerSetLevel.c                \
	LoggerSetLoc.c                  \
	LoggerSetLogFile.c              \
	LoggerSetOutputLevel.c          \
	LoggerSetTee.c                  \
	LoggerTrim.c                    \
	SetError.c                      \
	SetErrorHandler.c               \
	StringToDouble.c                \
	StringToInt.c                   \
	StringToLong.c                  \
	StringToShort.c                 \
	StringToUInt.c                  \
	StringToULong.c                 \
	StringToUShort.c                \
	StripSpaces.c                   \
	TempFileName.c                  \
	YYMMDDtoTimeT.c                 \
	YYYYMMDDtoTimeT.c               \
	YearMonthDayToTimeT.c           \
	_ArgString.c                    \
	_CommonDefaultErrorHandler.c    \
	_CommonErrorDesc.c              \
	_LoggerDefault.c                \
	_LoggerFileName.c               \
	_LoggerLogIt.c                  \
	$(ARCH_C_SOURCES)               \


USER_H_INCS	=			\
	Common.h                        \
	GnuRegex.h                      \
	$(ARCH_USER_H_INCS)             \

USER_INCLUDES	=		\
	$(USER_H_INCS)		\
	$(USER_HH_INCS)		\
	$(USER_II_INCS)		\

C_HEADERS	=			\
	Common.h                        \
	GnuRegex.h                      \
	_AvlTypes.h                     \
	_Common.h                       \
	$(ARCH_C_HEADERS)               \



###### T A R G E T S #####
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


include Make/make.cfg.targets.4.00


default debug shared:: proto

default:: objects/default $(LIBRARY_DEFAULT)

all::	default debug profile shared

debug:: objects/debug
	$(HIDE) $(MAKE) CCDEBUG='$(CC_DEBUG)' \
			CXXDEBUG='$(CXX_DEBUG)' \
			$(LIBRARY_DEBUG)

profile:: objects/profile
	$(HIDE) $(MAKE) CCDEBUG='$(CC_PROFILE)' \
			CXXDEBUG='$(CXX_PROFILE)' \
			$(LIBRARY_PROFILE)

shared:: objects/shared
	$(HIDE) $(MAKE) CCDEBUG='$(CCDEBUG) $(CC_SHARED)' \
			CXXDEBUG='$(CXXDEBUG) $(CXX_SHARED)' \
			$(LIBRARY_SHARED)


install:: install_lib_check install_default
	$(HIDE) echo Installation Complete!

install_all:: install_lib_check

install_all:: install_default install_debug install_profile install_shared
	$(HIDE) echo Installation Complete!

install_default:: default $(INSTALL_LIBDIR)/$(LIBRARY_DEFAULT)
install_debug::   debug   $(INSTALL_LIBDIR)/$(LIBRARY_DEBUG)
install_profile:: profile $(INSTALL_LIBDIR)/$(LIBRARY_PROFILE)
install_shared::  shared  $(INSTALL_LIBDIR)/$(LIBRARY_SHARED)


test::	default

FORCE: 

#
# include dependancies generated by 'make depend'
#
-include .depend


#
# =MAKEFILE_LOG=
#
# $Log$
# Revision 2.7  1995/11/12  17:45:58  houghton
# Changed to use MakeConfigs 3.5.
# Added NAME macro for install targets.
# Added sources for GnuRegex.
#
# Revision 2.6  1995/11/10  12:08:33  houghton
# Added MKDIRHIER to install target for missing directories
#
# Revision 2.5  1995/11/10  01:02:09  houghton
# Now using MakeConfigs 3.4 with improved install targets.
#
# Revision 2.4  1995/10/31  13:07:00  houghton
# Added arch components
#
# Revision 2.3  1995/10/31  12:38:30  houghton
# Move version info from CommonVersion.h to _Common.h
# Use MakeConfigs 3.3
# Update ErrorStrings for all CommonErrorType values
#
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




