
#include "../include/hashtable.hpp"
#include <string>
#include <iostream>
#include <string.h>
template<typename K, typename V>
Hashtable<K,V>::Hashtable()
{
    // initialize array size
    size=0;
    
    // allocates 100 positions
    arrayPositions = 100;
    this->array = new HashNode<K,V>*[arrayPositions];
    
    // initialize array with null pointers
    for(int i=0; i < arrayPositions; i++ )
    {
        array[i] = nullptr;
    }
    
}

template<typename K, typename V>
Hashtable<K,V>::~Hashtable() 
{
    Clean();
    delete array;
}


template<typename K, typename V>
void Hashtable<K,V>::Insert(K key,V value)
{
    int pos = HashCode(key);
    HashNode<K,V>* hashNode = new HashNode<K,V>;
    hashNode->key = key;
    hashNode->value = value;
    hashNode->next = nullptr;
    
    if(array[pos] == nullptr)
    {
        array[pos] = hashNode;
    }
    else
    {
        hashNode->next = array[pos];
        array[pos] = hashNode;
    }
    size++;
}

template<typename K, typename V>
V* Hashtable<K,V>::Find(K key)
{
    int pos = HashCode(key);
    HashNode<K,V>* curr = array[pos];
    while(curr != nullptr)
    {
        if(curr->key == key)
        {
            return &(curr->value);
        }
        curr = curr->next;
    }
    return nullptr;
}

/**
 * Delete the first node with the given pair of key, value.
 * @param key
 * @param value
 * @return 
 */ 
template<typename K, typename V>
bool Hashtable<K,V>::Remove(K key, V value)
{
   int pos = HashCode(key);
    HashNode<K,V>* curr = array[pos];
    HashNode<K,V>* prev = nullptr;
    
    while(curr != nullptr )
    {
        if(curr->key == key &&  curr->value == value)
        {
            
            HashNode<K,V>* toDelete =curr;
            if(prev!=nullptr)
                prev->next = curr->next;
            else
                array[pos] = curr->next;
            curr = curr->next;
            
            delete toDelete;
            size--;
            return true;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}


template<typename K, typename V>
int Hashtable<K,V>::Size()
{
    return size;
    
}

template<typename K, typename V>
void Hashtable<K,V>::Print()
{
    for(int i=0; i < arrayPositions; i++ )
    {
        if(array[i]!= nullptr)
        {
            std::cout<< i<<": ("<<array[i]->key<<","<<array[i]->value<<")"<<  std::endl; 
            HashNode<K,V>* next = array[i]->next;
            while(next != nullptr)
            {
                std::cout<< i<<": ("<<next->key<<","<<next->value<<")"<<  std::endl; 
                next = next->next;
            }
        }
        
    }
}

template<typename K, typename V>
void Hashtable<K,V>::Clean()
{
     for(int i=0; i < arrayPositions; i++ )
    {
        HashNode<K,V>* curr = array[i];
        while(curr != nullptr)
        {
            HashNode<K,V>* toDelete = curr;
            delete toDelete;
            curr = curr->next;
        }
        array[i] = nullptr;
    }
     size=0;
    
}

template<typename K, typename V>
int Hashtable<K,V>::HashCode(K key)
{
    int pos = 0;
    if( strcmp(typeid(key).name(),"d") == 0 ||
        strcmp(typeid(key).name(),"i") == 0 ||
        strcmp(typeid(key).name(),"f") == 0 )
    {
        int key_int = (int)key;
        pos = key_int%arrayPositions;
    }
    
    
    return pos;
}

// fix compile error with undefined reference
template class Hashtable<float,float>;
template class Hashtable<float,int>;
template class Hashtable<float,double>;
template class Hashtable<float,std::string>;

template class Hashtable<int,int>;
template class Hashtable<int,float>;
template class Hashtable<int,double>;
template class Hashtable<int,std::string>;


template class Hashtable<double,double>;
template class Hashtable<double,float>;
template class Hashtable<double,int>;
template class Hashtable<double,std::string>;

