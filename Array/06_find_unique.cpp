#include <iostream>
#include <limits.h>
using namespace std;

int findUnique(int *arr, int size)
{
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }
}

int main()
{
    int n = 7;
    int arr[n] = {2, 3, 8, 6, 3, 6, 2};

    cout << findUnique(arr, n) << endl;

    // print(arr,n);

    return 0;
}