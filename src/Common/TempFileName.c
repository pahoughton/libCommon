/*********************************************************************
 *
 * Title:            TempFileName.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    11/09/95 04:13
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.4  1998/10/23 11:37:32  houghton
 * Removed include <paths.h>
 *
 * Revision 2.3  1998/09/22 14:33:38  houghton
 * Added include paths.h.
 *
 * Revision 2.2  1995/12/02 02:08:05  houghton
 * Reorder includes.
 *
 * Revision 2.1  1995/11/10  00:56:06  houghton
 * Initial Version
 *
 *
 *********************************************************************/

#include "_Common.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

COMMON_VERSION(
  TempFileName,
  "$Id$" );

static char Pid[ 10 ] = "";
static char Unique[ 4 ] = "aaa";

static char TempName[ COMMON_PATH_MAX + FILENAME_MAX ];

static size_t	Value[3] = { 0, 0, 0 };

static char UniqueNum[] =  "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "0123456789";

  
const char *
TempFileName( const char * dir, const char * prefix )
{
  const char *	tmpDir = NULL;
  const char *  tmpPrefix;
  
  size_t	len = 0;

  if( dir )
    tmpDir = dir;
  
  if( tmpDir == NULL )
    tmpDir = getenv( "TMPDIR" );

  if( tmpDir == NULL )
    tmpDir = getenv( "TMP" );

  if( tmpDir == NULL )
    tmpDir = getenv( "TEMP" );

  if( tmpDir == NULL )
    tmpDir = COMMON_TEMP_DIR;

  len += strlen( tmpDir );

  if( prefix )
    len += ( ( ( strlen( prefix ) + COMMON_TEMPNAME_SIZE ) > FILENAME_MAX ) ?
	     FILENAME_MAX : strlen( prefix ) );
  
  if( len > sizeof( TempName ) )
    {
      COMMON_SET_ERROR( EC_BADPARAM, ("name to long '%s%s%s' max %d",
				      dir,
				      COMMON_DIR_SEP_STRING,
				      prefix,
				      sizeof( TempName ) ) );
      return( NULL );
    }

  tmpPrefix = ( prefix != NULL ) ? prefix : "";
  
  if( Pid[0] == 0 )
    sprintf( Pid, COMMON_PID_FORMAT, getpid() );

  while( Value[0] != sizeof( UniqueNum ) )
    {
      struct stat fileStat;
      
      sprintf( TempName, "%s%s%s%s%s",
	       tmpDir,
	       COMMON_DIR_SEP_STRING,
	       prefix,
	       Pid,
	       Unique );

      if( Value[2] == (sizeof( UniqueNum ) - 2) )
	{
	  Value[1]++;
	  Value[2] = 0;
	  if( Value[1] == (sizeof( UniqueNum ) - 2) )
	    {
	      Value[0]++;
	      Value[1] = 0;
	    }
	  if( Value[0] == (sizeof( UniqueNum ) - 2) )
	    break;
	}
      else
	{
	  Value[2]++;
	}

      Unique[0] = UniqueNum[ Value[ 0 ] ];
      Unique[1] = UniqueNum[ Value[ 1 ] ];
      Unique[2] = UniqueNum[ Value[ 2 ] ];
  
	      
      if( stat( TempName, &fileStat ) != 0 )
	return( TempName );

    }
  
  COMMON_SET_ERROR( EC_BADPARAM, ("can't generate temp name from '%s%s%s'",
				  dir,
				  COMMON_DIR_SEP_STRING,
				  prefix ) );
  return( NULL );
}
