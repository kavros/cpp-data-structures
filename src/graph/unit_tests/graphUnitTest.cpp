#include <cppunit/extensions/HelperMacros.h>
#include <stdlib.h>
#include "../include/graph.hpp"

#include <string.h>
class GraphUnitTest:public CppUnit::TestFixture 
{
    
    CPPUNIT_TEST_SUITE(GraphUnitTest);
    CPPUNIT_TEST(TestAddEdge);
    CPPUNIT_TEST(TestAddNode);
    CPPUNIT_TEST(TestRemoveEdge);
    CPPUNIT_TEST(TestRemoveNode);
    CPPUNIT_TEST_SUITE_END();
    
    
    public:
        
        /* Initialise test suite - no-op. */
        void setUp() 
        {
            // No-op.
        }
        
        /* Clean up test suite - no-op. */
        void tearDown() 
        {
            // No-op.
        }
        
        void TestAddEdge()
        {
            Graph<std::string> myGraph;
            myGraph.AddNode("node1");
            myGraph.AddNode("node2");
            myGraph.AddEdge("node1","node2");
            CPPUNIT_ASSERT_EQUAL(myGraph.GetTotalNodes(),2);
            CPPUNIT_ASSERT_EQUAL(myGraph.GetTotalEdges(),1);
            
            
            myGraph.AddEdge("node3","node2");
            CPPUNIT_ASSERT_EQUAL(myGraph.GetTotalEdges(),1);
            
            myGraph.AddEdge("node2","node2");
            CPPUNIT_ASSERT_EQUAL(myGraph.GetTotalEdges(),2);
        }
        void TestAddNode()
        {
            Graph<std::string> myGraph;
            myGraph.AddNode("node1");
            myGraph.AddNode("node2");
            CPPUNIT_ASSERT_EQUAL(myGraph.GetTotalNodes(),2);
            
            
            Graph<float> myGraph2;
            myGraph2.AddNode(1.23);
            CPPUNIT_ASSERT_EQUAL(myGraph2.AddNode(1.23),false);
            CPPUNIT_ASSERT_EQUAL(myGraph2.GetTotalNodes(),1);
            
            
        }
        void TestRemoveNode()
        {
            Graph<std::string> myGraph;
            myGraph.AddNode("node1");
            myGraph.AddNode("node2");
            myGraph.RemoveNode("node2");
            CPPUNIT_ASSERT_EQUAL(myGraph.GetTotalNodes(),1);

        }
        void TestRemoveEdge( )
        {
            
            Graph<float> myGraph2;
            myGraph2.AddNode(1.23);
            myGraph2.AddNode(1.22);
            myGraph2.AddNode(1.24);
            myGraph2.AddNode(1.27);
            
            myGraph2.AddEdge(1.27,1.24);
            
            myGraph2.AddEdge(1.27,1.23);
            myGraph2.RemoveEdge(1.27,1.23);
            CPPUNIT_ASSERT_EQUAL(myGraph2.GetTotalEdges(),1);
            
        }    
};

CPPUNIT_TEST_SUITE_REGISTRATION(GraphUnitTest);
