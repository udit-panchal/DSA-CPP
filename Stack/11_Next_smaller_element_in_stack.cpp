#include <bits/stdc++.h>
using namespace std;

vector<int> next_Smaller_Element(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    // vector<int> arr = {3,2,1,4};
    // int size = 4;

    vector<int> arr = {5, 7, 9, 2, 4, 6};
    int size = 6;

    vector<int> result = next_Smaller_Element(arr, size);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << result[i] << " ";
    }
}