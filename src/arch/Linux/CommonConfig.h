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
 * Revision 2.1  1995/10/28  19:19:12  houghton
 * New for Version 2.0
 *
 *
 *********************************************************************/

#if !defined( _POSIX_SOURCE )
#define _POSIX_SOURCE 1
#endif

#include <stddef.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif


#define COMMON_MAX_ERR_MESG	2048

#define COMMON_DIR_SEP_CHAR	'/'
#define COMMON_DIR_SEP_STRING	"/"
#define COMMON_PATH_ENV_VAR	"PATH"
#define COMMON_PATH_SEP		":"

#if !defined( min ) && !defined( __cplusplus )
#define min( _a_, _b_ ) ( ( (_a_) > (_b_) ) ? (_b_) : (_a_) )
#endif 

#if !defined( max ) && !defined( __cplusplus )
#define max( _a_, _b_ ) ( ( (_a_) < (_b_) ) ? (_b_) : (_a_) )
#endif 

  /* #define COMMON_HAVE_STRLWR	1  */
  /* #define COMMON_HAVE_STRUPR	1  */
  /* #define COMMON_HAVE_STRDUP	1  */
#define COMMON_HAVE_LOCKING	1 /* */
#define COMMON_HAVE_BASENAME	1 /* */
#define COMMON_HAVE_GROUPS	1 /* */
#define COMMON_HAVE_UMODE	1 /* */
  

#ifdef __cplusplus
};
#endif

#endif /* ! def _CommonConfig_h_ */
