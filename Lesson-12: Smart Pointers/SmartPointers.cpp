// Lesson 11 Part 2: Smart Pointers
#include <memory>
#include <iostream>

// Smart pointers in C++ are wrappers around regular pointers that help manage memory automatically, 
// thereby reducing the risk of memory leaks, dangling pointers, and other memory-related issues 
// that result from raw pointers.

// Manual memory management is powerful but error-prone. 
// Smart pointers solve these issues by managing memory automatically

// They are part of the C++ Standard Library (introduced in C++11) and are essential for modern C++ programming.

// There are three main types of smart pointers in C++:
    // - std::unique_ptr
    // - std::shared_ptr
    // - std::weak_ptr


// std::unique_ptr
    // * A unique_ptr is a smart pointer that owns a dynamically allocated object exclusively. 
    // * It ensures that only one unique_ptr can own an object at a time. 
    // * When the unique_ptr goes out of scope, the object it points to is automatically deleted.

    // Characteristics
        // * Exclusive Ownership: Only one unique_ptr can own the object at any given time.
            // Exclusive ownership is about the unique_ptr itself being the only boss of the object’s lifetime
        // * Automatic Cleanup: When the unique_ptr goes out of scope, it automatically deletes the object.
        // * Cannot be copied: It can only be moved, not copied, which prevents accidental copying and thus double-deletion.

    // unique_ptr methods:
        // .get() => Returns the raw pointer without releasing ownership. 
            //    => returns memory address
            // ex: ptr.get();

        // .release() => Releases ownership and returns the raw pointer. You must manually delete it!
            // doesnt delete object.. just releases ownership
            // ex: int* raw = ptr.release();
            // the unique pointer doesnt get deleted.. it gets assigned as a null pointer.

        // .reset() => Deletes the managed object and optionally takes new one. 
            // ex: ptr.reset(); // results in a null pointer
            // ex: ptr.reset(new int(10)); // points to the address on new object

        // .swap() Swaps the managed object with another unique_ptr. 
            // ex: ptr1.swap(ptr2);

        // move(ptr) // dog onership example
        // originak pointer becomes null

    // example
    void uniquePointerExample() {
        // Create a unique_ptr that owns a dynamically allocated integer with value 10
        std::unique_ptr<int> ptr = std::make_unique<int>(10);
        // std::unique_ptr<int> ptr2 = ptr; will result in an error
        // unique pointers cant be copied


        // note compare with new int(10) vs int(10)// jamil add notes please

        // Print the value that ptr is pointing to by dereferencing the pointer
        std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

        // ------------------------------------------------------------------------------------
        // .get() method: 
        // - Returns the raw pointer without giving up ownership.
        // - We can use it to access the pointer but unique_ptr still manages the memory.
        int* rawPtr = ptr.get(); // Get the raw pointer
        std::cout << "Raw pointer value (using .get()): " << *rawPtr << std::endl;

        // ------------------------------------------------------------------------------------
        // .release() method:
        // - Releases ownership of the object.
        // - After calling release(), ptr becomes nullptr.
        // - You must manually delete the returned raw pointer to avoid memory leaks.
        int* releasedPtr = ptr.release(); // Release ownership and get the raw pointer
        std::cout << "Raw pointer value (using .release()): " << *releasedPtr << std::endl;

        // Now ptr is nullptr. We must manually delete the raw pointer.
        delete releasedPtr; // Manual delete required after release()

        // ------------------------------------------------------------------------------------
        // .reset() method:
        // - Deletes the currently owned object (if any).
        // - Optionally, assigns a new object to the unique_ptr.
        ptr.reset(new int(20)); // Assign new memory with value 20
        std::cout << "Value pointed to by ptr after reset: " << *ptr << std::endl;

        // ------------------------------------------------------------------------------------
        // .reset() without arguments:
        // - Deletes the currently owned object.
        // - Makes the unique_ptr empty (nullptr).
        ptr.reset(); // Deletes 20 and makes ptr nullptr

        // Check if ptr is empty (nullptr) after reset
        if (!ptr) {
            std::cout << "ptr is nullptr after reset().\n";
        }

        // When a function ends, all local variables (including unique_ptr) go out of scope.
        // When a unique_ptr goes out of scope, its destructor is automatically called.
        // The destructor deletes the object it was owning (if it still owns something).
    }

// ------------------------------------------------------------------------------------------------------------------

// std::shared_ptr
    // * A shared_ptr is a smart pointer that allows multiple pointers to share ownership of the same object.
    // * The object is deleted only when the last shared_ptr pointing to it is destroyed or reset.

    // Characteristics:
        // - Shared Ownership: Multiple shared_ptr objects can share ownership of the same object.
        // - Reference Counting: Internally, it maintains a reference count to track how many shared_ptr instances are 
        // pointing to the object. The object is deleted when this count drops to zero.
        // - Can be copied: shared_ptr can be copied and shared among multiple owners

    // shared_ptr methods:
        // .get() => Returns raw pointer. 
            // ex: ptr.get(); // returns the memory address

        // .reset() => Destroys managed object if last owner. 
            // ex: ptr.reset(); 

        // .use_count() => Returns how many shared_ptrs share ownership. 
            // ex: ptr.use_count();

        // .unique() => Returns true if only one shared_ptr owns it. 
            // ex: ptr.unique();

        // .swap() => Swaps the managed object with another shared_ptr. 
            // ex: ptr1.swap(ptr2);


    void sharedPointerExample() {
        // Create a shared_ptr
        std::shared_ptr<int> ptr1 = std::make_shared<int>(10); 
        // ptr1 is now managing an integer with value 10.
        // use_count is 1 because only ptr1 owns it.

        std::cout << "After creating ptr1:" << std::endl;
        std::cout << "ptr1 value: " << *ptr1 << std::endl; // Dereference to get value
        std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl; // Should print 1
        std::cout << "ptr1 unique? " << (ptr1.unique() ? "Yes" : "No") << std::endl; // Should be Yes

        // Copy ptr1 to ptr2
        std::shared_ptr<int> ptr2 = ptr1;
        // Now, ptr1 and ptr2 BOTH share ownership of the same integer.
        // use_count becomes 2.

        std::cout << "After copying ptr1 to ptr2:" << std::endl;
        std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl; // Should print 2
        std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl; // Should also print 2
        std::cout << "ptr1 unique? " << (ptr1.unique() ? "Yes" : "No") << std::endl; // No, because shared
        std::cout << "ptr2 unique? " << (ptr2.unique() ? "Yes" : "No") << std::endl; // No, because shared

        // Access the raw pointer using .get()
        int* raw_ptr = ptr1.get();
        // .get() returns the raw pointer, but shared_ptr still manages the memory.

        std::cout << "Accessing the raw pointer: " << *raw_ptr << std::endl;

        // Swap ptr1 and ptr2 (though they point to the same thing, just for demonstration)
        ptr1.swap(ptr2);
        // After swap, they still point to the same object because they were sharing it already.

        std::cout << "After swapping ptr1 and ptr2:" << std::endl;
        std::cout << "ptr1 value: " << *ptr1 << ", ptr2 value: " << *ptr2 << std::endl;
        std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl; // Still 2
        std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl; // Still 2

        // Reset ptr2
        ptr2.reset();
        // ptr2 releases its ownership.
        // Now only ptr1 owns the object.
        // use_count should drop to 1.

        std::cout << "After resetting ptr2:" << std::endl;
        std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl; // Should be 1 now
        std::cout << "ptr2 is now " << (ptr2 ? "not null" : "null") << std::endl;

        // Finally, when method ends, ptr1 will go out of scope.
        // Since ptr1 is the last owner, the object (int 10) will be automatically deleted.
        // No memory leak!

    }

// ------------------------------------------------------------------------------------------------------------------

// std::weak_ptr
    // * A weak_ptr is a smart pointer that does not change the reference count. 
    // * It is used to observe an object managed by shared_ptr without taking ownership. 
    // * It can be used to avoid cyclic references (where two or more shared_ptr objects 
    // hold each other, preventing their deletion).

    // Characteristics:
        // - Non-owning: It doesn't affect the reference count.
        // - Can observe but not own: It allows access to the managed object, but does not prevent it from being deleted when
        // the last shared_ptr goes out of scope.
        // - Use with shared_ptr: You can convert a weak_ptr to a shared_ptr using lock(). If the object has already been deleted, 
        // lock() will return a null shared_ptr.

    // weak_ptr Methods:
        // .lock() => Tries to create a shared_ptr if object still exists. 
            // ex: auto sp = wp.lock();

        // .expired() => Returns true if the managed object has been deleted. 
            // ex: wp.expired();

        // .reset() => Clears the weak_ptr. // becomes null
            // ex: wp.reset();

        // .use_count() => How many shared_ptrs still exist (same as shared_ptr). 
            // ex: wp.use_count();

    void weakPointerExample() {
        // Create a shared_ptr
        std::shared_ptr<int> sp = std::make_shared<int>(42);
        // sp is managing an int with value 42.
        // use_count is 1 now.

        // Create a weak_ptr from the shared_ptr
        std::weak_ptr<int> wp = sp;
        // wp observes the object but DOES NOT increase use_count.
        // sp.use_count() is still 1.

        std::cout << "After creating shared_ptr and weak_ptr:" << std::endl;
        std::cout << "sp use_count: " << sp.use_count() << std::endl; // Should be 1
        std::cout << "wp use_count: " << wp.use_count() << std::endl; // Should also show 1

        std::cout << "--------------------------------------" << std::endl;

        // Access the object safely using .lock()
        if (auto locked_sp = wp.lock()) {
            // .lock() returns a shared_ptr.
            // If the object still exists, locked_sp is a valid shared_ptr.
            std::cout << "Locked weak_ptr successfully. Value: " << *locked_sp << std::endl;
        } else {
            std::cout << "Failed to lock weak_ptr. Object no longer exists." << std::endl;
        }

        std::cout << "--------------------------------------" << std::endl;

        // Reset the shared_ptr
        sp.reset();
        // Now no shared_ptrs own the object.
        // The integer (42) is deleted.
        // wp is now observing an object that no longer exists.

        std::cout << "After resetting shared_ptr (sp):" << std::endl;
        std::cout << "sp use_count: " << sp.use_count() << std::endl; // Should be 0
        std::cout << "wp expired? " << (wp.expired() ? "Yes" : "No") << std::endl; // Should be Yes

        std::cout << "--------------------------------------" << std::endl;

        // Try locking again after the object is deleted
        if (auto locked_sp = wp.lock()) {
            std::cout << "Locked weak_ptr successfully. Value: " << *locked_sp << std::endl;
        } else {
            std::cout << "Failed to lock weak_ptr. Object no longer exists." << std::endl;
        }

        std::cout << "--------------------------------------" << std::endl;

        // Reset the weak_ptr
        wp.reset();
        // Now wp no longer observes anything.

        std::cout << "After resetting weak_ptr (wp):" << std::endl;
        std::cout << "wp expired? " << (wp.expired() ? "Yes" : "No") << std::endl; // Still Yes
    }

// ------------------------------------------------------------------------------------------------------------------

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
