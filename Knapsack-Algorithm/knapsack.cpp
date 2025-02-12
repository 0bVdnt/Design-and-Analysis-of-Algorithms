/**
 * @file knapsack.cpp
 * @brief Implementation of the 0/1 Knapsack problem using various approaches
 *
 * This file implements the classic 0/1 Knapsack problem using four different methods:
 * 1. Pure recursive solution (exponential time complexity)
 * 2. Memoization (top-down dynamic programming)
 * 3. Tabulation (bottom-up dynamic programming)
 * 4. Space-optimized dynamic programming
 *
 * Time Complexities:
 * - Recursive: O(2^n)
 * - Memoization & DP: O(n*W) where n=number of items, W=capacity
 * - Space-optimized DP: O(n*W) time, O(W) space
 */
/**
 * @file knapsack.cpp
 * @brief Implementation of the 0/1 Knapsack problem using various approaches
 * 
 * This implementation provides four different solutions to the classic 0/1 Knapsack problem:
 * 1. Recursive approach
 * 2. Memoization (Top-down DP)
 * 3. Dynamic Programming (Bottom-up)
 * 4. Space-optimized Dynamic Programming
 */

/**
 * @class Knapsack
 * @brief Class implementing different solutions for the 0/1 Knapsack problem
 */

//  class Knapsack {
    /**
     * @brief Sets the weights of items from standard input
     */
    // void setWeights();
    
    /**
     * @brief Sets the values of items from standard input
     */
    // void setValues();
    
    // public:
    /**
     * @brief Constructor initializing the Knapsack problem instance
     * @param _numberOfItems Number of items available
     */
    // Knapsack();

    /**
     * @brief Recursive utility function for solving Knapsack problem
     * @param index Current item index being considered
     * @param wt Remaining capacity of knapsack
     * @return Maximum value that can be achieved
     * @time_complexity O(2^n)
     * @space_complexity O(n) due to recursion stack
     */
    // int knapsackRecUtil();

    /**
     * @brief Memoization utility function for solving Knapsack problem
     * @param index Current item index being considered
     * @param wt Remaining capacity of knapsack
     * @param memo Memoization table to store computed results
     * @return Maximum value that can be achieved
     * @time_complexity O(n*W)
     * @space_complexity O(n*W)
     */
    // int knapsackMemoUtil();

    /**
     * @brief Solves Knapsack problem using recursive approach
     * @return Maximum value that can be achieved
     */
    // int knapsackRecursion();

    /**
     * @brief Solves Knapsack problem using memoization
     * @return Maximum value that can be achieved
     */
    // int knapsackMemoization();

    /**
     * @brief Solves Knapsack problem using dynamic programming
     * @return Maximum value that can be achieved
     * @time_complexity O(n*W)
     * @space_complexity O(n*W)
     */
    // int knapsackDP();

    /**
     * @brief Solves Knapsack problem using space-optimized dynamic programming
     * @return Maximum value that can be achieved
     * @time_complexity O(n*W)
     * @space_complexity O(W)
     */
    // int knapsackDPSpaceOptimized();
// };


#include <iostream>
#include <vector>
#include <algorithm>

class Knapsack {
    private:
    int noOfItems, capacity;
    std::vector<int> weights, values;
    
    void setWeights() {
        // std::cout << "Enter the weights of " << noOfItems 
        //           << " items:" << std::endl;
        for(int &i : weights)
        std::cin >> i;
    }
    
    void setValues() {
        // std::cout << "Enter the values of " << noOfItems 
        //           << " items respectively:" << std::endl;
        for(int &i: values)
        std::cin >> i;
    }

    int knapsackRecUtil(int index, int wt) {
        if(index >= noOfItems || capacity <= 0)
        return 0;
        
        if(weights[index] > wt)
        return knapsackRecUtil(index + 1, wt);
        
        return std::max(
            values[index] + knapsackRecUtil(index + 1, wt - weights[index]),
            knapsackRecUtil(index + 1, wt)
        );
    }
    
    int knapsackMemoUtil(int index, int wt, std::vector<std::vector<int>> &memo) {
        if(index >= noOfItems || capacity < 0)
        return 0;
        
        if(memo[index][wt] != -1)
        return memo[index][wt];
        
        if(weights[index] > wt)
        return memo[index][wt] = knapsackMemoUtil(index + 1, wt, memo);

        return memo[index][wt] = std::max(
            values[index] + knapsackMemoUtil(index + 1, wt - weights[index], memo),
            knapsackMemoUtil(index + 1, wt, memo)
        );
    }
    
    public:
    Knapsack(int _numberOfItems)
    :noOfItems(_numberOfItems),
    weights(std::vector<int>(_numberOfItems, 0)),
    values(std::vector<int>(_numberOfItems, 0)) {
        setWeights();
        setValues();
        std::cin >> capacity;
    }
    
    int knapsackRecursion() {
        return knapsackRecUtil(0, capacity);
    }
    
    int knapsackMemoization() {
        std::vector<std::vector<int>> 
        memo(noOfItems + 1,std::vector<int>(capacity + 1, -1));
        return knapsackMemoUtil(0, capacity, memo);
    }
    
    int knapsackDP() {
        std::vector<std::vector<int>> dp(noOfItems + 1, std::vector<int>(capacity + 1, 0));
        for(int index = noOfItems - 1; index >= 0; index--) {
            for(int wt = 0; wt <= capacity; wt++) {
                if(weights[index] > wt)
                dp[index][wt] = dp[index + 1][wt];
                else
                dp[index][wt] = std::max(
                        values[index] + dp[index + 1][wt - weights[index]],
                        dp[index + 1][wt]
                    );
            }
        }
        return dp[0][capacity];
    }

    int knapsackDPSpaceOptimized() {
        std::vector<int> dp(capacity + 1, 0);
        for(int i = 0; i < noOfItems; i++) {
            for(int wt = capacity; wt >= weights[i]; wt--) {
                dp[wt] = std::max(dp[wt], values[i] + dp[wt - weights[i]]);
            }
        }
        return dp[capacity];
    }
};

/**
 * @brief Main function that reads test cases from input.txt and demonstrates all approaches
 * @return 0 on successful execution
 */

 int main (void) {
    FILE *instream;
    freopen_s(&instream, "input.txt" ,"r", stdin);
    int t;
    std::cin >> t;
    int cases = t;
    while(t--) {
        std::cout << cases - t << ':' << std::endl;
        int n;
        std::cin >> n;
        Knapsack k(n);
        std::cout << "Solution of knapsack problem using Recursion: "
                  << k.knapsackRecursion() << std::endl;

        std::cout << "Solution of knapsack problem using Memoization: "
                  << k.knapsackMemoization() << std::endl;

        std::cout << "Solution of knapsack problem using Dynamic Programming: "
                  << k.knapsackDP() << std::endl;
        
        std::cout << "Solution of knapsack problem using Dynamic Programming "
                  << "(Space Optimized): "
                  << k.knapsackDPSpaceOptimized() << std::endl;

        std::cout << std::endl;
    }

    return 0;
}