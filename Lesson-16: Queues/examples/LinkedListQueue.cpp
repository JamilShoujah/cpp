
// Using a linked list for a Queue is often the cleanest and most flexible approach because 
// it entirely avoids the size limitations and the circular logic required by arrays.

#include <iostream>

// --------------------------------------------------------------------------
// 1. Define the Node Structure
// --------------------------------------------------------------------------
// This structure represents one element in the queue.
struct Node {
    int data;       // The value stored in the node.
    Node* next;     // Pointer to the next node in the list.
};

// --------------------------------------------------------------------------
// 2. Class Definition for the Queue
// --------------------------------------------------------------------------
class Queue {
private:
    // 'front' pointer: Points to the first (oldest) element, ready for dequeue.
    Node* front; 
    
    // 'rear' pointer: Points to the last (newest) element, where enqueue happens.
    Node* rear; 

public:
    // Constructor to initialize the queue.
    Queue() {
        // Both pointers are set to nullptr when the queue is empty.
        front = nullptr; 
        rear = nullptr; 
        std::cout << "Linked List Queue initialized." << std::endl;
    }

    // Destructor to clean up memory when the Queue object is destroyed.
    ~Queue() {
        Node* current = front;
        Node* next;
        // Iterate through all nodes starting from the front and delete them 
        // to prevent memory leaks (crucial for linked lists).
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        front = nullptr;
        rear = nullptr;
        std::cout << "\nQueue memory successfully cleaned up." << std::endl;
    }

    // ----------------------------------------------------------------------
    // Core Utility Functions
    // ----------------------------------------------------------------------

    // Checks if the queue is empty.
    bool isEmpty() {
        // The queue is empty if the 'front' pointer is pointing to nothing.
        return front == nullptr;
    }

    // ----------------------------------------------------------------------
    // Core Queue Operations: enqueue, dequeue, peek
    // ----------------------------------------------------------------------
    
    // Adds an element to the rear of the queue (ENQUEUE operation).
    void enqueue(int data) {
        // 1. Create a new Node dynamically.
        Node* newNode = new Node;
        
        // Basic memory check
        if (!newNode) {
            std::cout << "ERROR: Memory allocation failed. Cannot enqueue." << std::endl;
            return;
        }

        // 2. Set the data for the new node and ensure its 'next' pointer is null 
        // since it will become the last node (rear).
        newNode->data = data; 
        newNode->next = nullptr; 

        // 3. Handle the special case of the FIRST element being added.
        if (isEmpty()) {
            // If the queue was empty, the new node is both the front and the rear.
            front = newNode; 
            rear = newNode; 
        } else {
            // 4. If the queue is NOT empty, link the current rear node to the new node.
            rear->next = newNode;
            
            // 5. Update 'rear' to point to the newly added node.
            rear = newNode; 
        }

        std::cout << "Enqueued: " << data << std::endl;
    }
    // 

    // Removes and returns the element from the front of the queue (DEQUEUE operation).
    int dequeue() {
        // 1. Check for Queue Underflow (Empty)
        if (isEmpty()) {
            std::cout << "ERROR: Queue Underflow! Cannot dequeue. Queue is empty." << std::endl;
            return 0; 
        }

        // 2. Save the pointer to the node that will be removed (the current front).
        Node* temp = front;           
        int dequeuedValue = front->data; // Get the data to return.

        // 3. Move 'front' to the next node in the list.
        front = front->next; 

        // 4. Check if the queue became empty after the removal.
        if (front == nullptr) {
            // If front is null, the queue is empty, so rear must also be set to null.
            rear = nullptr;
        }

        // 5. Delete the old front node to free up memory.
        delete temp;

        std::cout << "Dequeued: " << dequeuedValue << std::endl;
        return dequeuedValue;
    }

    // Returns the element at the front of the queue without removing it (PEEK operation).
    int peek() {
        // 1. Check for Underflow (Empty)
        if (isEmpty()) {
            std::cout << "ERROR: Cannot peek. Queue is empty." << std::endl;
            return 0;
        }

        // 2. Return the data of the node pointed to by 'front'.
        return front->data;
    }

    // ----------------------------------------------------------------------
    // Display Utility
    // ----------------------------------------------------------------------

    // Displays all elements in the queue from front to rear.
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Nothing to display." << std::endl;
            return;
        }

        // Use a temporary pointer to traverse the list without changing 'front'.
        Node* current = front; 

        std::cout << "\n--- Queue Content (Front -> Rear) ---" << std::endl;
        std::cout << "[ ";
        
        // Traverse the list until 'current' becomes nullptr (the end).
        while (current != nullptr) {
            std::cout << current->data;
            
            // Print labels
            if (current == front) std::cout << " (FRONT)";
            if (current == rear) std::cout << " (REAR)";
            
            if (current->next != nullptr) {
                std::cout << " | ";
            }

            // Move to the next node
            current = current->next;
        }
        std::cout << " ]" << std::endl;
        std::cout << "-------------------------------------\n" << std::endl;
    }
};

// --------------------------------------------------------------------------
// Main function for demonstration and testing
// --------------------------------------------------------------------------

int main() {
    Queue myQueue;
    
    // 1. Enqueue elements (FIFO: 10 is first in, 40 is last in)
    std::cout << "--- Step 1: Enqueue Elements ---" << std::endl;
    myQueue.enqueue(10); // Front and Rear point to 10
    myQueue.enqueue(20); 
    myQueue.enqueue(30); 
    myQueue.enqueue(40); // Rear points to 40
    
    myQueue.display(); 

    // 2. Peek at the front element
    std::cout << "Front element is: " << myQueue.peek() << std::endl;
    
    // 3. Dequeue elements
    std::cout << "\n--- Step 3: Dequeue Elements ---" << std::endl;
    myQueue.dequeue(); // Removes 10
    myQueue.dequeue(); // Removes 20
    
    myQueue.display(); // Front: 30, Rear: 40

    // 4. Enqueue more elements (no fixed size limit here!)
    std::cout << "--- Step 4: Enqueue More ---" << std::endl;
    myQueue.enqueue(50);
    myQueue.enqueue(60);
    
    myQueue.display(); // Front: 30, Rear: 60

    // 5. Emptying the queue and demonstrating Underflow
    std::cout << "\n--- Step 5: Emptying and Underflow Test ---" << std::endl;
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue(); 
    
    myQueue.display();

    // This dequeue should trigger the Queue Underflow error.
    myQueue.dequeue(); 

    // Note: Memory cleanup is automatically handled by the destructor.

    return 0;
}