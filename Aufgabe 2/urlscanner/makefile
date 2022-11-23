.SUFFIXES:
CC     = gcc
LEX    = flex

CFLAGS = -std=c99 -Wall -pedantic -DLEXDEBUG
LFLAGS = -t

LFILES = urlscanner.l
HFILES = urlscanner.h
CFILES = testurlscanner.c

target = $(LFILES:%.l=%.o) $(CFILES:%.c=%.o)

# Compiling
%.c: %.l
	$(LEX) $(LFLAGS) $< > $@
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Targets
all: testurlscanner
testurlscanner: $(target)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(RMFILES) testurlscanner core *.o
