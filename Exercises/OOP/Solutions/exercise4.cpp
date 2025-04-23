#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}

    virtual double area() const {
        return 0.0;
    }

    virtual void display() const {
        cout << "Shape: " << name << endl;
    }

    virtual ~Shape() {}
};

// Derived Rectangle class
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    // Method overriding
    double area() const override {
        return width * height;
    }

    void display() const override {
        cout << name << " [Width: " << width << ", Height: " << height << ", Area: " << area() << "]" << endl;
    }

    // Method overloading
    void scale(int factor) {
        width *= factor;
        height *= factor;
    }

    void scale(double factor) {
        width *= factor;
        height *= factor;
    }

    // Operator overloading
    Rectangle operator+(const Rectangle& other) {
        return Rectangle(this->width + other.width, this->height + other.height);
    }
};

// Derived Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    // Method overriding
    double area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << name << " [Radius: " << radius << ", Area: " << area() << "]" << endl;
    }
};

// Main function to test
int main() {
    Rectangle r1(4, 5);
    Rectangle r2(2, 3);

    cout << "Original Rectangles:" << endl;
    r1.display();
    r2.display();

    Rectangle r3 = r1 + r2;
    cout << "\nAfter Adding Rectangles:" << endl;
    r3.display();

    cout << "\nScaling Rectangle by int factor 2:" << endl;
    r3.scale(2);
    r3.display();

    cout << "\nScaling Rectangle by double factor 1.5:" << endl;
    r3.scale(1.5);
    r3.display();

    Circle c1(3);
    cout << "\nDisplaying Circle:" << endl;
    c1.display();

    return 0;
}
