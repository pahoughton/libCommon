#
# Makefile for Common
#
# Created: 10/9/95
#
# $Id$
#
# (see end of file for Log info)

#
# Include standard MakeConfig configuration for GNU make required
#

makefile_type   = library

include Make/make.cfg.3.4

# 
# =USE_CURRENT_MAKEFILE=
# When you re-gen a make file, every thing between 
# these tags will be kept int the new makefile
# if you want it re-gen'd, just delete the tags
#

BETA_DIR	= 
BETA_LIB_DIR	= $(LOCAL_ALPHA_LIB_DIR)
BETA_INC_DIR	= $(LOCAL_ALPHA_INC_DIR)

PROD_DIR	= /usr/local/
PROD_LIB_DIR	= $(PROD_DIR)/lib 
PROD_INC_DIR	= $(PROD_DIR)/include

MAJOR_VER	= 2
MINOR_VER	= 00.00.a.21
VERSION		= $(MAJOR_VER).$(MINOR_VER)

LIBRARY		= libCommon.a

PROTO_H	= _Common_Proto.h

include ../arch/$(arch)/Makefile.common

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
	 ../arch/$(arch)/CommonConfig.h \

USER_INCS	=	   \
	$(USER_H_INCS)     \
	$(USER_HH_INCS)    \
	$(USER_II_INCS)    \

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

include Make/make.cfg.targets.3.4

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS) 
	$(UPDATELIB) $@ $?

install: beta_check_installed beta_install_lib
	@echo $(BETA_LIB_DIR)/$(LIBRARY).$(VERSION) installed!

beta_check_installed: 
	@if [ -e $(BETA_LIB_DIR)/$(LIBRARY).$(VERSION) ] ; then \
	  echo $(BETA_LIB_DIR)/$(LIBRARY).$(VERSION) already installed!; \
	  echo Change version number in makefile and try again.; \
	  exit 1; \
	fi
	@echo + Installing $(NAME) Version: $(VERSION)

beta_install_lib: default beta_move_installed beta_install_new

beta_move_installed: 
	@if [ -e .installed.ver ] ; then \
	  for line in `cat .installed.ver` ; do \
	    case $$line in \
	      installed_ver=*) \
		installed_ver=$${line#installed_ver=};; \
	      installed_inc_dir=*) \
		installed_inc_dir=$${line#installed_inc_dir=};; \
	      installed_lib_dir=*) \
		installed_lib_dir=$${line#installed_lib_dir=};; \
	    esac; \
	  done; \
	  echo + Moving Version $$installed_ver out of way; \
	  if [ -d $$installed_inc_dir ] ; then \
	    for fn in `cat .installed.inc` ; do \
	      $(MKDIRHIER) $$installed_inc_dir/old/$(NAME).$$installed_ver; \
	      echo  Moving $$installed_inc_dir/$$fn ; \
	      echo -n "    to "; \
	      echo $$installed_inc_dir/old/$(NAME).$$installed_ver/$$fn; \
	      mv $$installed_inc_dir/$$fn \
	         $$installed_inc_dir/old/$(NAME).$$installed_ver; \
	    done; \
	  fi; \
	  if [ -d $$installed_lib_dir ] ; then \
	    for fn in `cat .installed.lib` ; do \
	      $(MKDIRHIER) $$installed_lib_dir/old/$(NAME).$$installed_ver; \
	      echo  Moving $$installed_lib_dir/$$fn to; \
	      echo -n "    to "; \
	      echo $$installed_lib_dir/old/$(NAME).$$installed_ver/$(LIBRARY);\
	      mv $$installed_lib_dir/$$fn \
		 $$installed_lib_dir/old/$(NAME).$$installed_ver/$(LIBRARY); \
	    done; \
	  fi; \
	fi

beta_install_new: 
	@echo + Installing $(VERSION)
	@rm -f .installed.ver .installed.inc .installed.lib
	$(INSTALL) $(INSTALL_INC_FLAGS) \
	  $(USER_INCS) \
	  $(BETA_INC_DIR)
	@for fn in $(USER_INCS); do \
	  basename $$fn >>.installed.inc; done
	$(INSTALL) $(INSTALL_LIB_FLAGS) \
	  $(LIBRARY) \
	  $(BETA_LIB_DIR)/$(LIBRARY).$(VERSION)
	(cd $(BETA_LIB_DIR); \
	  rm $(LIBRARY); \
	  ln -s $(LIBRARY).$(VERSION) $(LIBRARY) )
	@echo $(LIBRARY).$(VERSION) >.installed.lib
	@echo installed_ver=$(VERSION) >.installed.ver
	@echo installed_inc_dir=$(BETA_INC_DIR) >>.installed.ver
	@echo installed_lib_dir=$(BETA_LIB_DIR) >>.installed.ver

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

#
# include dependancies generated by 'make depend'
#
include .depend

#
# =MAKEFILE_LOG=
#
# $Log$
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




