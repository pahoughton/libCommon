/* 2017-04-30 (cc) <paul4hough@gmail.com>
 */

#include "proto.h"

#include <Common/Common.h>
#include <Common/verify.h>

int
tCanExecute(void)
{
#if !defined(PROG_SED)
  #error "no sed"
#endif
  const char * sed = PROG_SED;

  VVTRUE( CanExecute(sed) );
}
