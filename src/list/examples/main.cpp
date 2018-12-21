#include <cstdlib>
#include "../src/queue.cpp"
#include "../src/list.cpp"

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
    
    
    return 0;
}

