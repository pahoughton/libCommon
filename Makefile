#
# -*- Makefile -*- for Common root dir
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


INSTALL_INC_DIR = $(local_incdir)
INSTALL_LIB_DIR = $(local_libdir)
INSTALL_BIN_DIR	= $(local_bindir)
INSTALL_MAN_DIR = $(local_mandir)

SRC_DIR		= src
DOC_DIR		= doc
TEST_DIR	= test

exports	    = 					\
	INSTALL_BIN_DIR=$(INSTALL_BIN_DIR)	\
	INSTALL_INC_DIR=$(INSTALL_INC_DIR)	\
	INSTALL_LIB_DIR=$(INSTALL_LIB_DIR)	\
	INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)	\
	show_commands=$(show_commands)		\
	check_install=$(check_install)		\

beta_exports	=				\
	INSTALL_BIN_DIR=$(INSTALL_BIN_DIR)	\
	INSTALL_INC_DIR=$(beta_incdir)		\
	INSTALL_LIB_DIR=$(beta_libdir)		\
	INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)	\
	show_commands=$(show_commands)		\
	check_install=$(check_install)		\

.PHONY: test

depend depend_all depend_test depend_default depend_debug:
	$(hide) $(MAKE) -C $(SRC_DIR) $@ $(exports)

all default debug:
	$(hide) $(MAKE) -C $(SRC_DIR) $@ $(exports)

clean realclean:
	$(hide) $(MAKE) -C $(SRC_DIR) $@ $(exports)
	$(hide) $(MAKE) -C $(DOC_DIR) $@ $(exports)
	$(hide) $(MAKE) -C $(TEST_DIR) $@ $(exports)

test:
	$(hide) $(MAKE) -C $(SRC_DIR) $@ $(exports)
	$(hide) $(MAKE) -C $(TEST_DIR) $@ $(exports)

install_doc:
	$(hide) $(MAKE) -C $(DOC_DIR) $@ $(exports)

install_all install: install_doc
	$(hide) $(MAKE) -C $(SRC_DIR) $@ $(exports)

install_beta:
	$(hide) $(MAKE) -C $(SRC_DIR) install_all $(beta_exports)

install_default install_debug: 
	$(hide) $(MAKE) -C $(SRC_DIR) $@ $(exports)


#
# $Log$
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