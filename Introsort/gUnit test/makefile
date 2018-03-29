# paths
PRJ = ../prj
PINC = ../prj/inc
POBJ = ../prj/obj

# compiler settings
CPP = g++ -Wall -pedantic -std=c++17 -c -g 
TESTFLAGS = -L/opt/gtest/lib -lgtest -lgtest_main -lpthread 
INCS = -I$(PINC) -I/opt/gtest/include 
BOOST = -lboost_system -lboost_filesystem 
OBJS = obj obj/Main_TestALL.o 

testALL: $(OBJS)
	$(CPP) $(TESTFLAGS) $(INCS) -o testALL $(OBJS)

obj:
	mkdir obj

obj/Main_TestALL.o: Main_TestALL.cpp
	$(CPP) $(TESTFLAGS) Main_TestALL.cpp -o obj/Main_TestALL.o

clear:
	rm -rf obj
