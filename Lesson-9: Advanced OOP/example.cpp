#include <iostream>
#include <cmath> // For sqrt if needed in future
using namespace std;

// Base class: Shape (Abstract Concept)
class Shape {
public:
    // Virtual method to calculate area (to be overridden in derived classes)
    virtual double area() {
        return 0.0;
    }

    // Virtual method to describe the shape
    virtual void describe() {
        cout << "I am a generic shape." << endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor initializing the radius
    Circle(double r) : radius(r) {} // radius(r) is same as radius = r;

    // Override the area method using formula: πr²
    double area() override {
        return 3.14159 * radius * radius;
    }

    // Override the describe method
    void describe() override {
        cout << "I am a circle with radius " << radius << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    // Constructor initializing width and height
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override the area method using formula: width × height
    double area() override {
        return width * height;
    }

    // Override the describe method
    void describe() override {
        cout << "I am a rectangle with width " << width << " and height " << height << endl;
    }
};

// Compile-time Polymorphism: Function Overloading
class InfoPrinter {
public:
    // Print integer
    void print(int i) {
        cout << "Integer: " << i << endl;
    }

    // Print double
    void print(double d) {
        cout << "Double: " << d << endl;
    }

    // Print string
    void print(const string& s) {
        cout << "String: " << s << endl;
    }
};

// Operator Overloading Example: Vector2D
class Vector2D {
public:
    double x, y;

    // Constructor with default values
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Overload the + operator for vector addition
    Vector2D operator + (const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y);
    }

    // Overload the * operator for dot product
    double operator * (const Vector2D& other) {
        return x * other.x + y * other.y;
    }

    // Method to display the vector
    void display() {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }
};

// Main function
int main() {
    cout << "=== Runtime Polymorphism with Inheritance ===" << endl;
    Shape* shape; // Base class pointer to demonstrate runtime polymorphism / dynamic binding

    // Create Circle and Rectangle objects
    Circle c(5);          // Circle with radius 5
    Rectangle r(4, 6);    // Rectangle with width 4 and height 6

    // Pointing to Circle object
    shape = &c;
    shape->describe();                     // Calls Circle's describe()
    cout << "Area: " << shape->area() << endl;

    // Pointing to Rectangle object
    shape = &r;
    shape->describe();                     // Calls Rectangle's describe()
    cout << "Area: " << shape->area() << endl;

    // Demonstrate compile-time polymorphism
    cout << "\n=== Compile-time Polymorphism: Function Overloading ===" << endl;
    InfoPrinter printer;
    printer.print(42);                     // Calls print(int)
    printer.print(3.14159);                // Calls print(double)
    printer.print("Hello, OOP!");          // Calls print(string)

    // Demonstrate operator overloading
    cout << "\n=== Operator Overloading: Vector2D Math ===" << endl;
    Vector2D v1(1.5, 2.5);
    Vector2D v2(2.0, 3.0);

    Vector2D sum = v1 + v2;                // Uses overloaded + operator
    double dot = v1 * v2;                  // Uses overloaded * operator

    cout << "v1 + v2 = ";
    sum.display();                         // Display result of addition

    cout << "v1 . v2 = " << dot << endl;   // Display result of dot product

    return 0;
}
