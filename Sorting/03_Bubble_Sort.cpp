#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    #  Bubblle Sort
    ==============

    - comparison-based sorting algorithm.

    - treverse from left and compare adjacent elemets and the higher one is placed at right side
    - in this way, the largest element goes on his place
    - this process is then continued to find the second largest and place it and so on until the data is stored

    # The process can be visualized as follows:

    Round 1 : | 10 | 1  | 7  | 6  | 14 |  9 |
              | 1  | 10 | 7  | 6  | 14 |  9 |
              | 1  | 7  | 10 | 6  | 14 |  9 |
              | 1  | 7  | 6  | 10 | 14 |  9 |
              | 1  | 7  | 6  | 10 | 14 |  9 |
              | 1  | 7  | 6  | 10 | 9  \ 14 | // 14 is sorted

    Round 2 : | 1  | 7  | 6  | 10 | 9  \ 14 |
              | 1  | 7  | 6  | 10 | 9  \ 14 |
              | 1  | 6  | 7  | 10 | 9  \ 14 |
              | 1  | 6  | 7  | 10 | 9  \ 14 |
              | 1  | 6  | 7  | 9  \ 10 | 14 | // 10 , 14 is sorted

    Round 3 : | 1  | 6  | 7  |  9 \ 10 | 14 |
              | 1  | 6  | 7  |  9 \ 10 | 14 |
              | 1  | 6  | 7  |  9 \ 10 | 14 |
              | 1  | 6  | 7  \  9 | 10 | 14 | //9,10,14 sorted

    Round 4 : | 1  | 6  | 7  \  9 | 10 | 14 |
              | 1  | 6  | 7  \  9 | 10 | 14 |
              | 1  | 6  \ 7  |  9 | 10 | 14 | // 7,9,10,14 sorted

    Round 5 : | 1  | 6  \ 7  |  9 | 10 | 14 |
              | 1  \ 6  | 7  |  9 | 10 | 14 | // no need to sort first element all element sorted

    - In every ith round placing ith largest element on its right place

    size of array : 6
    no of round   : 5

    +--------------------------------+
    | Total round. : size_of_array-1 |
    +--------------------------------+


    # Time complexity
    ===============

    +-------------------------+
    | Best Case    : O(N)     |
    +-------------------------+
    | Average Case : O(N^2)   |
    +-------------------------+
    | Worst Case   : O(N^2)   |
    +-------------------------+

    # Space Complexity
    ================

    - No extra space will use

    +-------------------------+
    | SPACE COMPLEXITY : O(1) |
    +-------------------------+

    Advantages
    ==========
    - not require any additional memory space.
    - It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.

    Disadvantages
    =============
    - Bubble sort's time complexity makes it very slow for large data sets.

*/