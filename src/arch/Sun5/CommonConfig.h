#ifndef _CommonConfig_h_
#define _CommonConfig_h_
/*********************************************************************
 *
 * Title:       CommonConfig.h
 * Project:	Common
 * Desc:
 *
 *  libCommon configuratio for Sun5.
 *
 * Notes:
 *
 * Author:	Paul Houghton 719-527-7834 - (paul.houghton@wcom.com)
 * Created:	07/17/97 08:18
 *
 * Revision History: (See end of file for Revision Log)
 *
 *  Last Mod By:    $Author$
 *  Last Mod:	    $Date$
 *  Version:	    $Revision$
 *
 * $Id$
 *
 *********************************************************************/

#if !defined( COMMON_THREADS )
#define COMMON_TREADS	1
#endif

#if !defined( _POSIX_SOURCE )
#define _POSIX_SOURCE 1
#endif

#if !defined( _XOPEN_SOURCE )
#define _XOPEN_SOURCE 1
#endif

#if defined( COMMON_THREADS )
#define _MIT_POSIX_THREADS  1
#include <pthread.h>
#endif

#include <stddef.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <sys/types.h>

#if defined( __cplusplus )
extern "C" {
#endif

#define COMMON_PATH_MAX		_POSIX_PATH_MAX

#define COMMON_MAX_ERR_MESG	2048

#define COMMON_DIR_SEP_CHAR	'/'
#define COMMON_DIR_SEP_STRING	"/"
#define COMMON_PATH_ENV_VAR	"PATH"
#define COMMON_PATH_SEP		":"

#define COMMON_TEMPNAME_SIZE	8
#define COMMON_PID_FORMAT	"%05d"
#define COMMON_TEMP_DIR		P_tmpdir
    
#if !defined( TIMET_MAX )
#define TIMET_MAX   LONG_MAX
#define TIMET_MIN   LONG_MIN
#endif
  
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
#define COMMON_HAVE_MODE_T	1 /* */
#define COMMON_HAVE_STRPTIME	1 /* */  
  
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

#define COMMON_CHAR_8_T		char
#define COMMON_CHAR_S8_T	signed char
#define COMMON_CHAR_U8_T	unsigned char
#define COMMON_SHORT_S16_T	short
#define COMMON_SHORT_U16_T	unsigned short
#define COMMON_LONG_S32_T	long
#define COMMON_LONG_U32_T	unsigned long
  
#if defined(_BIG_ENDIAN)
  
#define COMMON_NET_HOST_CONVERTION  0
  
#define COMMON_n2hs( s ) s
#define COMMON_n2hl( l ) l
#define COMMON_n2hi( i ) i

#else
#error check little endian
  /* LITTLE_ENDIAN (1234) */
  
#define COMMON_NET_HOST_CONVERTION  1
  
#define COMMON_n2hs( s ) \
    ((unsigned short)( ( (((unsigned short)(s)) & 0x00ff) << 8 ) | \
		       ( (((unsigned short)(s)) & 0xff00) >> 8 ) ) )
      
#define COMMON_n2hl( l ) \
    ((unsigned long int)((((unsigned long int)(l) & 0x000000ffU) << 24) | \
			 (((unsigned long int)(l) & 0x0000ff00U) <<  8) | \
			 (((unsigned long int)(l) & 0x00ff0000U) >>  8) | \
			 (((unsigned long int)(l) & 0xff000000U) >> 24)))

#define COMMON_n2hi( i ) COMMON_n2hl( i )

#endif



#if defined( __cplusplus )
}
#endif

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.2  1998/03/21 17:13:31  houghton
 * Removed ';' to eliminate compiler warning.
 *
 * Revision 2.1  1997/09/21 19:14:48  houghton
 * Changed to Version 2
 *
 * Revision 1.3  1997/09/21 12:18:03  houghton
 * Added portable types COMMON_*_T.
 *
 * Revision 1.2  1997/09/16 11:33:26  houghton
 * Added define COMMON_NET_HOST_CONVERTION.
 *
 * Revision 1.1  1997/07/18 18:47:37  houghton
 * Initial Version.
 *
 *
 */

#endif /* ! def _CommonConfig_h_ */
