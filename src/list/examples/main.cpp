#include <cstdlib>
#include "../src/queue.cpp"
using namespace std;

int main() 
{
    Queue<double> queue;
    queue.Insert(1.9f);
    queue.Insert(2.0f);
    printf ("queue size = %d \n", queue.Size());
    double* next;
    
    while( (next = queue.Remove()) != nullptr)
    {
        double* temp = next;
        printf ("delete element %f \n", *next);
        delete  temp;
    }
    printf ("queue size = %d \n", queue.Size());
    return 0;
}

