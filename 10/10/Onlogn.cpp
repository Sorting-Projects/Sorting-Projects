#include "Onlogn.h"

// Binary Insertion Sort
void BinaryInsertionSort(int a[], int n) {
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

void BinaryInsertionSortwithComparison(int a[], int n, long long& count_compare) {
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int first = 0, last = i - 1;
        while (++count_compare && first <= last) {
            int m = (first + last) / 2;
            if (++count_compare && key < a[m]) last = m - 1;
            else first = m + 1;
        }
        for (int j = i - 1; ++count_compare && j >= first; --j)
            a[j + 1] = a[j];
        a[first] = key;
    }
}

// Heap sort

void Heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) Heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}


void HeapifyWithComparison(int arr[], int n, int i, long long& count_compare) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && ++count_compare && arr[left] > arr[largest]) largest = left;
    if (right < n && ++count_compare && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        HeapifyWithComparison(arr, n, largest, count_compare);
    }
}

void HeapSortwithComparison(int arr[], int n, long long& count_compare) {
    for (int i = n / 2 - 1; i >= 0; i--) HeapifyWithComparison(arr, n, i, count_compare);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        HeapifyWithComparison(arr, i, 0, count_compare);
    }
}


// Merge sort 
void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] R;
    delete[] L;
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

void MergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}


void MergeWithComparison(int arr[], int left, int mid, int right, long long& count_compare) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        ++count_compare;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] R;
    delete[] L;
}

void MergeSortwithComparison(int arr[], int left, int right, long long& count_compare) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSortwithComparison(arr, left, mid, count_compare);
    MergeSortwithComparison(arr, mid + 1, right, count_compare);
    MergeWithComparison(arr, left, mid, right, count_compare);
}


// Quick Sort
int Partition(int arr[], int low, int high) {
    swap(arr[low + (high - low) / 2], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pivot = Partition(arr, low, high);
        quickSortHelper(arr, low, pivot - 1);
        quickSortHelper(arr, pivot + 1, high);
    }
}

void QuickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

int PartitionWithComparison(int arr[], int low, int high, long long& count_compare) {
    swap(arr[low + (high - low) / 2], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        ++count_compare;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSortwithComparison(int arr[], int low, int high, long long& count_compare) {
    if (low < high) {
        int pivot = PartitionWithComparison(arr, low, high, count_compare);
        QuickSortwithComparison(arr, low, pivot - 1, count_compare);
        QuickSortwithComparison(arr, pivot + 1, high, count_compare);
    }
}



