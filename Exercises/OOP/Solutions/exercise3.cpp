#include <iostream>
#include <string>
using namespace std;

// Abstract class Employee
class Employee {
protected:
    string name;

public:
    Employee(string n) : name(n) {}

    virtual double calculateSalary() const = 0;  // Pure virtual function

    void display() const {
        cout << "Employee: " << name << ", Salary: " << calculateSalary() << endl;
    }
};

// Derived class FullTimeEmployee
class FullTimeEmployee : public Employee {
private:
    double salary;

public:
    FullTimeEmployee(string n, double s) : Employee(n), salary(s) {}

    double calculateSalary() const override {
        return salary;
    }
};

// Derived class PartTimeEmployee
class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(string n, double rate, int hours) : Employee(n), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    FullTimeEmployee fullTimeEmp("Alice", 5000);
    PartTimeEmployee partTimeEmp("Bob", 20, 80);

    fullTimeEmp.display();
    partTimeEmp.display();

    return 0;
}

// Explanation:

// Abstraction: We have an abstract class Employee with the pure virtual function calculateSalary(). 
// The implementation of this function is deferred to the derived classes.

// Polymorphism: The calculateSalary() method is called polymorphically, allowing us to use both FullTimeEmployee 
// and PartTimeEmployee objects through an Employee pointer or reference.