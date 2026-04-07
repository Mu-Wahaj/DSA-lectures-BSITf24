#include <iostream>
#include "sorted.h"
using namespace std;

sorted::sorted(int s)
{
    maxSize = s;
    arr = new int[maxSize];
    currentSize = 0;
}

sorted::~sorted()
{
    delete[] arr;
    arr = nullptr;
}
void sorted::display() const
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool sorted::isFull() const
{

    if (currentSize == maxSize)
    {
        return true;
    }
    return false;
}
bool sorted::isFull() const
{

    if (currentSize == maxSize)
    {
        return true;
    }
    return false;
}

int sorted::getLength() const
{
    return currentSize;
}

bool sorted::insert(int val)
{
    if (isFull()) //check if the list is full
        return false;

    int i = currentSize - 1;//start from the last element

    while (i >= 0 && arr[i] > val) //what is happening is the index of the last element, and we are comparing it with the value we want to insert, if the last element is greater than the value we want to insert, we need to shift it to the right, and we need to keep shifting until we find the correct position for the value we want to insert
    {
        arr[i + 1] = arr[i]; //here i is the index of the last element, and we are shifting it to the right, so we need to assign it to the index of the last element + 1, and then we need to decrement i to check the next element means we move last elmnt to forword and check the next one if it is greater than the value we want to insert or not, if it is greater than the value we want to insert, we need to shift it to the right as well, and we need to keep shifting until we find the correct position for the value we want to insert
        i--;
    }

    arr[i + 1] = val;
    currentSize++;
    return true;
}

bool sorted::deleteItem(int index, int &val)
{
    if (index < 0 || index >= currentSize)
        return false;

    val = arr[index];

    for (int i = index; i < currentSize - 1; i++) //here we are starting from the index of the element we want to delete, and we are shifting all the elements to the left, so we need to assign the next element to the current element, and we need to keep shifting until we reach the end of the list, and then we need to decrement the current size of the list
        arr[i] = arr[i + 1];

    currentSize--;
    return true;
}
bool sorted::deleteItem2(int index, int &val)
{
    return deleteItem(index, val);
}

// home work rule of three

sorted::sorted(const sorted &otherList)
{
    maxSize = otherList.maxSize;
    currentSize = otherList.currentSize;

    arr = new int[maxSize];
    for (int i = 0; i < currentSize; i++)
        arr[i] = otherList.arr[i];
}

sorted &sorted::operator=(const sorted &otherList)
{
    if (this != &otherList)
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }

        else
        {
            maxSize = otherList.maxSize;
            currentSize = otherList.currentSize;

            arr = new int[maxSize];
            for (int i = 0; i < currentSize; i++)
                arr[i] = otherList.arr[i];
        }
    }
    return *this;
}

bool sorted::operator==(const sorted &otherList) const
{
    if (currentSize != otherList.currentSize)
        return false;

    for (int i = 0; i < currentSize; i++)
        if (arr[i] != otherList.arr[i])
            return false;

    return true;
}


//below functon is order intensive the elemen in A is found soemwher in B but not in the same index, so we need to check all the elements in B to find the match for the element in A, and we need to keep track of the matched elements in B to avoid matching the same element in B with multiple elements in A, so we need to use a boolean array to keep track of the matched elements in B, and we need to initialize it with false, and when we find a match for an element in A, we need to set the corresponding index in the boolean array to true, and we need to check if the element in A is found in B or not, if it is not found in B, we need to return false, and if it is found in B, we need to continue checking the next element in A until we reach the end of A, and if we reach the end of A without finding any unmatched element in A, we need to return true
bool sorted::operator==(const sorted &otherList) const
{
    if (currentSize != otherList.currentSize)
        return false;

    bool matched[currentSize] = {false};

    for (int i = 0; i < currentSize; i++)
    {
        bool found = false;

        for (int j = 0; j < currentSize; j++)
        {
            if (!matched[j] && arr[i] == otherList.arr[j] && !found) //here we are checking if the element in A is found in B and it is not matched with any other element in A, if it is found in B and it is not matched with any other element in A, we need to set the corresponding index in the boolean array to true, and we need to set the found variable to true to indicate that we have found a match for the element in A, and we need to break the inner loop to check the next element in A, and if we reach the end of B without finding a match for the element in A, we need to return false, and if we find a match for the element in A, we need to continue checking the next element in A until we reach the end of A, and if we reach the end of A without finding any unmatched element in A, we need to return true
            {
                matched[j] = true;
                found = true;
            }
        }

        if (!found)//if we reach the end of B without finding a match for the element in A, we need to return false
            return false;
    }
    return true;
}

int sorted::removeAll(int val)
{
    int count = 0;
    int i = 0;

    while (i < currentSize)
    {
        if (arr[i] == val)
        {
            // shift elements left
            for (int j = i; j < currentSize - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            currentSize--;  // one element removed
            count++;
            // do NOT increment i → recheck same index
        }
        else
        {
            i++;  // move forward only if no deletion
        }
    }

    return count;
}
int sorted::removeAll3(int val)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i <=currentSize)
    {
        if (arr[i] != val)
        {
            arr[j] = arr[i];
            j++;
        }
        else
        {
            count++;
        }
        i++;
    }

    currentSize = j;
    return count;
}

   

int sorted::removeAll4(int val)
{
    int *newArr = new int[maxSize];
    int i = 0, j = 0;
    int count = 0;

    while (i < currentSize)
    {
        if (arr[i] != val)
        {
            newArr[j++] = arr[i];
        }
        else
        {
            count++;
        }
        i++;
    }

    delete[] arr;
    arr = newArr;
    currentSize = j;

    return count;
}

int sorted::removeAll4(int val)
{
    int *newArr = new int[maxSize];
    int i = 0, j = 0;
    int count = 0;

    while (i < currentSize)
    {
        if (arr[i] != val)
        {
            newArr[j++] = arr[i];
        }
        else
        {
            count++;
        }
        i++;
    }

    delete[] arr;
    arr = newArr;
    currentSize = j;

    return count;
}
bool sorted::search(int val, int &index) const
{
    int i = 0;
    while (i < currentSize)
    {
        if (arr[i] == val)
        {
            index = i;
            return true;
        }
        i++;
    }
    return false;
}

//binary search
bool sorted::binarySearch(int val, int &index) const
{
    int low = 0;
    int high = currentSize - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == val)
        {
            index = mid;
            return true;
        }
        else if (arr[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}
