#include "timeBenchmark.h"

double runTimeFunction(void(*func)(int*, std::size_t), int* arr, std::size_t n)
{
    auto start = std::chrono::high_resolution_clock::now();
    func(arr, n);
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count();
}

double runTimeFunction(void(*func)(int*, int), int* arr, int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    func(arr, n);
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count();
}

double funcRunTime(void(*func)(int*, int, int), int* arr, int l, int r)
{
    auto start = std::chrono::high_resolution_clock::now();
    func(arr, l, r);
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count();
}