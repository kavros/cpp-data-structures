
#include "../include/graph.hpp"
#include <algorithm>    // std::find
#include<iterator> // for iterators 
#include <iostream>
#include<vector>
using namespace std;
template<typename T>
Graph<T>::Graph() 
{
   
}

template<typename T> bool Graph<T>::AddEdge(T u, T a)
{
    if(Find(u) == true && Find(a) == true)
    {
        int size = v.size();
        for( int i = 0; i < size; i++) 
        {
            if ( v[i].front() == u)
            {
                v[i].push_back(a);
                return true;
            }
        }
    
    }
    return false;
}


template<typename T> bool Graph<T>::AddNode(T val)
{
    bool isFound = Find(val);
    if ( isFound == true) return false;
    std::list<T> newList;
    newList.push_back(val);
    
    v.push_back(newList);
    
    return true;
}

template<typename T> void Graph<T>::Print()
{
    int totalSize = v.size();
    for( int i = 0; i < totalSize; i++) 
    {
        std::list<T> currList = v[i];
        
        for (typename std::list<T>::iterator it=currList.begin(); it != currList.end(); ++it)
        {
                std::cout << ' ' << *it;
        }

        std::cout<<std::endl;
    }
}


template<typename T> bool Graph<T>::Find(T val)
{
    int totalSize = v.size();
    for( int i = 0; i < totalSize; i++) 
    { 
        if ( v[i].front() == val)
        {   
            return true;
        }
    }
    return false;
}


template<typename T> bool Graph<T>::RemoveNode(T val )
{
    int totalSize = v.size();
    bool found = false;
    for( int i = 0; i < totalSize; i++) 
    {
        std::list<T> currList = v[i];
        
        if(v[i].front() == val) //delete node and all the edges
        {
            v.erase(v.begin()+i);
            
            found=true;
            continue;
        }
        //delete the rest edges from other nodes to the target node
        for (typename std::list<T>::iterator it=currList.begin(); it != currList.end(); ++it)
        {
            if(*it == val)
            {
                v[i].remove(*it);
            }
        }
    }
    
    return found;
}

template<typename T> bool Graph<T>::RemoveEdge(T val1, T val2 )
{
    int totalSize = v.size();
    for( int i = 0; i < totalSize; i++) 
    {
        std::list<T> currList = v[i];
        
        if(v[i].front() == val1) //delete node and all the edges
        {
            for (typename std::list<T>::iterator it=currList.begin(); it != currList.end(); ++it)
            {
                if(*it == val2)
                {
                    v[i].remove(*it);
                    return true;
                }
            }
        }
        
    }
    
    return false;
}

template<typename T> int Graph<T>::GetTotalNodes()
{
    
    return v.size();
}
   
template<typename T> int Graph<T>::GetTotalEdges()
{
    int totalEdges=0;
    int totalNodes = v.size();
    for( int i = 0; i < totalNodes; i++) 
    {
         totalEdges = totalEdges+(v[i].size()-1);
    }
    return totalEdges;
}


template<typename T> void Graph<T>::BFS()
{
    
}
template<typename T> void Graph<T>::DFS()
{
    
}

template<typename T> Graph<T>::~Graph() 
{
    
  
}

template class Graph<double>;
template class Graph<int>;
template class Graph<float>;
template class Graph<string>;
