#
# -*- Makefile -*- for Common src dir
#
# Author: Paul Houghton
#
# Created: 11/12/95
#
# $Id$
#

make_cfg_ver	= 5.06
show_commands 	= # true

# Include standard MakeConfig configuration for GNU make required
include Make/make.cfg.$(make_cfg_ver)

INSTALL_BIN_DIR	= $(local_bindir)
INSTALL_INC_DIR = $(local_incdir)
INSTALL_LIB_DIR = $(local_libdir)
INSTALL_MAN_DIR = $(local_mandir)

exports	    = 					\
	INSTALL_BIN_DIR=$(INSTALL_BIN_DIR)	\
	INSTALL_INC_DIR=$(INSTALL_INC_DIR)	\
	INSTALL_LIB_DIR=$(INSTALL_LIB_DIR)	\
	INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)	\
	show_commands=$(show_commands)		\
	check_install=$(check_install)		\

depend depend_all depend_test depend_default depend_debug:
	$(hide) $(MAKE) -C Common $@ $(exports)

all default debug:
	$(hide) $(MAKE) -C Common $@ $(exports)

clean realclean:
	$(hide) $(MAKE) -C Common $@ $(exports)

test:
	$(hide) $(MAKE) -C Common $@ $(exports)


install_all install install_default install_debug:
	$(hide) $(MAKE) -C Common $@ $(exports)


#
# $Log$
# Revision 2.5  1999/05/14 10:20:45  houghton
# Bug-Fix: was not exiting with error code.
#
# Revision 2.4  1998/10/23 11:41:16  houghton
# Changed to use MakeConfigs 5.06.
#
# Revision 2.3  1998/09/24 15:39:33  houghton
# Cleanup.
#
# Revision 2.2  1998/09/24 14:35:36  houghton
# Complete rework.
#
# Revision 2.1  1995/11/12 17:42:28  houghton
# Initial Version.
#
#