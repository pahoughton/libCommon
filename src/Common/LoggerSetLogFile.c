/*********************************************************************
 *
 * Title:            LoggerSetLogFile.c
 *
 * Description:
 *
 *	This function initializes the file that log entries are
 *	written to, if the default logging funtion is used. Log files
 *	are opened with the append flag, so if the file exist, it will
 *	be appended.
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/07/95 13:17
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1997/05/07 11:36:57  houghton
 * Cleanup
 *
 * Revision 2.1  1995/11/10 00:56:05  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  LoggerSetLogFile,
  "$Id$" );

extern LogOutFileType	_CLogFileType;	    /* _LoggerDefault.c */
extern char		_CLogFilePath[];    /* _LoggerFileName.c */
extern char		_CLogFileName[];    /* _LoggerFileName.c */

extern long	_CLogMaxSize;	/* _LoggerDefault.c */
extern long	_CLogTrim;	/* _LoggerDefault.c */

extern FILE *	_CLogFP;	/* _LoggerDefault.c */

Ret_Status
LoggerSetLogFile(
  const char *	    logPath,
  const char *	    logFileName,
  LogOutFileType    outputFileType,
  long		    maxByteCount,
  long		    trimIncrement
  )
{
  if( outputFileType == LOG_STDOUT )
    COMMON_RETURN_ERROR( EC_BADPARAM,
			 ("Output file type is 'LOG_STDOUT'") );
      
  if( logPath != NULL )
    {
      if( strlen( logPath )  > COMMON_PATH_MAX )
	COMMON_RETURN_ERROR( EC_BADPARAM,
			     ("logPath '%s' to long max %d",
			      logPath,
			      COMMON_PATH_MAX ) );

      strcpy( _CLogFilePath, logPath );
    }

  if( logFileName != NULL )
    {
      if( strlen( logFileName ) > FILENAME_MAX )
	COMMON_RETURN_ERROR( EC_BADPARAM,
			     ("logFileName '%s' to long max %d",
			      logFileName,
			      FILENAME_MAX ) );

      strcpy( _CLogFileName, logFileName );
    }

  _CLogFileType = outputFileType;
  _CLogMaxSize  = maxByteCount;
  _CLogTrim     = trimIncrement;

  if( _CLogFileType != LOG_REOPEN )
    {
      char logFn[1024];

      _LoggerFileName( logFn, sizeof( logFn ) );
      
      if( (_CLogFP = fopen( logFn, "a" )) == NULL)
	{
	  SET_ERROR( ET_OSERROR, errno );
	  _CommonErrorDesc( "Can't open '%s'", logFn );
	  return( RET_ERROR );
	}
    }
      

  return( RET_SUCCEED );
}

