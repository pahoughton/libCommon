#
# Title:        Setup.Makefile
# Project:	Common
# Desc:
# 
#   
# 
# Notes:
# 
# Author:	Paul Houghton - (paul.houghton@wcom.com)
# Created:	10/29/99 13:04
#
# Revision History: (See end of file for Revision Log)
#
#   Last Mod By:    $Author$
#   Last Mod:	    $Date$
#   Version:	    $Revision$
#
#   $Id$
# 


SHELL		= /bin/ksh

PROJECT		= libCommon-3
CFG_DIR		= $(PROJECT)/src/config

make_cfg_ver	= 5.06
make_cfg_file	= $(TOOL_DIR)/include/Make/make.cfg.$(make_cfg_ver)

dejagnu_lib	= $(TOOL_DIR)/share/dejagnu/lib/libSupport.exp

MAKECONFIGS	= MakeConfigs-$(make_cfg_ver)
DEJAGNU		= DejagnuSupport-1


tools_archive_dir	= $(TOOL_DIR)/src/Tools
tools_build_dir		= $(TOOL_DIR)/src/Build/Tools
libs_build_dir		= $(TOOL_DIR)/src/Build/Libs

tools_host		= sideswipe.wcom.com
tools_cvs		= cvs-1.10.tar.gz
tools_gzip		= gzip-1.2.4.tar

no_default:

$(TOOL_DIR)/src								      \
$(TOOL_DIR)/src/Build							      \
$(tools_archive_dir)							      \
$(tools_build_dir):
	mkdir $@

$(tools_build_dir): $(TOOL_DIR)/src/Build

$(tools_archive_dir)/$(tools_gzip): $(tools_archive_dir)
	cd $(libs_build_dir)						      \
	&& $(PROJECT)/support/AnonFtp.ksh				      \
	      $(tools_host)						      \
	      pub/tools/$(tools_gzip)					      \
	      $(tools_archive_dir)

$(TOOL_DIR)/bin/gzip: $(tools_build_dir) $(tools_archive_dir)/$(tools_gzip)
	cd $(tools_build_dir)						      \
	&& tar xf $(tools_archive_dir)/$(tools_gzip)
	cd $(tools_build_dir)/gzip*					      \
	&& ./configure --prefix=$(TOOL_DIR)				      \
	&& make								      \
	&& make install

gzip: $(TOOL_DIR)/bin/gzip

$(tools_archive_dir)/$(tools_cvs):
	cd $(libs_build_dir)						      \
	&& $(PROJECT)/support/AnonFtp.ksh				      \
	      $(tools_host)						      \
	      pub/tools/$(tools_cvs)					      \
	      $(tools_archive_dir)

$(TOOL_DIR)/bin/cvs: $(tools_build_dir) $(tools_archive_dir)/$(tools_cvs)     \
		$(TOOL_DIR)/bin/gzip
	cd $(tools_build_dir)						      \
	&& zcat $(tools_archive_dir)/$(tools_cvs) | tar xf -
	cd $(tools_build_dir)/cvs*					      \
	&& ./configure --prefix=$(TOOL_DIR)				      \
	&& make								      \
	&& make install

cvs: $(TOOL_DIR)/bin/cvs

check_cvs:
	@if type cvs ; then						      \
	  echo " + cvs found.";						      \
	else								      \
	  echo " + cvs not found please install using the cvs target.";       \
	  echo "   (i.e. make -f $(PROJECT)/support/Setup.Makefile cvs";      \
	  exit 1;							      \
	fi

$(tools_build_dir)/$(MAKECONFIGS): 
	cd $(tools_build_dir)						      \
	&& cvs $(tools_cvsroot) co $(MAKECONFIGS)

$(make_cfg_file): $(tools_build_dir)/$(MAKECONFIGS)
	cd $(tools_build_dir)						      \
	&& $(MAKE) -f $(MAKECONFIGS)/Makefile setup
	$(TOOL_DIR)/bin/make						      \
		-C $(tools_build_dir)/MakeConfigs-$(make_cfg_ver)	      \
		install

$(tools_build_dir)/$(DEJAGNU): 
	cd $(tools_build_dir)						      \
	&& cvs $(tools_cvsroot) co $(DEJAGNU)

$(dejagnu): $(tools_build_dir)/$(DEJAGNU)
	cd $(tools_build_dir)						      \
	&& $(MAKE) -f $(DEJAGNU)/Makefile setup
	$(TOOL_DIR)/bin/make						      \
		-C $(tools_build_dir)/$(DEJAGNU)			      \
		install

gen_setup_cfg:
	rm -f $(CFG_DIR)/Setup.cfg
	sed								      \
		-e 's!%INSTALL_INC_DIR%!$(INSTALL_INC_DIR)!'		      \
		-e 's!%INSTALL_LIB_DIR%!$(INSTALL_LIB_DIR)!'		      \
		-e 's!%INSTALL_MAN_DIR%!$(INSTALL_MAN_DIR)!'		      \
	  < $(CFG_DIR)/Setup.cfg.src					      \
	  > $(CFG_DIR)/Setup.cfg
	chmod 444 $(CFG_DIR)/Setup.cfg

setup: check_cvs $(tools_build_dir) $(make_cfg_file) $(dejagnu) gen_setup_cfg


#
# $Log$
# Revision 1.6  1999/11/08 15:13:58  houghton
# Added get_setup_cfg target.
#
# Revision 1.5  1999/11/04 17:23:41  houghton
# Added dejagnu support to setup.
#
# Revision 1.4  1999/10/29 23:20:16  houghton
# Bug-Fix: all referances to MakeConfigs dir not fixed.
#
# Revision 1.3  1999/10/29 23:17:26  houghton
# Bug-Fix: need to be able to create tools_build_dir.
#
# Revision 1.2  1999/10/29 23:09:50  houghton
# Changed to use MakeConfigs-(ver) vs MakeConfigs.
#
# Revision 1.1  1999/10/29 21:43:59  houghton
# Initial Version.
#
#

# Local Variables:
# mode:makefile
# End:
