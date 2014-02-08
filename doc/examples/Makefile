CPPFLAGS = -I../../src
CFLAGS   = -std=c99 -g -Os -Wall -Wextra
LDFLAGS  = -L../../src/cpr/.libs -lcpr

PROGRAMS = list map set sizeof string vector

.PHONY: all
all: $(PROGRAMS)

.PHONY: clean
clean:
	$(RM) $(PROGRAMS) *.o *~
