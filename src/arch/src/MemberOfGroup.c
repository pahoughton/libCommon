/*********************************************************************
 *
 * Title:            MemberOfGroup.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/04/94 10:20
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.2  1994/08/15  19:57:08  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:20  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/
static const char * RcsId =
"$Id$";

#include <unistd.h>
#include <limits.h>
#include <sys/types.h>

#include "_Common.h"

Bool
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
