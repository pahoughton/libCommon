# -*- makefile -*- for Common
#
# Created: 3/2/97 using MakeConfigs 5.01.00.a.07
#
# $Id$
#
# (see end of file for Log info)

#
# Do not modifiy 'makefile_type'
makefile_type   = lib
# This is the make.cfg version that will be used
make_cfg_ver	= 5.01
# Default target type
make_target	= default
# Uncomment 'show_compile_command' to output compile command.
show_commands 	= # true

# Include standard MakeConfig configuration for GNU make required
include Make/make.cfg.$(make_cfg_ver)

# 
# =USE_CURRENT_MAKEFILE=
# When you re-gen a make file, every thing between 
# these tags will be kept in the new makefile
# if you want it re-gen'd, just delete the tags
#

NAME		= Common

INSTALL_LIBDIR	= $(beta_libdir)
INSTALL_INCDIR	= $(beta_incdir)

VER_MAJOR	= 2
VER_MINOR	= 00
VER_RELEASE	= 01.b.03
VERSION		= $(VER_MAJOR).$(VER_MINOR).$(VER_RELEASE)

LIBRARY_DEFAULT	= lib$(NAME).a
LIBRARY_DEBUG	= lib$(NAME)_g.a
LIBRARY_PROFILE	= lib$(NAME)_pg.a
LIBRARY_SHARED	= lib$(NAME)$(shlib_ext)

PROTO_H		= _$(NAME)_Proto.h
PRJ_TOPDIR	= ../..

# include any arch specific makefile component
-include $(PRJ_TOPDIR)/src/arch/$(arch)/Makefile.$(NAME)

VPATH		= $(ARCH_VPATH):.

###### D E F I N E S  #####
# 
# Config defines avalable
#
#


SRC_DEFINES	= 
PRJ_DEFINES	= -DVERSION=\"$(VERSION)\" $(ARCH_DEFINES)

DEFAULT_DEFINES = -DCOMMON_DEFAULT=1
DEBUG_DEFINES	= -DCOMMON_DEBUG=1
PROFILE_DEFINES	= -DCOMMON_PROFILE=1
SHARED_DEFINES	= -DCOMMON_SHARED=1

######  I N C L U D E S #####
#
# Config includes available (need to use -I)
#
# $(alpha_incdir) 	$(beta_incdir) 	$(local_incdir)
#


SRC_INC		= $(ARCH_INC) -I.
PRJ_INC		= 


# Any other cpp flags to use on for all targets

CPP_FLAGS		= $(ARCH_CPP_FLAGS)

###### C O M P I L E / C P P #####
#
# Config flags available
#
# $(cc_optimize) $(cxx_optimize)
# $(cc_debug)	 $(cxx_debug)
# $(cc_profile)	 $(cxx_profile)
# $(cc_warn)	 $(cxx_warn)
#


CC_FLAGS		= $(cc_warn) $(ARCH_CC_FLAGS)

DEFAULT_CC_FLAGS	= $(cc_optimize)
DEBUG_CC_FLAGS		= $(cc_debug)
PROFILE_CC_FLAGS	= $(cc_profile)
SHARED_CC_FLAGS		= $(cc_shared) $(cc_optimize)

CXX_FLAGS		= $(cxx_warn) $(ARCH_CXX_FLAGS)

DEFAULT_CXX_FLAGS	= $(cxx_optimize)
DEBUG_CXX_FLAGS		= $(cxx_debug)
PROFILE_CXX_FLAGS	= $(cxx_profile)
SHARED_CXX_FLAGS	= $(cxx_shared) $(cxx_optimize)

# **** S H A R E D   D E P   L I B S *****

SHDEP_LIBS		= -lc -lm

# **** I N S T A L L ****

INSTALL_LIB_FLAGS	= -m 664
INSTALL_INC_FLAGS	= -m 664

objects/$(make_target)/CommonGetVersion.o: FORCE

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
# depend:	create .depend_default
# profile:	MAKE CCDEBUG=CC_PROFILE all
# proto:	create $(PROTO_H)
# clean:  	rm -f LIB_OBJECTS LIBRARY
# realclean:	rm -f LIB_OBJECTS LIBRARY .depend.lib PROTO_H TAGS
# tags:		create TAGS using etags
#


include Make/make.cfg.targets.$(makefile_type).$(make_cfg_ver)


default debug profile shared:: proto

default:: $(LIBRARY_$($(make_target)))

debug profile shared:: 
	$(hide) $(MAKE) make_target=$@ $(LIBRARY_$($@))

all::	default debug profile shared


install:: install_lib_check install_$(make_target)
	$(hide) echo Installation Complete!

install_all:: install_lib_check

install_all:: install_default install_debug install_profile install_shared
	$(hide) echo Installation Complete!

install_default:: default $(INSTALL_LIBDIR)/$(LIBRARY_DEFAULT)
install_debug::   debug   $(INSTALL_LIBDIR)/$(LIBRARY_DEBUG)
install_profile:: profile $(INSTALL_LIBDIR)/$(LIBRARY_PROFILE)
install_shared::  shared  $(INSTALL_LIBDIR)/$(LIBRARY_SHARED)
	$(hide) chmod +x $(INSTALL_LIBDIR)/$(LIBRARY_SHARED)


test::	default

FORCE: 

#
# include dependancies generated by 'make depend'
#
-include .depend_$(make_target)


#
# =MAKEFILE_LOG=
#
# $Log$
# Revision 2.17  1997/03/02 15:04:05  houghton
# Removed GnuRegex.h.
#
# Revision 2.16  1997/03/02 15:03:14  houghton
# Removed GnuReges (now in libGnuRegex).
#
# Revision 2.15  1997/03/02 12:29:36  houghton
# Updated with latest MakeConfigs fixes.
#
# Revision 2.14  1996/11/06 18:23:16  houghton
# Changed install dir for personal use.
#
# Revision 2.13  1996/05/03 16:10:17  houghton
# Change SHDEP_LIBS
#
# Revision 2.12  1996/04/27 12:26:32  houghton
# Changed to use MakeConfigs 5
#
# Revision 2.11  1996/03/04 11:45:22  houghton
# Bug Fix: profile change dependancy to objects/profile
#
# Revision 2.10  1996/02/29 16:21:12  houghton
# Changed to use MakeConfigs 4.01
#
# Revision 2.9  1995/12/31 11:27:10  houghton
# Bug Fix - changed shared lib name for AIX port.
#
# Revision 2.8  1995/12/02 02:06:59  houghton
# Changed to use MakeConfigs Ver 4.
#
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




