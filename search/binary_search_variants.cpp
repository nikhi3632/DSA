/*
    g++ -o binary_search_variants binary_search_variants.cpp
    ./binary_search_variants
*/

/*
    https://www.geeksforgeeks.org/variants-of-binary-search/amp/
    Note: In binary search finding the index is more suitable than finding 
    the value, as we can always grab the value once we know the index.
    Refer: https://www.youtube.com/watch?v=tgVSkMA8joQ
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

/* 
    Find if target is in vector
    Returns: True if target belongs to vector,
    False if target doesn't belong to vector 
 */
bool contains(std::vector<int>v, int target)
{
    int low = 0;
    int high = v.size() - 1;
    bool ans = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midVal = v[mid];
 
        if (midVal < target) {
 
            // if mid is less than target, all elements
            // in range [low, mid] are also less
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > target) {
 
            // if mid is greater than target, all elements
            // in range [mid + 1, high] are also greater
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
        else if (midVal == target) {
 
            // comparison added just for the sake
            // of clarity if mid is equal to target, we
            // have found that target exists in vector
            ans = true;
            break;
        }
    }
 
    return ans;
}
 
/* 
    Find first occurrence index of target in vector
    Returns: an index in range [0, n-1] if target belongs
    to vector, -1 if target doesn't belong to vector
 */
int first_occurrence(std::vector<int>v, int target)
{
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;
 
    while (low <= high) {
        int mid = low + (high - low + 1) / 2;
        int midVal = v[mid];
 
        if (midVal < target) {
 
            // if mid is less than target, all elements
            // in range [low, mid] are also less
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > target) {
 
            // if mid is greater than target, all elements
            // in range [mid + 1, high] are also greater
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
        else if (midVal == target) {
 
            // if mid is equal to target, we note down
            //  the last found index then we search
            // for more in left side of mid
            // so we now search in [low, mid - 1]
            ans = mid;
            high = mid - 1;
        }
    }
 
    return ans;
}
 
/* 
    Find last occurrence index of target in vector
    Returns: an index in range [0, n-1] if target
    belongs to vector, -1 if target doesn't belong to vector
 */
int last_occurrence(std::vector<int>v, int target)
{
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;
 
    while (low <= high) {
        int mid = low + (high - low + 1) / 2;
        int midVal = v[mid];
 
        if (midVal < target) {
 
            // if mid is less than target, then all elements
            // in range [low, mid - 1] are also less
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > target) {
 
            // if mid is greater than target, then all
            // elements in range [mid + 1, high] are
            // also greater so we now search in
            // [low, mid - 1]
            high = mid - 1;
        }
        else if (midVal == target) {
 
            // if mid is equal to target, we note down
            // the last found index then we search
            // for more in right side of mid
            // so we now search in [mid + 1, high]
            ans = mid;
            low = mid + 1;
        }
    }
 
    return ans;
}
 
/* 
    Find index of first occurrence of least element
    greater than target in vector
    Returns: an index in range [0, n-1] if target is not
    the greatest element in vector, -1 if target is the greatest element in vector 
*/
int least_greater_element(std::vector<int>v, int target)
{
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;
 
    while (low <= high) {
        int mid = low + (high - low + 1) / 2;
        int midVal = v[mid];
 
        if (midVal < target) {
 
            // if mid is less than target, all elements
            // in range [low, mid - 1] are <= target
            // then we search in right side of mid
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > target) {
 
            // if mid is greater than target, all elements
            // in range [mid + 1, high] are >= target
            // we note down the last found index, then
            // we search in left side of mid
            // so we now search in [low, mid - 1]
            ans = mid;
            high = mid - 1;
        }
        else if (midVal == target) {
 
            // if mid is equal to target, all elements in
            // range [low, mid] are <= target
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
    }
 
    return ans;
}
 
/* 
    Find index of last occurrence of greatest element
    less than target in vector
    Returns: an index in range [0, n-1] if target is not the least element in vector,
    -1 if target is the least element in vector 
*/
int greatest_lesser_element(std::vector<int>v, int target)
{
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;
 
    while (low <= high) {
        int mid = low + (high - low + 1) / 2;
        int midVal = v[mid];
 
        if (midVal < target) {
 
            // if mid is less than target, all elements
            // in range [low, mid - 1] are < target
            // we note down the last found index, then
            // we search in right side of mid
            // so we now search in [mid + 1, high]
            ans = mid;
            low = mid + 1;
        }
        else if (midVal > target) {
 
            // if mid is greater than target, all elements
            // in range [mid + 1, high] are > target
            // then we search in left side of mid
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
        else if (midVal == target) {
 
            // if mid is equal to target, all elements
            // in range [mid + 1, high] are >= target
            // then we search in left side of mid
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
    }
 
    return ans;
}

int main()
{
    /*
        Binary Search - TC: O(nlogn), SC: O(1);
    */
    std::vector<int>vec;
    init_sorted_vector(vec);
    print_vector(vec);
    int target = 15;
    printf("Contains\n");
    printf("%d %d\n", target, contains(vec, target));
    printf("First occurrence of target\n");
    printf("%d %d\n", target, first_occurrence(vec, target));
    printf("Last occurrence of target\n");
    printf("%d %d\n", target, last_occurrence(vec, target));
    printf("Least integer greater than target\n");
    printf("%d %d\n", target, least_greater_element(vec, target));
    printf("Greatest integer lesser than target\n");
    printf("%d %d\n", target, greatest_lesser_element(vec, target));
    return 0;
}