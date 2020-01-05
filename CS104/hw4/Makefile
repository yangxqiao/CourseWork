all: remdup deque_test stack_test laundry

remdup: rem_dup.cpp rem_dup_lib.o 
	g++ -g -Wall -std=c++11 rem_dup.cpp rem_dup_lib.o -o remdup 

rem_dup_lib.o: rem_dup_lib.cpp rem_dup_lib.h
	g++ -g -Wall -c rem_dup_lib.cpp -o rem_dup_lib.o

deque_test: deque_test.cpp deque.h
	g++ -g -Wall -std=c++11 deque_test.cpp -I /usr/include/gtest/ -l gtest -l gtest_main -pthread -o deque_test

stack_test: stack_test.cpp stack.h
	g++ -g -Wall -std=c++11 stack_test.cpp -I /usr/include/gtest/ -l gtest -l gtest_main -pthread -o stack_test

laundry: laundry.cpp stack.h
	g++ -g -Wall -std=c++11 laundry.cpp -o laundry