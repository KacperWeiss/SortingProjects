#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestIS

#include <boost/test/unit_test.hpp>
#include "../inc/introsort.hpp"
#include <iostream>

struct myFixture{

    int length = 100;
    int *tab = new int[length];

    myFixture(){

        srand(time(nullptr));

        for(int i = 0; i < length; i++){
            tab[i] = rand();
        }

        introSortInit(tab, length);

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

        introSortReverseInit(tab, length);

    }

};

BOOST_FIXTURE_TEST_SUITE(IntroSortSuite, myFixture);

    BOOST_FIXTURE_TEST_CASE(simpleTest, myFixture){

        bool sorted = true;
        std::cout << tab[0] << std::endl;

        for(int i = 1; i < length; i++){

        std::cout << tab[i] << std::endl;
            if(tab[i-1] > tab[i])
                sorted = false;
            
        }

        BOOST_CHECK_EQUAL(sorted, true);

    }

    BOOST_FIXTURE_TEST_CASE(inDepthTest, myFixture){

        for(int i = 1; i < length; i++){

            BOOST_REQUIRE_LE(tab[i-1], tab[i]);
        
        }

    }

BOOST_AUTO_TEST_SUITE_END();



BOOST_FIXTURE_TEST_SUITE(IntroSortReverseSuite, myFixtureReverse);

    BOOST_FIXTURE_TEST_CASE(simpleTest, myFixtureReverse){

        bool sorted = true;
        std::cout << tab[0] << std::endl;

        for(int i = 1; i < length; i++){

            std::cout << tab[i] << std::endl;
            if(tab[i-1] < tab[i])
                sorted = false;
            
        }


        BOOST_CHECK_EQUAL(sorted, true);

    }

    BOOST_FIXTURE_TEST_CASE(inDepthTest, myFixtureReverse){

        for(int i = 1; i < length; i++){

            BOOST_REQUIRE_GE(tab[i-1], tab[i]);
        
        }

    }

BOOST_AUTO_TEST_SUITE_END();