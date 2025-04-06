// Lesson 8: Object Oriented Programming 
#include <iostream>
using namespace std;
// What is Object-Oriented Programming (OOP)?
    // OOP is a programming paradigm / style based on the concept of “objects”, which can contain data and functions. 
    // It helps you organize code better, especially in large projects.

// The Four Pillars of Object Oriented Programming
    // Encapsulation
        // Wrapping data and methods that operate on the data into a single unit (class).
        // Access modifiers (private, protected, public) are used to restrict access.

    // Abstraction
        // Hiding implementation details and showing only essential features.
        // Achieved via abstract classes or interfaces (pure virtual functions).

    // Inheritance
        // A class (child) can inherit attributes and methods from another class (parent).
        // Promotes code reuse.
        // Supports single, multilevel, multiple inheritance.

    // Polymorphism
        // Ability of a function or object to behave differently based on the context.

    // we will discuss each of these in details as we get to them

// The Basics
    // what is a class?
       // a class is a blueprint for creating objects. It defines the properties (also called attributes or fields) and 
       // behaviors (called methods) that the objects created from the class will have.

    // what is an object?
        // Object is a real instance of that blueprint 
        // in other words, the object was created from the class

    // Sytax of a class:
        // we define a class by simply using the class keyword, provide the class with a name and wrap it with {}
        // note that you should always place a semi colon after creatining the class.
        // ex:

        class Person {
        // access modifiers
        public:
            // Data members (attributes)
            string name;
            int age;

            // Member function (method)
            void introduce() {
                cout << "Hi, I am " << name << " and I am " << age << " years old." << endl;
            }
        };

        // creating an instance of the class above:

        void instanceCreation() {
            Person p1;           // Create object p1

            p1.name = "Alice";   // Assign values to data members
            p1.age = 25;

            p1.introduce();      // Call the method

        }

    // Access Modifiers:
        // Access modifiers are keywords in object-oriented programming that control who can access the variables, methods, and classes. 
        // They help you encapsulate your code by restricting direct access to the internals of your objects.

        // these are the major access modifiers
        // public
            // Members are accessible from anywhere in the program.
        // private
            // Members are only accessible within the class. Most of the time, variables are private and accessed via getter/setter functions.
        // protected
            // Like private, but accessible in derived (child) classes too.

    class Student {
    private:
        int id;

    public:
        void setId(int studentId) {
            id = studentId;
        }

        int getId() {
            return id;
        }
    };       

    void exampleTwo() {
        Student s;
        // Trying to access s.id directly will give a compilation error because it's private.
        // to access such data we need to define getters and setters
        s.setId(1001);
        cout << "Student ID: " << s.getId() << endl;
    }

    // Constructors
    // A constructor is a special function that runs automatically when you create an object.
    // its named after the class
    // incase we didnt define this function, the default constructor will run
    
    // Default Constructor
    // If you don’t create a constructor, C++ provides a default constructor (with no parameters). But once you create a custom constructor, 
    // the default is not provided unless you explicitly define it

    class Book {
    public:
        string title;
        int pages;

        // Constructor
        Book(string t, int p) {
            title = t;
            pages = p;
        }

        void printInfo() {
            cout << title << " has " << pages << " pages." << endl;
        }
    };

    void exmapleThree() {
        Book b1("C++ Basics", 300);
        b1.printInfo(); // "C++ Basics has 300 pages."
    }

    // Destructors
    // A destructor is called when an object is destroyed (e.g., goes out of scope). It's used to free up resources like memory or files.
    // similar to a constructor, the destructor also shares the class name, but with a ~ symbol

    class Demo {
    public:
        Demo() {
            cout << "Constructor called!\n";
        }

        ~Demo() {
            cout << "Destructor called!\n";
        }
    };

    //  Inline Member Functions
    // You can define functions inside the class (as we've done so far), or outside the class like this:

    class Car {
    public:
        string model;
        void display();  // Declaration
    };

    // Definition outside the class 
    void Car::display() {
        cout << "Car model: " << model << endl;
    }

