#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[mini])
                mini = j;
        swap(arr[mini], arr[i]);
    }
}

int main()
{

    int arr[] = {64, 25, 12, 22, 11};
    int size = 5;

    selectionSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*

 #  Selection Sort
    ==============

    - In selection sort list is divided into 2 parts (sorted and unsorted).
    - initially sorted part is empty and entire list is unsorted.

    - In selection sort the smallest element is selected from unsorted array & swapped with leftmost elements and that element added to sorted list. this process contine moving untile unsorted array become size of 1.

               | 64,25,12,22,11

    Round 1 :  11 | 25, 12, 22, 64
    Round 2 :  11, 12 | 25, 22, 64
    Round 3 :  11, 12, 22 | 25, 64
    Round 4 :  11, 12, 22, 25 | 64

    size of array : 5
    no of round   : 4

    +--------------------------------+
    | Total round. : size_of_array-1 |
    +--------------------------------+

 #  Time complexity
    ===============

    - one loop from starting to size-1;
    - another loop inside first loop for comparing assumed element to another smaller element

    O(N) + O(N) = O(N*N) = O(N^2);

    +--------------------------+
    | TIME COMPLEXITY : O(N^2) |
    +--------------------------+

 #  Space Complexity
    ================

    - No extra space will use

    +-------------------------+
    | SPACE COMPLEXITY : O(1) |
    +-------------------------+

 #  Advantage
    =========
    - simple and easy to understand.
    - better for small array.

 #  Disadvantage
    ============
    - not suitable for large data set as it's not efficient in terms of time complexity.
    - time complexity of O(N^2) in best, average and wrost case.
*/