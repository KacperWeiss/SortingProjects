#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestP

#include <boost/test/unit_test.hpp>
#include "../inc/presentation.hpp"



BOOST_AUTO_TEST_CASE(test_program){

    BOOST_CHECK_MESSAGE(program(), "Program not exited properly.");

}