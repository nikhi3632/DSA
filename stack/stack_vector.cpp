/* 
    g++ -o stack_vector stack_vector.cpp
    ./stack_vector 
*/

#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int val) {
        data.push_back(val);
    }

    void pop() {
        if (data.empty()) {
            std::cout << "Stack underflow! Cannot pop element." << std::endl;
            return;
        }
        data.pop_back();
    }

    int top() {
        if (data.empty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return data.back();
    }

    bool empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack.top() << std::endl;  // Output: 3
    std::cout << "Stack size: " << stack.size() << std::endl;

    stack.pop();

    std::cout << stack.top() << std::endl;  // Output: 2
    std::cout << "Stack size: " << stack.size() << std::endl;

    return 0;
}
