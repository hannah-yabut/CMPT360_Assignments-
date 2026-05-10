# = gcc-13
#CFLAGS = -std=c11 -Wall -Wextra -pedantic

#all: userclean

#userclean: userclean.c
#	$(CC) $(CFLAGS) userclean.c -o userclean

#clean:
#	rm -f userclean

CC := gcc-13
CFLAGS := -std=c11 -Wall -Wextra -pedantic -O2 -g
VALGRIND ?= valgrind
VGFLAGS  ?= --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=1

.PHONY: all clean check valgrind vg

all: userclean

userclean: userclean.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

userclean.o: userclean.c
	$(CC) $(CFLAGS) -c $<

check: userclean
	echo 'Bob123' | ./userclean
	echo 'a!' | ./userclean
	echo ' Admin 42 ' | ./userclean
	echo 'root user' | ./userclean
	echo 'Z_' | ./userclean
	echo '_99' | ./userclean
	echo 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' | ./userclean
	echo '123abc' | ./userclean
	echo 'AdMiN' | ./userclean
	echo '@#!#$%^t3st' | ./userclean
	echo 'a_b_c' | ./userclean
	echo 'a b c' | ./userclean
	echo ' ' | ./userclean

run: userclean
	./userclean

valgrind: userclean
	$(VALGRIND) $(VGFLAGS) ./userclean < input.txt

vg: valgrind

clean:
	rm -f userclean userclean.o