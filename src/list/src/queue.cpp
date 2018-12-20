#include "../include/queue.hpp"

template <typename T> 
Queue<T>::Queue() 
{
    last=nullptr;    
    List<T>::size = 0;
}

template <typename T> 
Queue<T>::~Queue() 
{
    Node<T>* temp = head;
    while(List<T>::Size() > 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        List<T>::size--;
    }
}

template <typename T> 
void Queue<T>::Print()
{
    
}

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
        head = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last=newNode;
    }
    
    //increase list size
    List<T>::size++;
}

template <typename T> 
T* Queue<T>::Remove()
{
    if(List<T>::size == 0) return nullptr;
    T* valPtr = new T;
    *valPtr  = head->val;
    
    Node<T>* target = head;
    head = head->next;
    delete target;    
    List<T>::size--;
    
    return valPtr;
}

template <typename T> 
void Queue<T>::Remove(T target)
{
    
}
