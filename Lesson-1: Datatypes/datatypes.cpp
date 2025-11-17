// Lesson 1: Basics of programming

// before we dive into the basics of programming, we must first understand the different types of data that exist.
// there are a lot of data types so well pass over every single one in details
// you might not use everything now, but later on, they will be essential

#include <string>

// Primitive Data Types

    // int: 
        // Used for storing whole numbers
        // typical size is 4 bytes
        // ex:

        int a = 5;

    // short:
        // smaller version of int, typically used when memory is a concern.
        // size is 2 bytes
        // ex:

        short b = 1;

    // long:
        // A larger version of int, used for larger integer values.
        // 4 or 8 bytes, depending on the system.
        // ex:

        long c = 100000000000000000;
    
    // float:
        // used for storing decimal numbers
        // size is 4 bytes
        // ex:

        float d = 69.420;

    // double:
        // A double-precision floating-point type, which can hold larger or more precise numbers
        // size is 8 bytes
        // ex: 

        double e = 12.3456789101112131415;


    // char:
        // Used to store a single character like letters or symbols
        // size 1 byte
        // ex: 

        char f = 'A';

    // bool:
        // used to store true or false values
        // size 1 byte
        // ex:

        bool g = true;

// Derived Data Types:

    // Strings:
        // strings are consider a unique type. theyre not primitive as they are basically a list of characters
        // to use strings we need to use the std namespace and a library
        // check line 7
        // ex:

        std::string h = "hello world";

    // arrays:
        // An array is a collection of elements of the same type.
        // ex:

        int numbers[5] = {1, 2, 3, 4, 5};

    // Pointer:
        // A pointer is a variable that holds the memory address of another variable.
        // dont overthink it.. its just pointing to where that variable is in memory
        // The pointer itself doesn't store the value, just the location where the value is stored.
        // in order to get the value, we need to dereference the pointer. more on that later!
        // Ex:

        int* pointer = &a;  // The pointer 'pointer' stores the memory address of 'a'.
        

    // reference:
        // A reference is an alias for another variable. It's another name that refers to the same memory location.
        // It allows you to access the value of the original variable without creating a copy.
        // Ex:
        int& ref = a;  // 'ref' is a reference to 'a', meaning both 'ref' and 'a' refer to the same variable.


// User Defined Types

    // Struct:
        // A structure is a collection of different types of data stored together.
        // A structure in C++ is used to create a custom data type that can hold multiple different types of data together. 
        // It allows you to group variables of different types under a single name, which can represent more complex data.
        // ex:

        struct Person {
            std::string name;
            int age;
        };

    // Class:
        // A class is similar to a structure but with added features like encapsulation and methods.
        // ex:
        class Car {
        public:
            std::string model;
            int year;

            void displayInfo() {
                // do something
            }
        };

    // enum:
        // An enum is used to define a set of named integer constants.
        // in other words.. An enum is a way to create a custom data type that represents a set of related values, 
        // typically integers, but with meaningful names instead of just numbers. It makes your code easier to read and 
        // understand by using descriptive names instead of raw numbers.
        // ex:

        enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };


// Type changing via casting is possible but for certain situations. we will cover this in the near future.
