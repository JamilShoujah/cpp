#include <iostream>
#include <cmath>
using namespace std;

// Abstract base class Shape
class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
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
};

// Derived class Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
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
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Rectangle(4.0, 5.0);
    shapes[1] = new Triangle(3.0, 4.0);
    shapes[2] = new Circle(2.0);

    for (int i = 0; i < 3; ++i) {
        cout << "Area of Shape " << i + 1 << ": " << shapes[i]->area() << endl;
    }

    // Clean up dynamic memory
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}


// Explanation:

// Polymorphism and Virtual Functions: The area() function is declared as a pure virtual function in the Shape class, 
// and each derived class (Rectangle, Triangle, Circle) provides its own implementation.
// Demonstration: We use a Shape* array to hold different types of shapes and calculate the area of each shape polymorphically.

