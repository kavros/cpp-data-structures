#include <cppunit/extensions/HelperMacros.h>
#include <stdlib.h>
#include "../include/bst.hpp"
#include <string.h>

class BSTUnitTest:public CppUnit::TestFixture 
{
    
    CPPUNIT_TEST_SUITE(BSTUnitTest);
    CPPUNIT_TEST(testInsert);
    CPPUNIT_TEST(testRemove);
    CPPUNIT_TEST(testClean);
    CPPUNIT_TEST(testFind);
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
        
        
        void testRemove()
        {
            
           
        }
        
        void testClean()
        {
            
        }
        
        void testFind()
        {
            
            
        }
        
        
        
};

CPPUNIT_TEST_SUITE_REGISTRATION(BSTUnitTest);


