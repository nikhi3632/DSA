/* 
    g++ -o merge_sort merge_sort.cpp
    ./merge_sort 
*/

#include <iostream>
#include <vector>
#include "base_vector.hpp"

void merge(std::vector<int>&vec, std::vector<int>&left_vec, std::vector<int>&right_vec)
{
    /*
        This merge function takes three input parameters: the original vector vec, 
        and the two sub-vectors left and right that are to be merged.

        It initializes three index variables: i for left, j for right, and k for vec. These variables 
        keep track of the current positions within the sub-vectors and the merged vector, respectively.

        The function then enters a loop that continues until all elements from either 
        left or right have been processed. Inside the loop, it compares the 
        elements at indices i and j in left and right, respectively.

        If the element at left[i] is less than or equal to the element at right[j], 
        it means that the element from left should be placed in vec[k] because it is smaller or equal. 
        So, the element is copied from left[i] to vec[k], and both i and k are incremented.

        If the element at left[i] is greater than the element at right[j], 
        it means that the element from right should be placed in vec[k] because it is smaller. 
        So, the element is copied from right[j] to vec[k], and both j and k are incremented.

        After copying an element to vec, the loop continues to the next iteration, 
        comparing and copying the next elements until either left or right is fully processed.

        Once the loop finishes, there might still be remaining elements in either left or right. 
        The function then enters two separate loops to copy any remaining elements to vec.

        The first loop copies any remaining elements from left to vec, starting from index i 
        and continuing until the end of left. It increments both i and k after each copy.

        The second loop copies any remaining elements from right to vec, starting from index j 
        and continuing until the end of right. It increments both j and k after each copy.

        Now, the merged and sorted elements are now stored in the original vector vec.
    */

    int i = 0;
    int j = 0;
    int k = 0;

    int left = left_vec.size();
    int right = right_vec.size();

    while (i < left && j < right) 
    {
        if (left_vec[i] <= right_vec[j]) 
        {
            vec[k] = left_vec[i];
            i++;
        } 
        else 
        {
            vec[k] = right_vec[j];
            j++;
        }
        k++;
    }

    while (i < left) 
    {
        vec[k] = left_vec[i];
        i++;
        k++;
    }

    while (j < right) 
    {
        vec[k] = right_vec[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>&vec) 
{
    int n = vec.size();
    /*
        Base case for recursion
    */
    if (n <= 1) 
    {
        return;
    }

    int mid = n/2;

    /* 
        Halving the vector vec. Create two new vectors: left and right. 
        left is a copy of the elements from the beginning of vec up to the middle index 
        while right is a copy of the elements from the middle index to the end of vec.
    */
    std::vector<int> left_vec(vec.begin(), vec.begin() + mid);
    std::vector<int> right_vec(vec.begin() + mid, vec.end());

    /* 
        Recursively call merge_sort on the left and right vectors effectively 
        dividing it into smaller sub-vectors until the base case is reached.
    */
    merge_sort(left_vec);
    merge_sort(right_vec);

    /* 
        Once the recursive calls return and the left and right sub-vectors 
        are sorted individually and then we merge them back together.
    */
    merge(vec, left_vec, right_vec);
}

int main()
{
    std::vector<int>v;
    init_vector(v);
    print_vector(v);
    /* 
        Merge sort follows divide and conquer approach.
        Merge sort is recursive and is not an in-place sorting algorithm as it required additional space.
        Merge sort is stable i.e the relative order of records with the same key is preserved.
        T.C = O(nlogn), S.C = O(n).
    */
    int n = v.size();
    merge_sort(v);
    std::cout << "Merge Sort: " << std::endl;
    print_vector(v);
    return 0;
}