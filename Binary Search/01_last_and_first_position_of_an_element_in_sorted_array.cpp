#include <iostream>
using namespace std;

int firstOccurance(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }

    return ans;
}

int lastOccurance(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }

    return ans;
}

int main()
{
    int size = 9;
    int even[size] = {2, 4, 6, 8, 8, 8, 10, 13, 15};
    int key = 8;

    // int odd[5] = {3, 8, 11, 14, 16};

    // cout<<binarySearch(even, 6, 12)<<endl;
    int ans = firstOccurance(even, size, key);
    int ans2 = lastOccurance(even, size, key);
    cout << " First occurence of " << key << "is : " << ans<<endl;
    cout << " Last occurence of " << key << "is : " << ans2<<endl;
}