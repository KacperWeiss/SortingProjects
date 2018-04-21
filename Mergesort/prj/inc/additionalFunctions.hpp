#ifndef ADDITIONAL_FUNCTIONS_QS
#define ADDITIONAL_FUNCTIONS_QS

#include "mergesort.hpp"
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
bool ascendingMS(T tab[], int length){

    if(tab == NULL)
        return false;

    return mergeSort(tab, 0, length-1);

}

/*!
 * \brief Sorts elements in descending order.
 * 
 * Function that sort elements in descending order.
 */
template <class T>
bool descendingMS(T tab[], int length){

    if(tab == NULL)
        return false;

    return mergeSortReverse(tab, 0, length-1);

}

/*!
 * \brief Adds random elements.
 * 
 * Function that adds random elements into choosen tabtor.
 */
template <class T>
bool addRandomValues(T tab[], int start, int length){

    srand(time(nullptr));

    for(int i = start; i < length; i++)
        tab[i] = (rand() * rand());

    return true;

}

#endif