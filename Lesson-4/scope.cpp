// Lesson 4 - Part 2: scopes
#include <iostream>
using namespace std;

// In C++, scope defines the region of a program where a variable or function can be accessed.

// There are several types of scopes in C++:

    // Local Scope
        // A variable declared inside a function or block {} is local to that function or block.
        // It cannot be accessed outside its scope.
        // ex:

        void example() {
            int x = 10; // x has local scope
            std::cout << x; // Accessible within this function
        }
        // std::cout << x;  // Error! x is not accessible here

    // Global Scope
        // A variable declared outside all functions has global scope.
        // It is accessible throughout the entire program.
        // ex:

        int y = 20; // Global variable

        void example2() {
            std::cout << y; // Accessible
        }

        int DEMOMAIN1() {
            std::cout << y; // Accessible
            return 0;
        }

    // Namespace Scope
        // A variable or function inside a namespace is limited to that namespace unless accessed using the :: operator.

        namespace MyNamespace {
            int z = 30;
        }
        
        int DEMOMAIN2() {
            std::cout << MyNamespace::z; // Access using namespace
            return 0;
        }

    // Class/Struct Scope
        // more detail when we get to oop very soon
        // Members of a class/struct have class scope.
        // They can be accessed using dot (.) for objects and arrow (->) for pointers.


        class Example {
            public:
                int a;  // Member variable (class scope)
        };
            
        int DEMOMAIN3() {
            Example obj;
            obj.a = 10; // Accessing member variable
            return 0;
        }

    // Function Scope
        // Variables declared inside a function are local to that function.
        // Even if they have the same name as a global variable, they do not affect the global variable.
            
        int x = 5; // Global variable

        void exampleone() {
            int x = 10; // Local to this function
            std::cout << x; // Prints 10 (local x)
        }
        
        int  DEMOMAIN4() {
            example();
            std::cout << x; // Prints 5 (global x)
            return 0;
        }

    // Loop/Block Scope
        // Variables declared inside a loop or block {} are only accessible within that block. 
        
        int DEMOMAIN5() {
            for (int i = 0; i < 5; i++) {
                std::cout << i; // i is accessible here
            }
            // std::cout << i;  // Error! i is out of scope
            return 0;
        }

    // Static Scope
        // static variables inside a function retain their value across function calls.
        // They have function scope but persist beyond function calls.

        void example() {
            static int count = 0; // Static variable
            count++;
            std::cout << count << std::endl;
        }
        
        int DEMOMAIN6() {
            example(); // Output: 1
            example(); // Output: 2
            return 0;
        }
        
    //  File Scope (static in global scope)
        // If a global variable is declared as static, it is limited to the file it is declared in.
        // This prevents name conflicts in multi-file projects.

        static int fileVar = 50; // Accessible only in this file


// Summary
    // Scope Type	                    Accessible From	                Lifetime
    // __________________________________________________________________________________________
    // Local	                        Within function/block	        Until function/block ends
    // Global	                        Anywhere in the file	        Until program ends
    // Namespace	                    Within the namespace	        Until program ends
    // Class/Struct	                    Within class methods	        Until object is destroyed
    // Function	                        Inside the function	            Until function ends
    // Loop/Block	                    Inside {} block	                Until block ends
    // Static (local)	                Inside the function	            Until program ends
    // File Scope (static global)	    Only in the same file	        Until program ends
