/*
    g++ -std=c++11 -o hashtable hashtable.cpp
    ./hashtable
*/

#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<std::pair<int, std::string>>> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        std::list<std::pair<int, std::string>>& bucket = table[index];

        // Check if the key already exists in the bucket
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }

        // If the key does not exist, insert a new pair
        bucket.push_back(std::make_pair(key, value));
    }

    std::string get(int key) {
        int index = hashFunction(key);
        std::list<std::pair<int, std::string>>& bucket = table[index];

        // Search for the key in the bucket
        for (const auto& pair : bucket) {
            if (pair.first == key) {
                return pair.second;
            }
        }

        // Key not found, return an empty string
        return "";
    }

    void remove(int key) {
        int index = hashFunction(key);
        std::list<std::pair<int, std::string>>& bucket = table[index];

        // Search for the key in the bucket
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::list<std::pair<int, std::string>>& bucket = table[i];

            if (!bucket.empty()) {
                std::cout << "Bucket " << i << ": ";

                for (const auto& pair : bucket) {
                    std::cout << pair.first << " -> " << pair.second << ", ";
                }

                std::cout << std::endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(1, "Alice");
    hashTable.insert(2, "Bob");
    hashTable.insert(11, "Charlie");
    hashTable.insert(21, "Dave");
    hashTable.insert(31, "Eve");

    std::cout << "Hash table contents:" << std::endl;
    hashTable.display();

    std::cout << "Value for key 2: " << hashTable.get(2) << std::endl;
    std::cout << "Value for key 11: " << hashTable.get(11) << std::endl;

    hashTable.remove(2);

    std::cout << "Hash table contents after removal:" << std::endl;
    hashTable.display();

    return 0;
}
