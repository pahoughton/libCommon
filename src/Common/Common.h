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
 * Error Handling:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton (pah)
 *
 * Start Date:	    09/03/93 10:04
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.2  1994/01/31  14:06:12  houghton
 * Add avl and some other minor functions
 *
 *********************************************************************/

#include <errno.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#ifndef ON
#define ON 1
#define OFF 0
#endif

#ifndef NO
#define NO  	0
#define YES 	1
#endif

#ifndef Bool
#define Bool int   /* wanted to do an enum, but to common */
#endif

typedef enum
{
  RET_SUCCEED,
  RET_DATA,
  RET_DONE,
  RET_ERROR,
  RET_FATAL
}   Ret_Status;


/*
 *Remember to add the descriptions for new errors in
 * ErrorString.c
 */
typedef enum
{
  C_ENONE,
  C_EOSERROR,
  C_ERANGE,
  C_EBADPARAM,
  C_EAPP,		/* Application Error */  
  C_EUNDEFINED
} CommonErrorType;

extern char *	    	CommonErrFile;
extern int  	    	CommonErrLine;
extern int  	    	CommonOsErr;
extern CommonErrorType 	CommonErrno;

#define SET_ERROR( _err_ )						\
    CommonErrFile = __FILE__; CommonErrLine = __LINE__;			\
    CommonErrno = _err_;						\
    CommonOsErr = ((_err_ == C_EOSERROR ) ? errno : 0);
 
    

Ret_Status ArgEnvInt( int * argc, char *argv[],
	       const char * argid, const char * envVar,
	       int min, int max, int * paramVar );

Ret_Status ArgEnvBool( int * argc, char *argv[],
		const char * argid, const char * envVar,
	        int * paramVar );

Ret_Status ArgEnvString( int * argc, char *argv[],
		  const char * argid, const char * envVar,
	          char ** paramVar );

time_t	Difftm( struct tm * t1, struct tm * t2 );
char * strlwr( char * str );
void CenterLine( char * dest, const char * src, int width );

Ret_Status ForeachFile(
    const char *    name,
    Ret_Status      (*fileProc)( const char * name, void * closure ),
    Bool    	    recurs,
    void *  	    closure 
    );

void SetErrorHandler( void (*errorHandler_)( CommonErrorType error,
					     const char * mesg ) );

void LibError( CommonErrorType error, const char * message, ... );

const char * ErrorString( CommonErrorType error );

const char * CommonGetVersion( void );


#if defined( NeXT )
char * strdup( const char *);
#endif

#ifdef __cplusplus
};
#endif


#endif

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
