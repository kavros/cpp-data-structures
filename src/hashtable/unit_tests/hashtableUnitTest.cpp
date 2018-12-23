#include <cppunit/extensions/HelperMacros.h>
#include "../include/hashtable.hpp"
#include <stdlib.h>
#include <string.h>

class HashTableUnitTest:public CppUnit::TestFixture 
{
    
    CPPUNIT_TEST_SUITE(HashTableUnitTest);
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

CPPUNIT_TEST_SUITE_REGISTRATION(HashTableUnitTest);

