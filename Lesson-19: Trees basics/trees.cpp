// Lesson 19: Basic Trees
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// What is a tree?
    // A tree is a hierarchical data structure.
    // Each element is called a node, which can have children.
    // One node is the root (top of the tree).

// Tree Terminology
    // Node     ->  Basic element of the tree
    // Root     ->  Topmost node
    // Parent   ->	Node with children
    // Child    ->	Node below a parent
    // Leaf	    ->  Node with no children
    // Subtree  ->	A tree formed by a node and its descendants
    // Depth    ->	Distance from root
    // Height   ->	Longest path from node to leaf

// Tip: Depth counts from root (root depth = 0). Height counts edges downward (leaf height = 0).

// : General Tree Example

    //       A
    //    /  |  \
    //   B   C   D
    //      / \
    //     E   F

    // A: root
    // B, C, D: children of A
    // E, F: children of C
    // B, D, E, F: leaf nodes

// Tree Representation in C++ Using pointers

struct TreeNode {
    string data;
    vector<TreeNode*> children; // general tree can have multiple children

    TreeNode(string val) {
        data = val;
    }
};

int main() {
    // Creating nodes
    TreeNode* root = new TreeNode("A");
    TreeNode* B = new TreeNode("B");
    TreeNode* C = new TreeNode("C");
    TreeNode* D = new TreeNode("D");
    TreeNode* E = new TreeNode("E");
    TreeNode* F = new TreeNode("F");

    // Building tree
    root->children.push_back(B);
    root->children.push_back(C);
    root->children.push_back(D);
    C->children.push_back(E);
    C->children.push_back(F);

    cout << "Root: " << root->data << endl;
    cout << "Child of C: " << C->children[0]->data << ", " << C->children[1]->data << endl;

    return 0;
}

// Tree Traversals
    // Traversal = visiting all nodes in some order.

    // * Preorder Traversal (Root → Children)
        void preorder(TreeNode* root) {
            if(!root) return;
            cout << root->data << " ";
            for(auto child : root->children) {
                preorder(child);
            }
        }

        // Output Example: A B C E F D

    // * Postorder Traversal (Children → Root)
        void postorder(TreeNode* root) {
            if(!root) return;
            for(auto child : root->children) {
                postorder(child);
            }
            cout << root->data << " ";
        }

        // Output Example: B E F C D A


    // * Level-order (BFS)
    void levelOrder(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            for(auto child : curr->children) q.push(child);
        }
    }

    // Output Example: A B C D E F