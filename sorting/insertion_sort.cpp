/* 
    g++ -o insertion_sort insertion_sort.cpp
    ./insertion_sort 
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

void insertion_sort(std::vector<int>&vec)
{
    int n = vec.size();

    for(int i = 1; i < n; i++)
    {
        int hole = i;
        int val = vec[i];
        /*
            To insert val into the hole of the sorted part, shift all numbers
            greater than val in the sorted part by one position to the right.
        */
        while(hole > 0 && vec[hole-1] > val)
        {
            vec[hole] = vec[hole-1];
            hole = hole - 1;
        }

        vec[hole] = val;

        std::cout << "-----------------------------------------------" <<std::endl;
        print_vector(vec);
    }
}

int main()
{
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    insertion_sort(v);
    std::cout << "Insertion Sort: " << std::endl; // T.C = O(n^2), S.C = O(1);
    print_vector(v);
    return 0;
}