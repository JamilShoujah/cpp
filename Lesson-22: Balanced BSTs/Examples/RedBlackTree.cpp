#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    Node* root;

    // Left rotation
    void rotateLeft(Node*& root, Node*& pt) {
        Node* pt_right = pt->right;
        pt->right = pt_right->left;
        if(pt->right) pt->right->parent = pt;

        pt_right->parent = pt->parent;
        if(!pt->parent) root = pt_right;
        else if(pt == pt->parent->left) pt->parent->left = pt_right;
        else pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    // Right rotation
    void rotateRight(Node*& root, Node*& pt) {
        Node* pt_left = pt->left;
        pt->left = pt_left->right;
        if(pt->left) pt->left->parent = pt;

        pt_left->parent = pt->parent;
        if(!pt->parent) root = pt_left;
        else if(pt == pt->parent->left) pt->parent->left = pt_left;
        else pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    // Fix violations after insertion
    void fixInsertRBTree(Node*& root, Node*& pt) {
        Node* parent_pt = nullptr;
        Node* grand_parent_pt = nullptr;

        while((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            // Parent is left child
            if(parent_pt == grand_parent_pt->left) {
                Node* uncle_pt = grand_parent_pt->right;

                // Case 1: Uncle is RED
                if(uncle_pt && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    // Case 2: pt is right child
                    if(pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    // Case 3: pt is left child
                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            } else { // Parent is right child
                Node* uncle_pt = grand_parent_pt->left;

                // Case 1: Uncle is RED
                if(uncle_pt && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    // Case 2: pt is left child
                    if(pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }
                    // Case 3: pt is right child
                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }
        root->color = BLACK; // Root is always black
    }

    // Inorder traversal
    void inorderHelper(Node* root) {
        if(!root) return;
        inorderHelper(root->left);
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
        inorderHelper(root->right);
    }

public:
    RBTree() { root = nullptr; }

    // Insert function
    void insert(const int& data) {
        Node* pt = new Node(data);
        Node* parent = nullptr;
        Node* curr = root;

        // Standard BST insertion
        while(curr) {
            parent = curr;
            if(pt->data < curr->data) curr = curr->left;
            else curr = curr->right;
        }

        pt->parent = parent;
        if(!parent) root = pt; // tree was empty
        else if(pt->data < parent->data) parent->left = pt;
        else parent->right = pt;

        // Fix violations
        fixInsertRBTree(root, pt);
    }

    // Inorder traversal
    void inorder() { inorderHelper(root); cout << endl; }

    // Search
    bool search(int val) {
        Node* curr = root;
        while(curr) {
            if(curr->data == val) return true;
            if(val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        return false;
    }
};

// --------------------- Main ---------------------
int main() {
    RBTree tree;
    int arr[] = {10, 20, 30, 15, 25, 5};
    for(int x : arr) tree.insert(x);

    cout << "Inorder traversal of Red-Black Tree: ";
    tree.inorder();

    cout << "Search 15: " << (tree.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}
