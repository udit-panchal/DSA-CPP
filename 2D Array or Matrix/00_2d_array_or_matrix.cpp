#include <iostream>
using namespace std;

/*
    -x-x-x-    Basics of 2D-Array or Matrix    -x-x-x-
               ============================


    A multidimensional array is basically an array of arrays.

    (I) for initialize 2d array

        dataType arrayName[row][col]

        int arr[3][3];
        int arr[3][3] = {{0,1,2},{3,4,5},{6,7,8}}
        int arr[3][3] = {{0,1,2,3,4,5,6,7,8}}

    (II) for accessing array input output
        - To access an element of a two-dimensional array, you must specify the index number of both the row and column.

        arrayName[row][col]

        cin>> arrayName[row][col]

        cin>>arr[2][3]


    2D Array or Matrix of 3x3

     -------------
     | 0 | 1 | 2 |   ←- R0
     -------------
     | 3 | 4 | 5 |   ←- R1
    -------------
     | 6 | 7 | 8 |   ←- R2
     -------------
       ↑   ↑   ↑
      C0  C1  C2


-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x

*/

bool isPresent(int arr[][3], int target, int rSize, int cSize)
{
    for (int row = 0; row < rSize; row++)
        for (int col = 0; col < cSize; col++)
            if (arr[row][col] == target)
                return 1;

    return 0;
}

int main()
{

    // creating 2d Array
    // int arrayName[row][column];
    // int arr[3][3];
    // int arr[3][3] = {0,1,2,3,4,5,6,7,8};
    int arr[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    // input -> row wise input
    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 3; col++)
    //     {
    //         cin >> arr[row][col];
    //     }
    // }

    // input -> col wise input
    // for (int row= 0; row< 3; row++)
    // {
    //     for (int col= 0; col< 3; col++)
    //     {
    //         cin >> arr[col][row]];
    //     }
    // }

    // output -> row wise output
    // cout << "row wise output" << endl;
    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 3; col++)
    //     {
    //         cout << arr[row][col] << " ";
    //     }
    //     cout << endl;
    // }

    // output -> col wise output
    // cout<<"col wise output"<<endl;
    // for (int row= 0; row< 3; row++)
    // {
    //     for (int col= 0; col< 3; col++)
    //     {
    //         cout << arr[col][row]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout << "enter the element to search 0 - 8 : ";
    int target;
    cin >> target;

    if (isPresent(arr, target, 3, 3))
        cout << "Element found" << endl;
    else
        cout << "not found" << endl;

    return 0;
}