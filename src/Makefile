#
# -*- Makefile -*- for Common src dir
#
# Author: Paul Houghton
#
# Created: 11/12/95
#
# $Id$
#

make_cfg_ver	= 5.05
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
	$(hide) if ! $(MAKE) -C Common $@ $(exports); then exit; fi

all default debug:
	$(hide) if ! $(MAKE) -C Common $@ $(exports); then exit; fi

clean realclean:
	$(hide) if ! $(MAKE) -C Common $@ $(exports); then exit; fi

test:
	$(hide) if ! $(MAKE) -C Common $@ $(exports); then exit; fi


install_all install install_default install_debug: install_doc
	$(hide) if ! $(MAKE) -C Common $@ $(exports); then exit; fi


#
# $Log$
# Revision 2.1  1995/11/12 17:42:28  houghton
# Initial Version.
#
#