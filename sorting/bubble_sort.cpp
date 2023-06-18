/* 
    g++ -o bubble_sort bubble_sort.cpp
    ./bubble_sort 
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

void bubble_sort(std::vector<int>&vec)
{
    int n = vec.size();
    for(int i = 0; i < n-1; i++)
    {
        bool swapped = false;
        
        for(int j = 0; j < n-1-i; j++)
        {
            if(vec[j] > vec[j+1])
            {
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
                swapped = true;
            }
        }

        if(!swapped)
        {
            break;
        }
    }
}

int main()
{
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    std::cout << "Bubble Sort: " << std::endl; // T.C = O(n^2), S.C = O(1);
    bubble_sort(v);
    print_vector(v);
    return 0;
}