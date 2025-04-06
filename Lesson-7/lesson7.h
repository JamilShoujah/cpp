// NOTE: Contains declarations only (function signatures, class definitions, constants):

#ifndef MATH_UTILS_H // This is a preprocessor directive that checks If the macro MATH_UTILS_H has not been defined yet.
    // This is the start of an include guard, which helps prevent a header file from being included more than once in a compilation unit.
    // If you include the same header twice (either directly or indirectly), the compiler might throw "redefinition" errors. 
    // This line helps prevent that.

#define MATH_UTILS_H // f MATH_UTILS_H hasn’t been defined yet, we define it here.
    // this ensures that the compiler processes this header file only once per translation unit.

int add(int a, int b); // Function declaration
// It tells the compiler that there exists a function named add which takes two integers and returns an integer.

// Constant
const double PI = 3.14159;
    // This is a constant declaration (and definition).
    // It's a named value of type double that holds the mathematical constant π.
    // const means its value cannot be changed anywhere in the program.

// Class declaration
// further explanantion when we get to classes and oop next lesson
class Calculator {
public:
    int multiply(int a, int b);
};

#endif // MATH_UTILS_H
    // This closes the #ifndef block.
    // It signals the end of the include guard.
