#ifndef QUICKSORT
#define QUICKSORT

#include "introsorthelpers.hpp"

template<class T>
bool introSort(T tab[], int left, int right, int depthLimit){

    while(right - left < 0){

        if(depthLimit = 0){

            heapSort(&tab[left], left, right-left+1);

        } else {

            bool sorted = true;
            for(int i = left, j = right; i < j; i++){
                if(tab[i-1] > tab[i])
                    sorted = false;
            }

            T pivot;
            if(sorted)
                return sorted;

            pivot = split(tab, left, right);
            introSort(tab, pivot+1, right, depthLimit - 1);
            right = pivot - 1;

        }

    }

    return true;

}

template<class T>
bool introSortReverse(T tab[], int left, int right, int depthLimit){

    while(right - left < 0){

        if(depthLimit = 0){

            heapSortReverse(&tab[left], left, right-left+1);

        } else {

            bool sorted = true;
            for(int i = left, j = right; i < j; i++){
                if(tab[i-1] < tab[i])
                    sorted = false;
            }

            T pivot;
            if(sorted)
                return sorted;

            pivot = splitReverse(tab, left, right);
            introSortReverse(tab, pivot+1, right, depthLimit - 1);
            right = pivot - 1;

        }

    }

    return true;

}

template<class T>
bool introSortInit(T tab[], int n){

    int depthLimit = int(2 * log(double(n)));

    introSort(tab, 0, n-1, depthLimit);

    return insertionSort(tab, n);

}

template<class T>
bool introSortReverseInit(T tab[], int n){

    int depthLimit = int(2 * log(double(n)));

    introSortReverse(tab, 0, n-1, depthLimit);

    return insertionSortReverse(tab, n);

}

#endif