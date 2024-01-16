#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int arr[] = {64, 25, 12, 22, 11};
    int size = 5;

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*

 #  Selection Sort
    ==============

    - simple comparison-based sorting algorithm.
    - it works similarly to the way you sort playing cards in your hands

    # The process can be visualized as follows:

    - Consider the first element of the input as a sorted segment.
    - Remove the next unsorted element and repeatedly compare it with the sorted elements in the sorted segment.
    - If the element is smaller than the sorted element, remove the sorted element and all elements to its right from the sorted segment.
    - Insert the unsorted element into the sorted segment before the sorted element that was removed or into the sorted segment itself if it was the first element to be removed.
    - Repeat the steps for each unsorted element until there are no more unsorted elements left

                4 | 3, 2, 10, 12, 1, 5, 6

    Round 1 :  3, 4 | 2, 10, 12, 1, 5, 6 
    Round 2 :  2, 3, 4 | 10, 12, 1, 5, 6
    Round 3 :  2, 3, 4, 10 | 12, 1, 5, 6
    Round 4 :  2, 3, 4, 10, 12 | 1, 5, 6
    Round 5 :  1, 2, 3, 4, 10, 12 | 5, 6
    Round 6 :  1, 2, 3, 4, 5, 10, 12 | 6
    Round 7 :  1, 2, 3, 4, 5, 6, 10, 12 | //Now Sorted


    size of array : 8
    no of round   : 7

    +--------------------------------+
    | Total round. : size_of_array-1 |
    +--------------------------------+

 #  Time complexity
    ===============

    +-------------------------+
    | Best Case    : O(N^2)   |
    +-------------------------+
    | Average Case : O(N^2)   |
    +-------------------------+
    | Wrost Case   : O(N^2)   |
    +-------------------------+

 #  Space Complexity
    ================

    - No extra space will use

    +-------------------------+
    | SPACE COMPLEXITY : O(1) |
    +-------------------------+

 #  Characteristics
    ===============
    - Simple and easy to understand.
    - Better for small array.
    - It is appropriate for data set that are already partially sorted.

    - Adaptive & Stable
*/