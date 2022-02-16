CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: ItemType.o SortedLinkedList.o main.o
	$(CC) $(LFLAGS) -o main ItemType.o SortedLinkedList.o main.o

main.o: main.cpp ItemType.h SortedLinkedList.h
	g++ -c main.cpp

ItemType.o: ItemType.cpp ItemType.h
	$(CC) $(CFLAGS) ItemType.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h
	$(CC) $(CFLAGS)	SortedLinkedList.cpp

run: compile
	./main input.txt

clean:
	rm -f main
	rm -f *.o
