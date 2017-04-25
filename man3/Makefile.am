#
# Title:        Makefile
# Project:	Common
# Desc:
# 
#   
# 
# Notes:
# 
# Author:	Paul A. Houghton - (paul.houghton@wcom.com)
# Created:	05/07/97 05:54
#
# Revision History: (See end of file for Revision Log)
#
#   Last Mod By:    $Author$
#   Last Mod:	    $Date$
#   Version:	    $Revision$
#
#   $Id$
# 

make_cfg_ver	= 5.06

include Make/make.cfg.$(make_cfg_ver)

INSTALL_MAN_DIR = $(local_mandir)
INSTALL_INC_DIR = $(local_incdir)
INSTALL_LIB_DIR = $(local_libdir)

MAN_PERM	= 444

MAN_3_PAGES	=		\
	Common.3		\
	SetErrorHandler.3	\
	GetErrorHandler.3	\
	Error.3			\
	ErrorArgs.3		\
	SetError.3		\
	ErrorMesg.3		\
	ErrorTypeString.3	\
	CommonErrorString.3	\
	SET_ERROR_CLOSURE.3	\
	SET_ERROR.3		\
	SET_APP_ERROR.3		\
	ERROR.3			\
	ERROR_APP.3		\
	ArgEnvBool.3		\
	ArgEnvDouble.3		\
	ArgEnvFlag.3		\
	ArgEnvInt.3		\
	ArgEnvLong.3		\
	ArgEnvString.3		\
	LogLevelSetString.3	\
	LogLevelFromString.3	\
	LogLevelString.3	\
	LoggerInit.3		\
	LoggerSetLogFile.3	\
	LoggerSetOutputLevel.3	\
	LoggerSetDate.3		\
	LoggerSetLoc.3		\
	LoggerSetTee.3		\
	LoggerSetFunct.3	\
	LoggerGetFunct.3	\
	LoggerLevel.3		\
	LoggerLoc.3		\
	Logger.3		\
	LoggerArgs.3		\
	LoggerTrim.3		\
	LOGITLOC.3		\
	LOGIT.3			\
	LOGFUNCT.3		\
	LOGERROR.3		\
	CHAR_TO_INT.3		\
	IS_BASE_DIGIT.3		\
	SAFE_STRCPY.3		\
	E2A.3			\
	StringToInt.3		\
	StringToUInt.3		\
	StringToShort.3		\
	StringToUShort.3	\
	StringToLong.3		\
	StringToULong.3		\
	StringToDouble.3	\
	CenterLine.3		\
	StripSpaces.3		\
	EbcdicToAscii.3		\
	strlwr.3		\
	strupr.3		\
	strdup.3		\
	basename.3		\
	IsLeapYear.3		\
	Difftm.3		\
	YYYYMMDDtoTimeT.3	\
	YYMMDDtoTimeT.3		\
	HHMMSStoTimeT.3		\
	DateStringToTimeT.3	\
	DateStringFromTimeT.3	\
	DateStringFromTm.3	\
	YearMonthDayToTimeT.3	\
	HourMinSecToTimeT.3	\
	strptime.3		\
	Bit.3			\
	Host2NetShort.3		\
	Net2HostShort.3		\
	Host2NetUShort.3	\
	Net2HostUShort.3	\
	Host2NetInt.3		\
	Net2HostInt.3		\
	Host2NetUInt.3		\
	Net2HostUInt.3		\
	Host2NetLong.3		\
	Net2HostLong.3		\
	Host2NetULong.3		\
	Net2HostULong.3		\
	AvlInit.3		\
	AvlAttach.3		\
	AvlGetRoot.3		\
	AvlAdd.3		\
	AvlDel.3		\
	AvlFind.3		\
	AvlCount.3		\
	AvlDispose.3		\
	AvlWalk.3		\
	AvlDelMin.3		\
	AvlFindMin.3		\
	AvlDelMax.3		\
	AvlFindMax.3		\
	TempFileName.3		\
	ForeachFile.3		\
	CanExecute.3		\
	FindPath.3		\
	MemberOfGroup.3		\
	FileModeString.3	\
	DWORD_ALIGN.3		\
	CommonGetVersion.3	\
	A2E.3			\
	AsciiToEbcdic.3


define REPLACE_VARS
sed -e 's!%INSTALL_LIB_DIR%!$(INSTALL_LIB_DIR)!'	\
	-e 's!%INSTALL_INC_DIR%!$(INSTALL_INC_DIR)!'
endef

install_man3: $(MAN_3_PAGES) 
	$(hide) for src in $^ ; do 				\
	  dest=$(INSTALL_MAN_DIR)/man3/$$src;			\
	  rm -f $$dest;						\
	  $(REPLACE_VARS) $$src > $$dest;			\
	  chmod $(MAN_PERM) $$dest;				\
	  echo "+ Installed $$dest";				\
	done

install		\
install_all	\
install_docs	\
install_man: install_man3

clean:

realclean:
	rm -f *~


#
# $Log$
# Revision 3.2  1999/10/29 21:42:26  houghton
# Chagned install_doc to install_docs.
#
# Revision 3.1  1999/10/29 16:56:11  houghton
# Changed Version to 3
#
# Revision 2.8  1999/05/14 10:20:41  houghton
# Bug-Fix: was not exiting with error code.
#
# Revision 2.7  1998/10/23 11:41:09  houghton
# Changed to use MakeConfigs 5.06.
#
# Revision 2.6  1998/09/24 15:39:20  houghton
# Added install_doc target.
#
# Revision 2.5  1998/09/24 14:29:23  houghton
# Reworked to replace directory names with Makefile variable value.
#
# Revision 2.4  1998/09/22 14:26:59  houghton
# Changed to use MakeConfigs 5.05.
# Added install & install_all targets.
# Renamed install.man to install_man.
#
# Revision 2.3  1997/09/02 21:32:50  houghton
# Changed to use MakeConfigs 5.02.
#
# Revision 2.2  1997/05/07 12:23:36  houghton
# Cleanup.
#
# Revision 2.1  1997/05/07 12:18:27  houghton
# Initial Version.
#
#

# Local Variables:
# mode:makefile
# End:
