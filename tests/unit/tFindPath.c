/* 2017-04-30 (cc) <paul4hough@gmail.com>
 */

#include "proto.h"

#include <Common/Common.h>
#include <Common/verify.h>

int
tFindPath(void)
{

  VVTRUE( FindPath("sed", NULL) );
  VVTRUE( FindPath("can_exec", ".:data") );
  return( TRUE );
}
