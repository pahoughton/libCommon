/*********************************************************************
 *
 * Title:            EbcdicToAscii.c
 *
 * Description:
 *
 *	
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (houghton@cworld.wiltel.com)
 *
 * Start Date:	    10/05/94 11:34
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.3  1997/07/18 18:44:44  houghton
 * Port(Sun5): Changed EtoA to unsigned char.
 *
 * Revision 2.2  1995/10/29 18:16:00  houghton
 * Fixes for Borland 4.0 Port
 *
 * Revision 2.1  1995/10/28  19:11:44  houghton
 * Change Version Id String
 *
 * Revision 2.0  1995/10/28  17:35:21  houghton
 * Move to Version 2.0
 *
 * Revision 1.1  1995/02/13  15:34:16  houghton
 * New functions and many enhancements to existing functions.
 *
 *
 *********************************************************************/

#include "_Common.h"

COMMON_VERSION(
  EbcdicToAscii,
  "$Id$");


const unsigned char EtoA[] =
{
  020, 01, 02, 03, 0234, 011, 0206, 0177,
  0227, 0215, 0216, 013, 014, 015, 016, 017,
  020, 021, 022, 023, 0235, 0205, 010, 0207,
  030, 031, 0222, 0217, 034, 035, 036, 037,
  0200, 0201, 0202, 0203, 0204, 012, 027, 033,
  0210, 0211, 0212, 0213, 0214, 05, 06, 07,
  0220, 0221, 026, 0223, 0224, 0225, 0226, 04,
  0230, 0231, 0232, 0233, 024, 025, 0236, 032,
  040, 0240, 0241, 0242, 0243, 0244, 0245, 0246,
  0247, 0250, 0133, 056, 074, 050, 053, 041,
  046, 0251, 0252, 0253, 0254, 0255, 0256, 0257,
  0260, 0261, 0135, 044, 052, 051, 073, 0136,
  055, 057, 0262, 0263, 0264, 0265, 0266, 0267,
  0270, 0271, 0174, 054, 045, 0137, 076, 077,
  0272, 0273, 0274, 0275, 0276, 0277, 0300, 0301,
  0302, 0140, 072, 043, 0100, 047, 075, 042,
  0303, 0141, 0142, 0143, 0144, 0145, 0146, 0147,
  0150, 0151, 0304, 0305, 0306, 0307, 0310, 0311,
  0312, 0152, 0153, 0154, 0155, 0156, 0157, 0160,
  0161, 0162, 0313, 0314, 0315, 0316, 0317, 0320,
  0321, 0176, 0163, 0164, 0165, 0166, 0167, 0170,
  0171, 0172, 0322, 0323, 0324, 0325, 0326, 0327,
  0330, 0331, 0332, 0333, 0334, 0335, 0336, 0337,
  0340, 0341, 0342, 0343, 0344, 0345, 0346, 0347,
  0173, 0101, 0102, 0103, 0104, 0105, 0106, 0107,
  0110, 0111, 0350, 0351, 0352, 0353, 0354, 0355,
  0175, 0112, 0113, 0114, 0115, 0116, 0117, 0120,
  0121, 0122, 0356, 0357, 0360, 0361, 0362, 0363,
  0134, 0237, 0123, 0124, 0125, 0126, 0127, 0130,
  0131, 0132, 0364, 0365, 0366, 0367, 0370, 0371,
  060, 061, 062, 063, 064, 065, 066, 067,
  070, 071, 0372, 0373, 0374, 0375, 0376, 0377
};

void
EbcdicToAscii( unsigned char * buf, int len )
{
  int	i;
  int	end;

  if( len == 0 )
    {
      end = strlen( (char *)buf );
    }
  else
    {
      end = len;
    }

  for( i = 0; i < end; i++, buf++ )
    {
      *buf = EtoA[*buf];
    }
}








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
