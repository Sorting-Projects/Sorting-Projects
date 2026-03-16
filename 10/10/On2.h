#ifndef O_n2_H
#define O_n2_H
#include <iostream>
using namespace std;

void BubbleSort(int a[], int n);
void BubbleSortwithComparison(int a[], int n, long long& count_compare);


void InsertionSort(int a[], int n);
void InsertionSortwithComparison(int a[], int n, long long& comparison);

void SelectionSort(int a[], int n);
void SelectionSortwithComparison(int a[], int n, long long& count_compare);

void ShellSort(int a[], int n);
void ShellSortwithComparison(int a[], int n, long long& count_compare);

void ShakerSort(int a[], int n); 
void ShakerSortwithComparison(int a[], int n, long long& count_compare);

int GetMax(int arr[], int n);
void CountingSortByDigit(int arr[], int n, int exp);
void RadixSort(int arr[], int n);
int GetMaxWithComparison(int arr[], int n, long long& count_compare);
void CountingSortByDigitWithComparison(int arr[], int n, int exp, long long& count_compare);
void RadixSortwithComparison(int arr[], int n, long long& count_compare);

void FlashSort(int a[], int n);
void FlashSortwithComparison(int a[], int n, long long& count_compare);

#endif 