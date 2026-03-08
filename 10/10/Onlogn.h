#ifndef ONLOGN_H
#define ONLOGN_H
#include <iostream>
using namespace std;

void BinaryInsertionSort(int a[], int n);
void BinaryInsertionSortwithComparison(int a[], int n, long long& count_compare);

void MergeSort(int a[], int n);
void MergeSortwithComparison(int a[], int l, int r, long long& count_compare);

void HeapSort(int a[], int n);
void HeapSortwithComparison(int a[], int n, long long& count_compare);

int Partition(int arr[], int low, int high);
void QuickSort(int arr[], int n);
void quickSortHelper(int arr[], int low, int high);
int PartitionWithComparison(int arr[], int low, int high, long long& count_compare);
void QuickSortwithComparison(int arr[], int low, int high, long long& count_compare);
#endif