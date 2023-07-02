/* 
    g++ -o queue queue.cpp
    ./queue 
*/

#include <iostream>
#include <queue>

int main() {
    /*
        T.C:
            Push: O(1)
            Pop : O(1)
            Front : O(1)
        S.C: O(n)
    */
    std::queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << "Front element: " << queue.front() << std::endl;  // Output: 3

    queue.pop();

    std::cout << "Front element: " << queue.front() << std::endl;  // Output: 2

    std::cout << "Queue size: " << queue.size() << std::endl;  // Output: 2

    std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;  // Output: No

    return 0;
}
