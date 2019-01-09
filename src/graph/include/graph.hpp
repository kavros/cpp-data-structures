/**
 * An implementation of a directed unweighted graph
 * using adjacent list structure.
 */
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <vector>
template<typename T> class Graph 
{
public:
    
    Graph();
    /**
     * Adds a directed edge from node u to node v.
     * @param u
     * @param v
     */
    bool AddEdge(T u, T v);
    bool AddNode(T val);
    bool RemoveNode(T val );
    /**
     * Removes an edge that points from val1 to val2.
     * Return true if edge is found and false otherwise.
     * @param val1
     * @param val2
     * @return 
     */
    bool RemoveEdge(T val1, T val2 );
    
    void BFS();
    void DFS();
    void Print();
    virtual ~Graph();



    
    
private:
    bool Find(T val);
    
    std::vector<std::list<T>> v;
    
    
};



#endif /* GRAPH_HPP */

