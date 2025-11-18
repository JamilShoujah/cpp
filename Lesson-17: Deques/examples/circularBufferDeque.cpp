#include <iostream>
#include <stdexcept>

// --------------------------------------------------------------------------
// Class Definition for the Deque (Circular Dynamic Array)
// --------------------------------------------------------------------------
class Deque {
private:
    int* arr;       // Dynamically allocated array (the circular buffer).
    int front;      // Index of the first element.
    int rear;       // Index of the last element.
    int size;       // Current number of elements in the Deque.
    int capacity;   // Total size of the underlying array.

    // Helper function to handle resizing the array when capacity is reached.
    void resize(int newCapacity) {
        // Double the capacity for efficient growth.
        int* newArr = new int[newCapacity];
        if (!newArr) {
            std::cerr << "ERROR: Failed to allocate memory during resize." << std::endl;
            return;
        }

        // Copy elements from the old array to the new one, 
        // preserving the logical front-to-rear order.
        for (int i = 0; i < size; ++i) {
            // Calculate the current index in the old circular array.
            int oldIndex = (front + i) % capacity;
            // Place the element at the beginning (index i) of the new linear array.
            newArr[i] = arr[oldIndex];
        }

        // Clean up the old array.
        delete[] arr;
        
        // Update the Deque's state pointers to the new, linearized array.
        arr = newArr;
        capacity = newCapacity;
        front = 0; // New front is always index 0
        rear = size - 1; // New rear is always size - 1

        std::cout << "\n[RESIZED: New capacity is " << capacity << "]\n";
    }

public:
    // Constructor
    Deque(int initialCapacity = 4) : front(-1), rear(-1), size(0) {
        // Ensure minimum starting capacity.
        capacity = (initialCapacity > 0) ? initialCapacity : 4; 
        arr = new int[capacity];
        std::cout << "Circular Deque initialized with capacity " << capacity << "." << std::endl;
    }

    // Destructor to free dynamic memory.
    ~Deque() {
        delete[] arr;
        std::cout << "\nDeque memory successfully cleaned up." << std::endl;
    }

    // ----------------------------------------------------------------------
    // Core Utility Functions
    // ----------------------------------------------------------------------

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    int getCurrentSize() const {
        return size;
    }

    // ----------------------------------------------------------------------
    // Insertion Operations (Front and Rear)
    // ----------------------------------------------------------------------

    // Adds an element to the FRONT of the Deque.
    void insertFront(int data) {
        // 1. Check for Full state and resize if necessary.
        if (isFull()) {
            resize(capacity * 2);
        }

        // 2. Handle the special case of the FIRST element being added.
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            // 3. Move 'front' backward circularly.
            // (front - 1 + capacity) % capacity handles wrapping from index 0 to capacity-1.
            front = (front - 1 + capacity) % capacity;
        }

        // 4. Insert data and update size.
        arr[front] = data;
        size++;
        std::cout << "Inserted front: " << data << std::endl;
    }

    // Adds an element to the REAR of the Deque.
    void insertRear(int data) {
        // 1. Check for Full state and resize if necessary.
        if (isFull()) {
            resize(capacity * 2);
        }

        // 2. Handle the special case of the FIRST element being added.
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            // 3. Move 'rear' forward circularly.
            rear = (rear + 1) % capacity;
        }

        // 4. Insert data and update size.
        arr[rear] = data;
        size++;
        std::cout << "Inserted rear: " << data << std::endl;
    }
    // 

    // ----------------------------------------------------------------------
    // Deletion Operations (Front and Rear)
    // ----------------------------------------------------------------------

    // Removes and returns the element from the FRONT (Dequeue action).
    int deleteFront() {
        if (isEmpty()) {
            throw std::runtime_error("ERROR: Deque is empty (Underflow). Cannot delete from front.");
        }

        int deletedValue = arr[front];
        
        // 1. Move 'front' one step forward circularly.
        front = (front + 1) % capacity;

        // 2. Decrease size.
        size--;

        // 3. Check if the Deque became empty.
        if (isEmpty()) {
            // Reset to the empty state.
            front = -1;
            rear = -1;
        }

        std::cout << "Deleted front: " << deletedValue << std::endl;
        return deletedValue;
    }

    // Removes and returns the element from the REAR (Stack Pop action).
    int deleteRear() {
        if (isEmpty()) {
            throw std::runtime_error("ERROR: Deque is empty (Underflow). Cannot delete from rear.");
        }

        int deletedValue = arr[rear];
        
        // 1. Move 'rear' one step backward circularly.
        // (rear - 1 + capacity) % capacity handles wrapping from index 0 to capacity-1.
        rear = (rear - 1 + capacity) % capacity;

        // 2. Decrease size.
        size--;

        // 3. Check if the Deque became empty.
        if (isEmpty()) {
            // Reset to the empty state.
            front = -1;
            rear = -1;
        }

        std::cout << "Deleted rear: " << deletedValue << std::endl;
        return deletedValue;
    }

    // ----------------------------------------------------------------------
    // Access Operations
    // ----------------------------------------------------------------------
    
    // Returns the element at the front without removing it.
    int getFront() {
        if (isEmpty()) {
            throw std::runtime_error("ERROR: Deque is empty. Cannot get front.");
        }
        return arr[front];
    }

    // Returns the element at the rear without removing it.
    int getRear() {
        if (isEmpty()) {
            throw std::runtime_error("ERROR: Deque is empty. Cannot get rear.");
        }
        return arr[rear];
    }

    // ----------------------------------------------------------------------
    // Display Utility
    // ----------------------------------------------------------------------

    // Displays all elements in the Deque from front to rear.
    void display() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Capacity: " << capacity << std::endl;
            return;
        }

        std::cout << "\n--- Deque Content (Front -> Rear) ---" << std::endl;
        std::cout << "Size: " << size << ", Capacity: " << capacity << std::endl;
        
        std::cout << "Data: [ ";
        for (int i = 0; i < size; ++i) {
            // Calculate the current index in the circular array.
            int index = (front + i) % capacity;
            std::cout << arr[index];
            if (i < size - 1) std::cout << " | ";
        }
        std::cout << " ]" << std::endl;

        std::cout << "Indices (Raw Array): [ ";
        for (int i = 0; i < capacity; ++i) {
            std::cout << i;
            if (i == front) std::cout << "(F)";
            if (i == rear) std::cout << "(R)";
            if (i < capacity - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
        std::cout << "-------------------------------------\n" << std::endl;
    }
};

// --------------------------------------------------------------------------
// Main function for demonstration and testing
// --------------------------------------------------------------------------

int main() {
    // Initial capacity is 4.
    Deque myDeque(4); 
    
    // Test 1: Filling and Wrapping (Circular nature)
    std::cout << "--- Test 1: Filling and Wrapping ---" << std::endl;
    myDeque.insertRear(10); // F=0, R=0
    myDeque.insertRear(20); // F=0, R=1
    myDeque.insertRear(30); // F=0, R=2
    myDeque.display(); 

    myDeque.deleteFront();  // Removes 10. F=1, R=2. (Space is freed at index 0)
    myDeque.deleteFront();  // Removes 20. F=2, R=2.
    myDeque.display(); 

    myDeque.insertRear(40); // F=2, R=3
    myDeque.insertRear(50); // F=2, R=0 (Wrapped!)
    myDeque.insertRear(60); // F=2, R=1 (FULL: size=4, capacity=4)
    myDeque.display(); 

    // Test 2: Dynamic Resizing
    std::cout << "--- Test 2: Dynamic Resizing ---" << std::endl;
    // This insertion triggers the resize from capacity 4 to 8.
    myDeque.insertRear(70); 
    myDeque.display(); 

    // Test 3: Mixed Operations
    std::cout << "--- Test 3: Mixed Operations ---" << std::endl;
    myDeque.insertFront(5); // Insert at front (new array, F=0). F=7, R=4
    myDeque.insertFront(1); // F=6, R=4
    myDeque.display(); 
    
    myDeque.deleteRear();   // Removes 70. R=3.
    myDeque.deleteFront();  // Removes 1. F=7.
    
    std::cout << "\nFront item: " << myDeque.getFront() << std::endl;
    std::cout << "Rear item: " << myDeque.getRear() << std::endl;
    
    myDeque.display(); 

    return 0;
}