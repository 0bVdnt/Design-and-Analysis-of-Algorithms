#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int tspBruteForce(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<int> cities;
    for (int i = 1; i < n; ++i) cities.push_back(i);

    int minCost = numeric_limits<int>::max();
    do {
        int cost = dist[0][cities[0]];
        for (int i = 0; i < cities.size() - 1; ++i) {
            cost += dist[cities[i]][cities[i+1]];
        }
        cost += dist[cities.back()][0]; // return to start
        minCost = min(minCost, cost);
    } while (next_permutation(cities.begin(), cities.end()));
    return minCost;
}

vector<vector<int>> buildMST(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    vector<int> key(n, numeric_limits<int>::max());

    key[0] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || key[j] < key[u])) u = j;
        }
        inMST[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!inMST[v] && dist[u][v] < key[v]) {
                key[v] = dist[u][v];
                parent[v] = u;
            }
        }
    }

    vector<vector<int>> mst(n);
    for (int v = 1; v < n; ++v) {
        int u = parent[v];
        mst[u].push_back(v);
        mst[v].push_back(u);
    }
    return mst;
}

void dfs(int u, const vector<vector<int>>& mst, vector<bool>& visited, vector<int>& tour) {
    visited[u] = true;
    tour.push_back(u);
    for (int v : mst[u]) {
        if (!visited[v]) dfs(v, mst, visited, tour);
    }
}

int tspApproxUsingMST(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> mst = buildMST(dist);

    vector<bool> visited(n, false);
    vector<int> tour;
    dfs(0, mst, visited, tour);
    tour.push_back(0);

    int cost = 0;
    for (int i = 0; i < tour.size() - 1; ++i) {
        cost += dist[tour[i]][tour[i+1]];
    }

    cout << "Approximate TSP tour using MST + DFS: ";
    for (int city : tour) cout << city << " ";
    cout << "\nApproximate cost: " << cost << "\n";

    return cost;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix (" << n*n << " values):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    cout << "\nCalculating exact solution using brute-force...\n";
    int exactCost = tspBruteForce(dist);
    cout << "Exact TSP cost: " << exactCost << "\n";

    cout << "\nCalculating approximate solution using MST...\n";
    int approxCost = tspApproxUsingMST(dist);

    double error = ((double)(approxCost - exactCost) / exactCost) * 100.0;
    cout << "\nApproximation error: " << error << "%\n";

    return 0;
}
