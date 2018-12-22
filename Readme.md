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
```
$ make
     or
$ cmake -H. -Bbuild
$ cmake --build build -- -j3
```




# Naming Conventions 
*.cpp: lowercase
*.hpp: lowercase
struct,class,function names: only the first letter of each word is uppercase and the other letters are lowercase
every bracket has a new line before and after
