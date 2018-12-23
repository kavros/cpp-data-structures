CC =g++
IDIR=list/include
CFLAGS=-I$(IDIR)
COMPILE_FLAGS=-std=c++11 -Wall -Wextra -g -O3  -std=c++0x 
INCLUDES= -I /usr/local/include
CPPUNITLDFLAGS=-lcppunit -Isrc -Itest

OBJECTS= bin/queue.o\
	bin/list.o\
	bin/main.o\
	bin/stack.o\
	bin/hashtable.o
	
EXECS=bin/queue\
	bin/queueUnitTest\
	bin/stackUnitTest\
	bin/hashtable\
	bin/hashtableUnitTest


.PHONY: all
all: 	directories\
	$(OBJECTS)\
	$(EXECS)\



.PHONY: directories
directories:
	mkdir -p bin/unit_tests

.PHONY: run_tests
run_tests:
	./bin/queueUnitTest
	./bin/stackUnitTest
	./bin/hashtableUnitTest

# Hashtable 
bin/hashtable.o: src/hashtable/src/hashtable.cpp\
		src/hashtable/include/hashtable.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

bin/hash_main.o: src/hashtable/examples/main.cpp\
		src/hashtable/include/hashtable.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

bin/hashtable: bin/hash_main.o\
	bin/hashtable.o	
	$(CC) $(COMPILE_FLAGS) $^ -o $@
	
bin/hashtableUnitTest.o: src/hashtable/unit_tests/hashtableUnitTest.cpp\
	src/hashtable/include/hashtable.hpp
	$(CC) -c $< $(COMPILE_FLAGS) $(CPPUNITLDFLAGS) $(INCLUDES) -o $@ 
	
bin/hashtableUnitTest: bin/hashtable.o\
		    bin/hashtableUnitTest.o\
		    bin/cppunit_test_driver.o
	$(CC)  $^ $(COMPILE_FLAGS) $(CPPUNITLDFLAGS) $(INCLUDES) -o $@ 
	
# List, Queue, Stack, Example, unit test
bin/list.o: src/list/src/list.cpp\
	src/list/include/list.hpp
	$(CC) -c $< -o $@

bin/queue.o: src/list/src/queue.cpp\
	src/list/include/queue.hpp\
	src/list/include/node.hpp\
	src/list/include/list.hpp
	$(CC) -c $< -o $@


bin/cppunit_test_driver.o:src/list/unit_tests/cppunitTestDriver.cpp
	$(CC) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

bin/queueUnitTest.o:  src/list/unit_tests/queueUnitTest.cpp
	$(CC) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@
	
bin/stackUnitTest.o:  src/list/unit_tests/stackUnitTest.cpp
	$(CC) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@
	
bin/queueUnitTest: bin/queue.o\
		    bin/queueUnitTest.o\
		    bin/list.o\
		    bin/cppunit_test_driver.o
	$(CC)  $^ $(COMPILE_FLAGS) $(CPPUNITLDFLAGS) $(INCLUDES) -o $@ 


bin/stackUnitTest: bin/stack.o\
		    bin/stackUnitTest.o\
		    bin/list.o\
		    bin/cppunit_test_driver.o
	$(CC)  $^ $(COMPILE_FLAGS) $(CPPUNITLDFLAGS) $(INCLUDES) -o $@ 


bin/main.o: src/list/examples/main.cpp\
	src/list/include/queue.hpp\
	src/list/include/list.hpp\
	src/list/include/stack.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

bin/stack.o: src/list/src/stack.cpp\
	    src/list/include/stack.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

bin/queue: $(OBJECTS)
	$(CC) $(COMPILE_FLAGS) $^  -o $@


.PHONY: clean	
clean:
	rm -rf bin
