// Lesson 20: Binary Trees
#include <iostream>
#include <queue>

using namespace std;


// What is a Binary Tree?
    // A binary tree is a special type of tree where each node has at most two children:
        // Left child
        // Right child

// Example

//        10
//       /  \
//      5    20
//     / \   / 
//    3   7 15  

// Root: 10
// Left child of 10: 5
// Right child of 10: 20
// Leaf nodes: 3, 7, 15


// Types of Binary Trees
    // Full Binary Tree	    --> Each node has 0 or 2 children	
    // Perfect Binary Tree	--> Full binary tree + all leaf nodes at same level	
    // Complete Binary Tree	--> All levels filled except possibly the last, filled left to right	
    // Skewed Binary Tree	--> Each node has only one child (left or right)


//  Binary Tree Representation in C++   
//  Node structure for binary tree

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

int main() {
    // Create nodes
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);

    cout << "Root: " << root->data << endl;
    cout << "Left child of root: " << root->left->data << endl;
    cout << "Right child of root: " << root->right->data << endl;

    return 0;
}


// Binary Tree Traversals

    // Preorder (Root → Left → Right)
        void preorder(Node* root) {
            if(!root) return;
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
        // Example Output: 10 5 3 7 20 15

    // Inorder (Left → Root → Right)
        void inorder(Node* root) {
            if(!root) return;
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
        // Example Output: 3 5 7 10 15 20

    // Postorder (Left → Right → Root)
        void postorder(Node* root) {
            if(!root) return;
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }

        // Example Output: 3 7 5 15 20 10

    // Level-order / BFS 
        void levelOrder(Node* root) {
            if(!root) return;
            queue<Node*> q;
            q.push(root);

            while(!q.empty()) {
                Node* curr = q.front();
                q.pop();
                cout << curr->data << " ";

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        // Example Output: 10 5 20 3 7 15

// Binary Tree Applications
    // Expression Trees: Evaluate arithmetic expressions.
    // Heaps: Binary heap is a complete binary tree.
    // Binary Search Trees (BST): Efficient search, insertion, deletion.
    // Game Trees: Chess, tic-tac-toe AI.
    // Huffman Trees: Data compression algorithms.