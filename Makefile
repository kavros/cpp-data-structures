CC=g++
IDIR=list/include
CFLAGS=-I$(IDIR)
COMPILE_FLAGS=-std=c++11 -Wall -Wextra -g -std=c++0x -O3

OBJECTS=bin/queue.o
EXECS=bin/queue


.PHONY: all
all: 	directories\
	$(OBJECTS)\
	$(EXECS)


.PHONY: directories
directories:
	mkdir -p bin/unit_tests

bin/queue.o: src/list/src/queue.cpp\
	src/list/include/queue.hpp\
	src/list/include/node.hpp\
	src/list/include/list.hpp
	$(CC) -c $< -o $@

bin/queue: src/list/examples/main.cpp\
	$(OBJECTS)
	$(CC) $(COMPILE_FLAGS) $^  -o $@


.PHONY: clean	
clean:
	rm -rf bin
