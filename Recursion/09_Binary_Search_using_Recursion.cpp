#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int start, int end)
{
    cout<<"Array : ";
    for(int i =start; i<end; i++)
        cout<<arr[i]<<" ";
     cout<<endl;
}

bool binarySearch(int *arr, int target, int start, int end)
{
    print(arr,start,end);
    // BASE CASE

    // Element not found
    if(start>end) return false;

    // calculate mid
    int mid = (start+end)/2;

    // Element found
    if(arr[mid] == target) return true;

    //target is bigger then mid element
    if(arr[mid] < target) return binarySearch(arr,target,mid+1, end);
    
    //if target is smaller then mid element
    else return binarySearch(arr,target,start,mid-1);

}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int target = 4;

    cout<<"target : "<<target<<endl<<endl;

    bool ans = binarySearch(arr,target,0,size);

    cout<<endl;
    if(ans)
        cout<<"found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}

/*

    Question : Binary Search

    Binary search in Recursion
    =========================

    we are using recursion 

    //base case
    
    check if the element not found at the end (start > end)

    initialize mid and store (start+end)/2

    check if the element found  (arr[mid] == target)

    // Recursive Case

    if (target is bigger then mid element)
    if(arr[mid] < target) return binarySearch(arr,target,mid+1, end);
    
    else (target is smaller then mid element)
    else return binarySearch(arr,target,start,mid-1);


*/