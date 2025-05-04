// Lesson 12: Templates
#include <iostream>
using namespace std;

// Templates in C++ are a powerful feature that allows functions and classes to operate with generic types. 
// This means that you can write a single function or class to work with different data types, without duplicating the code. 
// There are two types of templates in C++:
    // Function Templates: Allow you to create a generic function that can handle different data types.
    // Class Templates: Allow you to create a generic class that can handle different data types.

// Function Templates:
// A function template is defined by using the template keyword before the function definition. 
// It lets you define a function without specifying the type of its arguments.
// The function will be automatically instantiated for the appropriate types when it is called.

// Syntax of Function Template

template <typename T> // template <typename T> is the template declaration.
T add(T a, T b) { // T is a placeholder for the data type.
    // add(T a, T b) is the function definition that works with any data type T that supports the + operator.
    return a + b;
}

template <typename T, typename M>
void printData(T a, M b) {
    cout << "First: " << a << ", Second: " << b << endl;
}

template <typename J, typename R>
R specialAdd(J val1, R val2){
    return val1 + val2
}


void functionTemplateExample() {
    int x = 5, y = 10;
    double dx = 3.5, dy = 4.5;
    string sx ="Hello ", sy ="World!";
    // Here, the compiler automatically infers the type as 'int'
    cout << "Sum of integers: " << add(x, y) << endl;

    // Here, the compiler automatically infers the type as 'double'
    cout << "Sum of doubles: " << add(dx, dy) << endl;

    cout << add(sx, sy) <<endl;
}

// Class Templates:
// A class template allows you to create a class to handle various types, much like function templates but for 
// entire classes. This is useful when you need a class that can store or operate on values of different types.

// Syntax of Class Template

template <typename T> // template <typename T> declares a template that works with a type T.
class Boxs { // Boxs is a class that can store any type T.
public:
    T value;
    Boxs(T val) : value(val) {}
    T getValue() { return value; }
};

// example:
// Class template definition
template <typename T>
class Box {
private:
    T value;   // The value stored in the box

public:
    // Constructor to initialize the value
    Box(T val) : value(val) {}

    // Getter function to return the stored value
    T getValue() { 
        return value; 
    }
    
    // Setter function to update the value
    void setValue(T val) {
        value = val;
    }
};

void classTemplateExample() {
    // Creating a Box of integer
    Box<int> intBox(5);  // Here, Box<int> means T is replaced by int
    cout << "Integer Box Value: " << intBox.getValue() << endl;

    // Creating a Box of double
    Box<double> doubleBox(3.14);  // Here, Box<double> means T is replaced by double
    cout << "Double Box Value: " << doubleBox.getValue() << endl;

    // Changing the value in the integer box
    intBox.setValue(10);
    cout << "Updated Integer Box Value: " << intBox.getValue() << endl;

}
