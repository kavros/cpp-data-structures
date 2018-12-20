
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "node.hpp"
#include "list.hpp"

template<class T> 
class Queue:public List<T> 
{
public:
    Queue();   
    virtual ~Queue();
    
    void Print()  override;
    void Insert(T val) override;
    T* Remove() override;
    void Remove(T target) override;
    
private:
    struct Node<T>* last;
    struct Node<T>* head;
};

#endif /* QUEUE_HPP */

