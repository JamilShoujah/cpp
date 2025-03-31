// lesson 6: pointers and refernces
#include <iostream>
using namespace std;

// pointers 
    // as we discussed in lesson 1, A pointer is a variable that stores the memory address of another variable.

    // Declaring and Using Pointers
    int a = 10;       // A normal integer variable
    int* p = &a;      // Pointer storing the address of a

        // &a gets the memory address of a.
        // p stores that address.
        
    // what if we do the following?
        // int p = &a;
        // it will result in an error
        // the reason being a value of type "int *" cannot be used to initialize an entity of type "int"
        // so when storing memory addresses, alway use pointers

    // Pointer Dereferencing
        // To access the value a pointer holds, simply use the * symbol
        // this is known as dereferncing
        // ex:

        void printPointer(){
            cout<<*p<<endl; // Outputs: 10, which is the value of a
            // This means *p retrieves the value stored at the memory address stored in p.
        }

    //  Null and Dangling Pointers
    
        // Null Pointer: A pointer that doesn’t point to any valid memory.
        // Basically a null pointer is a pointer that doesn't point to anything.
            // Imagine a mailbox that has no address. If someone asks, "Where should I send the mail?" 
            // you reply, "Nowhere," that's like a null pointer.

        // Best practice to initialize unused pointers
        
        int* nptr = nullptr;

        // Dangling Pointer: A pointer that points to a memory location that has been freed.
            // Imagine you want to visit at friend at a hotel. You write down his hotel room number on paper to visit him when he is there. 
            // Later, your friend checks out, and a new person moves into his room. 

            // If you still try to visit your friend in his old room based on your paper, you might be knocking on a stranger’s door! 
            // That’s a dangling pointer.

            void danglingPointer(){
                int* dPtr = new int(5);
                delete dPtr;  // Memory is deallocated, but pointer still exists
                cout << *dPtr; // Undefined behavior (dangling pointer)
            }

            // Fix: After deleting a pointer, set it to nullptr to avoid using an invalid reference:
    
    // Pointer Arithmetic
        // Pointers support arithmetic operations
        // when performing arithmetic on pointers, the compiler automatically adjusts the pointer by the size of the data type it points to.
        // This ensures that the pointer correctly moves to the next memory location for that type.

        // ex:
        void pointerArthimetic(){
            int arr[] = {10, 20, 30};
            int* ptr = arr;  // Pointer to the first element

            cout << *ptr << endl; // Outputs: 10

            ptr++; // Moves the pointer to the next element in the array
            cout << *ptr << endl; // Outputs: 20

            ptr++; // Moves to the third element
            cout << *ptr << endl; // Outputs: 30
        }

        // detailed explanation:
       
        // int* ptr = arr;
            // ptr is initialized to point to the first element of arr, which is 10.

        // ptr++
            // The pointer moves to the next memory location. Since int is typically 4 bytes,
            // ptr moves forward by 4 bytes (to arr[1]).

        // Another ptr++
            //Moves forward again by 4 bytes to arr[2].

        // Each time we increment the pointer, it moves forward by sizeof(int) bytes (which is usually 4 bytes).

    
    // Pointer Arithmetic Operations

        // Increment (ptr++)
            //Moves the pointer forward to the next element in memory.
            //If ptr points to arr[i], after ptr++, it will point to arr[i+1].
            // ex:

            void IncrementPointerExample(){
                int arr[] = {10, 20, 30};
                int* ptr = arr;  
                ptr++;  // Moves to arr[1]
            }

        // Decrement (ptr--)
            // Moves the pointer backward.
            // If ptr points to arr[i], after ptr--, it will point to arr[i-1].
            // ex:

            void  DecrementPointerExample(){
                int arr[] = {10, 20, 30};
                int* ptr = &arr[2];  // Points to 30
                ptr--;  // Moves to arr[1] (20)

            }

        // Addition (ptr + n)
            // Moves the pointer forward by n elements.
            // incrementing a pointer is technically addition

            void  pointerAdditionExample(){
                int arr[] = {10, 20, 30, 40, 50};
                int* ptr = arr;
                ptr = ptr + 2;  // Moves to arr[2] (30)
            }

        // Subtraction (ptr - n)
            // Moves the pointer backward by n elements.

            void  pointerSubtractionExample(){
                int arr[] = {10, 20, 30, 40, 50};
                int* ptr = &arr[3];  // Points to 40
                ptr = ptr - 2;  // Moves back to arr[1] (20)
            }

        // Pointer Difference (ptr1 - ptr2)
            // Returns the number of elements between two pointers.

            void  pointerDifferenceExample(){
                int arr[] = {10, 20, 30, 40, 50};
                int* ptr1 = &arr[4];  // Points to 50
                int* ptr2 = &arr[1];  // Points to 20
                cout << ptr1 - ptr2;  // Outputs: 3 (they are 3 elements apart)

            }

    // there is more to pointer than just this, but for now we skip


// References
    // A reference is an alias for another variable. Unlike pointers:
        // Must be initialized when declared (unlike pointers).
        // Cannot be null (always refers to a valid object).
        // Acts like the original variable (any changes affect the original).
        // No explicit dereferencing required (unlike pointers).

    // Declaring and Using References
    int x = 100;
    int& ref = x; // ref is a reference to x
    // Now, ref and x refer to the same value:

    // References in Function Arguments
        // Using references avoids copying large objects

// Dynamic Memory Allocation in C++
    // C++ allows manual memory management using new and delete. This gives programmers control over heap memory 
    // but also introduces risks like memory leaks and dangling pointers.

    // Why Use Dynamic Memory?
        // The size of data structures (like arrays) isn't known at compile-time.
        // We need to allocate and deallocate memory dynamically at runtime.  
        // Heap memory is used instead of the stack, allowing larger data storage.

    // Allocating and Deallocating Memory
        // Allocating a Single Variable
            // We use new to allocate memory and delete to free it.

            void allocatingSingleVariable(){
                int* ptr = new int(10); // Allocates a single integer on the heap
                cout << "Value: " << *ptr << endl; // Output: 10

                delete ptr; // Deallocates the memory
                ptr = nullptr; // Best practice to avoid a dangling pointer
            }

            // new int(10) allocates memory for a single integer and initializes it with 10.
            // delete ptr releases the memory.
            // ptr = nullptr ensures ptr doesn't point to freed memory (avoids dangling pointers discuused above).

        // Allocating a Dynamic Array (vectors)
            // If you don’t know the array size at compile-time, use new[] to allocate an array dynamically.
            // ex:
            void dynamicArrayAllocation(){
                int size;
                cout << "Enter array size: ";
                cin >> size;
            
                int* arr = new int[size]; // Dynamically allocates an array
            
                // Assigning values
                for (int i = 0; i < size; i++) {
                    arr[i] = (i + 1) * 10;
                }
            
                // Printing values
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
            
                delete[] arr; // Deallocate array memory
                arr = nullptr; // Prevent dangling pointer
            
            }
            
            // explanation:

                // new int[size] dynamically creates an integer array of size size.
                // Use delete[] instead of delete to free the array correctly.
                // arr = nullptr; avoids using freed memory.
    
    // Common Mistakes in Dynamic Memory
    
        // Forgetting to delete (Memory Leak)
            // A memory leak happens when a program allocates memory but never releases it, causing a gradual increase in memory usage. 
            // Over time, this can lead to performance issues or even cause the program to crash due to out-of-memory errors.
            // ex: 

            void memoryLeak() {
                int* ptr = new int(100);
                // No delete -> memory is never freed! This is a memory leak.
            }
            // Every call to new should have a corresponding delete to free memory.

        //  Using delete Instead of delete[] when using dynamic arrays
            
            void mistakeTwo(){
                int* arr = new int[5];
                delete arr; // Incorrect: should be delete[] arr;
            }

        // Dangling Pointers (Accessing Freed Memory)
            // discussed above

// Smart Pointers (Modern C++) // for lazy developers like my self
#include <memory>
    // Manual memory management is error-prone.
    // C++11 introduced smart pointers to automatically manage memory.

    // unique_ptr (Exclusive Ownership)
        // Only one owner of the allocated memory.
        // Automatically deletes memory when out of scope.

        int MAINDEMO1() { // a function that serves as main

            unique_ptr<int> uptr = make_unique<int>(42);
            cout << *uptr << endl; // Output: 42

            return 0; // Memory is automatically freed
        }

    // shared_ptr (Shared Ownership)
        // Multiple shared_ptr instances can share ownership.
        // Memory is freed when the last shared_ptr is destroyed.

        int MAINDEMO2() {
            shared_ptr<int> sp1 = make_shared<int>(10);
            shared_ptr<int> sp2 = sp1; // Now sp1 and sp2 share ownership
        
            cout << *sp1 << " " << *sp2 << endl; // Output: 10 10
            cout << "Reference Count: " << sp1.use_count() << endl; // Output: 2
        
            return 0; // Memory is freed automatically
        }

    // weak_ptr (Non-Owning Reference)
        // Prevents circular references with shared_ptr.

        int MAINDEMO3(){
            shared_ptr<int> sp = make_shared<int>(100);
            weak_ptr<int> wp = sp; // Does not increase reference count
        
            if (auto temp = wp.lock()) { // Check if the memory is still valid
                cout << *temp << endl;
            }
        
            return 0;
        }

    // When to Use Dynamic Memory?
        // Fixed-size variables             ==>	Use stack allocation (int x;)
        // Unknown size at runtime          ==> Use new or vector<int>
        // Temporary memory                 ==>	Use unique_ptr
        // Shared memory (multiple owners)  ==> Use shared_ptr
        // Avoiding circular references     ==>	Use weak_ptr
    