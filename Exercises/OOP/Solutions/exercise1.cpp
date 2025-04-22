#include <iostream>
#include <cmath>
using namespace std;

// Base class Shape (abstract class)
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual double perimeter() const = 0;  // Pure virtual function
    virtual ~Shape() {}  // Virtual destructor
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Rectangle(4.0, 5.0);
    shapes[1] = new Circle(3.0);

    for (int i = 0; i < 2; ++i) {
        cout << "Shape " << i + 1 << ":" << endl;
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl << endl;
    }

    // Clean up dynamic memory
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

    return 0;
}


// Explanation:
// Abstract class (Shape): We define an abstract class Shape with two pure virtual functions (area and perimeter). 
// This forces derived classes to implement these methods.

// Derived classes (Rectangle and Circle): Both classes implement the area() and perimeter() methods specific to their shape.

// Polymorphism: We create an array of Shape* and assign Rectangle and Circle objects to it. 
// The area() and perimeter() methods are called polymorphically.


