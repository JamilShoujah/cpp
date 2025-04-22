// Lesson 11 Part 2: Smart Pointers
#include <memory>
#include <iostream>

// Smart pointers in C++ are wrappers around regular pointers that help manage memory automatically, thereby reducing the risk of memory leaks,
// dangling pointers, and other memory-related issues.

// They are part of the C++ Standard Library (introduced in C++11) and are essential for modern C++ programming.

// There are three main types of smart pointers in C++:
    // std::unique_ptr
    // std::shared_ptr
    // std::weak_ptr

// std::unique_ptr
    // A unique_ptr is a smart pointer that owns a dynamically allocated object exclusively. 
    // It ensures that only one unique_ptr can own an object at a time. 
    // When the unique_ptr goes out of scope, the object it points to is automatically deleted.

    // Characteristics
        // Exclusive Ownership: Only one unique_ptr can own the object at any given time.
        // Automatic Cleanup: When the unique_ptr goes out of scope, it automatically deletes the object.
        // Cannot be copied: It can only be moved, not copied, which prevents accidental copying and thus double-deletion.

    // example:

    void example() {
        std::unique_ptr<int> ptr1 = std::make_unique<int>(10); // ptr1 owns the memory
        // std::unique_ptr<int> ptr2 = ptr1; // Error: cannot copy unique_ptr
        std::unique_ptr<int> ptr2 = std::move(ptr1); // ptr2 now owns the memory
        // ptr1 is now empty
        }

// std::shared_ptr
    // A shared_ptr is a smart pointer that allows multiple pointers to share ownership of the same object.
    // The object is deleted only when the last shared_ptr pointing to it is destroyed or reset.

    // Characteristics:
        // Shared Ownership: Multiple shared_ptr objects can share ownership of the same object.
        // Reference Counting: Internally, it maintains a reference count to track how many shared_ptr instances are pointing to the object.
            // The object is deleted when this count drops to zero.
        // Can be copied: shared_ptr can be copied and shared among multiple owners

    // example:
    
    void example() {
        std::shared_ptr<int> ptr1 = std::make_shared<int>(20); // ptr1 owns the memory
        std::shared_ptr<int> ptr2 = ptr1; // ptr2 shares ownership with ptr1
        std::shared_ptr<int> ptr3 = ptr1; // ptr3 also shares ownership
        // The object will be deleted when all shared_ptrs are destroyed
    }

// std::weak_ptr
    // A weak_ptr is a smart pointer that does not change the reference count. 
    // It is used to observe an object managed by shared_ptr without taking ownership. 
    // It can be used to avoid cyclic references (where two or more shared_ptr objects hold each other, preventing their deletion).

    // Characteristics:
        // Non-owning: It doesn't affect the reference count.
        // Can observe but not own: It allows access to the managed object, but does not prevent it from being deleted when
            // the last shared_ptr goes out of scope.
        // Use with shared_ptr: You can convert a weak_ptr to a shared_ptr using lock(). If the object has already been deleted, 
            // lock() will return a null shared_ptr.


    void example() {
        std::shared_ptr<int> ptr1 = std::make_shared<int>(30);
        std::weak_ptr<int> weakPtr = ptr1; // weak_ptr does not affect reference count

        if (auto lockedPtr = weakPtr.lock()) {
            // If the object is still alive, lockedPtr will be a valid shared_ptr
            // Otherwise, lockedPtr will be null
            std::cout << *lockedPtr << std::endl;
        }
    }

// Why Use Smart Pointers?
    // Automatic Resource Management: Smart pointers ensure that memory is automatically freed when it is no longer in use, 
        // thus avoiding manual memory management errors like forgetting to delete or delete[] memory.
    // Exception Safety: When exceptions occur, smart pointers automatically release the memory they manage, preventing memory leaks.
    // Avoiding Dangling Pointers: With regular pointers, it's easy to forget to set them to nullptr after deletion,
        // leading to potential use of invalid memory. Smart pointers handle this for you.
    // Shared Ownership: shared_ptr allows multiple parts of a program to safely share ownership of an object without 
        //worrying about premature deallocation.

// When to Use Each Type:
    // std::unique_ptr: Use when you want exclusive ownership of a resource. It's fast and simple.
    // std::shared_ptr: Use when you need shared ownership of a resource, and when you're dealing with complex ownership structures 
        // (e.g., shared data structures, graphs).
    // std::weak_ptr: Use when you need to break circular references, or when you want to observe an object without affecting its lifetime.

// Best Practices:
    // Prefer unique_ptr when possible because it's lightweight and does not involve reference counting.
    // Use shared_ptr sparingly, as the reference counting mechanism adds some overhead.
    // Avoid cyclic dependencies by using weak_ptr to avoid memory leaks due to cycles.

    // In summary, smart pointers are powerful tools that help you manage dynamic memory in C++ without manually managing the memory lifecycle. 
    // By using unique_ptr, shared_ptr, and weak_ptr correctly, you can improve the safety and readability of your C++ programs.
