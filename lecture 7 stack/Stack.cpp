#include "Stack.h"
#include <iostream>
#include <cstring>
using namespace std;

Stack::Stack()
{
    topIndex = -1;
}

bool Stack::push(int value)
{
    if (isFull())
    {
        return false;
    }
    arr[++topIndex] = value;
    return true;
}

bool Stack::pop()
{
    if (isEmpty())
    {
        return false;
    }
    topIndex--;
    return true;
}

int Stack::peek()
{
    if (isEmpty())
    {
        return -1;
    }
    return arr[topIndex];
}

bool Stack::isEmpty()
{
    return topIndex == -1;
}

bool Stack::isFull()
{
    return topIndex == MAX_SIZE - 1;
}

void Stack::clear()
{
    topIndex = -1;
}

void Stack::reverseArray(int arr[], int size)
{
    Stack s;
    for (int i = 0; i < size; i++)
    {
        s.push(arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = s.peek();
        s.pop();
    }
}

bool Stack::checkBalancedParentheses(const char expr[])
{ // this functions arathsibalnce refer to parenthesize expression i.e the number of opening parentheses should be equal to the number of closing parentheses and they should be in the correct order. For example, the expression "{(a+b)*(c-d)}" is balanced, while the expression "{(a+b)*(c-d]" is not balanced because it has a mismatched closing bracket.
    Stack s;
    int len = strlen(expr);

    for (int i = 0; i < len; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            s.push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (s.isEmpty())
            {
                return false;
            }
            char top = s.peek();
            s.pop();

            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s.isEmpty();
}

void Stack::sortAscending() // this function sorts the elements of the stack in ascending order using an auxiliary array. It repeatedly pops elements from the stack and compares them with the elements in the auxiliary array to maintain a sorted order. Finally, it pushes the sorted elements back onto the stack.
{
    if (isEmpty()) // check if the stack is empty, if it is, there is nothing to sort, so we return immediately.
        return;

    int temp[MAX_SIZE];
    int tempIndex = -1; // This variable keeps track of the top index of the auxiliary array temp. It starts at -1, indicating that the array is initially empty. As we push elements onto temp, we increment tempIndex to point to the current top element of the array.

    while (!isEmpty()) // our original stack is not empty, we enter the loop to sort the elements.
    {
        int current = peek(); // We store the top element of the stack in the variable current. This is the element we want to place in the correct position in the auxiliary array temp.
        pop();                // We pop the top element from the stack since we have stored it in current and we will be comparing it with the elements in temp.

        while (tempIndex >= 0 && temp[tempIndex] > current) // We compare current with the top element of temp (temp[tempIndex]). If the top element of temp is greater than current, it means that current should be placed below it in the sorted order. Therefore, we push the top element of temp back onto the original stack and decrement tempIndex to move down the auxiliary array.

        // example: if current is 3 and the top of temp is 5, we push 5 back onto the stack and decrement tempIndex to check the next element in temp. This process continues until we find the correct position for current in temp or until temp is empty.
        {
            push(temp[tempIndex]); // We push the top element of temp back onto the original stack because it is greater than current and should be placed above it in the sorted order.
            tempIndex--;           // We decrement tempIndex to move down the auxiliary array and check the next element in temp.
        }
        temp[++tempIndex] = current; // Once we have found the correct position for current in temp (when temp is empty or when the top element of temp is less than or equal to current), we place current in that position by incrementing tempIndex and assigning current to temp[tempIndex].
    }

    while (tempIndex >= 0) // After we have sorted all the elements in temp, we need to push them back onto the original stack. We do this by iterating through temp from the top (tempIndex) down to 0 and pushing each element back onto the stack until temp is empty.
    {
        push(temp[tempIndex]);
        tempIndex--;
    }
}

void Stack::sortDescending()
{
    if (isEmpty())
        return;

    int temp[MAX_SIZE];
    int tempIndex = -1;

    while (!isEmpty())
    {
        int current = peek();
        pop();

        while (tempIndex >= 0 && temp[tempIndex] < current)
        {
            push(temp[tempIndex]);
            tempIndex--;
        }
        temp[++tempIndex] = current;
    }

    while (tempIndex >= 0)
    {
        push(temp[tempIndex]);
        tempIndex--;
    }
}

int Stack::findMin()
{
    if (isEmpty())
    {
        return -1;
    }

    int min = arr[0];
    for (int i = 1; i <= topIndex; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

void Stack::sortUsingExtraStack()
{
    Stack extraStack;

    while (!isEmpty())
    {
        int temp = peek();
        pop();

        while (!extraStack.isEmpty() && extraStack.peek() > temp)
        {
            push(extraStack.peek());
            extraStack.pop();
        }
        extraStack.push(temp);
    }

    while (!extraStack.isEmpty())
    {
        push(extraStack.peek());
        extraStack.pop();
    }
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = topIndex; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Stack::mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        int i = left, j = mid + 1, k = 0;
        int temp[MAX_SIZE];

        while (i <= mid && j <= right)
        {
            if (arr[i] < arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }

        while (j <= right)
        {
            temp[k++] = arr[j++];
        }

        for (i = left, k = 0; i <= right; i++, k++)
        {
            arr[i] = temp[k];
        }
    }
}

void Stack::bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Stack::insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Stack::selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

bool Stack::isSortedAscending()
{
    for (int i = 0; i < topIndex; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool Stack::isSortedDescending()
{
    for (int i = 0; i < topIndex; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool Stack::isPalindrome()
{
    int left = 0;
    int right = topIndex;

    while (left < right)
    {
        if (arr[left] != arr[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void Stack::sortStackUsingRecursion()
{
    if (isEmpty())
        return;

    int temp = peek();
    pop();

    sortStackUsingRecursion();

    Stack tempStack;
    while (!isEmpty() && peek() > temp)
    {
        tempStack.push(peek());
        pop();
    }
    push(temp);
    while (!tempStack.isEmpty())
    {
        push(tempStack.peek());
        tempStack.pop();
    }
}

void Stack::reverseStackUsingRecursion()
{
    if (isEmpty())
        return;

    int temp = peek();
    pop();

    reverseStackUsingRecursion();

    Stack tempStack;
    while (!isEmpty())
    {
        tempStack.push(peek());
        pop();
    }
    push(temp);
    while (!tempStack.isEmpty())
    {
        push(tempStack.peek());
        tempStack.pop();
    }
}
void Stack::sortStackUsingMergeSort()
{
    if (isEmpty())
        return;

    int temp[MAX_SIZE];
    for (int i = 0; i <= topIndex; i++)
    {
        temp[i] = arr[i];
    }
    mergeSort(temp, 0, topIndex);
    for (int i = 0; i <= topIndex; i++)
    {
        arr[i] = temp[i];
    }
}

void Stack::sortStackUsingBubbleSort()
{
    if (isEmpty())
        return;

    int temp[MAX_SIZE];
    for (int i = 0; i <= topIndex; i++)
    {
        temp[i] = arr[i];
    }
    bubbleSort(temp, topIndex + 1);
    for (int i = 0; i <= topIndex; i++)
    {
        arr[i] = temp[i];
    }
}

void Stack::sortStackUsingInsertionSort()
{
    if (isEmpty())
        return;

    int temp[MAX_SIZE];
    for (int i = 0; i <= topIndex; i++)
    {
        temp[i] = arr[i];
    }
    insertionSort(temp, topIndex + 1);
    for (int i = 0; i <= topIndex; i++)
    {
        arr[i] = temp[i];
    }
}

void Stack::sortStackUsingSelectionSort()
{
    if (isEmpty())
        return;

    int temp[MAX_SIZE];
    for (int i = 0; i <= topIndex; i++)
    {
        temp[i] = arr[i];
    }
    selectionSort(temp, topIndex + 1);
    for (int i = 0; i <= topIndex; i++)
    {
        arr[i] = temp[i];
    }
}

void Stack::nextGreaterElement(int arr[], int size) //in thtis function, we use a stack to keep track of the elements for which we are trying to find the next greater element. We iterate through the input array from right to left, and for each element, we pop elements from the stack until we find an element that is greater than the current element or until the stack is empty. If we find a greater element, we store it in the result array; otherwise, we store -1. Finally, we push the current element onto the stack to be used for future comparisons.    
{
    Stack s;
    int result[MAX_SIZE];

    for (int i = size - 1; i >= 0; i--)
    {
        while (!s.isEmpty() && s.peek() <= arr[i])
        {
            s.pop();
        }
        result[i] = s.isEmpty() ? -1 : s.peek();
        // no in ternory operator
        //  if (s.isEmpty())
        //  {
        //      result[i] = -1;
        //  }
        //  else
        //  {
        //      result[i] = s.peek();                    }
        s.push(arr[i]);
    }

    cout << "Next greater elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
