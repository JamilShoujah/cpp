// Lesson 9: Advanced Object Oriented Programming
#include <iostream>
using namespace std;
// review:
    //OOP is based on 4 main principles:
        // Encapsulation: Bundling data and methods.
        // Abstraction: Hiding implementation details.
        // Inheritance: Deriving new classes from existing ones.
        // Polymorphism: Same interface, different behavior.

    // Access Modifiers
        // public: Accessible from anywhere (inside or outside the class).
        // Private: Accessible only within the class. Not visible to derived classes or external code.
        // protected: Accessible within the class itself and its derived classes — but not from outside.

// Inheritance 
    // Inheritance is a feature in C++ that allows a new class (derived class) to take on the properties and behaviors (methods)
    // of an existing class (base class).

    // Syntax:
    class BaseClass {
    // Base class code
    };

    class DerivedClass : public BaseClass {
        // Derived class code
    };

    // Think of a Vehicle class as a base class, and Car and Truck as derived classes that inherit from Vehicle.

    // ex

    class Animal {
    public:
        void eat() { cout << "Eating food\n"; }
    };

    class Dog : public Animal {
    public:
        void bark() { cout << "Barking\n"; }
    };

    void Example() {
        Dog d;
        d.eat();  // Inherited function
        d.bark(); // Dog-specific function
    }

    // Explanation: The Dog class inherits the eat() method from the Animal class.

    //  Constructors and Destructors in Inheritance
    // Base Class Constructor and Destructor: When creating an object of a derived class, the constructor of the base class is called first.

    // ex:

    class Animal2 {
    public:
        Animal2() { std::cout << "Animal Constructor\n"; }
        ~Animal2() { std::cout << "Animal Destructor\n"; }
    };

    class Dog2 : public Animal2 {
    public:
        Dog2() { std::cout << "Dog Constructor\n"; }
        ~Dog2() { std::cout << "Dog Destructor\n"; }
    };

    void Example2() {
        Dog2 d;
    }

    // output:
        // Animal Constructor
        // Dog Constructor
        // Dog Destructor
        // Animal Destructor

// Polymorphism:
    // Polymorphism allows a derived class to provide a specific implementation of a method that is already
    // defined in its base class.

    // remember the example we discussed..
    // parents talk in a certain way, and genz which inherit the talking from parents, but they speak differently,
    // genz speak in a genz slang

    // Types of Polymorphism:
    //     Compile-time polymorphism (Function Overloading/Operator Overloading)
    //     Run-time polymorphism (Method Overriding)

// Compile-time Polymorphism (Static Binding)
    // This occurs when the decision about which function to call is made at compile time, not at runtime. 
    // It is achieved in two main ways:

    // 1. Function Overloading
    // Function overloading means having multiple functions with the same name but different parameters (number or type).

    // ex:
    class Printer {
    public:
        // Overloaded functions
        void print(int i) {
            cout << "Printing int: " << i << endl;
        }

        void print(double d) {
            cout << "Printing double: " << d << endl;
        }

        void print(const string& s) {
            cout << "Printing string: " << s << endl;
        }
    };

    void ExampleOne() {
        Printer p;
        p.print(42);          // Calls print(int)
        p.print(3.14);        // Calls print(double)
        p.print("Hello");     // Calls print(string)

    }

    // 2. Operator Overloading
    // Operator overloading allows you to redefine the way operators work for user-defined types like classes.
    // ex:

    class Point {
    public:
        int x, y;

        // Constructor with default parameters (if no values are passed, x and y will be 0)
        Point(int x = 0, int y = 0) : x(x), y(y) {}

       // Overloading the + operator so we can add two Point objects using p1 + p2
        Point operator + (const Point& p) {
            // When you do p1 + p2, this function is called with p2 as the parameter 'p'
            // It returns a new Point object with x and y added from both points
            return Point(x + p.x, y + p.y);
        }

        void display() {
            cout << "(" << x << ", " << y << ")" << endl;
        }
    };

    void ExampleTwo() {
        Point p1(1, 2);
        Point p2(3, 4);

        // Using the overloaded + operator to add p1 and p2
        // This will call the operator+ method we defined earlier
        Point result = p1 + p2;  // Uses overloaded + operator
        result.display();        // Output: (4, 6)

    }

// Method Overriding (Run-time Polymorphism)
    // the most common type of polymorphism
    // Use virtual keyword in the base class to allow method overriding in the derived class.
    // ex:

    // Base class: Animal
    class Animal3 {
    public:
        // Virtual function allows derived classes to override it
        virtual void sound() {
            std::cout << "Some animal sound" <<endl; // Base behavior for sound
        }
    };

    // Derived class: Dog
    class Dog3 : public Animal3 {
    public:
        // Overriding the sound function for Dog
        void sound() override {
            std::cout << "Bark\n"; // Dog-specific behavior for sound
        }
    };

    // Derived class: Cat
    class Cat3 : public Animal3 {
    public:
      // Overriding the sound function for Cat
        void sound() override {
            std::cout << "Meow\n";  // Cat-specific behavior for sound
        }
    };

    void Example3() {
        // Pointer to the base class (Animal)
        Animal3* a;

        // Creating objects of Dog and Cat
        Dog3 d;
        Cat3 c;

        // Assigning the address of the Dog object to the Animal pointer
        a = &d;

        // Calling the sound() method via the Animal pointer
        // Even though a is of type Animal*, the actual method that gets called
        // is the one defined in the Dog class due to polymorphism
        a->sound();  // Output: Bark

        // Assigning the address of the Cat object to the Animal pointer
        a = &c;

        // Calling the sound() method via the Animal pointer
        // Now the actual method that gets called is the one defined in the Cat class
        a->sound();  // Output: Meow
    }

    // The sound() function is overridden in the Dog and Cat classes. The appropriate method 
    // is called at runtime, based on the object type.

// Pure Virtual Functions and Abstract Classes
    // Pure Virtual Function: A function that has no implementation in the base class and 
    // forces derived classes to implement it.

    // Abstract Class: A class containing at least one pure virtual function.
    // Syntax:

    class Shape {
    public:
        virtual void draw() = 0; // Pure virtual function
    };

    class Circle : public Shape {
    public:
        void draw() override {
            std::cout << "Drawing Circle\n";
        }
    };

    void Example4() {
        Shape* shape = new Circle();
        shape->draw();  // Output: Drawing Circle
        delete shape;
    }

// Dynamic Polymorphism: Virtual Destructors
    // Why virtual destructors? 
    // When a derived class object is deleted via a base class pointer, a non-virtual destructor might 
    // not properly call the derived class's destructor, leading to resource leakage.

    // Example:

    class Base {
    public:
        virtual ~Base() { std::cout << "Base Destructor\n"; }
    };

    class Derived : public Base {
    public:
        ~Derived() { std::cout << "Derived Destructor\n"; }
    };

    int main() {
        Base* b = new Derived();
        delete b;  // Output: Derived Destructor, Base Destructor
        return 0;
    }

// Key Takeaways:
    // Inheritance allows code reuse and extension of base class functionality.
    // Polymorphism enables dynamic method calls and method overriding.
    // Use of virtual functions allows run-time polymorphism and the implementation of abstract classes.