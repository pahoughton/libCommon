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

make_cfg_ver	= 5.06
make_cfg_file	= $(TOOL_DIR)/include/Make/make.cfg.$(make_cfg_ver)

tools_archive_dir	= $(TOOL_DIR)/src/Tools
tools_build_dir		= $(TOOL_DIR)/src/Build/Tools
libs_build_dir		= $(TOOL_DIR)/src/Build/Libs

tools_host		= sideswipe.wcom.com
tools_cvs		= cvs-1.10.tar.gz
tools_gzip		= gzip-1.2.4.tar

default:

$(tools_archive_dir)/$(tools_gzip):
	cd $(libs_build_dir)						      \
	&& $(PROJECT)/support/AnonFtp.ksh				      \
	      $(tools_host)						      \
	      pub/tools/$(tools_gzip)					      \
	      $(tools_archive_dir)

$(TOOL_DIR)/bin/gzip: $(tools_archive_dir)/$(tools_gzip)
	cd $(tools_build_dir)						      \
	&& tar xf $(tools_archive_dir)/$(tools_gzip)
	basedir=`pwd`							      \
	&& cd $(tools_build_dir)/gzip*					      \
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

$(TOOL_DIR)/bin/cvs: $(tools_archive_dir)/$(tools_cvs)			      \
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

$(tools_build_dir)/MakeConfigs: 
	cd $(tools_build_dir)						      \
	&& cvs $(tools_cvsroot) co MakeConfigs

$(make_cfg_file): $(tools_build_dir)/MakeConfigs
	cd $(tools_build_dir)						      \
	&& $(MAKE) -f MakeConfigs/Makefile setup
	$(TOOL_DIR)/bin/make -C $(tools_build_dir)/MakeConfigs install

MakeConfigs: check_cvs $(make_cfg_file)

setup: MakeConfigs


#
# $Log$
#

# Local Variables:
# mode:makefile
# End:
