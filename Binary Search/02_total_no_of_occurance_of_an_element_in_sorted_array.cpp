#include <iostream>
using namespace std;

int firstOccurance(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e - mid - 1;
        }

        mid = (s + e) / 2;
    }

    return ans;
}

int lastOccurance(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }

        mid = (s + e) / 2;
    }
    return ans;
}

int main()
{

    int size = 8;
    int arr[size] = {1, 2, 3, 3, 3, 3, 3, 5, 6};
    int key = 3;

    int ans = (lastOccurance(arr, size, key) - firstOccurance(arr, size, key)) + 1;

    cout << "total no. of occurance : " << ans << endl;

    return 0;
}