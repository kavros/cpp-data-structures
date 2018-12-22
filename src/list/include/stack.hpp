
#ifndef STACK_HPP
#define STACK_HPP
#include "node.hpp"
#include "list.hpp"

template<class T> 
class Stack:public List<T>
{
    public:
        void Insert(T val) override;
        
};

#endif /* STACK_HPP */

