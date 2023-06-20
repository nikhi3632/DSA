/* 
    g++ -o quick_sort_optimized quick_sort_optimized.cpp
    ./quick_sort_optimized 
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>  // For rand()
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

    // swap pivot with element at partition index.
    int tmp = vec[partitionIndex];
    vec[partitionIndex] = vec[high];
    vec[high] = tmp;

    return partitionIndex;
}

int random_pivot_partition(std::vector<int>&vec, int low, int high)
{
    // Randomizing the pivot index in the given subpart of vector.
    int random_pivot_index = low + rand()%(high-low+1);

    // Swapping pivot value from high, so random pivot value will be taken as pivot while partitioning.
    int temp = vec[high];
    vec[high] = vec[random_pivot_index];
    vec[random_pivot_index] = temp;

    return partition(vec, low, high);
}

// Randomized Quick Sort function
void quick_sort_optimized(std::vector<int>&vec) 
{
    int n = vec.size();
    if (n <= 1) 
    {
        return;
    }
    int low = 0;
    int high = n - 1;
    /*
        A stack of pairs of integers, std::stack<std::pair<int, int>> stack, is created. 
        Each pair represents a sub-vector to be sorted, identified by its low and high indices.
    */
    std::stack<std::pair<int, int> > s;
    s.push(std::make_pair(low, high));

    while (!s.empty()) 
    {
        low = s.top().first;
        high = s.top().second;
        s.pop();

        if (low < high) 
        {
            int partitionIndex = random_pivot_partition(vec, low, high);

            s.push(std::make_pair(low, partitionIndex - 1));
            s.push(std::make_pair(partitionIndex + 1, high));
        }
    }
}

int main()
{
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    quick_sort_optimized(v);
    /* 
        Quick sort optimized version follows iterative approach and pivot randomization.
        A partition in a quick sort means that all the elements lesser than the pivot are 
        to the left of it and all the elements greater than the pivot are to the right of it.
        This iterative implementation uses an explicit stack to simulate the recursive calls, 
        avoiding the space overhead of the recursive approach. As a result, it achieves a 
        space complexity of O(logn) in the worst case and O(1) in the best and average cases.
        T.C = O(n^2) but it's mostly O(nlogn) due to randomized quick sort, S.C = O(logn).
    */
    std::cout << "Quick Sort Optimized: " << std::endl;
    print_vector(v);
    return 0;
}