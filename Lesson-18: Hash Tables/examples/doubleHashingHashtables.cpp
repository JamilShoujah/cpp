#include <iostream>
using namespace std;

//-------------------------------
// Hash Table with Double Hashing
//-------------------------------
class HashTable {
private:
    static const int TABLE_SIZE = 11;  // number of buckets
    int keys[TABLE_SIZE];
    string values[TABLE_SIZE];
    bool deleted[TABLE_SIZE];

    // Secondary hash function constant (prime < TABLE_SIZE)
    static const int R = 7;

public:
    HashTable() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            keys[i] = -1;       // -1 = empty slot
            values[i] = "";
            deleted[i] = false; // not deleted
        }
    }

    //-------------------------------
    // Primary hash function
    //-------------------------------
    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    //-------------------------------
    // Secondary hash function
    //-------------------------------
    int hash2(int key) {
        return R - (key % R);
    }

    //-------------------------------
    // Insert using Double Hashing
    //-------------------------------
    void insert(int key, string value) {
        int idx = hash1(key);
        int step = hash2(key);
        int i = 0;

        while(keys[idx] != -1 && keys[idx] != key) {
            i++;
            idx = (hash1(key) + i * step) % TABLE_SIZE;
            if(i == TABLE_SIZE) { // table full
                cout << "Hash table full! Cannot insert key " << key << endl;
                return;
            }
        }

        keys[idx] = key;
        values[idx] = value;
        deleted[idx] = false;
    }

    //-------------------------------
    // Search using Double Hashing
    //-------------------------------
    string get(int key) {
        int idx = hash1(key);
        int step = hash2(key);
        int i = 0;

        while(keys[idx] != -1 || deleted[idx]) {
            if(keys[idx] == key && !deleted[idx])
                return values[idx];

            i++;
            idx = (hash1(key) + i * step) % TABLE_SIZE;
            if(i == TABLE_SIZE) break;
        }

        return "Not Found";
    }

    //-------------------------------
    // Remove key
    //-------------------------------
    void remove(int key) {
        int idx = hash1(key);
        int step = hash2(key);
        int i = 0;

        while(keys[idx] != -1 || deleted[idx]) {
            if(keys[idx] == key && !deleted[idx]) {
                deleted[idx] = true; // mark as deleted
                return;
            }

            i++;
            idx = (hash1(key) + i * step) % TABLE_SIZE;
            if(i == TABLE_SIZE) break;
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
    ht.insert(12, "Bob");    // collision with key 1
    ht.insert(23, "Charlie"); // collision again
    ht.insert(2, "David");

    cout << "Initial Hash Table:\n";
    ht.display();

    // Search
    cout << "\nValue for key 12: " << ht.get(12) << endl;
    cout << "Value for key 5: " << ht.get(5) << endl; // not found

    // Remove
    ht.remove(12);
    cout << "\nHash Table after removing key 12:\n";
    ht.display();

    return 0;
}
