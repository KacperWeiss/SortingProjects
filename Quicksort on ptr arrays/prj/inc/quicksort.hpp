#ifndef QUICKSORT
#define QUICKSORT

#include "quicksorthelpers.hpp"

template<class T>
bool quickSort(T tab[], int left, int right){

    int splitPoint;
    if(left < right){

        splitPoint = split(tab, left, right);
        quickSort(tab, left, splitPoint);
        quickSort(tab, splitPoint+1, right);

    }

    return true;

}

template<class T>
bool quickSortReverse(T tab[], int left, int right){

    int splitPoint;
    if(left < right){

        splitPoint = splitReverse(tab, left, right);
        quickSortReverse(tab, left, splitPoint);
        quickSortReverse(tab, splitPoint+1, right);

    }

    return true;

}

#endif