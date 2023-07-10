/*
   g++ -std=c++11 -o tree tree.cpp
   ./tree
*/

#include <iostream>
#include <vector>

class TreeNode {
public:
    int data;
    std::vector<TreeNode*> children;

    TreeNode(int value) : data(value) {}
};

class Tree {
private:
    TreeNode* root;

    void destroyTree(TreeNode* node) {
        if (node) {
            for (TreeNode* child : node->children) {
                destroyTree(child);
            }
            delete node;
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        destroyTree(root);
    }

    TreeNode* createNode(int value) {
        return new TreeNode(value);
    }

    void setRoot(TreeNode* node) {
        root = node;
    }

    TreeNode* getRoot() {
        return root;
    }

    void insert(TreeNode* parent, TreeNode* child) {
        parent->children.push_back(child);
    }

    void traversePreorder(TreeNode* node) {
        if (node) {
            std::cout << node->data << " ";
            for (TreeNode* child : node->children) {
                traversePreorder(child);
            }
        }
    }

    void traversePostorder(TreeNode* node) {
        if (node) {
            for (TreeNode* child : node->children) {
                traversePostorder(child);
            }
            std::cout << node->data << " ";
        }
    }

    void traverseLevelOrder(TreeNode* root) {
        if (!root)
            return;

        std::vector<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            TreeNode* currNode = queue.front();
            queue.erase(queue.begin());

            std::cout << currNode->data << " ";

            for (TreeNode* child : currNode->children) {
                queue.push_back(child);
            }
        }
    }
};

int main() {
    Tree tree;

    TreeNode* root = tree.createNode(1);
    TreeNode* node2 = tree.createNode(2);
    TreeNode* node3 = tree.createNode(3);
    TreeNode* node4 = tree.createNode(4);
    TreeNode* node5 = tree.createNode(5);
    TreeNode* node6 = tree.createNode(6);

    tree.setRoot(root);
    tree.insert(root, node2);
    tree.insert(root, node3);
    tree.insert(root, node4);
    tree.insert(node2, node5);
    tree.insert(node2, node6);

    /*
             1
            /|\
            2 3 4
           / \
          5   6

    */

    std::cout << "Preorder traversal: "; // 1 2 5 6 3 4
    tree.traversePreorder(tree.getRoot());
    std::cout << std::endl;

    std::cout << "Postorder traversal: "; // 5 6 2 3 4 1
    tree.traversePostorder(tree.getRoot());
    std::cout << std::endl;

    std::cout << "Level-order traversal: "; // 1 2 3 4 5 6
    tree.traverseLevelOrder(tree.getRoot());
    std::cout << std::endl;

    return 0;
}