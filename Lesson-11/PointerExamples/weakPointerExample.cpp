#include <iostream>
#include <memory>

class Manager {
public:
    Manager(const std::string& name) : name_(name) {
        std::cout << "Manager " << name_ << " created." << std::endl;
    }
    ~Manager() {
        std::cout << "Manager " << name_ << " destroyed." << std::endl;
    }

    void assignTask() const {
        std::cout << "Assigning task by Manager " << name_ << std::endl;
    }

private:
    std::string name_;
};

void weakPtrExample() {
    std::shared_ptr<Manager> manager1 = std::make_shared<Manager>("Alice");
    
    // Create a weak_ptr to observe the manager1
    std::weak_ptr<Manager> weakManager = manager1;
    
    std::cout << "Use count before lock: " << manager1.use_count() << std::endl;
    
    if (auto lockedManager = weakManager.lock()) {  // Convert weak_ptr to shared_ptr if object is still alive
        lockedManager->assignTask();
    } else {
        std::cout << "Manager object has been deleted." << std::endl;
    }

    // manager1 goes out of scope and is destroyed
    std::cout << "Use count after manager1 is destroyed: " << weakManager.lock().use_count() << std::endl;
}

int main() {
    weakPtrExample();
    return 0;
}

// Output:
// Manager Alice created.
// Use count before lock: 1
// Assigning task by Manager Alice
// Manager Alice destroyed.
// Use count after manager1 is destroyed: 0
