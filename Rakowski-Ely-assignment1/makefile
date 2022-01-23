CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: Instructor.o Student.o main.o
	$(CC) $(LFLAGS) -o main Instructor.o Student.o main.o

main.o: main.cpp Instructor.h Student.h
	g++ -c main.cpp

Instructor.o: Instructor.cpp Instructor.h
	$(CC) $(CFLAGS) Instructor.cpp

Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS)	Student.cpp

run: compile
	./main instructors.txt students.txt

clean:
	rm -f main
	rm -f *.o
