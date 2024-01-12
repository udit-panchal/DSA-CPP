#include <bits/stdc++.h>
using namespace std;

// vector<int> shuffleArray(vector<int> nums, int n)
// {
//     vector<int> result;

//     int i = 0;
//     int j = n;

//     while (j <2* n)
//     {
//         result.push_back(nums[i]);
//         result.push_back(nums[j]);
//         i++;
//         j++;
//     }

//     return result;
// }

vector<int> shuffleArray(vector<int> nums, int n)
{
    vector<int> result;

    for(int i = 0; i<n*2; i++)
    {
        result.push_back(nums[i]);
        result.push_back(nums[i+n]);

    }

    return result;
}

int main()
{
    vector<int> array = {2, 5, 1, 3, 4, 7};
    int n = 3;

    vector<int> ans = shuffleArray(array, n);

    for (int i = 0; i < 2 * n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}