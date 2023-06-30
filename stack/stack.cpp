/* 
    g++ -o stack stack.cpp
    ./stack 
*/

#include <iostream>
#include <stack>

int main() {
    /*
        T.C:
            Push: O(1)
            Pop : O(1)
            Top : O(1)
        S.C: O(n)
    */
    std::stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;  // Output: 3

    stack.pop();

    std::cout << "Top element: " << stack.top() << std::endl;  // Output: 2

    std::cout << "Stack size: " << stack.size() << std::endl;  // Output: 2

    std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;  // Output: No

    return 0;
}
