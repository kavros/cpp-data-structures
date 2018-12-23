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
            Hashtable<double,double> hashtable;
            hashtable.Insert(5,5);
            hashtable.Insert(5,10);
            hashtable.Insert(5,50);
            hashtable.Insert(15,5);
            
            CPPUNIT_ASSERT_EQUAL(hashtable.Size(),4);
            
        }
        
        
        void testRemove()
        {
            Hashtable<double,double> hashtable;
            hashtable.Insert(5,5);
            hashtable.Insert(5,10);
            hashtable.Insert(5,50);
            hashtable.Insert(15,5);            
            CPPUNIT_ASSERT_EQUAL(hashtable.Size(),4);
            hashtable.Remove(15,5);
            CPPUNIT_ASSERT_EQUAL(hashtable.Size(),3);
            double* val=hashtable.Find(15);
            double* null_val =nullptr;
            CPPUNIT_ASSERT_EQUAL(val,null_val);
        }
        
        void testClean()
        {
            Hashtable<double,int> hashtable;
            hashtable.Insert(5,10);
            hashtable.Insert(5,50);
            hashtable.Insert(15,5);
            hashtable.Clean();
            CPPUNIT_ASSERT_EQUAL(hashtable.Size(),0);
        }
        
        void testFind()
        {
            Hashtable<double,int> hashtable;
            hashtable.Insert(5,10);
            hashtable.Insert(5,50);
            hashtable.Insert(15,5);
            int*val =  hashtable.Find(15);
            CPPUNIT_ASSERT_EQUAL(*val,5);
        }
        
        
        
};

CPPUNIT_TEST_SUITE_REGISTRATION(HashTableUnitTest);

