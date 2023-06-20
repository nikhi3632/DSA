/* 
    g++ -o builtin_sort builtin_sort.cpp
    ./builtin_sort 
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

int main()
{
    /*
        Time Complexity:
            Average Case: O(nlogn)
            Worst Case: O(n^2) (unlikely, but possible in rare cases)
            Best Case: O(nlogn)
        
        Space Complexity:
            O(log N) to O(N)
    */
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    std::sort(v.begin(), v.end());
    std::cout << "Built-in Sort: " << std::endl;
    print_vector(v);
    return 0;
}