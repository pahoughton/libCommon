/* 1995-10-28 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#ifndef _CommonConfig_h_
#define _CommonConfig_h_

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
#define COMMON_n2hs( s ) \
    ((unsigned short)( ( (((unsigned short)(s)) & 0x00ff) << 8 ) | \
		       ( (((unsigned short)(s)) & 0xff00) >> 8 ) ) )

#define COMMON_n2hl( l ) \
    ((unsigned long int)((((unsigned long int)(l) & 0x000000ffU) << 24) | \
			 (((unsigned long int)(l) & 0x0000ff00U) <<  8) | \
			 (((unsigned long int)(l) & 0x00ff0000U) >>  8) | \
			 (((unsigned long int)(l) & 0xff000000U) >> 24)))

#define COMMON_n2hi( i ) ((int)COMMON_n2hl( i ))

#ifdef __cplusplus
};
#endif

#endif /* ! def _CommonConfig_h_ */
