#ifndef OUTPUT_H
#define OUTPUT_H

#include "DataGenerator.h"
#include "timeBenchmark.h"
#include "Sorting.h"
#include <fstream>
#include <string>
using namespace std;

const string Name[] = {
    "Selection Sort", "Insertion Sort", "Shell Sort", "Bubble Sort",
    "Heap Sort", "Merge Sort", "Quick Sort", "Radix Sort",
    "Counting Sort", "Binary Insertion Sort", "Shaker Sort", "Flash Sort"
};

const string DataOrder[] =
{
    "Randomized Data",    // 0 = -rand
    "Nearly Sorted Data", // 1 = -nsorted
    "Sorted Data",        // 2 = -sorted
    "Reverse Sorted Data" // 3 = -rev
};

int getSortName(const string& sortName);
int getInputOrder(const string& inputOrder);
int getOutputParameter(const string& outputParameter);

void outputRuntime(int a[], int inputSize, const string& sortName, int command);
void outputComparisons(int a[], int inputSize, const string& sortName, int command);
void outputArray(const string& filePath, int a[], int inputSize);
void outputParameter(int type, int A[], int inputSize, const string& sortName);

void copyArray(int a[], int b[], int inputSize);

bool algorithmMode(int argc, char* argv[]);
bool comparisonMode(int argc, char* argv[]);

#endif