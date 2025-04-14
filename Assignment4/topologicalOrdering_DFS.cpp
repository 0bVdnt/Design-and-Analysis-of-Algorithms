#include <iostream>
#include <stack>
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

  void dfsHelper(int src, vector<bool> &visited, stack<int> &st) {
    visited[src] = true;
    for (int &nbr : adjList[src]) {
      if (!visited[nbr])
        dfsHelper(nbr, visited, st);
    }
    st.push(src);
  }

  stack<int> topologicalOrdering(int src) {
    stack<int> st;
    vector<bool> visited(size, false);
    dfsHelper(src, visited, st);
    return st;
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
  stack<int> revTopoOrder = g.topologicalOrdering(src);
  while (!revTopoOrder.empty()) {
    cout << revTopoOrder.top() << ", ";
    revTopoOrder.pop();
  }
  cout << endl;
  return 0;
}
