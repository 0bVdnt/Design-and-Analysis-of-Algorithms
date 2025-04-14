# Assignment 4: Topological Ordering of a Directed Graph

## Problem Statement
Obtain the Topological ordering of vertices in a given directed graph (digraph).

## Description
This assignment implements two approaches to solve the problem of topological ordering:
1. **DFS-based Topological Sorting**: Implemented in `topologicalOrdering_DFS.cpp`.
2. **Kahn's Algorithm**: Implemented in `kahnsAlgo.cpp`.

## Files
- `topologicalOrdering_DFS.cpp`: Contains the implementation of topological sorting using Depth First Search (DFS).
- `kahnsAlgo.cpp`: Contains the implementation of topological sorting using Kahn's Algorithm.
- `Makefile`: Automates the compilation and execution of the programs.
- `ProblemStatement.md`: Describes the problem statement for the assignment.

## How to Run
1. Ensure you have a C++ compiler installed (e.g., `clang++` or `g++`).
2. Use the provided `Makefile` to compile and run the programs:
   - To run the DFS-based approach:
     ```bash
     make topologicalOrdering_DFS
     ```
   - To run Kahn's Algorithm:
     ```bash
     make kahnsAlgo
     ```
3. Follow the prompts in the terminal to input the number of nodes, edges, and the edges themselves.

## Example Input
```
Enter the number of Nodes: 6
Enter the number of Edges: 6
Edge: 5 2
Edge: 5 0
Edge: 4 0
Edge: 4 1
Edge: 2 3
Edge: 3 1
Enter the source node: 5
```

## Example Output
For the DFS-based approach:
```
5, 4, 2, 3, 1, 0,
```

For Kahn's Algorithm:
```
5, 4, 2, 0, 3, 1,
```

## Notes
- The graph is assumed to be a Directed Acyclic Graph (DAG).
- The source node is used to start the traversal, but the algorithms ensure all reachable nodes are included in the topological order.