/**
 * @file createDataset.cpp
 * @brief This file contains functions to generate random data, measure the execution time of an algorithm, and save the results to a CSV file.
 * 
 * The program generates random integers, measures the execution time of a specified algorithm, and records the results
 * in a CSV file. The user is prompted to enter the required length of the dataset and the size of each dataset.
 */

#include <random>
#include <iostream>
#include <fstream>
#include <chrono>

/**
 * @brief Generates a vector of random integers.
 * 
 * This function generates a vector of random integers within a specified range.
 * 
 * @param n The number of random integers to generate.
 * @param lower_bound The lower bound of the random integers.
 * @param upper_bound The upper bound of the random integers.
 * @return std::vector<int> A vector containing the generated random integers.
 */
std::vector<int> generateRandomData(int n, int lower_bound, int upper_bound);

/**
 * @brief Creates a dataset and measures execution time.
 * 
 * This function generates random data, measures the execution time of a specified algorithm,
 * and writes the results to a CSV file. The user is prompted to enter the required length of the dataset
 * and the size of each dataset.
 */
void createDataset();

/**
 * @brief Algorithm to be executed.
 * 
 * This function contains the algorithm for which the execution time is to be measured.
 * 
 * @param input_data A reference to the vector of integers to be processed by the algorithm.
 */
void algorithm(std::vector<int> &input_data);

/**
 * @brief The main function that drives the program.
 * 
 * It generates random data, measures the execution time of a specified algorithm, and writes the results to a CSV file.
 * 
 * @return int Returns 0 on successful execution.
 */
int main();

/**
 * @brief Merges two sorted subarrays into a single sorted array.
 * 
 * @param arr The array to be sorted.
 * @param start The starting index of the subarray.
 * @param end The ending index of the subarray.
 * @param mid The middle index of the subarray.
 */
void merge(std::vector<int> &arr, int start, int end, int mid);

/**
 * @brief Sorts an array using the merge sort algorithm.
 * 
 * @param arr The array to be sorted.
 * @param start The starting index of the array.
 * @param end The ending index of the array.
 */
void mergeSort(std::vector<int> &arr, int start, int end);

void merge(std::vector<int> &arr, int start, int end, int mid) {
    std::vector<int> leftPart(arr.begin() + start, arr.begin() + mid + 1);
    std::vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + end + 1);    
    int i = 0;
    int j = 0;
    int idx = start;
    while(i < leftPart.size() && j < rightPart.size()) {
        if(leftPart[i] < rightPart[j])
            arr[idx++] = leftPart[i++];

        else 
            arr[idx++] = rightPart[j++];
    }
    while(i < leftPart.size())
        arr[idx++] = leftPart[i++];
    
    while(j < rightPart.size())
        arr[idx++] = rightPart[j++];
}

void mergeSort(std::vector<int> &arr, int start, int end) {
    if(start >= end)
        return;
    
    int mid = (start +  end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end, mid);
}

//Algorithm to be executed
void algorithm(std::vector<int> &input_data) {
    // Add the function of the Algorithm for which the execution time is to be measured here
    mergeSort(input_data, 0, input_data.size() - 1);
}

std::vector<int> generateRandomData(int n, int lower_bound, int upper_bound) {
    std::vector<int> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lower_bound, upper_bound);
    for(int i = 0; i < n; i++) {
        data.push_back(dis(gen));
    }
    return data;
}

void createDataset() {
    // Take input from input.txt file (if needed)
    freopen("input.txt", "r", stdin);

    // An array to store input data
    std::vector<int> input_data;
    
    // Open a file to write the results
    std::ofstream ofs("dataSheet.csv");
    
    int n = 0;
    std::cout << "Enter the required length of dataset: ";
    std::cin >> n;

    ofs << "Input_Size,Exec_Time" << std::endl;
    
    for(int i = 0; i < n; i++) {
        int size = 0;
        std::cin >> size;

        // Generate random data
        int lower_bound = -20000;
        int upper_bound = 20000;
        input_data = generateRandomData(size, lower_bound, upper_bound);
        
        std::cout << "Execution of algorithm started." << std::endl;
        // Saves the timestamp before the execution of the function
        auto start = std::chrono::high_resolution_clock::now();

        // Algorithm for which the execution time is to be measured
        algorithm(input_data);

        // Saves the timestamp after the execution of the function
        auto stop = std::chrono::high_resolution_clock::now();
        std::cout << "The execution of the algorithm has been completed." << std::endl;
        
        //Calculates the duration of the function execution
        std::chrono::duration<double> duration = stop - start;
        std::cout << "The algorithm was executed in '" << duration.count() << "' seconds " << std::endl;

        //Write the results to a CSV file
        ofs << size << ',' << duration.count() << '\n';
    }
    ofs.close();
}

int main() {
    createDataset();
    return 0;
}
