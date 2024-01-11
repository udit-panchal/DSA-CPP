#include <iostream>
using namespace std;

void rowWiseSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

void colWiseSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
}

int main()
{
    const int row = 3;
    const int col = 3;
    // int arr[row][col] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    int arr[row][col] = {{1,2,3},{1,2,3},{1,2,3}};;

    cout << "Row wise sum : ";
    rowWiseSum(arr, row, col);
    cout << endl;
    cout << "Col wise sum : ";
    colWiseSum(arr, row, col);

    return 0;
}

/*

    question : row and col wise sum in matrix

         1  2  3
         1  2  3
         1  2  3

         6,6,6

    ----------------------------------------------------------------------------------------------

    Input : arr = {{0,1,2},{3,4,5},{6,7,8}};
    Output : row => {3,12,21} || {9,12,15} => Col

    ---------------------

    Input : arr = {{1,2,3},{1,2,3},{1,2,3}}};
    Output : row => {3,12,21} || {3,6,9} => Col

    ----------------------------------------------------------------------------------------------
    Approach

    -
    ----------------------------------------------------------------------------------------------

*/
