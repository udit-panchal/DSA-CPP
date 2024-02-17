#include <iostream>
using namespace std;



void merge(int arr1[], int size1, int arr2[], int size2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];

        else
            arr3[k++] = arr2[j++];
    }

    while (i < size1)
        arr3[k++] = arr1[i++];

    while (j < size2)
        arr3[k++] = arr2[j++];
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6};
    int arr3[] = {};

    merge(arr1, 5, arr2, 3, arr3);

    print(arr3, 8);

    return 0;
}