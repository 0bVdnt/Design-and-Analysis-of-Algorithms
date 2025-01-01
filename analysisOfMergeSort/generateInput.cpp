/* This program generates input data for testing algorithms
 * It creates a file 'input.txt' with varying input sizes
 * The input sizes range from small to large values
 * The first line contains the total number of test cases
 * Each subsequent line contains a single input size
 */
//Generates input suitable for analysis of merge sort algorithm
#include <iostream>
using namespace std;

void generateInputFile() { //Here Any algorithm can be used to generate data according to the requirements
    freopen("input.txt", "w", stdout);
    // Define the start points, limits, and increments in arrays
    int start[] = {10, 100, 1000, 10000, 100000, 1000000};
    int limit[] = {100, 1000, 10000, 100000, 1000000, 10000000};
    int increment[] = {10, 100, 1000, 10000, 100000, 1000000};
    
    int cnt = 1;    
    for (int i = 0; i < 6; ++i) { // Calculate the number of test cases
        for (int j = start[i]; j < limit[i]; j += increment[i]) {
            cnt++;
        }
    }

    cout << cnt << '\n'; // Print the number of test cases

    // Loop through each range
    for (int i = 0; i < 6; ++i) {
        for (int j = start[i]; j < limit[i]; j += increment[i]) {
            cout << j << '\n';
        }
    }
    std::cout << 10000000;
}

int main() {
    generateInputFile();
    return 0;
}
