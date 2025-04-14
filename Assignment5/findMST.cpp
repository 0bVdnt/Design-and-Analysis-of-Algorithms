#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

//---------------------------------------------------
// Structure for representing an edge in the graph
//---------------------------------------------------
struct Edge {
    int u, v, weight;
};

//---------------------------------------------------
// Disjoint Set Union (DSU) structure for Kruskal's
// using standard notations: Find-Set and Union
//---------------------------------------------------
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;  // Initialize singleton sets: {v}
    }

    // Find-Set: returns the representative of the set containing x.
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    // Union: merges the sets containing x and y.
    bool unionSet(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;

        // Union by rank (standard notation)
        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

//---------------------------------------------------
// Kruskal's Algorithm Implementation
//---------------------------------------------------
//
// Input: Graph G = (V, E) with weight function w: E -> ℝ
// Output: Spanning tree T ⊆ E with minimum total weight
//
// Pseudocode:
//
// 1. Initialize T ← ∅ and for each vertex v ∈ V, create a singleton set {v}.
// 2. Sort edges E in non-decreasing order of weight, E' = sort(E).
// 3. For each edge e = (u, v) in E':
//      If Find-Set(u) ≠ Find-Set(v) then:
//          T ← T ∪ {e}
//          Union(Find-Set(u), Find-Set(v))
// 4. Return T
//---------------------------------------------------
void kruskalMST(int V, vector<Edge>& edges) {
    // Step 2: Sort the edges in non-decreasing order of weight.
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    DSU dsu(V);
    vector<Edge> mst;
    int totalCost = 0;

    // Step 3: Process each edge
    for (const Edge &edge : edges) {
        if (dsu.unionSet(edge.u, edge.v)) {  // If including edge doesn't form a cycle
            mst.push_back(edge);
            totalCost += edge.weight;
        }
    }

    // Output the result
    cout << "\nKruskal's Minimum Spanning Tree:\n";
    for (const Edge &e : mst) {
        cout << e.u << " -- " << e.v << " (weight: " << e.weight << ")\n";
    }
    cout << "Total cost: " << totalCost << "\n";
}

//---------------------------------------------------
// Prim's Algorithm Implementation  
//---------------------------------------------------
//
// Input: Graph G = (V, E) with weight function w: E -> ℝ
// Output: Spanning tree T ⊆ E with minimum total weight
//
// Pseudocode:
//
// 1. Initialize for an arbitrary root r ∈ V:
//       For each vertex v ∈ V:
//           key[v] ← ∞, parent[v] ← NIL
//       key[r] ← 0
//       Q ← the set of all vertices in V, prioritized by key[v].
// 2. While Q ≠ ∅:
//       u ← Extract-Min(Q)
//       For each v adjacent to u:
//           If v ∈ Q and w(u,v) < key[v] then:
//               parent[v] ← u, key[v] ← w(u,v)
// 3. Return T = { (v, parent[v]) : v ∈ V \ {r} }
//---------------------------------------------------
void primMST(int V, const vector<vector<pair<int, int>>>& adj) {
    const int INF = numeric_limits<int>::max();
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    // Step 1: Initialization
    key[0] = 0; // start from vertex 0

    // Priority queue to select the minimum weight edge at every step.
    // The queue stores pairs {key, vertex}.
    priority_queue< pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, 0});

    // Step 2: Process the graph until the queue is empty.
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;  // Skip if already included in MST

        inMST[u] = true;

        // Relaxation of adjacent vertices
        for (const auto& p : adj[u]) {
            int v = p.first;
            int weight = p.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Output the MST edges and total cost.
    int totalCost = 0;
    cout << "\nPrim's Minimum Spanning Tree:\n";
    for (int v = 1; v < V; v++) {
        cout << parent[v] << " -- " << v << " (weight: " << key[v] << ")\n";
        totalCost += key[v];
    }
    cout << "Total cost: " << totalCost << "\n";
}

//---------------------------------------------------
// Main function to input the graph and choose algorithm
//---------------------------------------------------
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Containers for edges (for Kruskal) and adjacency list (for Prim)
    vector<Edge> edges;
    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter each edge in the format: u v weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // For the undirected graph
        edges.push_back({u, v, w});
        // Build an adjacency list for Prim's
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int choice;
    cout << "\nChoose algorithm:\n";
    cout << "1 - Kruskal's Algorithm\n";
    cout << "2 - Prim's Algorithm\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        kruskalMST(V, edges);
    else if (choice == 2)
        primMST(V, adj);
    else
        cout << "Invalid choice.\n";

    return 0;
}