#ifndef PRESENTATION
#define PRESENTATION

#include "quicksort.hpp"
#include "additionalFunctions.hpp"
#include "../../../MyLoggerClass/inc/logger.hpp"


bool testWithPartSorted(fs::ofstream& out, std::vector<int>& vec, Logger& logger, clock_t& start, int all, int sorted){

    for(int i=1; i <= 100; i++){

        addRandomValues(vec, sorted);
        ascendingQS(vec);
        addRandomValues(vec, all-sorted);

        start = clock();
        ascendingQS(vec);
        out << "Execution time: " << (clock() - start)*1000/CLOCKS_PER_SEC << "ms\n";

        vec.clear();

    }
    out << "\n\n\n";
    return true;

}

bool testWithReversed(fs::ofstream& out, std::vector<int>& vec, Logger& logger, clock_t& start, int all){

    for(int i=1; i <= 100; i++){

        addRandomValues(vec, all);
        descendingQS(vec);

        start = clock();
        ascendingQS(vec);
        out << "Execution time: " << (clock() - start)*1000/CLOCKS_PER_SEC << "ms\n";

        vec.clear();

    }
    out << "\n\n\n";
    return true;

}

bool setTest(std::string loggername, int all){

    clock_t start;

    std::vector<int> elems;
    Logger logger(loggername);

    fs::ofstream out(logger.getLogsPath(), std::ios::out | std::ios::app);


    logger.logToFile("All random:\n");
    testWithPartSorted(out, elems, logger, start, all, 0);
    
    logger.logToFile("25% sorted:\n");
    testWithPartSorted(out, elems, logger, start, all, int(all*0.25));
        
    logger.logToFile("50% sorted:\n");
    testWithPartSorted(out, elems, logger, start, all, int(all*0.5));
        
    logger.logToFile("75% sorted:\n");
    testWithPartSorted(out, elems, logger, start, all, int(all*0.75));
        
    logger.logToFile("95% sorted:\n");
    testWithPartSorted(out, elems, logger, start, all, int(all*0.95));

    logger.logToFile("99% sorted:\n");
    testWithPartSorted(out, elems, logger, start, all, int(all*0.99));
            
    logger.logToFile("99.7% sorted:\n");
    testWithPartSorted(out, elems, logger, start, all, int(all*0.997));

    logger.logToFile("All sorted descending:\n");
    testWithReversed(out, elems, logger, start, all);

    return true;

}

bool quickPresentation(){

    setTest("10 000 elements.txt", 10000);
    setTest("50 000 elements.txt", 50000);
    setTest("100 000 elements.txt", 100000);
    setTest("500 000 elements.txt", 500000);
    setTest("1 000 000 elements.txt", 1000000);

    return true;

}

#endif