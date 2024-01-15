#include <iostream>
using namespace std;

bool isSorted(int *arr, int n)
{

    if (n == 0 || n == 1)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
    {
        bool ans = isSorted(arr + 1, n - 1);
        return ans;
    }
}

int main()
{

    int arr[6] = {2, 4, 6, 9, 11, 13};
    // int arr[6] = {2, 4, 61, 9, 11, 13};
    int size = 6;

    bool ans = isSorted(arr, size);

    if(ans)
        cout<<"Array is Sorted "<<endl;
    else   
        cout<<"Array is not Sorted "<<endl;

    return 0;
}