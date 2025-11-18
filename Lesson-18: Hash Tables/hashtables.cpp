// Lesson 18: Hash Tables

// What is a HashMap?
    // A HashMap (or hash table) is a data structure that maps keys to values. It allows:
        // Fast insertion
        // Fast lookup
        // Fast deletion

// Key idea: Use a hash function to convert a key into an array index.

// HashMap in C++ STL
    // C++ provides unordered_map (hashmap) and map (balanced BST).


#include <iostream>
#include <unordered_map>
using namespace std;

void UnorderedMapsDemo() {
    unordered_map<string, int> age;

    // Insert
    age["Alice"] = 25;
    age["Bob"] = 30;

    // Access
    cout << "Alice is " << age["Alice"] << " years old." << endl;

    // Check if key exists
    if(age.find("Charlie") == age.end()) {
        cout << "Charlie not found." << endl;
    }

    // Iterate
    for(auto &p : age) {
        cout << p.first << " -> " << p.second << endl;
    }

    // Delete
    age.erase("Bob");

}

// Pros of unordered_map:
    // Fast O(1) average lookup
    // Handles collisions automatically
    // Works with custom key types if you define a hash function


// How HashMap Works Internally

    // Array of buckets
        // A bucket is essentially a “slot” in an array where a key-value pair can go.
        // Think of a hashmap as an array of buckets.
            // Each bucket can hold one or multiple entries, depending on collision handling.
            // The size of the bucket array affects performance: too small → many collisions, too large → wasted memory.

    // Hash function maps key → bucket index
        // code
        // bucket_index = hash(key) % num_buckets;

        // hash(key) converts the key into an integer.
        // % num_buckets ensures the index is within bucket array bounds.

    // Collision
        // A collision happens when two different keys map to the same bucket.
        // Key observation: Collisions are inevitable if the number of keys > number of buckets.

        // We resolve collisions mainly in two ways:

            // * Chaining: Store a list of entries in each bucket
                // Each bucket holds a linked list or another container of key-value pairs.
                // If multiple keys map to the same bucket, append them to the list.

                // example
                // Buckets:    [0] -> empty
                //             [1] -> empty
                //             [2] -> (12, "Alice") -> (7, "Bob") -> (17, "Charlie")
                //             [3] -> empty
                //             [4] -> empty

                // Pros:
                    // Simple to implement
                    // Works even if number of elements >> number of buckets

                // Cons:
                    // Extra memory for linked list nodes
                    // Lookup becomes slower if many collisions

                // [CODE]
                // Lesson-18: Hash Tables/examples/chainingHashtables.cpp


            // * Open addressing: Find next available slot
                // All elements are stored directly in the array.
                    // If a bucket is occupied, probe the next slot until an empty one is found.  

                // Common strategies:
                    // Linear Probing
                        // [CODE]
                        // Lesson-18: Hash Tables/examples/LinearProbingHashtable.cpp
                    
                    // Quadratic Probing
                        // [CODE]
                        // Lesson-18: Hash Tables/examples/quadraticProbingHashtable.cpp
                    
                    // Double Hashing
                        // [CODE]
                        // Lesson-18: Hash Tables/examples/doubleHashingHashtables.cpp

                // Pros:
                    // No extra memory for linked lists
                    // Cache-friendly (better locality)

                // Cons:
                    // Can get “clustering” → many consecutive filled slots
                    // Must resize when table is full
                    // Delete is tricky (you may need “tombstones”)
