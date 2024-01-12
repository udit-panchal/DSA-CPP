#include <bits/stdc++.h>
using namespace std;

bool binarySearchInMatrix(vector<vector<int>> matrix, int target, int &a, int &b)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    int mid = start + (end - start) / 2;

    while (start < end)
    {
        int element = matrix[mid / col][mid % col];
        if (element == target)
        {
            a = mid/col;
            b = mid%col;
            return 1;

        }

        if (element < target)
            start = mid + 1;
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

    int target = 16;

    int a = -1;
    int b = -1;

    bool result = binarySearchInMatrix(matrix, target, a, b);

    if (result == 1)
    {
        cout << "Element Found on : index[" << a << "][" << b << "]";
    }

    return 0;
}