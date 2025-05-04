#include<iostream>
#include<memory> // For std::unique_ptr
using namespace std;

// Define a simple class
class Sample {
public:
    int x;
    Sample(int x = 0) : x(x) {
        cout << "Sample(" << x << ") constructed\n";
    }
    ~Sample() {
        cout << "Sample(" << x << ") destroyed\n";
    }
    void display() const {
        cout << "Value of x: " << x << "\n";
    }
};

// A function that returns a unique_ptr
unique_ptr<Sample> createSample(int val) {
    unique_ptr<Sample> ptr(new Sample(val)); // Dynamically allocate Sample
    ptr->x += 5; // Modify value before returning
    return ptr; // Return the smart pointer (moved automatically)
}

// A function that takes unique_ptr by reference and modifies the object
void incrementSample(unique_ptr<Sample>& uptr) {
    if (uptr) {
        uptr->x += 10;
    }
}

void unique_ptr_demo() {
    cout << "---- Step 1: Create a unique_ptr ----\n";
    unique_ptr<Sample> up1(new Sample(10)); // Create and own a new Sample object
    up1->display(); // Output: Value of x: 10

    cout << "\n---- Step 2: Transfer ownership using move ----\n";
    unique_ptr<Sample> up2 = move(up1); // Move ownership from up1 to up2
    if (!up1) {
        cout << "up1 is now null after move.\n";
    }
    up2->display(); // up2 now owns the object

    cout << "\n---- Step 3: Release ownership ----\n";
    Sample* raw_ptr = up2.release(); // Releases ownership and returns raw pointer
    if (!up2) {
        cout << "up2 is now null after release.\n";
    }
    raw_ptr->display(); // Still valid, but now manually managed

    delete raw_ptr; // Manually delete it now to avoid memory leak
    raw_ptr = nullptr; // Set to nullptr to avoid dangling pointer

    cout << "\n---- Step 4: Reset unique_ptr to a new object ----\n";
    up2.reset(new Sample(20)); // up2 now owns a new object
    up2->display();

    cout << "\n---- Step 5: Reset unique_ptr to nullptr ----\n";
    up2.reset(); // Deletes the owned object and becomes null
    if (!up2) {
        cout << "up2 is nullptr after reset.\n";
    }

    cout << "\n---- Step 6: Create unique_ptr via function ----\n";
    unique_ptr<Sample> up3 = createSample(30); // createSample returns a unique_ptr
    up3->display(); // Value will be 30+5 = 35

    cout << "\n---- Step 7: Modify unique_ptr object via function ----\n";
    incrementSample(up3); // Increments x by 10
    up3->display(); // Should print 45
}

int main() {
    unique_ptr_demo();
    return 0;
}

// DETAILED EXPLANATION:

// Step 1 | We create up1 that points to a Sample(10).
// Step 2 | We move(up1) into up2, transferring ownership. up1 becomes nullptr.
// Step 3 | We release() the pointer from up2, manually delete it (otherwise leak).
// Step 4 | We reset() up2 to manage a new Sample(20).
// Step 5 | We reset() up2 again, deleting Sample(20) automatically.
// Step 6 | We call a function that creates and returns a unique_ptr.
// Step 7 | We modify the object inside unique_ptr by passing it by reference.

// OUTPUT:

// ---- Step 1: Create a unique_ptr ----
// Sample(10) constructed
// Value of x: 10

// ---- Step 2: Transfer ownership using move ----
// up1 is now null after move.
// Value of x: 10

// ---- Step 3: Release ownership ----
// up2 is now null after release.
// Value of x: 10
// Sample(10) destroyed

// ---- Step 4: Reset unique_ptr to a new object ----
// Sample(20) constructed
// Value of x: 20

// ---- Step 5: Reset unique_ptr to nullptr ----
// Sample(20) destroyed
// up2 is nullptr after reset.

// ---- Step 6: Create unique_ptr via function ----
// Sample(30) constructed
// Value of x: 35

// ---- Step 7: Modify unique_ptr object via function ----
// Value of x: 45
// Sample(45) destroyed
