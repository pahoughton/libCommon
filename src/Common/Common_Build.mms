
!
!
! Build File for CommFabric for VAX/VMS
!
! Programmer: Dora Potluri X6131
! 
! Date:	March, 11 1994
!
!
!
.SUFFIXES		! Clear old suffixes
.SUFFIXES		.EXE .OBJ .C .H 
!
.C.OBJ :
       CC/include=([ ])/define=OPENVMS  $(MMS$TARGET_NAME)
!
.INCLUDE 		vaxa_build:include.mms
.INCLUDE		VAXA_BUILD:INCLUDE_FILES.MMS
!CMSFLAGS = $(CMSFLAGS)$(CLASS_MACRO)
!
!
!
TARGET		:	UTILITIES
			@ write sys$output "LibCommon for VMS build complete"

UTILITY_LIST  = 	ArgEnvInt.obj, -
			ArgEnvBool.obj, -
			ArgEnvString.obj, -
			ErrorString.obj, -
			strlwr.obj, -
			strupr.obj, -
			LibError.obj, -
			_ArgString.obj, -
			CommonGetVersion.obj, -
			CenterLine.obj, -
			Difftm.obj,-
			avl.obj, -
			StripSpaces.obj, -
			StringToInt.obj, -
			StringToLong.obj, -
			SetErrorHandler.obj, -
			YYMMDDtoTimeT.obj, -
			HHMMSStoTimeT.obj, -
			DateTimeData.obj, -
			LoggerInit.obj, -
			Logger.obj, -
			LogLevelFromString.obj, -
			LogLevelString.obj, -
			LoggerTrim.obj, -
			LoggerLoc.obj, -
			_LoggerFileName.obj, -
			strdup.obj, -
			TestOutput.obj, - 


ArgEnvInt.obj		: 	ArgEnvInt.c

ArgEnvBool.obj		:	ArgEnvBool.c

ArgEnvString.obj	:	ArgEnvString.c

ErrorString.obj		:	ErrorString.c

strlwr.obj		:	strlwr.c

strupr.obj		:	strupr.c

LibError.obj		:	LibError.c

_ArgString.obj		:	_ArgString.c

CommonGetVersion.obj	:	CommonGetVersion.c

CenterLine.obj		:	CenterLine.c

Difftm.obj		:	Difftm.c

avl.obj			:	avl.c

StripSpaces.obj		:	StripSpaces.c

StringToInt.obj		:	StringToInt.c

StringToLong.obj	:	StringToLong.c

SetErrorHandler.obj	:	SetErrorHandler.c

YYMMDDtoTimeT.obj	:	YYMMDDtoTimeT.c

HHMMSStoTimeT.obj	:	HHMMSStoTimeT.c

DateTimeData.obj	:	DateTimeData.c

LoggerInit.obj		:	LoggerInit.c

Logger.obj		:	Logger.c

LogLevelFromString.obj	:	LogLevelFromString.c

LogLevelString.obj	:	LogLevelString.c

LoggerTrim.obj		:	LoggerTrim.c

LoggerLoc.obj		:	LoggerLoc.c

_LoggerFileName.obj	:	_LoggerFileName.c

strdup.obj		:	strdup.c

TestOutput.obj		:	TestOutput.c


UTILITIES	:	COMMON($(UTILITY_LIST))
        		@ write $sys:output "Building Lib Common Complete Successful"




