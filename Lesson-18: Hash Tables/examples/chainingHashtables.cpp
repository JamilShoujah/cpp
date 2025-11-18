#include <iostream>
#include <list>     // we use list for chaining
using namespace std;

//-------------------------------
// Define the Hash Table class
//-------------------------------
class HashTable {
private:
    // Number of buckets in the hash table
    static const int BUCKETS = 10;

    // Each bucket holds a list of pairs (key, value)
    list<pair<int, string>> table[BUCKETS];

    //-------------------------------
    // Hash function: maps key to bucket index
    //-------------------------------
    int hashFunction(int key) {
        return key % BUCKETS;  // simple modulo hash
    }

public:
    //-------------------------------
    // Insert a key-value pair
    //-------------------------------
    void insert(int key, string value) {
        int idx = hashFunction(key);  // find bucket
        // Check if key already exists in the bucket
        for (auto &p : table[idx]) {
            if (p.first == key) {
                p.second = value;  // update value
                return;
            }
        }
        // If key doesn't exist, add it to the bucket
        table[idx].push_back({key, value});
    }

    //-------------------------------
    // Search for a key
    //-------------------------------
    string get(int key) {
        int idx = hashFunction(key);
        for (auto &p : table[idx]) {
            if (p.first == key) {
                return p.second;  // key found
            }
        }
        return "Not Found"; // key not found
    }

    //-------------------------------
    // Remove a key-value pair
    //-------------------------------
    void remove(int key) {
        int idx = hashFunction(key);
        // Remove element with the matching key
        table[idx].remove_if([key](pair<int, string> &p) {
            return p.first == key;
        });
    }

    //-------------------------------
    // Display the hash table
    //-------------------------------
    void display() {
        for (int i = 0; i < BUCKETS; i++) {
            cout << "Bucket " << i << ": ";
            for (auto &p : table[i]) {
                cout << "(" << p.first << ", " << p.second << ") -> ";
            }
            cout << "NULL\n";
        }
    }
};

//-------------------------------
// Main function to test
//-------------------------------
int main() {
    HashTable ht;

    // Insert key-value pairs
    ht.insert(1, "Alice");
    ht.insert(11, "Bob");     // collision with key 1
    ht.insert(21, "Charlie"); // another collision in same bucket
    ht.insert(2, "David");

    cout << "Initial Hash Table:\n";
    ht.display();

    // Access elements
    cout << "\nValue for key 11: " << ht.get(11) << endl;
    cout << "Value for key 5: " << ht.get(5) << endl; // not found

    // Remove a key
    ht.remove(11);
    cout << "\nHash Table after removing key 11:\n";
    ht.display();

    return 0;
}
