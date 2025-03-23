all: main

main: main.o arrayStack.o arraylist.o
	g++ -o main main.o arrayStack.o arraylist.o

main.o: main.cpp arrayStack.h ../ArrayList/arraylist.h
	g++ -c main.cpp

arrayStack.o: arrayStack.cpp arrayStack.h ../ArrayList/arraylist.h
	g++ -c arrayStack.cpp

arraylist.o: ../ArrayList/arraylist.cpp ../ArrayList/arraylist.h
	g++ -c ../ArrayList/arraylist.cpp

clean:
	rm -f *.o main
