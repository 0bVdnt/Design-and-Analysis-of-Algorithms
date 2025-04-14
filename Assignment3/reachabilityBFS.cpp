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

  vector<bool> bfs(int src) {
    vector<bool> isReachable(size);
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
      int currNode = q.front();
      q.pop();
      isReachable[currNode] = true;
      for (int &nbr : adjList[currNode]) {
        if (!isReachable[nbr])
          q.push(nbr);
      }
    }
    return isReachable;
  }

  vector<bool> reachableNodes(int src) { return bfs(src); }
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
  cout << "Enter a source node to check reachability: ";
  int src = 0;
  cin >> src;
  vector<bool> isReachable(_size, false);
  isReachable = g.reachableNodes(src);
  cout << "Reachability for the node " << src << ":\n";
  for (int i = 0; i < _size; i++) {
    cout << i << (isReachable[i] ? ": Reachable" : ": Not reachable") << endl;
  }
  return 0;
}
