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
  RET_DATA,
  RET_DONE,
  RET_ERROR,
  RET_FATAL
}   Ret_Status;


/*
 * Remember to add the descriptions for new errors in ErrorString.c
 */
typedef enum
{
  C_ENONE,
  C_ERANGE,		/* Argument out of legal value range */
  C_EBADPARAM,		/* Bad argument */
  C_ECOMMFABRIC,    	/* CF Errro */
  C_ESYBERR,		/* Sybase Error */
  C_ESYBMSG,		/* Sybase Message */
  C_ESYBOC,		/* SybocErrno */
  C_EOSERROR,		/* system call error */
  C_EAPP,		/* Application Error */  
  C_EUNDEFINED
} CommonErrorType;

extern char *	    	CommonErrFile;
extern int  	    	CommonErrLine;
extern int  	    	CommonOsErr;
extern CommonErrorType 	CommonErrno;
extern int		CommonAppErrno;

#define SET_ERROR( _err_ )						\
    CommonErrFile = __FILE__; CommonErrLine = __LINE__;			\
    CommonErrno = _err_;						\
    CommonOsErr = ((_err_ == C_EOSERROR ) ? errno : 0);
 
#define SET_APP_ERROR( _err_ )	\
    SET_ERROR( C_EAPP );	\
    CommonAppErrno = _err_;     \

#define LIB_ERROR( _close_, _str_ )    \
    LibError( CommonErrno, CommonAppErrno, _close_, _str_ )


void SetErrorHandler( void (*errorHandler_)( CommonErrorType error,
					     int appErrno,
					     void * closure,
					     const char * mesg ),
		      void * closure );

void LibError( CommonErrorType error,
	       int appErrno,
	       void * closure,
	       const char * message, ... );

const char * ErrorString( CommonErrorType error );


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
  LOG_NONE  = 0,
  LOG_ERROR = 0x01,
  LOG_WARN  = 0x02,
  LOG_USR1  = 0x04,
  LOG_USR2  = 0x08,
  LOG_INFO  = 0x10,
  LOG_TEST  = 0x20,
  LOG_DEBUG = 0x40,
  LOG_FUNCT = 0x80,
  LOG_ALL   = 0xff
} LogBit;

typedef enum
{
  LOG_SET,
  LOG_ON,
  LOG_OFF
} LogSetLevelType;
  
typedef enum
{
  LOG_BY_DATE,
  LOG_REOPEN,
  LOG_KEEP_OPEN
} LogOutFileType;



void LoggerInit( const char *	logPath,
		 const char *	logFileName,
		 LogOutFileType outputFileType,
		 long	    	maxByteCount,
		 long	    	trimIncrement,
		 LogSetLevelType setType,
		 int		 outputLevels,
		 BOOL		 outputDate,
		 BOOL		 outputSourceLoc
		 );

BOOL LoggerTee( BOOL state );

void Logger( const char * msgFmt, ... );

BOOL LoggerLoc( BOOL state );
void LoggerTrim( void );
int  LogLevelFromString( const char * levelString );
const char * LogLevelString( LogBit lvl );


extern int	  _CLogOutputLevel;
extern LogBit     _CLogCurMesgLevel;
extern const char * _CLogLocFile;
extern int  	    _CLogLocLine;

#define LOGIT( _lvl_, _logf_ )						     \
{									     \
  if( _lvl_ & _CLogOutputLevel )					     \
    {									     \
      _CLogCurMesgLevel = _lvl_;					     \
      _CLogLocFile = __FILE__;						     \
      _CLogLocLine = __LINE__;						     \
      _logf_;								     \
      _CLogCurMesgLevel = LOG_NONE;					     \
    }									     \
}									     \
  
		 
/**************************************************************
 * S T R I N G   P r o c e s s i n g 
 **************************************************************/
  

#define CHAR_TO_INT( _d_ ) \
( ( _d_ <= '9' ) ? _d_ - '0' : ( 10 + ( (_d_ | 0x20) - 'a' ) ))

#define IS_BASE_DIGIT( _d_, _b_ ) \
(CHAR_TO_INT(_d_) >= 0 && CHAR_TO_INT(_d_) < _b_ )

#define SAFE_STRCPY( _dest_, _src_, _size_ );    \
strncpy( _dest_, _src_, _size_); _dest_[_size_ - 1] = 0;
    

extern const char EtoA[];

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


/**************************************************************
 * D A T E / T I M E   P r o c e s s i n g 
 **************************************************************/
      
#define SEC_PER_MIN   60
#define SEC_PER_HOUR  (60 * SEC_PER_MIN)
#define SEC_PER_DAY   (24 * SEC_PER_HOUR)
#define SEC_PER_YEAR  (365 * SEC_PER_DAY)
#define MIN_PER_HOUR  60

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
extern const int    MonthDayOfYear[];
extern const char * Months[];
extern const char * AbbrMonths[];
extern const char * WeekDays[];
extern const char * AbbrWeekDays[];

BOOL
IsLeapYear( short year );

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
strptime( char *buf, const char *format, struct tm *tm);
#endif


/**************************************************************
 * Bit manipulation - (see CommonConfig.h for values)
 *
 * #define Bit( bitNumber )
 *
 * #define CHAR_BITS
 * #define SHORT_BIT
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

#define Net2HostShort( s )  COMMON_n2hs( s )
#define Host2NetShort( s )  COMMON_n2hs( s )

#define Net2HostUShort( us ) COMMON_n2hs( us )
#define Host2NetUShort( us ) COMMON_n2hs( us )

#define Net2HostLong( l )  COMMON_n2hl( l )
#define Host2NetLong( l )  COMMON_n2hl( l )

#define Net2HostULong( ul ) COMMON_n2hl( ul )
#define Host2NetULong( ul ) COMMON_n2hl( ul )
  
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

Ret_Status
ForeachFile( const char *   name,
	     Ret_Status     (*fileProc)( const char * name,
					 void * closure ),
	     BOOL	    recurs,
	     void *	    closure );

BOOL
CanExecute( const char * fileName );


#if defined( COMMON_HAVE_GROUPS )
BOOL
MemberOfGroup( gid_t grp );
#endif

#if defined( COMMON_HAVE_MODE_T )
const char * 
FileModeString( mode_t	mode, char * modeString );
#endif

#if !defined( COMMON_HAVE_BASENAME )
const char * basename( const char * path );
#endif

extern const char CommonVersion[];

const char * CommonGetVersion( void );

#define DWORD_ALIGN( _addr_ ) \
  ( ((_addr_ % 4) == 0) ? _addr_ :  ( _addr_  + ( 4 - ( _addr_ % 4 ) ) ) )


#ifdef __cplusplus
};
#endif


/*
 * Modification History
 *     			
 * $Log$
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
