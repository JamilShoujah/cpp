// Lesson 11 - part 1: Operator Overloading Recap
#include <string>
#include <iostream>
using namespace std;
// in C++ we can create a special type of functions which are called operator functions.
// We use those operator functions in order to define how a certain operator will behave with a specific data type
// lets look at it from a basic data type perspective:

// Take a look at the below example:
void example() {

    int a = 4, b = 5, c;

    c = a + b ;
}

// we have plus operator but in this situation our compiler already knows how the plus operator 
// behaves when dealing with two numbers.
// So in this situation the plus operator will sum these two numbers 

// lets take a look at another example

void exampleTwo(){
    string a = "Hello ", b = "world!", c ;
    
    c =  a + b; // "Hello world!"
}

// in this example, the plus operator behaves differntly when dealing with two strings.
// it would concatinate the two strings togther forming another bigger string.


// but what is going to happen if we have a user-defined data type?
// let's say we have a structure called car. If i try to do something like car1 + car2, what is going to happen?
// how will this plus operator behave so in this situation?
// this is where operator overloading comes into play

// Let's define a simple user-defined data type
struct Car {
    string brand;
    int horsepower;

    // Overload the '+' operator to combine two Car objects
    // The object on the left-hand side of the + is implicitly passed as this.
    // The object on the right-hand side is explicitly passed as the parameter other.
    Car operator +(const Car& other) { // returning an object to type car
        // object of type car will contain a brand and horespower member variables

        // We create a new Car object called result that will store the outcome of adding the two cars.
        Car result; 

        result.brand = this->brand + " & " + other.brand;
            // this->brand: refers to the brand of the calling object (left-hand side of the +).
            // other.brand: is the brand of the object on the right-hand side.
            // We concatenate both brands using " & " to show they're combined.

        // the above can also be written as:
        // result.brand = brand + " & " + other.brand;
        // checkout the == example

        result.horsepower = this->horsepower + other.horsepower;
            // Just adds the horsepower of both cars.
            // No string work here—just numeric addition.

        return result;
    }

    // Overload the '==' operator to compare two Car objects
    bool operator == (const Car& a) {
        return brand == a.brand && horsepower == a.horsepower;
    }

    void display() {
        cout << "Brand: " << brand << ", Horsepower: " << horsepower << endl;
    }

    // checkout friend functions below
    // Friend function to overload the '<<' operator for printing
    friend ostream& operator<<(ostream& out, const Car& car);
};

void exampleThree() {
    Car car1 = {"BMW", 300};
    Car car2 = {"Mercedes", 350};

    Car combinedCar = car1 + car2; // Using overloaded + operator
    // combinedCar.brand = "BMW & Mercedes";
    // combinedCar.horsePower = 650

    combinedCar.display();
    //  "Brand: BMW & Mercedes, Horsepower: 650";
}

// Why const Car& other?

    // const: Means we promise not to change the other object inside this function. 
    // This is important for safety and efficiency.

    // Car&: Passing by reference means we avoid copying the entire object (which could be costly). 
    // We just pass a reference to the existing object.

// So const Car& is best practice because
    // No copy overhead
    // Protects the passed object from accidental modification



// friend functions: Forgot to cover last time!
    // A friend function is a function that isn’t a member of a class, 
    // but it’s given special access to private and protected members of that class.

    // its like your bestfriend in a way
    // “Hey, you're not part of the family, but I trust you — come on in and use my private room and use my stuff.”

    // Why Do We Use Friend Functions?
    // Because sometimes you need a function to access private data without making it a member of the class.
    // ex:
        // Operator overloads
        // External helper functions
        // Functions that need to work with multiple classes at once (like comparing two objects from different classes)

        // Definition of the overloaded '<<' operator using a friend function
        // make sure to declare it in the class/struct (line 79)
        ostream& operator<<(ostream& out, const Car& car) {
            out << "Brand: " << car.brand << ", Horsepower: " << car.horsepower;
            return out;
        }

        void exampleFour(){
            Car car1  = {"NISSAN", 300};
            // The friend function allows us to output the brand and horsepower directly using cout like this:
            cout << car1;
            // "Brand: NISSAN, Horsepower: 300";
        }


    // why ostream&?
        // The << operator is used for output streaming. It takes an ostream object (like std::cout) and a Car object 
        // and streams the data to the output.

        // Since the << operator is usually chained, it must return the same ostream object that was passed to it so that multiple uses 
        // of << can be chained together. For example: cout << car1 << car2 << car3;

        // If operator<< didn't return the ostream&, you wouldn't be able to chain multiple << operations.
    
    // Recap of Potential Return Types for Operator Overloading:
        // void
        // T: The object type itself (Car).
        // T& or const T&: For operators that return a reference to the object.
        // ostream&: For output streaming (<< operator).
        // T* or const T*: For operators like -> (usually in smart pointers).
        // Other Primitive Types
