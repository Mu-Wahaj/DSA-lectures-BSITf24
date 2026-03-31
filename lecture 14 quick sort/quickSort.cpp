//quick sorting is a divide and conquer algorithm that sorts an array by partitioning it into two sub-arrays based on a pivot element. The elements less than the pivot are moved to the left of the pivot, and the elements greater than the pivot are moved to the right. This process is recursively applied to the sub-arrays until they are sorted.

// The time complexity of quick sort is O(n log n) on average and O(n^2) in the worst case, which occurs when the smallest or largest element is always chosen as the pivot. However, with good pivot selection strategies (like using the median), the worst-case time complexity can be improved to O(n log n).
#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
// The main function that implements QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// This function takes the last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}