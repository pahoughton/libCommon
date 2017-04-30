/* 2017-04-23 (cc) <paul4hough@gmail.com>
 */

#include <Common/Common.h>
#include <Common/verify.h>
#include <memory.h>

int
tCommon(void)
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

  {
    char estr[8];
    estr[0] = 0x81;
    estr[1] = 0x82;
    estr[2] = 0x83;
    EbcdicToAscii( estr, 3 );
    VVTRUE( memcmp( estr, "abc", 3 ) == 0 );
  }
  return( TRUE );
}
