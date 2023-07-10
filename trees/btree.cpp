/*
   g++ -std=c++11 -o btree btree.cpp
   ./btree
*/

#include <iostream>
#include <vector>

const int MAX_KEYS = 3;  // Maximum number of keys in each node
const int MIN_KEYS = 2;  // Minimum number of keys in each node

class BTreeNode {
public:
    bool isLeaf;                 // Indicates if the node is a leaf node
    std::vector<int> keys;       // Keys stored in the node
    std::vector<BTreeNode*> children;  // Pointers to child nodes

    BTreeNode(bool leaf = false) : isLeaf(leaf) {}
};

class BTree {
private:
    BTreeNode* root;

public:
    BTree() : root(nullptr) {}

    void insert(int key) {
        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == MAX_KEYS) {
                BTreeNode* newRoot = new BTreeNode(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0, root);
                insertNonFull(newRoot, key);
                root = newRoot;
            } else {
                insertNonFull(root, key);
            }
        }
    }

    void insertNonFull(BTreeNode* node, int key) {
        int i = node->keys.size() - 1;
        if (node->isLeaf) {
            node->keys.push_back(0);
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        } else {
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            i++;
            if (node->children[i]->keys.size() == MAX_KEYS) {
                splitChild(node, i, node->children[i]);
                if (key > node->keys[i])
                    i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

    void splitChild(BTreeNode* parent, int index, BTreeNode* child) {
        BTreeNode* newNode = new BTreeNode(child->isLeaf);
        parent->keys.insert(parent->keys.begin() + index, child->keys[MAX_KEYS / 2]);
        parent->children.insert(parent->children.begin() + index + 1, newNode);

        newNode->keys.assign(child->keys.begin() + MAX_KEYS / 2 + 1, child->keys.end());
        child->keys.resize(MAX_KEYS / 2);

        if (!child->isLeaf) {
            newNode->children.assign(child->children.begin() + MAX_KEYS / 2 + 1, child->children.end());
            child->children.resize(MAX_KEYS / 2 + 1);
        }
    }

    void traverse() {
        if (root != nullptr) {
            traverseNode(root);
        }
    }

    void traverseNode(BTreeNode* node) {
        int i;
        for (i = 0; i < node->keys.size(); i++) {
            if (!node->isLeaf) {
                traverseNode(node->children[i]);
            }
            std::cout << node->keys[i] << " ";
        }
        if (!node->isLeaf) {
            traverseNode(node->children[i]);
        }
    }
};

int main() {
    BTree btree;

    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);
    btree.insert(7);
    btree.insert(17);

    /*
            10, 20
            /     \
         5, 6    12, 17, 30
        /   |
       7    -
    */

    std::cout << "B-tree traversal: ";
    btree.traverse();
    std::cout << std::endl;

    return 0;
}