/* 
    g++ -o selection_sort selection_sort.cpp
    ./selection_sort 
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

void selection_sort(std::vector<int>&vec)
{
    int n = vec.size();
    for(int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for(int j = i+1; j < n; j++)
        {
            if(vec[j] < vec[min_index])
            {
                min_index = j;
            }
        }
        int temp = vec[i];
        vec[i] = vec[min_index];
        vec[min_index] = temp;
        std::cout << "-----------------------------------------------" <<std::endl;
        print_vector(vec);
    }
}

int main()
{
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    selection_sort(v);
    std::cout << "Selection Sort: " << std::endl; // T.C = O(n^2), S.C = O(1);
    print_vector(v);
    return 0;
}