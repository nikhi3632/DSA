#include <iostream>
#include <vector>
#include <list>

// Internals: https://www.youtube.com/playlist?list=PLsdq-3Z1EPT2UnueESBLReaVSLIo_BuAc

// HashTable class
template<typename KeyType, typename ValueType>
class HashTable {
private:
    // HashNode struct to store key-value pairs
    struct HashNode {
        KeyType key;
        ValueType value;
        HashNode(const KeyType& k, const ValueType& v) : key(k), value(v) {}
    };

    std::vector<std::list<HashNode>> table;  // Array of linked lists
    size_t capacity;  // Capacity of the hash table

    // Hash function to compute the hash value of a key
    size_t hash(const KeyType& key) const {
        // Use a simple hash function for demonstration purposes
        return std::hash<KeyType>{}(key) % capacity;
    }

public:
    // Constructor
    HashTable(size_t size) : capacity(size) {
        table.resize(capacity);
    }

    // Insert a key-value pair into the hash table
    void insert(const KeyType& key, const ValueType& value) {
        size_t index = hash(key);
        for (const auto& node : table[index]) {
            if (node.key == key) {
                std::cout << "Key already exists. Updating value." << std::endl;
                node.value = value;
                return;
            }
        }
        table[index].push_back(HashNode(key, value));
    }

    // Retrieve the value associated with a key
    ValueType get(const KeyType& key) {
        size_t index = hash(key);
        for (const auto& node : table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        return ValueType();  // Return a default-constructed value if key not found
    }

    // Remove a key-value pair from the hash table
    void remove(const KeyType& key) {
        size_t index = hash(key);
        table[index].remove_if([&key](const HashNode& node) {
            return node.key == key;
        });
    }
};

int main() {
    // Create a hash table with a capacity of 10
    HashTable<std::string, int> ht(10);

    // Insert key-value pairs
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);

    // Retrieve values
    std::cout << "Value for key 'one': " << ht.get("one") << std::endl;
    std::cout << "Value for key 'two': " << ht.get("two") << std::endl;
    std::cout << "Value for key 'three': " << ht.get("three") << std::endl;

    // Remove a key-value pair
    ht.remove("two");
    std::cout << "Value for key 'two' after removal: " << ht.get("two") << std::endl;

    return 0;
}
