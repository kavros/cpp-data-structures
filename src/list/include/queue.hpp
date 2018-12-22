
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "node.hpp"
#include "list.hpp"

template<class T> 
class Queue:public List<T> 
{
public: 
  
    void Insert(T val) override;
};

#endif /* QUEUE_HPP */

