/* 
    g++ -o quick_sort quick_sort.cpp
    ./quick_sort 
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

int partition(std::vector<int>& vec, int low, int high)
{
    int pivot = vec[high]; // set pivot as last element conventionally.
    int partitionIndex = low; // set partition index as first index conventionally.

    for (int i = low; i < high; ++i)
    {
        if (vec[i] <= pivot)
        {
            int temp = vec[i];
            vec[i] = vec[partitionIndex];
            vec[partitionIndex] = temp;
            ++partitionIndex;
        }
    }

    int temp = vec[partitionIndex];
    vec[partitionIndex] = vec[high];
    vec[high] = temp;

    return partitionIndex;
}

void process_quick_sort(std::vector<int>& vec, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(vec, low, high);
        process_quick_sort(vec, low, partitionIndex - 1);
        process_quick_sort(vec, partitionIndex + 1, high);
    }
}

void quick_sort(std::vector<int>& vec)
{
    int low = 0;
    int high = vec.size() - 1;
    process_quick_sort(vec, low, high);
}

int main()
{
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    quick_sort(v);
    /* 
        Quick sort follows divide and conquer approach.
        This implementation of quick sort is recursive and is an in-place 
        sorting algorithm as it does not required additional space.
        The worst-case space complexity can be O(n) in scenarios where the recursion depth is equal to the 
        number of elements in the input vector. However, the average case space complexity is O(logn).
        Merge sort is stable i.e the relative order of records with the same key is preserved.
        T.C = O(n^2), BestCase: O(nlogn), AverageCase: O(nlogn), WorstCase: O(n^2) and S.C = O(n) to O(logn).
    */
    std::cout << "Quick Sort: " << std::endl;
    print_vector(v);
    return 0;
}