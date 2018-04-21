#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestQP

#include <boost/test/unit_test.hpp>
#include "../inc/presentation.hpp"



BOOST_AUTO_TEST_CASE(test_quickPresentation){

    BOOST_CHECK_MESSAGE(quickPresentation(), "Presentation failure.");

}