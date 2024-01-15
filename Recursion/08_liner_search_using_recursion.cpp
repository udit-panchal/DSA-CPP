#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int size)
{
    cout<<"Array : ";
    for(int i =0; i<size; i++)
        cout<<arr[i]<<" ";
     cout<<endl;
}

bool linerSearch(int *arr, int size, int target)
{

    print(arr,size);

    //BASE CASE :

    // check size of element
    if(size == 0)
        return false;

    // check first element is equal to target
    if(arr[0] == target)
        return true;

    //RECURSIVE CASE : 
    return linerSearch(arr+1, size-1, target);
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    int target = 4;

    cout<<"target : "<<target<<endl<<endl;


    bool ans = linerSearch(arr, 5, target);

    cout<<endl;
    if(ans)
        cout<<"found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}

/*

    Question : Liner Search

    Liner Search is a sequestial search algoritham that starts from arr[0] and end from arr[n-1] 
    
    where it check if the key is equal to arr[i] if yes then return 

    liner search in Recursion
    =========================

    we are using recursion 

    //base case
    
    if array is empty (size == 0) return false;
    if first element of the array is equal to target (arr[0] == target).

    // Recursive Case

    passing "arr+1" next pointer to array and "size-1" in each iteration.

    return linerSearch(arr+1, size-1, target)

*/