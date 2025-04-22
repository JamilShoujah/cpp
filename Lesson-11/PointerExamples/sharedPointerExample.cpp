#include <iostream>
#include <memory>

class Engine {
public:
    Engine(const std::string& type) : type_(type) {
        std::cout << "Engine of type " << type_ << " created." << std::endl;
    }
    ~Engine() {
        std::cout << "Engine of type " << type_ << " destroyed." << std::endl;
    }

    void start() const {
        std::cout << "Starting the " << type_ << " engine." << std::endl;
    }

private:
    std::string type_;
};

void sharedPtrExample() {
    // Create a shared_ptr that manages an Engine object
    std::shared_ptr<Engine> engine1 = std::make_shared<Engine>("V8");
    engine1->start();

    // Create another shared_ptr that shares ownership
    std::shared_ptr<Engine> engine2 = engine1;
    engine2->start();

    std::cout << "Use count: " << engine1.use_count() << std::endl;  // Shows the number of shared_ptrs
}

int main() {
    sharedPtrExample();
    // No need to explicitly delete, the Engine object will be destroyed when the last shared_ptr is out of scope
    return 0;
}

// output:
// Engine of type V8 created.
// Starting the V8 engine.
// Starting the V8 engine.
// Use count: 2
// Engine of type V8 destroyed.

