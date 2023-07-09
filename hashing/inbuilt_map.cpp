/*
    g++ -std=c++11 -o inbuilt_map inbuilt_map.cpp
    ./inbuilt_map
*/

#include <iostream>
#include <map>

int main() {
    // Create a map to store string-key, int-value pairs
    std::map<std::string, int> myMap;

    // Insert key-value pairs into the map
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 35;

    // Access values using keys
    std::cout << "Age of Alice: " << myMap["Alice"] << std::endl;
    std::cout << "Age of Bob: " << myMap["Bob"] << std::endl;

    // Iterate over the map
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Check if a key exists in the map
    if (myMap.count("Alice") > 0) {
        std::cout << "Alice exists in the map" << std::endl;
    }

    // Remove a key-value pair from the map
    myMap.erase("Bob");

    // Check the size of the map
    std::cout << "Size of the map: " << myMap.size() << std::endl;

    return 0;
}
