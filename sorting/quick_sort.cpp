/* 
    g++ -o quick_sort quick_sort.cpp
    ./quick_sort 
*/

#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "base_vector.hpp"

// Function to partition the vector and return the partition index
int partition(std::vector<int>& vec, int low, int high) 
{
    int pivot = vec[high]; // set pivot as last element conventionally.
    int partitionIndex = low; // set partition index as first index conventionally.

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

int random_pivot_partition(std::vector<int>&vec, int low, int high)
{
	// Randomizing the pivot value in the given subpart of array.
	int random_pivot = low + rand()%(high-low+1);
 
	// Swapping pivot value from high, so random pivot value will be taken as pivot while partitioning.
    int temp = vec[high];
    vec[high] = vec[random_pivot];
    vec[random_pivot] = temp;
 
	return partition(vec, low, high);
}

// Processing function for Quick Sort
void process_quick_sort(std::vector<int>&vec, int low, int high) 
{
    if (low < high) 
    {
        // Partition the vector
        int partitionIndex = random_pivot_partition(vec, low, high);

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