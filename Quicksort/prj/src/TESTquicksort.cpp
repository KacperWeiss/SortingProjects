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


BOOST_FIXTURE_TEST_CASE(testQuickSort, myFixture){

    bool sorted = true;

    for(unsigned int i = 1; i < elems.size(); i++)
        if(elems[i-1] <= elems[i]);
            sorted = false;

    BOOST_CHECK_EQUAL(sorted, true);

}

BOOST_FIXTURE_TEST_CASE(testSwap, myFixture){

    int i = 0, j = 1;
    int temp1 = elems[i], temp2 = elems[j];

    qsSwap(elems, i, j);
    
    BOOST_CHECK_EQUAL(temp1, elems[j]);
    BOOST_CHECK_EQUAL(temp2, elems[i]);

}