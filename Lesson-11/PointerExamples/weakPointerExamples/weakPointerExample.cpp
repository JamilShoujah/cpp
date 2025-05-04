#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    shared_ptr<Node> connectedNode; // This is a shared pointer to the connected node.

    Node(int val) : data(val) {
        cout << "Node(" << data << ") constructed\n";
    }

    ~Node() {
        cout << "Node(" << data << ") destructed\n";
    }
};

void circularReferenceDemo() {
    // Create two nodes
    shared_ptr<Node> node1 = make_shared<Node>(1);
    shared_ptr<Node> node2 = make_shared<Node>(2);

    // Create circular reference: node1 points to node2, and node2 points back to node1
    node1->connectedNode = node2;
    node2->connectedNode = node1;

    // Show the use_count for both nodes (should be 2 for each, because of the circular reference)
    cout << "node1 use_count: " << node1.use_count() << endl;  // Should be 2
    cout << "node2 use_count: " << node2.use_count() << endl;  // Should be 2
    cout << "node1->connectedNode use_count: " << node1->connectedNode.use_count() << endl; // Should be 2
    cout << "node2->connectedNode use_count: " << node2->connectedNode.use_count() << endl; // Should be 2

    // At this point, neither node will be deleted, and we have a memory leak
}

int main() {
    circularReferenceDemo();
    return 0;
}

// OUTPUT:

// Node(1) constructed
// Node(2) constructed
// node1 use_count: 2
// node2 use_count: 2
// node1->connectedNode use_count: 2
// node2->connectedNode use_count: 2