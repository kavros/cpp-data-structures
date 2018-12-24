#ifndef BST_HPP
#define BST_HPP

template<typename T> class BSTNode
{
    T Key;
    BSTNode<T>* parent;
    BSTNode<T>* left;
    BSTNode<T>* right;
};

template<typename T> class BST
{
public:
    BST();
    
    virtual ~BST();
    void Insert(T key);
    bool Remove(T key);
    BSTNode<T>* Find(T key);
    void Print();
    void Destroy();
    
private:
    BSTNode<T>* root;
    int size;
};

#endif /* BST_HPP */

