// Lesson 22: Binary Search Trees

// Balanced BST Overview
    // A Balanced BST is a BST where the height is minimized to ensure operations like search, insert, delete stay O(log n).
    // Problem with plain BST: Skewed tree → O(n) operations.

    // Solution: Self-balancing trees.
    
    
    // Why Balance Matters
        // A BST allows fast search, insertion, and deletion only if the tree is roughly balanced.
            // Ideal scenario (perfectly balanced tree):
            // Height ≈ log₂(n)
            // → Search, insert, delete = O(log n)

        // Problem with unbalanced BST:
            // This is essentially a linked list
            // Operations degrade to O(n), losing the advantage of BSTs

        // example:
//         1
//          \
//           2
//            \
//             3
//              \
//               4
//                \
//                 5
//                  \
//                   6
//                    \
//                     7

// Self-Balancing BSTs
    // Self-balancing BSTs automatically reorganize themselves after insertions and deletions to maintain logarithmic height.
    // Two main types:
        // AVL Tree (height-balanced)
        // Red-Black Tree (color-based balancing)


// AVL Trees (Height-Balanced BST)
    // Concept:
        // Each node stores a height
        // Balance Factor (BF) = height(left) - height(right)
        // Invariant: BF ∈ {-1, 0, 1}

    // Rotations fix imbalance:

    // Case	                | Condition          	                                    | Fix
    // ---------------------------------------------------------------------------------------------------------------------------------------
    // Left-Left (LL)	    | Node inserted into left subtree of left child	            | Right rotation
    // Right-Right (RR)	    | Node inserted into right subtree of right child	        | Left rotation
    // Left-Right (LR)      | Node inserted into right subtree of left child	        | Left rotation on left child → Right rotation on node
    // Right-Left (RL)	    | Node inserted into left subtree of right child	        | Right rotation on right child → Left rotation on node



    // Pros:
        // Strictly balanced → very fast searches
        // Height ≈ 1.44 * log₂(n)

    // Cons:
        // More rotations on insertion/deletion than Red-Black
        // Slightly more complex to implement

    // CPP implementation:
        // Lesson-22: Balanced BSTs/Examples/AVLTree.cpp


// Red-Black Trees (Color-Balanced BST)
    // Concept:
        // Each node is either Red or Black
        // Rules to maintain balance:
            // - Root is black
            // - No two consecutive red nodes (Red parent → Red child prohibited)
            // - Every path from root → leaf has the same number of black nodes (black-height)
            // - Insertion and deletion may recolor nodes or perform rotations to maintain these rules
            
    // Pros:
        // Looser balance → fewer rotations on insert/delete
        // Height ≤ 2 * log₂(n+1) → still logarithmic
        // Widely used in real-world libraries (std::map, std::set)

    // Cons:
        // Slightly slower searches than AVL because the tree may be taller
        // Conceptually more complex (color rules + rotations)

    // CPP implementation:
        // Lesson-22: Balanced BSTs/Examples/RedBlackTree.cpp



// Comparing AVL vs Red-Black Trees
// Feature	            | AVL Tree                      | Red-Black Tree
// -------------------------------------------------------------------------------
// Balance Criterion	| Height difference ≤ 1	        | Color-based rules (looser balance)
// Height	            | Strictly ≤ 1.44*log₂(n)	    | ≤ 2*log₂(n+1)
// Search Efficiency	| Very fast	                    | Slightly slower
// Insertion/Deletion	| More rotations	            | Fewer rotations
// Use Cases	        | Read-heavy (lots of searches)	| Write-heavy (frequent insert/delete)

// Rule of Thumb:
    // AVL → optimal for static datasets (rare insertions)
    // Red-Black → optimal for dynamic datasets (frequent insertions/deletions)


// Visual Intuition
    // AVL tree: Always tries to keep perfect balance; rotations happen often to maintain height.
    // Red-Black tree: Tolerates some imbalance but guarantees logarithmic height using coloring rules.


// TLDR:
    // Balanced BSTs = guarantee of O(log n) operations
    // AVL = strict height balance → fast search, more rotations
    // Red-Black = color balance → slightly taller, fewer rotations
    // Key concept for students: balancing ensures the BST doesn’t degenerate into a linked list

