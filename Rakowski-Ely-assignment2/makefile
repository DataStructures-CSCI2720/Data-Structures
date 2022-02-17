CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile2:
	g++ -c main.cpp
	g++ -c ItemType.cpp
	g++ -c SortedLinkedList.cpp
	g++ -o main main.o ItemType.o SortedLinkedList.o

compile: main.o ItemType.o SortedLinkedList.o
	$(CC) $(LFLAGS) -o main main.o ItemType.o SortedLinkedList.o

main.o: main.cpp ItemType.h SortedLinkedList.h
	$(CC) $(CFLAGS) main.cpp

ItemType.o: ItemType.cpp ItemType.h
	$(CC) $(CFLAGS) ItemType.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h
	$(CC) $(CFLAGS)	SortedLinkedList.cpp

run: compile2
	./main input.txt

clean:
	rm -f main
	rm -f *.o
