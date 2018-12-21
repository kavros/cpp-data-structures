#include <cppunit/extensions/HelperMacros.h>
#include <stdlib.h>
#include "../src/queue.cpp"
#include <string.h>
class QueueUnitTest:public CppUnit::TestFixture 
{
    
    CPPUNIT_TEST_SUITE(QueueUnitTest);
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
            Queue<int> queue ;
            queue.Insert(4);
            queue.Insert(5);
            int* a = (queue.Remove());
            CPPUNIT_ASSERT_EQUAL(*a, 4);
            delete a;
            int *b = (queue.Remove());
            CPPUNIT_ASSERT_EQUAL(*b, 5);
            delete b;
        }
        
        
        void testRemove()
        {
            Queue<int> queue;
            CPPUNIT_ASSERT_EQUAL(queue.Size(), 0);
            queue.Remove();
            CPPUNIT_ASSERT_EQUAL(queue.Size(), 0);
            queue.Insert(19);
            queue.Insert(20);
            queue.Insert(25);
            int*a = queue.Remove();
            CPPUNIT_ASSERT_EQUAL(*a, 19);
            delete a;
            
            queue.Remove(200);
            CPPUNIT_ASSERT_EQUAL(queue.Size(), 2);
            
            queue.Remove(20);
            queue.Remove(25);
            CPPUNIT_ASSERT_EQUAL(queue.Size(), 0);            
            
        }
        
        void testClean()
        {
            Queue<std::string> queue;
            queue.Insert("Hello");
            std::string* str = queue.Remove();
            std::string str2 = "Hello";
            CPPUNIT_ASSERT_EQUAL(*str,str2);
            delete str;
            
            queue.Clean();
            CPPUNIT_ASSERT_EQUAL(queue.Size(),0);
        }
        
        
        
};

CPPUNIT_TEST_SUITE_REGISTRATION(QueueUnitTest);
