#include<iostream>
using namespace std;

int findDuplicates(int *arr, int n)
{
    int ans = 0;

    for(int i = 0; i<n; i++)
    {
        ans = ans ^ arr[i];
    }

    for(int i = 1; i<n; i++)
    {
        ans = ans ^ i ;
    }

    cout<<ans<<endl;
     
    return ans;
}

void print(int *arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n = 7;
    int arr[n] = {1,2,3,4,5,6,3};


    findDuplicates(arr,7);

    // print(arr, n);


    return 0;
}
