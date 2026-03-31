#include <iostream>
#include "SortingAlgorithms.h"
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr1[] = {5, 3, 8, 4, 2};
    int arr2[] = {9, 1, 6, 7, 3};
    int arr3[] = {10, 7, 2, 4, 1};
    int arr4[] = {12, 11, 13, 5, 6};
    int arr5[] = {10, 80, 30, 90, 40};
    int arr6[] = {4, 10, 3, 5, 1};

    SortingAlgorithms::bubble(arr1, 5);
    cout << "Bubble: ";
    printArr(arr1, 5);

    SortingAlgorithms::selection(arr2, 5);
    cout << "Selection: ";
    printArr(arr2, 5);

    SortingAlgorithms::insertion(arr3, 5);
    cout << "Insertion: ";
    printArr(arr3, 5);

    SortingAlgorithms::merge(arr4, 5);
    cout << "Merge: ";
    printArr(arr4, 5);

    SortingAlgorithms::quick(arr5, 5);
    cout << "Quick: ";
    printArr(arr5, 5);

    SortingAlgorithms::heap(arr6, 5);
    cout << "Heap: ";
    printArr(arr6, 5);

    return 0;
}