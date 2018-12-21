
#ifndef STACK_HPP
#define STACK_HPP

template<class T> 
class Stack:public List<T>
{
public:
    Stack();
    Stack(const Stack& orig);
    virtual ~Stack();
    
private:
    
};

#endif /* STACK_HPP */

