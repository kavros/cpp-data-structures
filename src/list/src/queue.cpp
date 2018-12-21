#include "../include/queue.hpp"
#include <assert.h>
template <typename T> 
Queue<T>::Queue() 
{
    last=nullptr;    
    List<T>::size = 0;
}

template <typename T> 
Queue<T>::~Queue() 
{
    Clean();
}

template <typename T> 
void Queue<T>::Print()
{
    Node<T>* temp = head;
    while(temp != nullptr)
    {
        std::cout<< temp->val << std::endl;
        temp = temp->next;
    }
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
    Node<T>* curr = head;
    Node<T>* prev = nullptr;
    
    while(curr!= nullptr)
    {
        if( curr->val ==  target)
            break;
        
        prev=curr;
        curr=curr->next;
    }
    
    if( curr==nullptr)
        return;
    
    if(head == curr)
    {
        head = curr->next;
        delete curr;
        List<T>::size--;
    }
    else
    {
        prev->next = curr->next;
        delete curr;
        List<T>::size--;
    }
    
}

template <typename T> 
void Queue<T>::Clean()
{
    Node<T>* temp = head;
    while(List<T>::Size() > 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        List<T>::size--;
    }
    assert(List<T>::size == 0);
}