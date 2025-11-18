#include <iostream>
using namespace std;

//-------------------------------
// Hash Table with Open Addressing (Linear Probing)
//-------------------------------
class HashTable {
private:
    static const int TABLE_SIZE = 10;

    // Array to store keys and values
    int keys[TABLE_SIZE];
    string values[TABLE_SIZE];

    // Special marker for deleted keys
    bool deleted[TABLE_SIZE];

public:
    // Constructor
    HashTable() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            keys[i] = -1;       // -1 indicates empty slot
            values[i] = "";
            deleted[i] = false; // false = not deleted
        }
    }

    //-------------------------------
    // Hash function
    //-------------------------------
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    //-------------------------------
    // Insert a key-value pair
    //-------------------------------
    void insert(int key, string value) {
        int idx = hashFunction(key);
        int startIdx = idx; // remember where we started

        while(keys[idx] != -1 && keys[idx] != key) {
            idx = (idx + 1) % TABLE_SIZE; // linear probing
            if(idx == startIdx) {
                cout << "Hash table full! Cannot insert key " << key << endl;
                return;
            }
        }

        keys[idx] = key;
        values[idx] = value;
        deleted[idx] = false;
    }

    //-------------------------------
    // Search for a key
    //-------------------------------
    string get(int key) {
        int idx = hashFunction(key);
        int startIdx = idx;

        while(keys[idx] != -1 || deleted[idx]) {
            if(keys[idx] == key && !deleted[idx])
                return values[idx];

            idx = (idx + 1) % TABLE_SIZE;
            if(idx == startIdx) break; // we circled the table
        }
        return "Not Found";
    }

    //-------------------------------
    // Remove a key
    //-------------------------------
    void remove(int key) {
        int idx = hashFunction(key);
        int startIdx = idx;

        while(keys[idx] != -1 || deleted[idx]) {
            if(keys[idx] == key && !deleted[idx]) {
                deleted[idx] = true; // mark as deleted
                return;
            }

            idx = (idx + 1) % TABLE_SIZE;
            if(idx == startIdx) break; // circled the table
        }
        cout << "Key " << key << " not found.\n";
    }

    //-------------------------------
    // Display table
    //-------------------------------
    void display() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            if(keys[i] != -1 && !deleted[i])
                cout << i << " -> (" << keys[i] << ", " << values[i] << ")\n";
            else
                cout << i << " -> NULL\n";
        }
    }
};

//-------------------------------
// Main function to test
//-------------------------------
int main() {
    HashTable ht;

    // Insert keys
    ht.insert(1, "Alice");
    ht.insert(11, "Bob");      // collision with key 1
    ht.insert(21, "Charlie");  // collision again
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
