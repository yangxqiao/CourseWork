all: majors

majors: majors.cpp setops.o
	g++ -g -Wall -std=c++11 majors.cpp setops.o -o majors 

setops.o: setops.h setops.cpp
	g++ -g -Wall -c -std=c++11 setops.cpp -o setops.o
