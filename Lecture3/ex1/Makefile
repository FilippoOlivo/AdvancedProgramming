#EXERCISE 0: fix mistakes so that this file actually work! hint: there is a confusion of where we store object files

# This is a comment line
CC=g++
# This is a folder to look for header files
INCDIR=include
OBJDIR = obj
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -I./$(OBJDIR)

main.x: main.o sqe.o
	$(CC) main.o sqe.o -o main.x
sqe.o: sqe.cpp
	$(CC) $(CFLAGS) sqe.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *.o *.x