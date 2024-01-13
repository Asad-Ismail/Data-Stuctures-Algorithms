

'''
Complexity: Average and worst-case as 
O(n2), best-case as 
O(n).
Use cases: Efficient for small datasets, much like bubble sort, and more efficient in practice than other quadratic algorithms, like selection sort. It's used when the cost of swapping elements is high (since insertion sort minimizes swaps), or the data is coming in live and needs to be sorted as it's received.
Mnemonic: "Insert an element into its correct position in the sorted portion."
'''

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low  --> Starting index,
// high  --> Ending index
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



// Function to perform Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}


// Function to perform Insertion Sort
void insertionSort(std::vector<int>& arr) {
    int i, key, j;
    int n = arr.size();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& nums, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = nums[l + i];
    for (j = 0; j < n2; j++)
        R[j] = nums[m + 1 + j];

    // Merge the temporary arrays back into nums[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& nums, int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        merge(nums, l, m, r);
    }
}

// NlogN time complexity no extra space
void heapify(std::vector<int>& nums, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && nums[left] > nums[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && nums[right] > nums[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        std::swap(nums[i], nums[largest]);

        // Recursively heapify the affected sub-tree
        heapify(nums, n, largest);
    }
}

void heapSort(std::vector<int>& nums) {
    int n = nums.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(nums[0], nums[i]);

        // Call max heapify on the reduced heap
        heapify(nums, i, 0);
    }
}

