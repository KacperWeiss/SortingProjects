#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestAF

#include <boost/test/unit_test.hpp>
#include "../inc/additionalFunctions.hpp"



BOOST_AUTO_TEST_CASE(testShowMenu){

    BOOST_CHECK_MESSAGE(showMenu(), "failure in showMenu function");

}

BOOST_AUTO_TEST_CASE(testProgram){

    BOOST_CHECK_MESSAGE(program(), "program not exited properly");

}

