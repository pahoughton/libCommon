#
# Title:        Makefile
# Project:	Common
# Desc:
# 
#   Makefile for Common
# 
# Notes:
#
#   This Makefile requres MakeConfig and GNU's make version 3.75
#
#   Try 'make help' for a list of standard targets.
# 
# Author:	Paul Houghton 719-527-7834 (paul.houghton@wcom.com)
# Created:	3/2/97 using MakeConfigs 5.01.00.a.07
# ReCreated:	3/3/98 useing MakeConfigs 5.04.00.b.02
#
# Revision History: (See end of file for Revision Log)
#
#   Last Mod By:    $Author$
#   Last Mod:	    $Date$
#   Version:	    $Revision$
#
#   $Id$
# 

#
# The following variables control the behavior of MakeConfigs.
#   makefile_type   is the type of object being build (do NOT change)
#   make_cfg_ver    is the version of MakeConfigs to use
#   make_target	    is the default target to build
#   show_commands   if this is true, the commands  will be output
#   proto_dep	    if this is true, the proto header will be rebuild when
#		    one of it's dependancies changes (ie a .c source)
#   check_install   if this is true, install and install_all will NOT
#		    overwrite an installed version.
#

makefile_type   = lib
make_cfg_ver	= 5.06
make_target	= default
show_commands 	= # true
proto_dep	= true
check_install	= true

# Include standard MakeConfig configuration for GNU make required
include Make/make.cfg.$(make_cfg_ver)

# 
# =USE_CURRENT_MAKEFILE=
# When you re-gen a make file, every thing between 
# these tags will be kept in the new makefile
# if you want it re-gen'd, just delete the tags
#

NAME		= Common

PRJ_TOPDIR	= ../..

INSTALL_BASE_DIR	= $(TOOL_DIR)
INSTALL_LIB_DIR		= $(beta_libdir)
INSTALL_INC_DIR		= $(beta_incdir)

VER_MAJOR	= 2
VER_MINOR	= 02
VER_RELEASE	= 01
VERSION		= $(VER_MAJOR).$(VER_MINOR).$(VER_RELEASE)

LIBRARY_DEFAULT	= lib$(NAME).a
LIBRARY_DEBUG	= lib$(NAME)_g.a
LIBRARY_TEST	= lib$(NAME)_tg.a
LIBRARY_PROFILE	= lib$(NAME)_pg.a
LIBRARY_SHARED	= lib$(NAME)_s.$(shlib_ext)

PROTO_H		= _$(NAME)_Proto.h
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
TEST_DEFINES	= -DCOMMON_TEST=1 $(DEBUG_DEFINES)
PROFILE_DEFINES	= -DCOMMON_PROFILE=1
SHARED_DEFINES	= -DCOMMON_SHARED=1

######  I N C L U D E S #####
#
# Config includes available (need to use -I)
#
# $(alpha_incdir) 	$(beta_incdir) 	$(local_incdir)
#


SRC_INC		= $(ARCH_INC) -I. -I$(PRJ_TOPDIR)
PRJ_INC		= -I$(INSTALL_INC_DIR)


# Any other cpp flags to use on for all targets

CPP_FLAGS		= $(ARCH_CPP_FLAGS)

FLEX_FLAGS		=
BISON_FLAGS		=

###### C O M P I L E / C P P #####
#
# Config flags available
#
# $(cc_optimize_flags) $(cxx_optimize_flags)
# $(cc_debug_flags)    $(cxx_debug_flags)
# $(cc_profile_flags)  $(cxx_profile_fllags)
# $(cc_warn)           $(cxx_warn)
#


CC_FLAGS		= $(cc_warn) $(ARCH_CC_FLAGS) $(CC_OTHER)

DEFAULT_CC_FLAGS	= $(cc_optimize_flags)
DEBUG_CC_FLAGS		= $(cc_debug_flags)
TEST_CC_FLAGS		= $(cc_debug_flags)
PROFILE_CC_FLAGS	= $(cc_profile_flags)
SHARED_CC_FLAGS		= $(cc_shared_flags) $(cc_optimize_flags)

CXX_FLAGS		= $(cxx_warn) $(ARCH_CXX_FLAGS) $(CXX_OTHER)

DEFAULT_CXX_FLAGS	= $(cxx_optimize_flags)
DEBUG_CXX_FLAGS		= $(cxx_debug_flags)
TEST_CXX_FLAGS		= $(cxx_debug_flags)
PROFILE_CXX_FLAGS	= $(cxx_profile_flags)
SHARED_CXX_FLAGS	= $(cxx_shared_flags) $(cxx_optimize_flags)

# **** S H A R E D   D E P   L I B S *****

SHDEP_LIBS		= -lc -lm

# **** I N S T A L L ****

INSTALL_LIB_PERM	= 444
INSTALL_INC_PERM	= 444

INSTALL_LIB_FLAGS	= -m $(INSTALL_LIB_PERM)
INSTALL_INC_FLAGS	= -m $(INSTALL_INC_PERM)

#
# =USE_CURRENT_MAKEFILE=
#

# **** S O U R C E   F I L E S ****

GENERATED_SOURCES	=			

FLEX_C_SOURCES	=			
BISON_C_SOURCES	=			
FLEX_CXX_C_SOURCES	=			
BISON_CXX_C_SOURCES	=			
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
	strptime.c			\
	$(ARCH_C_SOURCES)               \

CXX_C_SOURCES	=			
CXX_CC_SOURCES	=			
CXX_CPP_SOURCES	=			

USER_H_INCS	=			\
	Common.h                        \
	$(ARCH_USER_H_INCS)             \

USER_INCLUDES	=		\
	$(USER_H_INCS)		\
	$(USER_HH_INCS)		\
	$(USER_II_INCS)		\

C_HEADERS	=			\
	Common.h                        \
	_AvlTypes.h                     \
	_Common.h                       \
	_Common_Proto.h                 \
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


default debug test profile shared:: $(generated_files)

default:: $(LIBRARY_$($(make_target)))

debug test profile shared:: 
	$(hide) $(MAKE) make_target=$@ $(LIBRARY_$($@))

all::	default debug test profile shared


install:: install_lib_check install_$(make_target)
	$(hide) echo + Installation Complete!

install_all:: install_lib_check

install_all:: install_default install_debug install_profile install_shared
	$(hide) echo + Installation Complete!

install_default:: default $(INSTALL_LIB_DIR)/$(LIBRARY_DEFAULT)
install_debug::   debug   $(INSTALL_LIB_DIR)/$(LIBRARY_DEBUG)
install_test::    test    $(INSTALL_LIB_DIR)/$(LIBRARY_TEST)
install_profile:: profile $(INSTALL_LIB_DIR)/$(LIBRARY_PROFILE)
install_shared::  shared  $(INSTALL_LIB_DIR)/$(LIBRARY_SHARED)
	$(hide) chmod +x $(INSTALL_LIB_DIR)/$(LIBRARY_SHARED)

FORCE: 

#
# include dependancies generated by 'make depend'
#
-include .depend_$(make_target)


#
# =MAKEFILE_LOG=
#
# $Log$
# Revision 2.35  1998/10/23 11:41:25  houghton
# Changed to use MakeConfigs 5.06.
#
# Revision 2.34  1998/10/23 11:36:47  houghton
# Changed includes from beta_incdir to INSTALL_INC_DIR.
#
# Revision 2.33  1998/09/24 15:39:46  houghton
# Changed version number.
#
# Revision 2.32  1998/09/22 14:28:00  houghton
# Changed version number
# Added strptime as a primary source.
#
# Revision 2.31  1998/03/23 10:40:11  houghton
# Changed to work with MakeConfigs 5.05.
#
# Revision 2.30  1998/03/03 23:56:59  houghton
# Changed to use MakeConfig 5.04.
#
#
# =MAKEFILE_LOG=
#

# Local Variables:
# mode:makefile
# End:

