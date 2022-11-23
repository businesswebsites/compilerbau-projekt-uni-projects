.SUFFIXES:
CC     = gcc
LEX    = flex

CFLAGS = -std=c99 -Wall -pedantic -DLEXDEBUG
LFLAGS = -t

LFILES = minako-lexic.l
HFILES = minako.h
CFILES = testscanner.c

target = $(LFILES:%.l=%.o) $(CFILES:%.c=%.o)

# Compiling
%.c: %.l
	$(LEX) $(LFLAGS) $< > $@
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Targets
all: testscanner
testscanner: $(target)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(RMFILES) testscanner core *.o
