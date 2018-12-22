#include <cppunit/extensions/HelperMacros.h>
#include <stdlib.h>
#include "../include/stack.hpp"
#include "../include/list.hpp"
#include <string.h>

class StackUnitTest:public CppUnit::TestFixture 
{
    
    CPPUNIT_TEST_SUITE(StackUnitTest);
    CPPUNIT_TEST(testInsert);
    CPPUNIT_TEST(testRemove);
    CPPUNIT_TEST(testClean);
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
            Stack<std::string> stack;
            stack.Insert("Alex");
            stack.Insert("Antonis");
            
            CPPUNIT_ASSERT_EQUAL(stack.Size(),2);
           
        }
        
        
        void testRemove()
        {
            
            Stack<std::string> stack;
            stack.Insert("Alex");
            stack.Insert("Antonis");
            
            stack.Remove("Antonis");
            CPPUNIT_ASSERT_EQUAL(stack.Size(),1);
           
        }
        
        void testClean()
        {
            Stack<std::string> stack;
            stack.Insert("Alex");
            stack.Insert("Antonis");
            
            stack.Clean();
            
            CPPUNIT_ASSERT_EQUAL(stack.Size(),0);
        }
        
        
        
};

CPPUNIT_TEST_SUITE_REGISTRATION(StackUnitTest);

