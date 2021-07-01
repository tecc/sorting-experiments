#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstddef>
#include <cstdint>

#include <hayai.hpp>

/*
    Sorting experiments
*/

void sort_bubble(std::vector<int> *vec)
{
    bool hadToSort = true;
    while (hadToSort)
    {
        hadToSort = false;
        for (size_t i = 0; i < vec->size(); i++)
        {
            int v1 = vec->at(i);
            if (i + 1 == vec->size())
            {
                break;
            }
            int v2 = vec->at(i + 1);
            if (v1 > v2)
            {
                std::iter_swap(vec->begin() + i, vec->begin() + i + 1);
                hadToSort = true;
            }
        }
    }
}
void sort_bubble_plus(std::vector<int> *vec)
{
    size_t iterations = 0;
    bool hadToSort = true;
    while (hadToSort)
    {
        hadToSort = false;
        for (size_t i = 0; i < (vec->size() - iterations); i++)
        {
            int v1 = vec->at(i);
            if (i + 1 == vec->size())
            {
                break;
            }
            int v2 = vec->at(i + 1);
            if (v1 > v2)
            {
                std::iter_swap(vec->begin() + i, vec->begin() + i + 1);
                hadToSort = true;
            }
        }
        iterations++;
    }
}

#define ELEMENTS 50
#define TIMES 1000
#define ITERATIONS 10

time_t seed = time(NULL);

std::vector<int> rngVec() {
    std::srand(seed);
    std::vector<int> vec;
    for (size_t i = 0; i < ELEMENTS; i++) {
        vec.push_back(std::rand());
    }
    return vec;
}

BENCHMARK(SortTest, Bubble, TIMES, ITERATIONS)
{
    auto vec = rngVec();
    sort_bubble(&vec);
}

BENCHMARK(SortTest, BubblePlus, TIMES, ITERATIONS)
{
    auto vec = rngVec();
    sort_bubble_plus(&vec);
}
