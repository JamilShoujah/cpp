// Lesson 23: Heaps

#include <iostream>
#include <vector>
using namespace std;

// What are heaps?
    // A heap is a complete binary tree (every level filled left-to-right)
    // We have two types of heaps:
        // Min Heaps: Each parent ≤ its children 
        // Max Heaps: each parent ≥ its children

        // [Note] yes children and parents may be equal

        // in other words, in min heaps the minimum element is always at the root
        // in max heaps, the max element is at the root

    // Heaps are used for:
        // Priority queues
        // Dijkstra’s algorithm
        // Event simulation
        // Median maintenance
        // Scheduling tasks

// Array Representation
    // We never actually store heaps as node pointers.
    // We store them in a simple vector

    // Why Arrays Work Perfectly for Heaps
        // because a heap’s structure is so regular that pointers become useless overhead.
        // A heap is:
            // Always complete
            // Always filled left to right
            // Has no missing nodes except possibly the last level

        // This makes it possible to compute:
            // the parent
            // the left child
            // the right child
        // just using index arithmetic.

    // The Index Formulas (The Heart of Array-Heaps)

        // parent(i) = (i - 1) / 2       // integer division
        // left(i)   = 2*i + 1
        // right(i)  = 2*i + 2

        // These three formulas define the entire heap.
        // This is why heaps don’t need node structs.
    
    // Visualizing the Array–Tree Mapping
        // index:  0   1   2   3   4   5   6
        // value: 10  20  30  40  50  60  70

        // The tree representation is:
        //             (0)10
        //         /              \
        //     (1)20            (2)30
        //     /     \          /      \
        // (3)40   (4)50   (5)60    (6)70

        // 20 is left child of 10 → index 1 = 2*0 + 1
        // 30 is right child of 10 → index 2 = 2*0 + 2
        // 40 is left child of 20 → index 3 = 2*1 + 1
        // … and so on.

        // Example: Finding Parent of Node at Index i
            // Let’s say you're at index 5 (value: 60).
                // parent = (5 - 1) / 2 = 4 / 2 = 2
                // The parent of 60 (index 5) is 30 (index 2)

        // Example: Finding Children of Node at Index i
            // If you're at index 2 (30):
                // left  = 2*2 + 1 = 5
                // right = 2*2 + 2 = 6

                // left child → index 5 → 60
                // right child → index 6 → 70

        // Why This Makes Heaps Efficient
            // Arrays sit in contiguous memory → CPU caches entire chunks → faster access.
            // No pointer dereferencing → just math. (O(1) child/parent lookup)
            // Memory efficiency
            // Easy to resize


    // Core Heap Operations
        // Insert (push) O(log n)
            // Steps:
                // Add element to the end of array
                // “Bubble-up” while heap property is violated

        // Remove Root (pop) O(log n)
            // Steps:
                // Replace root with last element
                // Remove last element
                // “Heapify down” to restore heap property

        // Peek O(1)
            // Just return A[0].

        // Heapify O(n)
            // restore heap property starting from a node going DOWNWARD.
            // Used when:
                // You remove the root
                // You build a heap from an array

// Min-Heap Implementation
class MinHeap {
private:
    vector<int> arr;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Move element up until heap property is restored
    void bubbleUp(int i) {
        while (i > 0 && arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Move element down until heap property is restored
    void bubbleDown(int i) {
        int n = arr.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if (l < n && arr[l] < arr[smallest]) smallest = l;
            if (r < n && arr[r] < arr[smallest]) smallest = r;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else break;
        }
    }

public:
    MinHeap() {}

    bool empty() const { return arr.empty(); }
    int size() const { return arr.size(); }

    int top() const {
        if (arr.empty()) return -1; // fallback if empty
        return arr[0];
    }

    void push(int value) {
        arr.push_back(value);
        bubbleUp(arr.size() - 1);
    }

    void pop() {
        if (arr.empty()) return;

        arr[0] = arr.back();
        arr.pop_back();
        if (!arr.empty()) bubbleDown(0);
    }

    void clear() { arr.clear(); }

    // Build heap from a vector
    // Heapify
    void buildHeap(const vector<int>& v) {
        arr = v;
        int start = (arr.size() - 2) / 2; // last non-leaf
        for (int i = start; i >= 0; i--) {
            bubbleDown(i);
        }
    }
};

// ----------------- Example usage ------------------
void minHeapMain() {
    MinHeap h;

    vector<int> data = {7, 2, 5, 1, 9, 3};
    h.buildHeap(data);

    cout << "Heap elements popped in ascending order:\n";
    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << "\n";

    // Demonstrate push/pop
    MinHeap hx;
    hx.push(20);
    hx.push(4);
    hx.push(15);
    hx.push(1);

    cout << "Current min: " << hx.top() << "\n"; // 1
    hx.pop();
    cout << "After pop, min: " << hx.top() << "\n"; // 4
}


// Max-Heap Version Only difference: flip comparisons.
    // if (heap[index] > heap[parent])
    // if (left < size && heap[left] > heap[largest])

class MaxHeap {
private:
    vector<int> arr;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Move element up until heap property is restored
    void bubbleUp(int i) {
        while (i > 0 && arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Move element down until heap property is restored
    void bubbleDown(int i) {
        int n = arr.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            if (l < n && arr[l] > arr[largest]) largest = l;
            if (r < n && arr[r] > arr[largest]) largest = r;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap() {}

    bool empty() const { return arr.empty(); }
    int size() const { return arr.size(); }

    // Get the maximum element
    int top() const {
        if (arr.empty()) return -1; // simple fallback, no exceptions
        return arr[0];
    }

    // Insert a new value
    void push(int value) {
        arr.push_back(value);
        bubbleUp(arr.size() - 1);
    }

    // Remove the maximum element
    void pop() {
        if (arr.empty()) return;

        arr[0] = arr.back();
        arr.pop_back();
        if (!arr.empty()) bubbleDown(0);
    }

    // Build heap from a vector
    // Heapify
    void buildHeap(const vector<int>& v) {
        arr = v;
        int start = (arr.size() - 2) / 2; // last non-leaf
        for (int i = start; i >= 0; i--) {
            bubbleDown(i);
        }
    }
};

// ----------------- Example usage ------------------
void minHeapMain() {
    MaxHeap h;

    h.push(10);
    h.push(3);
    h.push(25);
    h.push(8);

    cout << "Max = " << h.top() << endl; // 25

    h.pop(); // remove 25

    cout << "New Max = " << h.top() << endl; // 10
}


// HEAP SORT
    // Heap Sort is a comparison-based sorting algorithm that uses the heap data structure to sort elements efficiently.
    // It’s an in-place sorting algorithm with O(n log n) time complexity and is not stable (doesn’t preserve relative order of equal elements). 

    // The idea behind Heap Sort:
        // 1- Build a max-heap from the input array.
            // The largest element is now at the root (index 0).
        // 2- Swap the root with the last element in the heap.
            // Now the largest element is at the end of the array (its final sorted position).
        // 3- Reduce heap size by 1 (ignore last element).
        // 4- Heapify the root to restore the heap property.
        // 5- Repeat steps 2–4 until the heap size is 1.

        // Result: Array sorted in ascending order.
        // (For descending order, use a min-heap instead.)

        // Lesson-23: Heaps/example.cpp/heapSort.cpp

    // Operation	Time Complexity
    //     Building heap	O(n)
    //     Heapify (per pop)	O(log n)
    //     Total Heap Sort	O(n log n)

    //     Space complexity: O(1) in-place (no extra arrays)

    //     Stable? No (heap swaps may reorder equal elements)
