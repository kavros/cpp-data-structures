CC =g++
IDIR=list/include
CFLAGS=-I$(IDIR)
COMPILE_FLAGS=-std=c++11 -Wall -Wextra -g -O3
INCLUDES= -I /usr/local/include
CPPUNITLDFLAGS=-lcppunit -Isrc -Itest

OBJECTS=bin/queue.o
EXECS=bin/queue\
	bin/queueUnitTest


.PHONY: all
all: 	directories\
	$(OBJECTS)\
	$(EXECS)\



.PHONY: directories
directories:
	mkdir -p bin/unit_tests

bin/queue.o: src/list/src/queue.cpp\
	src/list/include/queue.hpp\
	src/list/include/node.hpp\
	src/list/include/list.hpp
	$(CC) -c $< -o $@

bin/cppunit_test_driver.o:src/list/unit_tests/cppunitTestDriver.cpp
	$(CC) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

bin/queueUnitTest.o:  src/list/unit_tests/queueUnitTest.cpp
	$(CC) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@
	
	
bin/queueUnitTest: bin/queue.o\
		    bin/queueUnitTest.o\
		    bin/cppunit_test_driver.o
	$(CC)  $^ $(COMPILE_FLAGS) $(CPPUNITLDFLAGS) $(INCLUDES) -o $@ 

bin/queue: src/list/examples/main.cpp\
	$(OBJECTS)
	$(CC) $(COMPILE_FLAGS) $^  -o $@


.PHONY: clean	
clean:
	rm -rf bin
