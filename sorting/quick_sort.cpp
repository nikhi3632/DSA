/* 
    g++ -o quick_sort quick_sort.cpp
    ./quick_sort 
*/

#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "base_vector.hpp"

// Function to generate a random pivot index
int generate_random_pivot(int low, int high) 
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    return low + rand() % (high - low + 1);
}

// Function to partition the vector and return the partition index
int partition(std::vector<int>& vec, int low, int high) 
{
    int pivotIndex = generate_random_pivot(low, high);
    int pivot = vec[pivotIndex];

    int partitionIndex = low; // set partition index as first element conventionally.

    for(int i = low; i < high; i++)
    {
        if(vec[i] <= pivot) // swap if element is lesser than pivot.
        {
            int temp = vec[i];
            vec[i] = vec[partitionIndex];
            vec[partitionIndex] = temp;
            partitionIndex++;
        }
    }

    int tmp = vec[partitionIndex];
    vec[partitionIndex] = vec[high];
    vec[high] = tmp;

    return partitionIndex;
}

// Processing function for Quick Sort
void process_quick_sort(std::vector<int>&vec, int low, int high) 
{
    if (low < high) 
    {
        // Partition the vector
        int partitionIndex = partition(vec, low, high);

        // Recursively sort the sub-vectors
        process_quick_sort(vec, low, partitionIndex - 1);
        process_quick_sort(vec, partitionIndex + 1, high);
    }
}

// Randomized Quick Sort function
void quick_sort(std::vector<int>&vec) 
{
    int n = vec.size();
    if (n <= 1) 
    {
        return;
    }
    int low = 0;
    int high = n - 1;
    process_quick_sort(vec, low, high);
}

int main()
{
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    quick_sort(v);
    /* 
        T.C = O(n^2) but it's mostly O(nlogn) due to randomized quick sort, S.C = O(n)
    */
    std::cout << "Quick Sort: " << std::endl;
    print_vector(v);
    return 0;
}