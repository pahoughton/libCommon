/* 2017-04-30 (cc) <paul4hough@gmail.com>
 */

#include "proto.h"

#include <Common/Common.h>
#include <Common/verify.h>

int
tMemberOfGroup(void)
{
  VVTRUE( MemberOfGroup(getgid()) );
}
