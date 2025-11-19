// Lesson 24: Priority Queues (PQ) - Fully Commented Version
// File: priority_queue.cpp

#include <iostream>
#include <vector>
using namespace std;

// What is a Priority Queue?
    // A Priority Queue (PQ) is an abstract data type that works like a normal queue,
    // but each element has a "priority". Elements with higher priority are served first.

// Types of PQs:
    // 1. Max Priority Queue: largest element has the highest priority (Max-Heap)
    // 2. Min Priority Queue: smallest element has the highest priority (Min-Heap)

// PQ Operations:
    // - push(value)  -> insert element into PQ (O(log n))
    // - pop()        -> remove the element with highest priority (O(log n))
    // - top()        -> get the element with highest priority without removing it (O(1))
    // - empty()      -> check if PQ is empty
    // - size()       -> number of elements in PQ


// Why use Heaps to implement PQ?
    // Heaps are complete binary trees that are efficient for PQs:
    // - Insert and remove operations are O(log n)
    // - Accessing top element is O(1)
    // - Array representation is memory and cache friendly

// ---------------------- Min Priority Queue ----------------------
class MinPQ {
private:
    vector<int> arr; // Array representation of the heap

    // Helper functions to calculate parent and children indices in array
    int parent(int i) { return (i - 1) / 2; } // integer division
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Bubble-up (aka sift-up) to maintain heap property after insertion
    void bubbleUp(int i) {
        // While not at root and current value is smaller than parent
        while (i > 0 && arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]); // swap with parent
            i = parent(i);                // move index up to parent
        }
    }

    // Bubble-down (aka sift-down) to maintain heap property after removal
    void bubbleDown(int i) {
        int n = arr.size();
        while (true) {
            int l = left(i);      // left child index
            int r = right(i);     // right child index
            int smallest = i;     // assume current node is smallest

            // Compare with left child
            if (l < n && arr[l] < arr[smallest]) smallest = l;
            // Compare with right child
            if (r < n && arr[r] < arr[smallest]) smallest = r;

            if (smallest != i) {
                swap(arr[i], arr[smallest]); // swap with smaller child
                i = smallest;                // move index down
            } else break; // heap property restored
        }
    }

public:
    MinPQ() {}

    // Check if the priority queue is empty
    bool empty() const { return arr.empty(); }
    
    // Return the number of elements
    int size() const { return arr.size(); }

    // Access the smallest element (highest priority)
    int top() const {
        if (arr.empty()) return -1; // fallback if empty
        return arr[0];              // root always has min value
    }

    // Insert new element into PQ
    void push(int value) {
        arr.push_back(value);           // insert at end
        bubbleUp(arr.size() - 1);       // restore heap property
    }

    // Remove element with highest priority (smallest value)
    void pop() {
        if (arr.empty()) return;

        arr[0] = arr.back();  // move last element to root
        arr.pop_back();       // remove last element
        if (!arr.empty()) bubbleDown(0); // restore heap property
    }

    // Build PQ from existing array in O(n)
    void buildPQ(const vector<int>& v) {
        arr = v;
        int start = (arr.size() - 2) / 2; // last non-leaf node
        for (int i = start; i >= 0; i--) bubbleDown(i);
    }
};


// ---------------------- Max Priority Queue ----------------------
class MaxPQ {
private:
    vector<int> arr;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Bubble-up for Max-Heap
    void bubbleUp(int i) {
        while (i > 0 && arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Bubble-down for Max-Heap
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
            } else break;
        }
    }

public:
    MaxPQ() {}

    bool empty() const { return arr.empty(); }
    int size() const { return arr.size(); }

    // Access the largest element (highest priority)
    int top() const {
        if (arr.empty()) return -1;
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

    void buildPQ(const vector<int>& v) {
        arr = v;
        int start = (arr.size() - 2) / 2;
        for (int i = start; i >= 0; i--) bubbleDown(i);
    }
};


// ---------------------- Example Usage ----------------------
int main() {
    cout << "=== Min Priority Queue Example ===\n";
    MinPQ minPQ;
    minPQ.push(20); // Insert 20
    minPQ.push(5);  // Insert 5
    minPQ.push(15); // Insert 15
    minPQ.push(3);  // Insert 3

    cout << "Min-PQ top: " << minPQ.top() << "\n"; // 3 (smallest)
    minPQ.pop(); // Remove 3
    cout << "After pop, top: " << minPQ.top() << "\n"; // 5

    cout << "\n=== Max Priority Queue Example ===\n";
    MaxPQ maxPQ;
    maxPQ.push(10);
    maxPQ.push(30);
    maxPQ.push(25);
    maxPQ.push(5);

    cout << "Max-PQ top: " << maxPQ.top() << "\n"; // 30 (largest)
    maxPQ.pop(); // Remove 30
    cout << "After pop, top: " << maxPQ.top() << "\n"; // 25

    cout << "\n=== Build PQ from Array ===\n";
    vector<int> data = {7, 2, 9, 1, 5};
    minPQ.buildPQ(data); // Efficiently build min-PQ from array
    cout << "Min-PQ after building from array:\n";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " "; // Print and remove each element
        minPQ.pop();
    }
    cout << "\n";

    return 0;
}
