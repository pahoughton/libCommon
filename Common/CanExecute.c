/* 1994-08-04 (cc) Paul Houghton <paul4hough@gmail.com>

   is filename executable
*/
#include "Common.h"

#include <unistd.h>
#include <sys/stat.h>

BOOL
CanExecute( const char * fileName )
{

  struct stat st;

  if( stat( fileName, &st ) == 0 &&
      ( ( st.st_uid == geteuid() && ( st.st_mode & S_IXUSR ) ) ||
	( MemberOfGroup( st.st_gid ) && ( st.st_mode & S_IXGRP ) ) ||
	( st.st_mode & S_IXOTH ) ) )
    {
      return( TRUE );
    }

  return( FALSE );

}
