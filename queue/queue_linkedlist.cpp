/*
    g++ -o queue_linkedlist queue_linkedlist.cpp
    ./queue_linkedlist
*/

#include <iostream>

class Queue {
private:
    struct Node
    {
        int data;
        struct Node *next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();
    void enqueue(int data);
    void dequeue();
    int frontElement();
    int queueSize();
    bool empty();
};

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() 
{
    while (front != nullptr) 
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::enqueue(int data) 
{
    Node* newNode = new Node(data);

    // If the queue is empty, set the new node as both front and rear
    if (empty()) 
    {
        front = newNode;
        rear = newNode;
    } 
    else 
    {
        // Otherwise, add the new node at the rear and update the rear pointer
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeue() 
{
    // Check if the queue is empty
    if (empty()) 
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    // Remove the front node and update the front pointer
    Node* temp = front;
    front = front->next;
    delete temp;

    // If the queue becomes empty, update the rear pointer as well
    if (front == nullptr) 
    {
        rear = nullptr;
    }
}

int Queue::frontElement() 
{
    // Check if the queue is empty
    if (empty()) 
    {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }

    // Return the data of the front node
    return front->data;
}

int Queue::queueSize() 
{
    int count = 0;
    Node* current = front;

    // Traverse the linked list and count the nodes
    while (current != nullptr) 
    {
        count++;
        current = current->next;
    }

    return count;
}

bool Queue::empty() 
{
    return (front == nullptr);
}

int main() 
{
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Current size: " << queue.queueSize() << std::endl;
    std::cout << "Front element: " << queue.frontElement() << std::endl;

    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.frontElement() << std::endl;
    return 0;
}
