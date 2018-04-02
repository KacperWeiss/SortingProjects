#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestQS

#include <boost/test/unit_test.hpp>
#include "../inc/quicksort.hpp"


struct myFixture{

    myFixture(){

        srand(time(nullptr));

        for(int i = 0; i < 100; i++)
            elems.push_back(rand());

        quickSort(elems, 0, elems.size());

    }

    std::vector<int> elems;

};

struct myFixtureReverse{

    myFixtureReverse(){

        srand(time(nullptr));

        for(int i = 0; i < 100; i++)
            elems.push_back(rand());

        quickSortReverse(elems, 0, elems.size());

    }

    std::vector<int> elems;

};

BOOST_FIXTURE_TEST_SUITE(QuickSortSuite, myFixture);

    BOOST_FIXTURE_TEST_CASE(simpleTest, myFixture){

        bool sorted = true;

        for(unsigned int i = 1; i < elems.size(); i++)
            if(elems[i-1] > elems[i])
                sorted = false;

        BOOST_CHECK_EQUAL(sorted, true);

    }

    BOOST_FIXTURE_TEST_CASE(inDepthTest, myFixture){

        for(unsigned int i = 1; i < elems.size(); i++){

            BOOST_REQUIRE_LE(elems[i-1], elems[i]);
        
        }

    }

BOOST_AUTO_TEST_SUITE_END();



BOOST_FIXTURE_TEST_CASE(testSwap, myFixture){

    int i = 0, j = 1;
    int temp1 = elems[i], temp2 = elems[j];

    qsSwap(elems, i, j);

    BOOST_CHECK_EQUAL(temp1, elems[j]);
    BOOST_CHECK_EQUAL(temp2, elems[i]);

}

BOOST_FIXTURE_TEST_SUITE(QuickSortReverseSuite, myFixtureReverse);

    BOOST_FIXTURE_TEST_CASE(simpleTest, myFixtureReverse){

        bool sorted = true;

        for(unsigned int i = 1; i < elems.size(); i++)
            if(elems[i-1] < elems[i])
                sorted = false;

        BOOST_CHECK_EQUAL(sorted, true);

    }

    BOOST_FIXTURE_TEST_CASE(inDepthTest, myFixtureReverse){

        for(unsigned int i = 1; i < elems.size(); i++){

            BOOST_REQUIRE_GE(elems[i-1], elems[i]);
        
        }

    }

BOOST_AUTO_TEST_SUITE_END();