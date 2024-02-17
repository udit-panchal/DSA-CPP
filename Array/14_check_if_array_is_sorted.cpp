#include<iostream>
using namespace std;

bool is_sorted(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i] >= arr[i-1])
        {
            
        }
        else{
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 5;
    int arr[5] = {1,2,4,4,5};

    cout<<is_sorted(arr, n)<<endl;



    return 0;
}