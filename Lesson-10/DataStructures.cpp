// Lesson 10: Data Structures:

// What is a data structure?
// A data structure is a way of organizing and storing data so that operations like insertion, deletion, searching, and traversal 
// can be performed efficiently.

// Abstract vs. Concrete Data Structures

    // Abstract Data Types (ADTs)
        // These are conceptual models of how data can be organized and what operations can be performed on it.
        // They don’t specify how the structure is implemented—just what it does.
        // These can be implemented using other data structures
        // ex:
            // Stack
            // Queue
            // Deque
            // Priority Queue
            // Dictionaries
            // Set
            // Trees

    // Concrete Data Structures
        // These are the actual, physical data structures used in memory to store and organize data. They define how data is laid out in 
        // memory and how you can access it.
        // They form the foundation to implement abstract data types like stacks, queues, and more.
        // ex:
            // Array 
            // Linked List
            // Hash Table
            // Graph
            // 

    // we will be refering to both as data structures:

    // in this lesson we will cover the stacks and queues..
    // later on we will deep dive into data structures.

// Stacks:
    // A stack is a linear data structure that follows the LIFO principle:
    // Last in, first Out
    // think of it as a pile of folded clothes
    // you can easily add new clothes to the pile by simply placing another folded piece on top of the other
    // to pick a garment, you grab the first one on top
    // thus => last in, First Out

    // Operations
        // push(x)  // Add element to top       // O(1)
        // pop()    // Remove top element       // O(1)
        // top()/peek()  // View top element    // O(1)
        // isEmpty() // Check if empty          // O(1)

    // Stack Implementation using Array
    class Stack {
    private:
        int arr[100];
        int topIndex;

    public:
        Stack() { topIndex = -1; }

        void push(int x) {
            if (topIndex < 99) {
                arr[++topIndex] = x;
            }
        }

        void pop() {
            if (topIndex >= 0) topIndex--;
        }

        int top() {
            return (topIndex >= 0) ? arr[topIndex] : -1;
        }

        bool isEmpty() {
            return topIndex == -1;
        }
    };

    // The stack implementation using an array is a manual way to implement a stack in C++
    // Helps you understand how a stack works under the hood.
    // Shows how to manage memory, indexes, and operations manually.
    // Prepares you for interviews where you're often asked to implement data structures from scratch.

    // If you're building a custom stack class, you'd use this.
    // If you're just solving problems and want convenience, you'd go with std::stack.


    #include <stack>
    #include <iostream>
    using namespace std;

    void Example(){
        stack<int> s;
        s.push(10);
        s.push(20);
        cout << s.top() << endl; // 20
        s.pop();
        cout << s.top() << endl; // 10
    }


// Queues
    // A queue is a linear data structure that follows the FIFO principle:
    // First In, First Out
    // Think of a line at a ticket counter — first person in line is served first.
    
    // Operations:
    // enqueue(x) // Add element to rear            // O(1)
    // dequeue() // Remove element from front       // O(1)
    // front() // View front element                // O(1)
    // isEmpty() // Check if empty                  // O(1) 


    // Queue Implementation using Linked List
    struct Node {
        int data;
        Node* next;
    };

    class Queue {
    private:
        Node *frontNode, *rearNode;

    public:
        Queue() : frontNode(nullptr), rearNode(nullptr) {}

        void enqueue(int x) {
            Node* temp = new Node{x, nullptr};
            if (rearNode == nullptr) {
                frontNode = rearNode = temp;
            } else {
                rearNode->next = temp;
                rearNode = temp;
            }
        }

        void dequeue() {
            if (!frontNode) return;
            Node* temp = frontNode;
            frontNode = frontNode->next;
            if (!frontNode) rearNode = nullptr;
            delete temp;
        }

        int front() {
            return frontNode ? frontNode->data : -1;
        }

        bool isEmpty() {
            return frontNode == nullptr;
        }
    };

    // If you're building a custom Queue class, you'd use this.
    // If you're just solving problems and want convenience, you'd go with std::queue.

    // Queue using STL
    #include <queue>
    #include <iostream>
    using namespace std;

    queue<int> q;
    void Example2(){
        q.push(10);
        q.push(20);
        cout << q.front()<<endl; // 10
        q.pop();
        cout << q.front()<<endl; // 20
    }
   
