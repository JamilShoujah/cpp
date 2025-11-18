#include <iostream>
using namespace std;

// --------------------- AVL Node Structure ---------------------
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height; // height of the node

    AVLNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1; // new node is initially a leaf
    }
};

// --------------------- Utility Functions ---------------------

// Get height of node
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

// Get balance factor of node (left height - right height)
int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right rotation (for Left-Left imbalance)
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x; // new root
}

// Left rotation (for Right-Right imbalance)
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y; // new root
}

// --------------------- AVL Insertion ---------------------
AVLNode* insert(AVLNode* node, int val) {
    if(node == nullptr) return new AVLNode(val);

    // Normal BST insertion
    if(val < node->data)
        node->left = insert(node->left, val);
    else if(val > node->data)
        node->right = insert(node->right, val);
    else
        return node; // duplicates not allowed

    // Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor to check whether node became unbalanced
    int balance = getBalance(node);

    // ----------------- Balancing Cases -----------------

    // Left Left Case
    if(balance > 1 && val < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if(balance < -1 && val > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if(balance > 1 && val > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if(balance < -1 && val < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // return the (unchanged) node pointer
}

// --------------------- AVL Node Deletion ---------------------

// Find node with minimum value in subtree
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while(current->left != nullptr) current = current->left;
    return current;
}

AVLNode* deleteNode(AVLNode* root, int key) {
    if(root == nullptr) return root;

    // Standard BST deletion
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if(root->left == nullptr || root->right == nullptr) {
            AVLNode* temp = root->left ? root->left : root->right;
            if(temp == nullptr) {
                // No child
                temp = root;
                root = nullptr;
            } else {
                // One child
                *root = *temp;
            }
            delete temp;
        } else {
            // Node with two children
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If tree had only one node
    if(root == nullptr) return root;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check balance
    int balance = getBalance(root);

    // ----------------- Balancing Cases -----------------

    // Left Left Case
    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if(balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if(balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// --------------------- AVL Search ---------------------
bool search(AVLNode* root, int val) {
    if(!root) return false;
    if(root->data == val) return true;
    if(val < root->data) return search(root->left, val);
    return search(root->right, val);
}

// --------------------- Traversals ---------------------
void inorder(AVLNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(AVLNode* root) {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(AVLNode* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// --------------------- Main Function ---------------------
int main() {
    AVLNode* root = nullptr;

    // Insert nodes
    int arr[] = {10, 20, 30, 40, 50, 25};
    for(int x : arr) root = insert(root, x);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal of AVL tree: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal of AVL tree: ";
    postorder(root);
    cout << endl;

    // Search
    cout << "Search 25: " << (search(root, 25) ? "Found" : "Not Found") << endl;
    cout << "Search 60: " << (search(root, 60) ? "Found" : "Not Found") << endl;

    // Delete nodes
    root = deleteNode(root, 20);
    cout << "Inorder after deleting 20: ";
    inorder(root);
    cout << endl;

    return 0;
}
