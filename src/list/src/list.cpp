
#include "../include/list.hpp"

template <typename T> 
List<T>::List() 
{
    List<T>::last=nullptr;  
    List<T>::head=nullptr;  
    List<T>::size = 0;
}

template <typename T> 
List<T>::~List() 
{
    List<T>::Clean();
}


template <typename T> 
int List<T>::Size()
{
    return size;
}

template <typename T> 
void List<T>::Print() 
{
    Node<T>* temp = List<T>::head;
    while(temp != nullptr)
    {
        std::cout<< temp->val << std::endl;
        temp = temp->next;
    }
}

template <typename T> 
void List<T>::Clean()
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

template <typename T> 
void List<T>::Remove(T target)
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
T* List<T>::Remove()
{
    if(List<T>::size == 0) return nullptr;
    T* valPtr = new T;
    *valPtr  = List<T>::head->val;
    
    Node<T>* target = List<T>::head;
    List<T>::head = List<T>::head->next;
    delete target;    
    List<T>::size--;
    
    return valPtr;
}

