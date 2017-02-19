#declare the variable
CC = g++

CFLAGS = -c -Wall

TARGET = hello

RM = rm -rf

all: $(TARGET)

$(TARGET): main.o function1.o function2.o
	$(CC) main.o funciton1.o function2.o -o hello

#main.o is the target
#main.cpp is the dependency
#g++ -c main.cpp is the command
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

function1.o: function1.cpp
	$(CC) $(CFLAGS) function1.cpp

function2.o: function2.cpp
	$(CC) $(CFLAGS) function2.cpp

clean:
	$(RM) *.o $(TARGET)
