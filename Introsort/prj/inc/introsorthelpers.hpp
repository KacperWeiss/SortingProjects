#ifndef QUICKSORT_SWAP
#define QUICKSORT_SWAP

#include <math.h>
#include <algorithm>

template<class T>
void swap(T *a, T *b){

    T temp = *a;
    *a = *b;
    *b = temp;

}

template<class T>
bool insertionSort(T tab[], int n){

    for(int i = 1; i < n; i++){

        int j;
        T temp = tab[i];
        for(j = i; j > 0 && tab[j - 1] > temp; j--){

            tab[j] = tab[j-1];

        }

        tab[j] = temp;

    }

    return true;

}

template<class T>
bool insertionSortReverse(T tab[], int n){

    for(int i = 1; i < n; i++){

        int j;
        T temp = tab[i];
        for(j = i; j > 0 && tab[j - 1] < temp; j--){

            tab[j] = tab[j-1];

        }

        tab[j] = temp;

    }

    return true;

}

template<class T>
int split(T tab[], int left, int right){

    //Decyzja pomiędzy pivotem w środku, początku, lub na końcu
    int pivot, middle = (left+right)/2;
    pivot = tab[left] > tab[right] ? left : middle;

    if(tab[pivot] > tab[right])
        pivot = right;
    //Najlepszy pivot już wybrany

    swap(&tab[pivot], &tab[right]);
    pivot = left;

    while(left < right){
        if(tab[left] <= tab[right])
            swap(&tab[pivot++], &tab[left]);
        ++left;
    }

    swap(&tab[pivot], &tab[right]);
    return pivot;

}

template<class T>
int splitReverse(T tab[], int left, int right){

    //Decyzja pomiędzy pivotem w środku, początku, lub na końcu
    int pivot, middle = (left+right)/2;
    pivot = tab[left] < tab[right] ? left : middle;

    if(tab[pivot] < tab[right])
        pivot = right;
    //Najlepszy pivot już wybrany

    swap(&tab[pivot], &tab[right]);
    pivot = left;

    while(left < right){
        if(tab[left] >= tab[right])
            swap(&tab[pivot++], &tab[left]);
        ++left;
    }

    swap(&tab[pivot], &tab[right]);
    return pivot;

}

template<class T>
void doHeap(T tab[], int left, int right){

    T temp = tab[left];
    while(left <= right / 2){

        int k = 2 * left;
        while(k < right && tab[k] < tab[k+1])
            ++k;
        if(temp >= tab[k])
            break;
        tab[left] = tab[k];
        left = k;

    }
    tab[left] = temp;

}

template<class T>
void doHeapReverse(T tab[], int left, int right){

    T temp = tab[right];
    while(left <= right / 2){

        int k = 2 * left;
        while(k < right && tab[k] > tab[k+1])
            ++k;
        if(temp <= tab[k])
            break;
        tab[left] = tab[k];
        left = k;

    }
    tab[right] = temp;

}

template<class T>
void heapSort(T tab[], int left, int right){

    for(int i = (right-1) / 2; i >= left; i--){
        doHeap(tab, i, right - 1);
    }
    for(int i = right-1; i > left; i--){
        swap(&tab[i], &tab[left]);
        doHeap(tab, left, i-1);
    }

}

template<class T>
void heapSortReverse(T tab[], int left, int right){

    for(int i = (right-1) / 2; i >= left; i--){
        doHeapReverse(tab, i, right - 1);
    }
    for(int i = right-1; i > left; i--){
        swap(&tab[i], &tab[left]);
        doHeapReverse(tab, left, i-1);
    }

}

#endif