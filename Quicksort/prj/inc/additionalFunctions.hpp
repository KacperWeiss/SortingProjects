#ifndef ADDITIONAL_FUNCTIONS_QS
#define ADDITIONAL_FUNCTIONS_QS

#include "quicksort.hpp"
#include <iostream>
#include <cstring>

/*!
 * \brief Function that shows menu
 * 
 * Function that shows menu to an user, within itself function uses
 * std namespace.
 */
bool showMenu(){

    using namespace std;

    cout    << endl
            << "a - sort ascending\n"
            << "d - sort descending\n"
            << "r - adds given amount of random elements to array\n"
            << "t - quick test\n\n"
            << "m - show menu\n"
            << "q - quit program\n"
            << endl;

    return true;
    
}

template <class T>
bool ascendingQS(std::vector<T>& vec){



}

template <class T>
bool descendingQS(std::vector<T>& vec){



}

template <class T>
bool addRandomValues(std::vector<T>& vec, int quantity){



}

bool quickPresentation(){



}

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

    return true;

}

#endif