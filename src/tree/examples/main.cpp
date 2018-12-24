#include <cstdlib>
#include "../include/bst.hpp"
#include <iostream>
using namespace std;

int main()
{
    BST<int> bst;
    int array[] = {4,3,5,1,2,6};
    for(int i =0; i < 6; i++)
    {
        bst.Insert(array[i]);
    }
    bst.Print();
    
    
    
    bst.Remove(5);
    bst.Print();
    
    return 0;
}

