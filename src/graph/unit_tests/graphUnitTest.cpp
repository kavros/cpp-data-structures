#include <cppunit/extensions/HelperMacros.h>
#include <stdlib.h>
#include "../include/graph.hpp"

#include <string.h>
class GraphUnitTest:public CppUnit::TestFixture 
{
    
    CPPUNIT_TEST_SUITE(GraphUnitTest);
    CPPUNIT_TEST(testInsert);
    CPPUNIT_TEST_SUITE_END();
    
    public:
        
        /* Initialise test suite - no-op. */
        void setUp() 
        {
            // No-op.
        }
        
        /* Clean up test suite - no-op. */
        void tearDown() {
            // No-op.
        }
        
        void testInsert() 
        {
           
        }
        
};

CPPUNIT_TEST_SUITE_REGISTRATION(GraphUnitTest);
