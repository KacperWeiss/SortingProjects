# compiler settings
CPP = g++ -Wall -pedantic -std=c++17 -c -g -Iinc
BOOST = -lboost_system -lboost_filesystem
LOOGER = ../MyLoggerClass

# __start__: clear MergeSort
# 	./MergeSort

MergeSort: prj/obj prj/obj/main.o prj/obj/logger.o
	g++ prj/obj/logger.o prj/obj/main.o -o MergeSort ${BOOST}

prj/obj:
	mkdir prj/obj

prj/obj/main.o: prj/main.cpp
	${CPP} prj/main.cpp -o prj/obj/main.o

prj/obj/logger.o: ${LOOGER}/src/logger.cpp ${LOOGER}/inc/logger.hpp
	${CPP} ${LOOGER}/src/logger.cpp -o prj/obj/logger.o ${BOOST}

clear:
	rm -rf prj/obj logs

clearObj:
	rm -rf prj/obj

clearLogs:
	rm -rf logs
