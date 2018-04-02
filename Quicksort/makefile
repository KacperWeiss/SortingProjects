# compiler settings
CPP = g++ -Wall -pedantic -std=c++17 -c -g -Iinc
BOOST = -lboost_system -lboost_filesystem
TEST_CPP = g++ -std=c++17 -c -g
TEST = -lboost_unit_test_framework

presentation: clear run_all_tests QuickSort
	./QuickSort

QuickSort: prj/obj prj/obj/main.o
	g++ prj/obj/main.o -o QuickSort ${BOOST}

prj/obj:
	mkdir prj/obj

prj/obj/main.o: prj/main.cpp prj/inc/quicksort.hpp prj/inc/quicksortswap.hpp prj/inc/additionalFunctions.hpp
	${CPP} prj/main.cpp -o prj/obj/main.o

clear:
	rm -rf prj/obj logs

clearObj:
	rm -rf prj/obj

clearLogs:
	rm -rf logs

run_all_tests: testQS_run testAF_run

testQS_run: testQS
	./testQS --log_level=test_suite

testAF_run: testAF
	./testAF --log_level=test_suite

testQS: prj/obj prj/inc/quicksort.hpp prj/inc/quicksortswap.hpp prj/src/TESTquicksort.cpp
	${TEST_CPP} -o prj/obj/TESTquicksort.o prj/src/TESTquicksort.cpp ${TEST}
	g++ -o testQS prj/obj/TESTquicksort.o ${TEST}

testAF: prj/obj prj/inc/quicksort.hpp prj/inc/quicksortswap.hpp prj/inc/additionalFunctions.hpp prj/src/TESTadditionalFunctions.cpp
	${TEST_CPP} -o prj/obj/TESTadditionalFunctions.o prj/src/TESTadditionalFunctions.cpp ${TEST}
	g++ -o testAF prj/obj/TESTadditionalFunctions.o ${TEST}