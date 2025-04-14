#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int u, v, weight;
};

class DSU {
public:
  vector<int> parent, rank;

  DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  bool unionSet(int x, int y) {
    int xr = find(x);
    int yr = find(y);

    if (xr == yr)
      return false;

    if (rank[xr] < rank[yr])
      parent[xr] = yr;
    else if (rank[xr] > rank[yr])
      parent[yr] = xr;
    else {
      parent[xr] = yr;
      rank[yr]++;
    }
    return true;
  }
};

void kruskalMST(int n, vector<Edge> &edges) {
  sort(edges.begin(), edges.end(),
       [](Edge &a, Edge &b) { return a.weight < b.weight; });
  DSU dsu(n);
  vector<Edge> mst;
  int totalCost = 0;
  for (Edge &e : edges) {
    if (dsu.unionSet(e.u, e.v)) {
      mst.push_back(e);
      totalCost += e.weight;
    }
  }

  cout << "\nKruskal\'s Minimun Spanning Tree:" << endl;

  for (Edge &e : mst) {
    cout << e.u << " -- " << e.v << " (weight: " << e.weight << ")" << endl;
  }
  cout << "Total Cost: " << totalCost << endl;
}

int main() {
  int _size, edgeCnt;
  vector<Edge> edges;
  cout << "Enter the number of Nodes: ";
  cin >> _size;
  cout << "Enter the number of Edges: ";
  cin >> edgeCnt;
  for (int i = 0; i < edgeCnt; i++) {
    cout << "Edge (node1 , node2, weight): ";
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  kruskalMST(_size, edges);
  return 0;
}
