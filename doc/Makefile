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
# Created:	09/24/98 07:45
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

MAN_DIR	= man

exports	    = 					\
	INSTALL_BIN_DIR=$(INSTALL_BIN_DIR)	\
	INSTALL_INC_DIR=$(INSTALL_INC_DIR)	\
	INSTALL_LIB_DIR=$(INSTALL_LIB_DIR)	\
	INSTALL_MAN_DIR=$(INSTALL_MAN_DIR)	\
	show_commands=$(show_commands)		\
	check_install=$(check_install)		\


install install_doc:
	$(hide) $(MAKE) -C $(MAN_DIR) $@ $(exports)

clean:
	$(hide) $(MAKE) -C $(MAN_DIR) $@ $(exports)

realclean:
	rm -f *~
	$(hide) $(MAKE) -C $(MAN_DIR) $@ $(exports)


#
# $Log$
# Revision 1.2  1998/10/23 11:41:03  houghton
# Changed to use MakeConfigs 5.06.
#
# Revision 1.1  1998/09/24 15:28:14  houghton
# Initial Version.
#
#

# Local Variables:
# mode:makefile
# End:
