class Node:
    """A node of a singly linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    """Singly Linked List with basic operations."""
    def __init__(self):
        self.head = None

    def insert_at_head(self, data):
        """Insert a new node at the beginning of the list."""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_tail(self, data):
        """Insert a new node at the end of the list."""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def delete_node(self, key):
        """Delete the first node with the given value."""
        temp = self.head

        # If head node itself holds the key
        if temp and temp.data == key:
            self.head = temp.next
            temp = None
            return

        # Search for the key to be deleted
        prev = None
        while temp and temp.data != key:
            prev = temp
            temp = temp.next

        # If key was not present in the list
        if not temp:
            print(f"Value {key} not found in list.")
            return

        # Unlink the node
        prev.next = temp.next
        temp = None

    def search(self, key):
        """Search for a value in the linked list."""
        temp = self.head
        while temp:
            if temp.data == key:
                return True
            temp = temp.next
        return False

    def display(self):
        """Print the linked list."""
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")

if __name__ == "__main__":
    sll = SinglyLinkedList()
    sll.insert_at_head(10)
    sll.insert_at_head(20)
    sll.insert_at_tail(30)
    sll.insert_at_tail(40)

    print("Linked List:")
    sll.display()

    print("\nDeleting 50:")
    sll.insert_at_tail(50)
    sll.display()

    print("\nDeleting 20:")
    sll.delete_node(20)
    sll.display()

    print("\nDeleting 60:")
    sll.insert_at_head(60)
    sll.display()

    print("\nDeleting 60:")
    sll.delete_node(60)
    sll.display()

    print("\nSearching for 30:", sll.search(30))
    print("Searching for 20:", sll.search(20))
