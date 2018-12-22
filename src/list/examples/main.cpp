#include <cstdlib>
#include "../include/queue.hpp"
#include "../include/stack.hpp"
#include <assert.h>
using namespace std;
int main() 
{
    Queue<float> queue;
    queue.Insert(1.9f);
    queue.Insert(2.0f);
    queue.Print();
    queue.List<float>::Remove(1.93f);
    queue.Print();
    printf ("queue size = %d \n", queue.Size());
    float* next;
    while( (next = queue.Remove()) != nullptr)
    {
        float* temp = next;
        printf ("delete element %f \n", *next);
        delete  temp;
    }
    printf ("queue size = %d \n", queue.Size());
    
    Stack<float> stack;
    stack.Insert(10.0f);
    stack.Insert(11.0f);
    stack.Insert(12.0f);
    stack.Print();
    while( (next = stack.Remove()) != nullptr)
    {
        float* temp = next;
        printf ("delete element %f \n", *next);
        delete  temp;
    }
    
    
    Stack<std::string> stack2;
    stack2.Insert("Alex");
    stack2.Insert("Antonis");

    assert(stack2.Find("Antonis")==true);
    assert(stack2.Find("Antonis2")==false); 
    assert(stack2.Size()==2);
    stack2.Print();

    return 0;
}

