/* 1994-08-04 (cc) paul4hough@gmail.com

   is current user member of provided group
*/

#include "_Common.h"

#include <unistd.h>
#include <limits.h>
#include <sys/types.h>

BOOL
MemberOfGroup( gid_t grp )
{
  gid_t groups[ NGROUPS_MAX ];
  int	count;
  int	i;

  if( ( grp == getegid() ) || ( grp == getgid() ) )
    {
      return( 1 );
    }

  if( (count = getgroups( NGROUPS_MAX, groups ) ) == 0 )
    {
      return( 0 );
    }

  for( i = 0; i < count; i++ )
    {
      if( grp == groups[i] )
	{
	  return( 1 );
	}
    }

  return( 0 );
}
