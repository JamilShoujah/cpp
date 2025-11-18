
// The Circular Queue is the correct way to implement a queue using a fixed-size array, 
// as it eliminates the wasted space limitation of the linear queue.


#include <iostream>

// Define the maximum size of our queue array.
// Note: In a circular queue, one slot is typically left unused 
// to easily distinguish between a full queue and an empty queue.
#define MAX_SIZE 5 

// --------------------------------------------------------------------------
// Class Definition for the Circular Queue
// --------------------------------------------------------------------------
class CircularQueue {
private:
    // Array to hold the queue elements.
    int arr[MAX_SIZE]; 
    
    // 'front' index: Points to the first element.
    int front; 
    
    // 'rear' index: Points to the last element.
    int rear; 

public:
    // Constructor to initialize the queue.
    CircularQueue() {
        // Initialize both pointers to -1 to signify that the queue is empty.
        front = -1; 
        rear = -1; 
        std::cout << "Circular Queue initialized (Max size: " << MAX_SIZE << ", Usable space: " << MAX_SIZE - 1 << ").\n" << std::endl;
    }

    // ----------------------------------------------------------------------
    // Core Utility Functions: Check State
    // ----------------------------------------------------------------------

    // Checks if the queue is completely full.
    bool isFull() {
        // The queue is full if the next position for 'rear' is equal to 'front'.
        // This is done using the modulo operator to handle wrapping around the array.
        // We leave one space empty to prevent the full state from looking identical to the empty state.
        return (rear + 1) % MAX_SIZE == front; 
    }

    // Checks if the queue is empty.
    bool isEmpty() {
        // The queue is empty if 'front' is -1.
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
            // If adding the first element, set front to 0.
            front = 0; 
        }

        // 3. Update 'rear' circularly using the modulo operator.
        // If rear is MAX_SIZE-1, (rear+1) % MAX_SIZE becomes 0 (wraps around).
        rear = (rear + 1) % MAX_SIZE; 

        // 4. Insert the new data at the new 'rear' position.
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
            // 4. Move 'front' one step forward circularly.
            // (front + 1) % MAX_SIZE handles wrapping around.
            front = (front + 1) % MAX_SIZE;
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

        std::cout << "\n--- Circular Queue Content (Front -> Rear) ---" << std::endl;
        std::cout << "Indices: ";
        
        int current = front;
        
        // Loop runs as long as the current index hasn't wrapped around past the rear.
        while (true) {
            std::cout << arr[current];
            
            // Print labels
            if (current == front) std::cout << " (FRONT)";
            if (current == rear) std::cout << " (REAR)";

            if (current == rear) {
                break; // Stop when we reach the rear
            }
            
            std::cout << " | ";
            // Move to the next index circularly
            current = (current + 1) % MAX_SIZE;
        }
        std::cout << "\n----------------------------------------------\n" << std::endl;
    }
};
// 

// --------------------------------------------------------------------------
// Main function for demonstration and testing
// --------------------------------------------------------------------------

int main() {
    CircularQueue myCircularQueue;
    
    // 1. Enqueue elements until the queue is full (MAX_SIZE 5 means 4 elements fit).
    std::cout << "--- Step 1: Initial Enqueue ---" << std::endl;
    myCircularQueue.enqueue(10); // front=0, rear=0
    myCircularQueue.enqueue(20); // front=0, rear=1
    myCircularQueue.enqueue(30); // front=0, rear=2
    myCircularQueue.enqueue(40); // front=0, rear=3 (FULL, since index 4 is the guard space)
    
    myCircularQueue.display(); 

    // This enqueue should trigger the Overflow error because (rear + 1) % 5 == front (4 % 5 == 0).
    myCircularQueue.enqueue(50); 

    // 2. Dequeue elements to free up space at the front (indices 0 and 1).
    std::cout << "\n--- Step 2: Dequeue 10 and 20 ---" << std::endl;
    myCircularQueue.dequeue(); // Removes 10. front moves to 1.
    myCircularQueue.dequeue(); // Removes 20. front moves to 2.
    
    myCircularQueue.display(); // Now 30(FRONT), 40(REAR)

    // 3. REUSE THE SPACE! (The advantage of Circular Queue)
    // We can now enqueue elements 50 and 60 into the freed space (indices 0 and 1).
    std::cout << "--- Step 3: Reusing Space (Circular Wrap) ---" << std::endl;
    myCircularQueue.enqueue(50); // rear = (3 + 1) % 5 = 4. (30, 40, _, _, 50)
    myCircularQueue.enqueue(60); // rear = (4 + 1) % 5 = 0. (60, _, _, _, 50) - WRAPPED!
    
    myCircularQueue.display(); // Front: 30(index 2), Rear: 60(index 0)

    // This push should trigger the Overflow error again: (rear + 1) % 5 == front
    // (0 + 1) % 5 = 1. Is 1 == front(2)? No. Wait, I made a mistake in my logic check.

    // Let's check the indices for the FULL condition:
    // front=2, rear=0. 
    // (rear + 1) % MAX_SIZE -> (0 + 1) % 5 = 1.
    // Is 1 == front(2)? No. So we can enqueue one more.
    
    myCircularQueue.enqueue(70); // rear = (0 + 1) % 5 = 1. (60, 70, 30, 40, 50)
    
    // Now: front=2, rear=1.
    // (rear + 1) % MAX_SIZE -> (1 + 1) % 5 = 2. 
    // Is 2 == front(2)? YES. Queue is FULL.

    myCircularQueue.display();

    // This enqueue should now trigger the Overflow error.
    myCircularQueue.enqueue(80); 

    return 0;
}