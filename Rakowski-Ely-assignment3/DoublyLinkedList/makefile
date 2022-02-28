CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile2:
	g++ -c Main.cpp
	g++ -c DoublyLinkedList.cpp
	g++ -o Main Main.o DoublyLinkedList.o

compile: main.o ItemType.o SortedLinkedList.o
	$(CC) $(LFLAGS) -o main main.o ItemType.o SortedLinkedList.o

main.o: main.cpp ItemType.h SortedLinkedList.h
	$(CC) $(CFLAGS) main.cpp

ItemType.o: ItemType.cpp ItemType.h
	$(CC) $(CFLAGS) ItemType.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	$(CC) $(CFLAGS)	DoublyLinkedList.cpp

runfloat: compile2
	./Main float-input.txt

runint: compile2
	./Main int-input.txt

runint2: compile2
	./Main int-input2.txt

runstring: compile2
	./Main string-input.txt


clean:
	rm -f Main
	rm -f *.o
