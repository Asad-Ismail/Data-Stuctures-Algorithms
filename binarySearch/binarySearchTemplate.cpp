#include <iostream>
#include <vector>

// Problem-specific function to check if the current guess is valid.
bool is_valid(int guess) {
    // Implement this based on the given problem.
    // Example: return guess >= some_condition;
}

// Generic binary search template.
int binary_search(int low, int high) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (is_valid(mid)) {
            // Narrow the search to the lower half, including mid.
            high = mid;
        } else {
            // Narrow the search to the upper half, excluding mid.
            low = mid + 1;
        }
    }
    // Low is the smallest index at which is_valid is true.
    return low;
}

// Example usage of the binary search template.
int main() {
    int low = 0;
    int high = 100; // Set initial values based on the problem.

    int result = binary_search(low, high);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

/// Some examples of above template

bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 1, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low; // The first bad version.
}



