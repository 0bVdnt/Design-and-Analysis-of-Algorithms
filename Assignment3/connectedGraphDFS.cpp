#include <iostream>
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

  void dfs(int src, vector<bool> &reachable) {
    reachable[src] = true;
    for (int &nbr : adjList[src]) {
      if (!reachable[nbr])
        dfs(nbr, reachable);
    }
  }

  vector<bool> reachableNodes(int src) {
    vector<bool> reachable(size, false);
    dfs(src, reachable);
    return reachable;
  }

  void reverseEdges() {
    vector<vector<int>> revAdjList;
    revAdjList.resize(size);
    for (int u = 0; u < size; u++) {
      for (int &v : adjList[u]) {
        revAdjList[v].push_back(u);
      }
    }
    adjList = revAdjList;
  }
};

int main() {
  int _size, edgeCnt;
  cout << "Enter the number of Nodes: ";
  cin >> _size;
  cout << "Enter the number of Edges: ";
  cin >> edgeCnt;
  bool isDirected = false;
  char choice = 'y';
  cout << "Is the graph directed ? (y/n): ";
  cin >> choice;
  isDirected = (choice == 'y');
  Graph g(_size);
  for (int i = 0; i < edgeCnt; i++) {
    cout << "Edge: ";
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v, isDirected);
  }
  vector<bool> isReachable(_size, false);
  isReachable = g.reachableNodes(0);
  bool isConnected = true;
  for (int i = 0; i < _size; i++) {
    cout << i << isReachable[i] << '\n';
    isConnected &= isReachable[i];
  }
  if (!isConnected) {
    cout << "This is not a connected graph.\n";
    return 0;
  }
  g.reverseEdges();
  isReachable = g.reachableNodes(0);
  for (int i = 0; i < _size; i++) {
    cout << i << isReachable[i] << '\n';
    isConnected &= isReachable[i];
  }
  if (isConnected) {
    cout << "This is a strongly connected graph.\n";
  } else {
    cout << "This is a connected graph.\n";
  }
  return 0;
}
