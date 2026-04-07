
#include "Task.h"
#include <iostream>
#include <string>
using namespace std;
UnsortedList::UnsortedList(int size)
{
    maxSize = size;
    arr = new int[maxSize];
    currentSize = 0;
}
UnsortedList::~UnsortedList()
{
    delete[] arr;
    arr = nullptr;
}
bool UnsortedList::isEmpty() const
{
    if (currentSize == 0)
        return true;
    else
        return false;
}
bool UnsortedList::isFull() const
{
    if (currentSize == maxSize)
        return true;
    else
        return false;
}
bool UnsortedList::insert(int val)
{
    if (!isFull())
    {
        arr[currentSize] = val;
        currentSize++;
        return true;
    }
    return false;
}

bool UnsortedList::deleteItem(int index, int &val) // order is not preserved; last element is swapped into the current index
{
    if (index < 0 || index >= currentSize)
        return false; //check if array is empty or index is out of range
    else
    {
        // move the val to the last element and decrease the size of the array by one eg [1,2,3,4] delete index 1 => [1,4,3] currentSize = 3
        val = arr[index];  //let say val = 2 and index = 1 
        arr[index] = arr[currentSize - 1];
        currentSize--;
        return true;

    }
}
bool UnsortedList::deleteItem2(int index, int &val)
{
    if (index < 0 || index >= currentSize)
    {
        return false;
    }
    else
    {
        val = arr[index];
        for (int i = index; i < currentSize; i++)
        {
            arr[i] = arr[i + 1];
        }
        currentSize--;
        return true;
    }
}

int UnsortedList::getLength() const
{
    return currentSize;
}

UnsortedList::UnsortedList(const UnsortedList &otherList)
{

    maxSize = otherList.maxSize;
    currentSize = otherList.currentSize;
    arr = new int[maxSize];
    for (int i = 0; i < currentSize; i++)
    {
        arr[i] = otherList.arr[i];
    }
}
UnsortedList &UnsortedList::operator=(const UnsortedList &otherList)
{
    if (this != &otherList) //self assignment check it checks if the object is being assigned to itself, which can lead to issues if we delete the array before copying the data. If it's the same object, we skip the assignment to avoid deleting the array and losing data. 
    {
        delete[] arr; // delete the existing array to avoid memory leaks
        arr = nullptr; // set arr to nullptr after deleting to avoid dangling pointer
        maxSize = otherList.maxSize;
        currentSize = otherList.currentSize;
        arr = new int[maxSize];
        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = otherList.arr[i];
        }
    }
    return *this;
}
bool UnsortedList::operator==(const UnsortedList &otherList) const
{ // check if the sizes of the two lists are different. If they are, we can immediately conclude that the lists are not equal and return false. This is a quick check that can save time if the lists have different sizes.
    if (currentSize != otherList.currentSize)
    {
        return false;
    }
    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] != otherList.arr[i])
        {
            return false;
        }
    }
    return true;
    //time complexity of this function is O(n) because in the worst case, we need to compare each element of the two lists to determine if they are equal. If the sizes of the lists are different, we can return false immediately, which is a constant time operation O(1). However, if the sizes are the same, we need to iterate through each element of the lists and compare them, which takes linear time O(n) where n is the number of elements in the lists. Therefore, the overall time complexity of this function is O(n).
}

// order is not preserved; last element is swapped into the current index
int UnsortedList::removeAll(int val)
{  //diffence bet the deleteItem and removeAll is that the deleteItem deletes one element at a time and removeAll deletes all the occurrences of the value in the array and returns the number of elements deleted.
    int count = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[currentSize - 1];
            currentSize--;
            count++;
            i--;
        }
    }
    return count;
}
int UnsortedList::removeAll2(int val)
{
    int count = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] == val)
        {
            for (int j = i; j < currentSize; j++)
            {
                arr[j] = arr[j + 1];
            }
            count++;
            i--;
        }
        currentSize--;
    }
    return count;
}
int UnsortedList::removeAll3(int val)//its third version of removeAll function which is more efficient than the previous two versions because it uses a single pass through the array to remove all occurrences of the value, rather than using nested loops. It maintains a write index to keep track of where to write the next non-matching value, and a count of how many values were removed. This approach minimizes the number of operations needed to remove all occurrences of the value. rather call it two pointer approach where one pointer is used to read the array and the other pointer is used to write the non-matching values back into the array. This way we can remove all occurrences of the value in a single pass through the array, which is more efficient than using nested loops.
{
    int count = 0;
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < currentSize; readIndex++) //loop goes through first pointer readIndex to read the array and second pointer writeIndex to write the non-matching values back into the array. If the current value at readIndex is not equal to val, it is written to the position indicated by writeIndex, and writeIndex is incremented. If the value matches val, it is skipped, and count is incremented to keep track of how many values were removed. After the loop, currentSize is updated to reflect the new size of the array after removing the occurrences of val.
    {
        if (arr[readIndex] != val)
        {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
        else
        {
            count++;
        }
    }
    currentSize = writeIndex;
    return count;
}
void UnsortedList::display() const
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int UnsortedList::removeAll4(int val) //this version of removeAll function creates a new array to store the non-matching values, and then replaces the original array with the new array. This approach can be more efficient than the previous versions because it avoids the need for nested loops or multiple passes through the array. It iterates through the original array once, copying only the non-matching values to the new array, and then updates the currentSize to reflect the new size of the array after removing the occurrences of val. Finally, it returns the count of how many values were removed.
{
    int *arrNew = new int[maxSize];
    int count = 0;
    int j = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] != val)
        {
            arrNew[j] = arr[i];
            j++;
          
        }
        else
        {
            count++;
        }
    }
    delete[] arr;
    arr = arrNew;
    currentSize = j;
    return count;
}

bool UnsortedList::search(int key) const
{

    bool flag = false;   
    int i = 0;
    while (i < currentSize && flag == false) //explanion of condition is that the loop continues as long as i is less than currentSize and flag is false. This means that the loop will iterate through the array until it either finds the key (setting flag to true) or reaches the end of the array (i >= currentSize). If the key is found, flag will be set to true, and the loop will exit early. If the key is not found by the time i reaches currentSize, the loop will exit, and flag will remain false, indicating that the key was not found in the array.
    {
        if (arr[i] == key)
        {
            flag = true;
        }
        i++;
    }
    return flag;
}


bool UnsortedList::getval(int index, int &val) const
{
    if (index < 0 || index >= currentSize)
    {
        return false;
    }

    val = arr[index]; // if the index is valid, the function assigns the value at the specified index in the array to the reference variable val and returns true. This allows the caller to retrieve the value at the given index if it exists, while also providing a way to indicate whether the retrieval was successful or not through the return value.
    return true; /* if the index is valid, the function assigns the value at the specified index in the array to the reference variable val and returns true. This allows the caller to retrieve the value at the given index if it exists, while also providing a way to indicate whether the retrieval was successful or not through the return value. 
    it does not return the value directly because the function is designed to return a boolean indicating success or failure of the retrieval operation. By using a reference parameter (val), the function can output the retrieved value while still returning a boolean to indicate whether the operation was successful. This allows for better error handling, as the caller can check the return value to determine if the retrieval was successful before using the output value. */




}


 