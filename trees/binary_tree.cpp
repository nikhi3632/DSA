/*
    g++ -std=c++11 -o binary_tree binary_tree.cpp
    ./binary_tree

    Inorder Traversal: In inorder traversal, nodes are visited in the following order: 
    left subtree, root, right subtree. This means that for a binary tree, the left child is visited first, 
    then the root node, and finally the right child. In a general tree, the leftmost child is visited first, 
    followed by the remaining children in their respective order, and then the parent node.

    Postorder Traversal: In postorder traversal, nodes are visited in the following order: left subtree, 
    right subtree, root. This means that for a binary tree, the left child is visited first, then the 
    right child, and finally the root node. In a general tree, the children are visited from left to right 
    in their respective order, and then the parent node.

    Preorder Traversal: In preorder traversal, nodes are visited in the following order: root, left subtree, 
    right subtree. This means that for a binary tree, the root node is visited first, then the left child, 
    and finally the right child. In a general tree, the parent node is visited first, followed by the children 
    in their respective order.
*/

#include <iostream>
#include <vector>

typedef struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
} treenode_t;

class BinaryTree {
private:
    treenode_t* root;

    void destroyTree(treenode_t* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void preorderTraversalHelper(treenode_t* node) {
        if (node) {
            std::cout << node->data << " ";
            preorderTraversalHelper(node->left);
            preorderTraversalHelper(node->right);
        }
    }

    void inorderTraversalHelper(treenode_t* node) {
        if (node) {
            inorderTraversalHelper(node->left);
            std::cout << node->data << " ";
            inorderTraversalHelper(node->right);
        }
    }

    void postorderTraversalHelper(treenode_t* node) {
        if (node) {
            postorderTraversalHelper(node->left);
            postorderTraversalHelper(node->right);
            std::cout << node->data << " ";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    treenode_t* createNode(int value) {
        return new Node(value);
    }

    void setRoot(treenode_t* node) {
        root = node;
    }

    void setLeft(treenode_t* parent, treenode_t* child) {
        parent->left = child;
    }

    void setRight(treenode_t* parent, treenode_t* child) {
        parent->right = child;
    }

    void preorderTraversal() {
        preorderTraversalHelper(root);
        std::cout << std::endl;
    }

    void inorderTraversal() {
        inorderTraversalHelper(root);
        std::cout << std::endl;
    }

    void postorderTraversal() {
        postorderTraversalHelper(root);
        std::cout << std::endl;
    }

};

int main() {
    BinaryTree binaryTree;

    // Create nodes
    treenode_t* node1 = binaryTree.createNode(1);
    treenode_t* node2 = binaryTree.createNode(2);
    treenode_t* node3 = binaryTree.createNode(3);
    treenode_t* node4 = binaryTree.createNode(4);
    treenode_t* node5 = binaryTree.createNode(5);
    treenode_t* node6 = binaryTree.createNode(6);

    // Set root and connect nodes
    binaryTree.setRoot(node1);
    binaryTree.setLeft(node1, node2);
    binaryTree.setRight(node1, node3);
    binaryTree.setLeft(node2, node4);
    binaryTree.setLeft(node3, node5);
    binaryTree.setRight(node3, node6);

    /*
                1
               /  \
              /    \
             /      \
            /        \
           2          3
          / \       /   \
         4   NULL   5    6
    */


    // Perform preorder traversal
    std::cout << "Preorder traversal: ";
    binaryTree.preorderTraversal();

    // Perform inorder traversal
    std::cout << "Inorder traversal: ";
    binaryTree.inorderTraversal();

    // Perform postorder traversal
    std::cout << "Postorder traversal: ";
    binaryTree.postorderTraversal();

    return 0;
}