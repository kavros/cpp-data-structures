#include <stddef.h>
#include <iostream>
#include "../include/bst.hpp"
#include <assert.h>
template<typename T> 
BST<T>::BST() 
{
    root = nullptr;
    size=0;
}

template<typename T> 
BST<T>::~BST() 
{
}

template<typename T> 
void BST<T>::Insert(T key)
{
    BSTNode<T>* newNode = CreateNode(key);
    if(root == nullptr)
    {
        root=newNode;
        size++;
        return;
    }
    
    BSTNode<T>* curr = root;
    BSTNode<T>* prev = nullptr;
    while(curr!=nullptr)
    {
        if(newNode->key < curr->key)
        {
            prev=curr;
            curr=curr->left;
        }
        else
        {
            prev=curr;
            curr=curr->right;
        }
            
    }
    if(  newNode->key > prev->key )
    {
        prev->right = newNode;
        newNode->parent = prev;
    }
    else
    {
        prev->left = newNode;
        newNode->parent = prev;
    }
            
    size++;    
}

template<typename T> 
bool BST<T>::Remove(T key)
{
    BSTNode<T>* target= Find(key);
    if(target == nullptr)
        return false;
    
    // case: target node has no children
    if(target->left == nullptr && target->right == nullptr)
    {
        BSTNode<T>* parent = target->parent;
        
        if(target != root)
        {
            // deletes index of the node
            if( parent->left != nullptr && parent->left->key == key)
            {
                parent->left = nullptr;
            }
            else if(  parent->right != nullptr && parent->right->key == key)
            {
                parent->right = nullptr;
            }
        }
        else
        {
            root = nullptr;
        }
            
        // delete node 
        delete target;
        size--;

    }
    
    // case: target node has two children
    if(target->left != nullptr && target->right != nullptr)
    {
        
        // find min at the right subtree
        BSTNode<T>* min = FindMin(target->right);
        assert(min);
        
        /*T targetVal = target->key;
        target->key = min->key;
        min->key = targetVal;
        assert(Find(targetVal));
        Remove(targetVal);*/
        return true;
    }
    
    // case: target node has one children
    if(target->left != nullptr || target->right != nullptr)
    {
        
        BSTNode<T>* child;
        BSTNode<T>* parent=target->parent;
        
        // assign child node 
        if(target->left != nullptr )
            child = target->left;
        else
            child = target->right;
        
        if(target != root)
        {
            if( parent->left != nullptr && parent->left->key == key )
            {
                parent->left = child;
            }
            else if( parent->right != nullptr && parent->right->key == key )
            {
                parent->right = child;
            }
        }
        else
        {
            root=child;
        }
        
        delete target;
        size--;
        
    }    
    
    return true;    
}
    

template<typename T> 
BSTNode<T>* BST<T>::FindMin(BSTNode<T>* node)
{
    BSTNode<T>* curr = node;
    BSTNode<T>* prev = curr;
    while(curr != nullptr)
    {
        prev = curr;
        curr = curr->left;
    }
    return prev;
        
}

template<typename T> 
BSTNode<T>* BST<T>::Find(T key)
{
    BSTNode<T>* curr = root;
    while(curr!=nullptr)
    {
        if(key < curr->key)
        {
            curr=curr->left;
        }
        else if(key > curr->key)
        {
            curr=curr->right;
        }
        else
        {
            return curr;
        }
    } 
    return nullptr;
}

template<typename T> 
void BST<T>::Print()
{
    InOder(root);
}

template<typename T> 
void BST<T>::InOder(BSTNode<T>* node)
{
    if(node == nullptr)
        return;
    InOder(node->left);
    std::cout<<node->key<<std::endl;
    InOder(node->right);   
}



template<typename T> 
void BST<T>::Destroy()
{
    
}

template<typename T> 
int BST<T>::Size()
{
    return size;
}

template<typename T> 
BSTNode<T>* BST<T>::CreateNode(T val)
{
    BSTNode<T>* newNode = new BSTNode<T>();
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    newNode->key = val;
   return newNode;
}

// fix undefined reference
template class BST<float>;
template class BST<int>;
template class BST<double>;
