/* 2017-04-23 (cc) <paul4hough@gmail.com>
 */

#include "proto.h"

#include <Common/Common.h>
#include <Common/verify.h>
#include <string.h>

static struct CLTest {
  const char * inp;
  const char * exp;
} CenterLineTests[] =
  {
    /*            01234567890123456789 */
    { "a",       "         a" },
    { "ab",      "         ab" },
    { "a     b", "      a     b" },
    { 0,0}
  };

static const char * CLValues[] =
  {
    "a",
    "abcd",
    "a b c d",
    0
  };

int
tCenterLine(void) {

  for( const struct CLTest * t = CenterLineTests;
       t->inp;
       ++ t ) {
    char val[24];
    CenterLine( val, t->inp, 20);
    /* printf("e:%s~\nv:%s~\n\n", t->exp, val );
     */
    VVTRUE( strcmp( val, t->exp ) == 0 );
  }

  for( const char ** inval = CLValues; *inval; ++ inval ) {
    char val[4096];
    unsigned int width = 40;
    unsigned int ilen  = strlen( *inval );
    unsigned int elen  = ((width - ilen)/2)+ilen;

    CenterLine( val, *inval, width);
    VVTRUE( strlen( val ) == elen );
  }
  return( TRUE );
}
