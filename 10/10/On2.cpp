#include "On2.h"
#include <iostream>

using namespace std; 
// Selection Sort
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


void SelectionSortwithComparison(int a[], int n, long long& count_compare)
{
	for (int i = 0; ++count_compare && i < n; i++)
	{
		int min_idx = i;

		for (int j = i + 1; ++count_compare && j < n; j++)
		{
			if (++count_compare && a[j] < a[min_idx])
				min_idx = j;
		}

		if (++count_compare && min_idx != i)
			swap(a[min_idx], a[i]);
	}
}

// Insertion Sort
void InsertionSort(int a[], int n) {
	for (int i = 1; i <= n - 1; i++) {
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			int tmp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = tmp;
			j--;
		}
	}

}

void InsertionSortwithComparison(int a[], int n, long long& count_compare) {
	for (int i = 1; ++count_compare && i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (++count_compare && j >= 0 && (++count_compare && a[j] > key)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}


// Bubble sort
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void BubbleSortwithComparison(int a[], int n, long long& count_compare) {
	for (int i = 0; ++count_compare && i < n - 1; i++) {
		for (int j = 0; ++count_compare && j < n - i - 1; j++) {
			if (++count_compare && a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

// Shaker Sort
void ShakerSort(int a[], int n) {
	int left = 0, right = n - 1;
	while (left < right) {
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				int tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]) {
				int tmp = a[i]; a[i] = a[i - 1]; a[i - 1] = tmp;
			}
		}
		left++;
	}
}

void ShakerSortwithComparison(int a[], int n, long long& count_compare) {
	int left = 0, right = n - 1;
	while (++count_compare && left < right) {
		for (int i = left; ++count_compare && i < right; i++) {
			if (++count_compare && a[i] > a[i + 1]) {
				int tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
			}
		}
		right--;
		for (int i = right; ++count_compare && i > left; i--) {
			if (++count_compare && a[i] < a[i - 1]) {
				int tmp = a[i]; a[i] = a[i - 1]; a[i - 1] = tmp;
			}
		}
		left++;
	}
}

// Radix Sort
int GetMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void CountingSortByDigit(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
    delete[] output;
}

void RadixSort(int arr[], int n) {
    int m = GetMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountingSortByDigit(arr, n, exp);
}


int GetMaxWithComparison(int arr[], int n, long long& count_compare) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        ++count_compare;
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void CountingSortByDigitWithComparison(int arr[], int n, int exp, long long& count_compare) {
    int* output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
    delete[] output;
}

void RadixSortwithComparison(int arr[], int n, long long& count_compare) {
    int m = GetMaxWithComparison(arr, n, count_compare);
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountingSortByDigitWithComparison(arr, n, exp, count_compare);
}


// Flash sort
void FlashSort(int a[], int n)
{
	if (n <= 1) return;

	int m = int(0.45 * n);
	int* L = new int[m]();

	int minVal = a[0];
	int maxIdx = 0;

	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[maxIdx])
			maxIdx = i;
	}

	if (a[maxIdx] == minVal) return;

	double c = (double)(m - 1) / (a[maxIdx] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c * (a[i] - minVal));
		L[k]++;
	}

	for (int i = 1; i < m; i++)
		L[i] += L[i - 1];

	swap(a[maxIdx], a[0]);

	int move = 0, j = 0, k = m - 1;

	while (move < n - 1)
	{
		while (j > L[k] - 1)
		{
			j++;
			k = int(c * (a[j] - minVal));
		}

		int flash = a[j];

		while (j != L[k])
		{
			k = int(c * (flash - minVal));
			int pos = --L[k];
			swap(flash, a[pos]);
			move++;
		}
	}

	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

	delete[] L;
}

void FlashSortwithComparison(int a[], int n, long long& count_compare)
{
	if (++count_compare && n <= 1) return;

	int m = int(0.45 * n);
	int* L = new int[m]();

	int minVal = a[0];
	int maxIdx = 0;

	for (int i = 1; ++count_compare && i < n; i++)
	{
		if (++count_compare && a[i] < minVal)
			minVal = a[i];

		if (++count_compare && a[i] > a[maxIdx])
			maxIdx = i;
	}

	if (++count_compare && a[maxIdx] == minVal) return;

	double c = (double)(m - 1) / (a[maxIdx] - minVal);

	for (int i = 0; ++count_compare && i < n; i++)
	{
		int k = int(c * (a[i] - minVal));
		L[k]++;
	}

	for (int i = 1; ++count_compare && i < m; i++)
		L[i] += L[i - 1];

	swap(a[maxIdx], a[0]);

	int move = 0, j = 0, k = m - 1;

	while (++count_compare && move < n - 1)
	{
		while (++count_compare && j > L[k] - 1)
		{
			j++;
			k = int(c * (a[j] - minVal));
		}

		int flash = a[j];

		while (++count_compare && j != L[k])
		{
			k = int(c * (flash - minVal));
			int pos = --L[k];
			swap(flash, a[pos]);
			move++;
		}
	}

	for (int i = 1; ++count_compare && i < n; i++)
	{
		int key = a[i];
		int j = i - 1;

		while ((++count_compare && j >= 0) && (++count_compare && a[j] > key))
		{
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = key;
	}

	delete[] L;
}

// Shell sort
void ShellSort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}


void ShellSortwithComparison(int arr[], int n, long long& count_compare) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j = i;
			while (j >= gap && ++count_compare && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}




