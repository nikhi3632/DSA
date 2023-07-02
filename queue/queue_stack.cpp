/*
    g++ -o queue_stack queue_stack.cpp
    ./queue_stack

    Using a single stack, you can achieve O(1) time complexity for enqueue or dequeue, 
    but not for both operations simultaneously. One operation will always have a time complexity of O(n), 
    where n is the number of elements in the queue.

    In the enqueue costly implementation the enqueue operation has a time complexity of O(n) 
    because it involves transferring all the elements from the main stack to a temporary stack 
    and then pushing the new element to the bottom of the main stack. However, the dequeue operation 
    has a time complexity of O(1) since it simply pops the top element from the stack.

    In the dequeue costly implementation the enqueue operation simply pushes the element to the stack, 
    which takes constant time (O(1)). The dequeue operation involves moving all elements except the 
    last one from the main stack to a temporary stack, removing the last element from the main stack, 
    and then moving the elements back from the temporary stack to the main stack. 
    This ensures that the element at the bottom of the stack is always the front element of the queue, 
    achieving O(1) time complexity for dequeue.
*/

#include <iostream>
#include <stack>

class QueueEnqueueCostly {
private:
    std::stack<int> stack;

public:
    void enqueue(int data);
    void dequeue();
    int front();
    int size();
    bool empty();
};

// Dequeue operation (O(1))
void QueueEnqueueCostly::dequeue() {
    if (stack.empty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    // Pop the front element from the stack
    stack.pop();
}

// Enqueue operation (O(n))
void QueueEnqueueCostly::enqueue(int data) {
    // Create a temporary stack
    std::stack<int> tempStack;

    // Move all elements from the main stack to the temporary stack
    while (!stack.empty()) {
        tempStack.push(stack.top());
        stack.pop();
    }

    // Push the new element to the bottom of the main stack
    stack.push(data);

    // Move back all elements from the temporary stack to the main stack
    while (!tempStack.empty()) {
        stack.push(tempStack.top());
        tempStack.pop();
    }
}

// Front operation (O(1))
int QueueEnqueueCostly::front() {
    if (stack.empty()) {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }

    // Return the top element of the stack, which is the front of the queue
    return stack.top();
}

// Size operation
int QueueEnqueueCostly::size() {
    return stack.size();
}

// Empty operation
bool QueueEnqueueCostly::empty() {
    return stack.empty();
}

void testQueueEnqueueCostly() {
    QueueEnqueueCostly queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Current size: " << queue.size() << std::endl;
    std::cout << "Front element: " << queue.front() << std::endl;

    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.front() << std::endl;
}

class QueueDequeueCostly {
private:
    std::stack<int> stack;

public:
    void enqueue(int data);
    void dequeue();
    int front();
    int size();
    bool empty();
};

// Enqueue operation (O(1))
void QueueDequeueCostly::enqueue(int data) {
    stack.push(data);
}

// Dequeue operation (O(n))
void QueueDequeueCostly::dequeue() {
    if (stack.empty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    // Create a temporary stack
    std::stack<int> tempStack;

    // Move all elements except the last one from the main stack to the temporary stack
    while (stack.size() > 1) {
        tempStack.push(stack.top());
        stack.pop();
    }

    // Remove the last element from the main stack
    stack.pop();

    // Move back all elements from the temporary stack to the main stack
    while (!tempStack.empty()) {
        stack.push(tempStack.top());
        tempStack.pop();
    }
}

// Front operation (O(n))
int QueueDequeueCostly::front() {
    if (stack.empty()) {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }

    // Create a temporary stack
    std::stack<int> tempStack;

    // Move all elements except the last one from the main stack to the temporary stack
    while (stack.size() > 1) {
        tempStack.push(stack.top());
        stack.pop();
    }

    // Get the front element from the main stack
    int frontElement = stack.top();

    // Move back all elements from the temporary stack to the main stack
    while (!tempStack.empty()) {
        stack.push(tempStack.top());
        tempStack.pop();
    }

    return frontElement;
}

// Size operation
int QueueDequeueCostly::size() {
    return stack.size();
}

// Empty operation
bool QueueDequeueCostly::empty() {
    return stack.empty();
}

void testQueueDequeueCostly() {
    QueueDequeueCostly queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Current size: " << queue.size() << std::endl;
    std::cout << "Front element: " << queue.front() << std::endl;

    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.front() << std::endl;
}

int main() {
    testQueueEnqueueCostly();
    std::cout << "-----------------------------------------------" <<std::endl;
    testQueueDequeueCostly();
    return 0;
}
