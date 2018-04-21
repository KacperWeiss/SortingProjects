# compiler settings
CPP = g++ -Wall -pedantic -std=c++17 -c -g -Iinc
BOOST = -lboost_system -lboost_filesystem
TEST_CPP = g++ -std=c++17 -c -g
TEST = -lboost_unit_test_framework

__START__: clear QuickSort
	./QuickSort

QuickSort: prj/obj prj/obj/main.o prj/obj/logger.o
	g++ prj/obj/main.o prj/obj/logger.o -o QuickSort ${BOOST}

prj/obj:
	mkdir prj/obj

prj/obj/main.o: prj/main.cpp prj/inc/quicksort.hpp prj/inc/quicksorthelpers.hpp prj/inc/additionalFunctions.hpp prj/inc/presentation.hpp prj/inc/program.hpp 
	${CPP} prj/main.cpp -o prj/obj/main.o

prj/obj/logger.o: ../MyLoggerClass/inc/logger.hpp
	${CPP} ../MyLoggerClass/src/logger.cpp -o prj/obj/logger.o ${BOOST}

clear:
	rm -rf prj/obj logs

clearObj:
	rm -rf prj/obj

clearLogs:
	rm -rf logs

run_all_tests: testQS_run testAF_run testQP_run testP_run

presentation: testQP_run

testQS_run: testQS
	./testQS --log_level=test_suite

testAF_run: testAF
	./testAF --log_level=test_suite

testQP_run: clearLogs testQP
	./testQP --log_level=test_suite

testP_run: testP
	./testP --log_level=test_suite	

testQS: prj/obj prj/inc/quicksort.hpp prj/inc/quicksorthelpers.hpp prj/src/TESTquicksort.cpp
	${TEST_CPP} -o prj/obj/TESTquicksort.o prj/src/TESTquicksort.cpp ${TEST}
	g++ -o testQS prj/obj/TESTquicksort.o ${TEST}

testAF: prj/obj prj/inc/quicksort.hpp prj/inc/quicksorthelpers.hpp prj/inc/additionalFunctions.hpp prj/src/TESTadditionalFunctions.cpp
	${TEST_CPP} -o prj/obj/TESTadditionalFunctions.o prj/src/TESTadditionalFunctions.cpp ${TEST}
	g++ -o testAF prj/obj/TESTadditionalFunctions.o ${TEST}

testQP: prj/obj prj/inc/quicksort.hpp prj/inc/quicksorthelpers.hpp prj/inc/presentation.hpp prj/obj/logger.o prj/src/TESTpresentation.cpp
	${TEST_CPP} -o prj/obj/TESTpresentation.o prj/src/TESTpresentation.cpp ${TEST}
	g++ -o testQP prj/obj/TESTpresentation.o prj/obj/logger.o ${BOOST} ${TEST}

testP: prj/obj prj/inc/quicksort.hpp prj/inc/quicksorthelpers.hpp prj/inc/presentation.hpp prj/inc/program.hpp prj/src/TESTprogram.cpp
	${TEST_CPP} -o prj/obj/TESTprogram.o prj/src/TESTprogram.cpp ${TEST}
	g++ -o testP prj/obj/TESTprogram.o prj/obj/logger.o ${BOOST} ${TEST}
