#include <iostream>
using namespace std;

int peakIndex(int arr[], int size)
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

    return s;
}

int main()
{

    int size = 11;
    int arr[size] = {6,7,8,9,10,11,12,1,2,3,4};//7

    // int size = 5;
    // int arr[size] = {2,3,4,5,1};//4

    // int size = 7;
    // int arr[size] = {7,8,9,1,2,3,4};//3



    int ans = peakIndex(arr, size);

    cout << "pivot element found on index : " << ans << endl;

    return 0;
}