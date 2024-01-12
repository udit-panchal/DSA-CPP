#include <bits/stdc++.h>
using namespace std;

bool binarySearchInMatrix(vector<vector<int>> matrix, int target, int &a, int &b)
{
    // find row and col
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    //finding mid of the matrix
    int mid = start + (end - start) / 2;

    while (start < end)
    {

        int element = matrix[mid / col][mid % col];
        if (element == target)
        {
            //store index
            a = mid / col;
            b = mid % col;
            return 1;
        }
        //search from mid+1 to end
        if (element < target)
            start = mid + 1;
        //search from starting to mid-1
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }

    return 0;
}

int main()
{
    vector<vector<int>> matrix;

    matrix.push_back({1, 3, 5, 7});
    matrix.push_back({10, 11, 16, 20});
    matrix.push_back({23, 30, 34, 60});

    int target = 98;
    // int target = 1;
    // int target = 16;
    // int target = 60;

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

        You are given an m x n integer matrix matrix with the following two properties:

            - Each row is sorted in non-decreasing order.
            - The first integer of each row is greater than the last integer of the previous row.
            
        Given an integer target, return true if target is in matrix or false otherwise.

        You must write a solution in O(log(m * n)) time complexity.
    ----------------------------------------------------------------------------------------------

    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]

    ---------------------

    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    ----------------------------------------------------------------------------------------------
*/