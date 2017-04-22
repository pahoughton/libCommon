#include <Common.h>
#include <stdio.h>

BOOL
tTempFileName( void )
{
  int count = 0;

  for( ; count < 500; count++ )
    {
      const char * fn = TempFileName( NULL, "test.tmp." );

      if( fn == 0 )
	{
	  ErrorMesg( "TempFileName failed!" );
	  return( FALSE );
	}

      printf( "%s\n", fn );
    }

  return( TRUE );
}
