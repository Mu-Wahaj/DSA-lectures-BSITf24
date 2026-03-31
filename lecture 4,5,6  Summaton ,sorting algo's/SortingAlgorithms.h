#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

class SortingAlgorithms
{
public:
    static void bubble(int arr[], int n);
    static void selection(int arr[], int n);
    static void insertion(int arr[], int n);
    static void merge(int arr[], int n);
    static void quick(int arr[], int n);
    static void heap(int arr[], int n);

private:
    static void mergeSort(int arr[], int left, int right);
    static void mergeArrays(int arr[], int left, int mid, int right);
    static void quickSort(int arr[], int low, int high);
    static int partition(int arr[], int low, int high);
    static void heapify(int arr[], int n, int i);
};

#endif