/* 1994-01-29 (cc) Paul Houghton <paul4hough@gmail.com>
 */
#ifndef __Common_h_
#define __Common_h_

#include "Common.h"
#include <stdio.h>

#if defined( __cplusplus )
extern "C" {
#endif

#define COMMON_PRJ_VER	    VERSION

#define COMMON_VERSION( name_, verId_ )					      \
const char COMMONVER_##name_[] =					      \
"@(#) " COMMON_PRJ_NAME " - " COMMON_PRJ_VER "\n"			      \
"    " #name_ " - " __FILE__ " - Compiled: " __DATE__ " "__TIME__ "\n"	      \
"    CVS Tag: " COMMON_PRJ_VER_TAG "\n"					      \
"    " verId_


#define COMMON_SET_TYPE_ERROR( type_, err_, args_ )			      \
{									      \
  SET_ERROR( type_, err_ );						      \
  _CommonErrorDesc args_;						      \
}


#define COMMON_SET_ERROR( err_, args_ ) \
  COMMON_SET_TYPE_ERROR( ET_COMMON, err_, args_ )


#define COMMON_RETURN_TYPE_ERROR( type_, err_, args_ )			      \
{									      \
  COMMON_SET_TYPE_ERROR( type_, err_, args_ );				      \
  return( RET_ERROR );							      \
}

#define COMMON_RETURN_ERROR( err_, args_ ) \
  COMMON_RETURN_TYPE_ERROR( ET_COMMON, err_, args_ )


#if defined( __cplusplus )
};
#endif

#endif /* ! def __Common_h_ */
