/*
   g++ -std=c++11 -o binary_search_tree binary_search_tree.cpp
   ./binary_search_tree
*/

#include <iostream>
#include <queue>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void destroyTree(TreeNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    TreeNode* getRoot() {
        return root;
    }

    void preOrderTraversal(TreeNode* node) {
        if (node) {
            std::cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(TreeNode* node) {
        if (node) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    void levelOrderTraversal(TreeNode* root) {
        if (!root)
            return;

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* currNode = queue.front();
            queue.pop();

            std::cout << currNode->data << " ";

            if (currNode->left)
                queue.push(currNode->left);
            if (currNode->right)
                queue.push(currNode->right);
        }
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    /*
           50
          /  \
        30     70
        / \    / \
       20 40  60 80
    */

    std::cout << "Pre-order traversal: "; // 50 30 20 40 70 60 80
    bst.preOrderTraversal(bst.getRoot());
    std::cout << std::endl;

    std::cout << "Post-order traversal: "; // 20 40 30 60 80 70 50
    bst.postOrderTraversal(bst.getRoot());
    std::cout << std::endl;

    std::cout << "Level-order traversal: "; // 50 30 70 20 40 60 80
    bst.levelOrderTraversal(bst.getRoot());
    std::cout << std::endl;

    return 0;
}