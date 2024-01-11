#include <bits/stdc++.h>
using namespace std;

void rowWiseSum(int arr[][3], int row, int col)
{
    int maxi = 0;
    int rowIndex = -1;

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }

        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
    }
    cout << "max sum : " << maxi<<endl;
    cout <<"row :"<<rowIndex<< endl;
}

int main()
{
    const int row = 3;
    const int col = 3;
    int arr[row][col] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    // int arr[row][col] = {{1, 2, 3}, {1, 3, 3}, {1, 5, 3}}; // 9 : 3

    rowWiseSum(arr, row, col);

    return 0;
}

/*

    question : finding largest sum in row or matrix

         1  2  3  = 6
         1  3  3  = 7
         1  5  3  = 9 => output     

    ----------------------------------------------------------------------------------------------

    Input : arr = {{0,1,2},{3,4,5},{6,7,8}};
    Output : 21

    ---------------------

    Input : arr = {{1,2,3},{1,3,3},{1,5,3}};
    Output : 9

    ----------------------------------------------------------------------------------------------

*/
