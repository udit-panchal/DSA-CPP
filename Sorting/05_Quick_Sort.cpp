#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
    // make first element pivot
    int pivot = arr[start];
    int count = 0;

    // count actual index of pivot element
    for (int i = start + 1; i <= end; i++)
        if (pivot >= arr[i])
            count++;

    // place first element at it's right place
    int pivotActualIndex = start + count;
    swap(arr[pivotActualIndex], arr[start]);

    // for left and right part
    int i = start, j = end;

    while (i < pivotActualIndex && j > pivotActualIndex)
    {
        // for element smaller then pivot in left part
        while (arr[i] <= pivot)
            i++;

        // for element bigger then pivot in right part
        while (arr[j] > pivot)
            j--;

        // swap element
        if (i < pivotActualIndex && j > pivotActualIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotActualIndex;
}

void quickSort(int arr[], int start, int end)
{
    // base case
    if (start >= end)
        return;
    
    int p = partition(arr, start, end);

    // sorting left part
    quickSort(arr, start, p - 1);

    // sorting right part
    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50};
    int size = 6;

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*

    #  Merge Sort
    ==============

    - Divide and Conquer algorithm.

    - Use a recursive function (say quickSort) to initialize the function.
    - Call the partition function to partition the array and inside the partition function do the following
        - Take the first element as pivot and initialize and iterator k = high.
        - Iterate in a for loop from i = high to low+1:
            - If arr[i] is greater than pivot then swap arr[i] and arr[k] and decrement k.
        - After the iteration is swap the pivot with arr[k].
        - Return k-1 as the point of partition.
    - Now recursively call quickSort for the left half and right half of the partition index.

    # The process can be visualized as follows:

              10  80  30  90  40  50

              10  30  40  50  80  90    Sorted Array
                    /            \
             10  30  40      50  80  90     Partitioning Steps

             10  30  40      50  80  90     Recursive Sorting Steps
                  \              /
                10 30 40 50 80 90




    # Time complexity
    ===============

    +----------------------------+
    | Best Case    : O(n log n)  |
    +----------------------------+
    | Average Case : O(n log n)  |
    +----------------------------+
    | Worst Case   : O(n^2)      |
    +----------------------------+

    # Space Complexity
    ================

    - no extra space will use

    +-------------------------+
    | SPACE COMPLEXITY : O(1) |
    +-------------------------+

    Advantages
    ==========
    - doesn't require additional memory for temporary storage.
    - Quicksort is often faster in practice compared to other sorting algorithms like bubble sort and insertion sort.

    Disadvantages
    =============
    - The worst-case time complexity of quicksort is O(n^2) when the pivot selection consistently results in an imbalanced partition.
    - not a stable sorting algorithm.
    - Quicksort's performance degrades when applied to linked lists, mainly due to its reliance on random access



*/