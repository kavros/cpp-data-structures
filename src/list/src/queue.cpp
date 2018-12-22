#include "../include/queue.hpp"
#include <assert.h>

template <typename T> 
void Queue<T>::Insert(T val)
{
    //create new node
    struct Node<T>* newNode = new Node<T> ;
    newNode->val=val;
    newNode->next = nullptr;
    
    //add node to list
    if( List<T>::Size() == 0 )
    {
        List<T>::head = newNode;
        List<T>::last = newNode;
    }
    else
    {
        List<T>::last->next = newNode;
        List<T>::last=newNode;
    }
    
    //increase list size
    List<T>::size++;
}

