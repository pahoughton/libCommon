#ifndef _CommonVersion_h_
#define _CommonVersion_h_
/*********************************************************************
 *
 * Title:            CommonVersion.h
 *
 * Description:
 *
 *
 *
 * Notes:
 *
 * Programmer:	    Paul Houghton - (paul_houghton@wiltel.com)
 *
 * Start Date:	    10/28/95 10:29
 *
 * Modification History:
 *
 * $Log$
 * Revision 2.2  1995/10/29  13:33:41  houghton
 * Initial Linux Build of Version 2
 *
 * Revision 2.1  1995/10/28  19:18:18  houghton
 * New for version 2.0
 *
 * Revision 2.1  1995/10/28  17:26:21  houghton
 * Change to Version 2.1
 *
 * Revision 2.0  1995/10/28  16:54:43  houghton
 * Change to Version 2.0
 *
 * Revision 1.1  1995/10/28  16:51:36  houghton
 * Moving to 2.0
 * Change Directory Structure
 * Make compatible with libClue 2.0
 * Chage Version Identifiers
 * Linux Port
 *
 *
 *********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#define COMMON_PRJ_NAME	    "Common"
#define COMMON_PRJ_VER	    VERSION
#define COMMON_PRJ_VER_TAG  "BETA_2_0_0_2"

#define COMMON_VERSION( name_, verId_ )					      \
const char COMMONVER_##name_[] =						      \
"@(#) " COMMON_PRJ_NAME " - " COMMON_PRJ_VER "\n"			      \
"    " #name_ " - " __FILE__ " - Compiled: " __DATE__ " "__TIME__ "\n"	      \
"    " verId_





#ifdef __cplusplus
};
#endif

#endif /* ! def _CommonVersion_h_ */
