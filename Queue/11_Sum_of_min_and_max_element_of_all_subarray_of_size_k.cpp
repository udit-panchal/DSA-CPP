#include <bits/stdc++.h>
using namespace std;

int first_negative_in_k_size_window(vector<int> arr, int k)
{
    int n = arr.size();
    deque<int> maxi(k);
    deque<int> mini(k);
    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    ans = ans + arr[maxi.front()] + arr[mini.front()];
    for (int i = k; i < n; i++)
    {

        while (i - maxi.front() >= k)
            maxi.pop_front();

        while (i - mini.front() >= k)
            mini.pop_front();

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
        ans = ans + arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}
int main()
{
    vector<int> arr = {2, 5, -1, 7, -3};
    int windowSize = 3;
    int ans = first_negative_in_k_size_window(arr, windowSize);

    // for (int i = 0; i < ans.size(); i++)
    // {
    cout << ans << " ";
    // }
    // cout << endl;

    return 0;
}
