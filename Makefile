FileFind.out : main.o directory.o
	g++ -ansi -Wall -g -o FileFind.out main.o directory.o

main.o : main.cpp list.h
	g++ -ansi -Wall -g -c main.cpp
	
directory.o : directory.cpp directory.h list.h
	g++ -ansi -Wall -g -c directory.cpp

clean :
	rm -f FileFind.out main.o directory.o 