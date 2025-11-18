// Lesson 17: Deques (Double-Ended Queue)

// NOTE: Deques (Double-Ended Queue) and Dequeue are completly differnt things
// yeah its confusing, but i gotchu so dw

// Dequeue -> Operation of removing an element from the front of a standard Queue (or a Deque).

// A Deque (pronounced "deck") is a powerful and flexible data structure that generalizes both the stack and the queue. 
// It removes the restriction that insertion and deletion must occur at opposite ends.

// In short: A Deque is a container, while Dequeue is an action (a function call) performed on a queue or a deque.



// What is a Deque?
    // A Deque (Double-Ended Queue) is a linear abstract data type (ADT) where elements can be manipulated at both the front and the rear.
    // The versatility of a Deque means it can perfectly simulate the behavior of both a Stack and a Queue:
        // As a Queue (FIFO): Use the two-sided operations that mimic FIFO (e.g., insert at rear, remove from front).
        // As a Stack (LIFO): Use the two-sided operations that mimic LIFO (e.g., insert at front, remove from front, OR insert at rear, remove from rear).

// Core Operations // all O(1)

    // push_front() or addFirst()       |	 Adds an element to the front end.
    // push_back() or addLast()	        |    Adds an element to the rear end.
    // pop_front() or removeFirst()	    |    Removes and returns the element at the front.
    // pop_back() or removeLast()	    |    Removes and returns the element at the rear.

// Implementation
    // similar to queues, deques can be implemented by either doubly linked lists or Dynamic Array / Circular Buffer

    // doubly linked list implementation


    // Dynamic Array / Circular Buffer implementation
