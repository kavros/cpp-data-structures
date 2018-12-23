# Overview
This project aims to develop common data structures in C++ such as trie, queue, stack, hashtable and graphs

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

# Build
* Install CppUnit using the instructions.
* Build project using the following commands:
```
$ make
```
* Work in progress for CMake support:
```
$ cmake -H. -Bbuild
$ cmake --build build -- -j3
```



# Project GuideLines
* Source files naming: 
    * All letters must be lower case.
* Struct, Class, Function naming: 
    * Only the first letter of each word is uppercase and the rest are lowercase.
* Every bracket has a new line before and after.

