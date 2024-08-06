#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

extern std::mt19937 rng;
    
extern long long cmpCount;
extern long long swpCount;
extern int globSize;

void print(int size, int* arr);

bool cmp(int a, int b);

void swp(int * a, int * b);

int RandomizedSelect(int* A, int start, int end, int i);
int Select(int* A, int start, int end, int i);