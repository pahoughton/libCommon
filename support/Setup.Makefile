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

hide		= @

SHELL		= /bin/ksh

VER_MAJOR	= 3
PROJECT		= libCommon-$(VER_MAJOR)
CFG_DIR		= $(PROJECT)/src/config

make_cfg_ver	= 5.06
make_cfg_file	= $(TOOL_DIR)/include/Make/make.cfg.$(make_cfg_ver)
MAKECONFIGS	= MakeConfigs-$(make_cfg_ver)

tools_bin_dir		= $(TOOL_DIR)/bin
tools_archive_dir	= $(TOOL_DIR)/src/Archives
tools_build_dir		= $(TOOL_DIR)/src/Build/Tools
libs_build_dir		= $(TOOL_DIR)/src/Build/Libs

anon_ftp		= $(tools_bin_dir)/AnonFtp.ksh

cvs_ver			= 1.10

tools_cvs_pkg		= cvs-$(cvs_ver).tar.gz
tools_gzip_pkg		= gzip-1.2.4.tar

tools_host		= sideswipe.wcom.com

no_default:
	$(hide) echo " ++ ERROR: No default target available!"
	$(hide) exit 1;


$(tools_bin_dir)							      \
$(tools_archive_dir)							      \
$(tools_build_dir):
	$(hide) $(PROJECT)/support/mkdirhier.sh $@

$(TOOL_DIR)/bin/gzip: 
	$(hide)	[ -f $(tools_archive_dir)/$(tools_gzip) ]		      \
	  || $(anon_ftp) $(tools_host)					      \
	         pub/tools/$(tools_gzip)				      \
	         $(tools_archive_dir) )
	$(hide) cd $(tools_build_dir)					      \
	&& tar xf $(tools_archive_dir)/$(tools_gzip)			      \
	&& cd gzip*							      \
	&& ./configure --prefix=$(TOOL_DIR)				      \
	&& make								      \
	&& make install

$(TOOL_DIR)/bin/cvs:
	$(hide)	[ -f $(tools_archive_dir)/$(tools_cvs) ]		      \
	  || $(anon_ftp) $(tools_host)					      \
	         pub/tools/$(tools_cvs)					      \
	         $(tools_archive_dir) )
	$(hide) cd $(tools_build_dir)					      \
	&& tar xf $(tools_archive_dir)/$(tools_cvs)			      \
	&& cd cvs-$(cvs_ver)						      \
	&& ./configure --prefix=$(TOOL_DIR)				      \
	&& make								      \
	&& make install

cvs: 		$(tools_archive_dir)					      \
		$(tools_bin_dir)					      \
		$(tools_build_dir)					      \
		$(anon_ftp)						      \
		$(TOOL_DIR)/bin/gzip					      \
		$(TOOL_DIR)/bin/cvs
	$(hide) echo; echo " + CVS installation complete."; echo


check_cvs:
	$(hide) if type cvs ; then					      \
	  cvs_verstr=`cvs --version`;					      \
	  cvs_vernum=`echo $$cvs_verstr |				      \
	      sed 's/.* (CVS) \($(cvs_ver)\).*/\1/'`;			      \
	  if [ "$$cvs_vernum" != "$(cvs_ver)" ] ; then			      \
	     echo "+ ERROR: wrong version of cvs found - $(cvs_ver) needed:"; \
	     cvs --version;						      \
	     echo "+ please install the $(cvs_ver) version using the";	      \
	     echo "  cvs target of this makefile:"; 			      \
	     echo "  (i.e. make -f $(PROJECT)/support/Setup.Makefile cvs";    \
	     exit 1;							      \
	  else								      \
	    echo "+ cvs $(cvs_ver) found.";				      \
	  fi;								      \
	else								      \
	  echo "+ ERROR: cvs not found please install the $(cvs_ver) of";     \
	  echo "  cvs using the cvs target of this makefile.";		      \
	  echo "   (i.e. make -f $(PROJECT)/support/Setup.Makefile cvs";      \
	  exit 1;							      \
	fi

$(make_cfg_file): 
	cd $(tools_build_dir)						      \
	&& ( [ -d $(MAKECONFIGS) ] || cvs co $(MAKECONFIGS) )		      \
	&& $(MAKE) -f $(MAKECONFIGS)/Makefile setup			      \
	&& $(TOOL_DIR)/bin/make -C $(MAKECONFIGS) install

gen_setup_cfg:
	rm -f $(CFG_DIR)/Setup.cfg
	sed								      \
		-e 's!%INSTALL_INC_DIR%!$(INSTALL_INC_DIR)!'		      \
		-e 's!%INSTALL_LIB_DIR%!$(INSTALL_LIB_DIR)!'		      \
		-e 's!%INSTALL_MAN_DIR%!$(INSTALL_MAN_DIR)!'		      \
	  < $(CFG_DIR)/Setup.cfg.src					      \
	  > $(CFG_DIR)/Setup.cfg
	chmod 444 $(CFG_DIR)/Setup.cfg

setup: check_cvs $(tools_build_dir) $(make_cfg_file) gen_setup_cfg


#
# $Log$
# Revision 1.8  2000/06/01 00:45:02  houghton
# Bug-Fix: changed degagnu to dejagnu_lib.
#
# Revision 1.7  2000/05/30 15:28:14  houghton
# Changed to use MAKCCONFIGS and DEJAGNU variables.
#
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
