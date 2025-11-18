#include <iostream>

// Define the maximum size of our stack array.
// This is a fixed limit for array-based stacks.
#define MAX_SIZE 10

// --------------------------------------------------------------------------
// Class Definition for the Stack
// --------------------------------------------------------------------------
class Stack {
private:
    // 1. Array to hold the stack elements.
    // The size is fixed to MAX_SIZE (10).
    int arr[MAX_SIZE]; 

    // 2. 'top' is an index that tracks the top element of the stack.
    // It is initialized to -1, indicating the stack is initially empty.
    int top; 

public:
    // Constructor to initialize the stack when an object is created.
    Stack() {
        // Initialize 'top' to -1 to signify that the stack has no elements yet.
        top = -1; 
        std::cout << "Stack initialized (Max size: " << MAX_SIZE << ")." << std::endl;
    }

    // ----------------------------------------------------------------------
    // Core Utility Functions: Check State
    // ----------------------------------------------------------------------

    // Checks if the stack is completely full.
    bool isFull() {
        // Since the array is 0-indexed, the last position is MAX_SIZE - 1.
        return top == MAX_SIZE - 1; 
    }

    // Checks if the stack is empty.
    bool isEmpty() {
        return top == -1;
    }

    // ----------------------------------------------------------------------
    // Core Stack Operations: push, pop, peek
    // ----------------------------------------------------------------------
    
    // Adds an element to the top of the stack (PUSH operation).
    void push(int data) {
        // 1. Check for Stack Overflow (Full)
        if (isFull()) {
            std::cout << "ERROR: Stack Overflow! Cannot push " << data << ". Stack is full." << std::endl;
            return;
        }

        // 2. Increment 'top' to point to the next available empty spot.
        top++; 

        // 3. Insert the new data into the array at the new 'top' position.
        arr[top] = data; 
        std::cout << "Pushed: " << data << std::endl;
    }

    // Removes and returns the element at the top of the stack (POP operation).
    int pop() {
        // 1. Check for Stack Underflow (Empty)
        if (isEmpty()) {
            std::cout << "ERROR: Stack Underflow! Cannot pop. Stack is empty." << std::endl;
            // Returning a sentinel value (like 0) on error.
            return 0; 
        }

        // 2. Retrieve the value currently at the 'top' index.
        int poppedValue = arr[top]; 

        // 3. Decrement 'top'. This effectively removes the element
        // (we just ignore the old data by changing where 'top' points).
        top--; 

        std::cout << "Popped: " << poppedValue << std::endl;
        return poppedValue;
    }

    // Returns the element at the top of the stack without removing it (PEEK/TOP operation).
    int peek() {
        // 1. Check for Stack Underflow (Empty)
        if (isEmpty()) {
            std::cout << "ERROR: Cannot peek. Stack is empty." << std::endl;
            return 0;
        }

        // 2. Return the value at the current 'top' index.
        return arr[top];
    }

    // ----------------------------------------------------------------------
    // Display Utility
    // ----------------------------------------------------------------------

    // Displays all elements in the stack from top to bottom.
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Nothing to display." << std::endl;
            return;
        }

        std::cout << "\n--- Stack Content (Top to Bottom) ---" << std::endl;
        // Iterate from the current top index down to 0.
        for (int i = top; i >= 0; i--) {
            std::cout << "| " << arr[i] << " |";
            // Indicate the 'top' element clearly
            if (i == top) {
                std::cout << " <-- TOP";
            }
            std::cout << std::endl;
        }
        std::cout << "-------------------------------------" << std::endl;
    }
};

// --------------------------------------------------------------------------
// Main function for demonstration and testing
// --------------------------------------------------------------------------

int main() {
    // 1. Create a stack object.
    Stack myStack;
    
    // 2. Push elements onto the stack. Stacks follow the LIFO principle (Last-In, First-Out)
    std::cout << "\n--- Step 2: Pushing Elements ---" << std::endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    // 

    myStack.display();

    // 3. Peek at the top element (40).
    std::cout << "\n--- Step 3: Peeking ---" << std::endl;
    std::cout << "Top element is: " << myStack.peek() << std::endl;
    myStack.display(); // The stack remains unchanged after peek

    // 4. Pop elements from the stack.
    std::cout << "\n--- Step 4: Popping Elements ---" << std::endl;
    myStack.pop(); // Removes 40
    myStack.pop(); // Removes 30
    
    myStack.display();

    // 5. Demonstrate stack limits (Push until full)
    std::cout << "\n--- Step 5: Filling and Overflowing ---" << std::endl;
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);
    myStack.push(80);
    myStack.push(90);
    myStack.push(100);
    myStack.push(110); 
    myStack.push(120); 
    myStack.push(130); // Stack is now FULL (10 elements total)
    
    myStack.display();

    // This push should trigger the Stack Overflow error.
    myStack.push(140); 
    
    // 6. Demonstrate stack limits (Pop until empty)
    std::cout << "\n--- Step 6: Emptying and Underflowing ---" << std::endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        myStack.pop();
    }
    
    // This pop should trigger the Stack Underflow error.
    myStack.pop(); 
    
    // Final check
    myStack.display();

    return 0;
}