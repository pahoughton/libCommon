#ifndef _Bit_h_
#define _Bit_h_
/*********************************************************************
 *
 * Title:            Bit.h
 *
 * Description:
 *
 *
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton x2309 - (houghton@shoe.wiltel.com)
 *
 * Start Date:	    01/28/95 18:09
 *
 * Modification History:
 *
 * $Log$
 * Revision 1.2  1995/03/02  16:39:54  houghton
 * minor mods
 *
 * Revision 1.1  1995/02/13  15:34:12  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/

#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

#define Bit( _b_ ) ( 1 << _b_ )

#define CHAR_BITS   CHAR_BIT
#define SHORT_BITS  (sizeof(short) * CHAR_BITS)
#define INT_BITS    (sizeof(int) * CHAR_BITS)
#define LONG_BITS   (sizeof(long) * CHAR_BITS)

#define CHAR_ALL_BITS	0xff
#define SHORT_ALL_BITS	0xffff
#define LONG_ALL_BITS	0xffffffff
#define INT_ALL_BITS	(( sizeof(int) == sizeof(long)) ? LONG_ALL_BITS : SHORT_ALL_BITS )



#ifdef __cplusplus
};
#endif

#endif /* ! def _Bit_h_ */
/**
 *             This software is the sole property of
 *
 *                 The Williams Companies, Inc.
 *                       1 Williams Center
 *                         P.O. Box 2400
 *                      Tulsa, Oklahoma 74102
 *
 *        Copyright (c) 1994 by The Williams Companies, Inc.
 *
 *                      All Rights Reserved.  
 *
 **/
