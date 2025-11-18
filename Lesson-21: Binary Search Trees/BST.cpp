// Lesson 21: Binary Search Trees
#include <iostream>
using namespace std;

// What is a binary search Tree?
    // A BST is a binary tree with a special ordering property:
        // For any node N:
        // - All nodes in N's left subtree < N
        // - All nodes in N's right subtree > N

    // This property allows efficient search, insertion, and deletion. 

    // Example BST:

    //     10
    //    /  \
    //   5    20
    //  / \   / \
    // 3   7 15 25


    // Why BSTs Are Useful
        // Operation |  Normal Binary Tree  | BST (Average Case)
        // Search	 |  O(n)	            | O(log n)
        // Insert	 |  O(n)           	    | O(log n)
        // Delete	 |  O(n)	            | O(log n)

    // Why faster? Because the BST property reduces the search space at each step.

// BST Implementation in C++

// --------------------- BST Node ---------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// --------------------- BST Functions ---------------------

// Insert a new node
// Recursively finds the correct spot to maintain BST property.
Node* insert(Node* root, int val) {
    if(root == nullptr) return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Search for a value
// Efficient because you skip half the tree at each step.
bool search(Node* root, int val) {
    if(root == nullptr) return false;
    if(root->data == val) return true;

    if(val < root->data) return search(root->left, val);
    return search(root->right, val);
}

// Find the node with minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while(current && current->left != nullptr)
        current = current->left;
    return current;
}

// Delete a node
// Deleting a node has 3 cases:
    // Node has no child → delete directly.
    // Node has one child → replace node with child.
    // Node has two children → replace node with inorder successor (smallest in right subtree).

Node* deleteNode(Node* root, int key) {
    if(root == nullptr) return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// --------------------- Traversals ---------------------

// Traversals are same as binary trees, but inorder traversal produces sorted output.

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// --------------------- Height ---------------------
int height(Node* root) {
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// --------------------- Min & Max ---------------------
int findMin(Node* root) {
    Node* current = root;
    while(current->left) current = current->left;
    return current->data;
}

int findMax(Node* root) {
    Node* current = root;
    while(current->right) current = current->right;
    return current->data;
}

// --------------------- Main ---------------------
int main() {
    Node* root = nullptr;

    // Insert values
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    cout << "Inorder traversal: ";
    inorder(root); // Should print sorted order
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Search 12: " << (search(root, 12) ? "Found" : "Not Found") << endl;
    cout << "Search 19: " << (search(root, 19) ? "Found" : "Not Found") << endl;

    cout << "Height of BST: " << height(root) << endl;
    cout << "Minimum value: " << findMin(root) << endl;
    cout << "Maximum value: " << findMax(root) << endl;

    // Delete a node
    root = deleteNode(root, 10);
    cout << "Inorder after deleting 10: ";
    inorder(root);
    cout << endl;

    return 0;
}

// BST Applications
    // Efficient search: Dictionary, contact list.
    // Set / Map structures: STL set / map often use BSTs (Red-Black trees).
    // Range queries: Find values within a range.
    // Autocomplete / suggestions: When combined with tree variants.