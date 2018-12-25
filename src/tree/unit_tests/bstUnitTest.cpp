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
            BST<int> bst;
            int array[] = {4,8,4,7,2,9};
            for(int i =0; i < 6; i++)
            {
                bst.Insert(array[i]);
            }
            CPPUNIT_ASSERT_EQUAL(bst.Size(),6);
            CPPUNIT_ASSERT_EQUAL(bst.Find(4)->key,4);
            
        }
        
        
        void testRemove()
        {
            BST<int> bst;
            int array[] = {4,3,5,1,2,6};
            for(int i =0; i < 6; i++)
            {
                bst.Insert(array[i]);
            }
            
            CPPUNIT_ASSERT_EQUAL(bst.Remove(4),true);

            CPPUNIT_ASSERT_EQUAL(bst.Size(),5);            
            CPPUNIT_ASSERT_EQUAL(bst.Remove(5),true);

            CPPUNIT_ASSERT_EQUAL(bst.Remove(-5),false);
            CPPUNIT_ASSERT_EQUAL(bst.Size(),4);
            
            CPPUNIT_ASSERT_EQUAL(bst.Remove(6),true);

            CPPUNIT_ASSERT_EQUAL(bst.Size(),3);
            
            CPPUNIT_ASSERT_EQUAL(bst.Remove(1),true);

            CPPUNIT_ASSERT_EQUAL(bst.Size(),2);
            
        }
        
        void testClean()
        {
            BST<int> bst;
            int array[] = {4,8,4,7,2,9};
            for(int i =0; i < 6; i++)
            {
                bst.Insert(array[i]);
            }
            bst.Destroy();
        }
        
        void testFind()
        {
            BST<int> bst;
            int array[] = {4,8,4,7,2,9};
            for(int i =0; i < 6; i++)
            {
                bst.Insert(array[i]);
            }
            CPPUNIT_ASSERT_EQUAL(bst.Find(4)->key,4);
            CPPUNIT_ASSERT_EQUAL(bst.Find(8)->key,8);
            CPPUNIT_ASSERT_EQUAL(bst.Find(9)->key,9);
            
            
        }
        
        
        
};

CPPUNIT_TEST_SUITE_REGISTRATION(BSTUnitTest);


