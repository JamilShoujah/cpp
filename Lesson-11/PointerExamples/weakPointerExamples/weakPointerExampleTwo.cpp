#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    shared_ptr<Node> connectedNode;  // Shared pointer to the connected node
    weak_ptr<Node> backReference;    // Weak pointer to break the circular reference

    Node(int val) : data(val) {
        cout << "Node(" << data << ") constructed\n";
    }

    ~Node() {
        cout << "Node(" << data << ") destructed\n";
    }
};

void weakPtrDemo() {
    // Create two nodes
    shared_ptr<Node> node1 = make_shared<Node>(1);
    shared_ptr<Node> node2 = make_shared<Node>(2);

    // Create one-way connection using shared_ptr
    node1->connectedNode = node2;

    // Create back reference using weak_ptr to avoid circular reference
    node2->backReference = node1;

    // Show the use_count for both nodes
    cout << "node1 use_count: " << node1.use_count() << endl;  // Should be 1 // 1 shared 1 weak
    cout << "node2 use_count: " << node2.use_count() << endl;  // Should be 2 // 2 shared
    cout << "node1->connectedNode use_count: " << node1->connectedNode.use_count() << endl; // Should be 2
    cout << "node2->backReference use_count: " << node2->backReference.use_count() << endl; // Should be 1
    cout << "node2->backReference use_count: " << node2->backReference.lock().use_count() << endl; // Should be 2

    // At this point, only node1 is kept alive because node2 is now referencing node1 weakly
}

int main() {
    weakPtrDemo();
    return 0;
}

// OUTPUT:

// Node(1) constructed
// Node(2) constructed
// node1 use_count: 1
// node2 use_count: 2
// node1->connectedNode use_count: 2
// node2->backReference use_count: 2
// Node(1) destructed
// Node(2) destructed
