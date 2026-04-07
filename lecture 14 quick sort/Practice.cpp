// Implement Merge Sort iteratively (without recursion)

// Implement Quick Sort with different pivot strategies

// Count inversions using Merge Sort

// Find kth smallest element using Quick Select

// Sort a linked list using Merge Sort

#include <iostream>
#include <vector>
using namespace std;

// Merge Sort implementation without using vectors and builtin  functions
void merge(int arr[], int left, int mid, int right)
{
    int i = left;    // Starting index of left subarray
    int j = mid + 1; // Starting index of right subarray
    int k = left;    // Starting index of merged array

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            swap(arr[k], arr[i]);
            i++;
        }
        else
        {
            swap(arr[k], arr[j]);
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        swap(arr[k], arr[i]);
        i++;
        k++;
    }

    while (j <= right)
    {
        swap(arr[k], arr[j]);
        j++;
        k++;
    }
}
// Iterative Merge Sort function
void mergeSort(int arr[], int n)
{
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2)
    {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}
// kth smallest element using Quick Select
int partition(int arr[], int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // Move pivot to end
    int storeIndex = left;

    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(arr[storeIndex], arr[i]);
            storeIndex++;
        }
    }
    swap(arr[right], arr[storeIndex]); // Move pivot to its final place
    return storeIndex;
}
int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function (Lomuto)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Main function
int main() {
    int arr[] = {5, 2, 8, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

