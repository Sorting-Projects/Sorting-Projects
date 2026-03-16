#ifndef TIME_BENCHMARK_H
#define TIME_BENCHMARK_H
#include <chrono>
#include <cstddef>

double runTimeFunction(void(*func)(int*, std::size_t), int* arr, std::size_t n);
double runTimeFunction(void(*func)(int*, int), int* arr, int n);
double runTimeFunction(void(*func)(int*, int, int), int* arr, int l, int r);

#endif
#pragma once
