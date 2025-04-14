# Design and Analysis of Algorithms - Assignment 3

This assignment contains two programs: one to check if a graph is connected using Depth-First Search (DFS), and another to print all nodes reachable from a given starting node in a directed graph using Breadth-First Search (BFS).

## Files

1.  **connectedGraphDFS.cpp**: This program checks whether a given graph is connected or strongly connected using the Depth-First Search (DFS) algorithm.
    *   It takes the number of nodes and edges as input.
    *   It asks whether the graph is directed or undirected.
    *   It adds edges to the graph based on user input.
    *   It performs a DFS traversal to check reachability from a starting node (node 0).
    *   If the graph is not connected, it prints "This is not a connected graph."
    *   If the graph is connected, it reverses the edges and performs another DFS to check for strong connectivity.
    *   Finally, it prints whether the graph is strongly connected or just connected.

2.  **reachabilityBFS.cpp**: This program prints all the nodes reachable from a given starting node in a directed graph using the Breadth-First Search (BFS) algorithm.
    *   It takes the number of nodes and edges as input.
    *   It asks whether the graph is directed or undirected.
    *   It adds edges to the graph based on user input.
    *   It takes a source node as input.
    *   It performs a BFS traversal starting from the source node to find all reachable nodes.
    *   It prints the reachability status of each node from the given source node.

## How to Compile and Run

### Prerequisites

*   A C++ compiler (e.g., g++)
*   A terminal or command prompt

### Compilation

To compile and run the programs, use the following commands:

```bash
make connectedGraphDFS
make reachabilityBFS
```

This will compile the program, execute it, and then remove the executable file.

### Execution

The programs are executed automatically after compilation. You can also run them individually using the commands mentioned above. Follow the prompts in the terminal to enter the number of nodes, edges, and other required information.
