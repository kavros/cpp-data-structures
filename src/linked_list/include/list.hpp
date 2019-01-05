
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
    ~List();
    
    virtual void Insert(T val) = 0;
    T* Remove();
    
    bool Find(T val);
    int Size();
    void Print();
    void Clean();
    bool Remove(T target);

};


#endif /* LIST_HPP */

