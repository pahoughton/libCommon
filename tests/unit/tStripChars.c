/* 2017-04-23 (cc) <paul4hough@gmail.com>
 */

#include "proto.h"

#include <Common/Common.h>
#include <Common/verify.h>
#include <string.h>

struct CTestVals
{
  const char * was;
  const char * exp;
} SpaceValues[] = {
  { "no white in me" 	       , "no white in me" },
  { "  leading"  	       , "leading" },
  { "trailing   "  	       , "trailing" },
  { "    both lead & trail    ", "both lead & trail" },
  { 0,0 }
};

struct STestVals {
  const char * wht;
  const char * was;
  const char * exp;
} WhiteValues[] = {
  { "-",     "---  special  ----", "  special  " },
  { "(-!,) ", "!,-()\nstuff  ",    "\nstuff" }
};

int
tStripChars( void )
{
  for( struct CTestVals * t = SpaceValues;
       t->was;
       t++ )
    {
      char was[ 128 ];

      strcpy( was, t->was );

      StripSpaces( was );
      /* printf("e:%s~\nv:%s~\n\n", t->exp, was ); */
      VVTRUE( strcmp( was, t->exp ) == 0 );
    }

  for( struct STestVals * t = WhiteValues;
       t->was;
       t++ )
    {
      char was[ 128 ];

      strcpy( was, t->was );

      StripChars( was, t->wht );
      /* printf("e:%s~\nv:%s~\n\n", t->exp, was ); */
      VVTRUE( strcmp( was, t->exp ) == 0 );
    }

  return( TRUE );
}
