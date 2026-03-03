#include "BinaryInsertionSort.h"
#include <iostream>
void binaryInsertionSort(int a[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = a[i];
		int first = 0, last = i - 1;
		while (first <= last) {
			int m = (first + last) / 2;
			if (key < a[m]) last = m - 1;
			else first = m + 1;
		}
		for (int j = i - 1; j >= first; --j)
			a[j + 1] = a[j];
		a[first] = key;
	}
}