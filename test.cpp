#include <iostream>

// Functions (Lesson 4)
// Arrays & Strings (Lesson 5)
// Pointers & References (Lesson 6)

int main() {
    int x = 5;
    
    // Trying to assign a string to an integer variable (type mismatch)
    // x = "Hello, world!"; // This will cause a compilation error
    
    std::cout << x << std::endl; // This line won't be reached due to the error above
    return 0;
}
