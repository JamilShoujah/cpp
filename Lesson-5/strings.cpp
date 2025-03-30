// Lesson 5 - Part 2: Strings

#include <cstring> // Required for string functions
#include <iostream>
using namespace std;

// In C++, strings can be handled in two main ways:
    // C-style strings (character arrays) – Using char arrays.
    // C++ strings (std::string) – Using the string class from the Standard Library (preferred).  

    // C-Style Strings (char arrays)
        // C-style string is an array of characters terminated by a null character (\0).
        //ex:
        char string1[] = "Hello"; // Implicitly includes '\0' at the end
        char string2[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Explicitly defined

        // NOTE:
            // Arrays must have enough space for the null character (\0).
            // Using char str[] = "Hello"; automatically adds \0.

    // Taking User Input with cin vs getline()
        // By default, cin stops at whitespace, so it doesn't work well for multi-word input.
        // get line allows us to read full input

        // ex:
            // with cin, we cant pass the following: "Jamil Shoujah". We can only pass "Jamil"
            // with getline(), we can pass "Jamil Shoujah".

    // String Functions (cstring Library). check line 3

    char str1[] = "Hello";
    char str2[] = "World";
    // Common Functions:
        // strlen(str) → Returns length of string
            //ex:
            void stringLenght(){
                cout << strlen(str1) << endl; // Output: 10 (length)
            } 
        // strcpy(dest, src) → Copies one string into another
            // literally makes the first param have the same value as the second param
            // ex:
            void copyString(){
                strcpy(str1, str2); // Concatenates str2 to str1
                // str1 will now be "World"
            }

        // strcat(dest, src) → Appends one string to another
            // ex: 
            void concatString(){
                strcat(str1, str2); // Concatenates str2 to str1
                // Output: HelloWorld
            }

        // strcmp(str1, str2) → Compares two strings
            // ex:
            void compareStrings(){
                cout << strcmp(str1, str2) << endl; // Compares (returns 0 if equal)
            }

    // C++ Strings (std::string)
        // C++ provides the string class, which is more powerful, flexible, and safer than C-style strings.

        #include <string> // Required for string class

        string str1 = "Hello";
        string str2("World");

        //  std::string automatically manages memory, unlike character arrays.
        // No need for \0, as C++ handles null termination internally.
    
        // String Operations
        string first = "Hello, ";
        string second = "World!";

            // concatination:
            string result = first + second; // "Hello, World!""

            // String Length
            int length = result.length(); // // Output: 13

            // Accessing Characters
            char charcater = result[0]; // 'H'

            // Substring Extraction
            string sub = result.substr(7, 5); // Start at index 7, length 5 // Output: World

            // Finding a Substring
            size_t pos = result.find("World"); // Finds "World" and returns index

            // Replacing a Substring
            string newResult = result.replace(7, 5, "Universe"); // Replace "World" with "Universe" // // Output: Hello, Universe!

    // Strings and Iterators
    // You can iterate over std::string using loops or iterators.
        // Using a for Loop
        void loopOverString(){
            string text = "Hello";
            for (int i = 0; i < text.length(); i++) {
                cout << text[i] << " ";
            }
        }

        // Using a Range-Based Loop
        void loopOverString2(){
            string text = "Hello";
            for (char c : text) {
                cout << c << " ";
            }
        }

        // Using Iterators
        void loopOverString3(){
            string text = "Hello";
            for (auto it = text.begin(); it != text.end(); ++it) {
                cout << *it << " ";
            }
        }

    // Mutability: Can Strings Be Changed?
        // C++ std::string is mutable (can be modified after creation).
        // C-style strings (char*) can be modified, but const char* cannot.

    // String Streams
        // Used for string manipulation and conversion.
        #include <sstream>
        
        void stringStreamDemo(){
            stringstream ss;
            ss << "Age: " << 25; // Append int to string
            string result = ss.str(); // Convert to string
            cout << result << endl; // Output: Age: 25
        }




