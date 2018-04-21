#ifndef MERGE
#define MERGE

#include <iostream>
#include <vector>

template <class T>
bool merge(T tab[], int start, int middle, int end){
    
	T *tempTab = new T[(end - start + 1)];
	int i = start;
	int j = middle+1;
	int k = 0;

	while (i <= middle && j <= end){

		if (tab[i] < tab[j]){

			tempTab[k] = tab[i];
			i++;

		} else {

			tempTab[k] = tab[j];
			j++;
		}

		k++;

	}
 
	if (i <= middle){

		while (i <= middle){

			tempTab[k] = tab[i];
			i++;
			k++;
		}

	} else {

		while (j <= end){

			tempTab[k] = tab[j];
			j++;
			k++;

		}
	}

	for(int l = 0; l <= end - start; l++){

		tab[start + l] = tempTab[l];

	}

	delete[] tempTab;

	return true;

}

template <class T>
bool mergeReverse(T tab[], int start, int middle, int end){
    
	T *tempTab = new T[(end - start + 1)];
	int i = start;
	int j = middle+1;
	int k = 0;
	int l = 0;

	while (i <= middle && j <= end){

		if (tab[i] > tab[j]){

			tempTab[k] = tab[i];
			i++;

		} else {

			tempTab[k] = tab[j];
			j++;
		}

		k++;

	}
 
	if (i <= middle){

		while (i <= middle){

			tempTab[k] = tab[i];
			i++;
			k++;
		}

	} else {

		while (j <= end){

			tempTab[k] = tab[j];
			j++;
			k++;

		}
	}

	for(l = 0; l <= end - start; l++){

		tab[start + l] = tempTab[l];
		
	}

	delete[] tempTab;

	return true;

}

#endif