// Lesson 7: Header files 

#include <iostream>
using namespace std;

// What is a Header File?
    // A header file in C++ is a file with the .h or .hpp extension that contains declarations of functions, 
    // classes, variables, constants, and macros. 
    // It is not meant to contain actual implementation code (though it can, in certain cases like templates or inline functions).

    // Think of header files as a way to organize and share declarations between multiple .cpp files.

// Why Use Header Files?
    // Reusability: Declare once, use in multiple .cpp files.
    // Separation of concerns: Keeps code cleaner by splitting interface (in .h) from implementation (in .cpp).
    // Simplifies large projects: Makes it easier to manage and understand.

// Structure of a Header File
    // please go to the lesson 7 header file for more details

// usage
    // to use the header file, simply include it!
    // ex:

    #include "lesson7.h"

// Now where are the implementations of the functions defined in the header?
// they are in a another cpp file.
// checkout the lesson7.cpp file

// now we since we have difined the header file with the declarations
// and after we define the functionality of these functions in another file
// we can use the functions here

// ex:
int main() {
    std::cout << "Add: " << add(5, 3) << "\n";
    std::cout << "PI: " << PI << "\n";

    Calculator calc;
    std::cout << "Multiply: " << calc.multiply(4, 6) << "\n";

    return 0;
}

// compilation
    // since we have multiple files here, we need to compile mutliple files in the compilation process
    // we use the same compilation command, but well include two files to compile

    // ex: for the folder structure above
    // ------------------------------------------
    // g++ main.cpp functionFile.cpp -o myprogram
    // ------------------------------------------


    // ex: for our current code
    // ------------------------------------------
    // g++ headerfiles.cpp lesson7.cpp -o myprogram
    // ------------------------------------------


// Note for folder structure
// you can use any folder structure you want, but be sure to import the files correctly

// example folder structure:
    // your_project/
    // ├── include/
    // │   └── math_utils/
    // │       ├── add.h
    // │       └── multiply.h
    // ├── src/
    // │   ├── add.cpp
    // │   └── multiply.cpp
    // └── main.cpp

// in main to use teh add.h file we would do this:
// #include "math_utils/add.h"

// to get the actual path, just copy the file's relative path and paste it
