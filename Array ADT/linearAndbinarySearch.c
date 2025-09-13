#include <stdio.h>

// ?? Function to perform linear search
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        // ?? If current element matches the target, return index
        if (arr[i] == element)
        {
            return i;
        }
    }
    // ?? If not found, return -1
    return -1;
}

// ?? Function to perform binary search (array must be sorted)
int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1; // ?? Set initial low and high bounds

    while (low <= high)
    {
        int mid = (low + high) / 2; // ?? Calculate the middle index

        if (arr[mid] == element)
        {
            return mid; // ?? Element found at mid
        }

        if (arr[mid] < element)
        {
            low = mid + 1; // ?? Search in right half
        }
        else
        {
            high = mid - 1; // ?? Search in left half
        }
    }

    // ?? If not found, return -1
    return -1;
}

int main()
{
    // ?? Unsorted array for linear search
    int arr[] = {1, 3, 5, 56, 4, 25, 2};
    int size = sizeof(arr) / sizeof(int); // ?? Calculate number of elements
    int element = 56; // ?? Element to search
    int searchIndex = linearSearch(arr, size, element); // ?? Perform linear search
    printf("The element %d was found at index %d using linear search\n", element, searchIndex);

    // ?? Sorted array for binary search
    int arr1[] = {1, 3, 5, 56, 64, 73, 123, 444};
    int size1 = sizeof(arr1) / sizeof(int); // ?? Calculate number of elements
    int element1 = 444; // ?? Element to search
    int searchIndex1 = binarySearch(arr1, size1, element1); // ?? Perform binary search
    printf("The element %d was found at index %d using binary search\n", element1, searchIndex1);

    return 0;
}
