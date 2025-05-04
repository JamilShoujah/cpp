// Lesson 13: Parallel STL algorithms

// What Are Parallel STL Algorithms?
    // C++17 introduced execution policies to standard algorithms in the STL (Standard Template Library), 
    // allowing you to specify how the algorithm should execute:

    // Available Execution Policies:
        // std::execution::seq (Sequential) => Default, runs one step at a time 
        // std::execution::par (Parallel) => Uses multiple threads            
        // std::execution::par_unseq (Parallel + vectorized) => Threads + SIMD instructions  
        // std::execution::unseq (Unsequenced (vectorized only)) => No threads, just SIMD  

    // When to Use Parallel STL
        // Parallel STL shines when dealing with large, CPU-bound, independent data.
        
    // Characteristics of ideal cases:
        // Big data size — Thousands to millions of elements.
        // Independent operations — No element relies on others.
        // Heavy computation per element — Enough to outweigh the overhead of multithreading.
        // Read-only or minimal side effects — So there are no race conditions.


    // When Not to Use Parallel STL
        // Parallelism isn't always better. Sometimes, it can slow things down or introduce bugs.

    // Avoid parallel STL if:
        // Small dataset
        // The cost of managing threads outweighs the benefit.
        // Overhead > speedup.
        // Heavy synchronization needed
        // If operations depend on shared data, you risk:
        // Race conditions
        // Deadlocks
        // Increased complexity
        // Order matters
        // par and par_unseq may not preserve order — especially risky with side effects.
        // Debugging becomes harder
        // Threads can make bugs nondeterministic and tricky to trace.

// Example: Parallel vs Sequential Processing
// We'll apply a CPU-heavy operation (like a dummy calculation) to a vector of 10 million elements and time both versions.
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void heavyComputation(int& n) {
    for (int i = 0; i < 100; ++i)
        n = (n * n + 7) % 1000003;
}

void parallelWork(std::vector<int>& data, int start, int end) {
    for (int i = start; i < end; ++i) {
        heavyComputation(data[i]);
    }
}

int main() {
    const int N = 10'000'000;
    std::vector<int> data(N, 42);
    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    int chunk = N / numThreads;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numThreads; ++i) {
        int begin = i * chunk;
        int end = (i == numThreads - 1) ? N : (i + 1) * chunk;
        threads.emplace_back(parallelWork, std::ref(data), begin, end);
    }
    for (auto& t : threads) t.join();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Parallel execution time: " << duration.count() << " seconds\n";

    return 0;
}
