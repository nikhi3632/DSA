/*
    g++ -std=c++11 -o hashtable_map_set hashtable_map_set.cpp
    ./hashtable_map_set
    The HashMap class implements a basic key-value mapping using a hash table.
    The HashSet class implements a simple set data structure using a hash table.
*/

#include <iostream>
#include <vector>
#include <list>

template<typename Key, typename Value>
class HashMap {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<std::pair<Key, Value>>> table;

    int hashFunction(const Key& key) {
        // Custom hash function based on the key's properties
        return std::hash<Key>()(key) % TABLE_SIZE;
    }

public:
    HashMap() {
        table.resize(TABLE_SIZE);
    }

    void insert(const Key& key, const Value& value) {
        int index = hashFunction(key);
        std::list<std::pair<Key, Value>>& bucket = table[index];

        // Check if the key already exists in the bucket
        for (auto& pair : bucket) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }

        // If the key does not exist, insert a new pair
        bucket.push_back(std::make_pair(key, value));
    }

    bool contains(const Key& key) {
        int index = hashFunction(key);
        std::list<std::pair<Key, Value>>& bucket = table[index];

        // Search for the key in the bucket
        for (const auto& pair : bucket) {
            if (pair.first == key) {
                return true;
            }
        }

        // Key not found
        return false;
    }

    Value& get(const Key& key) {
        int index = hashFunction(key);
        std::list<std::pair<Key, Value>>& bucket = table[index];

        // Search for the key in the bucket
        for (auto& pair : bucket) {
            if (pair.first == key) {
                return pair.second;
            }
        }

        // Key not found, throw an exception or return a default value
        throw std::out_of_range("Key not found");
    }

    void remove(const Key& key) {
        int index = hashFunction(key);
        std::list<std::pair<Key, Value>>& bucket = table[index];

        // Search for the key in the bucket
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

template<typename T>
class HashSet {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<T>> table;

    int hashFunction(const T& element) {
        // Custom hash function based on the element's properties
        return std::hash<T>()(element) % TABLE_SIZE;
    }

public:
    HashSet() {
        table.resize(TABLE_SIZE);
    }

    void insert(const T& element) {
        int index = hashFunction(element);
        std::list<T>& bucket = table[index];

        // Check if the element already exists in the bucket
        if (std::find(bucket.begin(), bucket.end(), element) != bucket.end()) {
            return;
        }

        // If the element does not exist, insert it
        bucket.push_back(element);
    }

    bool contains(const T& element) {
        int index = hashFunction(element);
        std::list<T>& bucket = table[index];

        // Search for the element in the bucket
        if (std::find(bucket.begin(), bucket.end(), element) != bucket.end()) {
            return true;
        }

        // Element not found
        return false;
    }

    void remove(const T& element) {
        int index = hashFunction(element);
        std::list<T>& bucket = table[index];

        // Search for the element in the bucket
        auto it = std::find(bucket.begin(), bucket.end(), element);
        if (it != bucket.end()) {
            bucket.erase(it);
        }
    }
};

int main() {
    // HashMap usage example
    HashMap<std::string, int> hashMap;
    hashMap.insert("Alice", 25);
    hashMap.insert("Bob", 30);
    hashMap.insert("Charlie", 35);

    std::cout << "Value for key 'Alice': " << hashMap.get("Alice") << std::endl;
    std::cout << "Value for key 'Bob': " << hashMap.get("Bob") << std::endl;

    hashMap.remove("Bob");
    std::cout << "Contains key 'Bob': " << (hashMap.contains("Bob") ? "Yes" : "No") << std::endl;

    // HashSet usage example
    HashSet<int> hashSet;
    hashSet.insert(10);
    hashSet.insert(20);
    hashSet.insert(30);

    std::cout << "Contains element 20: " << (hashSet.contains(20) ? "Yes" : "No") << std::endl;

    hashSet.remove(20);
    std::cout << "Contains element 20: " << (hashSet.contains(20) ? "Yes" : "No") << std::endl;

    return 0;
}
