// Lesson 13: Introduction to Data Structures

// This lesson provides a high-level overview of data structures.
// Here, we introduce what data structures are, why we need them,
// and the difference between Abstract Data Types (ADTs) and 
// concrete data structures.

// Later lessons will deep-dive into each structure (Stack, Queue,
// Linked List, Trees, Hash Tables, Graphs, etc.).

#include <iostream>
#include <stack>
#include <queue>
using namespace std;


// What is a Data Structure?
    // A data structure is a way to organize and store data so that operations like
    // insertion, deletion, searching, and traversal can be performed efficiently.

    // Different problems require different structures. Choosing the right one
    // can dramatically improve performance.

    // Example:
    // - Searching in a sorted array: O(log n)
    // - Searching in a linked list:  O(n)


// Abstract vs. Concrete Data Structures
    
    // Abstract Data Types (ADTs)
        // ADTs define *what* a data structure does, not *how* it is implemented.
        // These are conceptual models of how data can be organized and what operations can be performed on it.
        // They don’t specify how the structure is implemented—just what it does.
        // These can be implemented using other data structures

        // Example ADTs:
            // - Stack
            // - Queue
            // - Deque
            // - Priority Queue
            // - Set
            // - Dictionary / Map
            // - Tree

        // These ADTs can be implemented using different concrete structures.

        // Example:
            // A Queue ADT can be implemented using:
            //   - Array
            //   - Linked List
            //   - Circular Buffer

        // ADTs describe behavior; concrete DS describe memory layout.


    // Concrete Data Structures
        // These describe *how* data is stored in memory.
        // These are the actual, physical data structures used in memory to store and organize data. 
        // They define how data is laid out in memory and how you can access it.

    // Common concrete structures:
        // - Array
        // - Linked List
        // - Hash Table
        // - Binary Tree
        // - Graph (Adjacency List / Matrix)

    // These are the building blocks used to implement ADTs.


// Why Do We Need Data Structures?
    // - Faster access (O(1) lookup in hash tables)
    // - Efficient searching (O(log n) in trees)
    // - Organized memory usage (linked lists avoid resizing)
    // - Enable solving complex problems (graphs, tries, heaps)

    // Using the wrong structure often makes programs slow or inefficient.


// Overview of the Most Common Data Structures

    // 1. Linear Structures
        //    - Array
        //    - Linked List
        //    - Stack
        //    - Queue

    // 2. Hierarchical Structures
        //    - Binary Search Trees (BST)
        //    - AVL / Red-Black Trees
        //    - Heaps (used for priority queues)

    // 3. Hash-Based Structures
        //    - Hash Table
        //    - unordered_map / map

    // 4. Graph Structures
        //    - Adjacency List
        //    - Adjacency Matrix
