include head.mk

SUBDIRS= connector core
PHONY += $(SUBDIRS)
.PHONY: $(PHONY)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@


test:
	${MAKE} -C ${SUBDIR} test

clean: 
	${MAKE} -C ${SUBDIR} clean
