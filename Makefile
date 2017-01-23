#declare the variable
CC=g++

CFLAGS=-c -Wall

all: head

head: darkConer.cpp
	$(CC) $(CFLAGS) -o head darkConer.cpp
clean:
	$(RM) head 
