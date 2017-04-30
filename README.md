## libCommon

[![Test Build Status](https://travis-ci.org/pahoughton/libCommon.png)](https://travis-ci.org/pahoughton/libCommon)

common c defines, types, macros & functions.

state: testing wip

## Install

```
autoreconf
./configure
make test
```

## Usage

Common(3)                  Library Functions Manual                  Common(3)

NAME
       Common - Common C Function Library

DESCRIPTION
       libCommon  is a collection of generic C functions that should be useful
       for most projects. It is available for Aix 3.2, Aix  4.1,  Linux,  Sun,
       HPUX, Sequent, Vax & MS-Win.

MISC DATA TYPES, CONSTANTS & GLOBALS
       COMMON_LIB_VERSION
              macro with the hex encoded library version number.

       CommonLibVersion
              const  long  of  the hex encoded library version number that was
              compiled.

       CommonVersion
              a string containing the library version info.

       BOOL   macro defined as int.

       TRUE   macro defined as 1.

       FALSE  macro defined as 0.

       YES    macro defined as 1.

       NO     macro defined as 0.

       ON     macro defined as 1.

       OFF    macro defined as 0.

ERROR DATA TYPES, CONSTTANTS & GLOBALS
       Ret_Status
              enum used for return status. Values are  RET_SUCCEED,  RET_DONE,
              RET_DATA, RET_ERROR, RET_FATAL

       CommonErrorType
              enum used to define the type of an error. Values are:

              ET_NONE
                     not set.

              ET_APP application error.

              ET_OSERROR
                     operating system error.

              ET_COMMON
                     libCommon error value (see CommonError).

              ET_WCF libWcf error value. See Wcf(3).

              ET_SYBERR
                     Sybase error.

              ET_SYBMSG
                     Sybase message.

              ET_SYBOC
                     libSyboc error. See Syboc(3).

       CommonError
              enum used for libCommon error codes. Values are:

              EC_NONE
                     No Error.

              EC_BADPARAM
                     invalid parameter passed

              EC_RANGE
                     Value out of range.

       CommonErrno
              CommonError value of the last libCommon error.

       CommonErrorDesc
              a string description of the last libCommon error.

       CommonErrorFile
              char  string  containing  the  name of the source file where the
              last error occurred.

       CommonErrorLine
              int line number of source file where the last error occurred.

       CommonErrorHandler
              type for the error handler used by SetErrorHandler(3) and GetEr‐
              rorHandler(3).

LOGGER DATA TYPES, CONSTTANTS & GLOBALS
       LogLogBit
              enum of log entry types.

       LogSetLevelType
              enum used to specify how to set the output log levels.

       LogOutFileType
              enum to specify the type of log file to create.

       LoggerFunct
              type  for  the logger function used by LoggerInit(3), LoggerSet‐
              Funct(3) and LoggerGetFunct(3).

TIME DATA TYPES, CONSTANTS & GLOBALS
       SEC_PER_MIN
              macro defined as the number of seconds in a minute.

       SEC_PER_HOUR
              macro defined as the number of seconds in a hour.

       SEC_PER_DAY
              macro defined as the number of seconds in a day.

       SEC_PER_YEAR
              macro defined as the number of seconds in a (non-leap) year.

       MIN_PER_HOUR
              macro defined as the number of minues in an hour.

       DayOfWeek
              enum of the days of the week; Sunday=0, Monday, Tuesday, Wednes‐
              day, Thursday, Friday, Saturday.

       DaysInMonth
              int array with number of days in each month (Jan=0).

       MonthDayOfYear
              int array  with the day of year for the first of every month.

       Months string array with names of the month (Jan=0).

       AbbrMonths
              string array with month abbreviations (Jan=0).

       WeekDays
              string array with names of the days of the week (Sun=0).

       AbbrWeekDays
              string array with day of week abbreviations (Sun=0).

BIT MANIPULATION DATA TYPES, CONSTANTS & GLOBALS
       CHAR_BITS
              the number of bits in a char.

       SHORT_BITS
              the number of bits in a short.

       LONG_BITS
              then number of bits in a long.

       INT_BITS
              the number of bits in an int.

       CHAR_ALL_BITS
              a char with all its bits turned on.

       SHORT_ALL_BITS
              a short with all its bits turned on.

       LONG_ALL_BITS
              a long with all its bits turned on.

       INT_ALL_BITS
              an it with all its bits turned on.

AVL TREE DATA TYPES, CONSTANTS & GLOBALS
       AvlTree
              typedef used to declare AVL tree identifiers.

       AvlVisit
              typedef definition of traversal type.

       AvlSiblingOrder
              typedef definition of sibling order type.

       AvlNodeType
              typedef definition of node type.

ERROR FUNCTIONS
       SetErrorHandler(3)
              specify  the  function  to call when an error occurs and/or when
              Error(3) is called.

       GetErrorHandler(3)
              get the current error handler and closure.

       Error(3)
              call the error handler using a printf like format  string.  (the
              default error handler outputs a log entry).

       ErrorArgs(3)
              call the error handler with stdarg like args. (the default error
              handler outputs a log entry).

       SetError(3)
              function to specify an error has occured.

       ErrorMesg(3)
              call the error handler with the values established using  SetEr‐
              ror(3).

       ErrorTypeString(3)
              translate a CommonErrorType value to a string.

       CommonErrorString(3)
              translate a CommonError value to a string.

       SET_ERROR_CLOSURE(3)
              macro to specifiy a library error has occured.

       SET_ERROR(3)
              macro to specify a library error has occurred.

       SET_APP_ERROR(3)
              macro to specify an application error has occurred.

       ERROR(3)
              macro to call SetError and ErrorMesg with default parameters.

       ERROR_APP(3)
              macro to call SetError and ErrorMesg with default parameters.

ARG / ENV FUNCTIONS
       ArgEnvBool(3)
              translate  command  line  argument  or environment variable to a
              boolean value.

       ArgEnvDouble(3)
              translate command line argument or  environment  variable  to  a
              double.

       ArgEnvFlag(3)
              translate  command  line  argeuemnt or environment variable to a
              flag.

       ArgEnvInt(3)
              translate command line argument or environment  variable  to  an
              integer value.

       ArgEnvLong(3)
              translate  command  line  argument  or environment variable to a
              long.

       ArgEnvString(3)
              translate command line argument or  environment  variable  to  a
              char string.

LOGGING FUNCTIONS
       LogLevelSetString(3)
              the string for a specific LogLevelBit.

       LogLevelFromString(3)
              converts a string to a LogLevelBit.

       LogLevelString(3)
              convert a log level into a string.

       LoggerInit(3)
              initialize the logger.

       LoggerSetLogFile(3)
              set the file that log entries will be written to.

       LoggerSetOutputLevel(3)
              set the type of log entries that should be output.

       LoggerSetDate(3)
              turn on/off prefixing the date and time of log entries.

       LoggerSetLoc(3)
              turn on/off including the source file and line in log entries.

       LoggerSetTee(3)
              turn on/off tee'ing log entries to stderr.

       LoggerSetFunct(3)
              specify the function to use to process log entries.

       LoggerGetFunct(3)
              retrieve the function used to process log entries.

       LoggerLevel(3)
              set the level for the next log entry.

       LoggerLoc(3)
              set the source file and line number for the next log entry.

       Logger(3)
              create a log entry.

       LoggerArgs(3)
              creates a log entry using the args passed.

       LoggerTrim(3)
              trim the log file.

       LOGITLOC(3)
              create a log entry using file, line, level and logArgs.

       LOGIT(3)
              create a log entry.

       LOGFUNCT(3)
              create a LOG_FUNCT entry.

       LOGERROR(3)
              create a LOG_ERROR level log entry.

STRING FUNCTIONS
       CHAR_TO_INT(3)
              translate a single char to an integer value.

       IS_BASE_DIGIT(3)
              true  or  false,  is a char value a valid digit of the specified
              base.

       SAFE_STRCPY(3)
              copy a string into dest for 'size' bytes and null terminate it.

       A2E(3) convert an ASCII character to its EBCDIC equivalent.

       E2A(3) convert an EBCDIC character to its ASCII equivalent.

       StringToInt(3)
              convert a string to an integer.

       StringToUInt(3)
              convert a string to an unsigned integer.

       StringToShort(3)
              convert a string to a short.

       StringToUShort(3)
              convert a string to an unsigned short.

       StringToLong(3)
              convert a string to a long.

       StringToULong(3)
              convert a string to an unsigned long.

       StringToDouble(3)
              convert a string to a double.

       CenterLine(3)
              prefix a string buffer with spaces to center it on a line.

       StripSpaces(3)
              remove leading and trailing spaces from a string.

       AsciiToEbcdic(3)
              convert all characters in an ASCII char buffer to EBCDIC.

       EbcdicToAscii(3)
              convert all characters in an EBCDIC char buffer to ASCII.

       strlwr(3)
              convert a string to lower case.

       strupr(3)
              convert a string to upper case.

       strdup(3)
              duplicate a string into a malloc'ed space.

       basename(3)
              return a pointer to the filename portion of a pathname.

DATE/TIME FUNCTIONS
       IsLeapYear(3)
              true or false, is the specified year a leap year.

       Difftm(3)
              return the difference of two tm structs in seconds

       YYYYMMDDtoTimeT(3)
              convert a YYMMDD string to time_t.

       YYMMDDtoTimeT(3)
              convert a YYMMDD string to time_t.

       HHMMSStoTimeT(3)
              convert a HHMMSS string to time_t.

       DateStringToTimeT(3)
              convert date/time string to time_t.

       DateStringFromTimeT(3)
              convert a time_t value to a string.

       DateStringFromTm(3)
              convert a tm struct to a string.

       YearMonthDayToTimeT(3)
              convert a year, month and day to a time_t value.

       HourMinSecToTimeT(3)
              convert an hour, minute and second to a time_t value.

       strptime(3)
              convert a date time string to a tm struct.

BIT MANIPULATION FUNCTIONS
       Bit(3) return an int with a specific bit set.

       Host2NetShort(3)
              return a short converted to network byte order.

       Net2HostShort(3)
              return a short converted from network to host byte order.

       Host2NetUShort(3)
              return a unsigned short converted to network byte order.

       Net2HostUShort(3)
              return a unsigned short converted  from  network  to  host  byte
              order.

       Host2NetInt(3)
              return a int converted to network byte order.

       Net2HostInt(3)
              return a int converted from network to host byte order.

       Host2NetUInt(3)
              return a unsigned int converted to network byte order.

       Net2HostUInt(3)
              return a unsigned int converted from network to host byte order.

       Host2NetLong(3)
              return a long converted to network byte order.

       Net2HostLong(3)
              return a long converted from network to host byte order.

       Host2NetULong(3)
              return a unsigned long converted to network byte order.

       Net2HostULong(3)
              return  a  unsgined  long  converted  from  network to host byte
              order.

AVL BINARY TREE FUNCTIONS
       AvlInit(3)
              initialize an AVL (balanced binary) tree.

       AvlAttach(3)
              attach to an existing AVL tree.

       AvlGetRoot(3)
              return the root pointer of an AVL tree.

       AvlAdd(3)
              add a new record (node) to an AVL tree.

       AvlDel(3)
              delete a record from an AVL tree.

       AvlFind(3)
              find a record in an AVL tree.

       AvlCount(3)
              return the number of records in an AVL tree.

       AvlDispose(3)
              destroy an AVL tree.

       AvlWalk(3)
              execute a specified function for each record of an AVL tree.

       AvlDelMin(3)
              delete the first (smallest) record of an AVL tree.

       AvlFindMin(3)
              find the first record of an AVL tree.

       AvlDelMax(3)
              delete the last record of an AVL tree.

       AvlFindMax(3)
              find the last record of an AVL tree.

MISC FUNCTIONS
       TempFileName(3)
              create a unique file name.

       ForeachFile(3)
              execute a function for each file in a directory.

       CanExecute(3)
              can a specific file be executed.

       FindPath(3)
              search for a file in using a path and return the full file name.

       MemberOfGroup(3)
              is the current user a member of the specified group.

       FileModeString(3)
              return a string representation of the mode passed.

       DWORD_ALIGN(3)
              return a value aligned to a dword (4 byte) value.

       CommonGetVersion(3)
              return the  version  string  to  identify  the  version  of  the
              library.

FILES
       $prefix/lib/libCommon.so
       $prefix/include/Common/Common.h




## Contribute

[Github pahoughton/libCommon](https://github.com/pahoughton/libCommon)

## Licenses
Avl - Brad Appleton <brad@ssd.csd.Harris.COM>
1991-10-09 (cc) <paul4hough@gmail.com>

[![LICENSE](http://i.creativecommons.org/l/by/3.0/88x31.png)](http://creativecommons.org/licenses/by/3.0/)

[![endorse](https://api.coderwall.com/pahoughton/endorsecount.png)](https://coderwall.com/pahoughton)
