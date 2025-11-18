// Lesson 15: Stacks

// What is a Stack?
// A stack is an abstract data type (ADT) that serves as a collection of elements, with two principal operations:
    // Push: Adds an element to the collection.
    // Pop: Removes the most recently added element.

// think of a stack like a stack of neatly folded clothes

// The defining characteristic of a stack is its adherence to the LIFO (Last-In, First-Out) principle.
// back to the clothes example, the last shirt you put on the stack is the first shirt that is removed
// in a data stack, the last element added (pushed) is the first element to be removed (popped).

// Key Terminology
    // Top: The position in the stack where elements are added or removed. This is the only place operations can occur.
    // Push: The operation of inserting a new element onto the top of the stack.
    // Pop: The operation of removing an element from the top of the stack.
    // Peek (or Top): The operation of looking at (retrieving) the value of the top element without removing it.

// Stack Implementation
    // Stacks can be implemented using two primary underlying data structures: Arrays (or dynamic arrays/lists) and Linked Lists.
    // hence its considered an abstract data type

    // Stack Implementation using an Array
        // checkout Lesson-15: Stacks/examples/ArrayStack.cpp

    // Stack Implementation using a Linked List
        // Lesson-15: Stacks/examples/LinkedListStack.cpp

// Operation    | Time Complexity
    // Push     | O(1)
    // Pop      | O(1)
    // Peek     | O(1)
    // IsEmpty  | O(1)
    // Size     | O(1) (if a size counter is maintained)