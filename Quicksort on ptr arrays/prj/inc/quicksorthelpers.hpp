#ifndef QUICKSORT_SWAP
#define QUICKSORT_SWAP

#include <vector>

template<class T>
bool qsSwap(T tab[], int i, int j){

    T temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
    return true;

}

template<class T>
int split(T tab[], int left, int right){

    T pivot = tab[(right - left)/2 + left];

    int i = left;
    int j = right;
    while(true){

        while(tab[i] < pivot) i++;
        while(tab[j] > pivot) j--;

        if(i < j){

            qsSwap(tab, i, j);
            i++;
            j--;

        } else {
            return j;
        }

    }

}

template<class T>
int splitReverse(T tab[], int left, int right){

    T pivot = tab[(right - left)/2 + left];

    int i = left;
    int j = right;
    while(true){

        while(tab[i] > pivot) i++;
        while(tab[j] < pivot) j--;

        if(i < j){

            qsSwap(tab, i, j);
            i++;
            j--;

        } else {
            return j;
        }

    }

}

#endif