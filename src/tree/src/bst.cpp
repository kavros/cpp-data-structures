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
    Destroy();
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
    {
        //std::cout<<"\n Key: "<< key <<" is not in bst\n"<<std::endl;
        return false;
    }
    
    // case: target node has two children
    if(target->left != nullptr && target->right != nullptr)
    {
        // find min at the right subtree and swap it with the target node
        //std::cout<<"\n Delete Key: "<< target->key <<" \n"<<std::endl;
        
        BstNodeSwap(&target);

        assert(target->left == nullptr || target->right == nullptr );
    }
    
    
    // case: target node has no children
    if(target->left == nullptr && target->right == nullptr)
    {
        BSTNode<T>* parent = target->parent;
        
        if(target != root)
        {
            // deletes index which connect node with parent
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
        
        //assign new parent node to child
        child->parent= parent;
        
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
void BST<T>::BstNodeSwap(BSTNode<T>** target)
{
    BSTNode<T>* curr = (*target)->right;
    BSTNode<T>* swapNode = curr;
    while(curr != nullptr)
    {
        swapNode = curr;
        curr = curr->left;
    }
    
    T targetVal = (*target)->key;
    (*target)->key = swapNode->key;
    swapNode->key = targetVal;

    *target = swapNode;
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
    std::cout<<std::endl;
}

template<typename T> 
void BST<T>::InOder(BSTNode<T>* node)
{
    if(node == nullptr)
        return;
    InOder(node->left);
    std::cout<<node->key; 
    if(node!=root)
        std::cout<<",parent:"<<node->parent->key<<std::endl;
    else
        std::cout<<std::endl;
    InOder(node->right);   
}



template<typename T> 
void BST<T>::Destroy()
{
    while(Size() != 0)
        Remove(root->key);
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
