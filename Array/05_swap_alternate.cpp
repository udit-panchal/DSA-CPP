#include<iostream>
using namespace std;

void swapAlternate(int *arr, int size)
{
    for(int i = 0; i<size; i+=2)
    {
        if(i+1 < size)
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};

    swapAlternate(arr, 5);

    for(int i = 0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}