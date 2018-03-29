# compiler settings
CPP = g++ -Wall -pedantic -std=c++17 -c -g -Iinc
BOOST = -lboost_system -lboost_filesystem

# __start__: clear IntroSort
# 	./IntroSort

IntroSort: prj/obj prj/obj/main.o
	g++ prj/obj/main.o -o IntroSort
 ${BOOST}

prj/obj:
	mkdir prj/obj

prj/obj/main.o: prj/main.cpp
	${CPP} prj/main.cpp -o prj/obj/main.o

clear:
	rm -rf prj/obj logs

clearObj:
	rm -rf prj/obj

clearLogs:
	rm -rf logs
