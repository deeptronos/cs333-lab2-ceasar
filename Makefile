CC = gcc
DEFINES =
DEBUG = -g
CFLAGS = $(DEFINES) $(DEBUG) -Wall -Wextra -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wno-return-local-addr -Wunsafe-loop-optimizations -Wuninitialized -Werror
SRC = caesar.c xor.c
OBJ = $(SRC:.c=.o)

COMMENT = "This is a comment"

# PROG1 = hellofunc
# PROG2 = xor
# PROGS = $(PROG1) $(PROG2)

all: caesar xor

# all : caesar xor
caesar: caesar.o
	$(CC) $(CFLAGS) -o caesar caesar.o

xor: xor.o
	$(CC) $(CFLAGS) -o xor xor.o

	
%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@




clean cls:
	rm -f $(PROG1) *.o *~ \#*

ci:
	if [ ! -d RCS ] ; then mkdir RCS; fi
	ci -t-none -l -m"lazy commit" [Mm]akefile *.[ch]

TAR_FILE = ${LOGNAME}_$(PROG1).tar.gz
tar:
	rm -f $(TAR_FILE)
	tar cvaf $(TAR_FILE) *.[ch] [Mm]akefile
	tar tvaf $(TAR_FILE)

comment:
	echo $(COMMENT)

opt:
	make clean
	make DEBUG=-O
