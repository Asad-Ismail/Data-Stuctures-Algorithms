#include <iostream>
#include <vector>

// Problem-specific function to check if the current guess is valid.
bool is_valid(int guess) {
    // Implement this based on the given problem.
    // Example: return guess >= some_condition;
}

// Generic binary search template. Can also be used to find min element
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

// Generic binary search template to find the maximum value satisfying is_valid.
int binary_search_max(int low, int high) {
    while (low < high) {
        // Use ceil of the middle to avoid infinite loops and ensure progress.
        int mid = low + (high - low + 1) / 2;
        if (is_valid(mid)) {
            // If mid is valid, this could be the maximum, so move the low boundary up.
            low = mid;
        } else {
            // If mid is not valid, exclude it and move the high boundary down.
            high = mid - 1;
        }
    }
    // Low is now the maximum index where is_valid is true.
    return low;
}

int findLastOccurrence(std::vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (nums[mid] <= target) {
            // Move towards the end of the array.
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return (nums[low] == target) ? low : -1; // Check if the target is actually found.
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



