#
# Title:        Makefile
# Project:	Common
# Desc:
# 
#   
# 
# Notes:
# 
# Author:	Paul A. Houghton - (paul.houghton@wcom.com)
# Created:	09/24/98 08:21
#
# Revision History: (See end of file for Revision Log)
#
#   Last Mod By:    $Author$
#   Last Mod:	    $Date$
#   Version:	    $Revision$
#
#   $Id$
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
	$(hide) $(MAKE) -C Base/src $@ $(exports)

all default debug test shared:
	$(hide) $(MAKE) -C Base/src $@ $(exports)

clean realclean:
	$(hide) $(MAKE) -C Base/src $@ $(exports)

check:
	$(hide) $(MAKE) -C Base/src $@ $(exports)



#
# $Log$
# Revision 3.1  1999/10/29 16:56:25  houghton
# Changed Version to 3
#
# Revision 1.2  1998/10/23 11:41:34  houghton
# Changed to use MakeConfigs 5.06.
#
# Revision 1.1  1998/09/24 15:28:07  houghton
# Initial Version.
#
#

# Local Variables:
# mode:makefile
# End:
