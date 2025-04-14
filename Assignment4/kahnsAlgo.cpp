#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
  vector<vector<int>> adjList;
  int size;

public:
  Graph(int _size) : size(_size), adjList(vector<vector<int>>(_size)) {}

  void addEdge(int u, int v, bool directed) {
    adjList[u].push_back(v);
    if (!directed) {
      adjList[v].push_back(u);
    }
  }

  vector<int> kahnsAlgo(int src) {
    vector<int> visited(size, false);
    vector<int> topologicalOrder;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
      int currNode = q.front();
      q.pop();
      topologicalOrder.push_back(currNode);
      for (int &nbr : adjList[currNode]) {
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
    return topologicalOrder;
  }

  vector<int> topologicalOrdering(int src) {
    vector<int> topoOrder = kahnsAlgo(src);
    return topoOrder;
  }
};

int main() {
  int _size, edgeCnt;
  cout << "Enter the number of Nodes: ";
  cin >> _size;
  cout << "Enter the number of Edges: ";
  cin >> edgeCnt;
  Graph g(_size);
  for (int i = 0; i < edgeCnt; i++) {
    cout << "Edge: ";
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v, true);
  }
  int src = 0;
  cout << "Enter the source node: ";
  cin >> src;
  for (int &node : g.topologicalOrdering(src))
    cout << node << ", ";
  cout << endl;
  return 0;
}
