CC=gcc
CFLAGS= -Wall

# the -Wall enables all basic warnings.

make: cvector.c
	$(CC) $(CFLAGS) -o cvector cvector.c
clean:
	rm cvector
