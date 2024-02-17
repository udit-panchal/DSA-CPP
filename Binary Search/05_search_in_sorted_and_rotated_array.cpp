#include <iostream>
using namespace std;

int search(int arr[], int size, int key, int s, int e)
{
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] <= key)
        {
            s = mid + 1;
        }
        else if (arr[mid] >= key)
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }

    return -1;
}

int findPivot(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;

    while (s < e)
    {

        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = (s + e) / 2;
    }

    int pivot = s;

    int ans = 0;
    if ((pivot <= key) && (key <= arr[size - 1]))
    {
        ans = search(arr, size, key, s, size);
    }
    else
    {
        ans = search(arr, size, key, 0, s - 1);
    }

    return ans;
}

int main()
{
    // int size = 9;
    // int arr[size] = {7,8,9,1,2,3,4,5,6};
    // int key = 5;

    // int size = 5;
    // int arr[size] = {4, 5, 1, 2, 3};
    // int key = 4;

    int size = 5;
    int arr[size] = {45, 56, 10, 21, 35};
    int key = 10;

    int ans = findPivot(arr, size, key);

    cout << "key found on index : " << ans << endl;
}