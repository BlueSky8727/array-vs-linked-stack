all: main

main: main.o linkedstack.o linkedlist.o
	clang++ -o main main.o linkedstack.o linkedlist.o -I../LinkedList

main.o: main.cpp linkedstack.h ../LinkedList/LinkedList.h
	clang++ -c main.cpp -I../LinkedList

linkedstack.o: linkedstack.cpp linkedstack.h ../LinkedList/LinkedList.h
	clang++ -c linkedstack.cpp -I../LinkedList

linkedlist.o: ../LinkedList/LinkedList.cpp ../LinkedList/LinkedList.h
	clang++ -c ../LinkedList/LinkedList.cpp -I../LinkedList

clean:
	rm -f *.o main