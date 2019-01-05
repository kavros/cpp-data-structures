# Overview [![Build Status](https://travis-ci.com/kavros/cpp-data-structures.svg?branch=master)](https://travis-ci.com/kavros/cpp-data-structures) [![Coverage Status](https://coveralls.io/repos/github/kavros/cpp-data-structures/badge.svg?branch=master)](https://coveralls.io/github/kavros/cpp-data-structures?branch=master)
This project aims to develop common data structures in C++ such as tree, queue, stack, hashtable and graphs

# Install CppUnit
```
$ wget http://dev-www.libreoffice.org/src/cppunit-1.14.0.tar.gz
$ tar -xvzf cppunit-1.13.2.tar.gz
$ cd cppunit-1.13.2
$ ./configure --prefix=$HOME
$ make
$ make install 
$ . ../scripts/exports.sh 
```

# Build & Run
* Install CppUnit using the instructions.
* Build project and run unit tests using the following commands:
```
$ make
$ make run_tests
```
* Work in progress for CMake support:
```
$ cmake -H. -Bbuild
$ cmake --build build -- -j3
```



# Code Style
* Source files naming: 
    * All letters must be lower case.
* Struct, Class, Function naming: 
    * Only the first letter of each word is uppercase and the rest are lowercase.
* Every bracket has a new line before and after.

