#include <iostream>

// --------------------------------------------------------------------------
// 1. Define the Node Structure
// --------------------------------------------------------------------------
// This structure represents one element in the Deque.
struct Node {
    int data;       // The value stored in the node.
    Node* prev;     // Pointer to the previous node (for going backward).
    Node* next;     // Pointer to the next node (for going forward).
};

// --------------------------------------------------------------------------
// 2. Class Definition for the Deque
// --------------------------------------------------------------------------
class Deque {
private:
    // 'front' pointer: Points to the first element (head).
    Node* front; 
    
    // 'rear' pointer: Points to the last element (tail).
    Node* rear; 

public:
    // Constructor to initialize the Deque.
    Deque() {
        // Both pointers are set to nullptr when the Deque is empty.
        front = nullptr; 
        rear = nullptr; 
        std::cout << "Doubly Linked List Deque initialized." << std::endl;
    }

    // Destructor to clean up memory.
    ~Deque() {
        Node* current = front;
        Node* next;
        // Iterate through all nodes starting from the front and delete them.
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        front = nullptr;
        rear = nullptr;
        std::cout << "\nDeque memory successfully cleaned up." << std::endl;
    }

    // ----------------------------------------------------------------------
    // Core Utility Function
    // ----------------------------------------------------------------------

    // Checks if the Deque is empty.
    bool isEmpty() {
        return front == nullptr;
    }

    // ----------------------------------------------------------------------
    // Insertion Operations (Front and Rear)
    // ----------------------------------------------------------------------

    // Adds an element to the FRONT of the Deque.
    void insertFront(int data) {
        Node* newNode = new Node;
        if (!newNode) {
            std::cout << "ERROR: Memory allocation failed." << std::endl;
            return;
        }
        
        newNode->data = data;
        newNode->prev = nullptr; // New front node always has no previous node.
        newNode->next = front;  // New front node points to the OLD front node.

        // Handle the case where the Deque is NOT empty.
        if (!isEmpty()) {
            // The old front node must now point its 'prev' back to the new node.
            front->prev = newNode;
        } else {
            // If it was empty, the new node is also the rear.
            rear = newNode;
        }

        // The Deque's front pointer always moves to the new node.
        front = newNode;
        std::cout << "Inserted front: " << data << std::endl;
    }

    // Adds an element to the REAR of the Deque.
    void insertRear(int data) {
        Node* newNode = new Node;
        if (!newNode) {
            std::cout << "ERROR: Memory allocation failed." << std::endl;
            return;
        }
        
        newNode->data = data;
        newNode->next = nullptr; // New rear node always has no next node.
        newNode->prev = rear;   // New rear node points to the OLD rear node.

        // Handle the case where the Deque is NOT empty.
        if (!isEmpty()) {
            // The old rear node must now point its 'next' forward to the new node.
            rear->next = newNode;
        } else {
            // If it was empty, the new node is also the front.
            front = newNode;
        }

        // The Deque's rear pointer always moves to the new node.
        rear = newNode;
        std::cout << "Inserted rear: " << data << std::endl;
    }

    // ----------------------------------------------------------------------
    // Deletion Operations (Front and Rear)
    // ----------------------------------------------------------------------

    // Removes and returns the element from the FRONT (Dequeue action).
    int deleteFront() {
        if (isEmpty()) {
            std::cout << "ERROR: Deque is empty (Underflow). Cannot delete from front." << std::endl;
            return 0; 
        }

        Node* temp = front;           
        int deletedValue = front->data;

        // Move the Deque's front pointer one step forward.
        front = front->next; 

        // Check if there is a new front (i.e., the list wasn't empty after removal).
        if (front != nullptr) {
            // The new front node must have its 'prev' pointer set to null.
            front->prev = nullptr;
        } else {
            // If front is null, the list is now empty, so rear must also be null.
            rear = nullptr;
        }

        delete temp; // Free the old front node's memory.
        std::cout << "Deleted front: " << deletedValue << std::endl;
        return deletedValue;
    }

    // Removes and returns the element from the REAR (Stack Pop action).
    int deleteRear() {
        if (isEmpty()) {
            std::cout << "ERROR: Deque is empty (Underflow). Cannot delete from rear." << std::endl;
            return 0; 
        }

        Node* temp = rear;           
        int deletedValue = rear->data;

        // Move the Deque's rear pointer one step backward.
        rear = rear->prev; 

        // Check if there is a new rear (i.e., the list wasn't empty after removal).
        if (rear != nullptr) {
            // The new rear node must have its 'next' pointer set to null.
            rear->next = nullptr;
        } else {
            // If rear is null, the list is now empty, so front must also be null.
            front = nullptr;
        }

        delete temp; // Free the old rear node's memory.
        std::cout << "Deleted rear: " << deletedValue << std::endl;
        return deletedValue;
    }

    // ----------------------------------------------------------------------
    // Access Operations
    // ----------------------------------------------------------------------
    
    // Returns the element at the front without removing it.
    int getFront() {
        if (isEmpty()) {
            std::cout << "ERROR: Deque is empty. Cannot get front." << std::endl;
            return 0;
        }
        return front->data;
    }

    // Returns the element at the rear without removing it.
    int getRear() {
        if (isEmpty()) {
            std::cout << "ERROR: Deque is empty. Cannot get rear." << std::endl;
            return 0;
        }
        return rear->data;
    }

    // ----------------------------------------------------------------------
    // Display Utility
    // ----------------------------------------------------------------------

    // Displays all elements in the Deque from front to rear.
    void display() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Nothing to display." << std::endl;
            return;
        }

        Node* current = front; 
        std::cout << "\n--- Deque Content (Front -> Rear) ---" << std::endl;
        
        while (current != nullptr) {
            std::cout << "[";
            
            // Indicate the direction the list points
            if (current->prev != nullptr) std::cout << " <-";
            
            std::cout << current->data;
            
            if (current->next != nullptr) std::cout << " ->";
            
            std::cout << "]";

            // Print labels
            if (current == front) std::cout << " (FRONT)";
            if (current == rear) std::cout << " (REAR)";
            
            std::cout << std::endl;
            current = current->next;
        }
        std::cout << "-------------------------------------\n" << std::endl;
    }
};

// --------------------------------------------------------------------------
// Main function for demonstration and testing
// --------------------------------------------------------------------------

int main() {
    Deque myDeque;
    
    std::cout << "--- Step 1: Initial Insertions ---" << std::endl;
    // Insert at Rear (Queue Enqueue)
    myDeque.insertRear(10); // Rear: 10
    myDeque.insertRear(20); // Rear: 20
    
    // Insert at Front (Stack Push)
    myDeque.insertFront(5); // Front: 5
    myDeque.insertFront(1); // Front: 1
    
    // Deque is now: [1 (Front) | 5 | 10 | 20 (Rear)]
    myDeque.display(); 

    // 2. Peek operations
    std::cout << "--- Step 2: Peeking ---" << std::endl;
    std::cout << "Front item is: " << myDeque.getFront() << std::endl; // Should be 1
    std::cout << "Rear item is: " << myDeque.getRear() << std::endl;   // Should be 20
    
    // 3. Deletion operations
    std::cout << "\n--- Step 3: Deletions ---" << std::endl;
    
    // Delete from Rear (Stack Pop)
    myDeque.deleteRear();   // Removes 20. Rear is now 10.
    
    // Delete from Front (Queue Dequeue)
    myDeque.deleteFront(); // Removes 1. Front is now 5.
    
    // Deque is now: [5 (Front) | 10 (Rear)]
    myDeque.display(); 

    // 4. Emptying and testing Underflow
    std::cout << "\n--- Step 4: Emptying and Underflow ---" << std::endl;
    myDeque.deleteRear(); // Removes 10
    myDeque.deleteFront(); // Removes 5 (Deque is now empty)

    myDeque.display();

    // This should trigger the Underflow error.
    myDeque.deleteFront(); 
    myDeque.deleteRear(); 

    return 0;
}