#include<iostream>
using namespace std;

int secondLargest(int arr[],int n)
{
    int largest = 0;
    for(int i = 0; i<n; i++)
    {
        if(largest < arr[i])
        {
            largest = arr[i];
        }
    }

    int scndLargest = 0;

    for(int i = 0; i<n; i++)
    {
        if(arr[i] > 0 && arr[i] < largest)
        {
            scndLargest = arr[i];
        }
    }

    return scndLargest;

}

int main()
{
    int n= 5 ;

    int arr[5] = {50,30,10,20,40};

    cout<<secondLargest(arr, n)<<endl;

    return 0;
}