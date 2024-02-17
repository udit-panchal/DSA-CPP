#include <iostream>
using namespace std;

int peakIndex(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while (start < end)
    {

        if ((arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1]))
        {
            return mid;
        }

        else if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }

        else if (arr[mid] > arr[mid + 1])
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    // while(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])

    return -1;
}

int main()
{

    // int size = 4;
    // int arr[size] = {3, 4, 5, 1};

    // int size = 5;
    // int arr[size] = {1, 3, 5, 4, 2};

    int size = 7;
    int arr[size] = {2, 3, 4, 7, 5, 3, 2};

    int ans = peakIndex(arr, size);

    cout << "peak index of the mountaion array is : " << ans << endl;

    return 0;
}