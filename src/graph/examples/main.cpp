#include <cstdlib>
#include "../include/graph.hpp"
#include <assert.h>
using namespace std;

int main() {
    Graph<int> myGraph;
    myGraph.AddNode(5);
    myGraph.AddNode(15);
    myGraph.AddNode(35);
    myGraph.AddNode(7);
    myGraph.AddEdge(7,35);
    myGraph.AddEdge(35,5);
    myGraph.AddEdge(35,7);
    myGraph.AddEdge(35,15);
    myGraph.AddEdge(15,7);
    myGraph.RemoveEdge(15,7);
    myGraph.Print();
    myGraph.RemoveNode(35);
    myGraph.Print();
    return 0;
}

