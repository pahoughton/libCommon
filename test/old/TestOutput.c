static char RcsId[] =
"$Id$";

#include <stdio.h>
#include <stdarg.h>
#include <string.h>


static char *	LogFileName;
static char 	LogMesg[2048];

TestOutputInit( const char * fileName )
{
#ifdef OPENVMS
  FILE * writePtr;
#endif

  LogFileName = (char *)strdup( fileName );

#ifdef OPENVMS
  writePtr = fopen( fileName, "w+" );
  if ( NULL == writePtr )
  {
	fprintf( stderr, "Fatal error in TestOutput" );
  }
  fclose( writePtr );
#else
  unlink( fileName );
#endif
}

void
TestOutput(
    const char * format,
    ...
    )
{
  FILE *    	outputFp;
  va_list 	arglist;		/* for variable args */

  va_start( arglist, format );
  
  vsprintf(LogMesg, format, arglist);

  outputFp = fopen( LogFileName, "a" );

  fputs( LogMesg, outputFp );

  fclose( outputFp );
}
