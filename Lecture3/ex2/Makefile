#EXERCISE 0: fix mistakes so that this file actually work! hint: there is a confusion of where we store object files

# This is a comment line
CC=g++
# This is a folder to look for header files
INCDIR=include
OBJDIR = obj
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -l./$(OBJDIR)

main.x: main.o write_res.o
	$(CC) main.o write_res.o -o main.x
write_res.o: write_res.cpp
	$(CC) $(CFLAGS) write_res.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *.o *.x