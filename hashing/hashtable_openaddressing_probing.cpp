/*
    g++ -std=c++11 -o hashtable_openaddressing_probing hashtable_openaddressing_probing.cpp
    ./hashtable_openaddressing_probing
*/

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cmath>

enum ProbingTechnique {
    LinearProbing,
    QuadraticProbing,
    DoubleHashing
};

class HashTable {
private:
    std::vector<std::pair<std::string, int> > table;
    int numElements;
    int tableSize;
    float loadFactor;
    int growthFactor;
    ProbingTechnique probingTechnique;

    int hashFunction(const std::string& key) {
        std::hash<std::string> hasher;
        return hasher(key) % tableSize;
    }

    int probe(int index, const std::string& key, int attempt) {
        switch (probingTechnique) {
            case LinearProbing:
                return (index + attempt) % tableSize;
            case QuadraticProbing:
                return (index + attempt * attempt) % tableSize;
            case DoubleHashing: {
                std::hash<std::string> hasher;
                int hash2 = hasher(key) % (tableSize - 1) + 1;
                return (index + attempt * hash2) % tableSize;
            }
        }
        return -1; // Invalid probing technique
    }

    void resizeTable() {
        int newSize = tableSize * growthFactor;
        std::vector<std::pair<std::string, int> > newTable(newSize);

        for (const auto& pair : table) {
            const std::string& key = pair.first;
            int value = pair.second;
            int hash = hashFunction(key);

            int attempt = 0;
            while (newTable[hash].first != "") {
                hash = probe(hash, key, ++attempt);
            }

            newTable[hash] = std::make_pair(key, value);
        }

        table = std::move(newTable);
        tableSize = newSize;
    }

public:
    HashTable(int initialSize, float loadFactorThreshold, int growthFactorValue, ProbingTechnique technique)
        : tableSize(initialSize), loadFactor(loadFactorThreshold),
          growthFactor(growthFactorValue), probingTechnique(technique) {
        numElements = 0;
        table.resize(tableSize);
    }

    void insert(const std::string& key, int value) {
        if (static_cast<float>(numElements + 1) / tableSize > loadFactor) {
            resizeTable();
        }

        int hash = hashFunction(key);

        int attempt = 0;
        while (table[hash].first != "") {
            hash = probe(hash, key, ++attempt);
        }

        table[hash] = std::make_pair(key, value);
        numElements++;
    }

    bool search(const std::string& key, int& value) {
        int hash = hashFunction(key);

        int attempt = 0;
        while (table[hash].first != "") {
            if (table[hash].first == key) {
                value = table[hash].second;
                return true;
            }
            hash = probe(hash, key, ++attempt);
        }

        return false;
    }

    void remove(const std::string& key) {
        int hash = hashFunction(key);

        int attempt = 0;
        while (table[hash].first != "") {
            if (table[hash].first == key) {
                table[hash] = std::make_pair("", 0);
                numElements--;
                return;
            }
            hash = probe(hash, key, ++attempt);
        }
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i].first != "") {
                std::cout << "Bucket " << i << ": " << table[i].first << " -> " << table[i].second << std::endl;
            }
        }
    }
};

int main() {
    int initialSize = 10;
    float loadFactorThreshold = 0.75;
    int growthFactorValue = 2;
    ProbingTechnique technique = LinearProbing;

    HashTable hashTable(initialSize, loadFactorThreshold, growthFactorValue, technique);

    hashTable.insert("apple", 25);
    hashTable.insert("banana", 30);
    hashTable.insert("orange", 35);

    std::cout << "Hash table contents:" << std::endl;
    hashTable.display();

    int value;
    if (hashTable.search("banana", value)) {
        std::cout << "Search for key 'banana': Found, Value = " << value << std::endl;
    } else {
        std::cout << "Search for key 'banana': Not found" << std::endl;
    }

    hashTable.remove("banana");

    if (hashTable.search("banana", value)) {
        std::cout << "Search for key 'banana' after removal: Found, Value = " << value << std::endl;
    } else {
        std::cout << "Search for key 'banana' after removal: Not found" << std::endl;
    }

    std::cout << "Hash table contents after removal:" << std::endl;
    hashTable.display();

    return 0;
}
