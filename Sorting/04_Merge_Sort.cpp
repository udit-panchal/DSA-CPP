#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy Values
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++)
        first[i] = arr[mainArrayIndex++];

    for (int i = 0; i < len2; i++)
        second[i] = arr[mainArrayIndex++];

    // merge 2 Sorted Arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];

        else
            arr[mainArrayIndex++] = second[index2++];
    }

    while (index1 < len1)
        arr[mainArrayIndex++] = first[index1++];

    while (index2 < len2)
        arr[mainArrayIndex++] = second[index2++];

    delete []first;
    delete []second;
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    // left part
    mergeSort(arr, start, mid);

    // right part
    mergeSort(arr, mid + 1, end);

    // merge
    merge(arr, start, end);
}

int main()
{
    int arr[] = {54, 7, 3, 98, 4, 213, 97 , 1};
    int size = 8;

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*

    #  Merge Sort
    ==============

    - Divide and Conquer algorithm.

    - It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.

    - The input array is divided into two halves.
    - The process is repeated for the two halves until we reach arrays of size 1.
    - The process of merging these sub-arrays starts from the highest to the lowest order.

    # The process can be visualized as follows:

              38 27 43 03 | 09 82 10
                    /            \
             38 27|43 03     09 82|10     Round 1
              /      \        /     \     
           38|27   43|03   09|82    10    Round 2
           /  \    /  \    /  \     |     
         38   27  43  03  09  82    10    Round 3
           \  /    \  /    \  /     |     
          27 38   03 43    09 82   10     Round 4
            \      /        \      /      
            03 27 38 43     09 10 82      Round 5
                \             /           
             03 09 10 27 38 43 82         Round 6

    size of array : 6
    no of round   : 5

    +--------------------------------+
    | Total round. : size_of_array-1 |
    +--------------------------------+


    # Time complexity
    ===============

    +----------------------------+
    | Best Case    : O(n log n)  |
    +----------------------------+
    | Average Case : O(n log n)  |
    +----------------------------+
    | Worst Case   : O(n log n)  |
    +----------------------------+

    # Space Complexity
    ================

    - extra space will use

    +-------------------------+
    | SPACE COMPLEXITY : O(n) |
    +-------------------------+

    Advantages
    ==========
    - Merge Sort is efficient and can handle large datasets.
    - It can handle linked lists and sort them.
    - Merge Sort is stable as it maintains the relative order of equal sort items.

    Disadvantages
    =============
    - It requires extra space for the 'left' and 'right' arrays.
    - It has a high time complexity compared to other sorting algorithms like QuickSort.

    Characteristics
    ===============

    - It's a stable sort algorithm.
    - It has a time complexity of O(n log n).
    - It has a space complexity of O(n).



*/