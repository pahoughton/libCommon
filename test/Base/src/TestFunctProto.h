#ifndef _TestFunctProto_h_
#define _TestFunctProto_h_
/*********************************************************************
 *
 * Title:       TestFunctProto.h
 * Project:	Common
 * Desc:
 *
 *  
 *
 * Notes:
 *
 * Author:	Paul A. Houghton - (paul.houghton@wcom.com)
 * Created:	09/16/98 10:21
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

#if defined( __cplusplus )
extern "C" {
#endif

int tstrptime( void );
int tIsLeapYear( void );
int tYearMonthDayToTimeT( void );
int tHourMinSecToTimeT( void );
int tYYYYMMDDtoTimeT( void );
int tYYMMDDtoTimeT( void );
int tHHMMSStoTimeT( void );
int tDateStringToTimeT( void );
int tDateStringFromTm( void );
int tDateStringFromTimeT( void );

#if defined( __cplusplus )
};
#endif

/*
 *
 * Revision Log:
 *
 * $Log$
 * Revision 1.1  1998/09/22 14:39:41  houghton
 * Initial version.
 *
 *
 */

#endif /* ! def _TestFunctProto_h_ */
