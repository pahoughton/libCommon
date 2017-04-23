/* 2017-04-23 (cc) <paul4hough@gmail.com>
 */

#include <missing/missing.h>
#include <missing/verify.h>

int
tmissing(void)
{
  BOOL ttrue = TRUE;
  VVTRUE( ttrue );
  VVTRUE( ON );
  VVTRUE( YES );
  VVTRUE( ! FALSE );
  VVTRUE( ! OFF );
  VVTRUE( ! NO );

  VVTRUE( Bit( 0 ) == 0x01 );
  VVTRUE( Bit( 1 ) == 0x02 );
  VVTRUE( Bit( 2 ) == 0x04 );
  VVTRUE( Bit( 3 ) == 0x08 );
  VVTRUE( Bit( 4 ) == 0x10 );
  VVTRUE( Bit( 5 ) == 0x20 );
  VVTRUE( Bit( 6 ) == 0x40 );
  VVTRUE( Bit( 7 ) == 0x80 );

#if !defined( LONG_BITS )
  #error "expect LONG_BITS DEFINED"
#endif

  VVTRUE( CHAR_TO_INT( '4' ) == 4 );
  VVTRUE( CHAR_TO_INT( 'e' ) == 14 );

  VVTRUE( ! IS_BASE_DIGIT( '!',10 ) );

  VVTRUE( ! IS_BASE_DIGIT( ' ',2 ) );
  VVTRUE( ! IS_BASE_DIGIT( 'a',2 ) );
  VVTRUE( IS_BASE_DIGIT( '0',2 ) );
  VVTRUE( IS_BASE_DIGIT( '1',2 ) );
  VVTRUE( ! IS_BASE_DIGIT( '2',2 ) );
  VVTRUE( IS_BASE_DIGIT( '0',8 ) );
  VVTRUE( IS_BASE_DIGIT( '7',8 ) );
  VVTRUE( ! IS_BASE_DIGIT( '8',8 ) );
  VVTRUE( IS_BASE_DIGIT( '9',10 ) );
  VVTRUE( ! IS_BASE_DIGIT( 'a',10 ) );
  VVTRUE( IS_BASE_DIGIT( '9',16 ) );
  VVTRUE( IS_BASE_DIGIT( 'f',16 ) );
  VVTRUE( ! IS_BASE_DIGIT( 'g',16 ) );


}
