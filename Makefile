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

PROJECT		= libCommon-3

PRJ_TOPDIR	= .
CFG_DIR		= $(PRJ_TOPDIR)/src/config

INSTALL_INC_DIR = $(TOOL_DIR)/include/prod
INSTALL_LIB_DIR = $(TOOL_DIR)/lib/prod
INSTALL_BIN_DIR	= $(TOOL_DIR)/bin
INSTALL_MAN_DIR = $(TOOL_DIR)/man

make_cfg_ver	= 5.06
make_cfg_file	= $(TOOL_DIR)/include/Make/make.cfg.$(make_cfg_ver)

exports	    = 					\
	INSTALL_BIN_DIR=$(INSTALL_BIN_DIR)	\
	INSTALL_INC_DIR=$(INSTALL_INC_DIR)	\
	INSTALL_LIB_DIR=$(INSTALL_LIB_DIR)	\
	INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)	\
	show_commands=$(show_commands)		\
	check_install=$(check_install)		\

no_target: help

setup:
	$(MAKE) -f $(PROJECT)/support/Setup.Makefile setup

verify_setup:
	@ if [ -z "$$TOOL_DIR" ] ; then					      \
	  echo "TOOL_DIR env var not set.";				      \
	  echo "  Please see $(PROJECT)/docs/devel/Dependencies.txt";	      \
	  echo "  for details.";					      \
	  exit 1;							      \
	fi
	@ if [ ! -f "$(make_cfg_file)" ] ; then				      \
	  echo "MakeConfigs $(make_cfg_ver) not properly installed";	      \
	  echo "  run make -f $(PROJECT)/Makefile setup from the";	      \
	  echo "  \$TOOL_DIR/src/Build/Libs directory.";		      \
	  echo "  Please see $(PROJECT)/docs/devel/Dependencies.txt";	      \
	  echo "  for details.";					      \
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
install_default								      \
install_debug								      \
install									      \
install_all: verify_setup
	@ $(TOOL_DIR)/bin/make -C $(PRJ_TOPDIR)/src $@ $(exports)
	@ echo + $(PROJECT) $@ complete

help targets:
	@ echo " + The following targets are available:"
	@ echo 
	@ echo "    setup"
	@ echo 
	@ echo "    depend_all"
	@ echo "    depend_debug"
	@ echo "    depend_default"
	@ echo "    debug"
	@ echo "    default"
	@ echo "    test (testing version)"
	@ echo "    shared"
	@ echo "    all"
	@ echo "    check (run tests)"
	@ echo "    clean"
	@ echo "    realclean"
	@ echo "    install_docs"
	@ echo "    install_default"
	@ echo "    install_debug"
	@ echo "    install"
	@ echo "    install_all"
	@ echo
	@ echo " + Use the help_config target to see the available"
	@ echo "   configuration overides."
	@ echo

help_config:
	@ echo " + The following configuration variables are available:"
	@ echo
	@ echo "    INSTALL_BIN_DIR=$(INSTALL_BIN_DIR)"
	@ echo "    INSTALL_INC_DIR=$(INSTALL_INC_DIR)"
	@ echo "    INSTALL_LIB_DIR=$(INSTALL_LIB_DIR)"
	@ echo "    INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)"
	@ echo "    show_commands=$(show_commands)"
	@ echo "    check_install=$(check_install)"
	@ echo






#
# $Log$
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

