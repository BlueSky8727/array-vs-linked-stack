all : main.o LinkedList.o
	g++ main.o LinkedList.o -o main

main.o : main.cpp LinkedList.h
	g++ -c main.cpp -o main.o

LinkedList.o : LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp -o LinkedList.o

clean:
	rm -f main.o LinkedList.o main
