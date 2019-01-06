#ifndef GRAPH_HPP
#define GRAPH_HPP

template<typename T> class Graph 
{
public:
    Graph();

    virtual ~Graph();
private:
    int* nodes;
};


template<typename T> class Node
{
    public:
        Node* children;
        T name;
};

#endif /* GRAPH_HPP */

