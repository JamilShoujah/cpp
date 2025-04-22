#include <iostream>
#include <memory>

class Car {
public:
    Car(const std::string& model) : model_(model) {
        std::cout << "Car " << model_ << " created." << std::endl;
    }
    ~Car() {
        std::cout << "Car " << model_ << " destroyed." << std::endl;
    }

    void drive() const {
        std::cout << "Driving " << model_ << std::endl;
    }

private:
    std::string model_;
};

void uniquePtrExample() {
    // Create a unique_ptr that manages a Car object
    std::unique_ptr<Car> car1 = std::make_unique<Car>("Tesla");
    car1->drive();  // Access the Car object

    // Transferring ownership to car2 using move semantics
    std::unique_ptr<Car> car2 = std::move(car1);
    
    // car1 is now null, and car2 owns the object
    if (!car1) {
        std::cout << "car1 is null after move." << std::endl;
    }

    car2->drive();  // Access the Car object
}

int main() {
    uniquePtrExample();
    // No need to explicitly delete, car2 goes out of scope and the memory is freed
    return 0;
}

// Output:
    // Car Tesla created.
    // Driving Tesla
    // car1 is null after move.
    // Driving Tesla
    // Car Tesla destroyed.
