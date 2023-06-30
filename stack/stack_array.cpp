/* 
    g++ -o stack_array stack_array.cpp
    ./stack_array 
*/

#include <iostream>

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;
    int stackSize;

public:
    Stack(int size) {
        capacity = size;
        data = new int[capacity];
        topIndex = -1;
        stackSize = 0;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int val) {
        if (topIndex == capacity - 1) {
            std::cout << "Stack overflow! Cannot push element." << std::endl;
            return;
        }

        topIndex++;
        data[topIndex] = val;
        stackSize++;
    }

    void pop() {
        if (topIndex == -1) {
            std::cout << "Stack underflow! Cannot pop element." << std::endl;
            return;
        }

        topIndex--;
        stackSize--;
    }

    int top() {
        if (topIndex == -1) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        return data[topIndex];
    }

    bool empty() {
        return topIndex == -1;
    }

    int size() {
        return stackSize;
    }
};

int main() {
    Stack stack(5);

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
