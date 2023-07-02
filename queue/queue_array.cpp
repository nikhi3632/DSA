/*
    g++ -o queue_array queue_array.cpp
    ./queue_array
*/

#include <iostream>
 
struct Queue 
{
    int front, rear, capacity;
    int* queue;
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int;
    }
 
    ~Queue() 
    { 
        delete[] queue; 
    }
 
    // function to insert an element
    // at the rear of the queue
    void enQueue(int data)
    {
        // check queue is full or not
        if (capacity == rear) 
        {
            printf("\nQueue is full\n");
            return;
        }
 
        // insert element at the rear
        else 
        {
            queue[rear] = data;
            rear++;
        }
        return;
    }
 
    // function to delete an element
    // from the front of the queue
    void deQueue()
    {
        // if queue is empty
        if (front == rear) 
        {
            printf("\nQueue is  empty\n");
            return;
        }
 
        // shift all the elements from index 2 till rear
        // to the left by one
        else 
        {
            for (int i = 0; i < rear - 1; i++) 
            {
                queue[i] = queue[i + 1];
            }
 
            // decrement rear
            rear--;
        }
        return;
    }

    bool isEmpty() {
        return front == rear;
    }
 
    // print queue elements
    void display()
    {
        if (isEmpty()) 
        {
            printf("\nQueue is Empty\n");
            return;
        }
 
        // traverse front to rear and print elements
        for (int i = front; i < rear; i++) 
        {
            printf(" %d <-- ", queue[i]);
        }
        return;
    }
 
    // print front of queue
    void frontElement()
    {
        if (isEmpty()) 
        {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d\n", queue[front]);
        return;
    }
};
 
// Driver code
int main(void)
{
    // Create a queue of capacity 4
    Queue q(4);
 
    // print Queue elements
    q.display();
 
    // inserting elements in the queue
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
 
    // print Queue elements
    q.display();
 
    // insert element in the queue
    q.enQueue(60);
 
    // print Queue elements
    q.display();
 
    q.deQueue();
    q.deQueue();
 
    printf("\n\nafter two node deletion\n\n");
 
    // print Queue elements
    q.display();
 
    // print front of the queue
    q.frontElement();
 
    return 0;
}