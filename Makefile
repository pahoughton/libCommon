#
# Title:        Makefile
# Project:	Common
# Desc:
# 
#   
# 
# Notes:
# 
# Author:	Paul Houghton - (paul.houghton@wcom.com)
# Created:	11/12/95
#
# Revision History: (See end of file for Revision Log)
#
#   Last Mod By:    $Author$
#   Last Mod:	    $Date$
#   Version:	    $Revision$
#
#   $Id$
# 

show_commands	= false
check_install	= true
hide		= @

PROJECT		= libCommon-3

PRJ_TOPDIR	= .
CFG_DIR		= $(PRJ_TOPDIR)/src/config

INSTALL_INC_DIR = $(TOOL_DIR)/include/prod
INSTALL_LIB_DIR = $(TOOL_DIR)/lib/prod
INSTALL_MAN_DIR = $(TOOL_DIR)/man

make_cfg_ver	= 5.06
make_cfg_file	= $(TOOL_DIR)/include/Make/make.cfg.$(make_cfg_ver)

dejagnu		= $(TOOL_DIR)/share/dejagnu/lib/libSupport.exp

setup_exports	    = 				\
	INSTALL_INC_DIR=$(INSTALL_INC_DIR)	\
	INSTALL_LIB_DIR=$(INSTALL_LIB_DIR)	\
	INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)	\
	show_commands=$(show_commands)		\
	check_install=$(check_install)

exports			=			\
	show_commands=$(show_commands)		\
	check_install=$(check_install)

no_target: help

setup:
	$(MAKE) -f $(PROJECT)/support/Setup.Makefile $(setup_exports) setup
	$(TOOL_DIR)/bin/make -C $(PROJECT) realclean depend_all
	$(hide) echo 
	$(hide) echo "+ $(PROJECT) setup complete."
	$(hide) echo 

verify_setup:
	$(hide)								      \
	if [ ! -f $(CFG_DIR)/Setup.cfg ]				      \
	    && [ ! -f $(PROJECT)/$(CFG_DIR)/Setup.cfg ] ; then		      \
	  echo "+ Setup.cfg NOT FOUND!";				      \
	  echo " ";							      \
	  echo "    To install all the dependencies, please perform";	      \
	  echo "    the following:";					      \
	  echo " ";							      \
	  echo "      cd \$$TOOL_DIR/src/Build/Libs";			      \
	  echo "      make -f $(PROJECT)/Makefile setup";		      \
	  echo " ";							      \
	  echo "    Please see $(PROJECT)/docs/devel/Dependencies.txt";	      \
	  echo "    for details.";					      \
	  echo " ";							      \
	  exit 1;							      \
	fi


depend_all								      \
depend_debug								      \
depend_default								      \
debug									      \
default									      \
test									      \
shared									      \
all									      \
check									      \
clean									      \
realclean								      \
install_docs								      \
install_lib_all								      \
install_default								      \
install_debug								      \
install_shared								      \
install_test								      \
install									      \
install_all: verify_setup
	$(hide) $(TOOL_DIR)/bin/make -C $(PRJ_TOPDIR)/src $@ $(exports)
	$(hide) echo + $(PROJECT) $@ complete

help targets:
	$(hide) echo " + The following targets are available:"
	$(hide) echo 
	$(hide) echo "    setup"
	$(hide) echo 
	$(hide) echo "    depend_all"
	$(hide) echo "    depend_debug"
	$(hide) echo "    depend_default"
	$(hide) echo "    debug"
	$(hide) echo "    default"
	$(hide) echo "    test (testing version)"
	$(hide) echo "    shared"
	$(hide) echo "    all"
	$(hide) echo "    check (run tests)"
	$(hide) echo "    clean"
	$(hide) echo "    realclean"
	$(hide) echo "    install_docs"
	$(hide) echo "    install_lib_all"
	$(hide) echo "    install_default"
	$(hide) echo "    install_debug"
	$(hide) echo "    install"
	$(hide) echo "    install_all"
	$(hide) echo
	$(hide) echo " + Use the help_config target to see the available"
	$(hide) echo "   configuration overides."
	$(hide) echo

help_config:
	$(hide) if [ -f $(CFG_DIR)/Setup.cfg ] ; then			      \
	  $(MAKE) -f $(CFG_DIR)/Setup.cfg help_config ;			      \
	else								      \
	  if [ -f $(PROJECT)/$(CFG_DIR) ] ; then			      \
	    $(MAKE) -f $(PROJECT)/$(CFG_DIR)/Setup.cfg help_config ;	      \
	  else								      \
	    echo ;							      \
	    echo "+ The following configuration variables are available:" ;   \
	    echo ;							      \
	    echo "    INSTALL_INC_DIR=$(INSTALL_INC_DIR)" ;		      \
	    echo "    INSTALL_LIB_DIR=$(INSTALL_LIB_DIR)" ;		      \
	    echo "    INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)" ;		      \
	    echo "    show_commands=$(show_commands)" ;			      \
	    echo "    check_install=$(check_install)" ;			      \
	    echo ;							      \
	  fi ;								      \
	fi 






#
# $Log$
# Revision 3.7  1999/11/09 13:00:30  houghton
# Bug-Fix: had to many backslashes '\' in setup_exports and exports.
#
# Revision 3.6  1999/11/09 10:45:51  houghton
# Added install_lib_all target.
#
# Revision 3.5  1999/11/08 15:17:25  houghton
# Changed to use $(hide) instead of @.
#
# Revision 3.4  1999/11/08 15:13:02  houghton
# Change: reworked setup to create src/config/Setup.cfg.
# Added install_lib_all target.
#
# Revision 3.3  1999/11/04 17:23:14  houghton
# Added dejagnu support to setup.
#
# Revision 3.2  1999/10/29 21:41:27  houghton
# Complete rewite to support 'setup' target.
#
# Revision 3.1  1999/10/29 16:55:54  houghton
# Changed Version to 3
#
# Revision 2.6  1999/05/14 10:20:24  houghton
# Bug-Fix: was not exiting with error code.
#
# Revision 2.5  1998/10/23 11:40:52  houghton
# Changed to use MakeConfigs 5.06.
#
# Revision 2.4  1998/10/13 14:15:22  houghton
# Added install_beta target.
# Cleanup.
#
# Revision 2.3  1998/09/24 14:36:03  houghton
# Complete rework.
#
# Revision 2.2  1998/09/22 14:26:08  houghton
# Complete rework.
#
# Revision 2.1  1997/04/26 12:28:27  houghton
# Changed to Version 2.
#
# Revision 1.1  1995/11/12 17:42:02  houghton
# Initial Version.
#
#

# Local Variables:
# mode:makefile
# End:
#

