# Using all: will help compile multiple C files
# creating the own representation of "cache: cache.c"
# Later adding "cache" onto clean and remove
collatz: collatz.c
	gcc -o collatz collatz.c

clean:
	rm collatz

test: collatz
	bash test.sh
