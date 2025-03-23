all: main.o arraylist.o
	g++ main.o arraylist.o -o main

main.o: main.cpp arraylist.h
	g++ -c main.cpp -o main.o

arraylist.o: arraylist.cpp arraylist.h
	g++ -c arraylist.cpp -o arraylist.o

clean:
	rm -f *.o main
