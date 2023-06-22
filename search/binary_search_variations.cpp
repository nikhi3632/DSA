/*
    g++ -o binary_search_variations binary_search_variations.cpp
    ./binary_search_variations
*/

/*
    https://leetcode.com/discuss/interview-question/1322500/5-variations-of-Binary-search-(A-Self-Note)
    Note: In binary search finding the index is more suitable than finding 
    the value, as we can always grab the value once we know the index.
    Refer: https://www.geeksforgeeks.org/binary-search-functions-in-c-stl-binary_search-lower_bound-and-upper_bound/
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

int binary_search(std::vector<int>v, int target)
{
    int n = v.size();
    int low = 0;
    int high = n - 1;
    
    while (low <= high) 
    {
        int mid = (low + high) / 2; // this may cause integer overflow
        
        if (v[mid] < target)
        {
            low = mid + 1;
        }
        else if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binary_search_round_down(std::vector<int>v, int target)
{
    int n = v.size();
    int low = 0;
    int high = n - 1;
    
    while (low <= high) 
    {
        int mid = low + (high - low) / 2; // round down (eliminates integer overflow)
        
        if (v[mid] < target)
        {
            low = mid + 1;
        }
        else if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binary_search_round_up(std::vector<int>v, int target)
{
    int n = v.size();
    int low = 0;
    int high = n - 1;
    
    while (low <= high) 
    {
        int mid = low + (high - low + 1) / 2; // round up (eliminates integer overflow)
        
        if (v[mid] < target)
        {
            low = mid + 1;
        }
        else if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binary_search_round_down_no_comparision(std::vector<int>v, int target)
{
    int n = v.size();
    int low = 0;
    int high = n - 1;
    
    while (low < high) 
    { // notice we do not compare element at mid with our target
        int mid = low + (high - low) / 2;
        if (v[mid] >= target)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    /* 
        At this point our search space has shrinked to 
        only one element if current element is the target element
        then return its index else we can safely assume that element was not found
    */
    
    return v[low] == target ? low : -1; // low == high
}

int binary_search_round_up_no_comparision(std::vector<int>v, int target)
{
    int n = v.size();
    int low = 0;
    int high = n - 1;
    
    while (low < high) 
    { // notice we do not compare element at mid with our target
        int mid = low + (high - low + 1) / 2;
        if (v[mid] <= target)
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    /* 
        At this point our search space has shrinked to 
        only one element if current element is the target element
        then return its index else we can safely assume that element was not found.
    */
    
    return v[low] == target ? low : -1; // low == high
}

/* 
    Use case: Find the pivot of a rotated sorted array
    same as Finding the minimum element in the array
*/

int find_min_or_pivot_index(std::vector<int>v) {
    int low = 0;
    int high = v.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (v[mid] > v[high]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }

int main()
{
    /*
        Rotated Binary Search - TC: O(nlogn), SC: O(1);
    */
    std::vector<int>vec;
    init_sorted_vector(vec);
    std::cout << "Initial Sorted Vector: " << std::endl;
    print_vector(vec);
    init_rotated_sorted_vector(vec);
    std::cout << "Rotated Sorted Vector: " << std::endl;
    print_vector(vec);
    int min_or_pivot_index = find_min_or_pivot_index(vec);
    std::cout << "Index: " << min_or_pivot_index << ", " << "Pivot/MinValue: " << vec[min_or_pivot_index] << std::endl;
}