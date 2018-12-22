#include "../include/stack.hpp"

template <typename T> 
void Stack<T>::Insert(T val)
{
    Node<T>* newNode = new Node<T>;
    newNode->val = val;
    if(List<T>::head == nullptr )
    {
        List<T>::head = newNode;
        List<T>::last = newNode;
                
    }
    else
    {
        newNode->next=List<T>::head;
        List<T>::head = newNode;
    }    
    List<T>::size++;
}

