#ifndef _CommonConfig_h_
#define _CommonConfig_h_
/*********************************************************************
 *
 * Title:       CommonConfig.h
 * Project:	Common
 * Desc:
 *
 *  libCommon configuration header for Linux
 *
 * Notes:
 *
 * Author:	Paul Houghton - (paul.houghton@wcom.com)
 * Created:	10/28/95 12:14
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

#include <sys/types.h>

#ifdef __cplusplus
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
#define COMMON_TEMP_DIR		_PATH_TMP
    
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

#define COMMON_NET_HOST_CONVERTION  1
  
#define COMMON_CHAR_8_T		char
#define COMMON_CHAR_S8_T	signed char
#define COMMON_CHAR_U8_T	unsigned char
#define COMMON_SHORT_S16_T	short
#define COMMON_SHORT_U16_T	unsigned short
#define COMMON_LONG_S32_T	long
#define COMMON_LONG_U32_T	unsigned long

  /* LITTLE_ENDIAN (1234) */
#define COMMON_n2hs( s ) \
    ((unsigned short)( ( (((unsigned short)(s)) & 0x00ff) << 8 ) | \
		       ( (((unsigned short)(s)) & 0xff00) >> 8 ) ) )
      
#define COMMON_n2hl( l ) \
    ((unsigned long int)((((unsigned long int)(l) & 0x000000ffU) << 24) | \
			 (((unsigned long int)(l) & 0x0000ff00U) <<  8) | \
			 (((unsigned long int)(l) & 0x00ff0000U) >>  8) | \
			 (((unsigned long int)(l) & 0xff000000U) >> 24)))

#define COMMON_n2hi( i ) COMMON_n2hl( i )
      
#ifdef __cplusplus
};
#endif

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.10  1997/09/21 12:17:44  houghton
 * Cleanup comment header.
 * Added portable types COMMON_*_T.
 *
 * Revision 2.9  1997/09/16 11:33:18  houghton
 * Added define COMMON_NET_HOST_CONVERTION.
 *
 * Revision 2.8  1997/03/02 12:13:47  houghton
 * Added support for turning threads on or off.
 *
 * Revision 2.7  1996/03/08 16:28:17  houghton
 * Bug Fix: n2hs parens missing
 *
 * Revision 2.6  1996/02/29 16:22:04  houghton
 * Fixed net to host converters
 *
 * Revision 2.5  1995/12/02 02:11:04  houghton
 * *** empty log message ***
 *
 * Revision 2.4  1995/11/10  01:04:30  houghton
 * Added configuration defines for File names a sizes
 *
 * Revision 2.3  1995/10/30  14:55:22  houghton
 * Add Net2Host
 *
 * Revision 2.2  1995/10/29  18:16:15  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.1  1995/10/29  13:31:20  houghton
 * Change version to 2.0
 *
 * Revision 1.1  1995/10/29  13:30:49  houghton
 * Linux Config File
 *
 * Revision 2.1  1995/10/28  19:19:12  houghton
 * New for Version 2.0
 *
 */

#endif /* ! def _CommonConfig_h_ */
