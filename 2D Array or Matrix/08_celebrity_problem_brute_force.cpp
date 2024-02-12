#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &arr)
{
    int candidate = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[candidate][i] == 1)
            candidate = i;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (i != candidate && (arr[candidate][i] == 1 || arr[i][candidate] == 0))
            return -1;
    }

    return candidate;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int celeb = celebrity(arr);

    if (celeb != -1)
        cout << "Celebrity is person " << celeb << endl;
    else
        cout << "No celebrity found" << endl;

    return 0;
}

//optimized approach : using stack