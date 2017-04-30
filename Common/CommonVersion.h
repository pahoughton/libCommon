#ifndef _CommonVersion_h_
#define _CommonVersion_h_
/* 1995-10-28 (cc) Paul Houghton <paul4hough@gmail.com>
 */

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
