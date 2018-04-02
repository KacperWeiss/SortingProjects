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

        sorted = true;

        for(unsigned int i = 1; i < elems.size(); i++)
            if(elems[i-1] <= elems[i]);
                sorted = false;

    }

    std::vector<int> elems;
    bool sorted;

};

BOOST_FIXTURE_TEST_CASE(testSort, myFixture){

    BOOST_CHECK_EQUAL(sorted, true);

}