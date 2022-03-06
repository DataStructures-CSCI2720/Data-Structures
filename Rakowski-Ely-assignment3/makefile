compile2:
	g++ -c main.cpp
	g++ -c DoublyLinkedList.cpp
	g++ -o main main.o DoublyLinkedList.o

runfloat: compile2
	./main float-input.txt

runint: compile2
	./main int-input.txt

runint2: compile2
	./main int-input2.txt

runstring: compile2
	./main string-input.txt


clean:
	rm -f main
	rm -f *.o
