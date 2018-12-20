
#ifndef LIST_HPP
#define LIST_HPP
#include "node.hpp"
template<typename T> class List
{
public:
    
    int Size()
    {
        return size;
    }
    
    virtual void Print() = 0;
    virtual void Insert(T val) = 0;
    virtual T* Remove() = 0;
    virtual void Remove(T target) = 0;
protected:
    int size;
};


#endif /* LIST_HPP */

