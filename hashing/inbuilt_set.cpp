/*
    g++ -std=c++11 -o inbuilt_set inbuilt_set.cpp
    ./inbuilt_set
*/

#include <iostream>
#include <set>

int main() {
    // Create a set of integers
    std::set<int> mySet;

    // Insert elements into the set
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(1);
    mySet.insert(10);

    // Print the elements in the set
    std::cout << "Set elements: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Check if an element exists in the set
    int searchKey = 2;
    if (mySet.find(searchKey) != mySet.end()) {
        std::cout << searchKey << " is found in the set." << std::endl;
    } else {
        std::cout << searchKey << " is not found in the set." << std::endl;
    }

    // Remove an element from the set
    int removeKey = 8;
    mySet.erase(removeKey);

    // Print the updated elements in the set
    std::cout << "Updated set elements: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Check the size of the set
    std::cout << "Size of the set: " << mySet.size() << std::endl;

    return 0;
}
