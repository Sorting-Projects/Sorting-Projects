#include "On.h"



void CountingSort(int a[], int n) {
    int maxVal = *std::max_element(a, a + n);
    int minVal = *std::min_element(a, a + n);
    int range = maxVal - minVal + 1;

    int* count = new int[range]();
    int* output = new int[n];

    for (int i = 0; i < n; i++) count[a[i] - minVal]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) output[--count[a[i] - minVal]] = a[i];
    for (int i = 0; i < n; i++) a[i] = output[i];

    delete[] count;
    delete[] output;
}

void CountingSortwithComparison(int a[], int n, long long& count_compare) {
    int maxVal = a[0], minVal = a[0];
    for (int i = 1; ++count_compare && i < n; i++) {
        if (++count_compare && a[i] > maxVal) maxVal = a[i];
        if (++count_compare && a[i] < minVal) minVal = a[i];
    }
    int range = maxVal - minVal + 1;

    int* count = new int[range]();
    int* output = new int[n];

    for (int i = 0; ++count_compare && i < n; i++) count[a[i] - minVal]++;
    for (int i = 1; ++count_compare && i < range; i++) count[i] += count[i - 1];
    for (int i = n - 1; ++count_compare && i >= 0; i--) output[--count[a[i] - minVal]] = a[i];
    for (int i = 0; ++count_compare && i < n; i++) a[i] = output[i];

    delete[] count;
    delete[] output;
}

