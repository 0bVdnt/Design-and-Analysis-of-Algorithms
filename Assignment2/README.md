# 0/1 Knapsack Problem Implementation

This repository contains an implementation of the 0/1 Knapsack problem using multiple approaches, including dynamic programming with different optimization levels.

## Problem Description

The 0/1 Knapsack problem is a classic optimization problem where given a set of items, each with a weight and value, we need to determine which items to include in a collection so that the total weight is less than or equal to a given capacity and the total value is maximized.

## Implementation Approaches

### 1. Top-Down (Memoization)
- Uses recursion with memoization
- Time Complexity: O(N*W)
- Space Complexity: O(N*W)

### 2. Bottom-Up (Tabulation)
- Uses iterative approach with 2D array
- Time Complexity: O(N*W)
- Space Complexity: O(N*W)

### 3. Space Optimized Solution
- Uses two arrays (current and previous)
- Time Complexity: O(N*W)
- Space Complexity: O(2*W)

### 4. Most Optimized Solution
- Uses single array
- Time Complexity: O(N*W)
- Space Complexity: O(W)

## Input Format

The input should be provided in the following format:
```
<number_of_test_cases>
<capacity> <number_of_items>
<values_array>
<weights_array>
```

Example:
```
1
10 4
1 2 3 4
2 3 4 5
```

## Usage

1. Prepare input in a file named "input.txt"
2. Compile the program:
   ```bash
   g++ 01knapsack.cpp -o knapsack
   ```
3. Run the executable:
   ```bash
   ./knapsack
   ```

## Output

The program outputs the maximum value that can be achieved within the given capacity for each test case.
