/*********************************************************************
 *
 * Title:            CanExecute.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    08/04/94 10:14
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.1  1995/10/29 18:14:25  houghton
 * Change version to 2
 *
 * Revision 1.1  1995/10/29  18:13:58  houghton
 * First Borland Port support files
 *
 * Revision 2.1  1995/10/29  13:33:55  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.0  1995/10/28  17:35:46  houghton
 * Move to Version 2.0
 *
 * Revision 1.3  1995/02/13  15:34:13  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.2  1994/08/15  19:56:59  houghton
 * Fix RcsId so ident will work
 *
 * Revision 1.1  1994/08/15  19:42:19  houghton
 * Add ArgEnvFlage, ArgEnvLong, CanExecute, FindPath and MemberOfGroup
 * functions
 *
 *
 *********************************************************************/
#include "_Common.h"

COMMON_VERSION(
  CanExecute,
  "$Id$");

BOOL
CanExecute( const char * fileName )
{

  size_t len = strlen( fileName );

  if( !stricmp( fileName + len - 4, ".bat" ) ||
      !stricmp( fileName + len - 4, ".com" ) ||
      !stricmp( fileName + len - 4, ".exe" ) )
    return( TRUE );

  return( FALSE );
}

