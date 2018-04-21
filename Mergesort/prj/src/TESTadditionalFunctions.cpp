#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestAF

#include <boost/test/unit_test.hpp>
#include "../inc/additionalFunctions.hpp"



BOOST_AUTO_TEST_CASE(test_showMenu){

    BOOST_CHECK_MESSAGE(showMenu(), "Failure in showMenu function.");

}

struct myFixture{

    int length = 100;
    int *tab = new int[length];

    myFixture(){

        srand(time(nullptr));

        for(int i = 0; i < length; i++){
            tab[i] = rand();
        }

    }

};


BOOST_FIXTURE_TEST_SUITE(test_Basic_Functions, myFixture);

    BOOST_FIXTURE_TEST_CASE(test_ascendingMS, myFixture){

        ascendingMS(tab, length);

        for(int i = 1; i < length; i++)
            BOOST_CHECK_LE(tab[i-1], tab[i]);

    }

    BOOST_FIXTURE_TEST_CASE(test_descendingQS, myFixture){

        descendingMS(tab, length);

        for(int i = 1; i < length; i++)
            BOOST_CHECK_GE(tab[i-1], tab[i]);

    }

    BOOST_FIXTURE_TEST_CASE(test_addRandomValues, myFixture){

        int *tempTab;
        tempTab = tab;
        bool different = false; 

        addRandomValues(tab, 0, length);

        for(int i = 0; i < length; i++){
            different = different ? different : (tab[i] == tempTab[i]);
        }

        BOOST_CHECK_EQUAL(different, true);

    }

BOOST_AUTO_TEST_SUITE_END();