#include <iostream>
#include "On2.h"
using namespace std;
extern long long comp;
void BinaryInsertionSort(int a[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = a[i];
		int first = 0, last = i - 1;
		while (first <= last) {
			int m = (first + last) / 2;
			comp++;
			if (key < a[m]) last = m - 1;
			else first = m + 1;
		}
		for (int j = i - 1; j >= first; --j)
			a[j + 1] = a[j];
		a[first] = key;
	}
}
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			comp++;
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
			}
		}
	}
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			comp++;
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void SelectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			comp++;
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		swap(a[min_index], a[i]);
	}
}
void InsertionSort(int arr[], int n) {
	for (int i = 1; i <= n - 1; i++) {
		int j = i;
		while (j > 0 && ++comp && arr[j - 1] > arr[j]) {
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}

void ShakerSort(int a[], int n) {
	int left = 0, right = n - 1;
	while (++comp && left < right) {
		for (int i = left; ++comp && i < right; i++) {
			if (++comp && a[i] > a[i + 1]) {
				int tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
			}
		}
		right--;
		for (int i = right; ++comp && i > left; i--) {
			if (++comp && a[i] < a[i - 1]) {
				int tmp = a[i]; a[i] = a[i - 1]; a[i - 1] = tmp;
			}
		}
		left++;
	}
}

void FlashSort(int a[], int n) {
	if (++comp && n <= 1) return;
	int m = int(0.45 * n);
	int* L = new int[m]();
	int minVal = a[0], maxIdx = 0;
	for (int i = 1; ++comp && i < n; i++) {
		if (++comp && a[i] < minVal) minVal = a[i];
		if (++comp && a[i] > a[maxIdx]) maxIdx = i;
	}
	if (++comp && a[maxIdx] == minVal) { delete[] L; return; }
	double c = (double)(m - 1) / (a[maxIdx] - minVal);
	for (int i = 0; ++comp && i < n; i++) {
		int k = int(c * (a[i] - minVal));
		L[k]++;
	}
	for (int i = 1; ++comp && i < m; i++) L[i] += L[i - 1];
	int tmp0 = a[maxIdx]; a[maxIdx] = a[0]; a[0] = tmp0;
	int move = 0, j = 0, k = m - 1;
	while (++comp && move < n - 1) {
		while (++comp && j > L[k] - 1) {
			j++;
			k = int(c * (a[j] - minVal));
		}
		int flash = a[j];
		while (++comp && j != L[k]) {
			k = int(c * (flash - minVal));
			int pos = --L[k];
			int tmpF = flash; flash = a[pos]; a[pos] = tmpF;
			move++;
		}
	}
	for (int i = 1; ++comp && i < n; i++) {
		int key = a[i], pos = i - 1;
		while (++comp && pos >= 0 && ++comp && a[pos] > key) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = key;
	}
	delete[] L;
}