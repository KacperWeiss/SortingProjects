#ifndef QUICKSORT
#define QUICKSORT

#include "quicksortswap.hpp"

template<class T>
bool quickSort(std::vector<T>& vec, int left, int right){

    if(vec.empty())
        return false;

    int i = left, j = right;
    T piv = vec[(right - left)/2 + left];

    while(i < right || j > left){

        while(vec[i] < piv) i++;
        while(vec[j] > piv) j--;

        if(i <= j){

            qsSwap(vec, i, j);
            i++;
            j--;

        } else {

            if(i < right)
                quickSort(vec, i, right);

            if(j > left)
                quickSort(vec, left, j);

            return true;

        }

    }

}

template<class T>
bool quickSortReverse(std::vector<T>& vec, int left, int right){

    if(vec.empty())
        return false;

    int i = left, j = right;
    T piv = vec[(right - left)/2 + left];

    while(i < right || j > left){

        while(vec[i] > piv) i++;
        while(vec[j] < piv) j--;

        if(i <= j){

            qsSwap(vec, i, j);
            i++;
            j--;

        } else {

            if(i < right)
                quickSortReverse(vec, i, right);

            if(j > left)
                quickSortReverse(vec, left, j);

            return true;

        }

    }

}

#endif