#include <iostream>
#include <vector>

void init_vector(std::vector<int>&vec)
{
    vec.push_back(10);
    vec.push_back(0);
    vec.push_back(20);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(15);
    vec.push_back(5);
    vec.push_back(-10);
    vec.push_back(-5);
    vec.push_back(-5);
    vec.push_back(-5);
    vec.push_back(30);
    vec.push_back(25);
    vec.push_back(-35);
}

void print_vector(std::vector<int>&vec)
{
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}