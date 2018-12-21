
#ifndef LIST_HPP
#define LIST_HPP
#include "node.hpp"
#include "assert.h"
template<typename T> class List
{
protected:
    int size;
    struct Node<T>* last;
    struct Node<T>* head;
public:
    
    List();   
    virtual ~List();
    
    virtual void Insert(T val) = 0;
    virtual T* Remove() = 0;
    
    
    int Size();
    void Print();
    void Clean();
    void Remove(T target);

};


#endif /* LIST_HPP */

