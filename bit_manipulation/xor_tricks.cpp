/*
    g++ -o xor_tricks xor_tricks.cpp
    ./xor_tricks
*/

/*
    https://www.geeksforgeeks.org/bits-manipulation-important-tactics/
*/

#include <iostream>

// Direct XOR of all numbers from 1 to n
int compute_xor_n(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

void xor_swap(int &a, int &b)
{
    /* Quickest way to swap two numbers. T.C: O(1), S.C: O(1) */

    /* 
        Code to swap 'a' and 'b'
        a = a + b;
        b = a - b;
        a = a - b;
    */
    a ^= b;
    b ^= a;
    a ^= b;
}

/*
    vector<int> v = {1,2,3,4,5,4,3,2,1}
    we are given an vector which contains duplicates in it. 
    Find the unique number which is present only once
    //let n be the size of vector a
    int duplicate_element(std::vector<int> &v)
    {
        int xorsum=0; //variable to calculate xor and store unique number
        for(int i=0;i<n;i++)
        {
            xorsum=xorsum^a[i];
        }
        return xorsum;
    }
    result--> 5 
    Hence, a unique number is found in the vector.
    Time complexity--> O(n)
*/

int main()
{
    int a = 10, b = 20;
    std::cout<< "a:" << a << " " << "b:" << b << std::endl;
    xor_swap(a, b);
    std::cout<< "a:" << a << " " << "b:" << b << std::endl;
    return 0;
}