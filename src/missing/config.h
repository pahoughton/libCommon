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
 * Revision 2.4  1995/10/30 14:55:27  houghton
 * Add Net2Host
 *
 * Revision 2.3  1995/10/29  18:16:24  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.2  1995/10/29  13:33:55  houghton
 * Initial Linux Build of Version 2
 *
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
#include <limits.h>

#include <grp.h>

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

#define COMMON_HAVE_STRLWR	1 /* */
#define COMMON_HAVE_STRUPR	1 /* */
#define COMMON_HAVE_STRDUP	1 /* */
#define COMMON_HAVE_LOCKING	1 /* */
#define COMMON_HAVE_BASENAME	1 /* */
#define COMMON_HAVE_GROUPS	1 /* */
#define COMMON_HAVE_MODE_T	1 /* */
#define COMMON_HAVE_STRPTIME	1 /* */  

/**************************************************************
 * Bit manipulations
 **************************************************************/

#if !defined( CHAR_ALL_BITS )

#define Bit( _b_ ) ( 1 << _b_ )

#define CHAR_BITS   CHAR_BIT
#define SHORT_BITS  ( sizeof(short) * CHAR_BITS )
#define LONG_BITS   ( sizeof(long) * CHAR_BITS )
#define INT_BITS    ( sizeof(int) * CHAR_BITS )

#define CHAR_ALL_BITS	((unsigned char)(~0))  /* 0xff */
#define SHORT_ALL_BITS	((unsigned short)(~0)) /* 0xffff */
#define LONG_ALL_BITS	((unsigned long)(~0L)) /* 0xffffffff */
#define INT_ALL_BITS	((unsigned int)(~0))   /* 0xffff | 0xffffffff */

#endif
  
  /* LITTLE_ENDIAN (1234) */
#define COMMON_n2hs( s ) ( (s << 8) | (s >> 8) )

#define COMMON_n2hl( l ) \
  ( ( l << 24 ) | ( (l & 0xff00) << 8 ) |  \
    (( l & 0xff0000L) >> 8 ) | ( l >> 24 ) )
    
#ifdef __cplusplus
};
#endif

#endif /* ! def _CommonConfig_h_ */