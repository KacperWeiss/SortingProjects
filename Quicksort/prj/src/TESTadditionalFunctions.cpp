#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestAF

#include <boost/test/unit_test.hpp>
#include "../inc/additionalFunctions.hpp"



BOOST_AUTO_TEST_CASE(test_showMenu){

    BOOST_CHECK_MESSAGE(showMenu(), "Failure in showMenu function.");

}

struct myFixture{

    myFixture(){

        srand(time(nullptr));

        for(int i = 0; i < 100; i++)
            elems.push_back(rand());

    }

    std::vector<int> elems;

};


BOOST_FIXTURE_TEST_SUITE(test_Basic_Functions, myFixture);

    BOOST_FIXTURE_TEST_CASE(test_ascendingQS, myFixture){

        ascendingQS(elems);
        bool sorted = true;

        for(int i = 1; i < elems.size(); i++)
            BOOST_CHECK_LE(elems[i-1], elems[i]);

    }

    BOOST_AUTO_TEST_CASE(test_Ascending_if_elems_are_empty){

        std::vector<int> elems;
        BOOST_REQUIRE_EQUAL(ascendingQS(elems), false);

    }

    BOOST_FIXTURE_TEST_CASE(test_descendingQS, myFixture){

        descendingQS(elems);
        bool sorted = true;

        for(int i = 1; i < elems.size(); i++)
            BOOST_CHECK_GE(elems[i-1], elems[i]);

    }

    BOOST_AUTO_TEST_CASE(test_Descending_if_elems_are_empty){

        std::vector<int> elems;
        BOOST_REQUIRE_EQUAL(descendingQS(elems), false);

    }

    BOOST_FIXTURE_TEST_CASE(test_addRandomValues, myFixture){

        addRandomValues(elems, 100);
        BOOST_CHECK_EQUAL(elems.size(), 200);

    }

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_CASE(test_quickPresentation){

    BOOST_CHECK_MESSAGE(quickPresentation(), "Presentation failure.");

}

BOOST_AUTO_TEST_CASE(test_program){

    BOOST_CHECK_MESSAGE(program(), "Program not exited properly.");

}