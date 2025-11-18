#include <iostream>

// --------------------------------------------------------------------------
// 1. Define the Node Structure
// --------------------------------------------------------------------------
// This structure represents one element in the stack (a node).
struct Node {
    int data;       // The value stored in the node.
    Node* next;     // Pointer to the next node in the list.
};

// --------------------------------------------------------------------------
// 2. Class Definition for the Stack
// --------------------------------------------------------------------------
class Stack {
private:
    // 'top' is a pointer that always points to the Node at the top of the stack.
    // It is initialized to NULL (nullptr in modern C++), meaning the stack is empty.
    Node* top; 

public:
    // Constructor to initialize the stack.
    Stack() {
        top = nullptr; 
        std::cout << "Linked List Stack initialized." << std::endl;
    }

    // Destructor to clean up memory when the Stack object is destroyed.
    ~Stack() {
        Node* current = top;
        Node* next;
        // Iterate through all nodes and delete them to prevent memory leaks.
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        top = nullptr;
        std::cout << "\nStack memory successfully cleaned up." << std::endl;
    }

    // ----------------------------------------------------------------------
    // Core Utility Functions
    // ----------------------------------------------------------------------

    // Checks if the stack is empty.
    bool isEmpty() {
        // The stack is empty if the 'top' pointer is pointing to nothing.
        return top == nullptr;
    }

    // ----------------------------------------------------------------------
    // Core Stack Operations: push, pop, peek
    // ----------------------------------------------------------------------
    
    // Adds an element to the top of the stack (PUSH operation).
    void push(int data) {
        // 1. Create a new Node dynamically (on the heap).
        Node* newNode = new Node;
        
        // Check if memory allocation failed (Stack Overflow is rare but possible here).
        if (!newNode) {
            std::cout << "ERROR: Memory allocation failed. Cannot push." << std::endl;
            return;
        }

        // 2. Set the data of the new node.
        newNode->data = data; 
        
        // 3. Link the new node to the current top node.
        // The 'next' pointer of the newNode should point to where 'top' currently points.
        newNode->next = top; 

        // 4. Update 'top' to point to the new node. This new node is now the stack top.
        top = newNode; 

        std::cout << "Pushed: " << data << std::endl;
    }
    // 

    // Removes and returns the element at the top of the stack (POP operation).
    int pop() {
        // 1. Check for Stack Underflow (Empty)
        if (isEmpty()) {
            std::cout << "ERROR: Stack Underflow! Cannot pop. Stack is empty." << std::endl;
            return 0; 
        }

        // 2. Save the value and the pointer to the node to be deleted.
        Node* temp = top;           // 'temp' points to the current top node.
        int poppedValue = top->data; // Get the data to return.

        // 3. Move the 'top' pointer to the next node in the list.
        // This is the essential "removal" step.
        top = top->next; 

        // 4. Delete the old top node to free up memory (Crucial memory management).
        delete temp;

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

        // 2. Return the data of the node pointed to by 'top'.
        return top->data;
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

        // Use a temporary pointer to traverse the list without changing 'top'.
        Node* current = top; 

        std::cout << "\n--- Stack Content (Top to Bottom) ---" << std::endl;
        
        // Traverse the list until 'current' becomes nullptr (the end).
        while (current != nullptr) {
            std::cout << "| " << current->data << " |";
            // Indicate the 'top' element clearly
            if (current == top) {
                std::cout << " <-- TOP";
            }
            std::cout << std::endl;
            // Move to the next node
            current = current->next;
        }
        std::cout << "-------------------------------------\n" << std::endl;
    }
};

// --------------------------------------------------------------------------
// Main function for demonstration and testing
// --------------------------------------------------------------------------

int main() {
    Stack myStack;
    
    // Pushing elements (LIFO: 10 is at the bottom, 40 is at the top)
    std::cout << "\n--- Pushing Elements ---" << std::endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    
    myStack.display();

    // Peeking at the top element (40)
    std::cout << "Top element is: " << myStack.peek() << std::endl;
    
    // Popping elements (40 comes out first, then 30)
    std::cout << "\n--- Popping Elements ---" << std::endl;
    myStack.pop(); 
    myStack.pop(); 
    
    myStack.display();

    // The stack can grow indefinitely (memory permitting)
    std::cout << "\n--- Pushing more without limits ---" << std::endl;
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);

    myStack.display();

    // Demonstrate Underflow
    std::cout << "\n--- Emptying Stack and Underflow Test ---" << std::endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    
    // This pop should trigger the Stack Underflow error.
    myStack.pop(); 

    myStack.display();

    // Note: The destructor automatically handles cleaning up all memory
    // when 'myStack' goes out of scope at the end of main().

    return 0;
}