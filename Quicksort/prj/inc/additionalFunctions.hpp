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

/*!
 * \brief Sorts elements in ascending order.
 * 
 * Function that sort elements in ascending order.
 */
template <class T>
bool ascendingQS(std::vector<T>& vec){

    if(vec.empty())
        return false;

    return quickSort(vec, 0, vec.size());

}

/*!
 * \brief Sorts elements in descending order.
 * 
 * Function that sort elements in descending order.
 */
template <class T>
bool descendingQS(std::vector<T>& vec){

    if(vec.empty())
        return false;

    return quickSortReverse(vec, 0, vec.size());

}

/*!
 * \brief Adds random elements.
 * 
 * Function that adds random elements into choosen vector.
 */
template <class T>
bool addRandomValues(std::vector<T>& vec, int quantity){

    srand(time(nullptr));

    for(int i = 0; i < quantity; i++)
        vec.push_back(rand());

    return true;

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