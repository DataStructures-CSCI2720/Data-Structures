compile:
	g++ -c main.cpp
	g++ -c Sorting.cpp
	g++ -o Main main.o Sorting.o

runordered: compile
	./Main ordered.txt

runreverse: compile
	./Main reverse.txt

runrandom: compile
	./Main random.txt

clean:
	rm -f Main
	rm -f *.o
