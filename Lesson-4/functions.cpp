// Lesson 4 - Part 1: Functions

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// In C++, functions are essential building blocks of a program, 
// used to structure and reuse code efficiently.

// Function Declaration & Definition
    // A function in C++ consists of:
        // Return Type – Specifies the type of value the function returns.
        // Function Name – Identifier for calling the function
        // Parameter List (Optional) – Defines input arguments.
        // Function Body – Contains executable statements.
        // Return Statement (Optional) – Returns a value if needed.
        // ex:

        int add(int a, int b) {
            return a + b;
        }

    // what is function declaration?
        // A function declaration tells the compiler that a function exists and how it should be called.
        // It specifies the return type, function name, and parameters but does not include the function body.
        // It is usually placed before main() or in a header file. More on that later on!
        // ex:
        int multiply(int, int);

    // What is function definition?
        // The function definition contains the actual implementation (function body).
        // It provides the logic that executes when the function is called.
        // ex:
        int multiply(int a, int b) { // Function definition
            return a * b;
        }

    // what is the difference between them?
        // A function declaration tells the compiler that a function exists by specifying its name, return type, 
        // and parameters without providing the actual implementation.
        
        // A function definition includes the complete implementation of the function with executable statements.

    // When to use each?
        // Function declarations are useful when calling a function before defining it or when working with multiple files,
        // whereas function definitions are necessary to execute the function.
        // in other words, use a function declaration when you want to tell the compiler about a function before 
        // using it, especially if the function is defined later in the code or in another file. 
        // This helps keep your code organized, allows separation of logic, and avoids errors when calling a 
        // function before its definition.

    // thats the cool thing about functions.. they can be placed anywhere in the file.. even after the main().
    // but inorder to tell the compiler that the function exists, we need to declare it before main
    // check this example below to get a better understanding of what i mean.

    
        void printMessage(); // Function declaration

        int main() {
            printMessage(); // Function call before definition
            return 0;
        }

        void printMessage() { // Function definition
            cout << "Hello, World!" << endl;
        }

        // NOTE: the function declaration is not necessary if the function's definition was implemented above main.

    // return types
    // The return type of a function defines the type of value that the function will return after execution.
    // in other words, The return type of a function tells what kind of value the function will give back after running.
        // If the function does not return anything, use void.
        // ex:
        void printMessage() { // No return value
            cout << "Hello, World!" << endl;
        }

        // If it returns a number, use int (whole number) or double (decimal).
        // ex:

        int add(int a, int b) { // Function returns an int
            return a + b;
        }

        double divide(double a, double b) {
            return a / b; // Returns a floating-point result
        }

        // If it returns text, use string or char (for a single letter).
        //ex:

        string getGreeting() {
            return "Hello, C++!";
        }

        char getFirstLetter() {
            return 'A'; // Returns a character
        }

        // If it returns true or false, use bool.
        // ex:
        bool isEven(int num) {
            return num % 2 == 0;
        }

        // If it returns a group of values use struct, or class.
        // ex:

        // Note: the function will return an object of type class / struct
        
        struct Point {
            int x, y;
        };
        
        Point getPoint() {
            return {10, 20}; // Returns a struct object
        }

        // if it returns an array
            // In C++, a function cannot return an entire array directly, but it can return a pointer to an array.

            int* getNumbers() {  
                static int numbers[3] = {10, 20, 30}; // Static array
                return numbers; // Return pointer to first element
            }

            // Use std::vector Instead of Pointers for best practice
            
            vector<int> getNumbersTwo() {
                return {10, 20, 30}; // Return a vector
            }

    // types of functions
        // User-Defined Functions
            // These are functions explicitly created by the programmer to perform specific tasks.
            // like the functions above

        //  Built-in (Library) Functions
            //C++ provides many standard functions inside libraries like <iostream>, <cmath>, <algorithm>
            // ex:
                //cout from <iostream>
                //sqrt(16) <cmath>

        // recursive functions:
            // A recursive function is a function that calls itself to solve a problem in smaller parts.
            // It continues calling itself until it reaches a base case, which stops the recursion.
            // ex:
            int factorial(int n) {
                if (n <= 1) return 1; // base case
                return n * factorial(n - 1);
            }

            // How Recursive Functions Work
                // Base Case → The condition that stops recursion. also to prevent infinite loops
                // Recursive Case → The function calls itself with a smaller problem.

            // lets take a look at the example above in more detail
            // The factorial of a number n is:
                // n!=n×(n−1)×(n−2)×...×1
                // ex: 5!=5×4×3×2×1=120
                //     5! = 5 * 4! 

            // this is how the function works:
                // factorial(5) = 5 * factorial(4)
                // factorial(4) = 4 * factorial(3)
                // factorial(3) = 3 * factorial(2)
                // factorial(2) = 2 * factorial(1)
                // factorial(1) = 1  (Base case, stops recursion)

            // Now, returning the values step by step:
                // factorial(2) = 2 * 1  →  2
                // factorial(3) = 3 * 2  →  6
                // factorial(4) = 4 * 6  →  24
                // factorial(5) = 5 * 24 →  120

            // When to Use Recursion?
                // Good for:
                    // Problems that can be broken into smaller subproblems (e.g., factorial, Fibonacci, tree traversal).
                    // When writing iterative code is complex.
                // Avoid when:
                    // The recursion depth is too high (it can cause stack overflow).
                    // Iterative solutions are simpler and more efficient.


    // function parameters
        // When you call a function in C++, you pass arguments (also called parameters) to it. 
        // These arguments are values that the function will use to perform its task.

        // When passing arguments to a function in C++, you can do it in three main ways:
            // Pass by Value (what we usually do)
            // Pass by Reference
            // Pass by Pointer

        // Pass by Value:
            // A copy of the original variable is made, and the function works with this copy instead of the original.
            // Changes inside the function do not affect the original variable.
            // ex:

            void modify(int x) { // x is a copy of the argument
                x = 10; // Only changes the copy, not the original
            }

            // how to call in main?
                // modify(num); // Passes a copy of num

            // when to use?
                // Use when you don't want the function to modify the original value.
                
            // NOTE: Avoid for large objects (e.g., arrays, structs) because copying is expensive

        // Pass by Reference
            // The function receives a reference to the original variable.
            // Changes inside the function affect the original variable (because they modify the same memory location)
            // ex:

            void modify(int &x) { // x is a reference to the original
                x = 10; // Changes the original variable
            }

            // how to call in main?
                // modify(num); // Passes reference to num

            // when to use?
                // Use when you need to modify the original variable.
                // More efficient than pass by value for large data types

        // Pass by Pointer
            // A pointer to the original variable is passed.
            // You must use * to access or modify the original value.
            // ex:

            void modify(int *x) { // x is a pointer to an int
                *x = 10; // Dereference pointer to modify the value
            }

            // how to call in main?
                // modify(&num); // Pass address of num

            // when to use?
                // Used when working with dynamically allocated memory.
                // Useful for modifying multiple values (arrays, linked lists).

    // function overloading
        //Function Overloading means you can have multiple functions with the same name, 
        // but they must have different parameters (either in type, number, or both). 
        // The compiler determines which function to call based on the arguments passed.

        // Why Use Function Overloading?
            // Improves code readability by using a single function name for similar operations.
            // Avoids redundant function names (e.g., addInt(), addDouble(), etc.).
            // Allows flexibility in handling different data types or numbers of parameters
        
        // Ex:
            int add(int a, int b) { // Function for integers
                return a + b;
            }

            double add(double a, double b) { // Function for doubles
                return a + b;
            }

            int add(int a, int b, int c) { // Function for 3 parameters
                return a + b + c;
            }

        // ex 2 : function Overloading with Mixed Data Types & Parameters

            void print(int x) { 
                cout << "Integer: " << x << endl;
            }
            
            void print(double x) { 
                cout << "Double: " << x << endl;
            }
            
            void print(string x) { 
                cout << "String: " << x << endl;
            }

        // Function Overloading Rules
            // Functions must have different parameter lists (either different types or number of parameters).
            // Return type alone cannot differentiate functions.
            // Overloaded functions cannot have the same signature (same parameters). we will discuss this in the future


    // inline functions
        // For small functions, using inline can reduce function call overhead.
        // ex:

        inline int square(int x) { return x * x; }

        // The inline keyword is a suggestion to the compiler to replace function calls with the actual function 
        // body at compile-time.
        

        // Without inline The function call would result in a function call at runtime.
        // This means the CPU needs to jump to the function's memory location, execute it, 
        // and then return to the main program.

        // With inline The compiler replaces the function call with its actual code
        // This removes the overhead of a function call, making execution slightly faster.

        //  When Should You Use inline?
            // For small, frequently used functions (like mathematical operations).
            // To eliminate function call overhead in performance-critical code.
            // For simple one-liner functions that execute very quickly.

    // default arguments
        // Functions can have default parameter values.
        // ex:

        void greet(string name = "Guest") {
            cout << "Hello, " << name << "!" << endl;
        }

    // templates
        // Templates allow functions to work with different data types.
        // Instead of writing multiple overloaded functions for int, double, float, etc., 
        // templates enable generic programming.
        
        // ex:
        template <typename batee5>
        batee5 maxVal(batee5 a, batee5 b) {
            return (a > b) ? a : b;
        }

        // Why Use Function Templates?
            // Reusability – Write once, use for any data type.
            // Eliminates redundancy – No need to write separate functions for int, float, double, etc.
            // Type safety – The compiler checks type correctness at compile time.

        // You can also create templates that work with more than one type
        // ex:
        template <typename Mawzi, typename bandoura>
        void printData(Mawzi a, bandoura b) {
            cout << "First: " << a << ", Second: " << b << endl;
        }

        // Sometimes, you may want a different implementation for a specific type.
        // ex:

        // General template
        template <typename T>
        void display(T x) {
            cout << "General template: " << x << endl;
        }

        // Specialized version for strings
        template <>
        void display<string>(string x) {
            cout << "Specialized template for strings: " << x << endl;
        }

        //Function Overloading vs Function Templates:

            // Number of functions written	
                // Overloading: Multiple	
                // Templates: Only one

            // Code duplication		
                // Overloading: More code	
                // Templates: Less code

            // Flexibility		
                // Overloading: Works for predefined types
                // Templates: Works for any type

            // Compile-time performance		
                // Overloading: More function calls to check	
                // Templates: Only one function to generate

            // Customization		
                // Overloading: Specific implementations for each type	
                // Templates: Generalized for multiple types