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

make_cfg_ver	= 5.05
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
	$(hide) if ! $(MAKE) -C $(MAN_DIR) $@ $(exports); then exit; fi

clean:
	$(hide) if ! $(MAKE) -C $(MAN_DIR) $@ $(exports); then exit; fi

realclean:
	rm *~
	$(hide) if ! $(MAKE) -C $(MAN_DIR) $@ $(exports); then exit; fi


#
# $Log$
#

# Local Variables:
# mode:makefile
# End:
