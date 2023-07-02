/*
    g++ -o queue_vector queue_vector.cpp
    ./queue_vector
*/

#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> queue;

public:
    void enqueue(int data);
    void dequeue();
    int front();
    int size();
    bool empty();
};

// Enqueue operation
void Queue::enqueue(int data) {
    queue.push_back(data);
}

// Dequeue operation
void Queue::dequeue() {
    if (queue.empty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    queue.erase(queue.begin());
}

// Front operation
int Queue::front() {
    if (queue.empty()) {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }

    return queue.front();
}

// Size operation
int Queue::size() {
    return queue.size();
}

// Empty operation
bool Queue::empty() {
    return queue.empty();
}

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Current size: " << queue.size() << std::endl;
    std::cout << "Front element: " << queue.front() << std::endl;

    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.front() << std::endl;

    return 0;
}
