// Lesson 12: Templates
#include <iostream>
using namespace std;

// Templates in C++ are a powerful feature that allows functions and classes to operate with generic types. 
// This means that you can write a single function or class to work with different data types, without duplicating the code. 
// There are two types of templates in C++:
    // 1. Function Templates
    // 2. Class Templates

// ==============================
// FUNCTION TEMPLATES
// ==============================

// A function template lets you define a generic function that works with any data type.
// Syntax of Function Template:
template <typename T>
T add(T a, T b) {
    return a + b;
}

// to use two different data types
template <typename T, typename M>
void printData(T a, M b) {
    cout << "First: " << a << ", Second: " << b << endl;
}

template <typename J, typename R>
R specialAdd(J val1, R val2){ // return type is R
    return val1 + val2; // This works as long as J + R is a valid expression
    // by valid i mean that the + operator works on the two types J and R
}

// ==============================
// FUNCTION TEMPLATE SPECIALIZATION
// ==============================

// Sometimes, you want a special implementation for a particular type. For that, you can specialize the template.
template <>
string add<string>(string a, string b) {
    return a + " (specialized) " + b;
}

void functionTemplateExample() {
    int x = 5, y = 10;
    double dx = 3.0, dy = 4.5;
    string sx = "Hello", sy = "World";

    cout << "Sum of integers: " << add(x, y) << endl;       // Uses general template
    cout << "Sum of doubles: " << add(dx, dy) << endl;      // Uses general template
    cout << "Sum of strings (specialized): " << add(sx, sy) << endl; // Uses specialized version
}


// ==============================
// CLASS TEMPLATES
// ==============================

// A class template allows a class to operate on multiple data types.
template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() { return value; }
    void setValue(T val) { value = val; }
};

// ==============================
// CLASS TEMPLATE SPECIALIZATION
// ==============================

// Specialize the Box class for string type
template <>
class Box<string> {
private:
    string value;

public:
    Box(string val) : value(val) {}
    string getValue() { return "Specialized Box: " + value; }
    void setValue(string val) { value = val; }
};

void classTemplateExample() {
    Box<int> intBox(5);
    cout << "Integer Box Value: " << intBox.getValue() << endl;

    Box<double> doubleBox(3.14);
    cout << "Double Box Value: " << doubleBox.getValue() << endl;

    Box<string> strBox("Template");
    cout << strBox.getValue() << endl; // Will use the specialized class version

    intBox.setValue(10);
    cout << "Updated Integer Box Value: " << intBox.getValue() << endl;
}

// ==============================
// MAIN
// ==============================

int main() {
    functionTemplateExample();
    cout << "----------------------\n";
    classTemplateExample();
    return 0;
}


// Summary of Specialization:                      
// Function:  
    // template<typename T> T add(T a, T b) => specialization => template<> returnType add<returnType>(returnType a, returnType b)
// Class:
    // template<typename T> class Box => specialization => template<> class Box<returnType>     
