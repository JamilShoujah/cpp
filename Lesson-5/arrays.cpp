// Lesson 5 - Part 1: Arrays
#include <iostream>
#include <vector>

using namespace std;

// Arrays
    // What is an Array?
        // An array in C++ is a collection of elements of the same data type stored in contiguous memory locations.
        // Each element is accessible via an index, and the size of the array is fixed when it's declared.

    // Declaring Arrays
        // When you declare an array in C++, you specify:
            // The type of data that will be stored.
            // The number of elements it will hold.

        // ex:
        int arr[5]; // Array of 5 integers.
        // This declaration creates an array of size 5 that can hold 5 integer values.

    // Initializing Arrays
        // You can initialize an array in several ways:
            // Static initialization (when values are known at compile time):
                // ex:
                int arr[5] = {1, 2, 3, 4, 5}; // Array of 5 integers with initial values
                
            // Partial initialization (leaving some values uninitialized will set them to zero):
                // ex:
                int arr[5] = {1, 2}; // arr = {1, 2, 0, 0, 0}

            // Zero initialization (using curly braces with no values):
                // ex:
                int arr[5] = {}; // arr = {0, 0, 0, 0, 0}

    // Accessing Array Elements
        // Array elements are accessed using their index. The index starts at 0, so the first element is at index 0, 
        // the second at index 1, and so on.
        // yes thats weird that we start from zero, but it is what it is
        // ex:
        void printArrayindexValue () {
            // focus on this section
            // ------------------------------
            int arr[5] = {1, 2, 3, 4, 5};
            cout << arr[0]; // Prints 1
            cout << arr[3]; // Prints 4
            // ------------------------------
        }
            

    // Modifying Array Elements
        // You can modify the value of any element in the array using its index
        // ex:

        void changeIndexValue () {
            // focus on this section
            // ------------------------------
            int arr[5] = {1, 2, 3, 4, 5};
            arr[2] = 10; // Changes the third element to 10 
            // ------------------------------
        }

    // Iterating Through Arrays
        // You can iterate over an array using different loop structures:

        //Using a for Loop
            //The most common way to iterate over an array is with a for loop.
            // ex:

            void forLoopIterationOverArray () {
                // focus on this section
                // ------------------------------
                int arr[5] = {1, 2, 3, 4, 5};

                for (int i = 0; i < 5; i++) {
                    cout << arr[i] << " "; 
                }
                // ------------------------------

                // the output will be: 1 2 3 4 5
            }

            // A simpler way to iterate over an array:
            void forLoopIterationOverArrayTwo () {
                // focus on this section
                // ------------------------------
                int arr[5] = {1, 2, 3, 4, 5};

                for (int num : arr) {
                    cout << num << " ";
                }
                // ------------------------------
                // This loop automatically iterates over all elements of arr. 
                // the output will be: 1 2 3 4 5
            }


        // using a while loop
            // ex:

            void whileLoopIterationOverArray() {
                // focus on this section
                // ------------------------------
                int arr[5] = {1, 2, 3, 4, 5};

                int i = 0;
                while (i < 5) {
                    cout << arr[i] << " ";
                    i++;
                }
                // ------------------------------
                // the output will be: 1 2 3 4 5
            }

        // using a do-while loop
            // ex:

            void doWhileLoopIterationOverArray() {
                // focus on this section
                // ------------------------------
                int i = 0;
                do {
                    cout << arr[i] << " ";
                    i++;
                } while (i < 5);

                // ------------------------------
                // the output will be: 1 2 3 4 5
            }

    // Multi-Dimensional Arrays
        // A multi-dimensional array is an array of arrays. The most common type is a 2D array.
        // also know as matricies

        // Declaring and Initializing a 2D Array
        //ex:
            int matrix[3][3] = {
                {1, 2, 3}, 
                {4, 5, 6}, 
                {7, 8, 9}
            };

        // Accessing Elements in a 2D Array
        // ex:

        void printElementInMatrix() {
            // focus on this section
            // ------------------------------
            cout << matrix[1][2]; // Accesses the element in the second row, third column (6)
            // ------------------------------
        }

        // iterating over a 2D array
        // ex:

        void iteratingOver2DArray() {
            // focus on this section
            // ------------------------------
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            // ------------------------------
            // the output will be:
                // 1 2 3  
                // 4 5 6  
                // 7 8 9  

        }

// Vectors (Dynamic Arrays)
    // NOTE: Vectors are not linked lists.. keep that in mind
    // more on linked lists later
    // A vector in C++ is part of the Standard Template Library (STL) and provides a dynamic array that can grow and shrink in size.
    // Unlike normal arrays, vectors handle memory management automatically.

    // To use vectors, include the <vector> header (Line 3)
 
    // Declaring and Initializing Vectors
    vector<int> vec; // Declares an empty vector of integers
    // since its dynamic, no need to specify it's size

    // Initializing a Vector

    vector<int> vec1 = {1, 2, 3, 4, 5}; // Direct initialization
    vector<int> vec2(5, 10); // Creates a vector of size 5, all initialized to 10
    vector<int> vec3(vec1); // Copies contents of vec1 into vec3

    // Accessing and Modifying Vectors

        // You can access vector elements using the index.
        void printVectorIndexValue () {
            // focus on this section
            // ------------------------------
            cout << vec1[0]; // Access first element (1)
            cout << vec1.at(2); // Access third element (3) with bounds checking
            // .at() provides bounds checking and throws an error if out of range.
            // so it is safter to use
            // ------------------------------
        }

        // Modifying Elements

        void modifyVectorIndex () {
            // focus on this section
            // ------------------------------
            vec1[2] = 10; // Change the third element
            // ------------------------------
        }
    
    // Adding and Removing Elements
        // Adding Elements

        void addingToVector () {
            // focus on this section
            // ------------------------------
            vec.push_back(6); // Adds 6 at the end
            vec.insert(vec.begin() + 1, 9); // Inserts 9 at index 1
            // ------------------------------
        }

        // Removing Elements
        void removingFromVector () {
            // focus on this section
            // ------------------------------
            vec.pop_back(); // Removes the last element
            vec.erase(vec.begin() + 1); // Removes the second element
            vec.clear(); // Removes all elements
            // ------------------------------
        }

    // Vector Properties
        // Size and Capacity

        void vectorFunctions () {
            // focus on this section
            // ------------------------------
            cout << vec.size(); // Number of elements
            cout << vec.capacity(); // Allocated storage space
            cout << vec.empty(); // Returns true if empty            
            // ------------------------------
        }

        // NOTE:  Size refers to the number of elements, while capacity is the allocated memory (which may be larger than size).

    // itterating over a vector
        // using a for loop

        void forLoopIteratingOverVector () {
            // focus on this section
            // ------------------------------
            for (int i = 0; i < vec.size(); i++) {
                cout << vec[i] << " ";
            }            
            // ------------------------------           
        }


        // Using a Range-Based for Loop
        void rangedForLoopIteratingOverVector () {
            // focus on this section
            // ------------------------------
            for (int num : vec) {
                cout << num << " ";
            }         
            // ------------------------------           
        }

        // Using Iterators
        void rangedForLoopIteratingOverVector () {
            // focus on this section
            // ------------------------------
            vector<int>::iterator it;
            for (it = vec.begin(); it != vec.end(); ++it) {
                cout << *it << " ";
            }        
            // ------------------------------           
        }

        // sorting vectors

        #include <algorithm>

        void sortMyVector(){
            // focus on this section
            // ------------------------------
            sort(vec.begin(), vec.end()); // Sorts in ascending order
            sort(vec.rbegin(), vec.rend()); // Sorts in descending order
            // ------------------------------
        }

    // 2D Vectors (Vector of Vectors)  
        
        // access a 2d vector
        void accessVector(){
            // focus on this section
            // ------------------------------
            vector<vector<int>> matrix(3, vector<int>(3, 0)); // 3x3 matrix filled with 0s
            matrix[1][2] = 5; // Change the element at row 1, column 2 to 5
            // ------------------------------
        }


// vectors vs arrays
    // Size	
        // Vector: Dynamic (grows/shrinks)	
        // arrays:Fixed at compile-time
    // Memory Management
        // Vector: Automatic	
        // arrays: Manual
    // Performance
        // Vector: Slight overhead due to resizing
        // arrays: Faster for fixed sizes
    // Bounds Checking		
        // Vector:.at() provides safety
        // arrays:  No bounds checking
