#ifndef _CommonConfig_h_
#define _CommonConfig_h_
/*********************************************************************
 *
 * Title:            CommonConfig.h
 *
 * Description:
 *
 *
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    10/28/95 12:14
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1995/10/29  13:33:55  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/28  19:19:12  houghton
 * New for Version 2.0
 *
 *
 *********************************************************************/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif


#define COMMON_MAX_ERR_MESG	2048

#define COMMON_DIR_SEP_CHAR	'\\'
#define COMMON_DIR_SEP_STRING	"\\"
#define COMMON_PATH_ENV_VAR	"PATH"
#define COMMON_PATH_SEP		":"


/* #define COMMON_HAVE_STRLWR	1 /* */
/* #define COMMON_HAVE_STRUPR	1 /* */
/* #define COMMON_HAVE_STRDUP	1 /* */
#define COMMON_HAVE_LOCKING	1 /* */
#define COMMON_HAVE_BASENAME	1 /* */
/* #define COMMON_HAVE_GROUPS	1 /* */
#define COMMON_HAVE_MODE_T	1 /* */
/* #define COMMON_HAVE_STRPTIME	1 /* */

typedef short mode_t;

#if !defined( S_ISREG )
#define S_ISREG( _mode ) ( _mode & S_IFREG )
#endif

#if !defined( S_ISLNK )
#define S_ISLNK( _mode ) (0)
#endif

#if !defined( S_ISDIR )
#define S_ISDIR( _mode ) (S_IFDIR & _mode)
#endif

#if !defined( S_ISCHR )
#define S_ISCHR( _mode ) (S_IFCHR & _mode)
#endif

#if !defined( S_ISBLK )
#define S_ISBLK( _mode ) (S_IFBLK & _mode)
#endif

#if !defined( S_ISFIFO )
#define S_ISFIFO( _mode ) (S_IFIFO & _mode)
#endif

#if !defined( S_ISSOCK )
#define S_ISSOCK( _mode ) (0)
#endif


#ifdef __cplusplus
};
#endif

#endif /* ! def _CommonConfig_h_ */
