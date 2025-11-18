// LINKED LISTS IN C++

#include <iostream>
using namespace std;

// What is a Linked List?
    // A linked list is a data structure where each element points to the next.
    // Unlike arrays/vectors which store everything contiguously in memory, a linked list stores nodes anywhere, 
    // but connects them with pointers.

// Why?
    // Arrays need contiguous memory → can fail if memory is fragmented.
    // Arrays have O(n) insertion in the middle.
    // Linked lists allow O(1) insertion/deletion once you have a pointer to the position.

// Tradeoff:
    // Slow access → O(n) to reach an element.
    // Worse cache locality.
    // More memory overhead due to pointers.


// The Basic Building Block: The Node
    // A linked list is basically: [node] -> [node] -> [node] -> nullptr


// ==============================================
// Singly Linked List (Beginner-Friendly Version)
// ==============================================

// A Node represents ONE element in the linked list.
// Each node stores:
//  - some data (an integer)
//  - a pointer to the next node in the list
class Node {
public:
    int data;      // The value stored inside the node
    Node* next;    // Pointer to the next node (or nullptr if none)

    // Constructor: makes a new node holding 'value'
    Node(int value) : data(value), next(nullptr) {}
};


// The LinkedList class manages the sequence of nodes.
// It stores ONLY the head pointer (start of the list).
class LinkedList {
private:
    Node* head;  // Points to the FIRST node in the list (nullptr if empty)

public:

    // Constructor: start with an empty list
    LinkedList() : head(nullptr) {}


    // ==============================================
    // Insert a new node at the *front* of the list
    // ==============================================
    // Example: list = [10 -> 20 -> NULL]
    // insertFront(5)
    // result: [5 -> 10 -> 20 -> NULL]
    void insertFront(int value) {

        // Step 1: Create a new node
        Node* newNode = new Node(value);

        // Step 2: Point this new node's next to current head
        // This attaches the new node *before* the old first node
        newNode->next = head;

        // Step 3: Update head to the new node
        head = newNode;
    }


    // ==============================================
    // Insert a new node at the *end* of the list
    // ==============================================
    // Example: list = [10 -> 20 -> NULL]
    // insertBack(30)
    // result: [10 -> 20 -> 30 -> NULL]
    void insertBack(int value) {

        // Step 1: Make the new node
        Node* newNode = new Node(value);

        // Case 1: If the list is empty, newNode becomes the head
        if (!head) {
            head = newNode;
            return;
        }

        // Case 2: Otherwise, travel to the last node
        // (the node whose next == nullptr)
        Node* temp = head;

        // Move forward until reaching the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Step 3: "Attach" the new node to the end
        temp->next = newNode;
    }


    // ==============================================
    // Delete the FIRST occurrence of a value
    // ==============================================
    // If list = [10 -> 20 -> 30 -> 20 -> NULL]
    // deleteValue(20)
    // result = [10 -> 30 -> 20 -> NULL]
    void deleteValue(int value) {

        // If list is empty, nothing to delete
        if (!head) return;

        // Case 1: If the head holds the value
        if (head->data == value) {

            // Save old head node so we can delete it
            Node* nodeToDelete = head;

            // Move head to next
            head = head->next;

            // Free memory
            delete nodeToDelete;
            return;
        }

        // Case 2: Value is somewhere *after* the head
        Node* temp = head;

        // Find the node BEFORE the one we want to delete
        // Loop stops when:
        //  - temp->next is null (value not found)
        //  - OR temp->next->data == value (found target)
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        // If found (temp->next != nullptr)
        if (temp->next != nullptr) {

            // Node to delete
            Node* nodeToDelete = temp->next;

            // Skip over the deleted node
            temp->next = temp->next->next;

            // Free memory
            delete nodeToDelete;
        }
        // If not found, do nothing (value does not exist)


    }


    // ==============================================
    // Print the entire linked list
    // ==============================================
    // Example: prints "10 -> 20 -> 30 -> NULL"
    void printList() {
        Node* temp = head;  // Start at the beginning

        // Traverse until reaching nullptr
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;  // Move forward
        }

        // Show that the list ends
        std::cout << "NULL\n";
    }


    Node* search(int value); // <-- forward declaration to a function below
    void insertAfter(Node* node, int value); // <-- forward declaration to a function below

};


// Key Notes:
    // Insert operations: O(1) at front, O(n) at back.
    // Deletion: O(n) worst case.
    // Traversal: O(n).


// Memory Model (Important for Interviews)
    // Each Node is allocated on heap memory using new.
    // You must also delete memory manually (or use smart pointers).


// Operations You Must Know
    // Search (worst-case)
        Node* LinkedList::search(int value) {
            Node* temp = head;
            while (temp) {
                if (temp->data == value) return temp;
                temp = temp->next;
            }
            return nullptr;
        }
        // Time: O(n).

    // Insert after a specific node
        void LinkedList::insertAfter(Node* node, int value) {
            if (!node) return;
            Node* newNode = new Node(value);
            newNode->next = node->next;
            node->next = newNode;
        }
        // Time: O(1).


// Doubly Linked List
    // same as the singly linked list, but with one extra feature:
    // Adds a prev pointer.
    // this allows for easy backward traversal and Easier deletions

    // NULL <- [node] <-> [node] <-> [node] -> NULL

    class DNode {
public:
    int data;        // Value stored in this node
    DNode* next;     // Pointer to next node
    DNode* prev;     // Pointer to previous node

    // Constructor initializes values
    DNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};


// Doubly Linked List class
class DoublyLinkedList {
private:
    DNode* head;    // Pointer to the FIRST node

public:

    // Start with an empty list
    DoublyLinkedList() : head(nullptr) {}


    // ==============================================
    // Insert at the FRONT of the list
    // ==============================================
    void insertFront(int value) {
        DNode* newNode = new DNode(value);

        // If list is empty
        if (!head) {
            head = newNode;
            return;
        }

        // If list has at least one node
        newNode->next = head; // Link forward
        head->prev = newNode; // Link backward
        head = newNode;       // Move head to new node
    }


    // ==============================================
    // Insert at the BACK of the list
    // ==============================================
    void insertBack(int value) {
        DNode* newNode = new DNode(value);

        // Empty list
        if (!head) {
            head = newNode;
            return;
        }

        // Move to the last node
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Attach new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }


    // ==============================================
    // Delete FIRST occurrence of a given value
    // ==============================================
    void deleteValue(int value) {

        if (!head) return; // empty list

        DNode* temp = head;

        // Step 1: Find the node to delete
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        // Value not found
        if (!temp) return;

        // Case 1: Deleting the HEAD node
        if (temp == head) {
            head = head->next;   // Move head forward

            if (head) {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        // Case 2: Deleting from middle or end

        // Connect previous node to next node
        if (temp->prev)
            temp->prev->next = temp->next;

        // Connect next node back to previous node
        if (temp->next)
            temp->next->prev = temp->prev;

        // Delete our target node
        delete temp;
    }


    // ==============================================
    // Print list FORWARD
    // ==============================================
    void printForward() {
        DNode* temp = head;

        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }


    // ==============================================
    // Print list BACKWARD
    // (Only possible because it's a doubly linked list!)
    // ==============================================
    void printBackward() {

        if (!head) {
            std::cout << "NULL\n";
            return;
        }

        DNode* temp = head;

        // Step 1: Move to the LAST node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Step 2: Traverse BACKWARDS
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        std::cout << "NULL\n";
    }
};

    // Advantages:
        // O(1) deletion of a node EVEN WITHOUT knowing the previous node.
        // Bidirectional traversal.
    
    // Disadvantages:
        // More memory (two pointers).
        // More complicated to maintain.


// Circular Linked Lists
    // can be implemented with both singly and doubly linked lists

    // With singly linked lists:
    
        // head → A → B → C →
        // ^                |
        // |________________|


    // Doubly Circular:
        // head.prev → tail
        // tail.next → head


        // _____________________________________
        // |                                    V
        // [node] <- [node] <-> [node] <-> [node]
        // ^                                    |
        // |____________________________________|

    
    // Use cases:
        // Round-robin scheduling
        // Implementing queues
        // Multiplayer game turns
