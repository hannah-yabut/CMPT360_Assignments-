#Name: Hannah Yabut & Ismael Robleh
#Student ID: 3131432 & 3149556
#May 10, 2026 
#Compile, run, and test userclean program for memory leaks or any potential errors

#Compiler 
CC := gcc-13

#Compiler flags
CFLAGS := -std=c11 -Wall -Wextra -pedantic -O2 -g

#Valgrind command
VALGRIND ?= valgrind

#Valgrind flags for detailed and thorough memory leak detection
VGFLAGS  ?= --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=1

#Declare the following targets as makefile commands instead of file targets
.PHONY: all clean check valgrind vg

#Build userclean executable
all: userclean

#Link object file to into executable
userclean: userclean.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

#Compile source file into object file
userclean.o: userclean.c
	$(CC) $(CFLAGS) -c $<

#Automatic test cases using pipes
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

#Run executable manually
run: userclean
	./userclean

#Run memory leak and error detection with Valgrind by using input.txt file as input
valgrind: userclean
	$(VALGRIND) $(VGFLAGS) ./userclean < input.txt

#Alias for Valgrind
vg: valgrind

#Remove all files from directory (specifically executable and object file)
clean:
	rm -f userclean userclean.o