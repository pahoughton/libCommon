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
check_install	= true

# Include standard MakeConfig configuration for GNU make required
include Make/make.cfg.$(make_cfg_ver)

PRJ_TOPDIR	= ..
CFG_DIR		= $(PRJ_TOPDIR)/src/config

include $(CFG_DIR)/00-Makefile.cfg

.PHONY: test

depend depend_all depend_test depend_default depend_debug:
	$(hide) $(MAKE) -C Common $@ $(exports)

all default debug:
	$(hide) $(MAKE) -C Common $@ $(exports)

clean realclean:
	$(hide) $(MAKE) -C Common $@ $(exports)
	$(hide) $(MAKE) -C $(DOC_DIR) $@ $(exports)
	$(hide) $(MAKE) -C $(TEST_DIR) $@ $(exports)

test:
	$(hide) $(MAKE) -C Common $@ $(exports)

check: test
	$(hide) $(MAKE) -C $(TEST_DIR) $@ $(exports)

install_docs:
	$(hide) $(MAKE) -C $(DOC_DIR) $@ $(exports)

install_all install install_default install_debug: install_docs
	$(hide) $(MAKE) -C Common $@ $(exports)

install_lib_all:
	$(hide) $(MAKE) -C Common install_all $(exports)

#
# $Log$
# Revision 3.2  1999/10/29 21:42:37  houghton
# Chagned to support 'setup' and other new targets in ../Makefile.
#
# Revision 3.1  1999/10/29 16:56:14  houghton
# Changed Version to 3
#
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