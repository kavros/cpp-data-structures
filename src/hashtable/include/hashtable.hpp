
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

template<typename K, typename V>
class HashNode
{
    K key;
    V value;
};

template<typename K, typename V>
class Hashtable {
public:
    Hashtable();
    virtual ~Hashtable();
    
    
    void Insert(K key,V value);
    V Find(K key);
    bool Remove(K key, V value);
    bool Remove(K key);
    int Size();
    void Print();
    void Clean();
    
private:
    HashNode<K,V>** arr;
    int size;
    
    int HashCode(K key);
};

#endif /* HASHTABLE_HPP */

