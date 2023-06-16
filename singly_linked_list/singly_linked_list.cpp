/* 
    g++ -o singly_linked_list singly_linked_list.cpp
    ./singly_linked_list 
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

typedef struct Node
{
   int value;
   struct Node *next;
} node_t;

node_t* sll_new_node(int val)
{
   node_t *res = new node_t;
   res->value = val;
   res->next = nullptr;
   return res;
}

/* node_t *head represents the head or the starting node of the linked list.
The head parameter is of type node_t*, which is a pointer to a node_t structure */

void sll_traverse(node_t *head)
{
    node_t *temp = head;
    while(temp != nullptr)
    {
        std::cout << temp->value << "-";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

int sll_findIndex(node_t *head, int element)
{
    int index = 0;
    node_t *curr = head;

    while (curr != nullptr)
    {
        if (curr->value == element)
        {
            return index;
        }

        curr = curr->next;
        index++;
        
    }
    
    // Element not found
    return -1;
}

void found_msg(int indx, int elem)
{
    if(indx == -1)
    {
        std::cout << "Element " << elem << " not found in the linked list." << std::endl;
    }
    else
    {
        std::cout << "Element " << elem << " found at index: " << indx << std::endl;
    }
}

node_t *sll_cloneLinkedList(node_t *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    // Create a map to store original nodes and their copies
    std::unordered_map<node_t *, node_t *> nodeMap;

    // Create a new head node for the cloned list
    node_t *newHead = sll_new_node(head->value);
    nodeMap[head] = newHead;

    node_t *curr = head->next;
    node_t *prev = newHead;

    while (curr != nullptr)
    {
        // Create a new node for the current node
        node_t *newNode = sll_new_node(curr->value);
        nodeMap[curr] = newNode;

        // Link the previous node to the new node
        prev->next = newNode;

        // Move to the next nodes
        curr = curr->next;
        prev = newNode;
    }

    // Set the next pointers for the cloned list
    curr = head;
    node_t *clonedCurrent = newHead;

    while (curr != nullptr)
    {
        clonedCurrent->next = nodeMap[curr->next];
        curr = curr->next;
        clonedCurrent = clonedCurrent->next;
    }

    return newHead;
}

void sll_removeDuplicates(struct Node* head) // first occurence is preserved
{
    // Hash to store unique values
    std::unordered_set<int> unique;
 
    /* Pick elements one by one */
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr != NULL) 
    {
        // If current value is seen before
        if (unique.find(curr->value) != unique.end()) 
        {
            prev->next = curr->next;
            delete (curr);
        }
        else 
        {
            unique.insert(curr->value);
            prev = curr;
        }
        curr = prev->next;
    }
}

/* node_t** head represents a double pointer to node_t. 
It means that head is a pointer variable that stores the memory address 
of another pointer variable, which in turn points to a node_t type.
The head parameter is the name given to this double pointer variable. 
For insert at index, delete at index, reverse opeartions the 
function prototype is similar to sll_operation(node_t **head, ...other args) 
and that function is called similar to sll_operation(&head, ...other args)*/

void sll_insertAtIndex(node_t **head, int val, int index)
{
    if (index < 0)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    node_t *newNode = sll_new_node(val);

    if (index == 0) // insertion at the beginning of the linked list
    {
        newNode->next = *head;
        *head = newNode;
    } 
    else 
    {
        node_t *curr = *head;
        int currentIndex = 0;

        while (curr != nullptr && currentIndex < index - 1) 
        {
            curr = curr->next;
            currentIndex++;
        }

        if (curr != nullptr) 
        {
            newNode->next = curr->next;
            curr->next = newNode;
        } 
        else 
        {
            std::cout << "Invalid index." << std::endl;
            delete newNode;
        }
    }
}

void sll_deleteAtIndex(node_t **head, int index)
{
    if (index < 0) 
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    if (*head == nullptr) 
    {
        std::cout << "Empty linked list." << std::endl;
        return;
    }

    if (index == 0) // deletion at the beginning of the linked list
    {
        node_t *temp = *head;
        *head = (*head)->next;
        delete temp;
    } 
    else 
    {
        node_t *curr = *head;
        int currentIndex = 0;

        while (curr != nullptr && currentIndex < index - 1) 
        {
            curr = curr->next;
            currentIndex++;
        }

        if (curr != nullptr && curr->next != nullptr) 
        {
            node_t *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } 
        else 
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
}

void sll_reverse(node_t **head)
{
    node_t *prev = nullptr;
    node_t *curr = *head;
    node_t *next = nullptr;

    while (curr != nullptr)
    {
        // Store the next node
        next = curr->next;

        // Reverse the next pointer of the current node
        curr->next = prev;

        // Move the pointers forward
        prev = curr;
        curr = next;
    }

    // Update the head pointer to the new head
    *head = prev;
}

void sll_init(node_t **head)
{
    node_t *tmp;

    tmp = sll_new_node(20);
    *head = tmp;

    tmp = sll_new_node(10);
    tmp->next = *head;
    *head = tmp;

    tmp = sll_new_node(15);
    tmp->next = *head;
    *head = tmp;
}

int main() 
{
    /* The head pointer is intially set to null pointer and then
    subsequently points to the first node of the linked list. */

    node_t *head = nullptr;

    sll_init(&head);
    sll_traverse(head);

    node_t *clonedList = sll_cloneLinkedList(head);
    sll_traverse(clonedList);

    sll_insertAtIndex(&head, 30, 0);
    sll_insertAtIndex(&head, 25, 2);
    sll_traverse(head);

    sll_deleteAtIndex(&head, 1);
    sll_traverse(head);

    sll_reverse(&head);
    sll_traverse(head);

    int target1 = 10;
    int idx1 = sll_findIndex(head, target1);
    found_msg(idx1, target1);

    int target2 = 45;
    int idx2 = sll_findIndex(head, target2);
    found_msg(idx2, target2);

    sll_traverse(head);

    sll_insertAtIndex(&head, 20, 0);
    sll_insertAtIndex(&head, 25, 5);
    sll_insertAtIndex(&head, 10, 3);
    sll_traverse(head);

    sll_removeDuplicates(head);
    sll_traverse(head);

    return 0;
}