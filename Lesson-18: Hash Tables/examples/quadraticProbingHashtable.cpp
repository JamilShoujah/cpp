#include <iostream>
using namespace std;

//-------------------------------
// Hash Table with Quadratic Probing
//-------------------------------
class HashTable {
private:
    static const int TABLE_SIZE = 11; // better to use a prime number
    int keys[TABLE_SIZE];
    string values[TABLE_SIZE];
    bool deleted[TABLE_SIZE];

public:
    HashTable() {
        for(int i = 0; i < TABLE_SIZE; i++) {
            keys[i] = -1;        // -1 = empty slot
            values[i] = "";
            deleted[i] = false;  // false = not deleted
        }
    }

    //-------------------------------
    // Hash function
    //-------------------------------
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    //-------------------------------
    // Insert using Quadratic Probing
    //-------------------------------
    void insert(int key, string value) {
        int idx = hashFunction(key);
        int i = 0; // collision counter

        while(keys[idx] != -1 && keys[idx] != key) {
            i++;
            idx = (hashFunction(key) + i*i) % TABLE_SIZE; // quadratic probing
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
    // Search using Quadratic Probing
    //-------------------------------
    string get(int key) {
        int idx = hashFunction(key);
        int i = 0;

        while(keys[idx] != -1 || deleted[idx]) {
            if(keys[idx] == key && !deleted[idx])
                return values[idx];

            i++;
            idx = (hashFunction(key) + i*i) % TABLE_SIZE;
            if(i == TABLE_SIZE) break; // circled table
        }

        return "Not Found";
    }

    //-------------------------------
    // Remove key (mark as deleted)
    //-------------------------------
    void remove(int key) {
        int idx = hashFunction(key);
        int i = 0;

        while(keys[idx] != -1 || deleted[idx]) {
            if(keys[idx] == key && !deleted[idx]) {
                deleted[idx] = true; // tombstone
                return;
            }

            i++;
            idx = (hashFunction(key) + i*i) % TABLE_SIZE;
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

    // Insert keys (note collisions)
    ht.insert(1, "Alice");
    ht.insert(12, "Bob");    // collision with key 1
    ht.insert(23, "Charlie"); // another collision
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
