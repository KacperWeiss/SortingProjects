#ifndef MYPROGRAM
#define MYPROGRAM

#include "introsort.hpp"
#include "additionalFunctions.hpp"
#include "presentation.hpp"
#include <iostream>
#include <cstring>


/*!
 * \brief This function is main function of whole program.
 * 
 * Shows UI and lets user choose an action
 */
bool program(){

    char selector = '\0';

    int userSelectedLength;
    std::cout << "Length of the array: ";
	std::cin >> userSelectedLength;

    int* tab = new int[userSelectedLength];

    showMenu();

    while(selector != 'q'){

        std::cout   << "Select action (m - show menu) > _\b";
        std::cin    >> selector;

        if(strchr("adrtmq", selector)){

            if(selector == 'a'){

                std::clock_t start = clock();
                ascendingIS(tab, userSelectedLength);
                std::cout << "Execution time: " << (clock() - start)*1000000/CLOCKS_PER_SEC << "mks\n";

            }

            else if(selector == 'd'){

                std::clock_t start = clock();
                descendingIS(tab, userSelectedLength);
                std::cout << "Execution time: " << (clock() - start)*1000000/CLOCKS_PER_SEC << "mks\n";

            }

            else if(selector == 'r'){

                addRandomValues(tab, 0, userSelectedLength);

            }

            else if(selector == 't'){

                quickPresentation();
                selector = 'q';

            }

            else if(selector == 'm')
                showMenu();

            else if(selector == 'q')
                std::cout << "Exiting program" << std::endl;

        } else {

            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cerr << "Nieporawne polecenie\n";
            selector = ' ';
            showMenu();

        }

    }

    delete[] tab;
    return true;

}

#endif