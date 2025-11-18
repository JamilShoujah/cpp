// Lesson 16: Queues

// What is a Queue?
// A Queue is an abstract data type (ADT) that serves as a collection of elements, characterized by two principal operations:
    // Enqueue: Adds an element to the collection.
    // Dequeue: Removes the least recently added element.

// The defining characteristic of a queue is its adherence to the FIFO (First-In, First-Out) principle.
    // Imagine a line of people waiting for a bus. The first person to join the line is the first person to get on the bus.
    // Similarly, in a data queue, the first element added (Enqueued) is the first element to be removed (Dequeued).

// Key Terminology
    // Front (or Head): The position where elements are removed (Dequeued).
    // Rear (or Tail): The position where elements are added (Enqueued).
    // Enqueue: The operation of inserting a new element at the Rear of the queue.
    // Dequeue: The operation of removing an element from the Front of the queue.
    // Peek (or Front): The operation of looking at (retrieving) the value of the front element without removing it.


// Implementation and Operations
    // Like stacks, queues can be implemented using either Arrays (or dynamic arrays/lists) or Linked Lists.
    
    // Queue Implementation using an Array
        // Lesson-16: Queues/examples/ArrayQueue.cpp

    // Efficient Queue Implementation using a Circular Array
        // Lesson-16: Queues/examples/CircularArrayQueue.cpp

    // Queue Implementation using a Linked List
        // Lesson-16: Queues/examples/LinkedListQueue.cpp


// Operation        | Time Complexity
    // Enqueue      | O(1)
    // Dequeue      | O(1)
    // Peek         | O(1)
    // IsEmpty      | O(1)