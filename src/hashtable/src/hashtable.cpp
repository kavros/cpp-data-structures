
#include "../include/hashtable.hpp"
#include <string>
template<typename K, typename V>
Hashtable<K,V>::Hashtable()
{
    
}

template<typename K, typename V>
Hashtable<K,V>::~Hashtable() 
{
    
}


template<typename K, typename V>
void Hashtable<K,V>::Insert(K key,V value)
{
    
}

template<typename K, typename V>
V Hashtable<K,V>::Find(K key)
{
    
}

template<typename K, typename V>
bool Hashtable<K,V>::Remove(K key, V value)
{
    
}

template<typename K, typename V>
bool Hashtable<K,V>::Remove(K key)
{
    
}

template<typename K, typename V>
int Hashtable<K,V>::Size()
{
    
}

template<typename K, typename V>
void Hashtable<K,V>::Print()
{
    
}

template<typename K, typename V>
void Hashtable<K,V>::Clean()
{
    
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

template class Hashtable<std::string,int>;
template class Hashtable<std::string,double>;
template class Hashtable<std::string,float>;
template class Hashtable<std::string,std::string>;