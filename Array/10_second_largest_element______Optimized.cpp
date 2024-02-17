#include<bits/stdc++.h>
using namespace std;

int solution(int arr[], int n)
{
    int largest = 0;
    int secondLargest = -1;

    for(int i = 0; i<n; i++)
    {
        if(largest < arr[i])
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] < largest)
        {
            secondLargest = arr[i];
        }
        
    }
    return secondLargest;

}

int main()
{
    int n = 5;
    int arr[5] = {70,30,65,20,60};    

    cout<<solution(arr, n)<<endl;

    return 0;
}