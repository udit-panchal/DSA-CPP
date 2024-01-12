#include <bits/stdc++.h>
using namespace std;

bool binarySearchInMatrix(vector<vector<int>> matrix, int target, int &a, int &b)
{
    // find row and col
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    // finding mid of the matrix
    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];

        if (element == target)
        {
            a=rowIndex;
            b=colIndex;
            return 1;
        }

        if (element < target)
            rowIndex++;

        else
            colIndex--;
    }

    return 0;
}

int main()
{
    vector<vector<int>> matrix;

    matrix.push_back({1, 4, 7, 11, 15});
    matrix.push_back({2, 5, 8, 12, 19});
    matrix.push_back({3, 6, 9, 16, 22});
    matrix.push_back({10, 13, 14, 17, 24});
    matrix.push_back({8, 21, 23, 26, 30});

    int target = 21;
    // int target = 8;
    // int target = 16;
    // int target = 4;

    int a = -1;
    int b = -1;

    bool result = binarySearchInMatrix(matrix, target, a, b);

    if (result == 1)
        cout << "Element Found on : index[" << a << "][" << b << "]";
    else
        cout << "Not Found" << endl;

    return 0;
}

/*

    question : search in 2d matrix
    link : https://leetcode.com/problems/search-a-2d-matrix/

    ----------------------------------------------------------------------------------------------
    Statement :

    Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

        - Integers in each row are sorted in ascending from left to right.
        - Integers in each column are sorted in ascending from top to bottom.

    ----------------------------------------------------------------------------------------------

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true

    ---------------------

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false

    ----------------------------------------------------------------------------------------------
*/