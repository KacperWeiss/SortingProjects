#ifndef QUICKSORT_SWAP
#define QUICKSORT_SWAP

#include <vector>

template<class T>
bool qsSwap(std::vector<T>& vec, int i, int j){

    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
    return true;

}

#endif