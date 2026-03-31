// bool linerSearch(int arr[], int start, int end, int key);
// count number of occurrences of an element in an array using recursion;
//draw recursion tree of an array using recursion;
// int findlargest(int *arr[], int start, int end);

#include <iostream>
using namespace std;

bool linerSearch(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        cout << "Element not found" << endl;
        return false;
    }
    if (arr[start] == key)
    {
        cout << "Element found at index " << start << endl;
        return true;
    }

    return linerSearch(arr, start + 1, end, key);
}
//count number of occurrences of an element in an array using recursion;

int countOccurrences(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return 0;
    }
    if (arr[start] == key)
    {
        return 1 + countOccurrences(arr, start + 1, end, key);
    }
    else
    {
        return countOccurrences(arr, start + 1, end, key);
    }
}

//int findlargest(int *arr[], int start, int end);
int findLargest(int arr[], int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }
    int mid = (start + end) / 2;
    int leftLargest = findLargest(arr, start, mid);
    int rightLargest = findLargest(arr, mid + 1, end);
    return max(leftLargest, rightLargest);
}

// minimum element in an array using recursion;
int findMinimum(int arr[], int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }
    int mid = (start + end) / 2;
    int leftMinimum = findMinimum(arr, start, mid);
    int rightMinimum = findMinimum(arr, mid + 1, end);
    return min(leftMinimum, rightMinimum);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = -22;
    linerSearch(arr, 0, n - 1, key);

    cout << "Number of occurrences of " << key << ": " << countOccurrences(arr, 0, n - 1, key) << endl;

    cout << "Largest element in the array: " << findLargest(arr, 0, n - 1) << endl;

    cout << "Minimum element in the array: " << findMinimum(arr, 0, n - 1) << endl;

    cout << "Recursion tree:" << endl;
    drawRecursionTree(arr, 0, n - 1, 0);

    return 0;
}