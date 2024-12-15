# Using all: will help compile multiple C files
# creating the own representation of "cache: cache.c"
# Later adding "cache" onto clean and remove
all: collatz

CFLAGS = -g -Wall -DDEBUG

OBJS = collatz.o cache.o

collatz: $(OBJS)
	gcc -o collatz $(OBJS)

collatz.o: collatz.c cache.h

# handlers.o: handlers.c handlers.h
#   gcc -c handlers.c

clean:
	rm -f myshell $(OBJS)
