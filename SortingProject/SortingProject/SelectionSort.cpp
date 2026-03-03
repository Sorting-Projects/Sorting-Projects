#include "SelectionSort.h"
#include <iostream>

void SelectionSort(int a[], int n) {
	int minimum; 
	int min_index; 
	for (int i = 0; i < n; i++) {
		minimum = a[i]; 
		min_index = i; 
		for (int j = i + 1; j < n; j++) {
			if (a[j] < minimum) {
				minimum = a[j]; 
				min_index = j; 
			}
		}
		swap(a[min_index], a[i]); 
	}
}


