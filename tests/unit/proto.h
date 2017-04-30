#ifndef _proto_h_
#define _proto_h_
/* 1998-09-16 (cc) paul4hough@gmail.com
 */


int tCommon( void );

int tstrptime( void );
int tCenterLine( void );
int tCanExecute( void );
int tMemberOfGroup( void );
int tFindPath( void );
int tStripChars( void );
int tStringTo( void );
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
extern "C" {
#endif

#if defined( __cplusplus )
};
#endif

#endif /* ! def _proto_h_ */
