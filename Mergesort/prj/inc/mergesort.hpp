#ifndef MERGESORT
#define MERGESORT

#include "merge.hpp"

template <class T>
bool mergeSort(T tab[], int start, int end)
{
	int middle;

	if (start != end)
	{
		middle = (start + end)/2;
		mergeSort(tab, start, middle);
		mergeSort(tab, middle+1, end);
		merge(tab, start, middle, end);
	}

	return true;
	
}

template <class T>
bool mergeSortReverse(T tab[], int start, int end)
{
	int middle;

	if (start != end)
	{
		middle = (start + end)/2;
		mergeSortReverse(tab, start, middle);
		mergeSortReverse(tab, middle+1, end);
		mergeReverse(tab, start, middle, end);
	}

	return true;

}

#endif