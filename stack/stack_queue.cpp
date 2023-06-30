
/*
    g++ -o stack_queue stack_queue.cpp
    ./stack_queue

    It is possible to achieve either O(1) push or O(1) pop operation using a single queue 
    for stack implementation.

    If you want to make push operation O(1) and pop operation O(n), you can enqueue the new element 
    at the front of the queue and dequeue elements one by one until you reach the rear. This way, 
    the newly pushed element will always be at the front and ready to be popped in constant time. 
    However, when you perform a pop operation, you will need to transfer all the elements from the 
    rear to the front of the queue, resulting in a time complexity of O(n).

    If you want to make pop operation O(1) and push operation O(n), you can enqueue the new element at the 
    rear of the queue. When you perform a pop operation, you can simply dequeue the element from the rear, 
    which will be the top of the stack. However, when you perform a push operation, you will need to transfer 
    all the elements from the front to the rear of the queue, resulting in a time complexity of O(n).

    While it is possible to achieve O(1) time complexity for one of the operations using a single queue, 
    the other operation will have a time complexity of O(n), where n is the number of elements in the stack. 
*/

#include <iostream>
#include <queue>

class StackPushCostly 
{
    /*
    Time Complexity:
        Push operation: O(N) because it involves transferring all the elements from the front to the rear of 
        the queue, resulting in a linear time complexity proportional to the number of elements in the queue.
        Pop operation: O(1)
    Space Complexity: O(N) since 1 queue is used.
    */
 
    std::queue<int> q;
 
public:
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
};
 
// Push operation
void StackPushCostly::push(int data)
{
    //  Get previous size of queue
    int s = q.size();
 
    // Push the current element
    q.push(data);
 
    // Pop all the previous elements and put them after
    // current element
 
    for (int i = 0; i < s; i++) 
    {
        // Add the front element again
        q.push(q.front());
 
        // Delete front element
        q.pop();
    }
}
 
// Removes the top element
void StackPushCostly::pop()
{
    if (q.empty())
        std::cout << "No elements\n";
    else
        q.pop();
}
 
// Returns top of stack
int StackPushCostly::top()
{ 
    return (q.empty()) ? -1 : q.front(); 
}
 
// Returns true if Stack is empty else false
bool StackPushCostly::empty() 
{ 
    return (q.empty()); 
}
 
int StackPushCostly::size() 
{ 
    return q.size(); 
}

class StackPopCostly {
    /*
        The push operation simply enqueues the new element at the rear of the queue, 
        which takes constant time (O(1)). However, the pop and top operations require moving 
        all the elements except the last one to the rear of the queue, which takes O(n) time, 
        where n is the number of elements in the stack.
    */
private:
    std::queue<int> q;

public:
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
};

// Push operation (O(1))
void StackPopCostly::push(int data) 
{
    q.push(data);
}

// Pop operation (O(n))
void StackPopCostly::pop() 
{
    if (q.empty()) 
    {
        std::cout << "Stack underflow! Cannot pop element." << std::endl;
        return;
    }

    // Move all elements except the last one to the rear
    int n = q.size();
    for (int i = 0; i < n - 1; i++) 
    {
        q.push(q.front());
        q.pop();
    }

    // Remove the last element
    q.pop();
}

// Top operation (O(n))
int StackPopCostly::top() 
{
    if (q.empty()) 
    {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }

    // Move all elements except the last one to the rear
    int n = q.size();
    for (int i = 0; i < n - 1; i++) 
    {
        q.push(q.front());
        q.pop();
    }

    // Get the last element
    int topElement = q.front();

    // Move the last element to the rear
    q.push(q.front());
    q.pop();

    return topElement;
}

// Size operation
int StackPopCostly::size() 
{
    return q.size();
}

// Empty operation
bool StackPopCostly::empty() 
{
    return q.empty();
}

void testPushCostlyStack()
{
    StackPushCostly pushCostlyStack;
    pushCostlyStack.push(1);
    pushCostlyStack.push(2);
    pushCostlyStack.push(3);
    std::cout << "current size: " << pushCostlyStack.size() << "\n";
    std::cout << pushCostlyStack.top() << "\n";
    pushCostlyStack.pop();
    std::cout << pushCostlyStack.top() << "\n";
    pushCostlyStack.pop();
    std::cout << pushCostlyStack.top() << "\n";
    std::cout << "current size: " << pushCostlyStack.size() << std::endl;
}

void testPopCostlyStack()
{
    StackPopCostly popCostlyStack;
    popCostlyStack.push(1);
    popCostlyStack.push(2);
    popCostlyStack.push(3);
    std::cout << "current size: " << popCostlyStack.size() << "\n";
    std::cout << popCostlyStack.top() << "\n";
    popCostlyStack.pop();
    std::cout << popCostlyStack.top() << "\n";
    popCostlyStack.pop();
    std::cout << popCostlyStack.top() << "\n";
    std::cout << "current size: " << popCostlyStack.size() << std::endl;
}

int main()
{
    testPushCostlyStack();
    std::cout << "-----------------------------------------------" <<std::endl;
    testPopCostlyStack();
    return 0;
}