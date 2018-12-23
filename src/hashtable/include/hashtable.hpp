
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

template<typename K, typename V>
class HashNode
{
public:
    K key;
    V value;
    HashNode* next;
};

template<typename K, typename V>
class Hashtable {
public:
    Hashtable();
    virtual ~Hashtable();
    
    
    void Insert(K key,V value);
    V* Find(K key);
    bool Remove(K key, V value);
    int Size();
    void Print();
    void Clean();
    
private:
    HashNode<K,V>** array;
    int size;
    int arrayPositions;
    int HashCode(K key);
};

#endif /* HASHTABLE_HPP */

