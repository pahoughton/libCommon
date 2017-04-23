#ifndef _TestFunctProto_h_
#define _TestFunctProto_h_
/* 1998-09-16 (cc) paul4hough@gmail.com
 */

#if defined( __cplusplus )
extern "C" {
#endif

int tmissing( void );
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

#endif /* ! def _TestFunctProto_h_ */
