/* 
    g++ -o stack_linkedlist stack_linkedlist.cpp
    ./stack_linkedlist 
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;
    int stackSize;

public:
    Stack() {
        topNode = nullptr;
        stackSize = 0;
    }

    ~Stack() {
        // Free the memory occupied by the linked list
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }

    void pop() {
        if (topNode == nullptr) {
            std::cout << "Stack underflow! Cannot pop element." << std::endl;
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }

    int top() {
        if (topNode == nullptr) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        return topNode->data;
    }

    bool empty() {
        return topNode == nullptr;
    }

    int size() {
        return stackSize;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack.top() << std::endl;  // Output: 3
    std::cout << "Stack size: " << stack.size() << std::endl;  // Output: 3

    stack.pop();

    std::cout << stack.top() << std::endl;  // Output: 2
    std::cout << "Stack size: " << stack.size() << std::endl;  // Output: 2

    return 0;
}
