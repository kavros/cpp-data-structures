#include <cstdlib>
#include "../include/queue.hpp"
#include "../include/stack.hpp"
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
    return 0;
}

