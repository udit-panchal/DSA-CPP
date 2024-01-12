#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> &arr)
{

    vector<int> ans;
    int row = arr.size();    // size of row in vector of vector
    int col = arr[0].size(); // size of col in vector of vector

    int count = 0;
    int total = row * col;

    // index initialization

    int startingRow = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;
    int startingCol = 0;

    while (count < total)
    {
        //      (I). print starting row
        for (int index = startingCol; (count < total) && (index <= endingCol); index++)
        {
            ans.push_back(arr[startingRow][index]);
            count++;
        }
        startingRow++;

        //      (II). print ending column
        for (int index = startingRow; (count < total) && (index <= endingRow); index++)
        {
            ans.push_back(arr[index][endingCol]);
            count++;
        }
        endingCol--;

        //      (III). print ending row.
        for (int index = endingCol; (count < total) && (index >= startingCol); index--)
        {
            ans.push_back(arr[endingRow][index]);
            count++;
        }
        endingRow--;

        //      (IV). print starting column
        for (int index = endingRow; (count < total) && (index >= startingRow); index--)
        {
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main()
{
    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> arr;

    arr.push_back({1, 2, 3});
    arr.push_back({4, 5, 6});
    arr.push_back({7, 8, 9});

    vector<int> result = spiralPrint(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*

    
                                  |         
     |→ → → → → → → → → → → → +   | ←- R0   
                              ↓   |         
      + → → → → → → → → → +   ↓   | ←- R1   
      ↑                   ↓   ↓   |         
      ↑  |← ← ← ← ← ← ← ← +   ↓   | ←- R2   
      ↑                       ↓   |         
      + ← ← ← ← ← ← ← ← ← ← ← +   | ←- R3   
     -----------------------------+         
      ↑   ↑   ↑   ↑   ↑   ↑   ↑             
      C0  C1  C2  C3  C4  C5  C6            


    question : spiral print
    link : https://leetcode.com/problems/spiral-matrix/

    ----------------------------------------------------------------------------------------------

    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]

    ---------------------

    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    ----------------------------------------------------------------------------------------------
*/