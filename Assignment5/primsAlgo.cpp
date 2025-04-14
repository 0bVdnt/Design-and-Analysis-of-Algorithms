#include <iostream>
#include <limits.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void primsMST(int size, vector<vector<pair<int, int>>> &adjList) {
  vector<int> key(size, INT_MAX);
  vector<int> parent(size, -1);
  vector<bool> inMST(size, false);

  key[0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  //{weight, vertex}
  pq.push({0, 0});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (inMST[u])
      continue;

    inMST[u] = true;

    for (pair<int, int> &p : adjList[u]) {
      int v = p.first;
      int w = p.second;

      if (!inMST[v] && w < key[v]) {
        key[v] = w;
        parent[v] = u;
        pq.push({key[v], v});
      }
    }
  }

  int totalCost = 0;
  cout << "Minimal Spanning Tree for Prim's Algorithm: " << endl;
  for (int v = 1; v < size; v++) {
    cout << parent[v] << " -- " << v << " (weight: " << key[v] << ")\n";
    totalCost += key[v];
  }
  cout << "Total cost: " << totalCost << endl;
}

int main() {
  int _size, edgeCnt;
  cout << "Enter the number of Nodes: ";
  cin >> _size;
  cout << "Enter the number of Edges: ";
  cin >> edgeCnt;
  vector<vector<pair<int, int>>> adjList(_size);

  for (int i = 0; i < edgeCnt; i++) {
    cout << "Edge (node1, node2, weight): ";
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
  }
  primsMST(_size, adjList);
  return 0;
}
