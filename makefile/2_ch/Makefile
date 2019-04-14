SUBDIRS=foo bar koo

.PHONY: clean subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

clean: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@
