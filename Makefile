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
	bin/hashtable.o\
	

EXECS=	bin/queue\
	bin/hashtable\
	bin/bst\
	bin/graph\

TESTS=	bin/queueUnitTest\
	bin/stackUnitTest\
	bin/hashtableUnitTest\
	bin/bstUnitTest\
	bin/graphUnitTest

.PHONY: all
all: 	directories\
	$(OBJECTS)\
	$(EXECS)\



.PHONY: directories
directories:
	mkdir -p bin/unit_tests

.PHONY: tests
tests:	$(TESTS)
	

.PHONY: run_tests
run_tests:
	./bin/queueUnitTest
	./bin/stackUnitTest
	./bin/hashtableUnitTest
	./bin/bstUnitTest
	./bin/graphUnitTest
	
	
#Graph
bin/graph.o: src/graph/src/graph.cpp\
	src/graph/include/graph.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@
	
bin/graph_main.o:src/graph/examples/main.cpp\
	    src/graph/src/graph.cpp\
	    src/graph/include/graph.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@
	
bin/graph:bin/graph_main.o\
	    bin/graph.o
	$(CC) $(COMPILE_FLAGS)  $^ -o $@

bin/graphUnitTest.o: src/graph/unit_tests/graphUnitTest.cpp\
		    src/graph/include/graph.hpp\
		    src/graph/src/graph.cpp
	$(CC) $(COMPILE_FLAGS) -c $<  $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

bin/graphUnitTest:bin/graphUnitTest.o\
	bin/graph.o\
	bin/cppunit_test_driver.o
	$(CC)   $(COMPILE_FLAGS)  $^ $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

	

#BST
bin/bst.o: src/binary_search_tree/src/bst.cpp\
	src/binary_search_tree/include/bst.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

bin/bst_main.o: src/binary_search_tree/examples/main.cpp\
	    src/binary_search_tree/include/bst.hpp\
	    src/binary_search_tree/src/bst.cpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@
	
bin/bstUnitTest.o: src/binary_search_tree/unit_tests/bstUnitTest.cpp\
		src/binary_search_tree/include/bst.hpp\
		src/binary_search_tree/src/bst.cpp
	$(CC) $(COMPILE_FLAGS) -c $<  $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

bin/bst: bin/bst_main.o\
	bin/bst.o
	$(CC) $(COMPILE_FLAGS)  $^ -o $@
	
bin/bstUnitTest:bin/bstUnitTest.o\
		bin/bst.o\
		bin/cppunit_test_driver.o
	$(CC)   $(COMPILE_FLAGS)  $^ $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

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
bin/list.o: src/linked_list/src/list.cpp\
	src/linked_list/include/list.hpp
	$(CC) -c $< $(COMPILE_FLAGS)  -o $@

bin/queue.o: src/linked_list/src/queue.cpp\
	src/linked_list/include/queue.hpp\
	src/linked_list/include/node.hpp\
	src/linked_list/include/list.hpp
	$(CC) -c $<  $(COMPILE_FLAGS)-o $@


bin/cppunit_test_driver.o:src/linked_list/unit_tests/cppunitTestDriver.cpp
	$(CC) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@

bin/queueUnitTest.o:  src/linked_list/unit_tests/queueUnitTest.cpp
	$(CC) $(COMPILE_FLAGS) -c $< $(CPPUNITLDFLAGS) $(INCLUDES) -o $@
	
bin/stackUnitTest.o:  src/linked_list/unit_tests/stackUnitTest.cpp
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


bin/main.o: src/linked_list/examples/main.cpp\
	src/linked_list/include/queue.hpp\
	src/linked_list/include/list.hpp\
	src/linked_list/include/stack.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

bin/stack.o: src/linked_list/src/stack.cpp\
	    src/linked_list/include/stack.hpp
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

bin/queue: bin/queue.o\
	bin/list.o\
	bin/main.o\
	bin/stack.o
	$(CC) $(COMPILE_FLAGS) $^  -o $@


.PHONY: clean	
clean:
	rm -rf bin
