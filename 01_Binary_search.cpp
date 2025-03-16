#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Binary search function
int binarysearch(vector<int> arr, int tar) {
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // Avoids potential overflow

        if (tar > arr[mid]) {
            start = mid + 1;
        } else if (tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid; // Target found
        }
    }

    return -1; // Target not found
}

int main() {
    // Varying input sizes
    vector<int> inputSizes = {1000, 10000, 100000, 1000000, 10000000};

    for (int size : inputSizes) {
        // Create a sorted vector from 1 to size
        vector<int> arr;
        for (int i = 1; i <= size; ++i) {
            arr.push_back(i);
        }

        // Target element (can be any element within the range)
        int target = size / 2;

        // Start measuring time
        auto start = high_resolution_clock::now();

        // Perform binary search
        int index = binarysearch(arr, target);

        // Stop measuring time
        auto stop = high_resolution_clock::now();

        // Calculate the duration
        auto duration = duration_cast<milliseconds>(stop - start);

        // Output the result
        cout << "Input size: " << size << ", Time taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
