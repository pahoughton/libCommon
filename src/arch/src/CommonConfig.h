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
 *
 *********************************************************************/

#include <stddef.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

#define COMMON_DIR_SEP_CHAR	'/'
#define COMMON_DIR_SEP_STRING	"/"
#define COMMON_PATH_ENV_VAR	"PATH"
#define COMMON_PATH_SEP		":"


#if !defined( Linux )
const char * basename( const char * path );
#endif

char * strlwr( char * str );
char * strupr( char * str );
#if defined( NeXT )
char * strdup( const char *);
#endif

/************************************************************/
/* AvlTree Locking Mechanisms */
/************************************************************/
  
int    AvlLockTree( AvlTree tree, int semId );
int    AvlUnlockTree( AvlTree tree, int semId  );
int    AvlWaitForUnlock( AvlTree tree, int semId  );
int    AvlGetNumberOfUsers( AvlTree tree );
int    InitLocking(
    	    	const char * fileName ,
		int 	     accessFlag,
    	        const char  keyID );


#ifdef _POSIX_SOURCE
Bool MemberOfGroup( gid_t grp );
#endif

#ifndef min
#define min( _a_, _b_ ) ( ( (_a_) > (_b_) ) ? (_b_) : (_a_) )
#endif 

#ifndef max
#define max( _a_, _b_ ) ( ( (_a_) < (_b_) ) ? (_b_) : (_a_) )
#endif 


#ifdef __cplusplus
};
#endif

#endif /* ! def _CommonConfig_h_ */
