/*
    g++ -o linear_search linear_search.cpp
    ./linear_search
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

int linear_search(std::vector<int>v, int target)
{
    int n = v.size();
    for(int i = 0; i < n; i++)
    {
        if(v[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::vector<int>vec;
    init_sorted_vector(vec);
    std::cout << "Initial Sorted Vector: " << std::endl;
    print_vector(vec);
    int target = 0;
    int target_index = linear_search(vec, target);
    std::cout << "Target Index: " << target_index << ", " << "Target Value: " << vec[target_index] << std::endl;
}