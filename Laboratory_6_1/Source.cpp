#include <iostream>
#include "Array.h"
#include <time.h>

Array returnDynamicArray(int arr[], const int size);

int main()
{
    srand((unsigned)time(NULL));
    const int size = 50;
    int arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = -50 + rand() % int(50 - (-50) + 1);  //filled the array( -50 ?? 50)

    Array taskArray = returnDynamicArray(arr, size);
    taskArray.Print();

    taskArray.Back();
    taskArray.Print();

    taskArray.Task();
    taskArray.Print();

    return 0;
}
Array returnDynamicArray(int arr[], const int size)
{
    Array dynamicArray = Array(size);

    for (int i = 0; i < size; i++)
        dynamicArray[i] = arr[i];

    return dynamicArray;
}