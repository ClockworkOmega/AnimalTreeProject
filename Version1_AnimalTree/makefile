CC= g++
CFLAGS= -Wall

all: AnimalTree

AnimalTree: Main.o AnimalTree.o
	$(CC) $(CFLAGS) -o AnimalTree Main.o AnimalTree.o

Main.o: AnimalTree.h Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp

AnimalTree.o: AnimalTree.h AnimalTree.cpp
	$(CC) $(CFLAGS) -c AnimalTree.cpp

clean:
	rm -rf *o
