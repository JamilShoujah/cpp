#include <iostream>

// Define the maximum size of our queue array.
#define MAX_SIZE 5 

// --------------------------------------------------------------------------
// Class Definition for the Queue (Linear Array Implementation)
// --------------------------------------------------------------------------
class Queue {
private:
    // Array to hold the queue elements.
    int arr[MAX_SIZE]; 
    
    // 'front' index: Points to the first (oldest) element, ready for dequeue.
    int front; 
    
    // 'rear' index: Points to the last (newest) element, where the next element is added.
    int rear; 

public:
    // Constructor to initialize the queue.
    Queue() {
        // Initialize both pointers to -1 to signify that the queue is empty.
        front = -1; 
        rear = -1; 
        std::cout << "Queue initialized (Max size: " << MAX_SIZE << ").\n" << std::endl;
    }

    // ----------------------------------------------------------------------
    // Core Utility Functions: Check State
    // ----------------------------------------------------------------------

    // Checks if the queue is completely full.
    bool isFull() {
        // The queue is full when 'rear' reaches the last valid index (MAX_SIZE - 1).
        return rear == MAX_SIZE - 1; 
    }

    // Checks if the queue is empty.
    bool isEmpty() {
        // The queue is empty if both front and rear are -1, OR if front has moved past rear.
        // The simplest check is if 'front' is -1 (meaning it was reset after the last dequeue).
        return front == -1;
    }

    // ----------------------------------------------------------------------
    // Core Queue Operations: enqueue, dequeue, peek
    // ----------------------------------------------------------------------
    
    // Adds an element to the rear of the queue (ENQUEUE operation).
    void enqueue(int data) {
        // 1. Check for Queue Overflow (Full)
        if (isFull()) {
            std::cout << "ERROR: Queue Overflow! Cannot enqueue " << data << ". Queue is full." << std::endl;
            return;
        }

        // 2. Handle the special case of the FIRST element being added.
        if (isEmpty()) {
            // When adding the first element, both front and rear move to index 0.
            front = 0; 
        }

        // 3. Increment 'rear' to the next available spot.
        rear++; 

        // 4. Insert the new data at the 'rear' position.
        arr[rear] = data; 
        std::cout << "Enqueued: " << data << std::endl;
    }

    // Removes and returns the element from the front of the queue (DEQUEUE operation).
    int dequeue() {
        // 1. Check for Queue Underflow (Empty)
        if (isEmpty()) {
            std::cout << "ERROR: Queue Underflow! Cannot dequeue. Queue is empty." << std::endl;
            return 0; 
        }

        // 2. Retrieve the value currently at the 'front' index.
        int dequeuedValue = arr[front]; 

        // 3. Check for the special case: the last element is being dequeued.
        if (front == rear) {
            // If the last element is removed, reset the queue to the empty state.
            front = -1;
            rear = -1;
        } else {
            // 4. Move 'front' one step forward to the next element.
            front++;
        }

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

        // 2. Return the value at the current 'front' index.
        return arr[front];
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

        std::cout << "\n--- Queue Content (Front -> Rear) ---" << std::endl;
        std::cout << "[ ";
        
        // Iterate from 'front' index up to 'rear' index.
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i];
            
            // Print separators and labels
            if (i == front) std::cout << " (FRONT)";
            if (i == rear) std::cout << " (REAR)";
            
            if (i < rear) {
                std::cout << " | ";
            }
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
    
    // 1. Enqueue elements (FIFO: 10 is the first out, 40 is the last in)
    std::cout << "--- Step 1: Enqueue Elements ---" << std::endl;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    
    myQueue.display(); // Front: 10, Rear: 30

    // 2. Dequeue elements
    std::cout << "--- Step 2: Dequeue Elements ---" << std::endl;
    myQueue.dequeue(); // Removes 10 (Front moves to 20)
    myQueue.dequeue(); // Removes 20 (Front moves to 30)
    
    myQueue.display(); // Front: 30, Rear: 30

    // 3. Peek at the front element
    std::cout << "Front element is: " << myQueue.peek() << std::endl;
    
    // 4. Filling the rest of the queue
    std::cout << "\n--- Step 4: Filling and Overflowing ---" << std::endl;
    myQueue.enqueue(40); // Rear moves to index 3
    myQueue.enqueue(50); // Rear moves to index 4 (Queue is now FULL)
    
    myQueue.display();

    // This push should trigger the Queue Overflow error.
    myQueue.enqueue(60); 

    // 5. Demonstrate the Linear Queue Limitation
    // If we dequeue 30, 40, and 50, the queue is empty, but front/rear are at index 4/4.
    std::cout << "\n--- Step 5: Dequeue and Limitation ---" << std::endl;
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue(); // Queue is now empty, front=-1, rear=-1

    myQueue.display();

    // This shows the limitation: Even though indices 0, 1, 2, 3 were freed, 
    // we cannot enqueue anything unless we use a Circular Queue implementation.
    myQueue.enqueue(70); 

    // This pop should trigger the Underflow error.
    myQueue.dequeue(); 

    return 0;
}