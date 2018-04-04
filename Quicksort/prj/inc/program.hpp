#ifndef MYPROGRAM
#define MYPROGRAM

#include "quicksort.hpp"
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
    std::vector<int> elems;

    showMenu();

    while(selector != 'q'){

        std::cout   << "Select action (m - show menu) > _\b";
        std::cin    >> selector;

        if(strchr("adrtmq", selector)){

            if(selector == 'a')
                ascendingQS(elems);

            else if(selector == 'd')
                descendingQS(elems);

            else if(selector == 'r'){

                int quantity;
                std::cout   << "Select how many elements to add > ";
                std::cin    >> quantity;

                addRandomValues(elems, quantity);

            }

            else if(selector == 't'){

                quickMYPROGRAM();
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

    return true;

}

#endif