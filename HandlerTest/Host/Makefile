# $Id$

CFLAGS += -O2 -g -Wall `pkg-config --cflags libpcsclite`

# -ldl to use ldopen(), etc.
# -rdynamic so that the driver can use debug_msg()

# GNU/Linux
LDFLAGS = -ldl -rdynamic
# *BSD
#LDFLAGS = -rdynamic
# Mac OS X
#CFLAGS = -framework PCSC -I. -DRESPONSECODE_DEFINED_IN_WINTYPES_H -DMAX_BUFFER_SIZE_EXTENDED="(4 + 3 + (1<<16) + 3)"

targets = handler_test.o debug.o tokenparser.o

all: handler_test

handler_test: $(targets)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f .dependencies
	touch .dependencies
	rm -f handler_test $(targets)

.dependencies:
	touch .dependencies

distclean: clean
	rm -f dep_stamp
	rm -f tags

ctags:
	ctags-exuberant *.c *.h

dep: dep_stamp
dep_stamp:
	@echo "Making dependencies..."
	makedepend -f - -I. *.c > .dependencies
	touch dep_stamp

.PHONY: all clean distclean ctags dep

include .dependencies

