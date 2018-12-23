#include <cstdlib>
#include "../include/hashtable.hpp"
#include <iostream>

using namespace std;

int main() {
    Hashtable<double,double> hashtable;
    hashtable.Insert(5,5);
    hashtable.Insert(5,10);
    hashtable.Insert(5,50);
    hashtable.Insert(15,5);
    
    hashtable.Print();
    double* a = hashtable.Find(105);
    if(a!=nullptr)
        cout<<*a<<endl;
    cout<<"delete key:5"<<endl;
    hashtable.Remove(5,10);    
    hashtable.Remove(5,50);
    
    hashtable.Print();
    cout<<"Clean hashtable"<<endl;
    hashtable.Clean();
    hashtable.Print();
    cout<<"Add values"<<endl;
    hashtable.Insert(15,5);
    hashtable.Insert(25,10);
    hashtable.Print();
    
    return 0;
}


