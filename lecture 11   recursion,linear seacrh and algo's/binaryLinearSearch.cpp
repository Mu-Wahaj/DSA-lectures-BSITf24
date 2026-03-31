#include <iostream>
using namespace std;

// bool linerSearch(int arr[], int start, int end, int key);
// count number of occurrences of an element in an array using recursion;
//draw recursion tree of an array using recursion;
// int findlargest(int *arr[], int start, int end);

int linerSearch(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        cout << "Element not found" << endl;
        return -1;
    }
    if (arr[start] == key)
    {
        cout << "Element found at index " << start << endl;
        return start;
    }

    return linerSearch(arr, start + 1, end, key);
}

// binanry search using recursion;

bool binarySearch(int arr[], int start, int end, int key)
{

    if (start > end)
    {
        return false;
    }
    else
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found at index " << mid << endl;
            return true;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr, start, mid - 1, key);
        }
        else
        {
            return binarySearch(arr, mid + 1, end, key);
        }
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = -22;
    linerSearch(arr, 0, n - 1, key);

    binarySearch(arr, 0, n - 1, key);

    return 0;
}

//homework
// bool linerSearch(int arr[], int start, int end, int key);
// count number of occurrences of an element in an array using recursion;
//draw recursion tree of an array using recursion;
// int findlargest(int *arr[], int start, int end);
