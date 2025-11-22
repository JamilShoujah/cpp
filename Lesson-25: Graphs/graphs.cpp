// Lesson 25: Graphs (Zero → Hero)
// File: graphs.cpp

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// What is a Graph?

// A graph is a collection of:
    // - Nodes (also called vertices)
    // - Edges (connections between nodes)


// Graphs can represent:
    // - Social networks
    // - Maps / roads
    // - Websites linking to each other
    // - Game levels
    // - Computer networks
    // - Project dependencies

    // Graphs allow us to model "relationships" between items.

// Types of Graphs

// 1. Directed Graph (DiGraph)
    // A -> B is NOT the same as B -> A 
        // Example: one way street (like bliss street)

// 2. Undirected Graph
    // A <--> B means both directions are allowed
        // EXAMPLE: Two way street (village roads)

// 3. Weighted Graph
    // Edges have a cost (distance, time, price)
        // EXAMPLE: different paths on google maps 
            // one may take time X while another may take time Y

// 4. Unweighted Graph
    // All edges are considered equal

// 5. Cyclic / Acyclic
    // Does the graph contain loops?
    // A cycle in a graph is a path that starts and ends at the same node without repeating edges or nodes

// 6. Connected / Disconnected
    // Is there a path between every pair of nodes?


// Graph Representation in C++
    // Two main ways:

    // 1. Adjacency List (BEST for most cases)
        // Pros:
            // - Efficient
            // - Easy to iterate neighbors
            // - Memory friendly
        
        // Cons:
            // Slower to check if an edge exists

        // example: 
            vector<vector<int>> adj;

    // 2. Adjacency Matrix
        // - grid[n][n], 1 means edge, 0 means no edge

        // pros
            // - Edge check is O(1)
        // Cons
            // - Memory heavy (n^2)

        // - Useful for dense graphs
        // example:
       void AdjacencyMatrixExample() {
            int n = 5;  // number of nodes
            int u = 1;  // first node index
            int v = 3;  // second node index

            // Create NxN adjacency matrix initialized to 0
            vector<vector<int>> matrix(n, vector<int>(n, 0));

            // Add an edge between u and v
            matrix[u][v] = 1;
            matrix[v][u] = 1; // because this example is undirected
        }
            

// Graph Traversal
    // There are two foundational traversals:

    // * BFS (Breadth-First Search) => Explore a graph level by level
        // Used for:
            // shortest path in unweighted graphs
            // levels
            // checking connectivity

        // Intuition
            // Imagine you're standing in a city, and you want to explore all places at distance 1,
            // then all places at distance 2,
            // then distance 3, and so on.

            // You explore closest first → that’s BFS.

        // How BFS Thinks
            // Start from a node
            // Visit all neighbors
            // Then visit neighbors of neighbors
            // And so on…

            // Graphically:
                // Start (root) → [N1 N2 N3] (nearest nodes) → [Neighbors of N1,N2,N3] → ...

                // Example:
                //           (0)
                //          / | \
                //        (1)(2)(3)
                //        / \
                //      (4) (5)

                // Edges:
                    // 0 → 1
                    // 0 → 2
                    // 0 → 3
                    // 1 → 4
                    // 1 → 5

                // final order of traversal:
                    // 0 → 1 → 2 → 3 → 4 → 5

        // Data Structure Used
            // Queue (FIFO → First In, First Out)
            // Why a queue?
            // Because BFS needs to process nodes in the order they are discovered.

        void bfs(int start, vector<vector<int>>& adj) {
            vector<bool> visited(adj.size(), false);
            queue<int> q;
            

            visited[start] = true;
            q.push(start);

            while (!q.empty()) {
                int node = q.front(); q.pop();
                cout << node << " ";

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

    // * DFS (Depth-First Search) => Explore a graph as deep as possible, then backtrack
        // Used for:
            // detecting cycles
            // topological sorting
            // exploring components
            // solving mazes

        // Intuition
            // Imagine exploring a maze.

            // You always take a path all the way until you hit a dead-end,
            // then you backtrack and try another path.

            // That’s DFS.
        
            // Graphically:
                // Start → N1 → N4 → N7 → (dead end) Backtrack → N5 → N9 → ...

                // Example:
                //           (0)
                //          / | \
                //        (1)(2)(3)
                //        / \
                //      (4) (5)

                // Edges:
                    // 0 → 1
                    // 0 → 2
                    // 0 → 3
                    // 1 → 4
                    // 1 → 5
                
                // Adjacency List:
                    // 0 → {1, 2, 3}
                    // 1 → {0, 4}
                    // 2 → {0}
                    // 3 → {0}
                    // 4 → {1, 5}
                    // 5 → {4}

                // final order of traversal:
                    // 0 → 1 → 4 → backtrack → 5 → backtrack → backtrack → 2 → backtrack → 3

                            
        // Data Structure Used
            // Stack (LIFO → Last In, First Out)
            // or recursion, which uses the system call stack.

        void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
            visited[node] = true;
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, adj, visited);
                }
            }
        }

    // Weighted Graphs
        // Use a pair: (neighbor, weight)

        //  Weighted Graph Example (Undirected)
        void WeightedGraphExample() {

            int n = 5;   // Number of nodes: 0, 1, 2, 3, 4

            // Step 1: Create adjacency list
            // Each element stores a pair: {neighbor, weight}
            vector<vector<pair<int, int>>> adj(n);

            // Step 2: Define edges with weights
            // Example edges:
            // 1 -- 3 (weight 7)
            // 0 -- 2 (weight 4)
            // 2 -- 4 (weight 5)
            
            adj[1].push_back({3, 7});
            adj[3].push_back({1, 7});  // undirected, add both ways

            adj[0].push_back({2, 4});
            adj[2].push_back({0, 4});

            adj[2].push_back({4, 5});
            adj[4].push_back({2, 5});

            // Step 3: Optional: Print adjacency list
            cout << "Weighted Graph Adjacency List:\n";
            for (int i = 0; i < n; i++) {
                cout << i << ": ";
                for (auto [neighbor, weight] : adj[i]) {
                    cout << "(" << neighbor << ", " << weight << ") ";
                }
                cout << endl;
            }
        }

    // Shortest Path Algorithms
        // Dijkstra (no negative weights)
        // Finds shortest path from single source.
        void dijkstra(int start, vector<vector<pair<int,int>>>& adj) {
            vector<int> dist(adj.size(), INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            dist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                auto [cost, node] = pq.top(); pq.pop();
                if (cost > dist[node]) continue;

                for (auto& e : adj[node]) {
                    int next = e.first;
                    int w = e.second;

                    if (dist[node] + w < dist[next]) {
                        dist[next] = dist[node] + w;
                        pq.push({dist[next], next});
                    }
                }
            }

            for (int i = 0; i < dist.size(); i++)
                cout << "dist to " << i << " = " << dist[i] << "\n";
        }

    // Detecting Cycles
        // Undirected Graph Cycle Detection (DFS)
        bool dfsCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
            visited[node] = true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    if (dfsCycle(neighbor, node, adj, visited)) return true;
                }
                else if (neighbor != parent) {
                    return true; // back edge
                }
            }
            return false;
        }

    // Topological Sort
        // (Only for DAGs – Directed Acyclic Graphs) => No cycles

        // Used for:
            // task scheduling
            // dependency resolution
            // build systems

        void topo(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s) {
            vis[node] = true;
            for (int nxt : adj[node])
                if (!vis[nxt]) topo(nxt, adj, vis, s);
            s.push(node);
        }

    // Connected Components
    int components(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }

    // When to Use What
        // Find shortest path (unweighted)	=> BFS
        // Shortest path with weights	    => Dijkstra
        // Detect cycle (undirected)	    => DFS
        // Detect cycle (directed)	        => DFS + recursion stack
        // Topological ordering	            => Topological sort
        // Check connectivity               => BFS / DFS
        // Count connected components	    => BFS / DFS
        // Represent large sparse graph	    => Adjacency list
        // Fast edge lookup	                => Adjacency matrix


