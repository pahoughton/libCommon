#
# -*- Makefile -*- for Common root dir
#
# Author: Paul Houghton
#
# Created: 11/12/95
#
# $Id$
#

SRC_DIR	= src/Common
DOC_DIR	= docs/man

depend depend_all depend_default depend_debug:
	if ! $(MAKE) -C $(SRC_DIR) $@ $(exports); then exit; fi

all default debug:
	if ! $(MAKE) -C $(SRC_DIR) $@ $(exports); then exit; fi

install install_default install_debug:
	if ! $(MAKE) -C $(SRC_DIR) $@ $(exports); then exit; fi

install_all:
	if ! $(MAKE) -C $(SRC_DIR) $@ $(exports); then exit; fi
	if ! $(MAKE) -C $(DOC_DIR) $@ $(exports); then exit; fi


#
# $Log$
# Revision 2.1  1997/04/26 12:28:27  houghton
# Changed to Version 2.
#
# Revision 1.1  1995/11/12 17:42:02  houghton
# Initial Version.
#
#