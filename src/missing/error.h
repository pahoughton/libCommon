#ifndef _missing_error_h_
#define _missing_error_h_
/* 1993-09-03 (cc) paul4hough@gmail.com
 */
#include <stdarg.h>


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
  ET_LIB,	/* lib Error */
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

#endif /* defined _missing_error_h_ */
