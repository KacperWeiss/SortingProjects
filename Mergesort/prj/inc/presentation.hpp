#ifndef PRESENTATION
#define PRESENTATION

#include "mergesort.hpp"
#include "additionalFunctions.hpp"
#include "../../../MyLoggerClass/inc/logger.hpp"

bool testWithPartSorted2(Logger& logger, clock_t& start, int all, int sorted){

    int *tab = new int[all];
    fs::ofstream out(logger.getLogsPath(), std::ios::out | std::ios::app);

    if(sorted != 0){

        addRandomValues(tab, 0, sorted);
        ascendingMS(tab, sorted);
        
    }

    addRandomValues(tab, sorted, all);

    start = clock();
    ascendingMS(tab, all);
    out << "Execution time: " << (clock() - start)*1000000/CLOCKS_PER_SEC << "mks\n";

    delete[] tab;
    return true;

}


bool testWithPartSorted(Logger& logger, clock_t& start, int all, int sorted){

    fs::ofstream endlout(logger.getLogsPath(), std::ios::out | std::ios::app);

    for(int i=1; i <= 100; i++){

       testWithPartSorted2(logger, start, all, sorted);

    }
    endlout << "\n\n\n";
    return true;

}

bool testWithReversed2(Logger& logger, clock_t& start, int all){

        int *tab = new int[all];
        fs::ofstream out(logger.getLogsPath(), std::ios::out | std::ios::app);

        addRandomValues(tab, 0, all);
        descendingMS(tab, all);

        start = clock();
        ascendingMS(tab, all);
        out << "Execution time: " << (clock() - start)*1000000/CLOCKS_PER_SEC << "mks\n";

        delete[] tab;
        return true;

}

bool testWithReversed(Logger& logger, clock_t& start, int all){

    fs::ofstream endlout(logger.getLogsPath(), std::ios::out | std::ios::app);

    for(int i=1; i <= 100; i++){

        testWithReversed2(logger, start, all);

    }

    endlout << "\n\n\n";
    return true;

}

bool setTest(std::string loggername, int all){

    clock_t start;
    Logger logger(loggername);


    logger.logToFile("All random:\n");
    testWithPartSorted(logger, start, all, 0);
    
    logger.logToFile("25% sorted:\n");
    testWithPartSorted(logger, start, all, int(all*0.25));
        
    logger.logToFile("50% sorted:\n");
    testWithPartSorted(logger, start, all, int(all*0.5));
        
    logger.logToFile("75% sorted:\n");
    testWithPartSorted(logger, start, all, int(all*0.75));
        
    logger.logToFile("95% sorted:\n");
    testWithPartSorted(logger, start, all, int(all*0.95));

    logger.logToFile("99% sorted:\n");
    testWithPartSorted(logger, start, all, int(all*0.99));
            
    logger.logToFile("99.7% sorted:\n");
    testWithPartSorted(logger, start, all, int(all*0.997));

    logger.logToFile("All sorted descending:\n");
    testWithReversed(logger, start, all);

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