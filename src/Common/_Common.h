#ifndef __Common_h_
#define __Common_h_
/*********************************************************************
 *
 * Title:       _Common.h
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	01/29/94 21:06
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

#include "Common.h"
#include <stdio.h>

#if defined( __cplusplus )
extern "C" {
#endif

#define COMMON_PRJ_NAME	    "Common"
#define COMMON_PRJ_VER_TAG  "PROD_2_02"
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


#if !defined( CPROTO )
#if !defined( COMMON_SHORT_FN )
#include "_Common_Proto.h"
#else
#include "Cmmnprot.h"
#endif
#endif
    
#if defined( __cplusplus )
};
#endif

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 2.9  1997/05/07 11:40:04  houghton
 * Bug-Fix: Added missing endif.
 *
 * Revision 2.8  1997/05/07 11:36:58  houghton
 * Cleanup
 *
 * Revision 2.7  1997/04/26 16:25:21  houghton
 * Added COMMON_PRJ_VER_TAG to COMMON_VERSION macro.
 *
 * Revision 2.6  1997/04/26 12:45:03  houghton
 * Changed ver tag.
 *
 * Revision 2.5  1997/03/02 12:28:44  houghton
 * Changed version info.
 *
 * Revision 2.4  1996/04/27 12:27:05  houghton
 * Changed to use new CPROTO macro for proto generation.
 *
 * Revision 2.3  1995/11/10 01:03:31  houghton
 * Change to use new Error processing functions.
 *
 * Revision 2.2  1995/10/31  12:38:31  houghton
 * Move version info from CommonVersion.h to _Common.h
 * Use MakeConfigs 3.3
 * Update ErrorStrings for all CommonErrorType values
 *
 * Revision 2.1  1995/10/29  12:01:28  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:37  houghton
 * Move to Version 2.0
 *
 * Revision 1.6  1995/02/13  15:34:23  houghton
 * New functions and many enhancements to existing functions.
 *
 * Revision 1.5  1994/07/13  14:54:06  houghton
 * Sequent port
 *
 * Revision 1.4  1994/06/22  16:34:55  dpotluri
 * Port to MSWindows and OPENVMS
 *
 * Revision 1.3  1994/06/06  13:23:38  houghton
 * Avl and DateTime functions added for Rating
 *
 * Revision 1.2  1994/01/31  14:06:16  houghton
 * Add avl and some other minor functions
 *
 */

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
#endif /* ! def __Common_h_ */
