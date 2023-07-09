/*
    g++ -std=c++11 -o hashtable_external_chaining hashtable_external_chaining.cpp
    ./hashtable_external_chaining
*/

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <utility>

class HashTable {
private:
    std::vector<std::list<std::string> > table;
    int numElements;
    int tableSize;
    float loadFactor;
    int growthFactor;

    void resizeTable() {
        int newSize = tableSize * growthFactor;
        std::vector<std::list<std::string> > newTable(newSize);

        for (int i = 0; i < tableSize; ++i) {
            std::list<std::string>& bucket = table[i];
            for (const std::string& key : bucket) {
                int newHash = hashFunction(key, newSize);
                newTable[newHash].push_back(key);
            }
        }

        table = std::move(newTable);
        tableSize = newSize;
    }

    int hashFunction(const std::string& key, int size) {
        std::hash<std::string> hasher;
        return hasher(key) % size;
    }

public:
    HashTable(int initialSize, float loadFactorThreshold, int growthFactorValue) {
        tableSize = initialSize;
        table.resize(tableSize);
        numElements = 0;
        loadFactor = loadFactorThreshold;
        growthFactor = growthFactorValue;
    }

    void insert(const std::string& key) {
        int hash = hashFunction(key, tableSize);
        std::list<std::string>& bucket = table[hash];
        bucket.push_back(key);
        numElements++;

        float currentLoadFactor = static_cast<float>(numElements) / tableSize;
        if (currentLoadFactor > loadFactor) {
            resizeTable();
        }
    }

    std::pair<int, int> search(const std::string& key) {
        int hash = hashFunction(key, tableSize);
        std::list<std::string>& bucket = table[hash];
        int position = 0;
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                return std::make_pair(hash, position);
            }
            position++;
        }
        return std::make_pair(-1, -1);
    }

    void remove(const std::string& key) {
        int hash = hashFunction(key, tableSize);
        std::list<std::string>& bucket = table[hash];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                numElements--;
                break;
            }
        }
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            std::list<std::string>& bucket = table[i];
            if (!bucket.empty()) {
                std::cout << "Bucket " << i << ": ";
                for (const std::string& key : bucket) {
                    std::cout << key << " ";
                }
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    HashTable hashTable(10, 0.75, 2);

    hashTable.insert("apple");
    hashTable.insert("banana");
    hashTable.insert("orange");

    hashTable.display();

    std::string keyToSearch = "orange";
    std::pair<int, int> result = hashTable.search(keyToSearch);
    if (result.first != -1) {
        std::cout << "Key '" << keyToSearch << "' found at Bucket " << result.first << ", Position " << result.second << std::endl;
    } else {
        std::cout << "Key '" << keyToSearch << "' not found" << std::endl;
    }

    std::string keyToRemove = "banana";
    hashTable.remove(keyToRemove);
    std::cout << "Removed key: " << keyToRemove << std::endl;

    std::cout << "Search for key " << keyToRemove << " after removal: " << (hashTable.search(keyToRemove).first != -1 ? "Found" : "Not found") << std::endl;

    std::cout << "Hash table contents:" << std::endl;
    hashTable.display();

    if (result.first != -1) {
        std::cout << "Key '" << keyToSearch << "' found at Bucket " << result.first << ", Position " << result.second << std::endl;
    } else {
        std::cout << "Key '" << keyToSearch << "' not found" << std::endl;
    }

    return 0;
}
