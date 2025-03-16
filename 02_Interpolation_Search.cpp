#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Interpolation search function
int interpolationSearch(const vector<int>& arr, int low, int high, int key) {
    // Check if key is outside array range
    if (key < arr[low] || key > arr[high]) {
        return -1;
    }

    // Calculate interpolation position
    int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    // Handle division by zero (if arr[high] == arr[low])
    if (arr[high] == arr[low]) {
        if (arr[low] == key) {
            return low;
        } else {
            return -1;
        }
    }

    // If key is found
    if (arr[pos] == key) {
        return pos;
    }

    // If key is less, search in the left half
    if (arr[pos] > key) {
        return interpolationSearch(arr, low, pos - 1, key);
    } else {
        // If key is greater, search in the right half
        return interpolationSearch(arr, pos + 1, high, key);
    }
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
        int key = size / 2;

        // Start measuring time
        auto start = high_resolution_clock::now();

        // Perform interpolation search
        int index = interpolationSearch(arr, 0, arr.size() - 1, key);

        // Stop measuring time
        auto stop = high_resolution_clock::now();

        // Calculate the duration
        auto duration = duration_cast<microseconds>(stop - start);

        // Output the result
        cout << "Input size: " << size << ", Time taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
