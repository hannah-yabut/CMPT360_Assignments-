CC = gcc-13
CFLAGS = -std=c11 -Wall -Wextra -pedantic

all: userclean

userclean: userclean.c
	$(CC) $(CFLAGS) userclean.c -o userclean

clean:
	rm -f userclean