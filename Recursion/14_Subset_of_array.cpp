#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case

    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(arr, output, index + 1, ans);

    // include
    int element = arr[index];
    output.push_back(element);
    solve(arr, output, index + 1, ans);
}

vector<vector<int>> subset(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr, output, index, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> ans = subset(arr);

    for (const auto& subset : ans) {
        cout << "{ ";
        for (const auto& element : subset) {
            cout << element << " ";
        }
        cout << "}" << std::endl;
    }

    return 0;
}