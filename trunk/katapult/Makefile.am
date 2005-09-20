SUBDIRS = common plugins katapult po

package-messages:
	cd $(top_srcdir) && $(MAKE) -f admin/Makefile.common package-messages
	$(MAKE) -C po merge

