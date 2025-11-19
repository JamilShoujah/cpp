#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // recursively heapify affected subtree
    }
}

// Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build max-heap
    for (int i = (n - 2) / 2; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);    // Move current root to end
        heapify(arr, i, 0);      // Heapify reduced heap
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    heapSort(arr);

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}

// Output
// Original array: 4 10 3 5 1 
// Sorted array:   1 3 4 5 10

