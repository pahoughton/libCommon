#ifndef _COMMON_H_
#define _COMMON_H_
/*********************************************************************
 *
 * Title:            Common.h
 *
 * Description:
 *
 *	Common / Generic C Functions
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (paul_houghton@wiltel.com)
 *
 * Start Date:	    09/03/93 10:04
 *
 * Modification History: See end of file
 *
 *  $Id$
 *
 *********************************************************************/

#if !defined( COMMON_SHORT_FN )
#include <CommonConfig.h>
#else
#include <CmmnCfg.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define COMMON_LIB_VERSION	    0x02010200

extern const long CommonLibVersion;

extern const char CommonVersion[];

const char * CommonGetVersion( void );

/* Boolean type and values */

#if !defined( BOOL )
#define BOOL	int
#endif

#if !defined( TRUE )
#define TRUE 1
#endif

#if !defined( FALSE )
#define FALSE 0
#endif

#if !defined( ON )
#define ON TRUE
#define OFF FALSE
#endif

#if !defined( NO )
#define NO  	FALSE
#define YES 	TRUE
#endif

  

/**************************************************************
 * E R R O R   P r o c e s s i n g 
 **************************************************************/
  
typedef enum
{
  RET_SUCCEED,
  RET_DONE,
  RET_DATA,
  RET_ERROR,
  RET_FATAL
} Ret_Status;


/*
 * Remember to add the descriptions for new errors in ErrorString.c
 */
typedef enum
{
  ET_NONE,
  ET_APP,	/* Application Error */  
  ET_OSERROR,	/* system call error */
  ET_COMMON,	/* libCommon Error */
  ET_WCF,	/* CF Errro */
  ET_SYBERR,	/* Sybase Error */
  ET_SYBMSG,	/* Sybase Message */
  ET_SYBOC,	/* Syboc Error */
  ET_UNDEFINED
} CommonErrorType;

typedef enum
{
  EC_NONE,
  EC_BADPARAM,
  EC_RANGE,
  EC_UNDEFINED
} CommonError;

/* SetError (below) assigns values to these */

extern CommonErrorType	CommonErrType;
extern CommonError	CommonErrValue;
extern const char *	CommonErrDesc;
extern const char *	CommonErrFile;
extern long		CommonErrLine;
extern void *		CommonErrClosure;

typedef int (* CommonErrorHandler)( void *		closure,
				    const char *	srcFileName,
				    long		srcLineNumber,
				    CommonErrorType	errorType,
				    int			errorValue,
				    const char *	errorDesc,
				    const char *	mesgFormat,
				    va_list		args );


void
SetErrorHandler( CommonErrorHandler handler, void * closure );

void
GetErrorHandler( CommonErrorHandler * handler, void ** closure );

int
Error( const char *	srcFileName,
       long		srcLineNumber,
       CommonErrorType	errorType,
       int		errorValue,
       void *		closure,
       const char *	errorDesc,
       const char *	mesgFormat,
       ... );

int
ErrorArgs( const char *	    srcFileName,
	   long		    srcLineNumber,
	   CommonErrorType  errorType,
	   int		    errorValue,
	   void *	    closure,
	   const char *	    errorDesc,
	   const char *	    mesgFormat,
	   va_list	    args );

void
SetError( const char *	    srcFileName,
	  long		    srcLineNumber,
	  CommonErrorType   errorType,
	  int		    errorValue,
	  const char *	    errorDesc,
	  void *	    closure );
       
int
ErrorMesg( const char * mesgFormat, ... );

const char *
ErrorTypeString( CommonErrorType errType );

const char *
CommonErrorString( CommonError errValue );


#define SET_ERROR_CLOSURE( type_, value_, closure_ ) \
  SetError( __FILE__, __LINE__, type_, value_, 0, closure_ )

#define SET_ERROR( type_, value_ ) \
  SET_ERROR_CLOSURE( type_, value_, NULL )

#define ERROR( type_, value_, args_ )					      \
{									      \
  SET_ERROR( type_, value_ );						      \
  (void)ErrorMesg args_;						      \
}

#define ERROR_APP( value_, args_ )					      \
{									      \
  SET_ERROR( ET_APP, value_ );						      \
  (void)ErrorMesg args_;						      \
}

	       
/**************************************************************
 * A R G / E N V   P r o c e s s i n g 
 **************************************************************/


Ret_Status ArgEnvInt( int * argc, char *argv[],
		      const char * argid, const char * envVar,
		      int min, int max, int * paramVar );

Ret_Status ArgEnvLong( int * argc, char *argv[],
		       const char * argid, const char * envVar,
		       long min, long max, long * paramVar );

Ret_Status ArgEnvBool( int * argc, char *argv[],
		       const char * argid, const char * envVar,
		       int * paramVar );

Ret_Status ArgEnvFlag( int * argc, char *argv[],
		       const char * argid, const char * envVar,
		       BOOL * paramVar );

Ret_Status ArgEnvString( int * argc, char *argv[],
			 const char * argid, const char * envVar,
			 char ** paramVar );

Ret_Status ArgEnvDouble( int * argc, char * argv[],
			 const char * argid, const char * envVar,
			 double * paramVar );

/**************************************************************
 * L O G G I N G 
 **************************************************************/

typedef enum
{
  LOG_NONE  = 0x0000,
  LOG_ERROR = 0x0001,
  LOG_WARN  = 0x0002,
  LOG_APP1  = 0x0004,
  LOG_APP2  = 0x0008,
  LOG_APP3  = 0x0010,
  LOG_APP4  = 0x0020,
  LOG_APP5  = 0x0040,
  LOG_APP6  = 0x0080,
  LOG_LIB1  = 0x0100, /* WARNING: used by Wcf */
  LOG_LIB2  = 0x0200, /* WARNING: used by Wcf */
  LOG_LIB3  = 0x0400, /* WARNING: used by Wcf */
  LOG_LIB4  = 0x0800, /* WARNING: used by Wcf */
  LOG_INFO  = 0x1000,
  LOG_TEST  = 0x2000,
  LOG_DEBUG = 0x4000,
  LOG_FUNCT = 0x8000,
  LOG_ALL   = 0xffff
} LogLevelBit;

#define LOG_WCF1    LOG_LIB1
#define LOG_WCF2    LOG_LIB2
#define LOG_WCF3    LOG_LIB3
#define LOG_WCF4    LOG_LIB4

typedef enum
{
  LOG_SET,
  LOG_ON,
  LOG_OFF
} LogSetLevelType;
  
typedef enum
{
  LOG_STDOUT,
  LOG_BY_DATE,
  LOG_REOPEN,
  LOG_KEEP_OPEN
} LogOutFileType; 

typedef void (* LoggerFunct)( void *	    closure,
			      const char *  srcFileName,
			      long	    srcLineNumber,
			      LogLevelBit   level,
			      const char *  mesgFmt,
			      va_list	    mesgArgs );

/* WARNING: the 'name' is not copied. the pointer is used */

const char *	LogLevelSetString( LogLevelBit level, const char * name );
int		LogLevelFromString( const char * levelString );
const char *	LogLevelString( LogLevelBit level );

Ret_Status
LoggerInit( const char *	logPath,
	    const char *	logFileName,
	    LogOutFileType	outputFileType,
	    long	    	maxByteCount,
	    long	    	trimIncrement,
	    LogSetLevelType	setType,
	    int			outputLevels,
	    BOOL		outputDate,
	    BOOL		outputSourceLoc,
	    BOOL		teeOutput,
	    LoggerFunct		funct,
	    void *		closure
	    );

Ret_Status
LoggerSetLogFile( const char *	    path,
		  const char *	    fileName,
		  LogOutFileType    outFileType,
		  long		    maxByteCount,
		  long		    trimIncrement );


int
LoggerSetOutputLevel( LogSetLevelType setType, int outputLevels );

BOOL
LoggerSetDate( BOOL outputDate );

BOOL
LoggerSetLoc( BOOL outputLoc );

BOOL
LoggerSetTee( BOOL  teeOutput );

void
LoggerSetFunct( LoggerFunct funct, void * closure );

void
LoggerGetFunct( LoggerFunct * funct, void ** closure );

LogLevelBit
LoggerLevel( LogLevelBit level );

void
LoggerLoc( const char * fileName, long lineNumber );

void
Logger( const char * msgFmt, ... );

void
LoggerArgs( const char *    srcFileName,
	    long	    srcLineNumber,
	    LogLevelBit     level,
	    void *	    closure,
	    const char *    mesgFmt,
	    va_list	    mesgArgs );

Ret_Status
LoggerTrim( void );


extern int _CLogOutputLevel;

#define LOGITLOC( file_, line_, level_, logArgs_ )			      \
{									      \
  if( level_ & _CLogOutputLevel )					      \
    {									      \
      (void)LoggerLevel( level_ );					      \
      (void)LoggerLoc( file_, line_ );					      \
      Logger logArgs_ ;							      \
      (void)LoggerLevel( LOG_NONE );					      \
    }									      \
}

#define LOGIT( level_, logArgs_ )  \
  LOGITLOC( __FILE__, __LINE__, level_, logArgs_ )
  
#define LOGFUNCT( name_ ) \
    LOGIT( LOG_FUNCT, ( #name_ "\n" ) )

#define LOGERROR( args_ ) \
  LOGIT( LOG_ERROR, args_ )

/**************************************************************
 * S T R I N G   P r o c e s s i n g 
 **************************************************************/
  

#define CHAR_TO_INT( _d_ ) \
( ( _d_ <= '9' ) ? _d_ - '0' : ( 10 + ( (_d_ | 0x20) - 'a' ) ))

#define IS_BASE_DIGIT( _d_, _b_ ) \
(CHAR_TO_INT(_d_) >= 0 && CHAR_TO_INT(_d_) < _b_ )

#define SAFE_STRCPY( _dest_, _src_, _size_ );    \
strncpy( _dest_, _src_, _size_); _dest_[_size_ - 1] = 0;
    

extern const unsigned char EtoA[];

#define E2A( _c_ ) (EtoA[((unsigned char)(_c_))])

int   	    	StringToInt( const char * str, int base, int len );
unsigned int   	StringToUInt( const char * str, int base, int len );
short	    	StringToShort( const char * str, int base, int len );
unsigned short	StringToUShort( const char * str, int base, int len );
long  	    	StringToLong( const char * str, int base, int len );
unsigned long   StringToULong( const char * str, int base, int len );
double 	    	StringToDouble( const char * str, int bash, int len );

char * CenterLine( char * dest, const char * src, int width );
void StripSpaces( char * buffer );

void EbcdicToAscii( unsigned char * buf, int len );

#if !defined( COMMON_HAVE_STRLWR )
char * strlwr( char * str );
#endif

#if !defined( COMMON_HAVE_STRUPR )
char * strupr( char * str );
#endif

#if !defined( COMMON_HAVE_STRDUP )
char * strdup( const char *);
#endif

#if !defined( COMMON_HAVE_BASENAME )
const char * basename( const char * path );
#endif


/**************************************************************
 * D A T E / T I M E   P r o c e s s i n g 
 **************************************************************/
      
#define SEC_PER_MIN   60
#define SEC_PER_HOUR  (60 * SEC_PER_MIN)
#define SEC_PER_DAY   (24 * SEC_PER_HOUR)
#define SEC_PER_YEAR  (365 * SEC_PER_DAY)
#define MIN_PER_HOUR  60
#define MIN_TIMET     LONG_MIN
#define MAX_TIMET     LONG_MAX
#define MIN_YEAR      (1970 + (MIN_TIMET / SEC_PER_YEAR))
#define MAX_YEAR      (1970 + (MAX_TIMET / SEC_PER_YEAR))

#if !defined( DAYOFWEEK_ENUM )
#define DAYOFWEEK_ENUM 1

typedef enum {
  Sunday = 0,
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday
} DayOfWeek;

#endif

/*
 * These constants are defined in DateTimeData.c if your linker
 * has problems finding them (MS-Win) call the LinkDateData function
 * from main.
 */

/* function in DataTimeData.c needed for some linkers */
void LinkDateData( void );  
 
extern const int    DaysInMonth[];
extern const int    DaysInMonthLeap[];
extern const int    MonthDayOfYear[];
extern const int    MonthDayOfYearLeap[];
extern const char * Months[];
extern const char * AbbrMonths[];
extern const char * WeekDays[];
extern const char * AbbrWeekDays[];

#if !defined( STLUTILS_IsLeapYear )
#define COMMON_IsLeapYear 1

BOOL
IsLeapYear( int year );

#endif

time_t
Difftm( struct tm * t1, struct tm * t2 );

time_t
YYYYMMDDtoTimeT( const char * yymmdd );

time_t
YYMMDDtoTimeT( const char * yymmdd );

time_t
HHMMSStoTimeT( const char * hhmmss );

time_t
DateStringToTimeT( const char * dateString, const char * fmt );

const char *
DateStringFromTimeT( char * buf, const char * fmt, time_t sec );

const char *
DateStringFromTm( char * buf, const char * fmt, const struct tm * tmTime );

time_t
YearMonthDayToTimeT( int year, int month, int day );

#define HourMinSecToTimeT( hour, min, sec ) \
  ( (hour * 60 * 60 ) + (min * 60) + sec )

    
#if !defined( COMMON_HAVE_STRPTIME )
char *
strptime( const char * buf, const char * format, struct tm *tm);
#endif


/**************************************************************
 * Bit manipulation - (see CommonConfig.h for values)
 *
 * #define Bit( bitNumber )
 *
 * #define CHAR_BITS
 * #define SHORT_BITS
 * #define LONG_BITS
 * #define INT_BITS
 *
 * #define CHAR_ALL_BITS
 * #define SHORT_ALL_BITS
 * #define LONG_ALL_BITS
 * #define INT_ALL_BITS
 *
 **************************************************************/

/**************************************************************
 * Net2Host - Network converters (declared in CommonConfig.h)
 *
 * short	  Net2HostShort( short from );
 * long		  Net2HostLong( long from );
 * unsigned short Net2HostUShort( unsigned short from );
 * unsigned long  Net2HostLong( unsigned long from );
 *
 * short	  Host2NetShort( short from );
 * long		  Host2NetLong( long from );
 * unsigned short Host2NetUShort( unsigned short from );
 * unsigned long  Host2NetLong( unsigned long from );
 *
 **************************************************************/

#if !defined( Net2Host )

#define Host2NetShort( s )  COMMON_n2hs( s )
#define Net2HostShort( s )  COMMON_n2hs( s )

#define Host2NetUShort( us ) COMMON_n2hs( us )
#define Net2HostUShort( us ) COMMON_n2hs( us )

#define Host2NetInt( i )  COMMON_n2hi( i )
#define Net2HostInt( i )  COMMON_n2hi( i )

#define Host2NetUInt( ui ) COMMON_n2hi( ui )
#define Net2HostUInt( ui ) COMMON_n2hi( ui )
  
#define Host2NetLong( l )  COMMON_n2hl( l )
#define Net2HostLong( l )  COMMON_n2hl( l )

#define Host2NetULong( ul ) COMMON_n2hl( ul )
#define Net2HostULong( ul ) COMMON_n2hl( ul )
  
#endif
/**************************************************************
 * A V L - Balanced Binary Tree
 **************************************************************/

typedef void * AvlTree;

typedef  enum  {       /* definition of traversal type */
  AVL_PREORDER,
  AVL_INORDER,
  AVL_POSTORDER
}  AvlVisit;

typedef  enum  {       /* definition of sibling order type */
  AVL_LEFT_TO_RIGHT,
  AVL_RIGHT_TO_LEFT
}  AvlSiblingOrder;

typedef  enum  {       /* definition of node type */
  AVL_IS_TREE,
  AVL_IS_LBRANCH,
  AVL_IS_RBRANCH,
  AVL_IS_LEAF,
  AVL_IS_NULL
} AvlNodeType;


AvlTree AvlInit( int    (*compare)(const void * data1,
				   const void * data2,
				   AvlNodeType nd),
		 void * (*getMem)( size_t size, void * closure ),
		 void   (*freeMem)( void * data, void * closure ),
		 void * memClosure );

/* for attaching to a memory mapped tree */

AvlTree AvlAttach( void * avlRoot,
		   int      (*compare)(const void * data1,
				       const void * data2,
				       AvlNodeType nd),
		   void *   (*getMem)( size_t size, void * closure ),
		   void     (*freeMem)( void * data, void * closure ),
		   void *   memClosure );

void * AvlGetRoot( AvlTree  tree );

void * AvlAdd( AvlTree tree, void * key );
void * AvlDel( AvlTree tree, void * key );
void * AvlFind( AvlTree tree, const void * key );
unsigned long    AvlCount( AvlTree tree );

void AvlDispose( AvlTree * treeptr,
		 void      (*action)( void * data,
				      AvlVisit order,
				      void * closure ),
  		 AvlSiblingOrder  sibling_order,
		 void *	   closure );

void AvlWalk( AvlTree      tree,
	      void          (*action)( void * data, AvlVisit order,
				       AvlNodeType node, int level,
				       short bal, void * closure),
	      AvlSiblingOrder  sibling_order,
	      void * 	   closure );

void * AvlDelMin( AvlTree  tree );
void * AvlFindMin( AvlTree  tree );
void * AvlDelMax( AvlTree  tree );
void * AvlFindMax ( AvlTree  tree );

void * AvlSetTreeData( AvlTree tree, void * data );
void * AvlGetTreeData( AvlTree tree );

#if defined( COMMON_HAVE_LOCKING )
/************************************************************/
/* AvlTree Locking Mechanisms */
/************************************************************/
  
int    InitLocking( const char *    fileName ,
		    int 	    accessFlag,
		    const char	    keyID );
int    AvlLockTree( AvlTree tree, int semId );
int    AvlUnlockTree( AvlTree tree, int semId  );
int    AvlWaitForUnlock( AvlTree tree, int semId  );
int    AvlGetNumberOfUsers( AvlTree tree );
#endif

/**************************************************************
 * M I S C   
 **************************************************************/

const char *
TempFileName( const char * dir, const char * prefix );

Ret_Status
ForeachFile( const char *   name,
	     Ret_Status     (*fileProc)( const char * name,
					 void * closure ),
	     BOOL	    recurs,
	     void *	    closure );

BOOL
CanExecute( const char * fileName );

char *
FindPath( const char * fileName, const char * path );

#if defined( COMMON_HAVE_GROUPS )
BOOL
MemberOfGroup( gid_t grp );
#endif

#if defined( COMMON_HAVE_MODE_T )
const char * 
FileModeString( mode_t	mode, char * modeString );
#endif

#define DWORD_ALIGN( _addr_ ) \
  ( ((_addr_ % 4) == 0) ? _addr_ :  ( _addr_  + ( 4 - ( _addr_ % 4 ) ) ) )


#ifdef __cplusplus
}
#endif


/*
 * Modification History
 *     			
 * $Log$
 * Revision 2.21  1999/03/02 12:42:42  houghton
 * Added DaysInMonthLeap
 * Added MonthDayOfYearLeap
 *
 * Revision 2.20  1998/09/24 14:32:00  houghton
 * Changed strptime 'buf' arg to const char * (was char *).
 *
 * Revision 2.19  1998/03/21 17:17:43  houghton
 * Removed ';' to eliminate compiler warning.
 *
 * Revision 2.18  1998/02/18 15:46:22  houghton
 * Bug-Fix: MIN_YEAR and MAX_YEAR need to be based of 1970.
 *
 * Revision 2.17  1997/09/19 09:00:20  houghton
 * Changed: renamed CommonError* variables to CommonErr becuase of conflict with
 *     enum names.
 *
 * Revision 2.16  1997/08/24 21:46:35  houghton
 * Added MIN_TIMET, MAX_TIMET, MIN_YEAR & MAX_YEAR.
 *
 * Revision 2.15  1997/07/18 18:44:24  houghton
 * Port(Sun5): Changed EtoA to unsigned char.
 *
 * Revision 2.14  1997/05/07 11:36:33  houghton
 * Cleanup
 * Added FindPath declaration.
 *
 * Revision 2.13  1997/04/29 12:27:16  houghton
 * Cleanup
 * Added CommonLibVersion.
 *
 * Revision 2.12  1997/04/26 13:32:06  houghton
 * Changed LOG_WCF* to LOG_LIB* and added defines for LOG_WCR*.
 *
 * Revision 2.11  1997/04/26 12:44:16  houghton
 * Added COMMON_LIB_VERSION define.
 *
 * Revision 2.10  1997/04/26 12:08:45  houghton
 * Bug-Fix: changed value of LOG_ALL to 0xffff.
 *
 * Revision 2.9  1997/03/03 14:12:28  houghton
 * Bug-Fix: changed ErrorMesg arg type to const char *.
 *
 * Revision 2.8  1996/02/29 16:20:44  houghton
 * Add Net to Host Conversion for Int and UInt
 *
 * Revision 2.7  1995/12/02 02:03:53  houghton
 * Add test and define for using libCommon with libClue.
 *
 * Revision 2.6  1995/11/10  00:44:32  houghton
 * Modified to use new Error processing routines
 * Modified for enhanced Logging routines
 *
 * Revision 2.5  1995/10/31  12:38:29  houghton
 * Move version info from CommonVersion.h to _Common.h
 * Use MakeConfigs 3.3
 * Update ErrorStrings for all CommonErrorType values
 *
 * Revision 2.4  1995/10/30  14:55:13  houghton
 * Move contents of Bit.h & DateTime.h to Common.h
 * Add Net2Host
 *
 * Revision 2.3  1995/10/29  18:15:57  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.2  1995/10/29  13:33:41  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/28  19:11:39  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:15  houghton
 * Move to Version 2.0
 *
 * Revision 1.15  1995/03/02  16:39:55  houghton
 * minor mods
 *
 * Revision 1.14  1995/02/13  15:34:13  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.13  1994/12/02  17:25:41  dpotluri
 * Added locking to Avl Trees
 *
 * Revision 1.12  1994/08/15  19:40:17  houghton
 * Cleanup; Rating QA1 Checkin
 *
 * Revision 1.11  1994/07/26  14:37:19  houghton
 * Fix basename in Common.h
 * Fix month in Logger
 *
 * Revision 1.10  1994/07/13  13:43:00  houghton
 * Added LoggerTee function and fixed some bugs with logging
 *
 * Revision 1.9  1994/07/05  21:39:13  houghton
 * Minor fixes and cleanup header info.
 *
 * Revision 1.8  1994/06/20  15:28:38  dpotluri
 * LibCommon Port to OPENVMS
 *
 * Revision 1.7  1994/06/20  10:27:18  houghton
 * Porting and add LoggerLoc function
 *
 * Revision 1.6  1994/06/17  21:48:14  dpotluri
 * Minor mods to the function Logger
 *
 * Revision 1.5  1994/06/17  18:03:56  houghton
 * Cleanup for beta release.
 *
 * Revision 1.4  1994/06/06  13:23:34  houghton
 * Avl and DateTime functions added for Rating
 *
 * Revision 1.3  1994/02/02  14:38:25  houghton
 * Had to rename error to LibError because of a conflicts with other
 * symbols. Minor mods to other files
 *
 * Revision 1.2  1994/01/31  14:06:12  houghton
 * Add avl and some other minor functions
 *
 */

/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1993 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
/*
 * Well actually most of it is public domain.
 */
#endif /* ! def _Common_h_ */
