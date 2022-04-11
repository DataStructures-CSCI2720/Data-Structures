compile2:
	g++ -c Main.cpp
	g++ -c BinaryTree.cpp
	g++ -o Main Main.o BinaryTree.o

runfloat: compile2
	./Main float-input1.txt

runint: compile2
	./Main int-input1.txt

runstring: compile2
	./Main string-input1.txt


clean:
	rm -f Main
	rm -f *.o
