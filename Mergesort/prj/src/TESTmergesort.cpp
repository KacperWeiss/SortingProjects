#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestMS

#include <boost/test/unit_test.hpp>
#include "../inc/mergesort.hpp"

struct myFixture{

    int length = 100;
    int *tab = new int[length];

    myFixture(){

        srand(time(nullptr));

        for(int i = 0; i < length; i++){
            tab[i] = rand();
        }

        mergeSort(tab, 0, length-1);

    }

};

struct myFixtureReverse{

    int length = 100;
    int *tab = new int[length];

    myFixtureReverse(){

        srand(time(nullptr));

        for(int i = 0; i < length; i++){
            tab[i] = rand();
        }

        mergeSortReverse(tab, 0, length-1);

    }

};

BOOST_FIXTURE_TEST_SUITE(MergeSortSuite, myFixture);

    BOOST_FIXTURE_TEST_CASE(simpleTest, myFixture){

        bool sorted = true;

        for(unsigned int i = 1; i < length; i++)
            if(tab[i-1] > tab[i])
                sorted = false;

        BOOST_CHECK_EQUAL(sorted, true);

    }

    BOOST_FIXTURE_TEST_CASE(inDepthTest, myFixture){

        for(unsigned int i = 1; i < length; i++){

            BOOST_REQUIRE_LE(tab[i-1], tab[i]);
        
        }

    }

BOOST_AUTO_TEST_SUITE_END();



BOOST_FIXTURE_TEST_SUITE(MergeSortReverseSuite, myFixtureReverse);

    BOOST_FIXTURE_TEST_CASE(simpleTest, myFixtureReverse){

        bool sorted = true;

        for(unsigned int i = 1; i < length; i++)
            if(tab[i-1] < tab[i])
                sorted = false;

        BOOST_CHECK_EQUAL(sorted, true);

    }

    BOOST_FIXTURE_TEST_CASE(inDepthTest, myFixtureReverse){

        for(unsigned int i = 1; i < length; i++){

            BOOST_REQUIRE_GE(tab[i-1], tab[i]);
        
        }

    }

BOOST_AUTO_TEST_SUITE_END();